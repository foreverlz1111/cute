#include "clzy.h"
#include"QDebug"
#include<QRgb>

CLzy::CLzy(){
/*
 * 打开24位bmp图片 "img"
 * 根据图片宽width高度height 创建数组a[heigh][width] - [行数][列数]
 * 判断此[行数][列数]对应的rgb =(0,0,0)/(255,255,255)
 * {rgb =(0,0,0)写入^代表黑色块、rgb =(255,255,255)写入空格}
*/

}
int CLzy::get_a(){
    a = 1;
    return a;
    //check
}
int CLzy::get_x(){
    return x;
}

int CLzy::get_y(){
    return y;
}

QImage CLzy::open_file(QString img_url){
    QImage img;
    if(img_url!="")
        img.load(img_url);
    x = img.width();
    y = img.height();
    return img;
}
QVector<QString> CLzy::img_info(QImage img,QString output_ascii){
    QVector<QString> tmp;
    for(unsigned i = 0;i < img.width();++i){
        for(unsigned h = 0;h < img.height();++h){
            if(img.pixelColor(i,h).red()==255 && img.pixelColor(i,h).green()==255
                    && img.pixelColor(i,h).blue()==255)
                tmp.push_back(" ");
            else
                tmp.push_back(output_ascii);//ascii 94号 ^
        }
    }
    return tmp;
}
QImage CLzy::img_grey(QImage img,int degree){
    int height_tmp = img.height();
    int width_tmp = img.width();
    for(int i = 0;i < width_tmp ; ++i){
        for(int j = 0;j < height_tmp ; ++j){
            int grey_temp;
            grey_temp = (img.pixelColor(i,j).red()+img.pixelColor(i,j).green()+img.pixelColor(i,j).blue())/degree;
            img.setPixel(i,j,qRgb(grey_temp,grey_temp,grey_temp));

        }
    }
    return img;
}

QImage CLzy::img_average_wave(QImage img){
    int height_tmp = img.height();
    int width_tmp = img.width();
//    int matrix_tmp[3][3]= {{1,1,1},
//                           {1,0,1},
//                           {1,1,1}};
    int pixal_temp;
    for(int i = 1;i < width_tmp - 1 ; ++i){
        for(int j = 1;j < height_tmp - 1 ; ++j){
            pixal_temp =(
            img.pixelColor(i-1,j-1).red()
            +img.pixelColor(i-1,j).red()
            +img.pixelColor(i-1,j+1).red()

            +img.pixelColor(i,j-1).red()
            +img.pixelColor(i,j).red()
            +img.pixelColor(i,j+1).red()

            +img.pixelColor(i+1,j-1).red()
            +img.pixelColor(i+1,j).red()
            +img.pixelColor(i+1,j+1).red())/9;

            img.setPixel(i,j,qRgb(pixal_temp,pixal_temp,pixal_temp));
        }
    }
    return img;
}

QImage CLzy::img_gans_wave(QImage img){
    int height_tmp = img.height();
    int width_tmp = img.width();
//    int matrix_tmp[3][3]= {{1,1,1},
//                           {1,0,1},
//                           {1,1,1}};
    int pixal_temp;
    for(int i = 1;i < width_tmp - 1 ; ++i){
        for(int j = 1;j < height_tmp - 1 ; ++j){
            pixal_temp =(
            (img.pixelColor(i-1,j-1).red()/20)
            +(img.pixelColor(i-1,j).red()/10)
            +(img.pixelColor(i-1,j+1).red()/20)

            +(img.pixelColor(i,j-1).red()/10)
            +(img.pixelColor(i,j).red()/2)
            +(img.pixelColor(i,j+1).red()/10)

            +(img.pixelColor(i+1,j-1).red()/20)
            +(img.pixelColor(i+1,j).red()/10)
            +(img.pixelColor(i+1,j+1).red()/20)
                        )
                  ;

            img.setPixel(i,j,qRgb(pixal_temp,pixal_temp,pixal_temp));
        }
    }
    return img;
}

QImage CLzy::img_center_wave(QImage img){
    int height_tmp = img.height();
    int width_tmp = img.width();
    int pixal_temp;
    for(int i = 1;i < width_tmp - 1 ; i+=4){
        for(int j = 1;j < height_tmp - 1 ; j+=4){
            int matrix_tmp[9] = {
             img.pixelColor(i-1,j-1).red()
            ,img.pixelColor(i-1,j).red()
            ,img.pixelColor(i-1,j+1).red()

            ,img.pixelColor(i,j-1).red()
            ,img.pixelColor(i,j).red()
            ,img.pixelColor(i,j+1).red()

            ,img.pixelColor(i+1,j-1).red()
            ,img.pixelColor(i+1,j).red()
            ,img.pixelColor(i+1,j+1).red()
            };
            pixal_temp = choose_center(matrix_tmp);
            img.setPixel(i,j,qRgb(pixal_temp,pixal_temp,pixal_temp));
        }
    }
    return img;
}
int CLzy::choose_center(int *D){
    int temp;
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9-i;j++)
            {
                if(D[i]>D[j+1])
                {
                    temp=D[i];
                    D[i]=D[j+1];
                    D[j+1]=temp;
                }
            }
        }
        return D[4];

}
QImage CLzy::img_toWhite(QImage img){
    //黑白化
    int height_tmp = img.height();
    int width_tmp = img.width();
    for(int i = 0;i < width_tmp ; ++i){
        for(int j = 0;j < height_tmp ; ++j){
            if(img.pixelColor(i,j).red()!=255&&img.pixelColor(i,j).green()!=255&&img.pixelColor(i,j).blue()!=255){
                img.setPixel(i,j,qRgb(0,0,0));
            }
        }
    }
    return img;
}
QImage CLzy::img_light(QImage img,int degree){
    //亮度

    int height_tmp = img.height();
    int width_tmp = img.width();
    int red_tmp,green_tmp,blue_tmp;
    QColor color(255,255,255);
    if(degree == 0 )
        return img;
    else if (degree > 0) {
        for(int y = 0; y <height_tmp;++y){
            for(int x = 0; x < width_tmp;++x){
                red_tmp = img.pixelColor(x,y).red()+10*degree;
                green_tmp = img.pixelColor(x,y).green()+10*degree;
                blue_tmp = img.pixelColor(x,y).blue()+10*degree;

                //qDebug()<<red_tmp<<""<<img.pixelColor(j,i).red();
                if(red_tmp<=255){
                    color.setRed(red_tmp);
                }
                else {
                    color.setRed(255);
                }
                if(green_tmp<=255){
                    color.setGreen(green_tmp);}
                else{
                    color.setGreen(255);
                }
                if(blue_tmp<=255){
                    color.setBlue(blue_tmp);}
                else{
                    color.setBlue(255);
                }
                    img.setPixelColor(x,y,color);

            }
        }
        return img;
    }
    else if (degree < 0) {
        for(int y = 0; y <height_tmp;++y){
            for(int x = 0; x < width_tmp;++x){
                red_tmp = img.pixelColor(x,y).red()+10*degree;
                green_tmp = img.pixelColor(x,y).green()+10*degree;
                blue_tmp = img.pixelColor(x,y).blue()+10*degree;

                //qDebug()<<red_tmp<<""<<img.pixelColor(j,i).red();
                if(red_tmp>=0){
                    color.setRed(red_tmp);}
                else {
                    color.setRed(0);
                }
                if(green_tmp>=0){
                    color.setGreen(green_tmp);}
                else {
                    color.setGreen(0);
                }
                if(blue_tmp>=0){
                    color.setBlue(blue_tmp);}
                else {
                    color.setBlue(0);
                }

                    img.setPixelColor(x,y,color);

            }
        }
        return img;
    }
}
QImage CLzy::img_sobel(QImage img){
    //sobel
    int gx[9]={-1,0,1,
               -2,0,2,
               -1,0,1};
    int gy[9]={-1,-2,-1,
               0,0,0,
               1,2,1};
    int value = 120;//阈值?
    int pixal_temp_x;
    int pixal_temp_y;
    int g;
    int height_tmp = img.height();
    int width_tmp = img.width();
    for(int x = 1; x <width_tmp - 1 ;++x){
        for(int y = 1; y < height_tmp - 1 ;++y){

            pixal_temp_x =(
            (img.pixelColor(x-1,y-1).red()*(-1))
            +(img.pixelColor(x-1,y).red()*(-2))
            +(img.pixelColor(x-1,y+1).red()*(-1))

            +(img.pixelColor(x,y-1).red()*0)
            +(img.pixelColor(x,y).red()*0)
            +(img.pixelColor(x,y+1).red()*0)

            +(img.pixelColor(x+1,y-1).red()*1)
            +(img.pixelColor(x+1,y).red()*2)
            +(img.pixelColor(x+1,y+1).red()*1)
                        )/9;//====================Gx
            pixal_temp_y =(
            (img.pixelColor(x-1,y-1).red()*(-1))
            +(img.pixelColor(x-1,y).red()*0)
            +(img.pixelColor(x-1,y+1).red()*1)

            +(img.pixelColor(x,y-1).red()*(-2))
            +(img.pixelColor(x,y).red()*0)
            +(img.pixelColor(x,y+1).red()*2)

            +(img.pixelColor(x+1,y-1).red()*(-1))
            +(img.pixelColor(x+1,y).red()*0)
            +(img.pixelColor(x+1,y+1).red()*1)
                        )/9;//====================Gy
            if(abs(pixal_temp_x)+abs(pixal_temp_y)>value){
                img.setPixelColor(x,y,qRgb(0,0,0));
            }
            else {
                img.setPixelColor(x,y,qRgb(255,255,255));
            }
        }
    }

    return img;

}
QImage CLzy::img_color_red(QImage img){
    //红色分量图
    int height_tmp = img.height();
    int width_tmp = img.width();
    for(int y = 0; y <height_tmp;++y){
        for(int x = 0; x < width_tmp;++x){

            img.setPixelColor(x,y,qRgb(img.pixelColor(x,y).red(),0,0));

        }
    }
    return img;
}
QImage CLzy::img_color_green(QImage img){
    int height_tmp = img.height();
    int width_tmp = img.width();
    for(int y = 0; y <height_tmp;++y){
        for(int x = 0; x < width_tmp;++x){

            img.setPixelColor(x,y,qRgb(0,img.pixelColor(x,y).green(),0));

        }
    }
    return img;
}
QImage CLzy::img_color_blue(QImage img){
    int height_tmp = img.height();
    int width_tmp = img.width();
    for(int y = 0; y <height_tmp;++y){
        for(int x = 0; x < width_tmp;++x){

            img.setPixelColor(x,y,qRgb(0,0,img.pixelColor(x,y).blue()));

        }
    }
    return img;
}
QImage CLzy::img_save_withprinter(QImage img, QString user_input){
    //保存图片带水印


    return img;
}




