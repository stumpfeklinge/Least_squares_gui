#ifndef WRONGPATH_H
#define WRONGPATH_H

#include <QMainWindow>

namespace Ui {
class wrongpath;
}

class wrongpath : public QMainWindow
{
    Q_OBJECT

public:
    explicit wrongpath(QWidget *parent = nullptr);
    ~wrongpath();

private:
    Ui::wrongpath *ui;
};

#endif // WRONGPATH_H
