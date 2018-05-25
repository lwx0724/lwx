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
//���������淢���ź�
	void infoRecvMove();
	void infoRecvDraw();
private:
	QImage  *m_dcmImage;
	cv::Mat mat;//ԭͼ��С
	cv::Mat mat2;//�任��С
	//item ��С
	int m_x;
	int m_y;
	//��¼���㼯
	//QVector<QPointF>  linePos;
	//����ʱ���ù���
	QPen *pen;
	QBrush *brush;
	//�����ı�ʱ����
	QFont *font;
	//��ť״̬�����벻ͬ������¼�����
	ButtonState m_state;
private:
	void drawPainterPathLine(QPainter * painter);
	void drawPoint(QPainter * painter,qreal x,qreal y);
	void drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy);
	void drawText(QPainter * painter,qreal x,qreal y, const char * textContent);
};

