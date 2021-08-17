#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QProcess>
#include<QTimer>
#include<rwthread.h>
#include<QTextCodec>
#pragma execution_character_set("utf-8")
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void info_update();

    void debug1();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_pool_clicked();

    void on_pushButton_excel_clicked();


    void excel_query();


    void on_pushButton_4_clicked();

    void on_pushButton_request_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *pro;
    QTimer *timer = new QTimer(this);
    int timeout = 0;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
};
#endif // MAINWINDOW_H
