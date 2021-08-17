#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <QSqlRecord>
#include<QSqlField>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QOCI");
    db.setHostName("192.168.196.132");
    db.setPort(1521);
    db.setDatabaseName("lzy");
    db.setUserName("system");
    db.setPassword("manager");
     //qDebug()<<QSqlDatabase::drivers();
    if(db.open())
    {
         qDebug()<<QString("连接成功");
         qDebug()<<QSqlDatabase::drivers();
         QSqlQuery query;
         QString S = query.exec("select * from ZIYUAN");
         qDebug()<<S;
         query.next();
         qDebug()<<query.value(0).toString();
         ui->label->setText(query.value(0).toString());

         QSqlRecord rec = query.record();
         qDebug()<<tr("列数")<<rec.count();
         QSqlField filed = rec.field(2);
         qDebug()<<rec.field(0).name()<<rec.field(0).type()<<rec.field(1).value();
         query.next();
         ui->textEdit->setText(query.value(1).toString());

         model = new QSqlTableModel(this);
         model->setTable("ZIYUAN");
         model->setEditStrategy(QSqlTableModel::OnManualSubmit);
         model->select();
         ui->tableView->setModel(model);

}
    else
    {
         qDebug()<<"连接失败";
         qDebug()<<QSqlDatabase::drivers();

    }

}
