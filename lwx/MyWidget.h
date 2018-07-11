#pragma once
#include <QtWidgets/QWidget>
#include"TitleBar.h"
#include"qpushbutton.h"
#include <QPainter>
#include"commonHelper.h"
#include"MyItem.h"
#include<QGraphicsView>
#include<qgraphicsscene>
#include<qpushbutton.h>
#include"combinedButton.h"
#include"tutorialCartoon.h"
#include"InteractiveView.h"
#include"qicon.h"
#pragma execution_character_set("utf-8")
class MyWidget : public QWidget
{
	Q_OBJECT
public:
	MyWidget(QWidget *parent = Q_NULLPTR);
protected:
	void paintEvent(QPaintEvent *event);

signals:
void textInfoSend(int index);

public slots:
void infoRecvChangeButton(int &a, int b);//�ı�С��ť
void infoRecvParpare(int index);//Ԥ������
void emitTextInfo();
void infoRecvBigButtonState(int a);//�ı��ť״̬
void infoRecvGapNum(double gap);//�ı�̶ȳߵļ��
void infoRecvTextMessage(int n, double *value);

private:
	QPoint point;
	bool pressed;
	int m_nBorder;
	//������
	TitleBar *pTitlebar;
	////��ʾͼƬ����	
	QGraphicsScene * m_pSence;
//	QGraphicsView *	m_pView;
	InteractiveView *m_pView;
	MyItem *m_pItem;//װ��dcmͼƬ
	tutorialCartoon *m_tutorialCartoon;
	//��ť
	QPushButton * m_pButtonItemmove;//�ƶ�item��ť
	QPushButton * m_pButtonDrawLine;//���߰�ť
	QPushButton * m_pButtonclearAll;//������е����������ʾ
	QPushButton * m_pButtonTweed;
	QButtonGroup * m_pGroup;
	QLabel *pLabelgroup;
	combinedButton *m_pButtonGroupWeight;//��ťȺweight

 ////С��ť��ʾ״̬��ͼ��
	//QPixmap *pixmap_havePos;
	//QPixmap *pixmap_noPos;
	QIcon  *pixmap_havePos;
	QIcon *pixmap_noPos;
	QIcon *pixmap_transparency;
	QPushButton * smallGroup[46];
	QPushButton * bigGroup[46];
};
     