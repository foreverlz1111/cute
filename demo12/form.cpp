#include "form.h"
#include "ui_form.h"

#include"QMessageBox"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->tabWidget->setTabBarAutoHide(true);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void Form::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void Form::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void Form::on_pushButton_15_clicked()
{
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle("退出");
    QPushButton *lockButton = customMsgBox.addButton(tr("确定"), QMessageBox::ActionRole);
    QPushButton *unlockButton = customMsgBox.addButton(tr("取消"), QMessageBox::ActionRole);
    customMsgBox.setText(tr("你确定退出吗？"));
    customMsgBox.exec();
    if (customMsgBox.clickedButton() == lockButton) {
        QApplication::quit();
    }
    if (customMsgBox.clickedButton() == unlockButton) {
    }
}

