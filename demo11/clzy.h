#ifndef CLZY_H
#define CLZY_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include"QDebug"
#include "QRgb"
#include"QImage"
#include"QRgb"
#include"QVector"
#include<QMovie>
#pragma execution_character_set("utf-8")
using namespace std;
class CLzy
{
private:
    int a;
    int x;//图片width
    int y;//height
    //QVector<QRgb> imgrgb;
public:
    CLzy();
    int get_a();
    int get_x();
    int get_y();
    QImage open_file(QString img_url);
    void read_img();
    QVector<QString> img_info(QImage img,QString output_ascii);
    QImage img_grey(QImage img,int degree);
    QImage img_average_wave(QImage img);
    QImage img_gans_wave(QImage img);
    QImage img_center_wave(QImage img);
    QImage img_toWhite(QImage img);
    int choose_center(int tmp[9]);

    QImage img_save_withprinter(QImage img,QString user_input);
    QImage img_light(QImage img,int degree);
    QImage img_sobel(QImage img);
    QImage img_color_red(QImage img);
    QImage img_color_green(QImage img);
    QImage img_color_blue(QImage img);


};


#endif // CLZY_H
