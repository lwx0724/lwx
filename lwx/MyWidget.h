#pragma once
#include <QtWidgets/QWidget>
#include"TitleBar.h"
#include"qpushbutton.h"
#include <QPainter>
#include"commonHelper.h"
#include"MyItem.h"
#include<QGraphicsView>
#include<qgraphicsscene>
#include<qpushbutton.h>
#pragma execution_character_set("utf-8")
class MyWidget : public QWidget
{
	Q_OBJECT
public:
	MyWidget(QWidget *parent = Q_NULLPTR);
protected:
	void paintEvent(QPaintEvent *event);
//	void mousePressEvent(QMouseEvent *event);
//	void mouseMoveEvent(QMouseEvent *event);
//	void mouseReleaseEvent(QMouseEvent *event);

//定义移动发送消息信号
signals:
void moveInfoSend();
signals:
void drawInfoSend();
//按下OpenDcmButton响应的槽函数

//窗体的随意缩放
	//bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:
	QPoint point;
	bool pressed;
	int m_nBorder;
	//标题栏
	TitleBar *pTitlebar;
	////显示图片区域	
	QGraphicsScene * m_pSence;
	QGraphicsView *	m_pView;
	MyItem *m_pItem;//装载dcm图片
	//按钮
	QPushButton * m_pButtonItemmove;//移动item按钮
	QPushButton * m_pButtonDrawLine;//画线按钮
};
     