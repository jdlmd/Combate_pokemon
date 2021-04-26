#include "mapa.h"
#include "ui_mapa.h"
#include "battle.h"

Mapa::Mapa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
}

Mapa::~Mapa()
{
    delete ui;
}

void Mapa::on_b3_clicked()
{
    hide();
    Battle *v_battle=new Battle(this);
    v_battle->show();
}

void Mapa::on_b2_clicked()
{
    hide();
    Battle *v_battle=new Battle(this);
    v_battle->show();
}

void Mapa::on_b1_clicked()
{
    hide();
    Battle *v_battle=new Battle(this);
    v_battle->show();
}

void Mapa::on_b4_clicked()
{
    hide();
    Battle *v_battle=new Battle(this);
    v_battle->show();
}
