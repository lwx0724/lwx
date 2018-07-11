#include "InteractiveView.h"
#include"qevent.h"
#include<qdebug.h>

#define VIEW_CENTER viewport()->rect().center()
#define VIEW_WIDTH  viewport()->rect().width()
#define VIEW_HEIGHT viewport()->rect().height()

InteractiveView::InteractiveView(QWidget *parent) : QGraphicsView(parent),
m_scale(1.0),
m_zoomDelta(0.1)
{
	
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setCursor(Qt::OpenHandCursor);
	setRenderHint(QPainter::Antialiasing,true);
	//设置view坐标系中scene的原点与窗口坐标系不同
//	setSceneRect(INT_MIN/2, INT_MIN / 2, INT_MAX, INT_MAX);//此函数设置场景原点位置，前两个参数是设置场景左上角坐标坐标，后两个参数是场景大小，此处是设置场景原点在视图正中心
	centerOn(0, 0);//关于滚动条的问题，保证场景坐标以视图（0，0）
	setBackgroundBrush(Qt::black);
	this->setAutoFillBackground(true);

	viewWidth = parent->width()/2;
	viewheight = parent->height()-40;
	m_gap = 60;
	

	font = new QFont();
	font->setFamily("Microsoft YaHei");
	font->setPointSize(8);
	//设置字符间距
	font->setLetterSpacing(QFont::AbsoluteSpacing, 1);
	//textIndex = NULL;
	textData = NULL;
	indexNumber = NULL;
	//testTimer = new QTimer(this);
	////将定时器超时信号与槽(功能函数)联系起来
	//connect(testTimer, SIGNAL(timeout()), this, SLOT(update()));
	////开始运行定时器，定时时间间隔为1000ms
	//testTimer->start(60);
	//m_nTimerId = startTimer(60);
	//connect(this, SIGNAL(updateInfo()), this, SLOT(paintEvent(QPaintEvent *event)));
}



// 缩放的增量
void InteractiveView::setZoomDelta(qreal delta)
{
	// 建议增量范围
	Q_ASSERT_X(delta >= 0.0 && delta <= 1.0,
		"InteractiveView::setZoomDelta", "Delta should be in range [0.0, 1.0].");
	m_zoomDelta = delta;
}

qreal InteractiveView::zoomDelta() const
{
	return m_zoomDelta;
}

// 放大/缩小
void InteractiveView::wheelEvent(QWheelEvent *event)
{
	// 滚轮的滚动量
	QPoint scrollAmount = event->angleDelta();
	// 正值表示滚轮远离使用者（放大），负值表示朝向使用者（缩小）
	scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

// 放大
void InteractiveView::zoomIn()
{
	zoom(1 + m_zoomDelta);
}

void InteractiveView::setText( int _indexNumber, double * _textData)
{
	textData = _textData;
	indexNumber = _indexNumber;
}

// 缩小
void InteractiveView::zoomOut()
{
	zoom(1 - m_zoomDelta);
}
// 缩放 - scaleFactor：缩放的比例因子
void InteractiveView::zoom(float scaleFactor)
{
	// 防止过小或过大
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	if (factor < 0.2 || factor > 2)
		return;

	scale(scaleFactor, scaleFactor);
	m_scale *= scaleFactor;
	//this->update();
}

void InteractiveView::setGapNum(double gap)
{
	m_gap = gap;
	//this->update();
}

void  InteractiveView::paintEvent(QPaintEvent *event)
{
	QGraphicsView::paintEvent(event);
	
	QPainter painter(this->viewport());
	painter.setRenderHint(QPainter::Antialiasing, true);
	QPen pen;
	pen.setWidth(1);
	pen.setStyle(Qt::SolidLine);
	pen.setColor(QColor(255, 255, 0));
	painter.setPen(pen);
	QFont font("Microsoft YaHei", 8,75);//宋体"MS Shell Dlg 2","Microsoft YaHei"
	//设置字符间距
	//font.setLetterSpacing(QFont::AbsoluteSpacing, 1);
	painter.setFont(font);
	//刻度尺最长轴
	QPointF topPoint(viewWidth - 20, 100);
	QPointF bottomPoint(viewWidth - 20, viewheight - 100);
	painter.drawLine(topPoint, bottomPoint);


	qreal length = bottomPoint.y() - topPoint.y();
	//初始刻度间隔
	qreal gapBigMark = m_gap*m_scale;
	qreal numBigMark = length / gapBigMark;
	double  startWidth = viewWidth - 21;
	double  startheight = viewheight - 100;
	double  markLength1 = 15;
	double markLength2 = 10;
	double markLength3 = 5;
	if (gapBigMark > 10)//每个间隔必须大于10
	{
		//画大刻度
		for (int i = 0; i < numBigMark ; i++)
		{
			painter.drawLine(startWidth-markLength1, startheight- i * gapBigMark, startWidth, viewheight - 100 - i * gapBigMark);
			QString str_a = QString::number(i * 10, 10);
			//	QTextOption option(Qt::AlignRight);
			//	option.setWrapMode(QTextOption::WordWrap);
			QRect temp(startWidth - 40, startheight-8 - i * gapBigMark, 20, 20);
			painter.drawText(temp, Qt::AlignRight, str_a);
		}
		//画中刻度
		for (int i = 0; i < numBigMark; i++)
		{
			if(startheight - (gapBigMark / 2) - i * gapBigMark>topPoint.y())
			painter.drawLine(startWidth-markLength2,startheight- (gapBigMark/2)- i * gapBigMark, startWidth, startheight - (gapBigMark / 2) - i * gapBigMark);
		}
		//画小刻度
		for (int i = 0; i < numBigMark * 2; i++)
		{
			if(startheight - (gapBigMark / 10) - i*(gapBigMark / 2)>topPoint.y())
			painter.drawLine(startWidth-markLength3, startheight - (gapBigMark / 10) - i*(gapBigMark / 2), startWidth, startheight - (gapBigMark / 10) - i*(gapBigMark / 2));
			if (startheight - (gapBigMark / 10)*2 - i*(gapBigMark / 2)>topPoint.y())
			painter.drawLine(startWidth - markLength3, startheight - (gapBigMark / 10)*2 - i*(gapBigMark / 2), startWidth, startheight - (gapBigMark / 10) * 2 - i*(gapBigMark / 2));
			if (startheight - (gapBigMark / 10)*3 - i*(gapBigMark / 2)>topPoint.y())
			painter.drawLine(startWidth - markLength3, startheight - (gapBigMark / 10)*3 - i*(gapBigMark / 2), startWidth, startheight - (gapBigMark / 10) * 3 - i*(gapBigMark / 2));
			if (startheight - (gapBigMark / 10)*4 - i*(gapBigMark / 2)>topPoint.y())
			painter.drawLine(startWidth - markLength3, startheight - (gapBigMark / 10)*4 - i*(gapBigMark / 2), startWidth, startheight - (gapBigMark / 10) * 4 - i*(gapBigMark / 2));
		}

	}

// 单位显示
	QRect unitRect(startWidth-10, startheight, 20, 20);
	painter.drawText(unitRect, Qt::AlignCenter, "mm");

	painter.setFont(font);
	pen.setColor(QColor(50, 205, 50));
	painter.setPen(pen);
	painter.setFont(font);
	//左上角文字
	int realHaveTextNum = 0;
	for (int i = 0; i < indexNumber; i++)
	{
		if (textData[i] != -1)
		{
			char str2[5];
			gcvt(textData[i] , 5, str2);
			int newStrLen1 = strlen(textHintOnView[i]) + strlen(str2) + 1;
			char *ab = (char *)malloc(sizeof(char) * newStrLen1);
			commonHelper::CreateNewStr(textHintOnView[i], str2,ab);
		
			int newStrLen2 = newStrLen1 + strlen(textUnit[i]) + 1;
			char *abc = (char *)malloc(sizeof(char) * newStrLen2);
			commonHelper::CreateNewStr(ab, textUnit[i], abc);
			
			painter.drawText(20, 20 + realHaveTextNum * 12, abc);
			realHaveTextNum++;
		
			delete ab;	
			delete abc;
			ab = NULL;
			abc = NULL;


			
		}	
	}
}

//void InteractiveView::timerEvent(QTimerEvent * event)
//{
//	//QGraphicsView::timerEvent(event);
//	this->update();	
//	qDebug("gap:%f", m_gap);
//}
InteractiveView::~InteractiveView()
{
	/*if (m_nTimerId != 0)
		killTimer(m_nTimerId);*/
	/*if (testTimer->isActive())
		testTimer->stop();*/
}
