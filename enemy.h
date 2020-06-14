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
    enemy(QPoint p,QImage enemypic = QImage(":/new/picture/pictures/enemy1.jpg"));
    ~enemy()
    {}
    void get_hurt();
    bool alive();

    QPoint get_pos()
    {
        return this->pos;
    }
    QImage get_pic()
    {
        return this->_pic;
    }
    int times=0;//用于记录怪物产生的时间长短，可以控制怪物前进
    QPoint pos;//敌人坐标
    int blood = 10;//敌人血量
private:



    QImage _pic;
    int id;//敌人编号

    int speed;//敌人速度
    int bonus;//击杀奖励

};

#endif // ENEMY_H
