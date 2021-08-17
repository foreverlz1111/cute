#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include"clzy.h"
#include"QLabel"
#include"QTranslator"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    CLzy lzy;
    QLabel* url_label = new QLabel("");
    void get_img_info(QString output_ascii);
    QVector<QString> img_ascii_storage;
private slots:


    void on_pushButton_3_clicked();

    void on_action_triggered();

    void on_pushButton_4_clicked();


    void on_horizontalSlider_valueChanged(int value);


    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_des_clicked();

    void on_action_CN_triggered();

    void on_actionEnglish_EN_triggered();

    void changeEvent(QEvent *e);


    void on_pushButton_10_clicked();


    void on_horizontalSlider_light_valueChanged(int value);

    void on_pushButton_comp_pressed();

    void on_pushButton_comp_released();

    void on_pushButton_color_sobel_clicked();

    void on_pushButton_color_div_clicked();

    void on_pushButton_plus_speed_clicked();

    void on_pushButton_des_speed_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QVector<QString> temp;
    QString img_file_url;
    QImage grey_img;
    QImage source_img;
    QTranslator *translator;
    QApplication *a;
    QLabel *status_title = new QLabel("QT");
    QLabel *url_label_tip = new QLabel(tr("选择图片："));

    QMovie *movies  = new QMovie();
    int movies_status;
};

#endif // MAINWINDOW_H
