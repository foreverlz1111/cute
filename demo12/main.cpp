#include "mainwindow.h"
#include <QApplication>
#include <form.cpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Form f;
    f.show();
    //w.show();

    return a.exec();
}
