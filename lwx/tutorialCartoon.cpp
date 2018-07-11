#include"tutorialCartoon.h"
#include <QTimerEvent>

static const QPoint pointPos[46]={
	QPoint(285, 122),QPoint(333,184),QPoint(320,197),QPoint(199,177)
	,QPoint(198, 170),QPoint(184,110),QPoint(309,300),QPoint(290,322)
	,QPoint(312, 331),QPoint(307,344),QPoint(288,348),QPoint(138,288)
	,QPoint(116, 256),QPoint(105,163),QPoint(126,279),QPoint(100,145)
	,QPoint(108,135),QPoint(114,146),QPoint(196,220),QPoint(322,53)
	,QPoint(148,74),QPoint(83,128),QPoint(99,165),QPoint(54,178)
	,QPoint(331,257),QPoint(303,198),QPoint(323,250),QPoint(300,300)
	,QPoint(248,246),QPoint(260,246),QPoint(328,231),QPoint(319,275)
	,QPoint(342,28),QPoint(338,54),QPoint(380,160),QPoint(364,188),
	QPoint(346,205),QPoint(352,222),QPoint(356,226),QPoint(360,231)
	,QPoint(355,263),QPoint(350,276),QPoint(336,291),QPoint(338,324)
	,QPoint(380,88),QPoint(380,62)
};

tutorialCartoon:: tutorialCartoon(const char*fileName, QWidget *parent ) :QLabel(parent)
{
	showImage = new QImage(fileName);
	//this->resize(parent->width()/2,(showImage->height()-40)/2);
	int showWidth = parent->width() / 2 - 10;
	int showHeight = (parent->height() - 40) / 2 - 50;
	this->setGeometry(parent->width() / 2+5,45,showWidth, showHeight);
	this->setAutoFillBackground(true);//设置自动填充背景颜色
	//this->setPalette(Qt::blue);//设置背景填充的颜色
	//this->setParent(parent);
	//showImage->scaled(showWidth,showHeight, Qt::KeepAspectRatio);
	this->setPixmap(QPixmap::fromImage(*showImage));
	
	//初始化画画工具
	pen = new QPen();
	brush =new QBrush();

	font = new QFont();
	font->setFamily("Microsoft YaHei");
	font->setPointSize(8);
	//设置字符间距
	font->setLetterSpacing(QFont::AbsoluteSpacing, 1);
	//设置定时器
	T1 = startTimer(1000);
	//T2 = startTimer(1300);
	T2 = -1;
	bDraw = false;
//	connect(this, SIGNAL(updateInfo()), this, SLOT(infoRecvUpdate()));
	cartoonIndex = 44;
}
void tutorialCartoon::paintEvent(QPaintEvent * e)
{
	
	if (cartoonIndex == -1)
	{
		this->update();
	}
	else
	{
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		drawPoint(pointPos[cartoonIndex].x(), pointPos[cartoonIndex].y(), &painter);
		writeChinesText(toothPosition_CHINA[cartoonIndex], &painter);
		if (bDraw == true)
		{
			drawArrows(pointPos[cartoonIndex].x() + 10, pointPos[cartoonIndex].y(), &painter);
			writeText(pointPos[cartoonIndex].x() + 5, pointPos[cartoonIndex].y(), toothPosition_ENGLISH[cartoonIndex], &painter);
		}
		else
		{

		}

	}
	
///必须有，才能让背景图片显示出来,调用父类的重绘方法
	QLabel::paintEvent(e);
}

void tutorialCartoon::timerEvent(QTimerEvent * event)
{
	Q_UNUSED(event);//没有实质性的作用，避免编译器警告（未使用event时）
	if (event->timerId() == T1)
	{
		bDraw = true;
		if(T2==-1)
			T2 = startTimer(500);
		this->update();
	}
	else if (event->timerId() == T2)
	{
		bDraw = false;
		if (T2!=-1)
		{
			killTimer(T2);
			T2 = -1;
		}
		
		this->update();
	}

}

int tutorialCartoon::getCurerntCartoon()
{
	return cartoonIndex;
}

void tutorialCartoon::setCurnetCattoon(const int & a)
{
	cartoonIndex = a;
		if (T2 != -1)
		{
			killTimer(T2);
			T2 = -1;
		}
		this->update();	
}


void tutorialCartoon::infoRecvCartoon(int &index)
{
	cartoonIndex = index;
	if (T2!=-1)
	{
		killTimer(T2);
		T2 = -1;
	}
	
}

void tutorialCartoon::drawPoint(qreal x, qreal y, QPainter *painter)
{
	pen->setColor(QColor(255, 0, 0));
	pen->setStyle(Qt::SolidLine);
	pen->setWidth(1);
	brush->setStyle(Qt::SolidPattern);
	brush->setColor(QColor(255, 0, 0));
	painter->setPen(*pen);
	painter->setBrush(*brush);
	painter->drawRect(QRect(x-2, y-2,5, 5));

}

void tutorialCartoon::drawArrows(qreal x, qreal y, QPainter *painter)
{
	pen->setColor(QColor(255, 0, 0));
	painter->setPen(*pen);
	QPainterPath path;
	QPoint startPoint(x, y);//起始点
	QPoint topTrianglePoint(x+10,y+10);//上半部三角形点
	QPoint bottomtrianglePoint(x+10,y-10);
	QPoint startRectPoint(x+10,y-5);
	QRectF myRect(x + 10, y - 5, 15, 10);
	QPolygonF polygon;
//	path.moveTo(startPoint);
	polygon << startPoint << topTrianglePoint << bottomtrianglePoint;
	path.addPolygon(polygon);

	path.closeSubpath();
//	path.moveTo(startRectPoint);
	path.addRect(myRect);
//	path.setFillRule(Qt::OddEvenFill);
	painter->drawPath(path);
}

void tutorialCartoon::writeText(qreal x, qreal y,const char *content, QPainter *painter)
{
	font->setPointSize(8);
	painter->setFont(*font);
	pen->setColor(QColor(255, 0, 0));
	painter->setPen(*pen);
	painter->setFont(*font);
	painter->drawText(x+40, y+5, content);
}

void tutorialCartoon::writeChinesText(const char * textContent, QPainter * painter)
{
	font->setPointSize(12);
	painter->setFont(*font);
	pen->setColor(QColor(139, 0,  0));
	painter->setPen(*pen);
	painter->drawText(20, 20, textContent);
}


//void tutorialCartoon::infoRecvUpdate()
//{	
//	this->update();
//}

