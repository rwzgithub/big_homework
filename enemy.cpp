#include "enemy.h"
#include <QMediaPlayer>
enemy::enemy(QPoint p,QImage i,int _blood,int _bonus):pos(p),_pic(i)
{
    this->full_blood = _blood;
    this->blood = _blood;
    this->bonus = _bonus;
}

