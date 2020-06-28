#ifndef BOSS_H
#define BOSS_H
#include "enemy.h"


class boss : public enemy
{
public:
    boss(QPoint p,QImage enemypic= QImage(":/new/picture/pictures/boss.jpg"),int _blood=20,int _bonus=30);
};


#endif // BOSS_H
