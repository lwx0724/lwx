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
	QLabel *m_pLabel1;//标签：可选分析项
	QLabel *m_pLabel2;//标签：已选分析项
	QComboBox *m_pCob;//下拉选项
	QPushButton *m_ButtonUp;
	QPushButton *m_ButtonDown;
	QPushButton *m_OneGet;
	QPushButton *m_AllGet;
	QPushButton *m_OneReturn;
	QPushButton *m_AllReturn;
	QPushButton *m_ok;
	QPushButton *m_cannel;

	QListWidget *listWidget1;//可选项
	QListWidget *listWidget2;//已选项

	void changeItem();//根据当前下拉列表更换可选项item
	void judgeExist(int existNum,int currentAddItemIndex,bool &exist);//判断当前要添加的item是否已经存在

	int listItemNum;//当前item数量
	int comboBoxLevel;//下拉列表选择的序号
	int currentSelectItemIndex;//当前左QlistWidget1选中的item序号
	int currentSelectItemIndex2;//当前右QlistWidget2选中的item序号
	QVector<int> hadSelectItem;//已经确认的已选项
};

