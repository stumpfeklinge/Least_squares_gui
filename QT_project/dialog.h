#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include "grafik.h"


namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Grafik *grafik;


public slots:
    void slot(QString a);


signals:
    void signal1(QString,int,float,float,float,float*,float*,int,float*);

};

#endif // DIALOG_H
