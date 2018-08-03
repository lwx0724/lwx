#pragma once
#include<qpushbutton.h>
#include<qstring.h>
#include<qobject.h>
#include<qpixmap.h>
#include"globelVariable.h"
#include"qlabel.h"
#include"qbuttongroup.h"
#include"qevent.h"
#include"qdebug.h"
#include"MyItem.h"
#include"tutorialCartoon.h"
#pragma execution_character_set("utf-8")
//整个按钮群
class combinedButton : public QWidget
{
	Q_OBJECT
public:
	combinedButton(qreal _posX,qreal _posY, MyItem *item, tutorialCartoon *cartoon,QWidget *parent = 0);
	bool eventFilter(QObject *obj,QEvent *e);
	void getSmallGroup(QPushButton *_smallGroup[]);
	void setSmallGroup(int a,QPushButton *_temp);
	void getBigGroup(QPushButton *_bigGroup[]);
	void getBigGroup(int a, QPushButton *_temp);
	void setCustomPoint(int _num,int *_customPoint);

	//void paintEvent(QPaintEvent*e);
////定义每个按钮按下发送消息信号
signals:
void buttonNumberInfo(int &a); //不仅要想场景发送信息，还要向动画发送信号
signals:
void smallInfo(int &a);//更改运行时的小按钮图片
signals:
void smallInfo2(int &a);//创建时

////按下按钮的槽函数
public slots:
	void infoRecvText(int a);

//signals:
//	void pickInfoSend();

//public slots:
//	void emit_signal_buttonNumberInfo();

	
private:
	qreal posX;//按钮位置
	qreal posY;
	bool bigButtonReleased;
	bool smallButtonReleased;
	QString bigContent;
	QString bigTip;
	QPushButton *bigButton_0;
	QPushButton *smallButton_0;
	
	//ButtonGroup
	QButtonGroup *bgroup;
	//按钮指针数组+2标准点
	QPushButton *bigGroup[46];
	QPushButton *smallGroup[46];
	//按钮标签
	QLabel *pLabelgroup[5];

	//记录当前按下按钮的序号
	int  currentIndex_big;
	int currentIndex_small;
	int currentIndex_standard;
	////小按钮显示状态的图标
	QPixmap *pixmap_havePos;
	QPixmap *pixmap_noPos;

	//本轮读取的测试方法
	int *text;
	//本轮测试方法的上限
	int topNum;
	//测试方法图案是否初始化,对连续按同一个按钮上锁，按其他按钮时解锁
	bool bInitialize;
	//初始化小按钮图片
	void initializeSmallButton(int level);
	//自定义初始化小按钮
	void initializeSmallButton2();

	//自定义所需点
	int *customPoint;
	int num;//数量包括1cma,1cmb
};

