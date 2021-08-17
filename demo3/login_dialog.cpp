#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "QMessageBox"
login_dialog::login_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_dialog)
{
    ui->setupUi(this);
}

login_dialog::~login_dialog()
{
    delete ui;
}

void login_dialog::on_loginbutton_clicked()
{
    if(ui->user->text().trimmed()==tr("123456")&&ui->password->text().trimmed()==tr("123456")){
        accept();//允许登陆，开始转跳
    }
    else{
        QMessageBox::warning(this,tr("密码错误"),tr("请检查输入的密码！"),QMessageBox::Yes);//错误提示
    }
}



