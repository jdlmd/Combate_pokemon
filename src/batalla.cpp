#include "batalla.h"
#include "ui_batalla.h"
#include "atacar.h"
#include "mochila.h"
#include "cambio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Batalla::Batalla(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Batalla)
{
    ui->setupUi(this);
}

Batalla::~Batalla()
{
    delete ui;
}

void Batalla::on_atacar_clicked()
{
 atacar *v_atacar=new atacar(this);
 v_atacar->show();
}

void Batalla::on_mochila_clicked()
{
    mochila *v_mochila=new mochila(this);
    v_mochila->show();
}

void Batalla::on_cambio_clicked()
{
    cambio *v_cambio=new cambio(this);
    v_cambio->show();
}
