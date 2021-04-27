#include "battle.h"
#include "ui_battle.h"
#include "atacar.h"
#include "cambio.h"
#include "QMessageBox"
Battle::Battle(QWidget *parent, int snumbat,bool sgenre, QString snombre) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);
    this->centralWidget()->hide();
    numbat=snumbat;
    genre=sgenre;
    nombre=snombre;
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

    //Pantalla batalla

    if (genre)
    {
        ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/f2.png);");
    }
    else{
       ui->avatar->setStyleSheet("background:transparent;border-image: url(:/combate/res/m.png);");
    }

    ui->plat_sup->setVisible(true);
    ui->plat_inf->setVisible(true);

    switch (numbat) {

    case(1):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b1.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/agua_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/agua_arriba.png);");
        break;}
    case(2):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b3.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_arriba.png);");
        break;}
    case(3):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b2.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/hierba_arriba.png);");
    break;}
    case(4):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b4.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/combate/res/tierra_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/combate/res/arena_arriba.png);");
    break;}}

    QThread::msleep(200);
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

    //Pantalla Batalla

    ui->atacar->setVisible(true);
    ui->cambio->setVisible(true);
    ui->avatar->setVisible(true);
    ui->enemigo->setVisible(true);

    switch (numbat) {

    case(1):{
        ui->enemigo->setStyleSheet("border-image: url(:/res/Nerea.png);\nbackground: transparent;");
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b1.jpg);");
        break;}
    case(2):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b3.jpg);");
        ui->enemigo->setStyleSheet("border-image: url(:/res/Jesus.png);\nbackground: transparent;");
        break;}
    case(3):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b2.jpg);");
        ui->enemigo->setStyleSheet("border-image: url(:/res/Maria.png);\nbackground: transparent;");
    break;}
    case(4):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/combate/res/b4.jpg);");
        ui->enemigo->setStyleSheet("border-image: url(:/res/chus.png);\nbackground: transparent;");
    break;}}

        //Dialogo

    switch (numbat) {
    case(1):{
        ui->cuadro_texto->setText("Parece que hoy tengo visita.");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("Vamos a ver que es lo que puedes hacer.");
        this->repaint();
        QThread::msleep(2500);
        pok=pokNerea[1];
        QMessageBox::information(this,tr("Maestra Nerea"),tr("¡La Maestra Nerea saca a %1!").arg(pok));
        ui->enemigo->setStyleSheet("background: transparent;border-image: url(:/pokNerea/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        pok=pokAvatar[1];
        QMessageBox::information(this,tr("Aprendiz %1").arg(nombre),tr("¡Adelante %1!").arg(pok));
        ui->avatar->setStyleSheet("background: transparent;border-image: url(:/pokAvatar/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        ui->cuadro_texto->setText("Haz tu movimiento.");
        this->repaint();
        break;
    }
    case(2):{
        ui->cuadro_texto->setText("¿Quién me molesta a estas horas?");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("Ah... solo eres tú.");
        this->repaint();
        QThread::msleep(2500);
        pok=pokJesus[1];
        QMessageBox::information(this,tr("Maestro Jesus"),tr("¡El Maestro Jesus saca a %1!").arg(pok));
        ui->enemigo->setStyleSheet("background: transparent;border-image: url(:/pokJesus/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        pok=pokAvatar[1];
        QMessageBox::information(this,tr("Aprendiz %1").arg(nombre),tr("¡Adelante %1!").arg(pok));
        ui->avatar->setStyleSheet("background: transparent;border-image: url(:/pokAvatar/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        ui->cuadro_texto->setText("Haz tu movimiento.");
        this->repaint();
        this->repaint();


        break;
    }
    case(3):{
        ui->cuadro_texto->setText("¿Quieres ganarme?");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("¡Veremos si puedes hacerlo!");
        this->repaint();
        QThread::msleep(2500);
        pok=pokMaria[1];
        QMessageBox::information(this,tr("Maestra Maria"),tr("¡La Maestra Maria saca a %1!").arg(pok));
        ui->enemigo->setStyleSheet("background: transparent;border-image: url(:/pokMaria/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        pok=pokAvatar[1];
        QMessageBox::information(this,tr("Aprendiz %1").arg(nombre),tr("¡Adelante %1!").arg(pok));
        ui->avatar->setStyleSheet("background: transparent;border-image: url(:/pokAvatar/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        ui->cuadro_texto->setText("Haz tu movimiento.");
        this->repaint();
        this->repaint();
        break;
    }
    case(4):{
        ui->cuadro_texto->setText("¿Por qué tanto alboroto?");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("¿Quieres un chicle""?");
        this->repaint();
        QThread::msleep(2500);
        pok=pokChus[1];
        QMessageBox::information(this,tr("Maestro Chus"),tr("¡El Maestro Chus saca a %1!").arg(pok));
        ui->enemigo->setStyleSheet("background: transparent;border-image: url(:/pokChus/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        pok=pokAvatar[1];
        QMessageBox::information(this,tr("Aprendiz %1").arg(nombre),tr("¡Adelante %1!").arg(pok));
        ui->avatar->setStyleSheet("background: transparent;border-image: url(:/pokAvatar/res/vs.png);");
        this->repaint();
        QThread::msleep(500);
        ui->cuadro_texto->setText("Haz tu movimiento.");
        this->repaint();
        this->repaint();
        break;
    }
    }

}

// Método para manejar el cierre de la ventana de forma correcta
void Battle::closeEvent(QCloseEvent *event) {
    audio.killAudio(); // Libera el audio
    parentWidget()->show();
    QMainWindow::closeEvent(event); // Se cierra la ventana
}

void Battle::on_atacar_clicked()
{
    Atacar *v_ataque=new Atacar(this,numpok);
    v_ataque->show();
}

void Battle::on_cambio_clicked()
{
    cambio *v_cambio=new cambio(this);
    v_cambio->show();
}
