#include "inicio.h"
#include "ui_inicio.h"
#include "personaje.h"

Inicio::Inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
}

Inicio::~Inicio()
{
    delete ui;
}

void Inicio::on_pushButton_clicked()
{
    hide();
    Personaje *pj = new Personaje(this);
    pj->show();
}
