#include "atacar.h"
#include "ui_atacar.h"
#include "../src/movimientos.h"

Atacar::Atacar(QWidget *parent,Pokemon* pokemon) :
    QDialog(parent),
    ui(new Ui::Atacar)
{
    Movimientos* mov[4];
    for (int i = 0 ; i < 4 ; i++) {
        mov[i]=pokemon->getMove(i);

    }


    ui->setupUi(this);

    ui->a1->setText(QString::fromStdString(mov[0]->getName()));
    ui->a2->setText(QString::fromStdString(mov[1]->getName()));
    ui->a3->setText(QString::fromStdString(mov[2]->getName()));
    ui->a4->setText(QString::fromStdString(mov[3]->getName()));
    std::string stylesheet = "background: transparent; border-image: url(:/files/tipos/";
    std::string formato = ".png";
    ui->inf1->setStyleSheet((stylesheet+mov[0]->getType()+formato).c_str());
    ui->inf1->setStyleSheet((stylesheet+mov[1]->getType()+formato).c_str());
    ui->inf1->setStyleSheet((stylesheet+mov[2]->getType()+formato).c_str());
    ui->inf1->setStyleSheet((stylesheet+mov[3]->getType()+formato).c_str());
    ui->pp1->setText(QString::number(mov[0]->getPPtotal()));
    ui->pp2->setText(QString::number(mov[1]->getPPtotal()));
    ui->pp3->setText(QString::number(mov[3]->getPPtotal()));
    ui->pp4->setText(QString::number(mov[4]->getPPtotal()));

    ui->pp11->setText(QString::number(mov[0]->getPPtotal()));
    ui->pp22->setText(QString::number(mov[1]->getPPtotal()));
    ui->pp33->setText(QString::number(mov[3]->getPPtotal()));
    ui->pp44->setText(QString::number(mov[4]->getPPtotal()));


}

Atacar::~Atacar()
{
    delete ui;
}

void Atacar::on_a1_clicked()
{

}
