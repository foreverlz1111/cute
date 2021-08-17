#include "rwthread.h"
#include<QDebug>
#include<QThread>
#include<QDateTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QThreadPool>
Rwthread::Rwthread(int id):id(id)
{

}
void Rwthread::run() {

    /*qDebug().noquote() <<*/
    user_outline =  QString("Start thread %1 at %2").arg(id).arg(QDateTime::currentDateTime().toString("mm:ss.z"));
    qDebug()<<user_outline;
    QThread::msleep(500 + qrand() % 2000); // 每个 run() 函数随机执行 [55, 2500] 毫秒，模拟耗时任务
    /*qDebug().noquote() <<*/
    user_outline2 =  QString("End   thread %1 at %2").arg(id).arg(QDateTime::currentDateTime().toString("mm:ss.z"));
    qDebug()<<user_outline2;

    qDebug()<<"QThreadPool:"<<QThreadPool::globalInstance()->activeThreadCount()<<"/"<<QThreadPool::globalInstance()->maxThreadCount();

    QApplication::processEvents();
}
