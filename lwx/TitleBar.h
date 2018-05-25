#pragma once

#include <QWidget>
#include<qlabel.h>
#include<qpushbutton.h>
class TitleBar : public QWidget
{
	Q_OBJECT

public:
  explicit	TitleBar(QWidget *parent = Q_NULLPTR);//explicit 放置构造函数的隐式构造，这里说明标题栏必须要有父窗口
  ~TitleBar();

protected:
  //双击标题栏进行界面的最大化/还原
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	//鼠标通过拖动标题栏拖动整个界面，用win32的方法
	virtual void mousePressEvent(QMouseEvent *event);
	virtual bool eventFilter(QObject *obj,QEvent *event);
private slots:
	void onClicked();//进行最小化、最大化/还原、关闭操作
	
	
private:
	//最大化
	void updateMaximize();

	

private:
	QLabel * m_pIconLabel;
	QLabel * m_pTitleLabel;
	QPushButton * m_pMinimizeButton;
	QPushButton * m_pMaximizeButton;
	QPushButton * m_pCloseButton;
};
