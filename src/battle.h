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
        explicit Battle(QWidget *parent = nullptr);
        ~Battle();

    private slots:
        void launchAnimation();

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
