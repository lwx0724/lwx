/********************************************************************************
** Form generated from reading UI file 'lwx.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LWX_H
#define UI_LWX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lwxClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lwxClass)
    {
        if (lwxClass->objectName().isEmpty())
            lwxClass->setObjectName(QStringLiteral("lwxClass"));
        lwxClass->resize(600, 400);
        menuBar = new QMenuBar(lwxClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        lwxClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lwxClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lwxClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lwxClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lwxClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lwxClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lwxClass->setStatusBar(statusBar);

        retranslateUi(lwxClass);

        QMetaObject::connectSlotsByName(lwxClass);
    } // setupUi

    void retranslateUi(QMainWindow *lwxClass)
    {
        lwxClass->setWindowTitle(QApplication::translate("lwxClass", "lwx", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class lwxClass: public Ui_lwxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LWX_H
