#include "atacar.h"
#include "ui_atacar.h"

Atacar::Atacar(QWidget *parent, int snumpok) :
    QDialog(parent),
    ui(new Ui::Atacar)
{
    ui->setupUi(this);
    numpok=snumpok;
    switch (numpok) {
    case(1):{
        //Flareon
        ui->a1->setText("Lanzallamas");
        ui->a2->setText("Giro Fuego");
        ui->a3->setText("Furia");
        ui->a4->setText("Evite Ígneo");
        ui->inf1->setText("FUEGO");
        ui->inf2->setText("FUEGO");
        ui->inf3->setText("NORMAL");
        ui->inf4->setText("FUEGO");
        ui->pp1->setText("15");
        ui->pp2->setText("15");
        ui->pp3->setText("20");
        ui->pp4->setText("15");
        break;}
    case(2):{
        //
        ui->a1->setText("Lanzallamas2");
        ui->a2->setText("Giro Fuego2");
        ui->a3->setText("Furia2");
        ui->a4->setText("Evite Ígneo2");
        ui->inf1->setText("FUEGO");
        ui->inf2->setText("FUEGO");
        ui->inf3->setText("NORMAL");
        ui->inf4->setText("FUEGO");
        ui->pp1->setText("15");
        ui->pp2->setText("15");
        ui->pp3->setText("20");
        ui->pp4->setText("15");
        break;}
    case(3):{
        ui->a1->setText("Lanzallamas3");
        ui->a2->setText("Giro Fuego3");
        ui->a3->setText("Furia3");
        ui->a4->setText("Evite Ígneo3");
        ui->inf1->setText("FUEGO");
        ui->inf2->setText("FUEGO");
        ui->inf3->setText("NORMAL");
        ui->inf4->setText("FUEGO");
        ui->pp1->setText("15");
        ui->pp2->setText("15");
        ui->pp3->setText("20");
        ui->pp4->setText("15");
        break;}
    case(4):{
        ui->a1->setText("Lanzallamas4");
        ui->a2->setText("Giro Fuego4");
        ui->a3->setText("Furia4");
        ui->a4->setText("Evite Ígneo4");
        ui->inf1->setText("FUEGO");
        ui->inf2->setText("FUEGO");
        ui->inf3->setText("NORMAL");
        ui->inf4->setText("FUEGO");
        ui->pp1->setText("15");
        ui->pp2->setText("15");
        ui->pp3->setText("20");
        ui->pp4->setText("15");
        break;}
    }

}

Atacar::~Atacar()
{
    delete ui;
}
