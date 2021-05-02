#include "mapa.h"
#include "ui_mapa.h"
#include "battle.h"
#include "QMessageBox"
#include <QCloseEvent>

/* Constructor */
Mapa::Mapa(QWidget *parent, bool sgenre, QString snombre) :
    QMainWindow(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
    this->setFixedSize(this->size()); // Evita que se haga resize
    genre=sgenre;
    nombre=snombre;

    std::string fullPath = SDL_GetBasePath();
    Genero _genre;

    std::ifstream f(fullPath+"./Combate_pokemon/entrenadores/Jesus.txt");
    if(f.good()){
        fullPath.append("./Combate_pokemon/entrenadores/");
    }else
        fullPath.append("../Combate_pokemon/");
    jesus = new Entrenador(fullPath + "Jesus.txt");
    chus = new Entrenador(fullPath + "Chus.txt");
    maria = new Entrenador(fullPath + "Maria.txt");
    nerea = new Entrenador(fullPath + "Nerea.txt");

    if (sgenre)
        _genre = FEMALE;
    else
        _genre = MALE;

    user = new Entrenador(snombre.toStdString(),_genre,fullPath + "user.txt");
}

/* Destructor */
Mapa::~Mapa() {
    delete ui;
}

/* Comprueba que el botón 1 se ha pulsado */
void Mapa::on_b1_clicked() {
    if(!nerea->checkStatus()){
        hide();
        numbat=1;
        Battle *v_battle=new Battle(this,nerea,user,genre,nombre);
        v_battle->show();
    }else{
        QMessageBox::information(this,"Abuson","Ya lo mataste wey");
    }
}

/* Comprueba que el botón 2 se ha pulsado */
void Mapa::on_b2_clicked() {
    if(!jesus->checkStatus()){
        hide();
        numbat=2;
        Battle *v_battle=new Battle(this,jesus,user,genre,nombre);
        v_battle->show();
    }else{
        QMessageBox::information(this,"Abuson","Ya lo mataste wey");
    }
}

/* Comprueba que el botón 3 se ha pulsado */
void Mapa::on_b3_clicked() {
    if(!maria->checkStatus()){
        hide();
        numbat=3;
        Battle *v_battle=new Battle(this,maria,user,genre,nombre);
        v_battle->show();
    }else{
        QMessageBox::information(this,"Abuson","Ya lo mataste wey");
    }
}

/* Comprueba que el botón 4 se ha pulsado */
void Mapa::on_b4_clicked() {
    if(!chus->checkStatus()){
        hide();
        numbat=4;
        Battle *v_battle=new Battle(this,chus,user,genre,nombre);

        v_battle->show();
    }else{
        QMessageBox::information(this,"Abuson","Ya lo mataste wey");
    }
}

/* Cierra la ventana del mapa */
void Mapa::closeEvent(QCloseEvent *event){
    delete jesus;
    delete chus;
    delete maria;
    delete nerea;
    parentWidget()->parentWidget()->show();
    event->accept();
    QMainWindow::closeEvent(event);
}

