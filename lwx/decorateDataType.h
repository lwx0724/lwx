#pragma once
#include "testMethod.h"
class  decorateDataType : public testMethod 
{
public:
	 decorateDataType(int _x,int _y);
	 virtual void drawLineJudge();
	 virtual void datacalculate();
	 virtual void setTestMethod(testMethod* _mTestMethod);
	 
	 void  setQPainter(QPainter *_painter);
	 void setPValue(double *_value);
	 void getPoint(QVector<int> & a);
	 ~ decorateDataType();
	
protected:
	testMethod * mTestMethod;
	double *m_value;
	QPainter * m_painter;
	int m_x;
	int m_y;
	QVector<int> relatePoint;
private:
};

