#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include<QDebug>
#include<QTimer>
#include<QTextCodec>

#include<sys/timeb.h>

#include<QThreadPool>
#include<QThread>
#include<QRunnable>
#include<rwthread.h>

#include<QFileDialog>
#include <QAxObject>
#include <QFileDialog>

#include<QEventLoop>
#include<QJsonObject>
#include<QJsonDocument>
#include<QNetworkAccessManager>
#include<QNetworkReply>

#include<Windows.h>
#include<QClipboard>
//#pragma execution_character_set("utf-8")
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<
               "QTime(0,0,0).secsTo(QTime::currentTime())"<<
               QTime(0,0,0).secsTo(QTime::currentTime());
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int rand = qrand()%1001;//0~1000
    //上限减下限+1 = 随机数范围
    ui->label->setText("随机数"+QString::number(rand));

    ui->pushButton_excel->hide();
    ui->pushButton_request->hide();
    ui->pushButton_pool->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    timeout = 0;
    timer->stop();
    ui->textEdit->clear();

    pro = new QProcess(this);
    QString ip_input = ui->lineEdit->text();
    if(ip_input!="")
        pro->start("ping "+ip_input+" -n 3");
    else {
        pro->start("ping 163.com -n 3");
    }
    //pro->execute("ipconfig");

    connect(timer, SIGNAL(timeout()), this, SLOT(info_update()));
    timer->start(1000);

    //ui->label->setText(pro->readAllStandardOutput());
    //ui->textEdit->setText(pro->readAllStandardOutput());


}
void MainWindow::info_update(){

    QTextCodec *codec = QTextCodec::codecForName("GBK");//指定QString的编码方式
    QString res;
    res.append(codec->toUnicode( pro->readAllStandardOutput()));
    //QString ip = pro->arguments().last();
    qDebug()<<res;


    qDebug()<<pro->readAllStandardOutput();
    if(res!=""){
        timeout=0;
         ui->textEdit->append(res);
    }
    else {
        timeout++;
        if(timeout >=10)
            timer->stop();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    timeout = 0;
    timer->stop();
    ui->textEdit->clear();

    pro = new QProcess(this);
    QString ip_input = ui->lineEdit->text();
    if(ip_input!=""){
        pro->start("tracert "+ip_input);
    }
    else {
        pro->start("tracert 163.com");
    }


    connect(timer, SIGNAL(timeout()), this, SLOT(info_update()));
    timer->start(1000);
}

void MainWindow::on_pushButton_3_clicked()
{

    pro = new QProcess(this);

    pro->start("ipconfig");
    connect(timer, SIGNAL(timeout()), this, SLOT(info_update()));
    timer->start(1000);
//    QTextCodec *codec = QTextCodec::codecForName("GBK");//指定QString的编码方式
//    QString res;
//    res.append(codec->toUnicode( pro->readAllStandardOutput()));
//    ui->textEdit->append(res);
}

void MainWindow::debug1(){
    qDebug() << "Hello from thread " << QThread::currentThread();
}
void MainWindow::on_pushButton_pool_clicked()
{

    qDebug()<<"QThreadPool:"<<QThreadPool::globalInstance()->activeThreadCount()<<"/"<<QThreadPool::globalInstance()->maxThreadCount();
   // QThreadPool::globalInstance()->start();
    for (int i = 0;i<QThreadPool::globalInstance()->maxThreadCount();i++) {
        debug1();
    }
    QString str_tmp;
    for(int i = 0;i<QThreadPool::globalInstance()->maxThreadCount();i++){
        Rwthread *rw = new Rwthread(i);
        QThreadPool::globalInstance()->setMaxThreadCount(4);
        QThreadPool user_threadpool;

        user_threadpool.setMaxThreadCount(2);
        user_threadpool.start(rw);
//        str_tmp.append(rw->user_outline);
//        str_tmp.append(rw->user_outline2);
//        ui->textEdit->setText(str_tmp);
        QThread *r1;

    }
}

void MainWindow::on_pushButton_excel_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this, QString("选择Excel文件"), "",QString("Exel file(*.xls *.xlsx)"));
    auto *excelobj = new QAxObject("Excel.Application");
    excelobj->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体

    auto workbooks = excelobj->querySubObject("Workbooks");
    auto workbook  = workbooks->querySubObject("Open(const QString&)",filePath);
    auto sheets    = workbook->querySubObject("Worksheets");
    auto sheet     = sheets->querySubObject("Item(int)", 1);

    auto range     = sheet->querySubObject("Range(A1,J700)");

    for (int r = 1; r <= 5; ++r)
    {
        auto cCell = sheet->querySubObject("Cells(int,int)",r+2,4);
        //      1    2    3    {4}
        //1+2
        //2+2
        //3+2
        //4+2

        qDebug() << cCell->dynamicCall("Value()");
    }

    excelobj->dynamicCall("Quit(void)");
    delete excelobj;
}
void MainWindow::excel_query(){

}


void MainWindow::on_pushButton_4_clicked()
{
    QString parse_str;
    QClipboard *clipboard = QApplication::clipboard();
    parse_str = clipboard->text();
    qDebug()<<parse_str;

    timeout = 0;
    timer->stop();
    ui->textEdit->clear();

    pro = new QProcess(this);
    //QString ip_input = ui->lineEdit->text();
    if(parse_str!="")
        pro->start("ping "+parse_str+" -n 3");
    else {
        pro->start("ping 163.com -n 3");
    }
    //pro->execute("ipconfig");

    connect(timer, SIGNAL(timeout()), this, SLOT(info_update()));
    timer->start(1000);
}

void MainWindow::on_pushButton_request_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    qDebug() <<"协议支持："<< manager->supportedSchemes();
    QString baseUrl = "http://freeapi.ipip.net/108.16.8.1";
    baseUrl = "http://www.163.com";
    QUrl url(baseUrl);
    //http://freeapi.ipip.net/108.16.8.1

    QEventLoop *loop = new QEventLoop;
    connect(manager, SIGNAL(finished(QNetworkReply*)), loop, SLOT(quit()));
    QNetworkRequest request(QUrl("http://freeapi.ipip.net/108.16.8.2"));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = manager->get(request);
    loop->exec();

    //qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).value<int>();
    QByteArray myarr = reply->readAll();
    qDebug()<<myarr.indexOf("\"");
    //qDebug()<<myarr;
    //qDebug()<<codec->toUnicode(myarr)<<"\n"<<codec->toUnicode(myarr).length();

    QString htmlusing = QString::fromUtf8(myarr);
        ui->textEdit->setHtml(htmlusing);
}
