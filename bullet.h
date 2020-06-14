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
    QImage get_pic()
    {
        return this->zd;
    }
    int power = 1;//子弹威力
//private:
    QPoint pos; //子弹的位置(原为start）
    QImage zd; //子弹绘图
    int times = 0;//用于记录防止炮塔后的时间，可以用来在每次repaint时使子弹前进
    bool attact;//是否击中
};

#endif // BULLET_H
