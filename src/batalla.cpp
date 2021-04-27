#include "batalla.h"
#include "ui_batalla.h"
#include "atacar.h"
#include "cambio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pers.h"
#include "personaje.h"
#include "QMessageBox"
#include "stdio.h"
#include "stdlib.h"
#include "mapa.h"

Batalla::Batalla(QWidget *parent,QString name,bool genre) :
    QMainWindow(parent),
    ui(new Ui::Batalla)
{
    ui->setupUi(this);
    sgenre=genre;
    sname=name;
    if (sgenre)
    {
       ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/fbatalla.png);");

    }
    else
    {
        ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/mbatalla.png);");
    }
    ui->texto->setText("   Ahora te voy a explicar como funcionan las batallas pokemon.\n"
"   Estas batallas van por turnos, durante tu turno puedes:\n   atacar una vez,"
"usar objetos, cambiar tu pokémon.\n   Si haces un cambio, ¡pierdes el turno!");
}

Batalla::~Batalla()
{
    delete ui;
}

void Batalla:: get_name()
{

}
void Batalla:: get_genre()
{

}

void Batalla::on_next_clicked()
{
        QMessageBox::information(this,tr("Misión"),tr("Derrota a los cuatro maestros de la ciudad.\n"
    "¡Buena suerte!"));

        //Ver el mapa
        hide();
        Mapa *v_mapa=new Mapa(this,sgenre,sname);
        v_mapa->show();


}

