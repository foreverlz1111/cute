#include "calculater.h"
#include <QApplication>
#include"QIcon"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculater w;
    w.setWindowIcon(QIcon(":/img/calculater.png"));
    w.setWindowIconText("calculator");
    w.setWindowTitle("计算器");
    w.show();

    return a.exec();
}
