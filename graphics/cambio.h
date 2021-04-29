#ifndef CAMBIO_H
#define CAMBIO_H

#include <QDialog>
#include "src/entrenador.h"

namespace Ui {
class cambio;
}

class cambio : public QDialog
{
    Q_OBJECT

public:
    explicit cambio(QWidget *parent = nullptr, Entrenador* = nullptr);
    ~cambio();

private:
    Ui::cambio *ui;
    Entrenador* user;
};

#endif // CAMBIO_H
