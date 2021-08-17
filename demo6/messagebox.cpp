#include "messagebox.h"
#include "ui_messagebox.h"
#include "QMessageBox"
Messagebox::Messagebox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Messagebox)
{
    ui->setupUi(this);
    setWindowTitle("【QT任务3.3】");
}

Messagebox::~Messagebox()
{
    delete ui;
}

void Messagebox::on_pushButton_clicked()
{
    //button1
    switch (QMessageBox::question(this,tr("提示"),tr("是否关闭当前窗口?"), QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok)) {
    case QMessageBox::Ok:
           ui->label->setText("已选择： OK");break;
         case QMessageBox::Cancel:
           ui->label->setText("已选择： Cancel");break;
    default:
        break;
    }
}

void Messagebox::on_pushButton_2_clicked()
{
    //button2
    QMessageBox::information(this,"消息",tr("点击可关闭窗口"));
}

void Messagebox::on_pushButton_3_clicked()
{
    //button3
    switch(QMessageBox::warning(this,tr("警告"),tr("是否保存对文档的修改?"), QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel, QMessageBox::Save))
        {
        case QMessageBox::Save:
          ui->label_3->setText("已选择：  保存");break;
        case QMessageBox::Discard:
          ui->label_3->setText("已选择：  不保存");break;
        case QMessageBox::Cancel:
          ui->label_3->setText("已选择：  取消");break;
        default: break;
        }
}

void Messagebox::on_pushButton_4_clicked()
{
    //button4
    QMessageBox::critical(this,"错误", tr("发生致命错误！"));
    //ui->label_4->setText("已提示错误");
}

void Messagebox::on_pushButton_5_clicked()
{
    //button5
    QMessageBox::about(this, "关于", tr("发布于\n2020年10月19日\n15点40分\n"));
       ui->label->setText("About QMessageBox");
}

void Messagebox::on_pushButton_6_clicked()
{
    QMessageBox customMsgBox;
      customMsgBox.setWindowTitle("自定义消息框");
      QPushButton *lockButton = customMsgBox.addButton(tr("选项1"),QMessageBox::ActionRole);
      QPushButton *unlockButton = customMsgBox.addButton(tr("选项2"),QMessageBox::ActionRole);
      QPushButton *cancelButton = customMsgBox.addButton(QMessageBox::Cancel);

      customMsgBox.setIconPixmap(QPixmap(":/qqimg/qqimg/qq.png"));

      customMsgBox.setText(tr("你确定吗？"));
      customMsgBox.exec();

      if(customMsgBox.clickedButton() == lockButton)
          ui->label_6->setText(" 已选择：自定义选项1  ");
      if(customMsgBox.clickedButton() == unlockButton)
          ui->label_6->setText(" 已选择：自定义选项2  ");
      if(customMsgBox.clickedButton() == cancelButton)
          ui->label_6->setText(" 已选择：取消  ");

}

void Messagebox::on_pushButton_7_clicked()
{
    QMessageBox::aboutQt(this,"关于Qt");
      //ui->label_7->setText("About Qt QMessageBox");

}
