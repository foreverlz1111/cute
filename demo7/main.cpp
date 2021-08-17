#include "mainwindow.h"
#include <QApplication>
#include"QIcon"
#include"infodialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.setWindowTitle("【任务4.1】");
    //w.setWindowIcon(QIcon(":/img/qq.png"));
    //w.show();
    InfoDialog InfoDialog;
    InfoDialog.setWindowIcon(QIcon(":/img/qq.png"));
    InfoDialog.setWindowTitle("信息编辑");
    InfoDialog.exec();
    return a.exec();
}
