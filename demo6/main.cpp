#include "mainwindow.h"
#include <QApplication>
#include "drawer.h"
#include <QToolBox>
int main(int argc, char *argv[])
{
    //QFont font("ZYSong18030",10);
    //QApplication::setFont(font);

    QApplication a(argc, argv);
    MainWindow w;

    //Drawer drawer;
    //Drawer *drawer = new Drawer();
    //drawer->resize(540,480);
    //drawer->show();

    w.setWindowTitle("【任务3整合】");
    w.show();

    return a.exec();
}
