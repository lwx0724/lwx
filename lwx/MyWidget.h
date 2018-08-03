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
#include"MyDialog.h"
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
void emitTextInfo0();
void emitTextInfo1();
void emitTextInfo2();
void emitTextInfo3();
void emitTextInfo4();
void emitTextInfo5();
void openSettingDialog();
void infoRecvBigButtonState(int a);//�ı��ť״̬
void infoRecvGapNum(double gap);//�ı�̶ȳߵļ��
void infoRecvTextMessage(int n, double *value);
void infoRecvchangItem();//����Զ��尴ť���ź�
void infoRecvCustomPoint(int n, int *point);//��ȡ
private:
	QPoint point;
	bool pressed;
	int m_nBorder;
	//������
	TitleBar *pTitlebar;
	////��ʾͼƬ����	
	QGraphicsScene * m_pSence;
	InteractiveView *m_pView;
	MyItem *m_pItem;//װ��dcmͼƬ
	tutorialCartoon *m_tutorialCartoon;
	MyDialog *m_pSetting;
	//��ť
	QPushButton * m_pButtonItemmove;//�ƶ�item��ť
	QPushButton * m_pButtonDrawLine;//���߰�ť
	QPushButton * m_pButtonclearAll;//������е����������ʾ
	QButtonGroup *m_pGroup;//���Է�������Ϊһ��s
	QPushButton *m_pButtonMethod[5];//5�ַ�����ָ������
	QPushButton *customButton1;//�Զ��尴ť1
	QPushButton *settingButton1;//���ð�ť1
	

	
	QLabel *pLabelgroup;
	combinedButton *m_pButtonGroupWeight;//��ťȺweight

 ////С��ť��ʾ״̬��ͼ��
	QIcon  *pixmap_havePos;
	QIcon *pixmap_noPos;
	QIcon *pixmap_transparency;
	QIcon *pixmap_setting;
	QPushButton * smallGroup[46];
	QPushButton * bigGroup[46];

};
     