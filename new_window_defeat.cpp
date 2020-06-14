#include "new_window_defeat.h"
#include "ui_new_window_defeat.h"

new_window_defeat::new_window_defeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_window_defeat)
{
    ui->setupUi(this);
}

new_window_defeat::~new_window_defeat()
{
    delete ui;
}

void new_window_defeat::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/picture/pictures/defeat.jpg"));
}
