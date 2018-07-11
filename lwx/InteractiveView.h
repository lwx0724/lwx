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
//缩放的增量
void setZoomDelta(qreal delta);
qreal zoomDelta()const;
//滚轮控制放大缩小
void wheelEvent(QWheelEvent *event)Q_DECL_OVERRIDE;
//改变 文字序号和数据
void setText(int _indexNumber,double * _textData);
public Q_SLOTS:
void zoomIn();
void zoomOut();
void zoom(float scaleFactor);//缩放

void  setGapNum(double gap);

protected:
	void paintEvent(QPaintEvent *event);

private:
	double viewWidth;
	double viewheight;
	qreal m_zoomDelta;  // 缩放的增量
	qreal m_scale;  // 缩放值
	qreal m_gap;
	
	//文字提示个数
	int  indexNumber;
	//文字提示数据
	double *textData;

	QFont *font;
	
	//QTimer *testTimer;
	//int m_nTimerId;
	~InteractiveView();
};

