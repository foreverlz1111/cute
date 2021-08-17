#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("net");
    w.setWindowIcon(QIcon(":/img/codingbrowser.ico"));
    w.show();
    return a.exec();
}
