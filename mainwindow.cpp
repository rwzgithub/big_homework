#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>
#include "tower.h"
#include <QtMath>
#include <iostream>
#define PI 3.1415926
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timeID=startTimer(20);//每20毫秒调用一次
    timeID2=startTimer(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(rect(),QPixmap(":/new/picture/pictures/backg.jpg"));
    painter.drawPixmap(0,0,QPixmap(":/new/picture/pictures/tower1.jpg"));


    for(int i=0;i<towers.size();i++){
      // QMatrix m;
       //m.rotate(t[i].getA());
       //t[i].rotate(m);//旋转失败
/*        painter.translate(t[i].getCP());
        painter.rotate(t[i].getA()%360);
        painter.translate(-t[i].getCP());*/
        cout<<towers.size();
        painter.drawImage(towers[i].getP(),towers[i].getPic());//画出所有村好的塔


      //  cout<<"xx is:"<<xx;
        for(int j=0;j<towers[i].bullets.size();j++)
        {
           painter.drawImage(towers[i].bullets[j].pos.x()+times[i]-49*j,towers[i].getP().y(),QImage(":/new/picture/pictures/bullet.png"));
        }



  /*    painter.drawImage(t[i].bt.start,QImage(":/new/picture/pictures/bullet.png"));
        painter.translate(t[i].getCP());
        painter.rotate(-t[i].getA()%360);
        painter.translate(-t[i].getCP());*/
    }

   if(touch&&choose0){//实现拖动塔
      painter.drawImage(cur.x(),cur.y(),QImage(":/new/picture/pictures/tower1.jpg"));
    }

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

    if(touch&&event->x()>=160){
        if(choose0){

            QPoint a(cur.x(),cur.y());
            Tower _tower(a);
            towers.push_back(_tower);
            settled = 1;
        }
        //qDebug()<<cur.x()<<cur.y();
    }
/*  else{
        touch=0;
        nowX=event->x();
        nowY=event->y();
        for(int i=0;i<t.size();i++){
            if(nowX>t[i].getP().x()){
                t[i].setA((180/PI)*qAtan((nowY-t[i].getP().y())/(nowX-t[i].getP().x())));
            }else{
                t[i].setA(53*qAtan((nowY-t[i].getP().y())/(nowX-t[i].getP().x()))+180);
            }
        }
    }*/

    touch=0;
    choose0 = 0;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    int id=e->timerId();
    if(id==timeID){
        repaint();
        for(int i=0;i<towers.size();i++)
        {
            times[i]++;
        }//实现给已经放置的炮塔发出子弹
    }

 /*  else if(id==timeID2){
        for(int i=0;i<t.size();i++)
        {
            if(t[i].count==0){
               t[i].bt.start=t[i].getP();
            }
            t[i].count++;
           if(t[i].count>=5)t[i].count=0;

        }
        repaint();
    }
*/
    if(id==timeID2)
    {
        if(towers.size()!=0)
        {
            int bx = towers[towers.size()-1].getP().x()+HARF_LENTH;
            int by = towers[towers.size()-1].getP().y();
            QPoint bp(bx,by);
            Bullet new_bullet(bp);
            towers[towers.size()-1].bullets.push_back(new_bullet);
        }

    }
}


