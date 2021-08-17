#include "mainwindow.h"
#include <QApplication>
#include"Point.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("qt实验1");
    w.show();
    //Point p(1,1);
    return a.exec();
}
