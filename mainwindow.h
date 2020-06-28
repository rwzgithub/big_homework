#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QtDebug>
#include <QPainter>
#include <tower.h>
#include "bullet.h"
#include "enemy.h"
#include <QList>
#include "new_window.h"
#include "new_window_defeat.h"
#include "enemy1.h"
#include "enemy2.h"
#include "boss.h"
#include "bomb.h"
#include "enemy_hp.h"
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);//用于ui的绘制
    void timerEvent(QTimerEvent *);
    void mouseReleaseEvent(QMouseEvent *);//松开鼠标
    void mousePressEvent(QMouseEvent *);//按下鼠标
    void mouseMoveEvent(QMouseEvent *);//鼠标移动
    void open_new_window(); //游戏胜利
    void open_new_defeat_window();//游戏失败

private:
    Ui::MainWindow *ui;
    bool touch;//是否触碰塔
    int choose0;//是否选中塔
    bool newWindow_painted = false;//是否已经绘制了新窗口
    QPoint cur;//current即当前鼠标坐标
    int killed_num = 0;//记录击杀怪物数
    int printed_num = 0;//记录出现怪物数
    QList <Tower> towers;//炮塔的列表
    QList <bomb> bombs;//炸弹列表
    QList <enemy*> enemies;//怪物的列表
    QList <enemy_hp*> hps;//血条的列表
    enemy_hp* thp;
    static const int HARF_LENTH = 50;
    static const int HEIGHT = 100;
    static const int COOL_TIME = 100;//冷却时间
    static const int _CT = 2;//冷却时间减少量
    QMediaPlayer *player;

    int back_y[5]={4,108,212,316,420};//每条道路的y坐标，用于怪物的出现

    int timeID;
    int timeID1;
    int timeID2;
    int timeID3;
    int money=100;
    QString m=QString::number(money);
    //计时器
    int power1 = 2;//第一种子弹的伤害
    int tower_power = 2;//怪物吃塔要承受的伤害
    int nowX;
    int nowY;//鼠标现在坐标
    bool settled;
    bool win=false;//是否胜利
    bool over=false;//是否结束
    bool stop_print_enemy = false;//不再出现怪物
    bool boss_printed = false;//不再出现boss
};
#endif // MAINWINDOW_H
