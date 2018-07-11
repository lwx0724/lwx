#pragma once
#include<QFile>
#include<QApplication>
#include<QImage>
//#pragma comment(lib,"iphlpapi.lib")
//#pragma comment(lib, "netapi32.lib")
#include<opencv2\opencv.hpp>
#include<qdebug.h>
class commonHelper
{
public:
	commonHelper();
	static void  setStyle(const QString &style);
	static bool dcm2QImage(const char*fileName, QImage &image);//Ã»³É¹¦
	static bool dcm2Mat(const char* fileName, cv::Mat & mat);
	static QImage MatToQImage(const cv::Mat&);
	static void CreateNewStr(const char *src1, const char *src2, char *dest);
	~commonHelper();
};

