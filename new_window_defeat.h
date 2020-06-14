#ifndef NEW_WINDOW_DEFEAT_H
#define NEW_WINDOW_DEFEAT_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class new_window_defeat;
}

class new_window_defeat : public QDialog
{
    Q_OBJECT

public:
    explicit new_window_defeat(QWidget *parent = nullptr);
    ~new_window_defeat();
    void paintEvent(QPaintEvent*);
private:
    Ui::new_window_defeat *ui;
};

#endif // NEW_WINDOW_DEFEAT_H
