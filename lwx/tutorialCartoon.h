#pragma once
#include<qlabel.h>
#include<qimage.h>
#include<qpixmap.h>
#include"qpainter.h"
#include<qtimer.h>
#include<qpainterpath.h>
#include"globelVariable.h"
#pragma execution_character_set("utf-8")
class tutorialCartoon : public QLabel
{
	Q_OBJECT
public:
	tutorialCartoon(const char*fileName, QWidget *parent = 0);
	void paintEvent(QPaintEvent*e);
	// ��ʱˢ��
	void timerEvent(QTimerEvent *event);
	int  getCurerntCartoon();
	void setCurnetCattoon(const int &a);
//signals:
//	void updateInfo();
public slots:
	//void infoRecvUpdate();
	void infoRecvCartoon(int &index);//���°�ť�󣬶�Ӧ�Ķ�����ʾ����

private:
	void drawPoint(qreal x, qreal y ,QPainter *painter);//����
	void drawArrows(qreal x,qreal y,QPainter *painter);//����ͷ
	void writeText(qreal x, qreal y, const char * textContent, QPainter *painter);//дӢ���ı�
	void writeChinesText(const char * textContent, QPainter *painter);
	QImage * showImage;
	//����ʱ���ù���
	QPen *pen;
	QBrush *brush;
	QFont *font;
	//�ػ�Ķ�ʱ��
//	QTimer *timer1;

	int T1;//���ֵļ�ʱ��
	int T2;//��ʧ�ļ�ʱ��
	bool bDraw;
	//��ǰ��ʾ�������
	int cartoonIndex;

};