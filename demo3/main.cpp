#include "mainwindow.h"
#include <QApplication>
#include "login_dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login_dialog login;
    login.setWindowTitle("【QT任务2】");
    if(login.exec()==QDialog::Accepted){
        w.setWindowTitle("【QT任务2】");
        w.show();
        return a.exec();
    }

    return 0;
}
