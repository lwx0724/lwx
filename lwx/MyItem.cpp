#include "MyItem.h"
//#include"FormatAndIos.h"
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<qpainter.h>


MyItem::MyItem(const char * fileName, qreal x, qreal y,QObject * parent):QObject(parent)
{
	m_dcmImage = new QImage();
	
    commonHelper::dcm2Mat(fileName,mat);
	cv::resize(mat, mat2, cv::Size(x, y));
	mat2 = 255 - mat2;
	*m_dcmImage =commonHelper::MatToQImage(mat2);
	//m_dcmImage->scaled(x,y,Qt::KeepAspectRatio);
	m_x = x;
	m_y = y;
	setCursor(Qt::OpenHandCursor);
	//设置图元可以移动
 	setFlags(QGraphicsItem::ItemIsMovable);
	//开启itemchange的检测
    setFlag(ItemSendsGeometryChanges, true);

	//初始化画画工具
	pen = new QPen();
	brush =new QBrush();

	//初始化鼠标按钮状态，默认是移动图片
	m_state = STATE_MOVE;

	//初始化字体
	font = new QFont();
	font->setFamily("Microsoft YaHei");
	//大小
	font->setPointSize(8);
	//设置字符间距
	font->setLetterSpacing(QFont::AbsoluteSpacing,2);

}


QRectF MyItem::boundingRect() const
{
	//使图元原点在图元的中心
	//return QRectF(-m_dcmImage->width()/2,-m_dcmImage->height()/2,m_dcmImage->width(),m_dcmImage->height()/2);
	//使图元原点在图元左上角
	return QRectF(0, 0,m_x, m_y);
}
MyItem::~MyItem()
{

}

void MyItem::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
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
			//	QPointF point = mapToScene(event->pos());//将视图坐标转换为场景坐标(此处场景坐标和视图坐标一致)
			//	qDebug() << "view->mapToScene" << point;
			linePos.push_back(event->pos());
			update();
		}
	}
	else if (m_state == STATE_MOVE)
	{
		setCursor(Qt::ClosedHandCursor);
		QGraphicsItem::mousePressEvent(event);
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
}

void MyItem::infoRecvDraw()
{
	m_state = STATE_DRAW;
	setCursor(Qt::CrossCursor);
}
void MyItem::infoRecvMove()
{
	m_state = STATE_MOVE;
	setCursor(Qt::OpenHandCursor);
}
void MyItem::drawPainterPathLine(QPainter * painter)
{
	painter->setRenderHint(QPainter::Antialiasing, true);
	if (linePos.size() == 1)
	{
		drawPoint(painter, linePos[0].x(), linePos[0].y());
		drawText(painter, linePos[0].x(), linePos[0].y(), toothPosition_ENGLISH[0]);
	}
	else if (linePos.size() > 1)
	{//先画线后画点
		for (int i = 1; i < linePos.size(); i++)
		{
			drawLine(painter,linePos[i-1].x(),linePos[i-1].y(),linePos[i].x(),linePos[i].y());
		}
		for (int i = 0; i < linePos.size(); i++)
		{
			drawPoint(painter, linePos[i].x(), linePos[i].y());
		}
		//最后绘制文字
		for (int i = 0; i < linePos.size(); i++)
		{
			drawText(painter, linePos[i].x(), linePos[i].y(), toothPosition_ENGLISH[i]);
		}
	}

}

void MyItem::drawPoint(QPainter * painter,qreal x,qreal y)
{
	
	//设置画点时画笔的颜色，线型,线宽
	pen->setColor(QColor(240, 40, 60));
	pen->setStyle(Qt::SolidLine);
	pen->setWidth(1);
	painter->setPen(*pen);
	//设置笔刷,画实心矩形点
	brush->setStyle(Qt::SolidPattern);
	brush->setColor(QColor(240, 40, 60));
	painter->setBrush(*brush);
	//QRectF rectangle(x, y, 5, 5);
	//painter->drawRoundedRect(rectangle,15.0, 15.0);
	painter->drawRect(QRect(x-3, y-3, 6,6));
}

void MyItem::drawLine(QPainter * painter,qreal startx,qreal starty,qreal endx,qreal endy)
{
	//划线深蓝色（0,0,139）
	pen->setColor(QColor(0, 0, 139));
	pen->setStyle(Qt::SolidLine);
	pen->setWidth(2);
	painter->setPen(*pen);
	painter->drawLine(startx,starty,endx,endy);
}

void MyItem::drawText(QPainter * painter, qreal x, qreal y, const char * textContent)
{
	//使用字体
	painter->setFont(*font);
	pen->setColor(QColor(240, 40, 60));
	painter->setPen(*pen);
	painter->drawText(x+10,y,textContent);
}

