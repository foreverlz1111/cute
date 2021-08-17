#ifndef POINT_H
#define POINT_H
#include <QDebug>
using namespace std;
class Point
{
private:
// 数据成员
    double x;			// x坐标
    double y;			// y坐标
public:
// 公有函数
    Point(double a = 0, double b = 0){
     // 构造函数
     x = a; y = b;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }

    void Set(double a, double b){	// 设置坐标
     x = a; y = b;
    }

    void Show()			// 显示坐标
    {
        qDebug() << "(" << x << "," << y << ")" << endl;
    }   //可用qDebug()代替cout
};

#endif // POINT_H
