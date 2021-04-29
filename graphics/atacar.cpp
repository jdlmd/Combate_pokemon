#include "atacar.h"
#include "ui_atacar.h"
#include "../src/movimientos.h"
#include "qdebug.h"

Atacar::Atacar(QWidget *parent,Pokemon* _user_poke,Pokemon* _cpu_poke) :
    QDialog(parent),
    ui(new Ui::Atacar)
{
    user_poke=_user_poke;
    cpu_poke=_cpu_poke;
    uint n=user_poke->getNumberMoves();
    if (n > 4)
        n = 4;
    Movimientos* mov[n];
    QString stylesheet = "background: transparent; border-image: url(:/files/tipos/";
    QString formato = ".png);";
    ui->setupUi(this);
    QString aux= QString::fromStdString(user_poke->getMove(0)->getType());
    qDebug() <<stylesheet+aux+formato;
    for (uint i = 0 ; i < n ; i++) {
        mov[i]=user_poke->getMove(i);
        if(i==0){
            ui->a1->setText(QString::fromStdString(mov[0]->getName()));
            ui->inf1->setStyleSheet((stylesheet+QString::fromStdString(mov[0]->getType())+formato));
            ui->pp1->setText(QString::number(mov[0]->getPPtotal()));
            ui->pp11->setText(QString::number(mov[0]->getPPtotal()));
        }else if (i==1){
            ui->a2->setText(QString::fromStdString(mov[1]->getName()));
            ui->inf2->setStyleSheet((stylesheet+QString::fromStdString(mov[1]->getType())+formato));
            ui->pp2->setText(QString::number(mov[1]->getPPtotal()));
            ui->pp22->setText(QString::number(mov[1]->getPPtotal()));
        }else if (i==2){
            ui->a3->setText(QString::fromStdString(mov[2]->getName()));
            ui->inf3->setStyleSheet((stylesheet+QString::fromStdString(mov[2]->getType())+formato));
            ui->pp3->setText(QString::number(mov[2]->getPPtotal()));
            ui->pp33->setText(QString::number(mov[2]->getPPtotal()));
        }else if (i==3){
            ui->a4->setText(QString::fromStdString(mov[3]->getName()));
            ui->inf4->setStyleSheet((stylesheet+QString::fromStdString(mov[3]->getType())+formato));
            ui->pp4->setText(QString::number(mov[3]->getPPtotal()));
            ui->pp44->setText(QString::number(mov[3]->getPPtotal()));
        }
    }
}

Atacar::~Atacar()
{
    delete ui;
}

void Atacar::on_a1_clicked()
{
    user_poke->getMove(0)->getDamage(user_poke,cpu_poke);
    std::cout<<"Calculo daños";
}
