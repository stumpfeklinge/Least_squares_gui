/********************************************************************************
** Form generated from reading UI file 'graf.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAF_H
#define UI_GRAF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graf
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *widget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Graf)
    {
        if (Graf->objectName().isEmpty())
            Graf->setObjectName(QString::fromUtf8("Graf"));
        Graf->resize(800, 854);
        centralwidget = new QWidget(Graf);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(250, 0, 256, 192));

        gridLayout->addWidget(widget, 0, 1, 1, 1);

        Graf->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Graf);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 39));
        Graf->setMenuBar(menubar);
        statusbar = new QStatusBar(Graf);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Graf->setStatusBar(statusbar);

        retranslateUi(Graf);

        QMetaObject::connectSlotsByName(Graf);
    } // setupUi

    void retranslateUi(QMainWindow *Graf)
    {
        Graf->setWindowTitle(QCoreApplication::translate("Graf", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graf: public Ui_Graf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAF_H
