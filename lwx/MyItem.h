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
	public QObject, public QGraphicsItem//1.要自定义添加信号槽必须要继承QObject。2.还要添加宏Q_OBJECT
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
	//获得当前需要画的点
	int getCurrentDrawIndex();
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
	void infoRecvClearAll();
	void infoRecvUpdata(int &a);//按下大按钮后，下次按下的点更新，指定位置的坐标
	void infoRecvClear(int &a);//有坐标的情况下，按下小按钮，清空坐标；无坐标的情况不能按下按钮，
	void infoRecvClear2(int &a);
	void infoRecvText(int a);//接受测试方法的信号infoRecvText
//更改坐标数组后发送信号然主界面更新按钮图片
signals:
	void changeInfo(int &a,int b);//改变的按钮序号，0为坐标未定，1为坐标确定,
signals:
	void changeCartoon(int index);//发送信息让动画随之改变，动画显示时下一个需要确定的点
signals:
	void showCurrentBigButton(int index);//发送现在刚确定坐标的按钮信息，让按钮群随之显示
signals:
	void changViewRuler(double gap);//给view发送信号，设定1cm的gap像素
signals:
	void changeTextHint(int n,double *value);//给View发送信号，改变文字提示
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
//需要更新的序号
	int updataIndex;
//需要清空的序号
	int clearIndex;
//当前需要画的点序号
	int currentDrawIndex;
//本轮读取的测试方法
	int *text;
//本轮测试方法的上限
	int topNum;
//本轮测试方法编号
	int textNumber;
//文字
	double *value;
//文字总共几个	
	int valueNum;
//结构点总共几个
	int structNumber;
//距离间隔
	double gapNum;
private:
	//画图需要用到的函数
	void drawPainterPathLine(QPainter * painter);
	void drawPoint(QPainter * painter,qreal x,qreal y);
	//void drawLine(QPainter * painter, qreal startx, qreal starty, qreal endx, qreal endy);//画线段
	 void drawText(QPainter * painter,qreal x,qreal y, const char * textContent);
	//void drawlongLine(QPainter * painter, QPointF firstPoint, QPointF secondPoint);//画直线
	//void drawRadial(QPainter * painter, QPointF firstPoint, QPointF secondPoint);//画射线，第一个参数为射线源点
	//void drawRule_Tweed(QPainter * painter, QVector<QPointF>& _newVector);
	void drawRule_default(QPainter *painter, QVector<QPointF>& _newVector);
	//计算连点间连线距离
	double lineDistance(QPointF p1,QPointF p2);
	double square(const double num);
	//double lineAngle(QPointF p1, QPointF p2, QPointF p3, QPointF p4);
	//void returnLineABC(QPointF p1, QPointF p2,double &A,double &B ,double &C);//返回一般式参数
	//不同测试方法的文字提示的判断流程
	//void tweedText(QVector<QPointF>& _newVector);
	//根据关卡判断需要发送哪些文字提示
//	void judgeText(QVector<QPointF>& _newVector);
	////找到第一个没被确定的点,这次确定这一个点
	void findFirstPoint();
	//判断需要清除的结构点是否在本轮需测试的方法中
	void judgeClear(int index);

private:
	//不同测试方法的文字提示的判断流程
	void tweedText2();
	//根据关卡判断需要发送哪些文字提示
	void judgeText2();
	//实现tweed
	void  drawRule_Tweed2(QPainter * painter, QVector<QPointF>& _newVector);
	//创建方法tweed等
	void  createMethod();
	//根据方法序号配置结构点计算类型
	void  configurationStyle(testMethod *_myMethod, decorateDataType * _decorate[],int arrayNum);
	testMethod *myTweed;
	//tweed方法所需配置的序号
	int *tweedIndex;
	decorateDataType * decorate_tweed[14];//记录需要配置的函数
	

};

