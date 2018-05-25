#pragma once

#include <QWidget>
#include<qlabel.h>
#include<qpushbutton.h>
class TitleBar : public QWidget
{
	Q_OBJECT

public:
  explicit	TitleBar(QWidget *parent = Q_NULLPTR);//explicit ���ù��캯������ʽ���죬����˵������������Ҫ�и�����
  ~TitleBar();

protected:
  //˫�����������н�������/��ԭ
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	//���ͨ���϶��������϶��������棬��win32�ķ���
	virtual void mousePressEvent(QMouseEvent *event);
	virtual bool eventFilter(QObject *obj,QEvent *event);
private slots:
	void onClicked();//������С�������/��ԭ���رղ���
	
	
private:
	//���
	void updateMaximize();

	

private:
	QLabel * m_pIconLabel;
	QLabel * m_pTitleLabel;
	QPushButton * m_pMinimizeButton;
	QPushButton * m_pMaximizeButton;
	QPushButton * m_pCloseButton;
};
