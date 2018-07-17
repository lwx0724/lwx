#pragma once
#include"qpainter.h"
#include"math.h"
#include"globelVariable.h"
class testMethod
{
public:
	testMethod();
	virtual void drawLineJudge();//�����ж�
	virtual void datacalculate();//���ݼ��㣨װ��ʱ��ͬ��װ�Σ�
	//���㺯��
	void  drawStructurePoint(QPainter * painter, QVector<QPointF>& _newVector, int structNumber);
	//д���ֺ���
	void drawStructureText(QPainter *painter, QVector<QPointF> &_newVector, int structNumber);
	//��1cmA��1cmB����
	void drawStandardLine(QPainter *painter, QVector<QPointF> &_newVector);

protected:
	//��Ҫ�������б�ʹ�õı�Ҫ���㺯��
	void drawPoint(QPainter * painter, qreal x, qreal y);
	void drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy);//���߶�
	void drawText(QPainter * painter, qreal x, qreal y, const char * textContent);
	void drawlongLine(QPainter * painter, QPointF firstPoint, QPointF secondPoint,int m_x,int m_y);//��ֱ�ߣ��������������ͼƬitem��С
	void drawRadial(QPainter * painter, QPointF firstPoint, QPointF secondPoint,int m_x,int m_y);//�����ߣ���һ������Ϊ����Դ��
	//���㼸�����ݺ���
	double lineDistance(QPointF p1, QPointF p2);//��������
	double square(const double num);//ƽ��
	double lineAngle(QPointF p1, QPointF p2, QPointF p3, QPointF p4);//ʹ���������㣬����б�ʼ���ķ���
	void returnLineABC(QPointF p1, QPointF p2, double &A, double &B, double &C);//����һ��ʽ����
	double pointToLine(QPointF p1, QPointF p2,QPointF P3);//ǰ��������Ϊֱ�������㣬��һ��Ϊ����һ�㣬�㵽ֱ�ߵľ���
	QPointF footPoint(QPointF p1, QPointF p2, QPointF P3);//�㵽ֱ�ߵĴ���
	bool  judgePointAndLineRelationship(QPointF p1, QPointF p2, QPointF p3);//�жϵ���ֱ���Ϸ������·�
	QPointF lineIntersection(QPointF p1, QPointF p2, QPointF p3,QPointF p4);
	//���߲��ֺ���
	void lineXtoIntersection(QPainter * painter, QVector<QPointF>& _newVector,int i,int j,int m,int n);//i,jΪ�ߣ�mΪ���߽�Զ��һ����
	void lineXtoFoot(QPainter * painter, QVector<QPointF>& _newVector, int i, int j, int m);//i��jΪ�ߣ�mΪ����һ��
	void lineQ1Q2(QPainter * painter, QVector<QPointF>& _newVector);//��Q1Q2
	void longLineXtoY(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y,int i ,int j);
	void lineXtoY(QPainter *painter, QVector<QPointF>& _newVector,int i, int j);
	void radialXtoY(QPainter * painter, QVector<QPointF>& _newVector, int m_x, int m_y,int i,int j);
};