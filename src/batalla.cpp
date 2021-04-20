#include "batalla.h"
#include "ui_batalla.h"
#include "atacar.h"
#include "mochila.h"
#include "cambio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pers.h"
#include "personaje.h"
#include "QMessageBox"
#include "stdio.h"
#include "stdlib.h"

Batalla::Batalla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Batalla)
{
    ui->setupUi(this);
    if (1)
    {

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
   parentWidget();
}
void Batalla:: get_genre()
{
    parentWidget();
}

void Batalla::on_next_clicked()
{
        QMessageBox::information(this,tr("Misión"),tr("Derrota a los cuatro maestros de la ciudad.\n"
    "¡Buena suerte!"));

        //Comienza Batalla

        ui->texto->hide();
        ui->recuadro->hide();
        ui->next->hide();
        ui->profesor->hide();
        ui->avatar->hide();

}

void Batalla::batalla()
{

}
