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
#include <QFontDatabase>

/* Constructor */
Batalla::Batalla(QWidget *parent,QString name,bool genre) :
    QMainWindow(parent),
    ui(new Ui::Batalla)
{
    ui->setupUi(this);
    sgenre=genre;
    sname=name;
    QFontDatabase::addApplicationFont(":/files/Pokemon_Pinball_RS.ttf");
    QFont pokefont = QFont("Pokemon Pinball RS",8,1);
    if (sgenre)
    {
       ui->avatar->setStyleSheet("background:transparent;border-image: url(:/files/personajes/fbatalla.png);");

    }
    else
    {
        ui->avatar->setStyleSheet("background:transparent;border-image: url(:/files/personajes/mbatalla.png);");
    }
    ui->texto->setFont(pokefont);
    ui->texto->setText("   Ahora te voy a explicar como funcionan las batallas pokemon.\n"
"   Estas batallas van por turnos, durante tu turno puedes:\n   Atacar una vez,"
" o cambiar tu pokémon.\n   Si haces un cambio, ¡pierdes el turno!");
}

/* Destructor */
Batalla::~Batalla() {
    delete ui;
}

/* Cuando se pulsa el boton de siguiente */
void Batalla::on_next_clicked() {
        QMessageBox::information(this,tr("Misión"),tr("Derrota a los cuatro maestros de la región.\n"
    "¡Buena suerte!"));

        //Ver el mapa
        hide();
        Mapa *v_mapa=new Mapa(this,sgenre,sname);
        v_mapa->show();
}

