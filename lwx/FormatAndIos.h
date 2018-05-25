#pragma once
#include<io.h>
//#include<opencv2\opencv.hpp>
#include<QImage>
using namespace std;
class Lformat
{
public:
	//static bool dcm2Mat(const char* fileName, cv::Mat & mat);
	static bool dcm2QImage(const char*fileName, QImage &image);
};