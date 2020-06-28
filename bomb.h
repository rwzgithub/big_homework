#ifndef BOMB_H
#define BOMB_H
#include <QPoint>
#include <QImage>


class bomb
{
public:
    bomb(QPoint p,QImage pi= QImage(":/new/picture/pictures/bomb.jpg"));//引入图片

    ~bomb(){}//塔的析构

    QPoint getP(){return pos;}//得到坐标

    void setP(QPoint p){pos=p;}//修改坐标

    QImage getPic(){return pic;}//得到绘图

    int power = 5;

    int get_cost()
    {
        return this->cost;
    }

private:
    QPoint pos;//塔的坐标

    QImage pic;

    int cost = 30;
    int towards;

};

#endif // BOMB_H
