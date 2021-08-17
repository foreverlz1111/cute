#include "mainwindow.h"
#include <QApplication>
#include"QSplashScreen"
#include"QElapsedTimer"
#include"QMovie"
#include<QTranslator>

#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(":/tr/cn.qm");
    a.installTranslator(&translator);

    MainWindow w;


    QPixmap pixmap(":/images/images/timg.gif");
    QSplashScreen spl(pixmap);
    QLabel spl_label(&spl);
    QMovie movie(":/images/images/timg.gif");
    spl_label.setMovie(&movie);
    movie.start();
    //spl.showMessage("正在加载中...");
    spl.show();
    int delayTime=3;
    QElapsedTimer timer;
    timer.start();

   // while(timer.elapsed()<(delayTime*1000))
  //  {
        a.processEvents();
  //  }

    w.showMaximized();
    spl.finish(&w);
    return a.exec();
}
