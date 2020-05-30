#include "enemy.h"

enemy::enemy(QPoint p,QImage i):pos(p),_pic(i)
{

}

int enemy::getX()
{
    return this->pos.x();
}
int enemy::getY()
{
    return this->pos.y();
}
int enemy::getWidth()
{
    return this->e_width;
}
int enemy::getHeight()
{
    return this->e_height;
}
void enemy::get_hurt()
{
    this->blood --;
}
