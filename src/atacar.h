#ifndef ATACAR_H
#define ATACAR_H

#include <QDialog>

namespace Ui {
class Atacar;
}

class Atacar : public QDialog
{
    Q_OBJECT

public:
    int numpok;
    explicit Atacar(QWidget *parent = nullptr,int numpok=1);
    ~Atacar();

private:
    Ui::Atacar *ui;
};

#endif // ATACAR_H
