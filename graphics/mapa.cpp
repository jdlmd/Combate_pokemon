#include "mapa.h"
#include "ui_mapa.h"
#include "battle.h"

Mapa::Mapa(QWidget *parent, bool sgenre, QString snombre) :
    QMainWindow(parent),
    ui(new Ui::Mapa)
{
    ui->setupUi(this);
    genre=sgenre;
    nombre=snombre;

    std::string fullPath = SDL_GetBasePath();
    Genero _genre;

    std::ifstream f(fullPath+"./Combate_pokemon/audio/files/");
    if(f.good()){
        fullPath.append("./Combate_pokemon/audio/files/");
    }else
        fullPath.append("../Combate_pokemon/audio/files/");
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

Mapa::~Mapa() {
    delete ui;
}

void Mapa::on_b3_clicked() {
    hide();
    numbat=3;
    Battle *v_battle=new Battle(this,maria,user,genre,nombre);
    v_battle->show();
}

void Mapa::on_b2_clicked() {
    hide();
    numbat=2;
    Battle *v_battle=new Battle(this,jesus,user,genre,nombre);
    v_battle->show();
}

void Mapa::on_b1_clicked() {
    hide();
    numbat=1;
    Battle *v_battle=new Battle(this,nerea,user,genre,nombre);
    v_battle->show();
}

void Mapa::on_b4_clicked() {
    hide();
    numbat=4;
    Battle *v_battle=new Battle(this,chus,user,genre,nombre);
    v_battle->show();
}

void Mapa::closeEvent(QCloseEvent *event){
    delete jesus;
    delete chus;
    delete maria;
    delete nerea;
    QMainWindow::closeEvent(event);
}
