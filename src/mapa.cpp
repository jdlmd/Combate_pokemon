#include "mapa.h"
#include "ui_mapa.h"
#include "battle.h"

Mapa::Mapa(QWidget *parent, bool sgenre) :
    QMainWindow(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
    genre=sgenre;
}

Mapa::~Mapa()
{
    delete ui;
}

void Mapa::on_b3_clicked()
{
    hide();
    numbat=3;
    Battle *v_battle=new Battle(this,numbat,genre);
    v_battle->show();
}

void Mapa::on_b2_clicked()
{
    hide();
    numbat=2;
    Battle *v_battle=new Battle(this,numbat,genre);
    v_battle->show();
}

void Mapa::on_b1_clicked()
{
    hide();
    numbat=1;
    Battle *v_battle=new Battle(this,numbat,genre);
    v_battle->show();
}

void Mapa::on_b4_clicked()
{
    hide();
    numbat=4;
    Battle *v_battle=new Battle(this,numbat,genre);
    v_battle->show();
}
