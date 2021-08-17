#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QWidget>
#include <form.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime datetimes ;
    QTimer * timer = new QTimer(this);//创建一个新的定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(time_update()));
    timer->start(1000);

}

void MainWindow::time_update(){
   // QDateTime time;

    QDateTime time = QDateTime::currentDateTime();
    QTime time1 = QTime::currentTime();
    //这里的 \t跳格  \n  换行
    //QString str = time.toString("\tyyyy-MM-dd \n\thh:mm:ss dddd");    //年-月-日 时:分:秒 周几
    QString text = time.toString("\t[yyyy年MM月dd日]\n\thh:mm:ss");           //年-月-日 时:分:秒

    //每隔一秒就将“:” 显示为空格
   // if(time1.second() % 2 == 0)
   //     text[19]=' ';
    //将处理后的日期时间写入
    ui->label_6->setText(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}



