#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lwx.h"

class lwx : public QMainWindow
{
	Q_OBJECT

public:
	lwx(QWidget *parent = Q_NULLPTR);

private:
	Ui::lwxClass ui;
};
