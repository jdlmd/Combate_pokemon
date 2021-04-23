#include "battle.h"
#include "ui_battle.h"

Battle::Battle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);
}

Battle::~Battle() {
    delete ui;
}
