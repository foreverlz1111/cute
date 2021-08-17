#ifndef CALCULATER_H
#define CALCULATER_H

#include <QMainWindow>

namespace Ui {
class Calculater;
}

class Calculater : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculater(QWidget *parent = 0);
    ~Calculater();

    void equal_function();//计算结果

    void add_function();//加法运算预备
    void double_add_function();//只按一个数后按等于号，累加

    void dec_function();//减法预算预备
    void double_dec_function();//只按一个数后按等号，减

    void multi_function();//乘法运算预备
    void double_multi_function();//只按一个数后按等号，累乘

    void div_function();//除法运算预备
    void double_div_function();//只按一个数后按等号，累除

    void reset_function();//归零
private slots:

    //void on_button_plus_clicked();

    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_0_clicked();

    void on_button_3_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_button_9_clicked();

    void on_button_reset_clicked();

    void on_button_plus_clicked();

    void on_button_equal_clicked();

    void on_button_dec_clicked();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_button_multi_clicked();

    void on_button_dev_clicked();

    void on_button_back_key_clicked();

    void back_key_function();

    void square_function();

    bool is_count_num1_FirstZero();//count_num1输入的字符，是否第一个字符

    bool is_count_num2_FirstZero();//count_num2输入的字符，是否第一个字符

    void on_button_square_clicked();

private:
    QString count_num1;//按下运算符号前输入的字符串
    QString count_num2;//按下运算符号后
    QString op_status;//选择的运算操作
    int sum_num1 = 0;
    int sum_num2 = 0;
    int tmp_num = 0;
    int tmp_length1 = 0;//输入的字符串长度
    int tmp_length2 = 0;
    float tmp_div_num ;
    QString process_display;
    //QChar mark[4]={'+','-','*','/'};
    bool waittingfor_mark=true;//等待按下符号按键状态{'+','-','*','/'}，显示用{'+','-','X','÷'};
    Ui::Calculater *ui;
};




#endif // CALCULATER_H
