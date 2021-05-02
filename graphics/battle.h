#ifndef BATTLE_H
#define BATTLE_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QString>
#include <QFile>
#include <QDir>
#include <QVector>
#include <QStringList>

#include "audio/extern.h"
#include "iostream"
#include "src/entrenador.h"

namespace Ui {
    class Battle;
}

class Battle : public QMainWindow {

        Q_OBJECT

    public:

        int numbat;
        int numpok=1;
        bool genre;
        QString nombre;
        QString pok;

    explicit Battle(QWidget *parent = nullptr,Entrenador* _trainer = nullptr,Entrenador* user = nullptr,bool genre=0,QString nombre="");
    ~Battle();

    private slots:
        void launchAnimation(); // Lanza la animación de entrada a un combate
        void on_atacar_clicked(); // Pulsa el boton de atacar y abre la ventana de los movimientos
        void on_cambio_clicked(); // Pulsa el boton de cambio y abre la ventana del equipo del usuario
        void setMove(Movimientos* _move); // Se ejecuta el movimiento escogido
        void setPoke(Pokemon* _poke, bool cambio_forzado); // Cambia el pokemon ya sea por decisión propia o por muerte del pokemon actual

    private:
        int ancho;
        int alto;
        Ui::Battle *ui;
        QLabel* vsAnimation();
        void attackAnimationInf(); // Animación de ataque del pokemon del usuario
        void attackAnimationSup(); // Animación de ataque del pokemon del rival
        void hpBarAnimation(int antes, Pokemon* pokemon); // Animación de la barra de vida
        void battleStartAnimation(QLabel* fondo); // Animación del comienzo de la batalla
        void closeEvent(QCloseEvent *event) override; // Cierra la ventana de batalla
        void changeCpuPoke(); // Cambia el pokemon del rival
        bool checkCpuPokeHp(); // Comprueba la vida del pokemon rival para ver si puede seguir luchando
        bool checkUserPokeHp(); // Comprueba la vida del pokemon del usuario para ver si puede seguir luchando
        bool UserAttack(Movimientos* _move); // Ataque del pokemon del usuario
        bool CpuAttack(); // Ataque aleatorio del rival
        void BattleText(uint acertado,Movimientos* _move,int vida_anterior, Pokemon* Atacante, Pokemon* Defensor); // Texto de la batalla
        void updateBars(); // Actualiza la información del pokemon
        void resolveStates(Pokemon* poke); // Resuelve el estado del pokemon afectado
        Entrenador* user; // Usuario
        Entrenador* cpu; // Rival
        Pokemon* user_poke; // Pokemon del usuario
        Pokemon* cpu_poke; // Pokemon del rival
        bool perdido = false; // Indica si el usuario ha perdido el combate
};

#endif // BATTLE_H
