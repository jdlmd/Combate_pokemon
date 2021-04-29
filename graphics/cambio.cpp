#include "cambio.h"
#include "ui_cambio.h"
#include "src/definiciones.h"

cambio::cambio(QWidget *parent, Entrenador* _user) :
    QDialog(parent),
    ui(new Ui::cambio)
{
    ui->setupUi(this);
    user = _user;
    QString stylesheet = "background: transparent; border-image: url(:/files/estados/";
    QString stylesheet2 = "background: transparent; border-image: url(:/files/pokemon/";
    QString stylesheet3 = "background: transparent; border-image: url(:/files/combate/";
    QString formato = ".png);";
    uint n = user->getNumber();

    if (n > 6)
        n = 6;

    Pokemon* pok[n];

    ui->nombre1->hide();
    ui->nombre2->hide();
    ui->nombre3->hide();
    ui->nombre4->hide();
    ui->nombre5->hide();
    ui->nombre6->hide();
    ui->min1->hide();
    ui->min2->hide();
    ui->min3->hide();
    ui->min4->hide();
    ui->min5->hide();
    ui->min6->hide();
    ui->n1->hide();
    ui->n2->hide();
    ui->n3->hide();
    ui->n4->hide();
    ui->n5->hide();
    ui->n6->hide();
    ui->pok1->hide();
    ui->pok2->hide();
    ui->pok3->hide();
    ui->pok4->hide();
    ui->pok5->hide();
    ui->pok6->hide();
    ui->est1->hide();
    ui->est2->hide();
    ui->est3->hide();
    ui->est4->hide();
    ui->est5->hide();
    ui->est6->hide();
    ui->vida1->hide();
    ui->vida2->hide();
    ui->vida3->hide();
    ui->vida4->hide();
    ui->vida5->hide();
    ui->vida6->hide();
    ui->v1->hide();
    ui->v2->hide();
    ui->v3->hide();
    ui->v4->hide();
    ui->v5->hide();
    ui->v6->hide();
    ui->v11->hide();
    ui->v22->hide();
    ui->v33->hide();
    ui->v44->hide();
    ui->v55->hide();
    ui->v66->hide();

    for (uint i = 0 ; i < n ; i++) {
        pok[i] = user->getPokemon(i);
        if (i == 0) {
            ui->min1->show();
            ui->n1->show();
            ui->pok1->show();
            ui->est1->show();
            ui->vida1->show();
            ui->v1->show();
            ui->v11->show();
            ui->nombre1->show();
            ui->nombre1->setText(QString::fromStdString(pok[i]->getName()));
            ui->est1->setStyleSheet(stylesheet + QString::fromStdString(Estados::getNameByState(pok[i]->getState())) + formato);
            ui->v1->setText(QString::number(pok[i]->getHPtotal()));
            ui->v11->setText(QString::number(pok[i]->getHP()));
            ui->vida1->setGeometry(137,70,115*pok[i]->getHP()/pok[i]->getHPtotal(),31);
            ui->min1->setStyleSheet(stylesheet2 + QString::fromStdString(pok[i]->getName()).toLower() + formato);
            if (115*pok[i]->getHP()/pok[i]->getHPtotal() > 63) {
                ui->vida1->setStyleSheet(stylesheet3 + "verde" + formato);
            } else if (115*pok[i]->getHP()/pok[i]->getHPtotal() < 63 && 115*pok[i]->getHP()/pok[i]->getHPtotal() > 28) {
                ui->vida1->setStyleSheet(stylesheet3 + "amarillo" + formato);
            } else {
                ui->vida1->setStyleSheet(stylesheet3 + "verde" + formato);
            }
        } else if (i == 1) {
            ui->min2->show();
            ui->n2->show();
            ui->pok2->show();
            ui->est2->show();
            ui->vida2->show();
            ui->v2->show();
            ui->v22->show();
            ui->nombre2->show();
            ui->nombre2->setText(QString::fromStdString(pok[i]->getName()));
            ui->est2->setStyleSheet(stylesheet + QString::fromStdString(Estados::getNameByState(pok[i]->getState())) + formato);
            ui->v2->setText(QString::number(pok[i]->getHPtotal()));
            ui->v22->setText(QString::number(pok[i]->getHP()));
            ui->vida2->setGeometry(425,90,115*pok[i]->getHP()/pok[i]->getHPtotal(),31);
            ui->min2->setStyleSheet(stylesheet2 + QString::fromStdString(pok[i]->getName()).toLower() + formato);
            if (115*pok[i]->getHP()/pok[i]->getHPtotal() > 63) {
                ui->vida2->setStyleSheet(stylesheet3 + "verde" + formato);
            } else if (115*pok[i]->getHP()/pok[i]->getHPtotal() < 63 && 115*pok[i]->getHP()/pok[i]->getHPtotal() > 28) {
                ui->vida2->setStyleSheet(stylesheet3 + "amarillo" + formato);
            } else {
                ui->vida2->setStyleSheet(stylesheet3 + "verde" + formato);
            }
        } else if (i == 2) {
            ui->min3->show();
            ui->n3->show();
            ui->pok3->show();
            ui->est3->show();
            ui->vida3->show();
            ui->v3->show();
            ui->v33->show();
            ui->nombre3->show();
            ui->nombre3->setText(QString::fromStdString(pok[i]->getName()));
            ui->est3->setStyleSheet(stylesheet + QString::fromStdString(Estados::getNameByState(pok[i]->getState())) + formato);
            ui->v3->setText(QString::number(pok[i]->getHPtotal()));
            ui->v33->setText(QString::number(pok[i]->getHP()));
            ui->vida3->setGeometry(137,220,115*pok[i]->getHP()/pok[i]->getHPtotal(),31);
            ui->min3->setStyleSheet(stylesheet2 + QString::fromStdString(pok[i]->getName()).toLower() + formato);
            if (115*pok[i]->getHP()/pok[i]->getHPtotal() > 63) {
                ui->vida3->setStyleSheet(stylesheet3 + "verde" + formato);
            } else if (115*pok[i]->getHP()/pok[i]->getHPtotal() < 63 && 115*pok[i]->getHP()/pok[i]->getHPtotal() > 28) {
                ui->vida3->setStyleSheet(stylesheet3 + "amarillo" + formato);
            } else {
                ui->vida3->setStyleSheet(stylesheet3 + "verde" + formato);
            }
        } else if (i == 3) {
            ui->min4->show();
            ui->n4->show();
            ui->pok4->show();
            ui->est4->show();
            ui->vida4->show();
            ui->v4->show();
            ui->v44->show();
            ui->nombre4->show();
            ui->nombre4->setText(QString::fromStdString(pok[i]->getName()));
            ui->est4->setStyleSheet(stylesheet + QString::fromStdString(Estados::getNameByState(pok[i]->getState())) + formato);
            ui->v4->setText(QString::number(pok[i]->getHPtotal()));
            ui->v44->setText(QString::number(pok[i]->getHP()));
            ui->vida4->setGeometry(425,240,115*pok[i]->getHP()/pok[i]->getHPtotal(),31);
            ui->min4->setStyleSheet(stylesheet2 + QString::fromStdString(pok[i]->getName()).toLower() + formato);
            if (115*pok[i]->getHP()/pok[i]->getHPtotal() > 63) {
                ui->vida4->setStyleSheet(stylesheet3 + "verde" + formato);
            } else if (115*pok[i]->getHP()/pok[i]->getHPtotal() < 63 && 115*pok[i]->getHP()/pok[i]->getHPtotal() > 28) {
                ui->vida4->setStyleSheet(stylesheet3 + "amarillo" + formato);
            } else {
                ui->vida4->setStyleSheet(stylesheet3 + "verde" + formato);
            }
        } else if (i == 4) {
            ui->min5->show();
            ui->n5->show();
            ui->pok5->show();
            ui->est5->show();
            ui->vida5->show();
            ui->v5->show();
            ui->v55->show();
            ui->nombre5->show();
            ui->nombre5->setText(QString::fromStdString(pok[i]->getName()));
            ui->est5->setStyleSheet(stylesheet + QString::fromStdString(Estados::getNameByState(pok[i]->getState())) + formato);
            ui->v5->setText(QString::number(pok[i]->getHPtotal()));
            ui->v55->setText(QString::number(pok[i]->getHP()));
            ui->vida5->setGeometry(137,370,115*pok[i]->getHP()/pok[i]->getHPtotal(),31);
            ui->min5->setStyleSheet(stylesheet2 + QString::fromStdString(pok[i]->getName()).toLower() + formato);
            if (115*pok[i]->getHP()/pok[i]->getHPtotal() > 63) {
                ui->vida5->setStyleSheet(stylesheet3 + "verde" + formato);
            } else if (115*pok[i]->getHP()/pok[i]->getHPtotal() < 63 && 115*pok[i]->getHP()/pok[i]->getHPtotal() > 28) {
                ui->vida5->setStyleSheet(stylesheet3 + "amarillo" + formato);
            } else {
                ui->vida5->setStyleSheet(stylesheet3 + "verde" + formato);
            }
        } else if (i == 5) {
            ui->min6->show();
            ui->n6->show();
            ui->pok6->show();
            ui->est6->show();
            ui->vida6->show();
            ui->v6->show();
            ui->v66->show();
            ui->nombre6->show();
            ui->nombre6->setText(QString::fromStdString(pok[i]->getName()));
            ui->est6->setStyleSheet(stylesheet + QString::fromStdString(Estados::getNameByState(pok[i]->getState())) + formato);
            ui->v6->setText(QString::number(pok[i]->getHPtotal()));
            ui->v66->setText(QString::number(pok[i]->getHP()));
            ui->vida6->setGeometry(425,390,115*pok[i]->getHP()/pok[i]->getHPtotal(),31);
            ui->min6->setStyleSheet(stylesheet2 + QString::fromStdString(pok[i]->getName()).toLower() + formato);
            if (115*pok[i]->getHP()/pok[i]->getHPtotal() > 63) {
                ui->vida6->setStyleSheet(stylesheet3 + "verde" + formato);
            } else if (115*pok[i]->getHP()/pok[i]->getHPtotal() < 63 && 115*pok[i]->getHP()/pok[i]->getHPtotal() > 28) {
                ui->vida6->setStyleSheet(stylesheet3 + "amarillo" + formato);
            } else {
                ui->vida6->setStyleSheet(stylesheet3 + "verde" + formato);
            }
        }
    }
}

cambio::~cambio()
{
    delete ui;
}
