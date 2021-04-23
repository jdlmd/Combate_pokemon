#ifndef BATTLE_H
#define BATTLE_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QString>
#include <QFile>

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
        QLabel* vsAnimation();
        void battleStartAnimation(QLabel* fondo);
};

#endif // BATTLE_H
