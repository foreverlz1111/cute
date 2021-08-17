#include "calculater.h"
#include "ui_calculater.h"
#include "aboutit.h"
Calculater::Calculater(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculater)
{
    ui->setupUi(this);
    ui->statusBar->hide();
    ui->mainToolBar->hide();
    ui->result_line->setText("0");//输出显示测试
    ui->process_label->setText("");//输出显示测试
    //ui->button_equal->setEnabled(false);//按钮禁按
    //ui->button_back_key->setEnabled(false);
    //ui->button_plus->setEnabled(false);
    //ui->button_dec->setEnabled(false);
    //ui->button_multi->setEnabled(false);
    //ui->button_dev->setEnabled(false);
}

Calculater::~Calculater()
{
    delete ui;
}

void Calculater::on_action_4_triggered()
{
    Aboutit Aboutit;
    Aboutit.setWindowTitle("关于此计算器");
    Aboutit.setWindowIcon(QIcon(":/img/network-question.png"));
    Aboutit.exec();
}

void Calculater::on_action_5_triggered()
{
    Calculater::on_button_reset_clicked();//按下菜单栏清除，转到清除按钮
}

void Calculater::on_button_0_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0 ){
        //运算完成，再按数字直接开始新运算
        reset_function();
        //count_num1.append("0");
        ui->result_line->setText("0");
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true){
       //如果就是初始状态，按下0无变化

        if(!is_count_num1_FirstZero()){
           count_num1.append("0");
           ui->result_line->setText(count_num1);
        }

    }

    else if(waittingfor_mark == false && is_count_num2_FirstZero()){
        //如果就是初始状态，按下0无变化

        if(!is_count_num2_FirstZero()){
            count_num2.append("0");
            ui->result_line->setText(count_num2);
        }
    }
}
void Calculater::on_button_1_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("1");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true){
       count_num1.append("1");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("1");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_2_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("2");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true ){
       count_num1.append("2");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("2");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_3_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("3");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true){
       count_num1.append("3");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("3");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_4_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("4");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true ){
       count_num1.append("4");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("4");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_5_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("5");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true){
       count_num1.append("5");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("5");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_6_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("6");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true ){
       count_num1.append("6");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("6");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_7_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
         reset_function();
         count_num1.append("7");
         ui->result_line->setText(count_num1);
         ui->process_label->setText("");
     }
    else if(waittingfor_mark == true ){
       count_num1.append("7");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("7");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_8_clicked()
{
    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("8");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
     else if(waittingfor_mark == true){
       count_num1.append("8");
       ui->result_line->setText(count_num1);
    }

    else if(waittingfor_mark == false){
        count_num2.append("8");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_9_clicked()
{

    if(waittingfor_mark == true && count_num1 != "" && sum_num2 != 0){
        reset_function();
        count_num1.append("9");
        ui->result_line->setText(count_num1);
        ui->process_label->setText("");
    }
    else if(waittingfor_mark == true ){
        count_num1.append("9");
        ui->result_line->setText(count_num1);
     }
    else if(waittingfor_mark == false){
        count_num2.append("9");
        ui->result_line->setText(count_num2);
    }
}

void Calculater::on_button_reset_clicked()
{
    reset_function();
    ui->result_line->setText("0");//清空归零
    ui->process_label->setText("");
}

void Calculater::on_button_plus_clicked()
{
    if(waittingfor_mark == true && count_num1 != ""){
        add_function();
        ui->process_label->setText(process_display);
        ui->result_line->setText("0");
        ui->button_equal->setEnabled(true);
    }
}

void Calculater::on_button_equal_clicked()
{
    //等于号按下，状态判断
    if(waittingfor_mark == false && count_num2 != "")
        equal_function();
    else if(waittingfor_mark == false && count_num2 == "") {
        if(op_status == "+"){
            double_add_function();
            ui->process_label->setText(process_display);
            ui->result_line->setText(QString::number(tmp_num));
        }
        else if(op_status == "-") {
            double_dec_function();
            ui->process_label->setText(process_display);
            ui->result_line->setText(QString::number(tmp_num));
        }
        else if(op_status == "*"){
            double_multi_function();
            ui->process_label->setText(process_display);
            ui->result_line->setText(QString::number(tmp_num));
        }
        else if(op_status == "/"){
            double_div_function();
            ui->process_label->setText(process_display);
            ui->result_line->setText(QString::number(tmp_num));
        }
    }
}

void Calculater::add_function(){
    //点击加号后
    if(tmp_num == 0){
    process_display.append(count_num1).append("+");
    sum_num1 = count_num1.toInt();
    op_status = "+";//记录此时等待运算状态为加法
    waittingfor_mark = false;
    }
    else if(tmp_num != 0){
        sum_num2=0;//清零操作
        count_num2="";//清零操作
        sum_num1=tmp_num;
        count_num1 = QString::number(tmp_num);
        process_display.clear();
        process_display.append(count_num1).append("+");
        op_status = "+";
        waittingfor_mark = false;//等待第二次加数输入
    }
}

void Calculater::equal_function(){
    //点击运算符号并填写数字2后
    process_display.append(count_num2).append("=");
    sum_num2 = count_num2.toInt();
    if(op_status == "+"){
        tmp_num = sum_num1 + sum_num2;
        ui->process_label->setText(process_display);
        ui->result_line->setText(QString::number(tmp_num));//int转回string进行显示
    }
    else if(op_status == "-"){
        tmp_num = sum_num1 - sum_num2;
        ui->process_label->setText(process_display);
        ui->result_line->setText(QString::number(tmp_num));//int转回string进行显示
    }
    else if(op_status == "*"){
        tmp_num = sum_num1 * sum_num2;
        ui->process_label->setText(process_display);
        ui->result_line->setText(QString::number(tmp_num));//int转回string进行显示
        }
    else if(op_status == "/"){
        tmp_div_num = (float)sum_num1 / (float)sum_num2;
        tmp_num = sum_num1 / sum_num2;
        ui->process_label->setText(process_display);
        if(tmp_div_num == tmp_num)
            ui->result_line->setText(QString::number(tmp_div_num));//转回string进行显示
        else if(tmp_div_num > tmp_num)
            ui->result_line->setText(QString::number(tmp_div_num));//转回string进行显示
        else if(tmp_div_num < tmp_num){
             ui->result_line->setText(QString::number(tmp_num));
        }
        }
    waittingfor_mark = true;
}
void Calculater::double_add_function(){
    //自加
    if(count_num2 == "" && sum_num2 == 0){
        //第一次
        sum_num2 = sum_num1;
        process_display.append(QString::number(sum_num2)).append("=");
        tmp_num = sum_num1 + sum_num2;
    }
    else if(sum_num2!=0){
        //第N+1次（int N > 0）
        sum_num1 = tmp_num;
        tmp_num = sum_num1 + sum_num2;
        process_display.clear();
        process_display.append(QString::number(sum_num1)).append(op_status).append(QString::number(sum_num2)).append("=");
    }
}
void Calculater::reset_function(){
    //归零按钮
    count_num1.clear();
    count_num2.clear();
    sum_num1 = 0;
    sum_num2 = 0;
    tmp_length1 = 0;
    tmp_length2 = 0;
    tmp_num = 0;
    tmp_div_num = 0;
    op_status.clear();
    waittingfor_mark = true;
    process_display.clear();
}

void Calculater::on_button_dec_clicked()
{
    if(waittingfor_mark == true && count_num1 != ""){
        dec_function();
        ui->process_label->setText(process_display);
        ui->result_line->setText("0");
    }
}
void Calculater::dec_function(){
    //点击减号后
    if(tmp_num == 0){
    process_display.append(count_num1).append("-");
    sum_num1 = count_num1.toInt();
    op_status = "-";//记录此时等待运算状态为减法
    waittingfor_mark = false;
    }
    else if(tmp_num != 0){
        sum_num2=0;//清零操作
        count_num2="";//清零操作
        sum_num1=tmp_num;
        count_num1 = QString::number(tmp_num);
        process_display.clear();
        process_display.append(count_num1).append("-");
        op_status = "-";
        waittingfor_mark = false;//等待第二次减数输入
    }
}
void Calculater::double_dec_function(){
    //自减
    if(count_num2 == "" && sum_num2 == 0){
        //第一次
        sum_num2 = sum_num1;
        process_display.append(QString::number(sum_num2)).append("=");
        tmp_num = sum_num1 - sum_num2;
    }
    else if(sum_num2!=0){
        //第N+1次（int N > 0）
        sum_num1 = tmp_num;
        tmp_num = sum_num1 - sum_num2;
        process_display.clear();
        process_display.append(QString::number(sum_num1)).append(op_status).append(QString::number(sum_num2)).append("=");
    }
}

void Calculater::on_button_multi_clicked()
{
    if(waittingfor_mark == true && count_num1 != ""){
        multi_function();
        ui->process_label->setText(process_display);
        ui->result_line->setText("0");
    }
    else if (waittingfor_mark == false && count_num2 == ""){
        multi_function();
        ui->process_label->setText(process_display);
        ui->result_line->setText("0");
    }
}
void Calculater::multi_function(){
    //点击乘号后
    if(tmp_num == 0 && count_num1 != ""){
    process_display.append(count_num1).append("X");
    sum_num1 = count_num1.toInt();
    op_status = "*";//记录此时等待运算状态为乘法
    waittingfor_mark = false;
    }
    else if(tmp_num != 0 && count_num2 != ""){
        sum_num2=0;//清零操作
        count_num2="";//清零操作
        sum_num1=tmp_num;
        count_num1 = QString::number(tmp_num);
        process_display.clear();
        process_display.append(count_num1).append("X");
        op_status = "*";
        waittingfor_mark = false;//等待第二次乘数输入
    }
    else if(tmp_num !=0 && count_num2 == ""){
        sum_num1=tmp_num;
        count_num1 = QString::number(tmp_num);
        process_display.clear();
        process_display.append(count_num1).append("X");
        op_status = "*";
        waittingfor_mark = false;//等待第二次乘数输入
    }
}
void Calculater::double_multi_function(){
    //自乘
    if(sum_num2 == 0){
        //第一次运算
        //且count_num2不能赋值，否则再次按等号无法跳入，通过赋值sum_num2间接显示count_num2
        sum_num2 = sum_num1;
        process_display.append(QString::number(sum_num2)).append("=");
        tmp_num = sum_num1 * sum_num2;
    }
    else if(sum_num2 != 0){
        //第N+1次（int N > 0）
        sum_num1 = tmp_num;
        count_num1 = QString::number(sum_num1);
        //第一次累乘运算已经得到count_num2和sum_num2，直接用，直到归零
        tmp_num = sum_num1 * sum_num2;
        process_display.clear();
        process_display.append(count_num1).append("X").append(QString::number(sum_num2)).append("=");
    }
}

void Calculater::on_button_dev_clicked()
{
    if(waittingfor_mark == true && count_num1 != ""){
        div_function();
        ui->process_label->setText(process_display);
        ui->result_line->setText("0");
    }
    else if (waittingfor_mark == false && count_num2 == ""){
        div_function();
        ui->process_label->setText(process_display);
        ui->result_line->setText("0");
    }
}

void Calculater::div_function(){
    //点击除号后
    if(tmp_num == 0 && count_num1 != ""){
    process_display.append(count_num1).append("÷");
    sum_num1 = count_num1.toInt();
    op_status = "/";//记录此时等待运算状态为除法
    waittingfor_mark = false;
    }
    else if(tmp_num != 0 && count_num2 != ""){
        sum_num2=0;//清零操作
        count_num2="";//清零操作
        sum_num1=tmp_num;
        count_num1 = QString::number(tmp_num);
        process_display.clear();
        process_display.append(count_num1).append("÷");
        op_status = "/";
        waittingfor_mark = false;//等待第二次除数输入
    }
    else if(tmp_num !=0 && count_num2 == ""){
        sum_num1=tmp_num;
        count_num1 = QString::number(tmp_num);
        process_display.clear();
        process_display.append(count_num1).append("÷");
        op_status = "/";
        waittingfor_mark = false;//等待第二次除数输入
    }
}
void Calculater::double_div_function(){
    //自除，一次运算
    if(sum_num2 == 0){
        //第一次运算
        sum_num2 = sum_num1;
        process_display.append(QString::number(sum_num2)).append("=");
        tmp_num = sum_num1 / sum_num2;
    }
}

void Calculater::on_button_back_key_clicked()
{
    back_key_function();
}

void Calculater::back_key_function(){
    //退格方法调用类
    if(waittingfor_mark == true && count_num1 != ""){
        tmp_length1 = count_num1.size();
        if(tmp_length1 == 1){
            reset_function();//操作意图：重置
            ui->result_line->setText("0");
        }
        else if(tmp_length1 > 1) {
            count_num1 = count_num1.left(tmp_length1 - 1);
            ui->result_line->setText(count_num1);
        }
        tmp_length1 = 0;//清除
    }
    else if(waittingfor_mark == false && count_num2 != ""){
       tmp_length2 = count_num2.size();
       if(tmp_length2 == 1){
           count_num2 = "" ;//操作意图：清除错误操作
           ui->result_line->setText("0");
       }
       else if(tmp_length2 > 1) {
           count_num2 = count_num2.left(tmp_length2 - 1);
           ui->result_line->setText(count_num2);
       }
       tmp_length2 = 0;//清除
    }
}
bool Calculater::is_count_num1_FirstZero(){
    //第一个字符，是否是0
    //count_num1默认为""，显示则为0；
    tmp_length1 = count_num1.size();
    if(tmp_length1 == 0){
        return true;//第一位显示是0,count_num1为""，无操作
    }
    else if (tmp_length1 >= 1){
        return false;
    }
    tmp_length1 = 0;
}
bool Calculater::is_count_num2_FirstZero(){
    tmp_length2 = count_num2.size();
    if(tmp_length2 == 0){
        return true;//第一位显示是0,count_num2为""，无操作
    }
    else if (tmp_length2 >= 1){
        return false;
    }
    tmp_length2 = 0;
}

void Calculater::on_button_square_clicked()
{
     square_function();

}
void Calculater::square_function(){
    if(waittingfor_mark == true && count_num1 != "" && count_num2 == "" ){
    sum_num1 = count_num1.toInt();
    tmp_num = sum_num1 * sum_num1;
    ui->process_label->setText("sqr("+count_num1 + ")=");
    ui->result_line->setText(QString::number(tmp_num));
    waittingfor_mark = false;
    }
    else if(waittingfor_mark == true && count_num1 != "" && count_num2 != ""){
        if(tmp_num >= 65536){
           ui->process_label->setText("异常");
           ui->result_line->setText("溢出");
        }else{
        sum_num1 = tmp_num;
        tmp_num = sum_num1 * sum_num1;
        ui->process_label->setText("sqr("+QString::number(sum_num1)+")=");
        ui->result_line->setText(QString::number(tmp_num));}
    }
    else if(waittingfor_mark == false && count_num1 != ""){

     if(tmp_num >= 65536){
        ui->process_label->setText("异常");
        ui->result_line->setText("溢出");
     }
     else {
         sum_num1 = tmp_num;
         tmp_num = sum_num1 * sum_num1;
         ui->process_label->setText("sqr("+QString::number(sum_num1)+")=");
         ui->result_line->setText(QString::number(tmp_num));
     }
    }
}
