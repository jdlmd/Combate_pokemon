#include "atacar.h"
#include "ui_atacar.h"

atacar::atacar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::atacar)
{
    ui->setupUi(this);
}

atacar::~atacar()
{
    delete ui;
}
