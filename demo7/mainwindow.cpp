#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infodialog.h"
#include "QIcon"

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



void MainWindow::on_info_button_clicked()
{
    InfoDialog InfoDialog;
    InfoDialog.setWindowIcon(QIcon(":/img/qq.png"));
    InfoDialog.setWindowTitle("信息编辑");
    InfoDialog.exec();
}

void MainWindow::on_counter_button_clicked()
{
  ;

}
