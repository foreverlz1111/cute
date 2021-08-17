#include "standdialog.h"
#include "ui_standdialog.h"
#include "QFileDialog"
#include "QColorDialog"
#include "QFontDialog"
standDialog::standDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::standDialog)
{
    ui->setupUi(this);
    setWindowTitle("【QT任务3.1】");
}

standDialog::~standDialog()
{
    delete ui;
}


void standDialog::on_pushButton_clicked()
{
    //选择文件路径
    QString s=QFileDialog::getOpenFileName(this,"open file dialog", "/","C++files(*.cpp);;C files(*.c);;Head files(*.h)");
    ui->filelineEdit->setText(s.toUtf8());
}

void standDialog::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::blue);
      if(color.isValid())
        {
          ui->colorframe->setPalette(QPalette(color));
        }
}

void standDialog::on_pushButton_3_clicked()
{
    bool ok;
        QFont font = QFontDialog::getFont(&ok);
        if(ok)
          {
            ui->fontlineeidt->setFont(font);
          }
}
