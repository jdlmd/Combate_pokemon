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
    explicit Atacar(QWidget *parent = nullptr,Pokemon* _user_poke = nullptr,Pokemon* _cpu_poke = nullptr); // Constructor
    ~Atacar();

private slots:
    void on_a1_clicked(); // Comprueba si se pulsa el ataque 1
    void on_a2_clicked(); // Comprueba si se pulsa el ataque 2
    void on_a3_clicked(); // Comprueba si se pulsa el ataque 3
    void on_a4_clicked(); // Comprueba si se pulsa el ataque 4

private:
    Ui::Atacar *ui;
    Pokemon* user_poke; // Pokemon del usuario
    Pokemon* cpu_poke; // Pokemon del rival

signals:
    void selectedMove(Movimientos* _move);
};

#endif // ATACAR_H
