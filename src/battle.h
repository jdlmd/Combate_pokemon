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

#include "audio/audio.h"
#include "iostream"

namespace Ui {
    class Battle;
}

class Battle : public QMainWindow {

        Q_OBJECT

    public:
    int numbat;
    int numpok=1;
    bool genre;
        explicit Battle(QWidget *parent = nullptr,int numbat=1,bool genre=0);
        ~Battle();

    private slots:
        void launchAnimation();

        void on_atacar_clicked();

        void on_cambio_clicked();

private:
        int ancho;
        int alto;
        Ui::Battle *ui;
        Audio audio;
        QLabel* vsAnimation();
        void battleStartAnimation(QLabel* fondo);
        void closeEvent(QCloseEvent *event) override;
};

#endif // BATTLE_H
