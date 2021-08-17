#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QFont"
#include"QFileDialog"
#include<QTimer>
#include<QScreen>
#include<QTranslator>
#include<QSettings>
#include<QSize>
#include<QPainter>
#include<QInputDialog>
#include<QMovie>
#include<QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->statusBar->addPermanentWidget(status_title);//右下角
    ui->statusBar->addWidget(url_label_tip);
    ui->statusBar->setStyleSheet("statusBar{background-color: rgb(255, 255, 255);}");
    QString label_grey = tr("灰度:");
    label_grey.append(QString::number(ui->horizontalSlider->value()));
    ui->label_grey->setText(label_grey);


    //ui->statusBar->addWidget(status_label);//左下角

    /*

    //ui->label->setText();
    //void Clzy::setvec(){
    QVector<QRgb> imgrgb;
        QImage img;
        img.load(":/img/images/qq.bmp");
        for(unsigned i = 0;i < img.width();++i){
            for(unsigned h = 0;h < img.height();++h){
                imgrgb.push_back(img.pixel(i,h));
                    //qDebug()<<img.pixelColor(i,h);
               // if(img.pixel(i,h)!=4294967295)//24位图生成12个数字
               //     qDebug()<<imgrgb[i,h];
                    if(img.pixelColor(i,h).red()!=255)
                       qDebug()<<i<<","<<h<<"="<<img.pixelColor(i,h).red();
            }
        }
   // }
    //#FF A1 A1

        //qDebug()<<img.pixelColor(24,86).red();
        int nums[3][3];
        nums[2][2] = 1;
    vector<int> num;
    num.push_back(nums[2][2]);
    //num.push_back(11);
    //num.push_back(145);
    qDebug()<<"输出数字"<<num[0];

    ui->label->setText("");
    qDebug()<<imgrgb[2,2]<<"?="<<img.pixel(2,2);
    qDebug()<<"宽度"<<img.width();
    qDebug()<<"高度"<<img.height();
*/

    //ui->label_output->setHidden(true);
    ui->textEdit->clear();

    ui->label_output->setAlignment(Qt::AlignCenter);

    ui->label_output_source->setAlignment(Qt::AlignCenter);
    ui->label_output_source->setHidden(true);
    //ui->textEdit->document()->setDefaultTextOption(QTextOption(Qt::AlignHCenter));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::get_img_info(QString output_ascii){
    //qDebug()<<lzy.get_a();
    //QImage img = lzy.open_file();
    QImage img = lzy.open_file(img_file_url);
    img_ascii_storage = lzy.img_info(img,output_ascii);
    QString str = "";
    for(int i = 0;i < img.width();++i){
        for(int h = 0;h < img.height();++h){
            //D:\project\qt\demo11\demo11\images
            str.append(img_ascii_storage[i + h*img.height() ]);
            if(h == img.height() - 1){
                str.append("\n");
                //qDebug()<<h;
            }
            //ui->label->setText(img_ascii_storage[200*h]);
        }
    }

    ui->textEdit->setText(str);
}

void MainWindow::on_pushButton_3_clicked()
{
    //打开图片

    movies->stop();
    QFileDialog filedialog;
    //qDebug()<<this->width()<<this->height()<<filedialog.geometry();
    filedialog.resize(940,680);
    filedialog.move(this->width()/2,this->height()/2);
    filedialog.setGeometry(this->width()/2,this->height()/2,640,480);
    //qDebug()<<filedialog.geometry();
    img_file_url = filedialog.getOpenFileName(this,"选择图片", "/","BMP图片(*.BMP);;JPG图片(*.JPG);;JPEG图片(*.JPEG)");
    //img_file_url = QFileDialog::getOpenFileName(this,"选择图片", "/","BMP图片(*.BMP);;JPG图片(*.JPG);;JPEG图片(*.JPEG)");
    filedialog.move(this->width()/2,this->height()/2);
    url_label->setText(img_file_url);
    ui->statusBar->addWidget(url_label);//用指针add不会重复
    QImage img = lzy.open_file(img_file_url);
    source_img = lzy.open_file(img_file_url);//全局打开图片
    ui->label->setPixmap(QPixmap::fromImage(img));
    QString label_height ;
    QString label_width ;
    label_width.append(tr("宽度:")+QString::number(lzy.get_x()));
    label_height.append(tr("高度:")+QString::number(lzy.get_y()));
    ui->label_height->setText(label_height);
    ui->label_width->setText(label_width);
    if(lzy.get_x()>ui->label_output->width()||lzy.get_y()>ui->label_output->height()){
        ui->label_output->setScaledContents(true);
        ui->label_output_source->setScaledContents(true);
        ui->label_output->setPixmap(QPixmap::fromImage(source_img));
    }
    else{
        ui->label_output->setScaledContents(false);
        ui->label_output_source->setScaledContents(false);
        ui->label_output->setPixmap(QPixmap::fromImage(source_img));
    }
    if(img_file_url != ""){
        ui->action_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);


        ui->label_grey->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);

        ui->pushButton_8->setEnabled(true);
        ui->label_light->setEnabled(true);


        ui->label_light->setEnabled(true);
        ui->horizontalSlider_light->setEnabled(true);

        ui->pushButton_color_div->setEnabled(true);

        ui->pushButton_comp->setEnabled(true);
    }
    else{
        ui->pushButton_4->setEnabled(false);
        ui->action_3->setEnabled(false);

        ui->label_grey->setEnabled(false);
        ui->horizontalSlider->setEnabled(false);




        ui->horizontalSlider_light->setEnabled(true);

        ui->pushButton_comp->setEnabled(false);

        ui->pushButton_color_div->setEnabled(false);
    }
}

void MainWindow::on_action_triggered()
{
    MainWindow::on_pushButton_3_clicked();
}

void MainWindow::on_pushButton_4_clicked()
{
    //开始转换
    QString output_ascii ;
    output_ascii = ui->comboBox->currentText();
    if(img_file_url != ""){
        ui->label_output->setHidden(true);
        get_img_info(output_ascii);}
}




void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //灰度
    ui->textEdit->clear();
    QString label_grey = tr("灰度:");
    label_grey.append(QString::number(value));
    ui->label_grey->setText(label_grey);
    QImage img = lzy.open_file(img_file_url);
    if(value == 2){
        //ui->label_output->resize(img.width(),img.height());
        ui->label_output->setPixmap(QPixmap::fromImage(img));
        ui->label_output->setHidden(false);

        ui->label_light->setEnabled(true);
        ui->horizontalSlider_light->setEnabled(true);


        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->label_push5->setEnabled(false);
        ui->pushButton_plus->setEnabled(false);
        ui->pushButton_des->setEnabled(false);

        ui->pushButton_color_sobel->setEnabled(false);
    }
    else {
        ui->label_light->setEnabled(false);
        ui->horizontalSlider_light->setEnabled(false);



        ui->pushButton_plus->setEnabled(true);
        ui->pushButton_des->setEnabled(true);
        ui->label_push5->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);

        //ui->label_output->resize(img.width(),img.height());
        grey_img = lzy.img_grey(img,value);
        ui->label_output->setPixmap(QPixmap::fromImage(grey_img));
        ui->label_output->setHidden(false);

        ui->pushButton_color_sobel->setEnabled(true);
    }
    if(value == 3){
        ui->pushButton_9->setEnabled(true);

    }
    else {
        ui->pushButton_9->setEnabled(false);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    //均值滤波
    QImage img = lzy.img_average_wave(grey_img);
    ui->label_output->setPixmap(QPixmap::fromImage(img));
    ui->label_output->setHidden(false);
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_6_clicked()
{
     //高斯滤波、
    QImage img;
    img = lzy.img_gans_wave(grey_img);
    ui->label_output->setPixmap(QPixmap::fromImage(img));
    ui->label_output->setHidden(false);
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_7_clicked()
{
 //中值滤波、
    QImage img ;//= lzy.open_file(img_file_url);
    img = lzy.img_center_wave(grey_img);
    ui->label_output->setPixmap(QPixmap::fromImage(img));
    ui->label_output->setHidden(false);
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_8_clicked()
{
    //另存为

    QString savename_to_url = QFileDialog::getSaveFileName(this,tr("另存为图片"),"",tr("BMP图片(*.BMP);;JPG图片(*.JPG);;JPEG图片(*.JPEG)"));
    //qDebug()<<savename_to_url;
    //QScreen *this_screen = QGuiApplication::primaryScreen();

    if(savename_to_url !=""){
        //grey_img.save(savename_to_url);
        if(ui->checkBox->isChecked())
        {

            QInputDialog inputdialog;
            inputdialog.setOkButtonText(tr("确认"));
            inputdialog.setCancelButtonText(tr("取消"));
            QString str = inputdialog.getText(this, "水印保存",
                                "输入水印内容:", QLineEdit::Normal,
                                "");

            if(str!="") {
                qDebug()<<"stirng:"<<str;
            }
                //QString tempImagePath="./wetest.png";
                //图片上的字符串，例如 当前时间
                QString imageText= str;
                QFont font;
                //设置显示字体的大小
                font.setPixelSize(30);

                //指定图片大小 自己调整
                QSize size(900, 100);
                //以ARGB32格式构造一个QImage
                QImage destinationImage(size, QImage::Format_ARGB32);
                //填充图片背景,120/250为透明度
                destinationImage.fill(qRgba(255, 255, 255, 0));
                //为这个QImage构造一个QPainter
                QPainter m_painter(&destinationImage);
                //设置画刷的组合模式CompositionMode_SourceOut这个模式为目标图像在上。
                //改变组合模式和上面的填充方式可以画出透明的图片。
                m_painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
                m_painter.setBrush(Qt::blue);

                //改变画笔和字体
                QPen pen = m_painter.pen();
                pen.setColor("#FFA1A1");

                m_painter.setPen(pen);
                m_painter.setFont(font);

                //将时间戳写在Image的中心
                m_painter.drawText(destinationImage.rect(), Qt::AlignCenter, imageText);
                //destinationImage.save(tempImagePath, "PNG", 100);

                QImage resultImage;
                QSize resultSize = source_img.size();

                resultImage = QImage(resultSize,QImage::Format_ARGB32_Premultiplied);
                QPainter::CompositionMode mode = QPainter::CompositionMode_Plus;
                QPainter painter(&resultImage);
                painter.setCompositionMode(QPainter::CompositionMode_Source);
                painter.fillRect(resultImage.rect(), Qt::transparent);
                painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
                painter.drawImage(resultSize.width()-destinationImage.width(), resultSize.height()-destinationImage.height(), destinationImage);
                    painter.setCompositionMode(mode);
                    painter.drawImage(0, 0, source_img);
                    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
                    painter.fillRect(resultImage.rect(), Qt::transparent);
                    painter.end();
                    resultImage.save(savename_to_url);

        }
        else {
        source_img.save(savename_to_url);
        }
    }
        //this_screen->grabWindow(ui->label_output->winId()).save(savename_to_url);
}

void MainWindow::on_pushButton_9_clicked()
{
    //黑白化
    //QImage img = lzy.open_file(img_file_url);

    grey_img  = lzy.img_toWhite(grey_img);
    QImage img  = grey_img;
    ui->label_output->setPixmap(QPixmap::fromImage(img));
    //ui->textEdit->set

    ui->label_output->setHidden(false);
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_plus_clicked()
{
    grey_img = grey_img.scaled(grey_img.width()*1.05,grey_img.height()*1.05,Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->label_output->setPixmap(QPixmap::fromImage(grey_img));
    qDebug()<<grey_img.size();
    //ui->label_output->resize(grey_img.width()*0.95,grey_img.height()*0.95);
}

void MainWindow::on_pushButton_des_clicked()
{

    grey_img = grey_img.scaled(grey_img.width()*0.95,grey_img.height()*0.95,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_output->setPixmap(QPixmap::fromImage(grey_img));
    //ui->label_output->resize(grey_img.width()*0.95,grey_img.height()*0.95);

}

void MainWindow::on_action_CN_triggered()
{

    //中文翻译转换
    translator = new QTranslator();
    translator->load(":/tr/cn.qm");
    a->installTranslator(translator);
    url_label_tip ->setText( tr("选择图片："));
    status_title->setText("QT");
    ui->textEdit->clear();
}

void MainWindow::on_actionEnglish_EN_triggered()
{

    //英文翻译转换
    translator = new QTranslator();
    translator->load(":/tr/us.qm");
    a->installTranslator(translator);
    url_label_tip ->setText( tr("选择图片："));
    status_title->setText("QT");
    ui->textEdit->clear();
}
void MainWindow::changeEvent(QEvent *e){
    //翻译适应
    QWidget::changeEvent(e);
           switch (e->type()) {
               case QEvent::LanguageChange:
                   ui->retranslateUi(this);
                   break;
               default:
                   break;
           }
}


void MainWindow::on_pushButton_10_clicked()
{
    //打开GIF
    QString gif_file_url = QFileDialog::getOpenFileName(this,tr("选择图片"), "/",tr("Gif图片(*.gif)"));
    if(gif_file_url!=""){
        movies->stop();
        movies->setFileName(gif_file_url);
        qDebug()<<movies->fileName();

        movies->start();
        ui->label->setPixmap(QPixmap::fromImage(movies->currentImage()));
        QString label_width;
        label_width.append(tr("宽度:")+QString::number(movies->frameRect().width()));
        QString label_height;
        label_height.append(tr("高度:")+QString::number(movies->frameRect().height()));
        ui->label_height->setText(label_height);
        ui->label_width->setText(label_width);
        url_label->setText(gif_file_url);
        ui->statusBar->addWidget(url_label);//用指针add不会重复

        //ui->label_output->setMovie(movies);

        movies->setSpeed(100);
        movies_status = 0;
        QObject::connect(movies, &QMovie::frameChanged, [=](int frameNumber) {

            if(movies_status == 0)
                ui->label_output->setPixmap(QPixmap::fromImage(movies->currentImage()));
            else if (movies_status == 1) {
                ui->label_output->setPixmap(QPixmap::fromImage(lzy.img_grey(movies->currentImage(),3)));
            }
            else if (movies_status == 2) {
                ui->label_output->setPixmap(QPixmap::fromImage(lzy.img_sobel(lzy.img_grey(movies->currentImage(),9))));
            }
           });
        ui->label_output->setScaledContents(false);

        ui->label_output->setHidden(false);

        ui->label_speed->setEnabled(true);
        ui->pushButton_plus_speed->setEnabled(true);
        ui->pushButton_des_speed->setEnabled(true);

        qDebug()<<movies->frameCount();

    }
}



void MainWindow::on_horizontalSlider_light_valueChanged(int value)
{
    //亮度
    ui->textEdit->clear();
    QString label_light = tr("亮度:");
    label_light.append(QString::number(value));
    ui->label_light->setText(label_light);
    QImage tmp;
    tmp = lzy.img_light(source_img,value);
    ui->label_output->setPixmap(QPixmap::fromImage(tmp));
    //qDebug()<<value;
    ui->label_output->setHidden(false);
    if(value!=0){
        ui->pushButton_comp->setEnabled(true);

    }
    else {
       ui->pushButton_comp->setEnabled(false);
    }

}

void MainWindow::on_pushButton_comp_pressed()
{

    ui->label_output_source->setPixmap(QPixmap::fromImage(source_img));
    ui->label_output_source->setHidden(false);
    ui->label_output->setHidden(true);
}

void MainWindow::on_pushButton_comp_released()
{
     qDebug()<<"release";
     ui->label_output_source->setHidden(true);
     ui->label_output->setHidden(false);
}

void MainWindow::on_pushButton_color_sobel_clicked()
{
    //sobel
    QImage tmp;
    tmp = lzy.img_sobel(grey_img);
    ui->label_output->setPixmap(QPixmap::fromImage(tmp));
    ui->label_output->setHidden(false);
}

void MainWindow::on_pushButton_color_div_clicked()
{
    //RGB分量图
    QImage tmp;
    if(ui->comboBox_color->currentText()==tr("红")){
        tmp = lzy.img_color_red(source_img);
    }
    else if (ui->comboBox_color->currentText()==tr("绿")) {
        tmp = lzy.img_color_green(source_img);
    }
    else if(ui->comboBox_color->currentText()==tr("蓝")){
        tmp = lzy.img_color_blue(source_img);
    }
    ui->label_output->setPixmap(QPixmap::fromImage(tmp));
}

void MainWindow::on_pushButton_plus_speed_clicked()
{
    //增速
    if(movies->speed()<300){
    QString str = tr("速度:");
    movies->setSpeed(movies->speed()+10);
    str.append(QString::number(movies->speed()));
    str.append("%");
    ui->label_speed->setText(str);}
}

void MainWindow::on_pushButton_des_speed_clicked()
{
    //慢速
    QString str = tr("速度:");
    if(movies->speed()>0){
    movies->setSpeed(movies->speed()-10);
    str.append(QString::number(movies->speed()));
    str.append("%");
    ui->label_speed->setText(str);}
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    movies_status = arg1;
}
