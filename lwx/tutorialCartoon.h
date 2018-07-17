#pragma once
#include<qlabel.h>
#include<qimage.h>
#include<qpixmap.h>
#include"qpainter.h"
#include<qtimer.h>
#include<qpainterpath.h>
#include"globelVariable.h"
#pragma execution_character_set("utf-8")
class tutorialCartoon : public QLabel
{
	Q_OBJECT
public:
	tutorialCartoon(const char*fileName, QWidget *parent = 0);
	void paintEvent(QPaintEvent*e);
	// 定时刷新
	void timerEvent(QTimerEvent *event);
	int  getCurerntCartoon();
	void setCurnetCattoon(const int &a);
//signals:
//	void updateInfo();
public slots:
	//void infoRecvUpdate();
	void infoRecvCartoon(int &index);//按下按钮后，对应的动画显示动作

private:
	void drawPoint(qreal x, qreal y ,QPainter *painter);//画点
	void drawArrows(qreal x,qreal y,QPainter *painter);//画箭头
	void writeText(qreal x, qreal y, const char * textContent, QPainter *painter);//写英文文本
	void writeChinesText(const char * textContent, QPainter *painter);
	QImage * showImage;
	//画画时所用工具
	QPen *pen;
	QBrush *brush;
	QFont *font;
	//重绘的定时器
//	QTimer *timer1;

	int T1;//出现的计时器
	int T2;//消失的计时器
	bool bDraw;
	//当前显示动画序号
	int cartoonIndex;

};