#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "standdialog.h"
#include "geometry.h"
#include "messagebox.h"

#include "drawer.h"
#include"QDialog"
#include"QWidget"
#include"QtGui"


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
    standDialog standDialog;
    standDialog.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    Geometry Geometry;
    Geometry.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Messagebox Messagebox;
    Messagebox.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
   Drawer *drawer = new Drawer();
   //drawer->setAttribute(Qt::WA_ShowModal, true);//属性模态设置
   drawer->setWindowModality(Qt::ApplicationModal);//阻塞
   drawer->resize(540,480);
   drawer->show();

}
