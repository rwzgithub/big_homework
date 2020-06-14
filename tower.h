#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QPainter>
#include "bullet.h"

class Tower
{
public:
    Tower(QPoint p,QImage pi=QImage(":/new/picture/pictures/tower1.jpg"));//引入图片

    ~Tower(){}//塔的析构

    QPoint getP(){return pos;}//得到坐标

    void setP(QPoint p){pos=p;}//修改坐标

    QImage getPic(){return pic;}//得到绘图


//以下变量先放在public里方便使用，后期慢慢改

    QList <Bullet> bullets;//子弹列表

    int cooling_time = 100;//冷却时间记为100，减为零时可以发射一颗子弹



private:
    QPoint pos;//塔的坐标

    QImage pic;

    QTimer * timer;
     //   int damage;//塔伤，第一阶段先不考虑

    int cost;
    int towards;

};

#endif // TOWER_H
