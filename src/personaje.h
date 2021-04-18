#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QMainWindow>

namespace Ui {
class Personaje;
}

class Personaje : public QMainWindow
{
    Q_OBJECT

public:
    explicit Personaje(QWidget *parent = nullptr);
    ~Personaje();

private:
    Ui::Personaje *ui;
};

#endif // PERSONAJE_H
