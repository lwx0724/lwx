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
	//����view����ϵ��scene��ԭ���봰������ϵ��ͬ
//	setSceneRect(INT_MIN/2, INT_MIN / 2, INT_MAX, INT_MAX);//�˺������ó���ԭ��λ�ã�ǰ�������������ó������Ͻ��������꣬�����������ǳ�����С���˴������ó���ԭ������ͼ������
	centerOn(0, 0);//���ڹ����������⣬��֤������������ͼ��0��0��
	setBackgroundBrush(Qt::black);
	this->setAutoFillBackground(true);

	viewWidth = parent->width()/2;
	viewheight = parent->height()-40;
	m_gap = 60;
	

	font = new QFont();
	font->setFamily("Microsoft YaHei");
	font->setPointSize(8);
	//�����ַ����
	font->setLetterSpacing(QFont::AbsoluteSpacing, 1);
	//textIndex = NULL;
	textData = NULL;
	indexNumber = NULL;
	//testTimer = new QTimer(this);
	////����ʱ����ʱ�ź����(���ܺ���)��ϵ����
	//connect(testTimer, SIGNAL(timeout()), this, SLOT(update()));
	////��ʼ���ж�ʱ������ʱʱ����Ϊ1000ms
	//testTimer->start(60);
	//m_nTimerId = startTimer(60);
	//connect(this, SIGNAL(updateInfo()), this, SLOT(paintEvent(QPaintEvent *event)));
}



// ���ŵ�����
void InteractiveView::setZoomDelta(qreal delta)
{
	// ����������Χ
	Q_ASSERT_X(delta >= 0.0 && delta <= 1.0,
		"InteractiveView::setZoomDelta", "Delta should be in range [0.0, 1.0].");
	m_zoomDelta = delta;
}

qreal InteractiveView::zoomDelta() const
{
	return m_zoomDelta;
}

// �Ŵ�/��С
void InteractiveView::wheelEvent(QWheelEvent *event)
{
	// ���ֵĹ�����
	QPoint scrollAmount = event->angleDelta();
	// ��ֵ��ʾ����Զ��ʹ���ߣ��Ŵ󣩣���ֵ��ʾ����ʹ���ߣ���С��
	scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

// �Ŵ�
void InteractiveView::zoomIn()
{
	zoom(1 + m_zoomDelta);
}

void InteractiveView::setText( int _indexNumber, double * _textData)
{
	textData = _textData;
	indexNumber = _indexNumber;
}

// ��С
void InteractiveView::zoomOut()
{
	zoom(1 - m_zoomDelta);
}
// ���� - scaleFactor�����ŵı�������
void InteractiveView::zoom(float scaleFactor)
{
	// ��ֹ��С�����
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
	QFont font("Microsoft YaHei", 8,75);//����"MS Shell Dlg 2","Microsoft YaHei"
	//�����ַ����
	//font.setLetterSpacing(QFont::AbsoluteSpacing, 1);
	painter.setFont(font);
	//�̶ȳ����
	QPointF topPoint(viewWidth - 20, 100);
	QPointF bottomPoint(viewWidth - 20, viewheight - 100);
	painter.drawLine(topPoint, bottomPoint);


	qreal length = bottomPoint.y() - topPoint.y();
	//��ʼ�̶ȼ��
	qreal gapBigMark = m_gap*m_scale;
	qreal numBigMark = length / gapBigMark;
	double  startWidth = viewWidth - 21;
	double  startheight = viewheight - 100;
	double  markLength1 = 15;
	double markLength2 = 10;
	double markLength3 = 5;
	if (gapBigMark > 10)//ÿ������������10
	{
		//����̶�
		for (int i = 0; i < numBigMark ; i++)
		{
			painter.drawLine(startWidth-markLength1, startheight- i * gapBigMark, startWidth, viewheight - 100 - i * gapBigMark);
			QString str_a = QString::number(i * 10, 10);
			//	QTextOption option(Qt::AlignRight);
			//	option.setWrapMode(QTextOption::WordWrap);
			QRect temp(startWidth - 40, startheight-8 - i * gapBigMark, 20, 20);
			painter.drawText(temp, Qt::AlignRight, str_a);
		}
		//���п̶�
		for (int i = 0; i < numBigMark; i++)
		{
			if(startheight - (gapBigMark / 2) - i * gapBigMark>topPoint.y())
			painter.drawLine(startWidth-markLength2,startheight- (gapBigMark/2)- i * gapBigMark, startWidth, startheight - (gapBigMark / 2) - i * gapBigMark);
		}
		//��С�̶�
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

// ��λ��ʾ
	QRect unitRect(startWidth-10, startheight, 20, 20);
	painter.drawText(unitRect, Qt::AlignCenter, "mm");

	painter.setFont(font);
	pen.setColor(QColor(50, 205, 50));
	painter.setPen(pen);
	painter.setFont(font);
	//���Ͻ�����
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
