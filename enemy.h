#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <string>
#include <QImage>
#include <QPoint>
using namespace  std;

class enemy
{
public:
    enemy(QPoint p,QImage i);
    ~enemy();
    void get_hurt();
    bool alive();
    int getX();
    int getY();
    int getHeight();
    int getWidth();

private:

    QPoint pos;//敌人坐标
    int e_width,e_height;//敌人宽高
    QImage _pic;
    int id;//敌人编号
    int blood;//敌人血量
    int speed;//敌人速度
    int bonus;//击杀奖励
};

#endif // ENEMY_H
