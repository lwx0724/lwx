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
	//设置无边框
	setWindowFlags(Qt::FramelessWindowHint);
	//// 背景透明
	//setAttribute(Qt::WA_TranslucentBackground, true);

	pTitlebar = new TitleBar(this);
	installEventFilter(pTitlebar);

	this->resize(1500,900);
	setWindowTitle("Custom Window");
	setWindowIcon(QIcon(":/lwx/icon/1.ico"));

	QPalette pal(palette());
	pal.setColor(QPalette::Background,QColor(68,69,73));//68, 69, 73(淡一点的黑色)
	setAutoFillBackground(true);
	setPalette(pal);
	
	////载入dcm图像，在主窗口按固定大小展示
	 m_pItem =new MyItem(".\\dcm\\dcm-0126.dcm",width()/2-200,height()-40-200,this);
	m_pSence= new QGraphicsScene(this);
	m_pSence->setSceneRect(0,-40,width()/2,height()-40);
	m_pSence->addItem(m_pItem);
	m_pSence->setBackgroundBrush(Qt::black);
	m_pItem->setPos(100,100);

	m_pView = new QGraphicsView(this);
	m_pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pView->setGeometry(0,40, width() / 2,height() - 40);
	m_pView->setFixedSize(width() / 2, height() - 40);
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
}

void MyWidget::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);
	
}


//void MyWidget::mousePressEvent(QMouseEvent * event)
//{
//	if (event->button() == Qt::LeftButton)
//	{
//		pressed = true;
//		point = event->pos();
//	}
//}
//
//void MyWidget::mouseMoveEvent(QMouseEvent * event)
//{
//	if (pressed)
//	{
//		move(event->pos() -point+pos());
//	}
//}
//
//void MyWidget::mouseReleaseEvent(QMouseEvent * event)
//{s
//	Q_UNUSED(event);
//	pressed = false;
//}

//bool MyWidget::nativeEvent(const QByteArray & eventType, void * message, long * result)
//{
//	Q_UNUSED(eventType)
//
//		MSG *param = static_cast<MSG *>(message);
//
//	switch (param->message)
//	{
//	case WM_NCHITTEST:
//	{
//		int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
//		int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();
//
//		// 如果鼠标位于子控件上，则不进行处理
//		if (childAt(nX, nY) != NULL)
//			return QWidget::nativeEvent(eventType, message, result);
//
//		*result = HTCAPTION;
//
//		// 鼠标区域位于窗体边框，进行缩放
//		if ((nX > 0) && (nX < m_nBorder))
//			*result = HTLEFT;
//
//		if ((nX > this->width() - m_nBorder) && (nX < this->width()))
//			*result = HTRIGHT;
//
//		if ((nY > 0) && (nY < m_nBorder))
//			*result = HTTOP;
//
//		if ((nY > this->height() - m_nBorder) && (nY < this->height()))
//			*result = HTBOTTOM;
//
//		if ((nX > 0) && (nX < m_nBorder) && (nY > 0)
//			&& (nY < m_nBorder))
//			*result = HTTOPLEFT;
//
//		if ((nX > this->width() - m_nBorder) && (nX < this->width())
//			&& (nY > 0) && (nY < m_nBorder))
//			*result = HTTOPRIGHT;
//
//		if ((nX > 0) && (nX < m_nBorder)
//			&& (nY > this->height() - m_nBorder) && (nY < this->height()))
//			*result = HTBOTTOMLEFT;
//
//		if ((nX > this->width() - m_nBorder) && (nX < this->width())
//			&& (nY > this->height() - m_nBorder) && (nY < this->height()))
//			*result = HTBOTTOMRIGHT;
//
//		return true;
//	}
//	}

//	return QWidget::nativeEvent(eventType, message, result);
//}




