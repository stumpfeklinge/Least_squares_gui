#include "grafik.h"
#include "ui_grafik.h"
#include "qcustomplot.h"
#include <iostream>

using namespace std;

Grafik::Grafik(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Grafik)
{
    ui->setupUi(this);
}

Grafik::~Grafik()
{
    delete ui;
}

void Grafik::slot1(QString a,int s,float a1,float b1,float c1,float *X,float *Y,int n,float *coef)
{

    ui->textBrowser->setText(a);
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(-1,5);
    ui->widget->yAxis->setRange(12,50);
    ui->widget->replot();
    QVector<double> x(n),y(n);
    for(int i=0;i<n;i++)
    {
        x[i]=X[i];
        y[i]=Y[i];
        //cout<<x[i]<<" "<<y[i]<<endl;
    }
    if(s==1)
    {
        QVector<double> x1(20),y1(20);

        for(int i=0;i<20;i++)
        {
            x1[i]=i/5.;
            y1[i]=a1*x1[i]+b1;
            //cout<<x1[i]<<" "<<y1[i]<<endl;
        }
        //cout<<y1[0]<<" "<<y1[19]<<endl;
        ui->widget->yAxis->setRange(y1[0],y1[19]);
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x1,y1);
        ui->widget->addGraph();
        ui->widget->graph(1)->addData(x,y);
        QCPScatterStyle scatterStyle;
        scatterStyle.setShape(QCPScatterStyle::ssCircle);
        scatterStyle.setSize(8);
        scatterStyle.setBrush(QColor(255, 0, 0));
        ui->widget->graph(1)->setScatterStyle(scatterStyle);
        ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->widget->replot();
    }
    if(s==2)
    {
        int k=a1;
        if(k<=7 && k>=2){
        QVector<double> x2(20),y2(20);
        //cout<<a1<<" "<<b1<<" "<<c1<<endl;

        for(int i=0;i<20;i++)
        {
            y2[i]=0;
            x2[i]=i/5.;
            for(int j=0;j<k+1;j++)
            {
                y2[i]+=coef[j]*pow(x2[i],j);
            }
            cout<<x2[i]<<" "<<y2[i]<<endl;
        }
        cout<<x2[19]<<" "<<y2[19]<<endl;
        ui->widget->yAxis->setRange(y2[0],y2[19]);
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x2,y2);
        ui->widget->addGraph();
        ui->widget->graph(1)->addData(x,y);
        QCPScatterStyle scatterStyle;
        scatterStyle.setShape(QCPScatterStyle::ssCircle);
        scatterStyle.setSize(8);
        scatterStyle.setBrush(QColor(255, 0, 0));
        ui->widget->graph(1)->setScatterStyle(scatterStyle);
        ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->widget->replot();
        }
        else
        {
            ui->textBrowser->setText("Введено некорректное число k!");
        }

    }
    if(s==3)
    {
        QVector<double> x3(20),y3(20);
        //cout<<a1<<" "<<b1<<" "<<c1<<endl;
        for(int i=0;i<20;i++)
        {
            x3[i]=i/5.;
            y3[i]=b1*log(x3[i])+a1;
        }
        ui->widget->yAxis->setRange(y3[0],y3[19]);
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x3,y3);
        ui->widget->addGraph();
        ui->widget->graph(1)->addData(x,y);
        QCPScatterStyle scatterStyle;
        scatterStyle.setShape(QCPScatterStyle::ssCircle);
        scatterStyle.setSize(8);
        scatterStyle.setBrush(QColor(255, 0, 0));
        ui->widget->graph(1)->setScatterStyle(scatterStyle);
        ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->widget->replot();
    }
    if(s==4)
    {
        QVector<double> x4(20),y4(20);
        //cout<<a1<<" "<<b1<<" "<<c1<<endl;
        for(int i=0;i<20;i++)
        {
            x4[i]=i/5.;
            y4[i]=a1*pow(x4[i],b1)*exp(c1*x4[i]);
        }
        ui->widget->yAxis->setRange(y4[0],y4[19]);
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x4,y4);
        ui->widget->addGraph();
        ui->widget->graph(1)->addData(x,y);
        QCPScatterStyle scatterStyle;
        scatterStyle.setShape(QCPScatterStyle::ssCircle);
        scatterStyle.setSize(8);
        scatterStyle.setBrush(QColor(255, 0, 0));
        ui->widget->graph(1)->setScatterStyle(scatterStyle);
        ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->widget->replot();
    }
    if(s==5)
    {
        QVector<double> x5(20),y5(20);
        //cout<<a1<<" "<<b1<<" "<<c1<<endl;
        for(int i=0;i<20;i++)
        {
            x5[i]=i/5.;
            y5[i]=b1/x5[i]+a1;
        }
        ui->widget->yAxis->setRange(y5[0],y5[19]);
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x5,y5);
        ui->widget->addGraph();
        ui->widget->graph(1)->addData(x,y);
        QCPScatterStyle scatterStyle;
        scatterStyle.setShape(QCPScatterStyle::ssCircle);
        scatterStyle.setSize(8);
        scatterStyle.setBrush(QColor(255, 0, 0));
        ui->widget->graph(1)->setScatterStyle(scatterStyle);
        ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
        ui->widget->replot();
    }

}
