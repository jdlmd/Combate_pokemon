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
    this->setFixedSize(this->size()); // Evita que se haga resize

    ui->attck1->hide();
    ui->attck2->hide();
    ui->attck3->hide();
    ui->attck4->hide();
    ui->inf1->hide();
    ui->inf2->hide();
    ui->inf3->hide();
    ui->inf4->hide();
    ui->pp1->hide();
    ui->pp2->hide();
    ui->pp3->hide();
    ui->pp4->hide();
    ui->pp11->hide();
    ui->pp22->hide();
    ui->pp33->hide();
    ui->pp44->hide();
    ui->mov->hide();
    ui->mov_2->hide();
    ui->mov_3->hide();
    ui->mov_4->hide();
    ui->a1->setEnabled(false);
    ui->a2->setEnabled(false);
    ui->a3->setEnabled(false);
    ui->a4->setEnabled(false);

    for (uint i = 0 ; i < n ; i++) {
        mov[i]=user_poke->getMove(i);
        if(i==0){
            ui->attck1->show();
            ui->inf1->show();
            ui->pp1->show();
            ui->pp11->show();
            ui->mov->show();
            ui->attck1->setText(QString::fromStdString(mov[0]->getName()));
            ui->inf1->setStyleSheet((stylesheet+QString::fromStdString(mov[0]->getType())+formato));
            ui->pp1->setText(QString::number(mov[0]->getPPtotal()));
            ui->pp11->setText(QString::number(mov[0]->getPPremaining()));
            if(mov[0]->getPPremaining()!=0)
                ui->a1->setEnabled(true);
        }else if (i==1){
            ui->attck2->show();
            ui->inf2->show();
            ui->pp2->show();
            ui->pp22->show();
            ui->mov_2->show();
            ui->attck2->setText(QString::fromStdString(mov[1]->getName()));
            ui->inf2->setStyleSheet((stylesheet+QString::fromStdString(mov[1]->getType())+formato));
            ui->pp2->setText(QString::number(mov[1]->getPPtotal()));
            ui->pp22->setText(QString::number(mov[1]->getPPremaining()));
            if(mov[1]->getPPremaining()!=0)
                ui->a2->setEnabled(true);
        }else if (i==2){
            ui->attck3->show();
            ui->inf3->show();
            ui->pp3->show();
            ui->pp33->show();
            ui->mov_3->show();
            ui->attck3->setText(QString::fromStdString(mov[2]->getName()));
            ui->inf3->setStyleSheet((stylesheet+QString::fromStdString(mov[2]->getType())+formato));
            ui->pp3->setText(QString::number(mov[2]->getPPtotal()));
            ui->pp33->setText(QString::number(mov[2]->getPPremaining()));
            if(mov[2]->getPPremaining()!=0)
                ui->a3->setEnabled(true);
        }else if (i==3){
            ui->attck4->show();
            ui->inf4->show();
            ui->pp4->show();
            ui->pp44->show();
            ui->mov_4->show();
            ui->attck4->setText(QString::fromStdString(mov[3]->getName()));
            ui->inf4->setStyleSheet((stylesheet+QString::fromStdString(mov[3]->getType())+formato));
            ui->pp4->setText(QString::number(mov[3]->getPPtotal()));
            ui->pp44->setText(QString::number(mov[3]->getPPremaining()));
            if(mov[3]->getPPremaining()!=0)
                ui->a4->setEnabled(true);
        }
    }
}

Atacar::~Atacar() {
    delete ui;
}

void Atacar::on_a1_clicked() {
    close();
    emit selectedMove(user_poke->getMove(0));
    delete this;
}

void Atacar::on_a2_clicked() {
    close();
    emit selectedMove(user_poke->getMove(1));
    delete this;
}

void Atacar::on_a3_clicked() {
    close();
    emit selectedMove(user_poke->getMove(2));
    delete this;
}

void Atacar::on_a4_clicked() {
    close();
    emit selectedMove(user_poke->getMove(3));
    delete this;
}
