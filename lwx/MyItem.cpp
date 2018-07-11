#include "MyItem.h"
//#include"FormatAndIos.h"
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<qpainter.h>

#define PI 3.1415927
MyItem::MyItem(const char * fileName, qreal x, qreal y, QObject * parent) :QObject(parent)
{
	m_dcmImage = new QImage();

	commonHelper::dcm2Mat(fileName, mat);
	cv::resize(mat, mat2, cv::Size(x, y));
	mat2 = 255 - mat2;
	*m_dcmImage = commonHelper::MatToQImage(mat2);
	//m_dcmImage->scaled(x,y,Qt::KeepAspectRatio);
	m_x = x;
	m_y = y;
	setCursor(Qt::OpenHandCursor);
	//����ͼԪ�����ƶ�
	setFlags(QGraphicsItem::ItemIsMovable);
	//����itemchange�ļ��
	setFlag(ItemSendsGeometryChanges, true);

	//��ʼ����������
	pen = new QPen();
	brush = new QBrush();

	//��ʼ����갴ť״̬��Ĭ�����ƶ�ͼƬ
	m_state = STATE_MOVE;

	//��ʼ������
	font = new QFont();
	font->setFamily("Microsoft YaHei");
	//��С
	font->setPointSize(8);
	//�����ַ����
	font->setLetterSpacing(QFont::AbsoluteSpacing, 2);

	updataIndex = 0;
	currentDrawIndex = 0;
	gapNum = 60.0;
	topNum = 46;//��ʼ����ǰ������������
	textNumber = 0;
	valueNum = 41;//23
	structNumber = 46;

	text = new int[46];//��ʼ�����Է�����Ĭ��Ϊȫ��
	text[0] = 44;
	text[1] = 45;
	for (int i = 2; i < 46; i++)
	{
		text[i] = i - 2;
	}
	//��ʼ��tweed���跽��
	tweedIndex = new int[14];
	for (int i = 0; i < 14; i++)
	{
		tweedIndex[i] = i; 

	}
	createMethod();

	connect(this, SIGNAL(changeInfo(int &, int )), parent, SLOT(infoRecvChangeButton(int &,int )));
	connect(this, SIGNAL(changeCartoon(int )), parent, SLOT(infoRecvParpare(int )));
	connect(this, SIGNAL(showCurrentBigButton(int)), parent, SLOT(infoRecvBigButtonState(int)));
	connect(this, SIGNAL(changViewRuler(double)), parent, SLOT(infoRecvGapNum(double)));
	connect(this, SIGNAL(changeTextHint(int, double *)), parent, SLOT(infoRecvTextMessage(int, double *)));

}


QRectF MyItem::boundingRect() const
{
	//ʹͼԪԭ����ͼԪ������
	//return QRectF(-m_dcmImage->width()/2,-m_dcmImage->height()/2,m_dcmImage->width(),m_dcmImage->height()/2);
	//ʹͼԪԭ����ͼԪ���Ͻ�
	return QRectF(0, 0,m_x, m_y);
}
MyItem::~MyItem()
{

}

void MyItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget *widget)
{
	painter->drawImage(boundingRect().topLeft(), *m_dcmImage);

	drawPainterPathLine(painter);
}

QVariant MyItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if (change == ItemPositionChange && scene()) {
		// value is the new position.
		QPointF newPos = value.toPointF();
		//qDebug() << "scene right:" << scene()->sceneRect().right();
		QRectF rect(scene()->sceneRect().left() - m_x / 2, scene()->sceneRect().top() - m_y / 2, scene()->sceneRect().right(), scene()->sceneRect().bottom());
		//QRectF rect = scene()->sceneRect();
		if (!rect.contains(newPos)) {
			// Keep the item inside the scene rect.
			newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
			newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
			return newPos;
		}
	}
	return QGraphicsItem::itemChange(change, value);
}
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if (m_state == STATE_DRAW)
	{
		if (event->button() == Qt::LeftButton)
		{	
			if (currentDrawIndex < topNum)
			{	
				linePos[text[currentDrawIndex]] = event->pos();
				//�ж��Ƿ���Ŀ̶ȳ߷�Χ
				if ((linePos[text[0]] != QPointF(-200.0, -200.0) && currentDrawIndex ==1)||(linePos[text[1]] != QPointF(-200.0, -200.0) && currentDrawIndex == 0))
				{
					gapNum = lineDistance(linePos[text[0]], linePos[text[1]]);
					emit changViewRuler(gapNum);			
				}
				//�ж���Ҫ������Щ������ʾ
				//judgeText(linePos);//+++++++++++++
					judgeText2();
				emit changeInfo(text[currentDrawIndex], 1);

				////��ǰȷ���ĵ����һ����Ҫȷ���ĵ㣬�����ǰ�㱻ȷ������������һ��
					//��һ����Ҫȷ���ĵ�
				findFirstPoint();
					
				update();
			}
		}
	}
	else if (m_state == STATE_MOVE)
	{
		setCursor(Qt::ClosedHandCursor);
		QGraphicsItem::mousePressEvent(event);
	}
	else if (m_state == STATE_UPDATA)
	{
		linePos[updataIndex] = event->pos();
		//�ж��Ƿ���Ŀ̶ȳ߷�Χ
		if ((linePos[text[0]] != QPointF(-200.0, -200.0) && updataIndex == 45) || (linePos[text[1]] != QPointF(-200.0, -200.0) && updataIndex == 44))
		{
			gapNum = lineDistance(linePos[text[0]], linePos[text[1]]);
			emit changViewRuler(gapNum);
		}
		//�ж���Ҫ������Щ������ʾ
		//judgeText(linePos);//++++++++++++++++
			judgeText2();
		emit changeInfo(updataIndex, 1);
////�ҵ���һ��û��ȷ���ĵ�,���ȷ����һ����
		findFirstPoint();

		m_state = STATE_DRAW;
		update();
	}
	else if (m_state == STATE_CLEAR)
	{
		
	}

}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	if (m_state == STATE_DRAW)
	{

	}
	else if (m_state == STATE_MOVE)
	{
		QGraphicsItem::mouseMoveEvent(event);
	}
	else if (m_state = STATE_UPDATA)
	{

	}
	else if (m_state = STATE_CLEAR)
	{

	}
	
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	if (m_state == STATE_DRAW)
	{

	}
	else if (m_state == STATE_MOVE)
	{
		setCursor(Qt::OpenHandCursor);
		QGraphicsItem::mouseReleaseEvent(event);
	}
	else if (m_state = STATE_UPDATA)
	{

	}
	else if (m_state = STATE_CLEAR)
	{

	}
}

void MyItem::infoRecvDraw()
{
	m_state = STATE_DRAW;
	setCursor(Qt::CrossCursor);
}

void MyItem::infoRecvClearAll()
{	
	for(int i=0;i<structNumber;i++)
	{
		linePos[i] = QPointF(-200.0, -200.0);

		judgeClear(i);
	}

	//judgeText(linePos);//++++++
		judgeText2();
	findFirstPoint();
			
	this->update();
	m_state = STATE_DRAW;
}
void MyItem::infoRecvUpdata(int &a)
{
	m_state = STATE_UPDATA;
	updataIndex = a;
	emit changeCartoon(updataIndex);
	emit showCurrentBigButton(updataIndex);//���水��״̬
	setCursor(Qt::CrossCursor);
}
void MyItem::infoRecvMove()
{
	m_state = STATE_MOVE;
	setCursor(Qt::OpenHandCursor);
}

void MyItem::infoRecvClear(int &a)
{
	
	clearIndex = a;
	linePos[clearIndex] = QPointF(-200.0, -200.0);
	//�ж���Ҫ������Щ������ʾ
	//judgeText(linePos);//+++++++++++
		judgeText2();
	//�ж���Ҫ����Ľṹ���Ƿ��ڱ�������Եķ�����
	judgeClear(clearIndex);

	findFirstPoint();

	update();
	m_state = STATE_DRAW;
}

void MyItem::infoRecvClear2(int & a)
{
	if (linePos[a] == QPointF(-200.0, -200.0))
		judgeClear(a);
	else
		emit changeInfo(a, 1);

	m_state = STATE_DRAW;
	findFirstPoint();
}

void MyItem::infoRecvText(int a)
{
	m_state = STATE_DRAW;
	setCursor(Qt::CrossCursor);
	switch (a)
	{
	case 1:		
		textNumber = a;
		delete text;
		text = new int[23];
		text[0] = 44;
		text[1] = 45;
		for (int i = 2; i < 23; i++)
		{
			text[i] = Tweed[i-2];
		}	
		topNum = 23;
		//currentDrawIndex = 0;
		updataIndex = 0;
		//���ֳ�ʼ��
		//��Ӧ�±��¼��Ӧ�������Ƿ��Ѿ�����
		value = new double[valueNum];
		for (int i = 0; i < valueNum; i++)
			value[i] = -1;
		//��װ�����ݼ��㸳ֵvalue
		for (int i = 0; i < 14; i++)
		{
			decorate_tweed[i]->setPValue(value);
		}
		//�ж��Ƿ���Ѿ�ȷ�������»��ߺ�����
	//	tweedText(linePos);//+++++++++++++++++++++++
		tweedText2();

		this->update();
		break;
	case 2:
		textNumber = a;
		break;

	default:
		break;
	}
}
void MyItem::drawPainterPathLine(QPainter * painter)
{
	painter->setRenderHint(QPainter::Antialiasing, true);
	switch (textNumber)
	{
	case 0:
		drawRule_default(painter,linePos);
		break;
	case 1:
		//drawRule_Tweed(painter, linePos);
		drawRule_Tweed2(painter,linePos);

		break;
	default:
		break;
	}
}

void MyItem::drawPoint(QPainter * painter,qreal x,qreal y)
{	
	//���û���ʱ���ʵ���ɫ������,�߿�
	pen->setColor(QColor(240, 40, 60));
	pen->setStyle(Qt::SolidLine);
	pen->setWidth(1);
	painter->setPen(*pen);
	//���ñ�ˢ,��ʵ�ľ��ε�
	brush->setStyle(Qt::SolidPattern);
	brush->setColor(QColor(240, 40, 60));
	painter->setBrush(*brush);
	//QRectF rectangle(x, y, 5, 5);
	//painter->drawRoundedRect(rectangle,15.0, 15.0);
	painter->drawRect(QRect(x-3, y-3, 6,6));
}
//
//void MyItem::drawLine(QPainter * painter,qreal startx,qreal starty,qreal endx,qreal endy)
//{
//	//��������ɫ��0,0,139��
//	pen->setColor(QColor(0, 0, 139));
//	pen->setStyle(Qt::SolidLine);
//	pen->setWidth(1);
//	painter->setPen(*pen);
//	painter->drawLine(startx,starty,endx,endy);
//}
//
void MyItem::drawText(QPainter * painter, qreal x, qreal y, const char * textContent)
{
	//ʹ������
	painter->setFont(*font);
	pen->setColor(QColor(240, 40, 60));
	painter->setPen(*pen);
	painter->drawText(x+10,y,textContent);
}
//
//void MyItem::drawlongLine(QPainter * painter, QPointF firstPoint, QPointF secondPoint)
//{
//	//��������ɫ��0,0,139��
//	pen->setColor(QColor(0, 0, 139));
//	pen->setStyle(Qt::SolidLine);
//	pen->setWidth(1);
//
//	double x1 = firstPoint.x();
//	double y1 = firstPoint.y();
//	double x2 = secondPoint.x();
//	double y2 = secondPoint.y();
//	if (x2 - x1 != 0)
//	{	
//		double a = (y2 - y1) / (x2 - x1);
//		double b = (x2 * y1 - x1 * y2) / (x2 - x1);
//		//QPointF topLeft(0,0);
//		//QPointF rightBottom(m_x,m_y);
//		//QRectF rect(topLeft,rightBottom);
//		//if(rect.contains())
//		QPointF newX1;
//		QPointF newY1;
//		if (b < 0)
//		{
//			newX1.setX(-b / a);
//			newX1.setY(0);
//		}
//		else if (b>=0&&b<=m_y)
//		{
//			newX1.setX(0);
//			newX1.setY(b);
//		}
//		else if(b>m_y)
//		{
//			newX1.setX((m_y - b) / a);
//			newX1.setY(m_y);
//		}
//
//		double  newY1_y = m_x*a + b;
//		if (newY1_y < 0)
//		{
//			newY1.setX(-b/a);
//			newY1.setY(0);
//		}
//		else if (newY1_y >= 0 && newY1_y <= m_y)
//		{
//			newY1.setX(m_x);
//			newY1.setY(newY1_y);
//		}
//		else if(newY1_y>m_y)
//		{
//			newY1.setX((m_y - b) / a);
//			newY1.setY(m_y);
//		}
//		painter->setPen(*pen);
//		painter->drawLine(newX1, newY1);
//	}
//	else
//	{
//		QPointF newX1(x1, 0);
//		QPointF newY1(x1, m_y);
//		painter->setPen(*pen);
//		painter->drawLine(newX1, newY1);
//		return;
//	}
//	
//
//
//}
//void MyItem::drawRadial(QPainter * painter, QPointF firstPoint, QPointF secondPoint)
//{
//	//��������ɫ��0,0,139��
//	pen->setColor(QColor(0, 0, 139));
//	pen->setStyle(Qt::SolidLine);
//	pen->setWidth(1);
//
//	double x1 = firstPoint.x();
//	double y1 = firstPoint.y();
//	double x2 = secondPoint.x();
//	double y2 = secondPoint.y();
//	if (x2 - x1 != 0)
//	{
//		double a = (y2 - y1) / (x2 - x1);
//		double b = (x2 * y1 - x1 * y2) / (x2 - x1);
//
//		//�ж����߷���
//		if (x1 - x2 > 0)
//		{
//			//��������
//			QPointF newY1(0, b);
//			painter->setPen(*pen);
//			painter->drawLine(firstPoint, newY1);
//		}
//		else
//		{
//			//��������
//			QPointF newY1(m_x, a*m_x + b);
//			painter->setPen(*pen);
//			painter->drawLine(firstPoint, newY1);
//		}
//	
//	}
//	else
//		return;
//}
//
//void MyItem::drawRule_Tweed(QPainter * painter, QVector<QPointF>& _newVector)
//{
//	//�Ȼ���
//	//PNS��ANS
//	if (_newVector[1] != QPointF(-200.0, -200.0) && _newVector[3] != QPointF(-200.0, -200.0))
//	{
//		drawlongLine(painter, _newVector[1], _newVector[3]);
//	}
//	//T1��Ar
//	if (_newVector[12] != QPointF(-200.0, -200.0) && _newVector[13] != QPointF(-200.0, -200.0))
//	{
//		drawlongLine(painter, _newVector[12], _newVector[13]);
//	}
//	//N��S
//	if (_newVector[19] != QPointF(-200.0, -200.0) && _newVector[20] != QPointF(-200.0, -200.0))
//	{
//		drawRadial(painter, _newVector[19], _newVector[20]);
//	}
//	//N��A��B
//	if (_newVector[19] != QPointF(-200.0, -200.0) && _newVector[2] != QPointF(-200.0, -200.0))
//	{
//		drawLine(painter, _newVector[19].x(), _newVector[19].y(),_newVector[2].x(), _newVector[2].y());
//	}
//	if (_newVector[19] != QPointF(-200.0, -200.0) && _newVector[6] != QPointF(-200.0, -200.0))
//	{
//		drawLine(painter, _newVector[19].x(), _newVector[19].y(), _newVector[6].x(), _newVector[6].y());
//	}
//	//T2��me
//	if (_newVector[10] != QPointF(-200.0, -200.0) && _newVector[11] != QPointF(-200.0, -200.0))
//	{
//		drawlongLine(painter, _newVector[10], _newVector[11]);
//	}
//	//LIA��LI
//	if (_newVector[27] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0))
//	{
//		drawlongLine(painter, _newVector[27], _newVector[26]);
//	}
//	//or��po
//	if (_newVector[0] != QPointF(-200.0, -200.0) && _newVector[21] != QPointF(-200.0, -200.0))
//	{
//		drawlongLine(painter, _newVector[0], _newVector[21]);
//	}
//	//L6,L1
//	if (_newVector[29] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0))
//	{
//		drawLine(painter, _newVector[29].x(), _newVector[29].y(), _newVector[26].x(), _newVector[26].y());
//	}
//	//UI,LI
//	if (_newVector[24] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0))
//	{
//		drawLine(painter, _newVector[24].x(), _newVector[24].y(), _newVector[26].x(), _newVector[26].y());
//	}
//	//pos��LL
//	if (_newVector[43] != QPointF(-200.0, -200.0) && _newVector[43] != QPointF(-200.0, -200.0))
//	{
//		drawLine(painter, _newVector[40].x(), _newVector[40].y(), _newVector[43].x(), _newVector[43].y());
//	}
//	//��׼��A���׼��B
//	if (_newVector[44] != QPointF(-200.0, -200.0) && _newVector[45] != QPointF(-200.0, -200.0))
//	{
//		drawLine(painter, _newVector[44].x(), _newVector[44].y(), _newVector[45].x(), _newVector[45].y());	
//	}
//	
//	//�ṹ�㻭��
//	for (int i = 0; i < 46; i++)
//	{
//		if (_newVector[i] != QPointF(-200.0, -200.0))
//			drawPoint(painter, _newVector[i].x(), _newVector[i].y());
//	}
//
//	//�����ƽṹ������
//		for (int i = 0; i <46; i++)
//		{
//			if (_newVector[i] != QPointF(-200.0, -200.0))
//			drawText(painter, _newVector[i].x(), _newVector[i].y(), toothPosition_ENGLISH[i]);
//		}
//	
//}

void MyItem::drawRule_default(QPainter * painter, QVector<QPointF>& _newVector)
{
	//�ṹ�㻭��
	for (int i = 0; i <46; i++)
	{
		if (_newVector[text[i]] != QPointF(-200.0, -200.0))
			drawPoint(painter, _newVector[text[i]].x(), _newVector[text[i]].y());
	}

	//�����ƽṹ������
	for (int i = 0; i <46; i++)
	{
		if (_newVector[text[i]] != QPointF(-200.0, -200.0))
			drawText(painter, _newVector[text[i]].x(), _newVector[text[i]].y(), toothPosition_ENGLISH[text[i]]);
	}

}

double MyItem::lineDistance(QPointF p1, QPointF p2)
{
	return sqrt(double(square(p2.x() - p1.x()) + square(p2.y() - p1.y())));
}

double MyItem::square(const double num)
{
	return num * num;
}
//
//double MyItem::lineAngle(QPointF p1, QPointF p2, QPointF p3, QPointF p4)
//{	
//	//�ñ�׼ʽ��ʾֱ�ߣ�����ABC��Ax+By+C =0
//	double A1, B1, C1;
//	double A2, B2, C2;
//	returnLineABC(p1,p2,A1,B1,C1);
//	returnLineABC(p3,p4,A2,B2,C2);
//
//	double v = A1*A2 + B1*B2;
//	if (v == 0)
//		return 90;
//
//	double t = (A1*B2 - A2*B1) / v;
//	if (t < 0)
//		t = -t;
//	 
//	return atan(t) * 180.0 / PI;
//}
//
//void MyItem::returnLineABC(QPointF p1, QPointF p2, double &A, double &B, double &C)
//{
//	if (p1.x() == p2.x())
//	{
//		A = 1;
//		B = 0;
//		C = -p1.x();
//	}
//	else if (p1.y() == p2.y())
//	{
//		A = 0;
//		B = 1;
//		C = -p1.y();
//	}
//	else
//	{
//		A = p2.y() - p1.y();
//		B = p1.x() - p2.x();
//		C = p2.x()*p1.y() - p1.x()*p2.y();
//	}
//}
//
//void MyItem::tweedText(QVector<QPointF>& _newVector)
//{
//	bool bSend = false;
//	
//	//FMIA
//	if(_newVector[0] != QPointF(-200.0, -200.0)&& _newVector[21] != QPointF(-200.0, -200.0)&& _newVector[26] != QPointF(-200.0, -200.0)&& _newVector[27] != QPointF(-200.0, -200.0))
//	{ 
//		double angel = lineAngle(_newVector[0], _newVector[21], _newVector[26], _newVector[27]);
//		value[0] = angel; 
//		bSend = true;
//	}
//	else {
//		value[0] = -1;
//	}
//
//	//FMA
//	if (_newVector[0] != QPointF(-200.0, -200.0) && _newVector[21] != QPointF(-200.0, -200.0) && _newVector[11] != QPointF(-200.0, -200.0) && _newVector[10] != QPointF(-200.0, -200.0))
//	{
//		double angel = lineAngle(_newVector[0], _newVector[21], _newVector[11], _newVector[10]);
//		value[1] = angel;
//		bSend = true;
//	}
//	else
//	{
//		value[1] = -1;
//	}
//	
//	//IMPA
//	if (_newVector[11] != QPointF(-200.0, -200.0) && _newVector[10] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0) && _newVector[27] != QPointF(-200.0, -200.0))
//	{
//		double angel = lineAngle(_newVector[11], _newVector[10], _newVector[26], _newVector[27]);
//		value[2] = angel;
//		bSend = true;
//	}
//	else
//	{
//		value[2] = -1;
//	}
//	//SNA
//	if (_newVector[20] != QPointF(-200.0, -200.0) && _newVector[19] != QPointF(-200.0, -200.0) && _newVector[2] != QPointF(-200.0, -200.0))
//	{
//		double angel = lineAngle(_newVector[20], _newVector[19], _newVector[19], _newVector[2]);
//	//	index[3] = 1;
//		value[3] = angel;
//		bSend = true;
//	}
//	else
//	{
//	//	index[3] = 0;
//		value[3] = -1;
//	}
//	//SNB
//	if (_newVector[20] != QPointF(-200.0, -200.0) && _newVector[19] != QPointF(-200.0, -200.0) && _newVector[6] != QPointF(-200.0, -200.0))
//	{
//		double angel = lineAngle(_newVector[20], _newVector[19], _newVector[19], _newVector[6]);
//		value[4] = angel;
//		bSend = true;
//	}
//	else
//	{
//		value[4] = -1;
//	}
//	//ANB
//	if (_newVector[2] != QPointF(-200.0, -200.0)&& _newVector[19] != QPointF(-200.0, -200.0)&& _newVector[6] != QPointF(-200.0, -200.0))
//	{
//		double angel =lineAngle(_newVector[2],_newVector[19], _newVector[2],_newVector[6]);
//		value[5] = angel;
//		bSend = true;
//	}
//	else
//	{
//		value[5] = -1;
//	}
//	//AO-BO
//
//
//	//OP��
//	if (_newVector[29] != QPointF(-200.0, -200.0) && _newVector[26] != QPointF(-200.0, -200.0) && _newVector[0] != QPointF(-200.0, -200.0) && _newVector[21] != QPointF(-200.0, -200.0))
//	{
//		double angel = lineAngle(_newVector[29], _newVector[26], _newVector[0], _newVector[21]);
//		value[7] = angel;
//		bSend = true;
//	}
//	else
//	{
//		value[7] = -1;
//	}
//	//Z��
//	if (_newVector[39] != QPointF(-200.0, -200.0) && _newVector[40] != QPointF(-200.0, -200.0) && _newVector[43] != QPointF(-200.0, -200.0))
//	{
//		if (_newVector[39].x() > _newVector[40].x())
//		{
//			double angel = lineAngle(_newVector[39], _newVector[43], _newVector[0], _newVector[21]);
//			value[8] = angel;	
//		}
//		else
//		{
//			double angel = lineAngle(_newVector[40], _newVector[43], _newVector[0], _newVector[21]);
//			value[8] = angel;
//			
//		}		
//		bSend = true;
//	}
//	else
//	{
//		value[8] = -1;
//	}
//
//
//	//�ϴ����
//
//	//ȫ���
//
//	//�����
//	if (_newVector[12] != QPointF(-200.0, -200.0) && _newVector[13] != QPointF(-200.0, -200.0))
//	{
//		//����AR��T1�ľ���
//		double length = lineDistance(_newVector[12], _newVector[13]);
//		value[11] = length / gapNum * 10;
//		bSend = true;
//	}
//	else
//	{
//		value[11] = -1;
//	}
//
//	//ǰ���
//	if (_newVector[1] != QPointF(-200.0, -200.0) && _newVector[3] != QPointF(-200.0, -200.0))
//	{
//		//����pNS��ANS�ľ���
//		double length = lineDistance(_newVector[1], _newVector[3]);
//		value[12] = length/gapNum*10;
//		bSend = true;
//	}
//	else
//	{
//		value[12] = -1;
//	}
//	//��߱�
//	if (value[11] != -1 && value[12] != -1)
//	{
//		value[13] = value[11] / value[12];
//		bSend = true;
//	}
//	else
//	{
//		value[13] = -1;
//	}
//
//	if(bSend)
//	emit changeTextHint(valueNum, value);
//
//}
//
//void MyItem::judgeText(QVector<QPointF>& _newVector)
//{
//	if (textNumber == 1)
//	{
//		tweedText(_newVector);
//	}
//}

void MyItem::findFirstPoint()
{
	////�ҵ���һ��û��ȷ���ĵ�,���ȷ����һ����,��ͬ����ťȺ״̬�Ͷ���״̬
	currentDrawIndex = 0;
	while (linePos[text[currentDrawIndex]] != QPointF(-200.0, -200.0))
	{
		currentDrawIndex++;
		if (currentDrawIndex == topNum)
			break;
	}
	if (currentDrawIndex < topNum)
	{
		emit changeCartoon(text[currentDrawIndex]);
		emit showCurrentBigButton(text[currentDrawIndex]);//���º��ť״̬��λ
	}
	else
	{
		emit showCurrentBigButton(-1);//���ȫ����ȷ������ť״̬����ȡ��
		emit changeCartoon(-1);//���е㶼ȷ��ʱ��������ʾ����������-1
	}

}

void MyItem::judgeClear(int index)
{
	bool temp = false;
	for (int i = 0; i < topNum; i++)
	{
		if (text[i] == index)
		{
			emit changeInfo(index, 0);
			temp = true;
			break;
		}
	}
	if (temp == false)
	{
		emit changeInfo(index, 2);
	}

}

void MyItem::tweedText2()
{
	decorate_tweed[13]->datacalculate();
	
	//���value�Ƿ��з�-1�����������ź�
	for (int i = 0; i < valueNum; i++)
	{
		if (value[i] != -1)
		{
			emit changeTextHint(valueNum, value);
		}
	}
}

void MyItem::judgeText2()
{
	switch (textNumber)
	{
	case 0:
		break;
	case 1:
		tweedText2();
		break;
	default:
		break;
	}
}

void MyItem::drawRule_Tweed2(QPainter * painter, QVector<QPointF>& _newVector)
{
	//����
	//��װ�λ��ߺ�����ֵpainter
	for (int i = 0; i < 14; i++)
	{
		decorate_tweed[i]->setQPainter(painter);
	}
	decorate_tweed[13]->drawLineJudge();
	//����׼��
	decorate_tweed[13]->drawStandardLine(painter, _newVector);
	//�ṹ�㻭��
	decorate_tweed[13]->drawStructurePoint(painter, _newVector,structNumber);
	//�����ƽṹ������
	decorate_tweed[13]->drawStructureText(painter,_newVector,structNumber);

}

void MyItem::createMethod()
{
	//��װ��tweed
	myTweed = new testMethod();
	configurationStyle(myTweed,decorate_tweed,14);
}

void MyItem::configurationStyle(testMethod * _myMethod, decorateDataType * _decorate[],int arrayNum)
{
	for (int i = 0; i < arrayNum; i++)
	{
		switch (tweedIndex[i])
		{
		case 0:
			_decorate[i] = new FMIA(linePos, m_x, m_y);
			break;
		case 1:
			_decorate[i] = new FMA(linePos, m_x, m_y);
			break;
		case 2:
			_decorate[i] = new IMPA(linePos, m_x, m_y);
			break;
		case 3:
			_decorate[i] = new SNA(linePos, m_x, m_y);
			break;
		case 4:
			_decorate[i] = new SNB2(linePos, m_x, m_y);
			break;
		case 5:
			_decorate[i] = new ANB(linePos, m_x, m_y);
			break;
		case 6:
			_decorate[i] = new AOBO(linePos, m_x, m_y);
			break;
		case 7:
			_decorate[i] = new OP(linePos, m_x, m_y);
			break;
		case 8:
			_decorate[i] = new Z(linePos, m_x, m_y);
			break;
		case 9:
			_decorate[i] = new labrumDistance(linePos, m_x, m_y);
			break;
		case 10:
			_decorate[i] = new chinDistance(linePos, m_x, m_y);
			break;
		case 11:
			_decorate[i] = new ART1(linePos, m_x, m_y);
			break;
		case 12:
			_decorate[i] = new PNSANS(linePos, m_x, m_y);
			break;
		case 13:
			_decorate[i] = new surfaceHeightRatio(linePos, m_x, m_y);
			break;
		case 14:
			_decorate[i] = new surfaceAngle(linePos, m_x, m_y);
			break;
		case 15:
			_decorate[i] = new jawRaiseAngle(linePos, m_x, m_y);
			break;
		case 16:
			_decorate[i] = new ABSurfaceAngle(linePos, m_x, m_y);
			break;
		case 17:
			_decorate[i] = new underjawSurfaceAngle(linePos, m_x, m_y);
			break;
		case 18:
			_decorate[i] = new YAxisAngle(linePos, m_x, m_y);
			break;
		case 19:
			_decorate[i] = new UIUIA(linePos, m_x, m_y);
			break;
		case 20:
			_decorate[i] = new LIMP(linePos, m_x, m_y);
			break;	
		case 21:
			_decorate[i] = new LIOP(linePos, m_x, m_y);
			break;
		case 22:
			_decorate[i] = new UI_APog(linePos, m_x, m_y);
			break;
		case 23:
			_decorate[i] = new Co_Pog(linePos, m_x, m_y);
			break;
		case 24:
			_decorate[i] = new Ptm_S(linePos, m_x, m_y);
			break;
		case 25:
			_decorate[i] = new ANS_Ptm(linePos, m_x, m_y);
			break;
		case 26:
			_decorate[i] = new Co_S(linePos, m_x, m_y);
			break;
		case 27:
			_decorate[i] = new N_Me(linePos, m_x, m_y);
			break;
		case 28:
			_decorate[i] = new N_ANS(linePos, m_x, m_y);
			break;
		case 29:
			_decorate[i] = new ANS_Me(linePos, m_x, m_y);
			break;
		case 30:
			_decorate[i] = new N_ANS_Ratio(linePos, m_x, m_y);
			break;
		case 31:
			_decorate[i] = new ANS_Me_Ratio(linePos, m_x, m_y);
			break;
		case 32:
			_decorate[i] = new Ptm_U6(linePos, m_x, m_y);
			break;
		case 33:
			_decorate[i] = new noseLabrumAngle(linePos, m_x, m_y);
			break;
		case 34:
			_decorate[i] = new upperlipSlope(linePos, m_x, m_y);
			break;
		case 35:
			_decorate[i] = new underSlope(linePos, m_x, m_y);
			break;
		case 36:
			_decorate[i] = new CmSnUL(linePos, m_x, m_y);
			break;
		case 37:
			_decorate[i] = new surfaceRaiseAngle(linePos, m_x, m_y);
			break;
		case 38:
			_decorate[i] = new allSurfaceRaiseAngle(linePos, m_x, m_y);
			break;
		case 39:
			_decorate[i] = new LL_B_Pos(linePos, m_x, m_y);
			break;
		case 40:
			_decorate[i] = new FCA(linePos, m_x, m_y);
			break;

		default:
			break;
		}
		if (i == 0)
		{
			_decorate[i]->setTestMethod(_myMethod);
		}
		else
		{
			_decorate[i]->setTestMethod(_decorate[i - 1]);
		}

	}
}

int MyItem::getCurrentDrawIndex()
{
	return text[currentDrawIndex];
}
