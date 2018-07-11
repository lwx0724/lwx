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
	//m_pView->setFixedSize(width() / 2, height() - 40);
	m_pView->setScene(m_pSence);
	m_pView->show();
	//按钮move
	m_pButtonItemmove = new QPushButton(this);
	m_pButtonItemmove->setGeometry(width()/2 + 5, (height() - 40) / 2, 50, 30);
	m_pButtonItemmove->setText("移动");
	m_pButtonItemmove->setCheckable(true);
	m_pButtonItemmove->setChecked(true);
	m_pButtonItemmove->setAutoExclusive(true);
	m_pButtonItemmove->show();
	//m_pButtonItemmove->setFocus();//默认设置移动为初始焦点
	connect(m_pButtonItemmove, SIGNAL(clicked(bool)), m_pItem, SLOT(infoRecvMove()));

	//按钮draw
	m_pButtonDrawLine = new QPushButton(this);
	m_pButtonDrawLine->setGeometry(width() / 2 + 60, (height() - 40) / 2, 50, 30);
	m_pButtonDrawLine->setText("画线");
	m_pButtonDrawLine->setCheckable(true);
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

	m_pButtonTweed = new QPushButton(this);
	m_pButtonTweed->setGeometry(1163,490,40,25);
	m_pButtonTweed->setText("Tweed");
	m_pButtonTweed->setCheckable(true);
	m_pButtonTweed->setAutoExclusive(true);
	m_pButtonTweed->show();
//	m_pGroup = new QButtonGroup(this);
//	m_pGroup->addButton(m_pButtonTweed);
    connect(m_pButtonTweed, SIGNAL(clicked(bool)), this, SLOT(emitTextInfo()));
	//connect(m_pButtonTweed, SIGNAL(clicked(bool)), m_pItem, SLOT(infoRecvDraw()));
	connect(this, SIGNAL(textInfoSend(int)), m_pItem, SLOT(infoRecvText(int)));
	connect(this, SIGNAL(textInfoSend(int)), m_pButtonGroupWeight, SLOT(infoRecvText(int)));
//	connect(this, SIGNAL(gapInfoSend(double)), m_pView, SLOT(infogetGapNum(double)));
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
//
void MyWidget::emitTextInfo()
{
	emit textInfoSend(1);
	infoRecvBigButtonState(m_pItem->getCurrentDrawIndex());
	

}

void  MyWidget::infoRecvGapNum(double gap)
{
	m_pView->setGapNum(gap);
	m_pView->viewport()->update();//更新视口绘制，不是m_pView->updat
//	m_pView->update();
//  this->update();
//	m_pView->show();
//	qApp->processEvents();
}

void MyWidget::infoRecvTextMessage( int n, double * value)
{
	m_pView->setText(n,value);//浅复制传入进去，debug时没问题但是在发布版本时有时会出现指针中断问题
	m_pView->viewport()->update();
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
		//smallGroup[a]->setFlat(true);
		smallGroup[a]->setIcon(*pixmap_noPos);
		smallGroup[a]->setIconSize(smallGroup[a]->size());
		smallGroup[a]->setStyleSheet(" border-color: #E6E6FA;border-width: 0px;border-style: solid;");
	//	smallGroup[a]->show();
	//	m_pButtonGroupWeight->setSmallGroup(a,smallGroup[a]);
	}
	else if(b ==1)
	{
		//smallGroup[a]->setFlat(true);
		smallGroup[a]->setIcon(*pixmap_havePos);
		smallGroup[a]->setIconSize(smallGroup[a]->size());
		smallGroup[a]->setStyleSheet(" border-color: #E6E6FA;border-width: 0px;border-style: solid;");
	// bn  	smallGroup[a]->show();
	//	m_pButtonGroupWeight->setSmallGroup(a, smallGroup[a]);
	}
	else if (b == 2)
	{
		smallGroup[a]->setIcon(*pixmap_transparency);
		smallGroup[a]->setIconSize(smallGroup[a]->size());
		smallGroup[a]->setStyleSheet(" border-color: #E6E6FA;border-width: 1px;border-style: solid;");
	}

	this->update();
}




