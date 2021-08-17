#include "infodialog.h"
#include "ui_infodialog.h"
#include "QFileDialog"
InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_img_change_clicked()
{
    QString qimg_url = QFileDialog::getOpenFileName(this,"选择头像","/","图片文件(*.png *.jpg)");
    //ui->lineEdit->setText(qimg_url.toUtf8());
    QImage* img = new QImage;
    //选了才输入
    if(qimg_url!=""){
    img->load(qimg_url);
    ui->img_label->setPixmap(QPixmap::fromImage(*img)); }
}
