#include "TitleBar.h"
#include<QHBoxLayout>
#include<QEvent>
#include<QApplication>
#include<QMouseEvent>
#ifdef Q_OS_WIN
//#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif
TitleBar::TitleBar(QWidget *parent)
	: QWidget(parent)
{
	setFixedHeight(35);
	m_pIconLabel = new QLabel(this);
	m_pTitleLabel = new QLabel(this);
	m_pMinimizeButton = new QPushButton(this);
	m_pMaximizeButton = new QPushButton(this);
	m_pCloseButton = new QPushButton(this);

	m_pIconLabel->setFixedSize(32,32);
	m_pIconLabel->setScaledContents(true);//确保图片充满整个label

	m_pTitleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_pTitleLabel->setFixedSize(1350,50);
	m_pMinimizeButton->setFixedSize(37, 32);
	m_pMaximizeButton->setFixedSize(37, 32);
	m_pCloseButton->setFixedSize(37, 32);
	
	QPalette pal(palette());
	pal.setColor(QPalette::Background, QColor(50, 50, 50));//68, 69, 73(淡一点的黑色)
	setAutoFillBackground(true);
	setPalette(pal);

	m_pTitleLabel->setObjectName("whiteLabel");
	m_pMinimizeButton->setObjectName("minimizeButton");
	m_pMaximizeButton->setObjectName("maximizeButton");
	m_pCloseButton->setObjectName("closeButton");

	m_pMinimizeButton->setToolTip("Minimize");
	m_pMaximizeButton->setToolTip("Maximize");
	m_pCloseButton->setToolTip("Close");

	//水平布局
	QHBoxLayout *pLayout = new QHBoxLayout(this);
	pLayout->addWidget(m_pIconLabel);
	pLayout->addSpacing(5);
	pLayout->addWidget(m_pTitleLabel);
	pLayout->addWidget(m_pMinimizeButton);
	pLayout->addWidget(m_pMaximizeButton);
	pLayout->addWidget(m_pCloseButton);
	pLayout->setSpacing(0);
	pLayout->setContentsMargins(5, 0, 5, 0);
	setLayout(pLayout);

	//连接槽函数
	connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
	connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
	connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
	//ui.setupUi(this);
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent * event)
{
	Q_UNUSED(event);

	emit m_pMaximizeButton->clicked();
}

void TitleBar::mousePressEvent(QMouseEvent * event)
{
#ifdef Q_OS_WIN
	if (ReleaseCapture())
	{
		QWidget *pWindow = this->window();//返回标题栏的窗口
		if (pWindow->isTopLevel())
		{
			SendMessage(HWND(pWindow->winId()),WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
	event->ignore();

#else
#endif // Q_OS_WIN

}

bool TitleBar::eventFilter(QObject * obj, QEvent * event)
{
	switch(event->type())
	{
	case QEvent::WindowTitleChange:
	{
		QWidget *pWidget = qobject_cast<QWidget *>(obj);
		if (pWidget)
		{
			m_pTitleLabel->setText(pWidget->windowTitle());
			QPalette pe;
			pe.setColor(QPalette::WindowText, Qt::white);
			m_pTitleLabel->setPalette(pe);
			return true;
		}
	}
	case QEvent ::WindowIconChange:
	{
		QWidget *pWidget = qobject_cast<QWidget*>(obj);
		if (pWidget)
		{
			QIcon icon = pWidget->windowIcon();
			m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
			return true;
		}
	}
	case QEvent:: WindowStateChange:
	case QEvent:: Resize:
		updateMaximize();
		return true;


	}
	return QWidget::eventFilter(obj, event);
}

TitleBar::~TitleBar()
{
}

void TitleBar::updateMaximize()
{
	QWidget *pWindow = this->window();
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized();
		if (bMaximize)
		{
			m_pMaximizeButton->setToolTip(tr("Restore"));
			m_pMaximizeButton->setProperty("maximizeProperty","restore");
		}
		else
		{
			m_pMaximizeButton->setProperty("maximizeProperty","maximize");//设置小窗口时，按钮属性为maximize
			m_pMaximizeButton->setToolTip("Maximize");
		}
		m_pMaximizeButton->setStyle(QApplication::style());
	}
}

void TitleBar::onClicked()
{
	//当某一个Object emit一个signal的时候，它就是一个sender,
	QPushButton * pButton = qobject_cast<QPushButton *>(sender());
	QWidget *pWindow = this->window();
	//判断pWindow是否是最上级窗口，没有父窗口
	if (pWindow->isTopLevel())
	{
		if (pButton == m_pMinimizeButton)
		{
			pWindow->showMinimized();
		}
		else if (pButton == m_pMaximizeButton)
		{
	//		pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();   //使窗口失去最大化功能
		}
		else if (pButton == m_pCloseButton)
		{
			pWindow->close();
		}
	}

}