#include "commonHelper.h"
#include<dcmtk/config/osconfig.h>
#include<dcmtk/ofstd/ofstdinc.h>
#include<dcmtk/dcmdata/dctk.h>
#include<dcmtk/dcmdata/dcrledrg.h>
#include<dcmtk/dcmdata/cmdlnarg.h>
#include<dcmtk/ofstd/ofconapp.h>
#include<dcmtk/dcmdata/dcuid.h>
#include<dcmtk/dcmjpeg/djdecode.h>
#include<dcmtk/dcmjpeg/dipijpeg.h>
#include"dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmimage/diregist.h"  
#include "dcmtk/dcmjpeg/djdecode.h"

commonHelper::commonHelper()
{
}

void commonHelper::setStyle(const QString & style)
{
	QFile qss(style);
	if (qss.open(QFile::ReadOnly))
	{
	qDebug("open success!");
	qApp->setStyleSheet(qss.readAll());
	qss.close();
	}
}

bool commonHelper::dcm2QImage(const char * fileName, QImage & inImage)
{
	QImage *image = 0;
	DcmRLEDecoderRegistration::registerCodecs(OFFalse, OFTrue);
	DJDecoderRegistration::registerCodecs();
	DcmFileFormat *fileFormat = new DcmFileFormat();
	OFCondition condition = fileFormat->loadFile(fileName);
	if (!condition.good())
	{
		qDebug("DcmConvert::set file fail:");
		return false;
	}

	else {
		DcmDataset * dset = fileFormat->getDataset();
		DicomImage *dcmImage = new DicomImage(fileFormat, dset->getOriginalXfer(), CIF_MayDetachPixelData);
		if (dcmImage != NULL) {
			if (dcmImage->getStatus() == EIS_Normal) {
				dcmImage->setNoDisplayFunction();
				dcmImage->hideAllOverlays();
				dcmImage->setNoVoiTransformation();
				int width = dcmImage->getWidth();
				int height = dcmImage->getHeight();
				ulong size = width * height;
				if (dcmImage->isMonochrome()) {
					uchar *data = new uchar[size];
					dcmImage->setMinMaxWindow();
					dcmImage->getOutputData(data, size, 8);
					image = new QImage(data, width, height, 8, QImage::Format_Mono);
					inImage = *image;
				}
				else {
					size = size * 4;
					uchar *data = new uchar[size];
					uchar* pixelData = (uchar *)(dcmImage->getOutputData(8));
					unsigned long y = 0;
					for (unsigned long x = 0; x < size; x += 4) {
						data[x] = pixelData[y];     //R
						data[x + 1] = pixelData[y + 1]; //G
						data[x + 2] = pixelData[y + 2]; //B
						data[x + 3] = 0xFF; //Alpha
						y += 3;
					}
					image = new QImage(data, width, height, QImage::Format_RGBA8888);
				}
			}
			else {
				//	qDebug() << "Error: cannot load DICOM image (" << DicomImage::getString(dcmImage->getStatus()) << ")" << endl;
				qDebug("Error: cannot load DICOM image ");
			}
			delete dcmImage;
			dcmImage = 0;
		}
	}
	return false;
}
bool commonHelper::dcm2Mat(const char * fileName, cv::Mat & mat)
{
	DJDecoderRegistration::registerCodecs();//jpeg 译码器注册
	DcmFileFormat fileformat;
	if (!(fileformat.loadFile(fileName).good()))
		return false;

	DcmDataset *dataset = fileformat.getDataset();
	dataset->chooseRepresentation(EXS_LittleEndianExplicit, NULL);//小端排序
	DcmElement *element = NULL;
	OFCondition result = dataset->findAndGetElement(DCM_PixelData, element);//获取数据集当中数据元素的像素信息
	if (result.bad() || element == NULL)
		return false;
	unsigned short *pixdata;
	result = element->getUint16Array(pixdata);

	long rows = 0;
	long cols = 0;
	dataset->findAndGetLongInt(DCM_Rows, rows);
	dataset->findAndGetLongInt(DCM_Columns, cols);

	if (rows == 0 || cols == 0)
		return false;

	unsigned short *pbuf = new unsigned short[rows *cols];
	memcpy(pbuf, pixdata, rows*cols * 2);//每个像素数组2个字节

	cv::Mat xxx(rows, cols, CV_16SC1, pbuf);//16位有符号整数，单通道
	cv::Mat xx;

	cv::normalize(xxx, xx, 0, 255, cv::NORM_MINMAX, CV_8UC1);//将像素值归一化位0~255，同时格式也变为8位无符号整形
	cv::Mat afull(xx.rows, xx.cols, CV_8UC1, 255);//行、宽、格式、初始化值
	xx = afull - xx;  //颜色反转
	mat = xx.clone();
	//cvtColor(mat, mat, CV_GRAY2RGB);
	delete[] pbuf;
	DJDecoderRegistration::cleanup();
	return true;
}
QImage commonHelper::MatToQImage(const cv::Mat &mat)
{
	// 8-bits unsigned, NO. OF CHANNELS=1
	if (mat.type() == CV_8UC1)
	{
		// Set the color table (used to translate colour indexes to qRgb values)
		QVector<QRgb> colorTable;
		for (int i = 0; i<256; i++)
			colorTable.push_back(qRgb(i, i, i));
		// Copy input Mat
		const uchar *qImageBuffer = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
		img.setColorTable(colorTable);
		return img;
	}
	// 8-bits unsigned, NO. OF CHANNELS=3
	if (mat.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *qImageBuffer = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return img.rgbSwapped();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
commonHelper::~commonHelper()
{
}
