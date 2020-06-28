#ifndef ENEMY_HP_H
#define ENEMY_HP_H
#include <QProgressBar>
#include "enemy.h"
#include <QPainter>

//这个类是敌人的血条

class enemy_hp : public QProgressBar
{
public:
    enemy_hp(enemy* _who);
    void show(QPainter* p);//绘制血条的函数
private:
    enemy* who;
    QRect rect_hp;//画血条的矩形
    QRect rect_fill;//血条填充
    double ratio;//当前血量占比
    double len;//当前血条长度
    QPixmap below;
    QPixmap above;

};

#endif // ENEMY_HP_H
