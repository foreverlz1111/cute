#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"login_dialog.h"
#include"mydialog.h"

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

void MainWindow::on_resetbutton_clicked()
{
    setnum(0);
    ui->lcdNumber->display(getnum());
}

void MainWindow::on_addbutton_clicked()
{
    setnum(getnum()+1);
    ui->lcdNumber->display(getnum());
}

void MainWindow::on_incbutton_clicked()
{
    if(getnum()>0)
        setnum(getnum()-1);
    else
        setnum(0);
    ui->lcdNumber->display(getnum());
}

void MainWindow::on_pushButton_clicked()
{
    //accpet();
    myDialog myDialog;
    myDialog.setWindowTitle("【QT任务2】");
    myDialog.setWindowFlags(Qt::FramelessWindowHint);
    myDialog.exec();
}
