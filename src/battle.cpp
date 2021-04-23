#include "battle.h"
#include "ui_battle.h"

Battle::Battle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);

    // Se obtienen los tamaños y coordenadas de la ventana. (Si todo
    // va normal, debería estar en (0,0),1000x800)
    posX = this->geometry().x();
    posY = this->geometry().y();
    ancho = this->geometry().width();
    alto = this->geometry().height();

    this->setFixedSize(this->size()); // Evita que se haga resize

    QTimer::singleShot(100,this,SLOT(launchAnimation())); // Al contar 100 ms, lanza launchAnimation()

}

Battle::~Battle() {
    delete ui;
}

void Battle::launchAnimation() {
    vsAnimation(); // Se lanza la animación del versus
}

void Battle::vsAnimation() {
    QLabel* font = new QLabel(this);
    font->setGeometry(posX,posY,ancho,alto);
    font->setStyleSheet("background-color: black;");
    font->raise();
    font->show();
    this->repaint();
}
