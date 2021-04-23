#ifndef BATTLE_H
#define BATTLE_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QDebug>

namespace Ui {
    class Battle;
}

class Battle : public QMainWindow
{
        Q_OBJECT

    public:
        explicit Battle(QWidget *parent = nullptr);
        ~Battle();

    private slots:
        void launchAnimation();

    private:
        int posX;
        int posY;
        int ancho;
        int alto;
        Ui::Battle *ui;
        void vsAnimation();
};

#endif // BATTLE_H
