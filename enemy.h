#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <string>
#include <QImage>
#include <QPoint>
#include <QMediaPlayer>
using namespace  std;

class enemy
{
public:
    enemy(QPoint p,QImage enemypic,int _blood,int _bonus);// = QImage(":/new/picture/pictures/enemy1.jpg")
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
    void set_pos(QPoint p)
    {
        this->pos = p;
    }
    int times=0;//用于记录怪物产生的时间长短，可以控制怪物前进
    QPoint pos;//敌人坐标
    int blood;//敌人血量
    int full_blood;
    int get_bonus()
    {
        return this->bonus;
    }


private:
    QImage _pic;
    int id;//敌人编号

    int speed;//敌人速度
    int bonus;//击杀奖励

};

#endif // ENEMY_H
