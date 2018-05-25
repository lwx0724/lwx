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
#pragma execution_character_set("utf-8")
class MyWidget : public QWidget
{
	Q_OBJECT
public:
	MyWidget(QWidget *parent = Q_NULLPTR);
protected:
	void paintEvent(QPaintEvent *event);
//	void mousePressEvent(QMouseEvent *event);
//	void mouseMoveEvent(QMouseEvent *event);
//	void mouseReleaseEvent(QMouseEvent *event);

//�����ƶ�������Ϣ�ź�
signals:
void moveInfoSend();
signals:
void drawInfoSend();
//����OpenDcmButton��Ӧ�Ĳۺ���

//�������������
	//bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:
	QPoint point;
	bool pressed;
	int m_nBorder;
	//������
	TitleBar *pTitlebar;
	////��ʾͼƬ����	
	QGraphicsScene * m_pSence;
	QGraphicsView *	m_pView;
	MyItem *m_pItem;//װ��dcmͼƬ
	//��ť
	QPushButton * m_pButtonItemmove;//�ƶ�item��ť
	QPushButton * m_pButtonDrawLine;//���߰�ť
};
     