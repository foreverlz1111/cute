#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double getnum(){
        return num;//获取数字
    }
    void setnum(int n){
        num=n;//设定数字
    }


private slots:
    void on_resetbutton_clicked();

    void on_addbutton_clicked();

    void on_incbutton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int num=0;
};

#endif // MAINWINDOW_H
