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
    explicit Mapa(QWidget *parent = nullptr,bool genre=0,QString nombre="");
    ~Mapa();

private slots:
    void on_b3_clicked();
    void on_b2_clicked();
    void on_b1_clicked();
    void on_b4_clicked();

private:
    Ui::Mapa *ui;
    Entrenador* jesus;
    Entrenador* chus;
    Entrenador* maria;
    Entrenador* nerea;
    Entrenador* user;
    void closeEvent(QCloseEvent *event) override;

};

#endif // MAPA_H
