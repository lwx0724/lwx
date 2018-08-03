#include "MyWidget.h"
#include<QMouseEvent>
#include<QVBOXLayout>
#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <Windowsx.h>
#endif
MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
	pixmap_havePos = new QIcon(":/pixmap/Black/success.png");
	pixmap_noPos = new QIcon(":/pixmap/Black/warning.png");
	pixmap_transparency = new QIcon(":/pximap/Black/transparency.png");
	pixmap_setting = new QIcon(":/pixmap/icon/setting.png");
	//设置无边框
	setWindowFlags(Qt::FramelessWindowHint);
	//// 背景透明
	//setAttribute(Qt::WA_TranslucentBackground, true);

	pTitlebar = new TitleBar(this);
	installEventFilter(pTitlebar);

	this->resize(1500,900);
//	this->setFixedSize(1500,900);
	setWindowTitle("Custom Window");
	setWindowIcon(QIcon(":/lwx/icon/1.ico"));

	QPalette pal(palette());
	pal.setColor(QPalette::Background,QColor(68,69,73));//68, 69, 73(淡一点的黑色)
	setAutoFillBackground(true);
	setPalette(pal);
	
	//辅助动画区域
	m_tutorialCartoon = new tutorialCartoon(".\\icon\\2.png", this);

	////载入dcm图像，在主窗口按固定大小展示
	 m_pItem =new MyItem(".\\dcm\\head1.dcm",width()/2-200,height()-40-200,this);//head;dcm-0126
	m_pSence= new QGraphicsScene(this);
	m_pSence->setSceneRect(0,0,width()/2,height()-40);
	m_pSence->addItem(m_pItem);
	m_pSence->setBackgroundBrush(Qt::black);//Qt::black；Qt::transparent
	m_pItem->setPos(100,100);

	m_pView = new InteractiveView(this);
	m_pView->setGeometry(0,40, width() / 2,height() - 40);
	m_pView->setScene(m_pSence);
	m_pView->show();
	//按钮move
	m_pButtonItemmove = new QPushButton(this);
	m_pButtonItemmove->setGeometry(width()/2 + 5, (height() - 40) / 2, 50, 30);
	m_pButtonItemmove->setText("移动");
	m_pButtonItemmove->setCheckable(true);

	m_pButtonItemmove->setAutoExclusive(true);
	m_pButtonItemmove->show();

	connect(m_pButtonItemmove, SIGNAL(clicked(bool)), m_pItem, SLOT(infoRecvMove()));

	//按钮draw
	m_pButtonDrawLine = new QPushButton(this);
	m_pButtonDrawLine->setGeometry(width() / 2 + 60, (height() - 40) / 2, 50, 30);
	m_pButtonDrawLine->setText("画线");
	m_pButtonDrawLine->setCheckable(true);
	m_pButtonDrawLine->setChecked(true);
	m_pButtonDrawLine->setAutoExclusive(true);
	m_pButtonDrawLine->show();
	connect(m_pButtonDrawLine, SIGNAL(clicked(bool)), m_pItem, SLOT(infoRecvDraw()));

	//清除按钮
	m_pButtonclearAll = new QPushButton(this);
	m_pButtonclearAll->setGeometry(width() / 2 + 120, (height() - 40) / 2, 50, 30);
	m_pButtonclearAll->setText("清除");
	m_pButtonclearAll->setCheckable(true);
	m_pButtonclearAll->setAutoExclusive(true);
	m_pButtonclearAll->show();
	connect(m_pButtonclearAll, SIGNAL(clicked(bool)), m_pItem, SLOT(infoRecvClearAll()));

	//按钮群
	m_pButtonGroupWeight = new combinedButton(width() / 2 + 5, (height() - 40) / 2 + 40, m_pItem, m_tutorialCartoon, this);
	m_pButtonGroupWeight->getSmallGroup(smallGroup);
	m_pButtonGroupWeight->getBigGroup(bigGroup);
	//测量方法按钮group,按下变执行画线功能
	pLabelgroup = new  QLabel(this);
	pLabelgroup->setText("测量方法");
	pLabelgroup->setStyleSheet("color:white");
	pLabelgroup->setGeometry(1160 ,470,80,20);
	pLabelgroup->show();
	//创建测试按钮
	m_pGroup = new QButtonGroup(this);
	for (int i = 0; i < 5; i++)
	{
		m_pButtonMethod[i] = new QPushButton(this);
		m_pButtonMethod[i]->setGeometry(1163, 490+30*i, 40, 25);
		m_pButtonMethod[i]->setText(methodName[i]);
		m_pGroup->addButton(m_pButtonMethod[i], i);
		m_pButtonMethod[i]->setCheckable(true);
		m_pButtonMethod[i]->setAutoExclusive(true);
		m_pButtonMethod[i]->show();
		
	}
	m_pButtonMethod[0]->setChecked(true);
	
	//创建自定义按钮,位置处有编号，更改时需注意
	customButton1 = new QPushButton(this);
	settingButton1 = new QPushButton(this);
	customButton1->setGeometry(1163, 490 + 30 * 5, 40, 25);
	settingButton1->setGeometry(1163+45,490+30*5,25,25);
	customButton1->setText("自定义");
	m_pGroup->addButton(customButton1,5);
	customButton1->setCheckable(true);
	customButton1->setAutoExclusive(true);
	customButton1->show();
	settingButton1->setIcon(*pixmap_setting);
	//初始化setting Dialog
	m_pSetting = new MyDialog(this);

	//默认方法下的小图标初始化
	int defualtPointNum = 46;
	for (int i = 0; i < defualtPointNum; i++)
	{
		smallGroup[i]->setIcon(*pixmap_noPos);
		smallGroup[i]->setIconSize(smallGroup[i]->size());
		smallGroup[i]->setStyleSheet(" border-color: #E6E6FA;border-width: 0px;border-style: solid;");
	}
		
	connect(m_pButtonMethod[0], SIGNAL(clicked(bool)), this, SLOT(emitTextInfo0()));
	connect(m_pButtonMethod[1], SIGNAL(clicked(bool)), this, SLOT(emitTextInfo1()));
	connect(m_pButtonMethod[2], SIGNAL(clicked(bool)), this, SLOT(emitTextInfo2()));
	connect(m_pButtonMethod[3], SIGNAL(clicked(bool)), this, SLOT(emitTextInfo3()));
	connect(m_pButtonMethod[4], SIGNAL(clicked(bool)), this, SLOT(emitTextInfo4()));
	connect(customButton1, SIGNAL(clicked(bool)),this, SLOT(emitTextInfo5()));
	connect(settingButton1,SIGNAL(clicked(bool)),this,SLOT(openSettingDialog()));
	connect(this, SIGNAL(textInfoSend(int)), m_pItem, SLOT(infoRecvText(int)));
	connect(this, SIGNAL(textInfoSend(int)), m_pButtonGroupWeight, SLOT(infoRecvText(int)));
	bigGroup[44]->setStyleSheet("background:rgb(46,139,87);");
	QCoreApplication::processEvents();//防止事件队列堵塞
}


void MyWidget::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
         
}

void MyWidget::infoRecvParpare(int index)
{
	m_tutorialCartoon->setCurnetCattoon(index);
}
void MyWidget::emitTextInfo0()
{
	emit textInfoSend(0);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
}
//
void MyWidget::emitTextInfo1()
{
	emit textInfoSend(1);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
}

void MyWidget::emitTextInfo2()
{
	emit textInfoSend(2);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
}

void MyWidget::emitTextInfo3()
{
	emit textInfoSend(3);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
}

void MyWidget::emitTextInfo4()
{
	emit textInfoSend(4);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
}

void MyWidget::emitTextInfo5()
{
	emit textInfoSend(5);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
}

void MyWidget::openSettingDialog()
{
	m_pSetting->show();
}

void  MyWidget::infoRecvGapNum(double gap)
{
	m_pView->setGapNum(gap);
	m_pView->viewport()->update();//更新视口绘制，不是m_pView->updat
}

void MyWidget::infoRecvTextMessage( int n, double * value)
{
	m_pView->setText(n,value);//浅复制传入进去
	m_pView->viewport()->update();
	
}

void MyWidget::infoRecvchangItem()
{
	QVector<int> a;
	m_pSetting->getVector(a);
	m_pItem->setDefindVector(a);
}

void MyWidget::infoRecvCustomPoint(int n, int * point)
{
}

void MyWidget::infoRecvBigButtonState(int a)
{
	if (a >= 0 && a < 46)
	{
		for (int i = 0; i < 46; i++)
		{
			bigGroup[i]->setStyleSheet("background:rgb(60,60,60);");
		}
		bigGroup[a]->setStyleSheet("background:rgb(46,139,87);");
	}
	else
	{
		for (int i = 0; i < 46; i++)
		{
			bigGroup[i]->setStyleSheet("background:rgb(60,60,60);");
		}
		this->update();
	}
	
}

void MyWidget::infoRecvChangeButton(int &a, int b)
{
	if (b == 0)
	{
		smallGroup[a]->setIcon(*pixmap_noPos);
		smallGroup[a]->setIconSize(smallGroup[a]->size());
		smallGroup[a]->setStyleSheet(" border-color: #E6E6FA;border-width: 0px;border-style: solid;");
	}
	else if(b ==1)
	{
		smallGroup[a]->setIcon(*pixmap_havePos);
		smallGroup[a]->setIconSize(smallGroup[a]->size());
		smallGroup[a]->setStyleSheet(" border-color: #E6E6FA;border-width: 0px;border-style: solid;");
	}
	else if (b == 2)
	{
		smallGroup[a]->setIcon(*pixmap_transparency);
		smallGroup[a]->setIconSize(smallGroup[a]->size());
		smallGroup[a]->setStyleSheet(" border-color: #E6E6FA;border-width: 1px;border-style: solid;");
	}

	this->update();
}




