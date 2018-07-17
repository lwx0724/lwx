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
#include"combinedButton.h"
#include"tutorialCartoon.h"
#include"InteractiveView.h"
#include"qicon.h"
#pragma execution_character_set("utf-8")
class MyWidget : public QWidget
{
	Q_OBJECT
public:
	MyWidget(QWidget *parent = Q_NULLPTR);

protected:
	void paintEvent(QPaintEvent *event);

signals:
void textInfoSend(int index);

public slots:
void infoRecvChangeButton(int &a, int b);//改变小按钮
void infoRecvParpare(int index);//预备动画
void emitTextInfo0();
void emitTextInfo1();
void emitTextInfo2();
void emitTextInfo3();
void emitTextInfo4();
void infoRecvBigButtonState(int a);//改变大按钮状态
void infoRecvGapNum(double gap);//改变刻度尺的间隔
void infoRecvTextMessage(int n, double *value);

private:
	QPoint point;
	bool pressed;
	int m_nBorder;
	//标题栏
	TitleBar *pTitlebar;
	////显示图片区域	
	QGraphicsScene * m_pSence;
	InteractiveView *m_pView;
	MyItem *m_pItem;//装载dcm图片
	tutorialCartoon *m_tutorialCartoon;
	//按钮
	QPushButton * m_pButtonItemmove;//移动item按钮
	QPushButton * m_pButtonDrawLine;//画线按钮
	QPushButton * m_pButtonclearAll;//清除所有点的数据与显示
	QButtonGroup * m_pGroup;//测试方法设置为一组s
	QPushButton *m_pButtonMethod[5];//5种方法的指针数组
	
	QLabel *pLabelgroup;
	combinedButton *m_pButtonGroupWeight;//按钮群weight

 ////小按钮显示状态的图标
	QIcon  *pixmap_havePos;
	QIcon *pixmap_noPos;
	QIcon *pixmap_transparency;
	QPushButton * smallGroup[46];
	QPushButton * bigGroup[46];

};
     