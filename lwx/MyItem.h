#pragma once
#include "qobject.h"
#include"qgraphicsitem.h"
#include"qpainter.h"
#include"qgraphicsscene.h"
#include"qgraphicsview.h"
#include"commonHelper.h"
#include<opencv2\opencv.hpp>
#include"globelVariable.h"

class MyItem :
	public QObject, public QGraphicsItem
{
	Q_OBJECT
enum ButtonState
	{
		STATE_MOVE,
		STATE_DRAW
	};
public:
	explicit MyItem(const char * fileName,qreal x,qreal y,QObject *parent =0);
	QRectF boundingRect() const;
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);
	~MyItem();
protected:
	void paint(QPainter *painter,const QStyleOptionGraphicsItem *,QWidget *);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public slots:
//接受主界面发送信号
	void infoRecvMove();
	void infoRecvDraw();
private:
	QImage  *m_dcmImage;
	cv::Mat mat;//原图大小
	cv::Mat mat2;//变换大小
	//item 大小
	int m_x;
	int m_y;
	//记录鼠标点集
	//QVector<QPointF>  linePos;
	//画画时所用工具
	QPen *pen;
	QBrush *brush;
	//绘制文本时字体
	QFont *font;
	//按钮状态，进入不同的鼠标事件处理
	ButtonState m_state;
private:
	void drawPainterPathLine(QPainter * painter);
	void drawPoint(QPainter * painter,qreal x,qreal y);
	void drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy);
	void drawText(QPainter * painter,qreal x,qreal y, const char * textContent);
};

