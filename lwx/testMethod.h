#pragma once
#include"qpainter.h"
#include"math.h"
#include"globelVariable.h"
class testMethod
{
public:
	testMethod();
	virtual void drawLineJudge();//划线判断
	virtual void datacalculate();//数据计算（装饰时共同被装饰）
	//画点函数
	void  drawStructurePoint(QPainter * painter, QVector<QPointF>& _newVector, int structNumber);
	//写文字函数
	void drawStructureText(QPainter *painter, QVector<QPointF> &_newVector, int structNumber);
	//画1cmA，1cmB连线
	void drawStandardLine(QPainter *painter, QVector<QPointF> &_newVector);

protected:
	//需要在子类中被使用的必要计算函数
	void drawPoint(QPainter * painter, qreal x, qreal y);
	void drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy);//画线段
	void drawText(QPainter * painter, qreal x, qreal y, const char * textContent);
	void drawlongLine(QPainter * painter, QPointF firstPoint, QPointF secondPoint,int m_x,int m_y);//画直线，最后两个参数是图片item大小
	void drawRadial(QPainter * painter, QPointF firstPoint, QPointF secondPoint,int m_x,int m_y);//画射线，第一个参数为射线源点
	//计算几何数据函数
	double lineDistance(QPointF p1, QPointF p2);//两点间距离
	double square(const double num);//平方
	double lineAngle(QPointF p1, QPointF p2, QPointF p3, QPointF p4);//使用向量计算，抛弃斜率计算的方法
	void returnLineABC(QPointF p1, QPointF p2, double &A, double &B, double &C);//返回一般式参数
	double pointToLine(QPointF p1, QPointF p2,QPointF P3);//前两个参数为直线上两点，后一个为线外一点，点到直线的距离
	QPointF footPoint(QPointF p1, QPointF p2, QPointF P3);//点到直线的垂足
	bool  judgePointAndLineRelationship(QPointF p1, QPointF p2, QPointF p3);//判断点在直线上方还是下方
	QPointF lineIntersection(QPointF p1, QPointF p2, QPointF p3,QPointF p4);
	//画线部分函数
	void lineXtoIntersection(QPainter * painter, QVector<QPointF>& _newVector,int i,int j,int m,int n);//i,j为线，m为离线较远的一个点
	void lineXtoFoot(QPainter * painter, QVector<QPointF>& _newVector, int i, int j, int m);//i，j为线，m为线外一点
	void lineQ1Q2(QPainter * painter, QVector<QPointF>& _newVector);//画Q1Q2
	void longLineXtoY(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y,int i ,int j);
	void lineXtoY(QPainter *painter, QVector<QPointF>& _newVector,int i, int j);
	void radialXtoY(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y,int i,int j);
};