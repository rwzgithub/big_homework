#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include "bullet.h"

class Tower
{
public:
    Tower(QPoint p,QImage pi=QImage(":/new/picture/pictures/tower1.jpg"));//引入图片
    ~Tower(){}
    QPoint centrePoint();
    void draw();
    QPoint getP(){return pos;}
    void setP(QPoint p){pos=p;}
        int getA(){return  arc;}
        void setA(int a){arc=a;}
        void rotate(QMatrix m){
            pic=pic.transformed(m,Qt::FastTransformation);
        }
        QImage getPic(){return pic;}
      //  QPoint getCP(){return Cpos;}

        QList <Bullet> bullets;
        int count=0;//生成子弹计数
    private:


        QPoint pos;//塔的坐标
        QImage pic;

        QTimer * timer;
       // QPoint Cpos;//中心坐标

        int direct;
        int arc;//角度

     //   int damage;//塔伤，第一阶段先不考虑
        int range;//攻击范围
        int rate;
        int cost;
        int towards;


};

#endif // TOWER_H
