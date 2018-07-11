#pragma once
#include "qgraphicsview.h"
#include <QPaintEvent>
#include<QApplication>
#include<qtimer.h>
#include"qevent.h"
#include"qfont.h"
#include"globelVariable.h"
#include"commonHelper.h"
#pragma execution_character_set("utf-8")
class QWheelEvent;
class QKeyEvent;
class InteractiveView :
	public QGraphicsView
{
	Q_OBJECT
public:
explicit InteractiveView(QWidget *parent);
//���ŵ�����
void setZoomDelta(qreal delta);
qreal zoomDelta()const;
//���ֿ��ƷŴ���С
void wheelEvent(QWheelEvent *event)Q_DECL_OVERRIDE;
//�ı� ������ź�����
void setText(int _indexNumber,double * _textData);
public Q_SLOTS:
void zoomIn();
void zoomOut();
void zoom(float scaleFactor);//����

void  setGapNum(double gap);

protected:
	void paintEvent(QPaintEvent *event);

private:
	double viewWidth;
	double viewheight;
	qreal m_zoomDelta;  // ���ŵ�����
	qreal m_scale;  // ����ֵ
	qreal m_gap;
	
	//������ʾ����
	int  indexNumber;
	//������ʾ����
	double *textData;

	QFont *font;
	
	//QTimer *testTimer;
	//int m_nTimerId;
	~InteractiveView();
};

