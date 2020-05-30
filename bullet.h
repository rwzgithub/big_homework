#ifndef BULLET_H
#define BULLET_H
#include <QPainter>
#include <QPoint>

class Bullet
{
public:
    Bullet(QPoint p,QImage zidan=QImage(":/new/picture/pictures/bullet.png"));

    void setpos(QPoint p){pos=p;}
    void move(int d);//让子弹运动的函数
//private:
    QPoint pos; //子弹的位置(原为start）
    QImage zd; //子弹绘图
    int direct;//子弹方向？？
    bool attact;//是否击中
};

#endif // BULLET_H
