#include "cambio.h"
#include "ui_cambio.h"
#include "src/definiciones.h"

cambio::cambio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cambio)
{
    ui->setupUi(this);
}

cambio::~cambio()
{
    delete ui;
}
