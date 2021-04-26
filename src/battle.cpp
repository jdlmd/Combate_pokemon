#include "battle.h"
#include "ui_battle.h"

Battle::Battle(QWidget *parent, int snumbat,bool sgenre) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);
    this->centralWidget()->hide();
    numbat=snumbat;
    genre=sgenre;
    ui->atacar->hide();
    ui->cambio->hide();
    ui->plat_sup->hide();
    ui->plat_inf->hide();
    ui->avatar->hide();
    ui->enemigo->hide();
    // Se obtienen los tamaños de la ventana. (Si todo
    // va normal, debería estar en (0,0),1000x800)
    ancho = this->geometry().width();
    alto = this->geometry().height();

    this->setFixedSize(this->size()); // Evita que se haga resize

    QTimer::singleShot(100,this,SLOT(launchAnimation())); // Al contar 100 ms, lanza launchAnimation()
}


Battle::~Battle() {
    delete ui;
}


void Battle::launchAnimation() {
    QLabel* fondo = vsAnimation(); // Se lanza la animación del versus
    QThread::msleep(300);
    battleStartAnimation(fondo);
}


/*
Genera la animación de vs y devuelve un puntero al fondo en blanco superpuesto, para que pueda ser eliminado en la animación de fadeOut */

QLabel* Battle::vsAnimation() {

    audio.launchAudio("./Combate_pokemon/audio/files/theme.wav");

    QThread::msleep(200);
    // Variables de altura y posición para los elementos de la animación
    int width = 0.8*ancho/2;
    int height = (alto-ui->cuadro_texto->geometry().height())/3;
    int pY = (alto-ui->cuadro_texto->geometry().height())/2 - height/2;

    QLabel* font = new QLabel(this->centralWidget()); // Se genera un fondo negro
    font->setGeometry(0,0,ancho,alto);
    font->setStyleSheet("background-color: black;");
    font->lower();
    font->show();
    ui->fondobat->lower();

    this->centralWidget()->show();
    this->repaint(); 
    QThread::msleep(100);

    // Se generan los elementos de la animación
    QLabel* Izq = new QLabel(this->centralWidget()); // Se crean los objetos
    QLabel* Der = new QLabel(this->centralWidget());
    QLabel* PjIzq = new QLabel(this->centralWidget());
    QLabel* PjDer = new QLabel(this->centralWidget());
    QLabel* Poke = new QLabel(this->centralWidget());
    QLabel* Vs = new QLabel(this->centralWidget());
    QLabel* fondo = new QLabel(this->centralWidget());
    Izq->raise(); // Se colocan en la posición correcta
    Der->raise();
    PjIzq->raise();
    PjDer->raise();
    Poke->raise();
    Vs->raise();
    fondo->raise();
    Izq->show(); // Se muestran
    Der->show();
    PjIzq->show();
    PjDer->show();
    Poke->show();
    Vs->show();
    fondo->show();
    Izq->setStyleSheet("border-image: url(:/res/blue.png);\nbackground: transparent;"); // Se les da el StyleSheet
    Der->setStyleSheet("border-image: url(:/res/red.png);\nbackground: transparent;");

    switch (numbat) {

    case(1):
    {PjDer->setStyleSheet("border-image: url(:/res/Nerea.png);\nbackground: transparent;");
        break;}
    case(2):{
        PjDer->setStyleSheet("border-image: url(:/res/Jesus.png);\nbackground: transparent;");
        break;}
    case(3):
    {PjDer->setStyleSheet("border-image: url(:/res/Maria.png);\nbackground: transparent;");
    break;}
    case(4):
    {PjDer->setStyleSheet("border-image: url(:/res/chus.png);\nbackground: transparent;");
    break;}
    }

    if (genre)
    {
        PjIzq->setStyleSheet("background:transparent;border-image: url(:/combate/res/f2.png);");
    }
    else{
        PjIzq->setStyleSheet("background:transparent;border-image: url(:/combate/res/m.png);");
    }


    Poke->setStyleSheet("border-image: url(:/res/pokeball_battle.png);\nbackground: transparent;");
    Vs->setStyleSheet("border-image: url(:/res/vs.png);\nbackground: transparent;");

    // Se genera el movimiento
    for (int x = 0 ; x <= width ; x += 15 ) {
        Izq->setGeometry(x-width,pY,width,height);
        Der->setGeometry(ancho-x,pY,width,height);
        PjIzq->setGeometry(x-3*width/4,pY/2,width/2,height*2);
        PjDer->setGeometry(ancho+width/4-x,pY/2,width/2,height*2);
        Poke->setGeometry(ancho/2-1.8*x/4,pY-0.2*height/width*x,1.8*x/2,1.4*height/width*x);
        Vs->setGeometry(ancho/2-x/6,pY/5,x/3,0.6*height/width*x);

        QThread::msleep(15);
        this->repaint();
    }

    ui->cuadro_texto->setText("¡EL COMBATE ESTÁ A PUNTO DE COMENZAR!");
    this->repaint();
    QThread::msleep(3500);
    fondo->setGeometry(0,0,ancho,alto);

    // Se va aumentando la opacidad del fondo blanco
    for (int i = 0 ; i <= 15 ; i++){
        QString back = "background-color: rgba(255, 255, 255, ";
        fondo->setStyleSheet(back.append(QString::number(255/15*i)).append(");"));
        QThread::msleep(50);
        this->repaint();
    }

    delete font; // Se borran los elementos generados
    delete Izq;
    delete Der;
    delete PjIzq;
    delete PjDer;
    delete Vs;
    delete Poke;

    QThread::msleep(500);
    return fondo; // Se duelve la capa superior, para que pueda ser manejada por otras animaciones (fadeOut)

}

void Battle::battleStartAnimation(QLabel *fondo) {
    // Se va disminuyendo la opacidad del fondo blanco
    for (int i = 15 ; i >= 0 ; i--){
        QString back = "background-color: rgba(255, 255, 255, ";
        fondo->setStyleSheet(back.append(QString::number(255/15*i)).append(");"));
        QThread::msleep(50);
        this->repaint();
    }
    delete fondo; // Se borra el fondo

    ui->atacar->setVisible(true);
    ui->cambio->setVisible(true);
    ui->plat_sup->setVisible(true);
    ui->plat_inf->setVisible(true);
    ui->avatar->setVisible(true);
    ui->enemigo->setVisible(true);

    switch (numbat) {

    case(1):{

        if (genre)
        {
            ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/f2.png);");
        }
        else{
           ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/m.png);");
        }
        ui->enemigo->setStyleSheet("border-image: url(:/res/Nerea.png);\nbackground: transparent;");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/agua_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/agua_arriba.png);");
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b1.jpg);");
        break;}
    case(2):{

        if (genre)
        {
            ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/f2.png);");
        }
        else{
           ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/m.png);");
        }
        ui->enemigo->setStyleSheet("border-image: url(:/res/Jesus.png);\nbackground: transparent;");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_arriba.png);");
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b3.jpg);");
        break;}
    case(3):{
        if (genre)
        {
            ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/f2.png);");
        }
        else{
           ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/m.png);");
        }
        ui->enemigo->setStyleSheet("border-image: url(:/res/Maria.png);\nbackground: transparent;");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_arriba.png);");
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b2.jpg);");
    break;}
    case(4):{
        if (genre)
        {
            ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/f2.png);");
        }
        else{
           ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/m.png);");
        }
        ui->enemigo->setStyleSheet("border-image: url(:/res/chus.png);\nbackground: transparent;");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/tierra_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/arena_arriba.png);");
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b4.jpg);");
    break;}}

    ui->cuadro_texto->setText("¡EL COMBATE ESTÁ A PUNTO DE COMENZAR!");
    this->repaint();
    ui->cuadro_texto->setText("¡EL COMBATE ESTÁ A PUNTO DE COMENZAR!");
    QThread::msleep(15);
    this->repaint();
}

// Método para manejar el cierre de la ventana de forma correcta
void Battle::closeEvent(QCloseEvent *event) {
    audio.killAudio(); // Libera el audio
    parentWidget()->show();
    QMainWindow::closeEvent(event); // Se cierra la ventana
}
