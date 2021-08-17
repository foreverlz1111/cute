#ifndef DRAWER_H
#define DRAWER_H
#include"QToolButton"
#include <QtGui>
#include"QDialog"
#include"QToolBox"
#include <QToolBox>

namespace Ui {
class Drawer;
}

class Drawer : public QToolBox
{
    Q_OBJECT

public:
    explicit Drawer(QWidget *parent = 0);
    ~Drawer();
    QToolButton *toolbutton1_1;
    QToolButton *toolbutton1_2;
    QToolButton *toolbutton1_3;
    QToolButton *toolbutton1_4;
    QToolButton *toolbutton1_5;
    QToolButton *toolbutton2_1;
    QToolButton *toolbutton2_2;
    QToolButton *toolbutton3_1;
    QToolButton *toolbutton3_2;

private:
    Ui::Drawer *ui;
};

#endif // DRAWER_H
