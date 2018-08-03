#pragma once
#include<qdialog.h>
#include"QPushButton.h"
#include"qlabel.h"
#include <QComboBox>
#include<qlistwidget.h>
#include"globelVariable.h"
#include<qdebug.h>
#pragma execution_character_set("utf-8")
class MyDialog: public QDialog
{
	Q_OBJECT
public:
	explicit MyDialog(QWidget *parent =0);
	void getVector(QVector<int> &a);
	
	~MyDialog();

public slots:
	void indexChanged(int a);
	void listWidgetItemUp();
	void listWidgetItemDown();
	void acquireItemIndex();
	void acquireItemIndex2();
	void addOne();
	void addAll();
	void deleteOne();
	void deleteAll();
	void ok();
	void cannel();
signals:
void changeVectorInfo();


private:
	QLabel *m_pLabel1;//��ǩ����ѡ������
	QLabel *m_pLabel2;//��ǩ����ѡ������
	QComboBox *m_pCob;//����ѡ��
	QPushButton *m_ButtonUp;
	QPushButton *m_ButtonDown;
	QPushButton *m_OneGet;
	QPushButton *m_AllGet;
	QPushButton *m_OneReturn;
	QPushButton *m_AllReturn;
	QPushButton *m_ok;
	QPushButton *m_cannel;

	QListWidget *listWidget1;//��ѡ��
	QListWidget *listWidget2;//��ѡ��

	void changeItem();//���ݵ�ǰ�����б������ѡ��item
	void judgeExist(int existNum,int currentAddItemIndex,bool &exist);//�жϵ�ǰҪ��ӵ�item�Ƿ��Ѿ�����

	int listItemNum;//��ǰitem����
	int comboBoxLevel;//�����б�ѡ������
	int currentSelectItemIndex;//��ǰ��QlistWidget1ѡ�е�item���
	int currentSelectItemIndex2;//��ǰ��QlistWidget2ѡ�е�item���
	QVector<int> hadSelectItem;//�Ѿ�ȷ�ϵ���ѡ��
};

