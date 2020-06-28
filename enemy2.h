#ifndef ENEMY2_H
#define ENEMY2_H
#include "enemy.h"

class enemy2 : public enemy
{
public:
    enemy2(QPoint p,QImage enemypic= QImage(":/new/picture/pictures/enemy2.jpg"),int _blood=10,int _bonus=10);
};

#endif // ENEMY2_H
