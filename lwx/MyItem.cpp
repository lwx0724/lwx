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
	//设置图元可以移动
	setFlags(QGraphicsItem::ItemIsMovable);
	//开启itemchange的检测
	setFlag(ItemSendsGeometryChanges, true);

	//初始化鼠标按钮状态，默认是移动图片
	m_state = STATE_DRAW;
	setCursor(Qt::CrossCursor);
	updataIndex = 0;
	currentDrawIndex = 0;
	gapNum = 60.0;
	topNum = 46;//初始化当前测试数量上限
	textNumber = 0;
	valueNum = 41;//23
	structNumber = 46;

	text = new int[46];//初始化测试方法，默认为全部
	text[0] = 44;
	text[1] = 45;
	for (int i = 2; i < 46; i++)
	{
		text[i] = i - 2;
	}
	//初始化记录文字的Value数组
	value = new double[valueNum];
	for (int i = 0; i < valueNum; i++)
		value[i] = -1;
	
	createMethod();
	myDefind = NULL;
	
	connect(this, SIGNAL(changeInfo(int &, int )), parent, SLOT(infoRecvChangeButton(int &,int )));
	connect(this, SIGNAL(changeCartoon(int )), parent, SLOT(infoRecvParpare(int )));
	connect(this, SIGNAL(showCurrentBigButton(int)), parent, SLOT(infoRecvBigButtonState(int)));
	connect(this, SIGNAL(changViewRuler(double)), parent, SLOT(infoRecvGapNum(double)));
	connect(this, SIGNAL(changeTextHint(int, double *)), parent, SLOT(infoRecvTextMessage(int, double *)));
	connect(this, SIGNAL(changeCustomPoint(int, int *)), parent, SLOT(infoRecvCustomPoint(int, int *)));
}


QRectF MyItem::boundingRect() const
{
	//使图元原点在图元的中心
	//return QRectF(-m_dcmImage->width()/2,-m_dcmImage->height()/2,m_dcmImage->width(),m_dcmImage->height()/2);
	//使图元原点在图元左上角
	return QRectF(0, 0,m_x, m_y);
}

void MyItem::setDefindVector(QVector<int> a)
{	
	for (int i = defindVector.size(); i > 0; i--)
	{
		defindVector.remove(i-1);
	}
	for (int i = 0; i < a.size(); i++)
	{
		defindVector.append(a.at(i));
	}	


	//配置自定义方法
	creatMyDefind();
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
				//判断是否更改刻度尺范围
				if ((linePos[text[0]] != QPointF(-200.0, -200.0) && currentDrawIndex ==1)||(linePos[text[1]] != QPointF(-200.0, -200.0) && currentDrawIndex == 0))
				{
					gapNum = lineDistance(linePos[text[0]], linePos[text[1]]);
					emit changViewRuler(gapNum);			
				}
				//判断需要发送哪些文字提示
				//judgeText(linePos);//+++++++++++++
					judgeText2();
				emit changeInfo(text[currentDrawIndex], 1);

				////当前确定的点的下一个需要确定的点，如果当前点被确定，则再找下一个
					//第一个需要确定的点
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
		//判断是否更改刻度尺范围
		if ((linePos[text[0]] != QPointF(-200.0, -200.0) && updataIndex == 45) || (linePos[text[1]] != QPointF(-200.0, -200.0) && updataIndex == 44))
		{
			gapNum = lineDistance(linePos[text[0]], linePos[text[1]]);
			emit changViewRuler(gapNum);
		}
		//判断需要发送哪些文字提示
		//judgeText(linePos);//++++++++++++++++
			judgeText2();
		emit changeInfo(updataIndex, 1);
////找到第一个没被确定的点,这次确定这一个点
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
	emit showCurrentBigButton(updataIndex);//跟随按下状态
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
	//判断需要发送哪些文字提示
	//judgeText(linePos);//+++++++++++
		judgeText2();
	//判断需要清除的结构点是否在本轮需测试的方法中
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
		break;
	case 5:
		initializeLevelData2(5);//初始化自定义
		break;
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
	case 5:
		drawRule_X2(painter, linePos, decorate_defind);//自定义方法
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
	////找到第一个没被确定的点,这次确定这一个点,并同步按钮群状态和动画状态
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
		emit showCurrentBigButton(text[currentDrawIndex]);//更新后大按钮状态归位
	}
	else
	{
		emit showCurrentBigButton(-1);//如果全部点确定，大按钮状态跟随取消
		emit changeCartoon(-1);//所有点都确定时，不再显示动画，发送-1
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
	case 5:
		if(decorate_defind.size() >0)
			decorate_defind.at(decorate_defind.size() - 1)->datacalculate();
		break;
	default:
		break;
	}

	////检查value是否有非-1，若有则发送信号
	//for (int i = 0; i < valueNum; i++)
	//{
	//	if (value[i] != -1)
	//	{
	//		emit changeTextHint(valueNum, value);
	//		break;
	//	}
	//}
	emit changeTextHint(valueNum, value);
}



void MyItem::drawRule_X(QPainter * painter, QVector<QPointF>& _newVector, decorateDataType *decorate_X[],int num)
{
	//画线
	//对装饰画线函数赋值painter
	for (int i = 0; i < num; i++)
	{
		decorate_X[i]->setQPainter(painter);
	}
	if (num > 0)
	{
		decorate_X[num - 1]->drawLineJudge();
		//换标准线
		decorate_X[num - 1]->drawStandardLine(painter, _newVector);
		//结构点画点
		decorate_X[num - 1]->drawStructurePoint(painter, _newVector, structNumber);
		//最后绘制结构点文字
		decorate_X[num - 1]->drawStructureText(painter, _newVector, structNumber);
	}	
}
void MyItem::drawRule_X2(QPainter * painter, QVector<QPointF>& _newVector, QVector<decorateDataType *> &decorate_defind)
{
	//画线
	//对装饰画线函数赋值painter
	int num = decorate_defind.size();
	for (int i = 0; i < num; i++)
	{
		decorate_defind[i]->setQPainter(painter);
	}
	if (num> 0)
	{
		decorate_defind[num - 1]->drawLineJudge();
		//换标准线
		decorate_defind[num - 1]->drawStandardLine(painter, _newVector);
		//结构点画点
		decorate_defind[num - 1]->drawStructurePoint(painter, _newVector, structNumber);
		//最后绘制结构点文字
		decorate_defind[num - 1]->drawStructureText(painter, _newVector, structNumber);
	}
}

void MyItem::createMethod()
{
	//逐步装饰tweed
	myTweed = new testMethod();
	configurationStyle(myTweed,decorate_Tweed,dataType_Tweed,14);
	//逐步装饰myDowns
	myDowns = new testMethod();
	configurationStyle(myDowns, decorate_Downs, dataType_Downs, 10);
	//逐步装饰Wylie
	myWyile = new testMethod();
	configurationStyle(myWyile, decorate_Wyile, dataType_Wyile, 10);
	//逐步装饰SoftTissue
	mySoftTissue = new testMethod();
	configurationStyle(mySoftTissue, decorate_Tissue, dataType_tissue, 9);
	//逐步装饰默认方法
	myDefault = new testMethod();
	configurationStyle(myDefault, decorate_Default, dataType_default, 10);

}

void MyItem:: creatMyDefind()
{
	//删除前自定义方法
	if (myDefind != NULL)
	{
		delete myDefind;
		myDefind = NULL;
	}
	
	//创建新自定义方法
	myDefind = new testMethod();
	if (decorate_defind.size() != 0)
	{
		for (int i = decorate_defind.size(); i>0; i--)
		{
			delete decorate_defind.at(i-1);
			decorate_defind[i-1] = NULL;
			decorate_defind.remove(i-1);
		}
	}

	//首先要把前次点容器清空
	for (int i = defindPoint.size(); i > 0; i--)
	{
		defindPoint.remove(i - 1);
	}

	//创建decorate_defind个数

	//创建自定义方法
	for (int i = 0; i < defindVector.size(); i++)
	{
		switch (defindVector.at(i))
		{
		case 0:
			decorate_defind.append(new FMIA(linePos, m_x, m_y));//new FMIA(linePos, m_x, m_y)
			break;
		case 1:
			decorate_defind.append(new FMA(linePos, m_x, m_y));
			break;
		case 2:
			decorate_defind.append(new IMPA(linePos, m_x, m_y));
			break;
		case 3:
			decorate_defind.append(new SNA(linePos, m_x, m_y));
			break;
		case 4:
			decorate_defind.append(new SNB2(linePos, m_x, m_y));
			break;
		case 5:
			decorate_defind.append(new ANB(linePos, m_x, m_y));
			break;
		case 6:
			decorate_defind.append(new AOBO(linePos, m_x, m_y));
			break;
		case 7:
			decorate_defind.append(new OP(linePos, m_x, m_y));
			break;
		case 8:
			decorate_defind.append(new Z(linePos, m_x, m_y));
			break;
		case 9:
			decorate_defind.append(new labrumDistance(linePos, m_x, m_y));
			break;
		case 10:
			decorate_defind.append(new chinDistance(linePos, m_x, m_y));
			break;
		case 11:
			decorate_defind.append(new ART1(linePos, m_x, m_y));
			break;
		case 12:
			decorate_defind.append(new PNSANS(linePos, m_x, m_y));
			break;
		case 13:
			decorate_defind.append(new surfaceHeightRatio(linePos, m_x, m_y));
			break;
		case 14:
			decorate_defind.append(new surfaceAngle(linePos, m_x, m_y));
			break;
		case 15:
			decorate_defind.append(new jawRaiseAngle(linePos, m_x, m_y));
			break;
		case 16:
			decorate_defind.append(new ABSurfaceAngle(linePos, m_x, m_y));
			break;
		case 17:
			decorate_defind.append(new underjawSurfaceAngle(linePos, m_x, m_y));
			break;
		case 18:
			decorate_defind.append(new YAxisAngle(linePos, m_x, m_y));
			break;
		case 19:
			decorate_defind.append(new UIUIA(linePos, m_x, m_y));
			break;
		case 20:
			decorate_defind.append(new LIMP(linePos, m_x, m_y));
			break;
		case 21:
			decorate_defind.append(new LIOP(linePos, m_x, m_y));
			break;
		case 22:
			decorate_defind.append(new UI_APog(linePos, m_x, m_y));
			break;
		case 23:
			decorate_defind.append(new Co_Pog(linePos, m_x, m_y));
			break;
		case 24:
			decorate_defind.append(new Ptm_S(linePos, m_x, m_y));
			break;
		case 25:
			decorate_defind.append(new ANS_Ptm(linePos, m_x, m_y));
			break;
		case 26:
			decorate_defind.append(new Co_S(linePos, m_x, m_y));
			break;
		case 27:
			decorate_defind.append(new N_Me(linePos, m_x, m_y));
			break;
		case 28:
			decorate_defind.append(new N_ANS(linePos, m_x, m_y));
			break;
		case 29:
			decorate_defind.append(new ANS_Me(linePos, m_x, m_y));
			break;
		case 30:
			decorate_defind.append(new N_ANS_Ratio(linePos, m_x, m_y));
			break;
		case 31:
			decorate_defind.append(new ANS_Me_Ratio(linePos, m_x, m_y));
			break;
		case 32:
			decorate_defind.append(new Ptm_U6(linePos, m_x, m_y));
			break;
		case 33:
			decorate_defind.append(new noseLabrumAngle(linePos, m_x, m_y));
			break;
		case 34:
			decorate_defind.append(new upperlipSlope(linePos, m_x, m_y));
			break;
		case 35:
			decorate_defind.append(new underSlope(linePos, m_x, m_y));
			break;
		case 36:
			decorate_defind.append(new CmSnUL(linePos, m_x, m_y));
			break;
		case 37:
			decorate_defind.append(new surfaceRaiseAngle(linePos, m_x, m_y));
			break;
		case 38:
			decorate_defind.append(new allSurfaceRaiseAngle(linePos, m_x, m_y));
			break;
		case 39:
			decorate_defind.append(new LL_B_Pos(linePos, m_x, m_y));
			break;
		case 40:
			decorate_defind.append(new FCA(linePos, m_x, m_y));
			break;

		default:
			break;
		}
		if (i == 0)
		{
			decorate_defind[i]->setTestMethod(myDefind);
			decorate_defind[i]->setPValue(value);
		}
		else
		{
			decorate_defind[i]->setTestMethod(decorate_defind[i - 1]);
			decorate_defind[i]->setPValue(value);
		}
		//统计本次自定义所需的点,添加不重复的点,
		// 对自定义所需点进行排序，从小到大
		int currentPointNum = defindPoint.size();
		QVector<int> temp;
		decorate_defind[i]->getPoint(temp);
		bool repitititon =false;
		//for (int i = 0; i < temp.size(); i++)
		//{
		//	for (int j = 0; j < currentPointNum; j++)
		//	{
		//		if (temp.at(i) == defindPoint.at(j))
		//		{
		//			break;
		//			repitititon = true;
		//		}
		//	}
		//	if (!repitititon)
		//	{
		//	}
		//}
		for (int n = 0; n < temp.size(); n++)
		{
			if (defindPoint.size() == 0)
			{
				defindPoint.append(temp.at(n));
			}
			else
			{
				for (int m = 0; m < defindPoint.size(); m++)
				{
					if (temp.at(n) > defindPoint.at(m))
					{
						continue;
					}
					else if (temp.at(n) == defindPoint.at(m))
					{
						break;
						repitititon = true;
					}
					else
					{
						defindPoint.insert(m, temp.at(n));
						break;
					}
				}

				if (!repitititon)
					defindPoint.append(temp.at(n));
			}
			
		}
			
	}



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
	const int *temp;//获取当前关卡的所需点的全局数组
	switch (level)
	{
	case 0: a = 46;//本轮测试方法涉及的点加上1cmA和1cmB这两个
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
		text = new int[46];//初始化测试方法，默认为全部
		text[0] = 44;
		text[1] = 45;
		for (int i = 2; i < 46; i++)
		{
			text[i] = i - 2;
		}
	}
	topNum = a;
	updataIndex = 0;
	//文字初始化
	//对应下标记录对应的数据全部归0
	for (int i = 0; i < valueNum; i++)
		value[i] = -1;

	//判断是否点已经确定，更新划线和文字
	judgeText2();
	this->update();
}

void MyItem::initializeLevelData2(int level)
{

	int a = defindVector.size();//测试项数量
	int b = defindPoint.size()+2;//测试点数量
	textNumber = level;
	if (text != NULL)
	{
		delete text;
		text = NULL;
	}
		
	if (a >0)
	{
		
		text = new int[b];//测试项对应点的数量
		text[0] = 44;
		text[1] = 45;
		for (int i = 2; i < b; i++)
		{
			text[i] = defindPoint[i - 2];//自定义方法所含对应点
		}
		emit changeCustomPoint(b,text);
		topNum = b;
		updataIndex = 0;
		for (int i = 0; i < valueNum; i++)
			value[i] = -1;
		//判断是否点已经确定，更新划线和文字
		judgeText2();
		this->update();
	}
	else
	{		
		text = new int[2];//测试项对应点的数量
		text[0] = 44;
		text[1] = 45;
		topNum = 0;
		updataIndex = 0;
		//for (int i = 0; i < valueNum; i++)
		//	value[i] = -1;
		////判断是否点已经确定，更新划线和文字
		//judgeText2();
		QMessageBox::information(NULL, "提示！", "未设置可选项！", QMessageBox::Ok);
		//this->update();	
	}
		
}

int MyItem::getCurrentDrawIndex()
{
	return text[currentDrawIndex];
}
