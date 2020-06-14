#ifndef NEW_WINDOW_H
#define NEW_WINDOW_H

#include <QDialog>
#include <QPainter>


namespace Ui {
class new_window;
}

class new_window : public QDialog
{
    Q_OBJECT

public:
    explicit new_window(QWidget *parent = nullptr);
    ~new_window();
    void paintEvent(QPaintEvent *);//用于ui的绘制

private:
    Ui::new_window *ui;
};

#endif // NEW_WINDOW_H
