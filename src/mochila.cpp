#include "mochila.h"
#include "ui_mochila.h"

mochila::mochila(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mochila)
{
    ui->setupUi(this);
}

mochila::~mochila()
{
    delete ui;
}
