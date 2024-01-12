#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "wrongpath.h"
#include <fstream>
#include <iostream>
#include <QtDebug>
#include <QFileDialog>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //window = new Dialog();
    //window->show();
    //connect(this,&MainWindow::signal,window,&Dialog::slot);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString strLines=QFileDialog::getOpenFileName(this,"Открыть файл");
    qDebug()<<strLines;
    string fileLink = strLines.toStdString();
    ifstream f;
    f.open(fileLink);
    if (f)
    {
        window = new Dialog(this);
        window->show();
        connect(this,&MainWindow::signal,window,&Dialog::slot);
        emit signal(strLines);

    }
    else
    {
         cout<<"File not found"<<endl;
         warningwindow = new wrongpath(this);
         warningwindow->show();
    }




}

