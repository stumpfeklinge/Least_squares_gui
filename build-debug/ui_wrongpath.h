/********************************************************************************
** Form generated from reading UI file 'wrongpath.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRONGPATH_H
#define UI_WRONGPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wrongpath
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *wrongpath)
    {
        if (wrongpath->objectName().isEmpty())
            wrongpath->setObjectName(QString::fromUtf8("wrongpath"));
        wrongpath->resize(800, 600);
        centralwidget = new QWidget(wrongpath);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(250, 200, 300, 120));
        wrongpath->setCentralWidget(centralwidget);
        menubar = new QMenuBar(wrongpath);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 39));
        wrongpath->setMenuBar(menubar);
        statusbar = new QStatusBar(wrongpath);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        wrongpath->setStatusBar(statusbar);

        retranslateUi(wrongpath);

        QMetaObject::connectSlotsByName(wrongpath);
    } // setupUi

    void retranslateUi(QMainWindow *wrongpath)
    {
        wrongpath->setWindowTitle(QCoreApplication::translate("wrongpath", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("wrongpath", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\320\262\320\265\320\264\320\265\320\275 \320\275\320\265\320\262\320\265\321\200\320\275\321\213\320\271 \320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260!</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wrongpath: public Ui_wrongpath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRONGPATH_H
