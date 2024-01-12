#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "wrongpath.h"


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float fail(string fileLink,float* X, float* Y);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *window;
    wrongpath *warningwindow;


signals:
    void signal(QString);
};
#endif // MAINWINDOW_H
