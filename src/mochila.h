#ifndef MOCHILA_H
#define MOCHILA_H

#include <QDialog>

namespace Ui {
class mochila;
}

class mochila : public QDialog
{
    Q_OBJECT

public:
    explicit mochila(QWidget *parent = nullptr);
    ~mochila();

private:
    Ui::mochila *ui;
};

#endif // MOCHILA_H
