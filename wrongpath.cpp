#include "wrongpath.h"
#include "ui_wrongpath.h"

wrongpath::wrongpath(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wrongpath)
{
    ui->setupUi(this);
}

wrongpath::~wrongpath()
{
    delete ui;
}
