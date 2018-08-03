#pragma once
#include<qpushbutton.h>
#include<qstring.h>
#include<qobject.h>
#include<qpixmap.h>
#include"globelVariable.h"
#include"qlabel.h"
#include"qbuttongroup.h"
#include"qevent.h"
#include"qdebug.h"
#include"MyItem.h"
#include"tutorialCartoon.h"
#pragma execution_character_set("utf-8")
//������ťȺ
class combinedButton : public QWidget
{
	Q_OBJECT
public:
	combinedButton(qreal _posX,qreal _posY, MyItem *item, tutorialCartoon *cartoon,QWidget *parent = 0);
	bool eventFilter(QObject *obj,QEvent *e);
	void getSmallGroup(QPushButton *_smallGroup[]);
	void setSmallGroup(int a,QPushButton *_temp);
	void getBigGroup(QPushButton *_bigGroup[]);
	void getBigGroup(int a, QPushButton *_temp);
	void setCustomPoint(int _num,int *_customPoint);

	//void paintEvent(QPaintEvent*e);
////����ÿ����ť���·�����Ϣ�ź�
signals:
void buttonNumberInfo(int &a); //����Ҫ�볡��������Ϣ����Ҫ�򶯻������ź�
signals:
void smallInfo(int &a);//��������ʱ��С��ťͼƬ
signals:
void smallInfo2(int &a);//����ʱ

////���°�ť�Ĳۺ���
public slots:
	void infoRecvText(int a);

//signals:
//	void pickInfoSend();

//public slots:
//	void emit_signal_buttonNumberInfo();

	
private:
	qreal posX;//��ťλ��
	qreal posY;
	bool bigButtonReleased;
	bool smallButtonReleased;
	QString bigContent;
	QString bigTip;
	QPushButton *bigButton_0;
	QPushButton *smallButton_0;
	
	//ButtonGroup
	QButtonGroup *bgroup;
	//��ťָ������+2��׼��
	QPushButton *bigGroup[46];
	QPushButton *smallGroup[46];
	//��ť��ǩ
	QLabel *pLabelgroup[5];

	//��¼��ǰ���°�ť�����
	int  currentIndex_big;
	int currentIndex_small;
	int currentIndex_standard;
	////С��ť��ʾ״̬��ͼ��
	QPixmap *pixmap_havePos;
	QPixmap *pixmap_noPos;

	//���ֶ�ȡ�Ĳ��Է���
	int *text;
	//���ֲ��Է���������
	int topNum;
	//���Է���ͼ���Ƿ��ʼ��,��������ͬһ����ť��������������ťʱ����
	bool bInitialize;
	//��ʼ��С��ťͼƬ
	void initializeSmallButton(int level);
	//�Զ����ʼ��С��ť
	void initializeSmallButton2();

	//�Զ��������
	int *customPoint;
	int num;//��������1cma,1cmb
};

