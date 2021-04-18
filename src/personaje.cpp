#include "personaje.h"
#include "ui_personaje.h"

Personaje::Personaje(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Personaje)
{
    ui->setupUi(this);
}

Personaje::~Personaje()
{
    delete ui;
}
