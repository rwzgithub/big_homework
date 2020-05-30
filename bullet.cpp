#include "bullet.h"
#include <qmath.h>
Bullet::Bullet(QPoint p, QImage zidan):pos(p),zd(zidan)
{
    attact = 0;
}

void Bullet::move(int d)
{
    int x=pos.x();
    int y=pos.y();
    pos.setX(x+qCos(d)*40);
    pos.setY(y+qCos(d)*40);

}
