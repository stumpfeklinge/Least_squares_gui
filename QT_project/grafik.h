#ifndef GRAFIK_H
#define GRAFIK_H

#include <QMainWindow>
using namespace std;

namespace Ui {
class Grafik;
}

class Grafik : public QMainWindow
{
    Q_OBJECT

public:
    explicit Grafik(QWidget *parent = nullptr);
    ~Grafik();

private:
    Ui::Grafik *ui;

public slots:
    void slot1(QString a,int s,float a1,float b1,float c1,float *X,float *Y,int n,float* coef);
};

#endif // GRAFIK_H
