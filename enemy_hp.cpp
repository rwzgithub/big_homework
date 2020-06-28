#include "enemy_hp.h"

enemy_hp::enemy_hp(enemy* _who):who(_who)
{
    setMaximum(100);//设置上限
    setMinimum(0);//设置下限
    rect_hp = QRect(who->get_pos().x(),who->get_pos().y()-15,100,15);
    below = QPixmap(":/new/picture/pictures/blood_below.png");//设置血槽
    above = QPixmap(":/new/picture/pictures/blood_above.png");//设置血条
}

void enemy_hp::show(QPainter *p)
{
    ratio = (double)(value()-minimum())/(maximum()-minimum());
    len = (double)(rect_hp.width()*ratio);//血条长度
    rect_fill=rect_hp.adjusted(0,0,len-rect_hp.width(),0);
    //调整宽高，前两个数值是坐标该变量，后两个数值是宽高改变量
    this->setValue(100*(who->blood)/who->full_blood);
    //下面开始绘制
    rect_hp.moveTo(who->get_pos().x(),who->get_pos().y()-15);
    rect_fill.moveTo(who->get_pos().x(),who->get_pos().y()-15);
    p->drawPixmap(rect_hp,below);
    p->drawPixmap(rect_fill,above);//绘制血槽并按照其比例填充血条

}
