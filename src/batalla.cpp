#include "batalla.h"
#include "ui_batalla.h"

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

}

void Batalla::on_mochila_clicked()
{

}

void Batalla::on_cambio_clicked()
{

}
