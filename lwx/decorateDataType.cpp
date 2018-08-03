#include "decorateDataType.h"

decorateDataType::decorateDataType(int _x, int _y):m_x(_x),m_y(_y)
{
}

void decorateDataType::drawLineJudge()
{
	mTestMethod->drawLineJudge();
}

void decorateDataType::datacalculate()
{
	mTestMethod->datacalculate();
}

void decorateDataType::setTestMethod(testMethod * _mTestMethod)
{
	this->mTestMethod = _mTestMethod;
}

void decorateDataType::setQPainter(QPainter * _painter)
{
	m_painter = _painter;
}

void decorateDataType::setPValue(double * _value)
{
	m_value = _value;
}

void decorateDataType::getPoint(QVector<int>& a)
{
	////…Ó∏¥÷∆
	//for (int i = 0; i < relatePoint.size(); i++)
	//{
	//	a.append(relatePoint.at(i));
	//}

	a = relatePoint;

}

decorateDataType::~decorateDataType()
{
}
