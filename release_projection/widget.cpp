#include "widget.h"
#include "ui_widget.h"

#include<QFileDialog>

#include<QSettings>
#include<QDebug>
#include<QUrl>
#include<QMessageBox>
#include<QProcess>
#include<QTextCodec>
#include<QDir>
#include<QDesktopServices>
#pragma execution_character_set("utf-8")
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    update_bat_url();
    ui->label->hide();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::update_bat_url(){

    QSettings *user_set_read = new QSettings("config.ini",QSettings::IniFormat);
    if(user_set_read->value("bat_url").isValid()){
        bat_url = user_set_read->value("bat_url").toString();
        ui->lineEdit_2->setText(bat_url);

    }
    else {
        ui->lineEdit_2->setText(error_string.no_bat_url);
    }
    if(user_set_read->value("project_url").isValid()){
        project_url = user_set_read->value("project_url").toString();
        ui->label_2->setText(project_url);
    }
    else {
        ui->label_2->setText(error_string.no_project_url);
    }
    if(user_set_read->value("output_project_url").isValid()){
        output_project_url = user_set_read->value("output_project_url").toString();
        ui->label_3->setText(output_project_url);
    }
    else {
        ui->label_3->setText(error_string.no_output_project_url);
    }
    delete user_set_read;
}

void Widget::on_pushButton_2_clicked()
{
    QString tmp_bat_url = QFileDialog::getOpenFileName(this,"选择bat","/","Bat(*.bat)");
    if(nullptr!=tmp_bat_url){
        bat_url = tmp_bat_url;
        ui->lineEdit_2->setText(bat_url);
    }
    else {
        ui->lineEdit_2->setText(bat_url);
    }
}

void Widget::on_pushButton_5_clicked()
{

    QSettings *user_set_write = new QSettings("config.ini",QSettings::IniFormat);
    if(nullptr!=bat_url){
        user_set_write->setValue("bat_url",bat_url);
        user_set_write->value("bat_url") ==
                bat_url?QMessageBox::information(this,"成功","保存成功")
                       :QMessageBox::information(this,"失败","保存失败");
    }
    delete user_set_write;
}

void Widget::on_pushButton_clicked()
{

    QString tmp_exe_url = QFileDialog::getOpenFileName(this,"选择exe",project_url==""?"/":project_url,"可执行程序(*.exe)");
    if(nullptr!=tmp_exe_url){
        exe_url = tmp_exe_url;
        ui->lineEdit->setText(exe_url);
    }
    else {
        ui->lineEdit->setText(exe_url);
    }
}

void Widget::on_pushButton_3_clicked()
{
    QString tmp_output_url = QFileDialog::getExistingDirectory(this,"文件夹",output_project_url==""?"/":output_project_url);
    if(nullptr!=tmp_output_url){
        output_url = tmp_output_url;
        ui->lineEdit_3->setText(output_url);
    }
    else {
        ui->lineEdit_3->setText(output_url);
    }
}

void Widget::on_pushButton_7_clicked()
{
    QString tmp_project_url = QFileDialog::getExistingDirectory(this,"文件夹","/");
    if(nullptr!=tmp_project_url){
        project_url = tmp_project_url;
        ui->label_2->setText(project_url);
        QSettings *user_set_write = new QSettings("config.ini",QSettings::IniFormat);
        if(nullptr!=project_url){
            user_set_write->setValue("project_url",project_url);
            user_set_write->value("project_url") ==
                    project_url?QMessageBox::information(this,"成功","设置成功")
                           :QMessageBox::information(this,"失败","设置失败");
        }
        delete user_set_write;
    }
    else {
        ui->label_2->setText(project_url);
    }
}

void Widget::on_pushButton_8_clicked()
{
    QString tmp_output_project_url = QFileDialog::getExistingDirectory(this,"文件夹","/");
    if(nullptr!=tmp_output_project_url){
        output_project_url = tmp_output_project_url;
        ui->label_3->setText(output_project_url);
        QSettings *user_set_write = new QSettings("config.ini",QSettings::IniFormat);
        if(nullptr!=output_project_url){
            user_set_write->setValue("output_project_url",output_project_url);
            user_set_write->value("output_project_url") ==
                    output_project_url?QMessageBox::information(this,"成功","设置成功")
                           :QMessageBox::information(this,"失败","设置失败");
        }
        delete user_set_write;
    }
    else {
        ui->label_3->setText(output_project_url);
    }
}

void Widget::on_pushButton_4_clicked()
{
    if(bat_url!="" && bat_url!=error_string.no_bat_url && exe_url!="" && output_url!=""){
          QMessageBox customMsgBox;
          customMsgBox.setWindowTitle("发布程序");
          QPushButton *lockButton = customMsgBox.addButton(tr("确认"),QMessageBox::ActionRole);
          QPushButton *unlockButton = customMsgBox.addButton(tr("取消"),QMessageBox::ActionRole);


          customMsgBox.setIconPixmap(QPixmap(":/qqimg/qqimg/qq.png"));
          QString tmp_output_info;
          tmp_output_info.append("qtenv2.bat路径:\n");
          tmp_output_info.append(bat_url+"\n");
          tmp_output_info.append("exe程序路径:\n");
          tmp_output_info.append(exe_url+"\n");
          tmp_output_info.append("发布程序至目标路径:\n");
          tmp_output_info.append(output_url+"\n");
          customMsgBox.setText(tmp_output_info);
          customMsgBox.exec();
          if(customMsgBox.clickedButton() == lockButton)
              output_process();
    }
    else {
        //output_process();
        QMessageBox::information(this,"提示","未选择路径");
    }
}
void Widget::output_process(){
    outprocess = new QProcess(this);
    timer = new QTimer(this);
    QDir output_dir(output_url);
    if(!output_dir.exists()){
        QMessageBox::information(this,"失败","目标文件夹路径不存在");
        return;
    }
    if(QFile::exists(output_url+"/"+exe_url.right(exe_url.size()-exe_url.lastIndexOf("/")-1))){
        QMessageBox::information(this,"失败","目标文件夹内有相同文件名，需要删除");
        return;
    }
    QFile::copy(exe_url,output_url+"/"+exe_url.right(exe_url.size()-exe_url.lastIndexOf("/")-1));
    //qDebug()<<exe_url.lastIndexOf("/")<<exe_url.size()<<exe_url.right(38-26-1);

    connect(outprocess, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
        [=](){
        info_update();
    });

    outprocess->start("cmd\n");
    //outprocess->start("pwsh\n");
    outprocess->waitForStarted();

    outprocess->write(QByteArray::fromStdString(bat_url.toStdString()+"\n"));
    outprocess->write(QByteArray::fromStdString("windeployqt "+
                                                (output_url
                                                 +"/"
                                                 +exe_url.right(exe_url.size()-exe_url.lastIndexOf("/")-1)).toStdString()+"\n"));
    outprocess->closeWriteChannel();
    outprocess->waitForFinished();
    QDesktopServices::openUrl(QUrl(output_url, QUrl::TolerantMode));

}
void Widget::info_update(){

    QTextCodec *codec = QTextCodec::codecForName("GBK");//指定QString的编码方式
    QString res;
    res.append(codec->toUnicode( outprocess->readAll() ));

    if(res!="")
    {
        qDebug()<<res;
        ui->textEdit->append(res);
    }
}
void Widget::on_pushButton_6_clicked()
{
    ui->textEdit->clear();
}
