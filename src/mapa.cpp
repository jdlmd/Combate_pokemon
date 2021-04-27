#include "mapa.h"
#include "ui_mapa.h"
#include "battle.h"

Mapa::Mapa(QWidget *parent, bool sgenre, QString snombre) :
    QMainWindow(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
    genre=sgenre;
    nombre=snombre;
}

Mapa::~Mapa()
{
    delete ui;
}

void Mapa::on_b3_clicked()
{
    hide();
    numbat=3;
    Battle *v_battle=new Battle(this,numbat,genre,nombre);
    v_battle->show();
}

void Mapa::on_b2_clicked()
{
    hide();
    numbat=2;
    Battle *v_battle=new Battle(this,numbat,genre,nombre);
    v_battle->show();
}

void Mapa::on_b1_clicked()
{
    hide();
    numbat=1;
    Battle *v_battle=new Battle(this,numbat,genre,nombre);
    v_battle->show();
}

void Mapa::on_b4_clicked()
{
    hide();
    numbat=4;
    Battle *v_battle=new Battle(this,numbat,genre,nombre);
    v_battle->show();
}
