#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Point.h"
#include <QLCDNumber>
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
//Point p;
double x = p.getX();
double y = p.getY();
x++;
y++;
p.Set(x,y);
p.Show();
ui->lcdNumber->display(p.getX());
ui->lcdNumber_2->display(p.getY());
}


void MainWindow::on_pushButton_2_clicked()
{
  p.Set(0,0);
  ui->lcdNumber->display(p.getX());
  ui->lcdNumber_2->display(p.getY());
}
