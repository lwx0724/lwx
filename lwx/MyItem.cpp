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

	//��ʼ����갴ť״̬��Ĭ�����ƶ�ͼƬ
	m_state = STATE_DRAW;
	setCursor(Qt::CrossCursor);
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
	//��ʼ����¼���ֵ�Value����
	value = new double[valueNum];
	for (int i = 0; i < valueNum; i++)
		value[i] = -1;
	
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
	//delete value;
	//value = NULL;
	//delete myTweed;
	//myTweed = NULL;
	//delete myDefault;
	//myDefault = NULL;
	//delete myDowns;
	//myDowns = NULL;
	//delete mySoftTissue;
	//mySoftTissue = NULL;
	//delete myWyile;
	//myWyile = NULL;
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
	case 0:
		initializeLevelData(0);
		break;
	case 1:		
		initializeLevelData(1);
		break;
	case 2:
		initializeLevelData(2);	
		break;
	case 3:
		initializeLevelData(3);
		break;
	case 4:
		initializeLevelData(4);
	default:
		break;
	}
}
void MyItem::drawPainterPathLine(QPainter * painter)
{
	
	switch (textNumber)
	{
	case 0:
		drawRule_X(painter, linePos, decorate_Default,10);
		break;
	case 1:
		drawRule_X(painter, linePos, decorate_Tweed, 14);
		break;
	case 2:
		drawRule_X(painter, linePos, decorate_Downs, 10);
		break;
	case 3:
		drawRule_X(painter, linePos, decorate_Wyile, 10);
		break;
	case 4:
		drawRule_X(painter, linePos, decorate_Tissue, 9);
		break;
	default:
		break;
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


void MyItem::judgeText2()
{
	switch (textNumber)
	{
	case 0:
		decorate_Default[9]->datacalculate();
		break;
	case 1:
		decorate_Tweed[13]->datacalculate();
		break;
	case 2:
		decorate_Downs[9]->datacalculate();
		break;
	case 3:
		decorate_Wyile[9]->datacalculate();
		break;
	case 4:
		decorate_Tissue[8]->datacalculate();
		break;
	default:
		break;
	}

	//���value�Ƿ��з�-1�����������ź�
	for (int i = 0; i < valueNum; i++)
	{
		if (value[i] != -1)
		{
			emit changeTextHint(valueNum, value);
		}
	}
}



void MyItem::drawRule_X(QPainter * painter, QVector<QPointF>& _newVector, decorateDataType *decorate_X[],int num)
{
	//����
	//��װ�λ��ߺ�����ֵpainter
	for (int i = 0; i < num; i++)
	{
		decorate_X[i]->setQPainter(painter);
	}
	if (num - 1 > 0)
	{
		decorate_X[num - 1]->drawLineJudge();
		//����׼��
		decorate_X[num - 1]->drawStandardLine(painter, _newVector);
		//�ṹ�㻭��
		decorate_X[num - 1]->drawStructurePoint(painter, _newVector, structNumber);
		//�����ƽṹ������
		decorate_X[num - 1]->drawStructureText(painter, _newVector, structNumber);
	}	
}

void MyItem::createMethod()
{
	//��װ��tweed
	myTweed = new testMethod();
	configurationStyle(myTweed,decorate_Tweed,dataType_Tweed,14);
	//��װ��myDowns
	myDowns = new testMethod();
	configurationStyle(myDowns, decorate_Downs,dataType_Tweed, 10);
	//��װ��Wylie
	myWyile = new testMethod();
	configurationStyle(myWyile, decorate_Wyile, dataType_Wyile, 10);
	//��װ��SoftTissue
	mySoftTissue = new testMethod();
	configurationStyle(mySoftTissue, decorate_Tissue, dataType_tissue, 9);
	//��װ��Ĭ�Ϸ���
	myDefault = new testMethod();
	configurationStyle(myDefault, decorate_Default, dataType_default, 10);

}

void MyItem::configurationStyle(testMethod * _myMethod, decorateDataType * _decorate[],const int *index,int arrayNum)
{
	for (int i = 0; i < arrayNum; i++)
	{
		switch (index[i])
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
			_decorate[i]->setPValue(value);
		}
		else
		{
			_decorate[i]->setTestMethod(_decorate[i - 1]);
			_decorate[i]->setPValue(value);
		}

	}
}

void MyItem::initializeLevelData(int level)
{
	textNumber = level;
	
	int  a=0;
	const int *temp;//��ȡ��ǰ�ؿ���������ȫ������
	switch (level)
	{
	case 0: a = 46;//���ֲ��Է����漰�ĵ����1cmA��1cmB������
			temp = DefalutPoint;
			break;
	case 1: a = 23;
			temp = Tweed;
			break;
	case 2: a = 18;
			temp = Downs;
			break;
	case 3: a = 13;
			temp = Wylie;
			break;
	case 4: a = 17;
			temp = tissue;
			break;
	default:
			a = 46;
			break;
	}
	if(text!=NULL)
	delete text;
	if (a >= 2)
	{
		text = new int[a];
		text[0] = 44;
		text[1] = 45;
		for (int i = 2; i < a; i++)
		{
			text[i] = temp[i - 2];
		}
	}	
	else
	{
		text = new int[46];//��ʼ�����Է�����Ĭ��Ϊȫ��
		text[0] = 44;
		text[1] = 45;
		for (int i = 2; i < 46; i++)
		{
			text[i] = i - 2;
		}
	}
	topNum = a;
	updataIndex = 0;
	//���ֳ�ʼ��
	//��Ӧ�±��¼��Ӧ������ȫ����0
	for (int i = 0; i < valueNum; i++)
		value[i] = -1;

	//�ж��Ƿ���Ѿ�ȷ�������»��ߺ�����
	judgeText2();
	this->update();
}

int MyItem::getCurrentDrawIndex()
{
	return text[currentDrawIndex];
}
