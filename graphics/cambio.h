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
        explicit cambio(QWidget *parent = nullptr, Entrenador* _user = nullptr, Pokemon* poke = nullptr,bool _cambio_forzado=false);
    ~cambio();

    private slots:
        void on_btn1_clicked();
        void on_btn2_clicked();
        void on_btn3_clicked();
        void on_btn4_clicked();
        void on_btn5_clicked();
        void on_btn6_clicked();

    private:
        Ui::cambio *ui;
        Entrenador* user;
        bool cambio_forzado;

    signals:
        void selectedPoke(Pokemon* _poke,bool cambio_forzado);
};

#endif // CAMBIO_H
