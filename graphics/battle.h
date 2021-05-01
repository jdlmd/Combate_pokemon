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
        void launchAnimation();
        void on_atacar_clicked();
        void on_cambio_clicked();
        void setMove(Movimientos* _move);
        void setPoke(Pokemon* _poke, bool cambio_forzado);

    private:
        int ancho;
        int alto;
        Ui::Battle *ui;
        QLabel* vsAnimation();
        void attackAnimationInf();
        void attackAnimationSup();
        void hpBarAnimation(int antes, Pokemon* pokemon);
        void battleStartAnimation(QLabel* fondo);
        void closeEvent(QCloseEvent *event) override;
        void changeCpuPoke();
        bool checkCpuPokeHp();
        bool checkUserPokeHp();
        bool UserAttack(Movimientos* _move);
        bool CpuAttack();
        void BattleText(uint acertado,Movimientos* _move,int vida_anterior, Pokemon* Atacante, Pokemon* Defensor);        
        void updateBars();
        void resolveStates(Pokemon* poke);
        Entrenador* user;
        Entrenador* cpu;
        Pokemon* user_poke;
        Pokemon* cpu_poke;
};

#endif // BATTLE_H
