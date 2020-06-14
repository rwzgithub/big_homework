#include "new_window.h"
#include "ui_new_window.h"

new_window::new_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_window)
{
    ui->setupUi(this);
}

new_window::~new_window()
{
    delete ui;
}

void new_window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/picture/pictures/victory.jpg"));
}
