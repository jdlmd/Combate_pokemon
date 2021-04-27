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

    QStringList list1={"N1","N2","N3","N4"};
    QVector<QString> pokNerea= QVector<QString>::fromList(list1);

    QStringList list2={"J1","J2","J3","J4"};
    QVector<QString> pokJesus= QVector<QString>::fromList(list2);

    QStringList list3={"C1","C2","C3","C4"};
    QVector<QString> pokChus= QVector<QString>::fromList(list3);

    QStringList list4={"M1","M2","M3","M4"};
    QVector<QString> pokMaria= QVector<QString>::fromList(list4);

    QStringList list5={"A1","A2","A3","A4"};
    QVector<QString> pokAvatar= QVector<QString>::fromList(list5);

        explicit Battle(QWidget *parent = nullptr,int numbat=1,bool genre=0,QString nombre="");
        ~Battle();

    private slots:
        void launchAnimation();

        void on_atacar_clicked();

        void on_cambio_clicked();

private:
        int ancho;
        int alto;
        Ui::Battle *ui;
        QLabel* vsAnimation();
        void battleStartAnimation(QLabel* fondo);
        void closeEvent(QCloseEvent *event) override;
};

#endif // BATTLE_H
