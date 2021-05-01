#include "battle.h"
#include "ui_battle.h"
#include "atacar.h"
#include "cambio.h"
#include "QMessageBox"
#include <QFontDatabase>
Battle::Battle(QWidget *parent,Entrenador* _trainer,Entrenador* _user,bool sgenre, QString snombre) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);
    this->centralWidget()->hide();

    QFontDatabase::addApplicationFont(":/files/Pokemon_Pinball_RS.ttf");
    QFont pokefont = QFont("Pokemon Pinball RS",12,1);

    if (_trainer->getNombre() == "Nerea") {
        numbat = 1;
    } else if (_trainer->getNombre() == "Jesus") {
        numbat = 2;
    } else if (_trainer->getNombre() == "Maria") {
        numbat = 3;
    } else if (_trainer->getNombre() == "Chus") {
        numbat = 4;
    }

    user=_user;
    cpu=_trainer;
    user_poke = user->getPokemon(0);
    cpu_poke = cpu->getPokemon(0);

    genre=sgenre;
    nombre=snombre;
    ui->atacar->hide();
    ui->cambio->hide();
    ui->plat_sup->hide();
    ui->plat_inf->hide();
    ui->avatar->hide();
    ui->enemigo->hide();
    ui->pokemon_inf->hide();
    ui->pokemon_sup->hide();
    ui->hp_inf->hide();
    ui->vida_act->hide();
    ui->vida_total->hide();
    ui->vida_inf->hide();
    ui->vida_inf_fondo->hide();
    ui->level_inf->hide();
    ui->pok_inf->hide();
    ui->hp_sup->hide();
    ui->vida_sup->hide();
    ui->vida_sup_fondo->hide();
    ui->level_sup->hide();
    ui->pok_sup->hide();
    ui->cuadro_texto->setFont(pokefont);
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
    Izq->setStyleSheet("border-image: url(:/files/combate/blue.png);\nbackground: transparent;"); // Se les da el StyleSheet
    Der->setStyleSheet("border-image: url(:/files/combate/red.png);\nbackground: transparent;");

    switch (numbat) {

    case(1):
    {PjDer->setStyleSheet("border-image: url(:/files/personajes/Nerea.png);\nbackground: transparent;");
        break;}
    case(2):{
        PjDer->setStyleSheet("border-image: url(:/files/personajes/Jesus.png);\nbackground: transparent;");
        break;}
    case(3):
    {PjDer->setStyleSheet("border-image: url(:/files/personajes/Maria.png);\nbackground: transparent;");
    break;}
    case(4):
    {PjDer->setStyleSheet("border-image: url(:/files/personajes/chus.png);\nbackground: transparent;");
    break;}
    }

    if (genre)
    {
        PjIzq->setStyleSheet("background:transparent;border-image: url(:/files/personajes/f2.png);");
    }
    else{
        PjIzq->setStyleSheet("background:transparent;border-image: url(:/files/personajes/m.png);");
    }


    Poke->setStyleSheet("border-image: url(:/files/combate/pokeball_battle.png);\nbackground: transparent;");
    Vs->setStyleSheet("border-image: url(:/files/combate/vs.png);\nbackground: transparent;");

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
        ui->avatar->setStyleSheet("background:transparent;border-image: url(:/files/personajes/f2.png);");
    }
    else{
       ui->avatar->setStyleSheet("background:transparent;border-image: url(:/files/personajes/m.png);");
    }

    ui->plat_sup->setVisible(true);
    ui->plat_inf->setVisible(true);

    switch (numbat) {

    case(1):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b1.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/files/fondos/agua_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/files/fondos/agua_arriba.png);");
        break;}
    case(2):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b3.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/files/fondos/hierba_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/files/fondos/hierba_arriba.png);");
        break;}
    case(3):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b2.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/files/fondos/hierba_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/files/fondos/hierba_arriba.png);");
    break;}
    case(4):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b4.jpg);");
        ui->plat_inf->setStyleSheet("background: transparent;border-image: url(:/files/fondos/tierra_abajo.png);");
        ui->plat_sup->setStyleSheet("background: transparent;border-image: url(:/files/fondos/arena_arriba.png);");
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
        ui->enemigo->setStyleSheet("border-image: url(:/files/personajes/Nerea.png);\nbackground: transparent;");
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b1.jpg);");
        break;}
    case(2):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b3.jpg);");
        ui->enemigo->setStyleSheet("border-image: url(:/files/personajes/Jesus.png);\nbackground: transparent;");
        break;}
    case(3):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b2.jpg);");
        ui->enemigo->setStyleSheet("border-image: url(:/files/personajes/Maria.png);\nbackground: transparent;");
    break;}
    case(4):{
        ui->fondobat->setStyleSheet("background: transparent;border-image: url(:/files/fondos/b4.jpg);");
        ui->enemigo->setStyleSheet("border-image: url(:/files/personajes/chus.png);\nbackground: transparent;");
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
        break;
    }
    case(2):{
        ui->cuadro_texto->setText("¿Quién me molesta a estas horas?");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("Ah... solo eres tú.");
        this->repaint();
        QThread::msleep(2500);
        break;
    }
    case(3):{
        ui->cuadro_texto->setText("¿Quieres ganarme?");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("¡Veremos si puedes hacerlo!");
        this->repaint();
        QThread::msleep(2500);
        break;
    }
    case(4):{
        ui->cuadro_texto->setText("!SKEREEEEE¡");
        this->repaint();
        QThread::msleep(3000);
        ui->cuadro_texto->setText("Te voy a dejar como en Control");
        this->repaint();
        QThread::msleep(2500);
        break;
    }
    }

    QString stylesheet = "background: transparent;";
    QString path = ":/files/pokemon/";
    QString formato = ".png";

    QMessageBox::information(this,tr("Maestro %1").arg(QString::fromStdString(cpu->getNombre())),tr("¡El Maestro %1 saca a %2!").arg(QString::fromStdString(cpu->getNombre()),QString::fromStdString((cpu_poke->getName()))));
    ui->pokemon_sup->setPixmap(path + QString::fromStdString(cpu_poke->getName()).toLower()+formato);
    ui->pokemon_sup->setStyleSheet(stylesheet);
    ui->pokemon_sup->show();
    ui->enemigo->hide();
    this->repaint();
    ui->hp_sup->show();
    ui->vida_sup->show();
    ui->vida_sup_fondo->show();
    ui->level_sup->show();
    ui->pok_sup->show();
    QThread::msleep(500);
    QMessageBox::information(this,tr("Aprendiz %1").arg(QString::fromStdString(user->getNombre())),tr("¡Adelante %1!").arg(QString::fromStdString((user_poke->getName()))));
    ui->pokemon_inf->setPixmap(path + QString::fromStdString(user_poke->getName()).toLower()+"2"+formato);
    ui->pokemon_inf->setStyleSheet(stylesheet);
    ui->pokemon_inf->show();
    ui->avatar->hide();
    this->repaint();
    ui->hp_inf->show();
    ui->vida_act->show();
    ui->vida_total->show();
    ui->vida_inf->show();
    ui->vida_inf_fondo->show();
    ui->level_inf->show();
    ui->pok_inf->show();
    QThread::msleep(500);
    ui->cuadro_texto->setText("Haz tu movimiento.");
    this->repaint();
    this->repaint();
}

// Método para manejar el cierre de la ventana de forma correcta
void Battle::closeEvent(QCloseEvent *event) {
    audio.killAudio(); // Libera el audio
    parentWidget()->show();
    QMainWindow::closeEvent(event); // Se cierra la ventana
}

void Battle::on_atacar_clicked()
{
//    audio.launchSound("attack.wav");
    Atacar *v_ataque=new Atacar(this,user_poke,cpu_poke);
    v_ataque->show();
    connect(v_ataque,SIGNAL(selectedMove(Movimientos*)),this,SLOT(setMove(Movimientos*)));
}

void Battle::on_cambio_clicked() {
    cambio *v_cambio=new cambio(this,user,user_poke);
    v_cambio->show();
    connect(v_cambio,SIGNAL(selectedPoke(Pokemon*)),this,SLOT(setPoke(Pokemon*)));
}

void Battle::setMove(Movimientos* _move){
//    QThread::msleep(100);
//    uint acertado=_move->getDamage(user_poke,cpu_poke);
//    if(acertado==0)
//        qDebug()<<"Ha fallao";
//    else if(acertado==1)
//        qDebug()<<"Ha acertado";
//    else if (acertado==2)
//        qDebug()<<"Ha acertado y ha metido estao";
//    QThread::msleep(500);
//    audio.launchSound("attack.wav");
    uint acertado;
    QThread::msleep(100);
    if(user_poke->getSpeed()>cpu_poke->getSpeed()){
        if (user_poke->getStatePtr()->getMov()){
            qDebug()<<"El mas rapido del oeste";
            acertado=_move->getDamage(user_poke,cpu_poke);
            if(cpu_poke->getHP()<=0){
                qDebug() << "Dejalo, ya esta muerto";
                cpu->updateStatus();
                if(cpu->checkStatus()){
                    qDebug() << "Le has ganado";
                }else{
                    changeCpuPoke();
                }
            }
        }else{
            qDebug()<<"No se ha movido por pringado";
            //Añadir cambio de texto
        }
        if (cpu_poke->getStatePtr()->getMov()){
            acertado=cpu_poke->getMove(rand()%4)->getDamage(cpu_poke,user_poke);
            if(user_poke->getHP()<=0){
                qDebug() << "Dejalo, ya se me mato el pollo de fuego";
            //Añadir funcion de cambio del personaje.
            }
        }else{
            qDebug()<<"No se ha movido por pringado";
            //Añadir cambio de texto
        }
        cpu_poke->getStatePtr()->resolveState(cpu_poke);
        if(cpu_poke->getHP()<=0){
            qDebug() << "Dejalo, ya esta muerto";
            cpu->updateStatus();
            if(cpu->checkStatus()){
                qDebug() << "Le has ganado";
            }else{
                changeCpuPoke();
            }
        }
        user_poke->getStatePtr()->resolveState(user_poke);
        if(user_poke->getHP()<=0){
            qDebug() << "Dejalo, ya se me mato el pollo de fuego";
            cambio *v_cambio=new cambio(this,user,user_poke);
            v_cambio->show();
            connect(v_cambio,SIGNAL(selectedPoke(Pokemon*)),this,SLOT(setPoke(Pokemon*)));
        }
    }else{
        qDebug()<<"El mas rapido del oeste es el pollo de agua";
        if (cpu_poke->getStatePtr()->getMov()){
            acertado=cpu_poke->getMove(rand()%4)->getDamage(cpu_poke,user_poke);
            if(user_poke->getHP()<=0){
                qDebug() << "Dejalo, ya se me mato el pollo de fuego";
                cambio *v_cambio=new cambio(this,user,user_poke);
                v_cambio->show();
                connect(v_cambio,SIGNAL(selectedPoke(Pokemon*)),this,SLOT(setPoke(Pokemon*)));
            }
        }else{
            qDebug()<<"No se ha movido por pringado";
            //Añadir cambio de texto
        }
        if (user_poke->getStatePtr()->getMov()){
            acertado=_move->getDamage(user_poke,cpu_poke);
            if(cpu_poke->getHP()<=0){
                qDebug() << "Dejalo, ya esta muerto";
                cpu->updateStatus();
                if(cpu->checkStatus()){
                    qDebug() << "Le has ganado";
                }else{
                    changeCpuPoke();
                }
            }
        }else{
            qDebug()<<"No se ha movido por pringado";
            //Añadir cambio de texto
        }
        cpu_poke->getStatePtr()->resolveState(cpu_poke);
        if(cpu_poke->getHP()<=0){
            qDebug() << "Dejalo, ya esta muerto";
            cpu->updateStatus();
            if(cpu->checkStatus()){
                qDebug() << "Le has ganado";
            }else{
                changeCpuPoke();
            }
        }
        user_poke->getStatePtr()->resolveState(user_poke);
        if(user_poke->getHP()<=0){
            qDebug() << "Dejalo, ya se me mato el pollo de fuego";
            cambio *v_cambio=new cambio(this,user,user_poke);
            v_cambio->show();
            connect(v_cambio,SIGNAL(selectedPoke(Pokemon*)),this,SLOT(setPoke(Pokemon*)));
        }
    }
    QThread::msleep(500);
}

// Animaciones de ataque para los pokemons inferiores
void Battle::attackAnimationInf(){
    audio.launchSound("attack.wav");
    for (int i = 0 ; i <= 15 ; i++){
        ui->pokemon_inf->setGeometry(40+(170/15)*i,360,381,321);
        QThread::msleep(25);
        this->repaint();
    }
    for (int i = 15 ; i >= 0 ; i--){
        ui->pokemon_inf->setGeometry(40+(170/15)*i,360,381,321);
        QThread::msleep(25);
        this->repaint();
    }
}

// Animaciones de ataque para los pokemons superiores
void Battle::attackAnimationSup(){
    audio.launchSound("attack.wav");
    for (int i = 0 ; i <= 15 ; i++){
        ui->pokemon_sup->setGeometry(610-(140/15)*i,60+(120/15)*i,321,321);
        QThread::msleep(25);
        this->repaint();
    }
    for (int i = 15 ; i >= 0 ; i--){
        ui->pokemon_sup->setGeometry(610-(140/15)*i,60+(120/15)*i,321,321);
        QThread::msleep(25);
        this->repaint();
    }
}

void Battle::setPoke(Pokemon* _poke) {
    user_poke = _poke;
    QThread::msleep(300);
    QString stylesheet = "background: transparent;";
    QString path = ":/files/pokemon/";
    QString formato = ".png";

    QMessageBox::information(this,tr("Aprendiz %1").arg(QString::fromStdString(user->getNombre())),tr("¡Adelante %1!").arg(QString::fromStdString((user_poke->getName()))));
    ui->pokemon_inf->setPixmap(path + QString::fromStdString(user_poke->getName()).toLower()+"2"+formato);
    ui->pokemon_inf->setStyleSheet(stylesheet);
    ui->pokemon_inf->show();
    ui->avatar->hide();
    this->repaint();
}

void Battle::changeCpuPoke(){
    cpu_poke = cpu->getPokemon();

    QThread::msleep(300);
    QString stylesheet = "background: transparent;";
    QString path = ":/files/pokemon/";
    QString formato = ".png";

    QMessageBox::information(this,tr("Maestro %1").arg(QString::fromStdString(cpu->getNombre())),tr("¡Adelante %1!").arg(QString::fromStdString((cpu_poke->getName()))));
    ui->pokemon_sup->setPixmap(path + QString::fromStdString(cpu_poke->getName()).toLower()+formato);
    ui->pokemon_sup->setStyleSheet(stylesheet);
    ui->pokemon_sup->show();
    ui->avatar->hide();
    this->repaint();

}
