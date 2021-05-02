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
        explicit cambio(QWidget *parent = nullptr, Entrenador* _user = nullptr, Pokemon* poke = nullptr,bool _cambio_forzado=false);//Constructor
    ~cambio();

    private slots:
        void on_btn1_clicked(); // Comprueba si se pulsa el boton 1
        void on_btn2_clicked(); // Comprueba si se pulsa el boton 2
        void on_btn3_clicked(); // Comprueba si se pulsa el boton 3
        void on_btn4_clicked(); // Comprueba si se pulsa el boton 4
        void on_btn5_clicked(); // Comprueba si se pulsa el boton 5
        void on_btn6_clicked(); // Comprueba si se pulsa el boton 6

    private:
        Ui::cambio *ui;
        Entrenador* user;
        bool cambio_forzado; // Comprueba si tienes que hacer un cambio forzado porque han eliminado tu pokemon
        bool AbrilCerral; // Comprueba si puedes cerrar la interfaz de cambio de pokemon, ya que si tu pokemon ha muerto no puede cerrarse hasta que elijas otro
        void closeEvent(QCloseEvent *event) override; // Cierra la ventana

    signals:
        void selectedPoke(Pokemon* _poke,bool cambio_forzado); // Emite el Pokemon que has selecionado
};

#endif // CAMBIO_H
