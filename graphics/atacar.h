#ifndef ATACAR_H
#define ATACAR_H

#include <QDialog>
#include "src/pokemon.h"

namespace Ui {
class Atacar;
}

class Atacar : public QDialog
{
    Q_OBJECT

public:
    int numpok;
    explicit Atacar(QWidget *parent = nullptr,Pokemon* _user_poke = nullptr,Pokemon* _cpu_poke = nullptr);
    ~Atacar();

private slots:
    void on_a1_clicked();

    void on_a2_clicked();

    void on_a3_clicked();

    void on_a4_clicked();

private:
    Ui::Atacar *ui;
    Pokemon* user_poke;
    Pokemon* cpu_poke;

signals:
    void selectedMove(Movimientos* _move);
};

#endif // ATACAR_H
