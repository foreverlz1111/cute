#ifndef ERROR_STRING_H
#define ERROR_STRING_H

#include<QString>
#pragma execution_character_set("utf-8")
class Error_string
{
public:
    Error_string();
    QString illegel_url = "不合法的路径！";
    QString no_bat_url = "请设置qtenv2.bat路径";
    QString no_project_url = "未设置项目默认路径";
    QString no_output_project_url = "未设置项目默认输出路径";
};

#endif // ERROR_STRING_H
