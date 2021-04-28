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
    explicit Atacar(QWidget *parent = nullptr,Pokemon* pokemon = nullptr);
    ~Atacar();

private slots:
    void on_a1_clicked();

private:
    Ui::Atacar *ui;
};

#endif // ATACAR_H