#ifndef ENEMY1_H
#define ENEMY1_H
#include "enemy.h"


class enemy1 : public enemy
{
public:
    enemy1(QPoint p,QImage enemypic= QImage(":/new/picture/pictures/enemy1.jpg"),int _blood=5,int _bonus=5);
};

#endif // ENEMY1_H
