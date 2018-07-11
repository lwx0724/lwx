#pragma once
#include "qobject.h"
#include"qgraphicsitem.h"
#include"qpainter.h"
#include"qgraphicsscene.h"
#include"qgraphicsview.h"
#include"commonHelper.h"
#include<opencv2\opencv.hpp>
#include"globelVariable.h"
#include"concreteDataType.h"

#include"math.h"
class MyItem :
	public QObject, public QGraphicsItem//1.Ҫ�Զ�������źŲ۱���Ҫ�̳�QObject��2.��Ҫ��Ӻ�Q_OBJECT
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
enum ButtonState
	{
		STATE_MOVE,
		STATE_DRAW,
		STATE_UPDATA,
		STATE_CLEAR
	};
public:
	explicit MyItem(const char * fileName,qreal x,qreal y,QObject *parent =0);
	QRectF boundingRect() const;
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);
	//��õ�ǰ��Ҫ���ĵ�
	int getCurrentDrawIndex();
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
	void infoRecvClearAll();
	void infoRecvUpdata(int &a);//���´�ť���´ΰ��µĵ���£�ָ��λ�õ�����
	void infoRecvClear(int &a);//�����������£�����С��ť��������ꣻ�������������ܰ��°�ť��
	void infoRecvClear2(int &a);
	void infoRecvText(int a);//���ܲ��Է������ź�infoRecvText
//����������������ź�Ȼ��������°�ťͼƬ
signals:
	void changeInfo(int &a,int b);//�ı�İ�ť��ţ�0Ϊ����δ����1Ϊ����ȷ��,
signals:
	void changeCartoon(int index);//������Ϣ�ö�����֮�ı䣬������ʾʱ��һ����Ҫȷ���ĵ�
signals:
	void showCurrentBigButton(int index);//�������ڸ�ȷ������İ�ť��Ϣ���ð�ťȺ��֮��ʾ
signals:
	void changViewRuler(double gap);//��view�����źţ��趨1cm��gap����
signals:
	void changeTextHint(int n,double *value);//��View�����źţ��ı�������ʾ
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
//��Ҫ���µ����
	int updataIndex;
//��Ҫ��յ����
	int clearIndex;
//��ǰ��Ҫ���ĵ����
	int currentDrawIndex;
//���ֶ�ȡ�Ĳ��Է���
	int *text;
//���ֲ��Է���������
	int topNum;
//���ֲ��Է������
	int textNumber;
//����
	double *value;
//�����ܹ�����	
	int valueNum;
//�ṹ���ܹ�����
	int structNumber;
//������
	double gapNum;
private:
	//��ͼ��Ҫ�õ��ĺ���
	void drawPainterPathLine(QPainter * painter);
	void drawPoint(QPainter * painter,qreal x,qreal y);
	//void drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy);//���߶�
	 void drawText(QPainter * painter,qreal x,qreal y, const char * textContent);
	//void drawlongLine(QPainter * painter, QPointF firstPoint, QPointF secondPoint);//��ֱ��
	//void drawRadial(QPainter * painter, QPointF firstPoint, QPointF secondPoint);//�����ߣ���һ������Ϊ����Դ��
	//void drawRule_Tweed(QPainter * painter, QVector<QPointF>& _newVector);
	void drawRule_default(QPainter *painter, QVector<QPointF>& _newVector);
	//������������߾���
	double lineDistance(QPointF p1,QPointF p2);
	double square(const double num);
	//double lineAngle(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
	//void returnLineABC(QPointF p1, QPointF p2,double &A,double &B ,double &C);//����һ��ʽ����
	//��ͬ���Է�����������ʾ���ж�����
	//void tweedText(QVector<QPointF>& _newVector);
	//���ݹؿ��ж���Ҫ������Щ������ʾ
//	void judgeText(QVector<QPointF>& _newVector);
	////�ҵ���һ��û��ȷ���ĵ�,���ȷ����һ����
	void findFirstPoint();
	//�ж���Ҫ����Ľṹ���Ƿ��ڱ�������Եķ�����
	void judgeClear(int index);

private:
	//��ͬ���Է�����������ʾ���ж�����
	void tweedText2();
	//���ݹؿ��ж���Ҫ������Щ������ʾ
	void judgeText2();
	//ʵ��tweed
	void  drawRule_Tweed2(QPainter * painter, QVector<QPointF>& _newVector);
	//��������tweed��
	void  createMethod();
	//���ݷ���������ýṹ���������
	void  configurationStyle(testMethod *_myMethod, decorateDataType * _decorate[],int arrayNum);
	testMethod *myTweed;
	//tweed�����������õ����
	int *tweedIndex;
	decorateDataType * decorate_tweed[14];//��¼��Ҫ���õĺ���
	

};

