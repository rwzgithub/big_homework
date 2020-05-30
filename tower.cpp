#include "tower.h"


Tower::Tower(QPoint p,QImage pi)
    :pos(p),pic(pi)
{
  //  Cpos.setX(pos.x()+60);
 //   Cpos.setY(pos.y()+50);

    count=30;
}

void Tower::draw()
{
    QPainter painter;
    painter.drawImage(pos.x(),pos.x(),pic);//画图
}
