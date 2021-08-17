#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include<error_string.h>
#include<QTimer>
#include<QProcess>
#pragma execution_character_set("utf-8")
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString bat_url = "";
    QString exe_url = "";
    QString project_url = "";
    QString output_project_url = "";
    QString output_url = "";

private slots:
    void on_pushButton_2_clicked();
    void update_bat_url();
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void output_process();

    void info_update();
    void on_pushButton_6_clicked();

private:
    QProcess *outprocess;
    QTimer *timer;
    Error_string error_string;
    Ui::Widget *ui;
};
#endif // WIDGET_H
