#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include "tower.h"
#include <QtMath>
#include <iostream>
#include <cstdlib>
#define PI 3.1415926
#define target_num 10
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timeID=startTimer(20);//每10毫秒调用一次
    timeID1=startTimer(20);
    timeID2=startTimer(5000);
    timeID3=startTimer(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(over == false)
    {
        painter.drawPixmap(rect(),QPixmap(":/new/picture/pictures/backg.jpg"));
        painter.drawPixmap(0,0,QPixmap(":/new/picture/pictures/tower1.jpg"));


        for(int i=0;i<towers.size();i++)
        {
            bool kill_tower = false;//标记此次循环是否删除了塔
            painter.drawImage(towers[i].getP(),towers[i].getPic());//画出所有放置好的塔

            //画子弹，利用循环画出所有炮塔的子弹

            for(int j=0;j<towers[i].bullets.size();j++)
            {
                bool kill_bullet = false;
                //将子弹坐标修改为当前值
                towers[i].bullets[j].pos.setX(towers[i].getP().x()+HARF_LENTH+towers[i].bullets[j].times);
                if(towers[i].bullets[j].pos.x()>=900)
                    towers[i].bullets.removeFirst();
                //画出子弹
                painter.drawImage(towers[i].bullets[j].pos,towers[i].bullets[j].get_pic());

                for(int k=0;k<enemies.size();k++)
                {
                    bool kill_enemy = false;//标记此次循环是否删除了怪物
                    if(enemies[k].get_pos().x()<=towers[i].bullets[0].pos.x() && fabs(enemies[k].get_pos().y() - towers[i].getP().y()) <=40)
                    {
                        //如果有子弹越过了怪物怪物血量减一
                        enemies[k].blood = enemies[k].blood - towers[i].bullets[0].power;

                        //如果有子弹越过了怪物（一定是第一颗），删除第一颗
                        towers[i].bullets.removeFirst();
                        kill_bullet = true;
                     }
                        //怪物吃塔
                     if(enemies[k].get_pos().x()<=towers[i].getP().x()+100 && fabs(enemies[k].get_pos().y()-towers[i].getP().y())<=40)
                      {
                           enemies[k].blood = enemies[k].blood - tower_power;//如果怪物吃塔，怪物也要承受一次伤害
                           towers.removeAt(i);
                           cout<<"kill tower"<<endl;
                           kill_tower = true;

                      }

                        //如果血量减没，那么怪物消失
                        if(enemies[k].blood == 0)
                        {
                            killed_num ++;
                            cout<<"kill "<<killed_num<<endl;
                            enemies.removeAt(k);
                            kill_enemy = true;
                        }

                      if(kill_enemy==true )
                          k--;
                      if(kill_tower == true)
                          break;
                    }
                if(kill_tower == true)
                    break;
                if(kill_bullet==true)
                    j--;
            }
            if(kill_tower == true)
                i--;


    }
        //画出怪物
        for(int i=0;i<enemies.size();i++)
        {
            //将怪物坐标修改为当前值
            enemies[i].pos.setX(1000-enemies[i].times);//1000为怪物初始坐标
            //画出怪物
            painter.drawImage(enemies[i].get_pos(),enemies[i].get_pic());
            //cout<<i<<":"<<enemies[i].get_pos().x()<<endl;
            //如果有怪物越过了底线，就失败
            if(enemies[i].get_pos().x()<=200)
                over = true;
        }



       if(touch&&choose0){//实现拖动塔
          painter.drawImage(cur.x(),cur.y(),QImage(":/new/picture/pictures/tower1.jpg"));
        }

    }
           // cout<<enemies.size()<<endl;

}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(touch){
        cur.setX(event->x());
        cur.setY(event->y());
        //qDebug()<<cur.x();
    }

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if(x<=60&&x>=0&&y>=0&&y<=60)
    {

        touch=1;
        choose0=1;
    }//如果点到范围内，那么就是选中
    else{
        touch=0;
        choose0=0;
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
   // cout<<event->x()<<','<<event->y()<<endl;
    //规定炮塔只能放在格子中

    int x_true=0,y_true=0;
    for(int i=0;i<9;i++)
    {
        if(fabs(event->x()-235-100*i)<=8)
        {
            x_true = 1;
            break;
        }
        else
            continue;
    }
    for(int i=0;i<9;i++)
    {
        if(fabs(event->y()-10-101*i)<=8)
        {
            y_true = 1;
            break;
        }
        else
            continue;
    }

  //  cout<<"x_true is"<<x_true<<endl;
   // cout<<"y_true is"<<y_true<<endl;

    if(touch && event->x()>=229 && x_true==1 && y_true==1){
        if(choose0){

            QPoint a1(cur.x(),cur.y());

            Tower _tower(a1);
            towers.push_back(_tower);

            settled = 1;

        }
        //qDebug()<<cur.x()<<cur.y();
    }

    touch=0;
    choose0 = 0;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    int id=e->timerId();
    if(id==timeID)
    {
        open_new_window();
        open_new_defeat_window();
        repaint();
        for(int i=0;i<towers.size();i++)
        {
            for (int j =0;j<towers[i].bullets.size();j++)
            {
                towers[i].bullets[j].times++;//用于记录每个子弹射出后走的时间,可以控制子弹的飞行
            }

            towers[i].cooling_time = towers[i].cooling_time - _CT;

            //一旦冷却结束，增加一个子弹

            if(towers[i].cooling_time ==0)
            {

                QPoint pos_b(towers[i].getP().x()+HARF_LENTH,towers[i].getP().y()+20);
                Bullet b(pos_b);
                towers[i].bullets<<b;
                towers[i].cooling_time = COOL_TIME;//冷却重置
            }
        }

        //用于记录每个怪物出发后走的时间

        for(int i=0;i<enemies.size();i++)
        {
                enemies[i].times++;
        }

        //用于判断游戏是否结束
        if(printed_num == target_num)
            stop_print_enemy = true;
        if(killed_num == target_num)
        {

            over =true;
            win = true;
        }
    }

    if(id==timeID2 && printed_num<=target_num/2 && stop_print_enemy==false)
    {

            //产生一个随机整数，用于怪物随机生成在某一行
           int ran_num;
           srand((unsigned)time(0));
           ran_num = rand()%5;
           //cout<<ran_num<<endl;
           QPoint pos_e(1000,back_y[ran_num]);
           enemy _enemy(pos_e);
           enemies.push_back(_enemy);//每到时间在随机行产生一个怪物
           printed_num++;
           cout<<"print "<<printed_num<<endl;
      }

    if(id==timeID3 && printed_num>target_num/2 &&stop_print_enemy==false)//随着游戏进行难度加大（怪物出现间隔时间减少）
    {

            //产生一个随机整数，用于怪物随机生成在某一行
           int ran_num;
           srand((unsigned)time(0));
           ran_num = rand()%5;
           //cout<<ran_num<<endl;
           QPoint pos_e(1000,back_y[ran_num]);
           enemy _enemy(pos_e);
           enemies.push_back(_enemy);//每到时间在随机行产生一个怪物
           printed_num++;
           cout<<"print "<<printed_num<<endl;

    }
}

void MainWindow::open_new_window()
{

    if(over==true && win==true && newWindow_painted == false)
    {
        new_window *w =new new_window();
        w->show();
        newWindow_painted = true;
    }
}

void MainWindow::open_new_defeat_window()
{

    if( over==true && win==false&& newWindow_painted == false)
    {
        new_window_defeat *w =new new_window_defeat();
        w->show();
        newWindow_painted = true;
    }
}
