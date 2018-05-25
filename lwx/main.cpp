#include "lwx.h"
#include <QtWidgets/QApplication>
#include<MyWidget.h>
#include"commonHelper.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	commonHelper::setStyle("style.qss");
	//painterPractice w;
	//w.show();
	MyWidget w;
	w.show();
	return a.exec();
}
