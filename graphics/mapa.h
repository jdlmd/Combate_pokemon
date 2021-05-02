#ifndef MAPA_H
#define MAPA_H

#include <QMainWindow>
#include "../src/entrenador.h"
#include "../src/definiciones.h"

namespace Ui {
class Mapa;
}

class Mapa : public QMainWindow
{
    Q_OBJECT

public:
    bool genre;
    int numbat;
    QString nombre;
    explicit Mapa(QWidget *parent = nullptr,bool genre=0,QString nombre=""); // Constructor
    ~Mapa();

private slots:

    void on_b1_clicked(); // Comprueba que el botón 1 se ha pulsado
    void on_b2_clicked(); // Comprueba que el botón 2 se ha pulsado
    void on_b3_clicked(); // Comprueba que el botón 3 se ha pulsado
    void on_b4_clicked(); // Comprueba que el botón 4 se ha pulsado

private:
    Ui::Mapa *ui;
    Entrenador* jesus;
    Entrenador* chus;
    Entrenador* maria;
    Entrenador* nerea;
    Entrenador* user;
    void closeEvent(QCloseEvent *event) override; // Cierra la ventana del mapa

};

#endif // MAPA_H
