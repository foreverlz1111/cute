#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWhatsThis("下载");
    w.setWindowIcon(QIcon(":/img/folder-download.png"));
    w.show();

    return a.exec();
}
