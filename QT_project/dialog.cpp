#include "dialog.h"

#include "ui_dialog.h"
#include <fstream>
#include <iostream>
#include <QtDebug>
#include <math.h>
#include "grafik.h"
#include <string>
using namespace std;
Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//Метод Гаусса решения СЛАУ
float * gauss(float **a, float *y, int n)
{
  float *x, max;
  int k, index;
  const float eps = 0.00001;  // точность
  x = new float[n];
  k = 0;
  while (k < n)
  {
    // Поиск строки с максимальным a[i][k]
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++)
    {
      if (abs(a[i][k]) > max)
      {
        max = abs(a[i][k]);
        index = i;
      }
    }
    // Перестановка строк
    if (max < eps)
    {
      // нет ненулевых диагональных элементов
      cout << "Решение получить невозможно из-за нулевого столбца ";
      cout << index << " матрицы A" << endl;
      return 0;
    }
    for (int j = 0; j < n; j++)
    {
      float temp = a[k][j];
      a[k][j] = a[index][j];
      a[index][j] = temp;
    }
    float temp = y[k];
    y[k] = y[index];
    y[index] = temp;
    // Нормализация уравнений
    for (int i = k; i < n; i++)
    {
      float temp = a[i][k];
      if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] / temp;
      y[i] = y[i] / temp;
      if (i == k)  continue; // уравнение не вычитать само из себя
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  // обратная подстановка
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  return x;
}

//Линейная функция
pair<float,float> lin(float* X, float* Y, int n) {
    float sum_x = 0;
    float sum_y = 0;
    float sum_xy = 0;
    float sum_x_sq = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += X[i];
        sum_y += Y[i];
        sum_xy += X[i] * Y[i];
        sum_x_sq += X[i] * X[i];
    }

    // Вычисляем коэффициенты a и b

    float a = (n * sum_xy - sum_x * sum_y) / (n * sum_x_sq - sum_x * sum_x);
    float b = (sum_y - a * sum_x) / n;
    return pair<float,float>(a,b);


}

//Полиномиальная функция
vector<float> leastSquaresPolynomial(float* X, float* Y, int k,int size) {
    int n = size;

    float** AA;
    float* XX;
    float* BB;
    AA=new float* [k+1];
    BB=new float[k+1];
    for(int i=0;i<k+1;i++)
    {
        AA[i]=new float[k+1];
    }


    for (int i = 0; i < k+1; i++) {
      BB[i]=0;
        for (int j = 0; j <n ; j++)
        {
            BB[i]+=Y[j]*pow(X[j],i);
        }


    }

  for(int i=0;i<k+1;i++)
  {
    for(int j=0;j<k+1;j++)
    {
      AA[i][j]=0;
      for(int g=0;g<n;g++)
      {
        AA[i][j]+=pow(X[g],i+j);
      }
    }
  }

  XX=gauss(AA,BB,k+1);
  vector<float> coef(k+1,0);
  for(int i=0;i<k+1;i++)
  {
    coef[i]=XX[i];
  }
  return coef;


}



//Логорифмическая функция
void logo(float* X, float* Y,int size, float& a, float& b)
{
    int n = size;

    float sumlnX=0.0;
    float sumlnX2=0.0;
    float sumY=0.0;
    float sumYlnX=0.0;

    for (int i = 0; i < n; ++i)
    {
        double x = X[i];
        double y = Y[i];
        sumlnX+=log(x);
        sumlnX2+=log(x)*log(x);
        sumY+=y;
        sumYlnX+=log(x)*y;
    }

    float** AA;
    float* XX;
    float* YY;
    AA=new float* [2];
    YY=new float[2];
    for(int i=0;i<2;i++)
    {
        AA[i]=new float[2];
    }
    AA[0][0]=n;AA[0][1]=sumlnX;
    AA[1][0]=sumlnX;AA[1][1]=sumlnX2;
    YY[0]=sumY;YY[1]=sumYlnX;
    XX=gauss(AA,YY,2);
    a=XX[0];
    b=XX[1];
}

//Гиперболическая функция
void gip(float* X, float* Y,int size, float& a, float& b)
{
double sum1_X = 0.0, sumY = 0.0, sum1_X2 = 0.0, sumY_X = 0.0;
int n=size;
  for (int i = 0; i < n; i++)
  {
    sum1_X += 1/X[i];
    sumY += Y[i];
    sum1_X2 += 1/X[i] * 1/X[i];
    sumY_X += Y[i] / X[i];
  }

  float** AA;
  float* XX;
  float* YY;
  AA=new float* [2];
  YY=new float[2];
  for(int i=0;i<2;i++)
  {
      AA[i]=new float[2];
  }
  AA[0][0]=n;AA[0][1]=sum1_X;
  AA[1][0]=sum1_X;AA[1][1]=sum1_X2;
  YY[0]=sumY;YY[1]=sumY_X;
  XX=gauss(AA,YY,2);
  a=XX[0];
  b=XX[1];
}

//Дробно линейная функция
void droblin(float* X, float* Y,int size, float& a, float& b,float& c)
{
double sumlnX = 0.0, sumlnY = 0.0, sum_X = 0.0, sumlnX2 = 0.0;
double sumXlnX=0.0,sumlnYlnX=0.0,sumX2=0.0,sumXlnY=0.0;
int n=size;
  for (int i = 0; i < n; i++)
  {
    sumlnX += log(X[i]);
    sumlnY += log(Y[i]);
    sum_X += X[i];
    sumlnX2 += log(X[i])*log(X[i]);
    sumXlnX+=X[i]*log(X[i]);
    sumlnYlnX+=log(X[i])*log(Y[i]);
    sumX2+=X[i]*X[i];
    sumXlnY+=X[i]*log(Y[i]);
  }

  float** AA;
  float* XX;
  float* YY;
  AA=new float* [3];
  YY=new float[3];
  for(int i=0;i<3;i++)
  {
      AA[i]=new float[3];
  }
  AA[0][0]=n;AA[0][1]=sumlnX;AA[0][2]=sum_X;
  AA[1][0]=sumlnX;AA[1][1]=sumlnX2;AA[1][2]=sumXlnX;
  AA[2][0]=sum_X;AA[2][1]=sumXlnX;AA[2][2]=sumX2;
  YY[0]=sumlnY;YY[1]=sumlnYlnX;YY[2]=sumXlnY;
  XX=gauss(AA,YY,3);
  a=XX[0];
  a=exp(a);
  b=XX[1];
  c=XX[2];
}


void Dialog::on_pushButton_clicked()
{
    QString strLines=ui->textBrowser->toPlainText();
    qDebug()<<strLines;
    string fileLink = strLines.toStdString();
    ifstream f;
    float a; int n=0;
    float nach[100];
    f.open(fileLink);
        if (f)
        {
            while (!f.eof())
            {
                f>>a;
                nach[n]=a;
                n++;
            }
            f.close();
            //cout<<"n="<<n<<endl;
            float *X,*Y;
            X=new float[n/2];
            Y=new float[n/2];
            for(int i=0;i<n/2;i++)
            {
                X[i]=nach[i];
                Y[i]=nach[n/2+i];
            }
            //for(int i=0;i<n/2;i++)
            //{
                //cout<<X[i]<<endl;
                //cout<<Y[i]<<endl;
                //cout<<""<<endl;
            //}

            if(ui->radioButton->isChecked())
            {
                ui->textBrowser_4->setText("Выбрана линейная функция!");
                auto[a,b]=lin(X,Y,n/2);
                //cout<<a<<b<<endl;
                string funkl="Y="+to_string(a)+"x+"+to_string(b);
                ui->textBrowser_5->setText(QString::fromStdString(funkl));
                float s=0;
                float My=0;
                float Mx=0;
                for(int i=0;i<n/2;i++)
                {
                    s+=pow((Y[i]-a*X[i]-b),2);
                    My+=Y[i];
                    Mx+=X[i];
                }
                My=My/(n/2);
                Mx=Mx/(n/2);
                float st=sqrt(s)/(n/2);
                float sto=(st/My)*100;
                float chisl=0;
                float znam1=0;
                float znam2=0;
                for(int i=0;i<n/2;i++)
                {
                    chisl+=(X[i]-Mx)*(Y[i]-My);
                    znam1+=(X[i]-Mx)*(X[i]-Mx);
                    znam2+=(Y[i]-My)*(Y[i]-My);
                }
                float r;
                r=chisl/sqrt(znam1*znam2);
                string strr=to_string(r);
                string strsto=to_string(sto);
                string strst=to_string(st);
                string strs=to_string(s);
                //cout<<strs<<endl;
                ui->textBrowser_8->setText(QString::fromStdString(strs));
                ui->textBrowser_9->setText(QString::fromStdString(strst));
                ui->textBrowser_11->setText(QString::fromStdString(strsto));
                ui->textBrowser_13->setText(QString::fromStdString(strr));
                grafik=new Grafik(this);
                grafik->show();
                connect(this,&Dialog::signal1,grafik,&Grafik::slot1);
                emit signal1(QString::fromStdString(funkl),1,a,b,0,X,Y,n/2,0);

            }
            if(ui->radioButton_2->isChecked())
            {
                ui->textBrowser_4->setText("Выбран полином!");
                //cout<<a1<<" "<<b1<<" "<<c1<<endl;
                string funkk;
                QString kk=ui->lineEdit->text();
                bool ok;
                int k = kk.toInt(&ok);
                vector<float> coef=leastSquaresPolynomial(X, Y, k,n/2);
                float *coeff;
                coeff=new float[k+1];
                for(int i=0;i<k+1;i++)
                {
                    coeff[i]=coef[i];
                    funkk+=to_string(coef[k-i])+"x^"+to_string(k-i);
                    if(i!=k)
                      funkk+="+";
                }
                ui->textBrowser_5->setText(QString::fromStdString(funkk));
                float* s=0;
                s=new float[k+1];
                float S=0;
                float My=0;
                for(int i=0;i<n/2;i++)
                {
                    s[i]=Y[i];
                    for(int j=0;j<=k+1;j++)
                    {
                        s[i]-=coef[j]*pow(X[i],j);
                    }
                    S+=s[i]*s[i];
                    My+=Y[i];

                }
                My=My/(n/2);

                float st=sqrt(S)/(n/2);
                float sto=(st/My)*100;
                float chisl=S;
                float znam=0;

                for(int i=0;i<n/2;i++)
                {

                    znam+=pow((Y[i]-My),2);

                }
                float R;
                R=1-sqrt(chisl/znam);
                string strr=to_string(R);
                cout<<strr<<endl;
                string strsto=to_string(sto);
                string strst=to_string(st);
                string strs=to_string(S);
                //cout<<strs<<endl;
                ui->textBrowser_8->setText(QString::fromStdString(strs));
                ui->textBrowser_9->setText(QString::fromStdString(strst));
                ui->textBrowser_11->setText(QString::fromStdString(strsto));
                ui->textBrowser_13->setText(QString::fromStdString(strr));
                grafik=new Grafik(this);
                grafik->show();
                connect(this,&Dialog::signal1,grafik,&Grafik::slot1);
                emit signal1(QString::fromStdString(funkk),2,k,k,k,X,Y,n/2,coeff);
            }
            if(ui->radioButton_3->isChecked())
            {
                ui->textBrowser_4->setText("Выбрана лог-ая функция!");
                float a2,b2;
                logo(X,Y,n/2,a2,b2);
                cout<<a2<<" "<<b2<<endl;
                string funks="Y="+to_string(b2)+"*ln(x)+"+to_string(a2);
                ui->textBrowser_5->setText(QString::fromStdString(funks));
                float s=0;
                float My=0;

                for(int i=0;i<n/2;i++)
                {
                    s+=pow((Y[i]-b2*log(X[i])-a2),2);
                    My+=Y[i];

                }
                My=My/(n/2);

                float st=sqrt(s)/(n/2);
                float sto=(st/My)*100;
                float chisl=0;
                float znam=0;

                for(int i=0;i<n/2;i++)
                {
                    chisl+=pow((Y[i]-b2*log(X[i])-a2),2);
                    znam+=pow((Y[i]-My),2);

                }
                float R;
                R=1-sqrt(chisl/znam);
                string strr=to_string(R);
                string strsto=to_string(sto);
                string strst=to_string(st);
                string strs=to_string(s);
                //cout<<strs<<endl;
                ui->textBrowser_8->setText(QString::fromStdString(strs));
                ui->textBrowser_9->setText(QString::fromStdString(strst));
                ui->textBrowser_11->setText(QString::fromStdString(strsto));
                ui->textBrowser_13->setText(QString::fromStdString(strr));
                grafik=new Grafik(this);
                grafik->show();
                connect(this,&Dialog::signal1,grafik,&Grafik::slot1);
                emit signal1(QString::fromStdString(funks),3,a2,b2,0,X,Y,n/2,0);
            }
            if(ui->radioButton_4->isChecked())
            {
                ui->textBrowser_4->setText("Выбрана функция Y=axᵇeᶜˣ!");
                float a4,b4,c4;
                droblin(X,Y,n/2,a4,b4,c4);
                //cout<<a4<<" "<<b4<<" "<<c4<<endl;
                string funkdl="Y="+to_string(a4)+"x^("+to_string(b4)+")*e^("+to_string(c4)+"x)";
                ui->textBrowser_5->setText(QString::fromStdString(funkdl));
                float s=0;
                float My=0;

                for(int i=0;i<n/2;i++)
                {
                    s+=pow((Y[i]-a4*pow(X[i],b4)*exp(c4*X[i])),2);
                    My+=Y[i];

                }
                My=My/(n/2);

                float st=sqrt(s)/(n/2);
                float sto=(st/My)*100;
                float chisl=0;
                float znam=0;

                for(int i=0;i<n/2;i++)
                {
                    chisl+=pow((Y[i]-a4*pow(X[i],b4)*exp(c4*X[i])),2);
                    znam+=pow((Y[i]-My),2);

                }
                float R;
                R=1-sqrt(chisl/znam);
                string strr=to_string(R);
                string strsto=to_string(sto);
                string strst=to_string(st);
                string strs=to_string(s);
                //cout<<strs<<endl;
                ui->textBrowser_8->setText(QString::fromStdString(strs));
                ui->textBrowser_9->setText(QString::fromStdString(strst));
                ui->textBrowser_11->setText(QString::fromStdString(strsto));
                ui->textBrowser_13->setText(QString::fromStdString(strr));
                grafik=new Grafik(this);
                grafik->show();
                connect(this,&Dialog::signal1,grafik,&Grafik::slot1);
                emit signal1(QString::fromStdString(funkdl),4,a4,b4,c4,X,Y,n/2,0);
            }
            if(ui->radioButton_5->isChecked())
            {
                ui->textBrowser_4->setText("Выбрана гипер-ая функция!");
                float a5,b5;
                gip(X,Y,n/2,a5,b5);
                //cout<<a5<<" "<<b5<<endl;
                string funkg="Y="+to_string(b5)+"/x+"+to_string(a5);
                ui->textBrowser_5->setText(QString::fromStdString(funkg));
                float s=0;
                float My=0;

                for(int i=0;i<n/2;i++)
                {
                    s+=pow((Y[i]-b5/X[i]-a5),2);
                    My+=Y[i];

                }
                My=My/(n/2);

                float st=sqrt(s)/(n/2);
                float sto=(st/My)*100;
                float chisl=0;
                float znam=0;

                for(int i=0;i<n/2;i++)
                {
                    chisl+=pow((Y[i]-b5/X[i]-a5),2);
                    znam+=pow((Y[i]-My),2);

                }
                float R;
                R=1-sqrt(chisl/znam);
                string strr=to_string(R);
                string strsto=to_string(sto);
                string strst=to_string(st);
                string strs=to_string(s);
                //cout<<strs<<endl;
                ui->textBrowser_8->setText(QString::fromStdString(strs));
                ui->textBrowser_9->setText(QString::fromStdString(strst));
                ui->textBrowser_11->setText(QString::fromStdString(strsto));
                ui->textBrowser_13->setText(QString::fromStdString(strr));
                grafik=new Grafik(this);
                grafik->show();
                connect(this,&Dialog::signal1,grafik,&Grafik::slot1);
                emit signal1(QString::fromStdString(funkg),5,a5,b5,0,X,Y,n/2,0);
            }

        }
}

void Dialog::slot(QString a)
{
    ui->textBrowser->setText(a);
}




