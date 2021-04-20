#ifndef PERS_H
#define PERS_H

#include <QMainWindow>

namespace Ui {
class pers;
}

class pers : public QMainWindow
{
    Q_OBJECT

public:
    explicit pers(QWidget *parent = nullptr);
    ~pers();

private slots:
    void on_siguiente_clicked();

private:
    Ui::pers *ui;
};

#endif // PERS_H
