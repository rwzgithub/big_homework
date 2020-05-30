#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QtDebug>
#include <QPainter>
#include <tower.h>
#include "bullet.h"

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


private:
    Ui::MainWindow *ui;
    bool touch;//是否触碰塔
    bool choose0;//是否选中塔
    QPoint cur;//current即当前鼠标坐标

    QList <Tower> towers;//炮塔的列表

    static const int HARF_LENTH = 25;
    static const int HEIGHT = 50;
    int timeID;
    int timeID2;
    int nowX;
    int nowY;
    bool settled;
    int times[100] = {0};//用于记录防止炮塔后的时间，可以用来在每次repaint时使子弹前进
};
#endif // MAINWINDOW_H
