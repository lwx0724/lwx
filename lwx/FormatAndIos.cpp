#include "FormatAndIos.h"
#include<dcmtk/config/osconfig.h>
#include<dcmtk/ofstd/ofstdinc.h>
#include<dcmtk/dcmdata/dctk.h>
#include<dcmtk/dcmdata/cmdlnarg.h>
#include<dcmtk/ofstd/ofconapp.h>
#include<dcmtk/dcmdata/dcuid.h>
#include<dcmtk/dcmjpeg/djdecode.h>
#include<dcmtk/dcmjpeg/dipijpeg.h>
#include "dcmtk/dcmimgle/dcmimage.h"
//bool Lformat::dcm2Mat(const char * fileName, cv::Mat & mat)
//{
//	DJDecoderRegistration::registerCodecs();//jpeg ������ע��
//	DcmFileFormat fileformat;
//	if (!(fileformat.loadFile(fileName).good()))
//		return false;
//
//	DcmDataset *dataset = fileformat.getDataset();
//	dataset->chooseRepresentation(EXS_LittleEndianExplicit, NULL);//С������
//	DcmElement *element = NULL;
//	OFCondition result = dataset->findAndGetElement(DCM_PixelData, element);//��ȡ���ݼ���������Ԫ�ص�������Ϣ
//	if (result.bad() || element == NULL)
//		return false;
//	unsigned short *pixdata;
//	result = element->getUint16Array(pixdata);
//
//	long rows = 0;
//	long cols = 0;
//	dataset->findAndGetLongInt(DCM_Rows, rows);
//	dataset->findAndGetLongInt(DCM_Columns, cols);
//
//	if (rows == 0 || cols == 0)
//		return false;
//
//	unsigned short *pbuf = new unsigned short[rows *cols];
//	memcpy(pbuf, pixdata, rows*cols * 2);//ÿ����������2���ֽ�
//	 
//	cv::Mat xxx(rows, cols, CV_16SC1, pbuf);//16λ�з�����������ͨ��
//	cv::Mat xx;
//
//	cv::normalize(xxx, xx, 0, 255, cv::NORM_MINMAX, CV_8UC1);//������ֵ��һ��λ0~255��ͬʱ��ʽҲ��Ϊ8λ�޷�������
//    cv::Mat afull(xx.rows, xx.cols, CV_8UC1, 255);//�С�������ʽ����ʼ��ֵ
//	xx = afull - xx;  //��ɫ��ת
//    mat = xx.clone();
//	//cvtColor(mat, mat, CV_GRAY2RGB);
//	delete[] pbuf;
//	DJDecoderRegistration::cleanup();
//	return true;
//
//}

bool Lformat::dcm2QImage(const char * fileName, QImage & image)
{
	 register JPEG decompression codecs
	DJDecoderRegistration::registerCodecs();
	DcmFileFormat *fileFormat = new DcmFileFormat();
	OFCondition condition = fileFormat->loadFile(fileName);
	if (!condition.good())
	{
		qDebug("DcmConvert::set file fail:");
		return false;
	}

	else{
		QImage *image = 0;
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
			qDebug() << "Error: cannot load DICOM image (" << DicomImage::getString(dcmImage->getStatus()) << ")" << endl;
			qDebug("Error: cannot load DICOM image ");
		}
		delete dcmImage;
		dcmImage = 0;
		}
	}
	return false;
}