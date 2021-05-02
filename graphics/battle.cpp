#include "battle.h"
#include "ui_battle.h"
#include "atacar.h"
#include "cambio.h"
#include "QMessageBox"
#include <QFontDatabase>
#include <QCloseEvent>

/* Constructor */
Battle::Battle(QWidget *parent,Entrenador* _trainer,Entrenador* _user,bool sgenre, QString snombre) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);
    this->centralWidget()->hide();

    // Cambia la letra
    QFontDatabase::addApplicationFont(":/files/Pokemon_Pinball_RS.ttf");
    QFont pokefont = QFont("Pokemon Pinball RS",12,1);
    QFont pokefont2 = QFont("Pokemon Pinball RS",10,1);

    // Según el rival lanza una canción diferente de combate
    if (_trainer->getNombre() == "Nerea") {
        numbat = 1;
        audio.killAudio();
        audio.launchAudio("nerea.wav");
    } else if (_trainer->getNombre() == "Jesus") {
        numbat = 2;
        audio.killAudio();
        audio.launchAudio("jesus.wav");
    } else if (_trainer->getNombre() == "Maria") {
        numbat = 3;
        audio.killAudio();
        audio.launchAudio("maria.wav");
    } else if (_trainer->getNombre() == "Chus") {
        numbat = 4;
        audio.killAudio();
        audio.launchAudio("chus.wav");
    }

    // Inicializa las variables
    user=_user;
    cpu=_trainer;
    user_poke = user->getPokemon();
    cpu_poke = cpu->getPokemon();

    // Oculta la interfaz de batalla
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
    ui->state_inf->hide();
    ui->hp_sup->hide();
    ui->vida_sup->hide();
    ui->vida_sup_fondo->hide();
    ui->level_sup->hide();
    ui->pok_sup->hide();
    ui->state_sup->hide();
    ui->cuadro_texto->setFont(pokefont);
    ui->level_inf->setFont(pokefont2);
    ui->level_sup->setFont(pokefont2);
    ui->vida_act->setFont(pokefont2);
    ui->vida_total->setFont(pokefont2);
    ui->pok_inf->setFont(pokefont2);
    ui->pok_sup->setFont(pokefont2);
    // Se obtienen los tamaños de la ventana. (Si todo
    // va normal, debería estar en (0,0),1000x800)
    ancho = this->geometry().width();
    alto = this->geometry().height();

    this->setFixedSize(this->size()); // Evita que se haga resize

    QTimer::singleShot(100,this,SLOT(launchAnimation())); // Al contar 100 ms, lanza launchAnimation()
}

/* Destructor */
Battle::~Battle() {
    delete ui;
}

/* Se lanza la animación del versus */
void Battle::launchAnimation() {
    QLabel* fondo = vsAnimation();
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

/* Animación del comienzo de la batalla */
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

        //Dialogo en función del rival

    switch (numbat) {
        case(1):
            ui->cuadro_texto->setText("Parece que hoy tengo visita");
            this->repaint();
            QThread::msleep(3000);
            ui->cuadro_texto->setText("Veamos qué puedes hacer");
            this->repaint();
            QThread::msleep(2500);
            break;

        case(2):
            ui->cuadro_texto->setText("¡BARA BARA!");
            this->repaint();
            QThread::msleep(3000);
            ui->cuadro_texto->setText("¿Tienes un pollo de fuego, o de agua?");
            this->repaint();
            QThread::msleep(2500);
            break;

        case(3):
            ui->cuadro_texto->setText("¿Pretendes ganarme?");
            this->repaint();
            QThread::msleep(3000);
            ui->cuadro_texto->setText("¡Aún estás a años luz para eso!");
            this->repaint();
            QThread::msleep(2500);
            break;

        case(4):
            ui->cuadro_texto->setText("¡SKEREEEEE!");
            this->repaint();
            QThread::msleep(3000);
            ui->cuadro_texto->setText("Te voy a dejar como en Control");
            this->repaint();
            QThread::msleep(2500);
            break;

        default:
            this->repaint();
            QThread::msleep(2000);
            break;
    }

    QString stylesheet = "background: transparent;";
    QString path = ":/files/pokemon/";
    QString formato = ".png";

    // Aparecen los pokemons y desaparecen los entrenadores
    QMessageBox::information(this,tr("Maestro %1").arg(QString::fromStdString(cpu->getNombre())),tr("¡El Maestro %1 saca a %2!").arg(QString::fromStdString(cpu->getNombre()),QString::fromStdString((cpu_poke->getName()))));
    ui->pokemon_sup->setPixmap(path + QString::fromStdString(cpu_poke->getName()).toLower()+formato);
    ui->pokemon_sup->setStyleSheet(stylesheet);
    ui->pokemon_sup->show();
    ui->enemigo->hide();
    this->repaint();
    updateBars();
    ui->hp_sup->show();
    ui->vida_sup->show();
    ui->vida_sup_fondo->show();
    ui->level_sup->show();
    ui->pok_sup->show();
    ui->state_sup->show();
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
    ui->state_inf->show();
    QThread::msleep(500);
    ui->cuadro_texto->setText("Haz tu movimiento.");
    this->repaint();
    this->repaint();
}

// Método para manejar el cierre de la ventana de forma correcta
void Battle::closeEvent(QCloseEvent *event) {
    audio.killAudio(); // Libera el audio
    audio.launchAudio("theme.wav");
     // Se cierra la ventana
    if (perdido){
        QMessageBox::information(this->parentWidget()->parentWidget(),"Game Over","Perdiste");
        parentWidget()->parentWidget()->parentWidget()->show();
        parentWidget()->close();
        parentWidget()->parentWidget()->close();
    }
    else
        parentWidget()->show();
    QThread::msleep(50);
    event->accept();
    // Emitir señal para cerrar el mapa
}

/* Pulsa el boton de atacar y abre la ventana de los movimientos */
void Battle::on_atacar_clicked()
{
//    audio.launchSound("attack.wav");
    Atacar *v_ataque=new Atacar(this,user_poke,cpu_poke);
    v_ataque->show();
    connect(v_ataque,SIGNAL(selectedMove(Movimientos*)),this,SLOT(setMove(Movimientos*)));
}

/* Pulsa el boton de cambio y abre la ventana del equipo del usuario */
void Battle::on_cambio_clicked() {
    cambio *v_cambio=new cambio(this,user,user_poke,false);
    v_cambio->show();
    connect(v_cambio,SIGNAL(selectedPoke(Pokemon*,bool)),this,SLOT(setPoke(Pokemon*,bool)));
}

/* Se ejecuta el movimiento escogido */
void Battle::setMove(Movimientos* _move){
//    QThread::msleep(100);
    bool cpuAlive=true;
    bool userAlive=true;
    if(user_poke->getSpeed()>cpu_poke->getSpeed()){
        cpuAlive = UserAttack(_move);
        QThread::msleep(1000);
        if(cpuAlive)
            userAlive = CpuAttack();

        if(cpuAlive){
            resolveStates(cpu_poke);
        }

        if(userAlive){
            resolveStates(user_poke);
        }
    }else{
        userAlive = CpuAttack();
        QThread::msleep(1000);
        if(userAlive)
            cpuAlive = UserAttack(_move);

        if(cpuAlive){
            resolveStates(cpu_poke);
        }

        if(userAlive){
            resolveStates(user_poke);
        }
    }
    QThread::msleep(500);
    ui->cuadro_texto->setText("Haz tu movimiento.");
    this->repaint();
    if (perdido)
        close();
}

/* Animaciones de ataque para los pokemons inferiores */
void Battle::attackAnimationInf(){
    audio.launchSound("attack.wav");
    for (int i = 0 ; i <= 10 ; i++){
        ui->pokemon_inf->setGeometry(40+(170/10)*i,360,381,321);
        QThread::msleep(15);
        this->repaint();
    }
    for (int i = 10 ; i >= 0 ; i--){
        ui->pokemon_inf->setGeometry(40+(170/10)*i,360,381,321);
        QThread::msleep(15);
        this->repaint();
    }
}

/* Animaciones de ataque para los pokemons superiores */
void Battle::attackAnimationSup(){
    audio.launchSound("attack.wav");
    for (int i = 0 ; i <= 10 ; i++){
        ui->pokemon_sup->setGeometry(610-(140/10)*i,60+(120/10)*i,321,321);
        QThread::msleep(15);
        this->repaint();
    }
    for (int i = 10 ; i >= 0 ; i--){
        ui->pokemon_sup->setGeometry(610-(140/10)*i,60+(120/10)*i,321,321);
        QThread::msleep(15);
        this->repaint();
    }
}

/* Cambia el pokemon ya sea por decisión propia o por muerte del pokemon actual */
void Battle::setPoke(Pokemon* _poke,bool cambio_forzado) {
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
    updateBars();
    if(!cambio_forzado){
        bool userAlive = CpuAttack();
    resolveStates(cpu_poke);

    if(userAlive){
        resolveStates(user_poke);
    }
    }
    QThread::msleep(500);
    ui->cuadro_texto->setText("Haz tu movimiento.");
    this->repaint();
}

/* Animacion de la barra de vida */
void Battle::hpBarAnimation(int antes, Pokemon* pokemon) {
    float ant = antes;
    float tot = pokemon->getHPtotal();
    float des = pokemon->getHP();
    if (des < 0) {
        des = 0;
    }
    if (pokemon == user_poke) {
        for (int i = 0 ; i <= 15 ; i++) {
            ui->vida_inf->setGeometry(802,550,170*(ant/tot-((ant-des)/(tot*15))*i),35);
            ui->vida_act->setText( QString::number(round(ant-((ant-des)/15)*i)));
            if (170*(ant/tot-((ant-des)/(tot*15))*i) <= 94 && 170*(ant/tot-((ant-des)/(tot*15))*i) > 43) { // rangos: 55% y 25% de 170
                ui->vida_inf->setStyleSheet("background: transparent;border-image: url(:/files/combate/amarillo.png)");
            }else if (170*(ant/tot-((ant-des)/(tot*15))*i) < 43) {
                ui->vida_inf->setStyleSheet("background: transparent;border-image: url(:/files/combate/rojo.png)");
            }else {
                ui->vida_inf->setStyleSheet("background: transparent;border-image: url(:/files/combate/verde.png)");
            }
            QThread::msleep(50);
            this->repaint();
        }


    }else if (pokemon == cpu_poke){
        for (int i = 0 ; i <= 15 ; i++){
            ui->vida_sup->setGeometry(155,115,170*(ant/tot-((ant-des)/(tot*15))*i),35);
            if (170*(ant/tot-((ant-des)/(tot*15))*i) <= 94 && 170*(ant/tot-((ant-des)/(tot*15))*i) > 43) { // rangos: 55% y 25% de 170
                ui->vida_sup->setStyleSheet("background: transparent;border-image: url(:/files/combate/amarillo.png)");
            }else if (170*(ant/tot-((ant-des)/(tot*15))*i) < 43) {
                ui->vida_sup->setStyleSheet("background: transparent;border-image: url(:/files/combate/rojo.png)");
            }else {
                ui->vida_sup->setStyleSheet("background: transparent;border-image: url(:/files/combate/verde.png)");
            }
            QThread::msleep(50);
            this->repaint();
        }
    }else {
        // No pasa nada
    }
}

/* Cambia el pokemon del rival */
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
    updateBars();
}

/* Comprueba la vida del pokemon rival para ver si puede seguir luchando */
bool Battle::checkCpuPokeHp(){
    if(cpu_poke->getHP()<=0){
        qDebug() << "Dejalo, ya esta muerto";
        cpu->updateStatus();
        if(cpu->checkStatus()){
            qDebug() << "Le has ganado";

            for (int i = 0; i <= 15; i++) {
                ui->pokemon_sup->setGeometry(610+(390/15)*i, 60, 321, 321);
                QThread::msleep(25);
                this->repaint();
            }
            ui->enemigo->show();
            for (int i = 0; i <= 15; i++) {
                ui->enemigo->setGeometry(1000-(320/15)*i, 60, 161, 301);
                QThread::msleep(25);
                this->repaint();
            }
            switch (numbat) {
                case(1):
                    ui->cuadro_texto->setText("Parece que en el sótano de mi fracaso siempre hay una planta más...");
                    this->repaint();
                    QThread::msleep(3000);
                    break;

                case(2):
                    ui->cuadro_texto->setText("Pues ale, a casa calentito...");
                    this->repaint();
                    QThread::msleep(3000);
                    break;

                case(3):
                    ui->cuadro_texto->setText("Bueno, pues hoy toca chill y netflix...");
                    this->repaint();
                    QThread::msleep(3000);
                    break;

                case(4):
                    ui->cuadro_texto->setText("Si es que soy un bocas...");
                    this->repaint();
                    QThread::msleep(3000);
                    break;

                default:
                    this->repaint();
                    QThread::msleep(2000);
                    break;
            }
            this->close();
        }else{
            changeCpuPoke();
        }
//            QMessageBox::information(this,"Game Over","Has perdido");
        // Emitir señal para cerrar el mapa
        return false;
    }else
        return true;
}

/* Comprueba la vida del pokemon del usuario para ver si puede seguir luchando */
bool Battle::checkUserPokeHp(){
    if(user_poke->getHP()<=0){
        user->updateStatus();
        if(!user->checkStatus()){
            qDebug() << "Dejalo, ya se me mato el pollo de fuego";
            cambio *v_cambio=new cambio(this,user,user_poke,true);
            v_cambio->show();
            connect(v_cambio,SIGNAL(selectedPoke(Pokemon*,bool)),this,SLOT(setPoke(Pokemon*,bool)));
            return false;
        }else {
            perdido = true;
//            QMessageBox::information(this,"Game Over","Has perdido");
            return true;
        }
    }else
        return true;
}

/* Ataque del pokemon del usuario */
bool Battle::UserAttack(Movimientos* _move){
    uint acertado;
    int vida_anterior;
    if (user_poke->getStatePtr()->getMov()){
        qDebug()<<"El mas rapido del oeste";
        vida_anterior=cpu_poke->getHP();
        acertado=_move->getDamage(user_poke,cpu_poke);
        BattleText(acertado,_move,vida_anterior,user_poke,cpu_poke);
//        hpBarAnimation(vida_anterior,cpu_poke);
        updateBars();
        return checkCpuPokeHp();
    }
        else{
//        qDebug()<<"No se ha movido por pringado";
        ui->cuadro_texto->setText(QString("%1 esta %2.\nY no ha podido moverse.").arg(QString::fromStdString(user_poke->getName())).arg(QString::fromStdString(user_poke->getStatePtr()->getStateName())));
        this->repaint();
        QThread::msleep(500);


    }
    return true;
}

/* Ataque aleatorio del rival */
bool Battle::CpuAttack(){
    uint acertado;
    int vida_anterior;
    if (cpu_poke->getStatePtr()->getMov()){
        vida_anterior=user_poke->getHP();
        Movimientos* move=cpu_poke->getMove(rand()%4);
//        move=cpu_poke->getMove(2);
        acertado=move->getDamage(cpu_poke,user_poke);
        BattleText(acertado,move,vida_anterior,cpu_poke,user_poke);
//        hpBarAnimation(vida_anterior,user_poke);
        updateBars();
        return checkUserPokeHp();
    }else{
//        qDebug()<<"No se ha movido por pringado";
        ui->cuadro_texto->setText(QString("%1 esta %2.\nY no ha podido moverse").arg(QString::fromStdString(cpu_poke->getName())).arg(QString::fromStdString(cpu_poke->getStatePtr()->getStateName())));
        QThread::msleep(500);

    }
    return true;
}

/* Resuelve el estado del pokemon afectado */
void Battle::resolveStates(Pokemon* poke){
    int vida_anterior=poke->getHP();
    poke->getStatePtr()->resolveState(poke);
    Estado estado = poke->getState();
    if(estado == 2 || estado == 3){
        ui->cuadro_texto->setText(QString("%1 se encuentra %2.\n Y se resiente por ello.").arg(QString::fromStdString(poke->getName())).arg(QString::fromStdString(poke->getStatePtr()->getStateName())));
    }
    hpBarAnimation(vida_anterior,poke);
    if(poke==user_poke)
        checkUserPokeHp();
    else
        checkCpuPokeHp();
}

/* Actualiza la información del pokemon */
void Battle::updateBars(){
    QString stylesheet = "background: transparent;";
    QString formato = ".png";

    float userHP = user_poke->getHP();
    float userHPtotal = user_poke->getHPtotal();
    float cpuHP = cpu_poke->getHP();
    float cpuHPtotal = cpu_poke->getHPtotal();

    ui->vida_total->setText(QString::number(user_poke->getHPtotal()));
    if(user_poke->getHP()>=0)
        ui->vida_act->setText(QString::number(user_poke->getHP()));
    else
        ui->vida_act->setText("0");
    ui->pok_inf->setText(QString::fromStdString(user_poke->getName()));
    ui->level_inf->setText(QString::number(user_poke->getLevel()));
    ui->state_inf->setStyleSheet(stylesheet + "border-image: url(:/files/estados/" + QString::fromStdString(user_poke->getStatePtr()->getNameByState(user_poke->getState()))+formato+")");


    ui->pok_sup->setText(QString::fromStdString(cpu_poke->getName()));
    ui->level_sup->setText(QString::number(cpu_poke->getLevel()));
    ui->state_sup->setStyleSheet(stylesheet + "border-image: url(:/files/estados/" + QString::fromStdString(cpu_poke->getStatePtr()->getNameByState(cpu_poke->getState()))+formato+ ")");

    ui->vida_inf->setGeometry(802,550,170*userHP/userHPtotal,35);
    if (170*userHP/userHPtotal <= 94 && 170*userHP/userHPtotal > 43) { // rangos: 55% y 25% de 170
        ui->vida_inf->setStyleSheet("background: transparent;border-image: url(:/files/combate/amarillo.png)");
    }else if (170*userHP/userHPtotal < 43) {
        ui->vida_inf->setStyleSheet("background: transparent;border-image: url(:/files/combate/rojo.png)");
    }else {
        ui->vida_inf->setStyleSheet("background: transparent;border-image: url(:/files/combate/verde.png)");
    }

    ui->vida_sup->setGeometry(155,115,170*cpuHP/cpuHPtotal,35);
    if (170*cpuHP/cpuHPtotal <= 94 && 170*cpuHP/cpuHPtotal > 43) { // rangos: 55% y 25% de 170
        ui->vida_sup->setStyleSheet("background: transparent;border-image: url(:/files/combate/amarillo.png)");
    }else if (170*cpuHP/cpuHPtotal < 43) {
        ui->vida_sup->setStyleSheet("background: transparent;border-image: url(:/files/combate/rojo.png)");
    }else {
        ui->vida_sup->setStyleSheet("background: transparent;border-image: url(:/files/combate/verde.png)");
    }

    this->repaint();
}

/* Texto durante la batalla */
void Battle::BattleText(uint acertado,Movimientos* _move,int vida_anterior, Pokemon* Atacante, Pokemon* Defensor){
    QString texto;
    float multiplicador;
    std::string efectividad;
    switch (acertado) {
        case 0:
            ui->cuadro_texto->setText(QString("%1 ha fallado.").arg(QString::fromStdString(Atacante->getName())));
            this->repaint();
            QThread::msleep(1000);
            break;
        case 1:
            {
                texto = QString("%1").arg(QString::fromStdString(Atacante->getName()));
                ui->cuadro_texto->setText(QString("%1 ha realizado %2").arg(QString::fromStdString(Atacante->getName())).arg(QString::fromStdString(_move->getName())));
                this->repaint();
                if(Defensor==user_poke)
                    attackAnimationSup();
                else
                    attackAnimationInf();
                hpBarAnimation(vida_anterior,Defensor);
                multiplicador = Defensor->getType().multiplicador(_move->getTipos());
                efectividad=Defensor->getType().eficacia(multiplicador);
                ui->cuadro_texto->setText(QString::fromStdString(efectividad));
                this->repaint();
                break;
            }
        case 2:
            {
                texto= QString("%1").arg(QString::fromStdString(Atacante->getName()));
                ui->cuadro_texto->setText(QString("%1 ha realizado %2").arg(QString::fromStdString(Atacante->getName())).arg(QString::fromStdString(_move->getName())));
                this->repaint();
                if(Defensor==user_poke)
                    attackAnimationSup();
                else
                    attackAnimationInf();
                hpBarAnimation(vida_anterior,Defensor);
                ui->cuadro_texto->setText(QString::fromStdString(efectividad));
                this->repaint();
                QThread::msleep(500);
                Defensor->getStatePtr()->getStateName();
                ui->cuadro_texto->setText(QString("%1 ha sido %2.").arg(QString::fromStdString(Defensor->getName())).arg(QString::fromStdString(Defensor->getStatePtr()->getStateName())));
                this->repaint();
                break;
            }
        case 3:
            {
                texto = QString("%1").arg(QString::fromStdString(Atacante->getName()));
                ui->cuadro_texto->setText(QString("%1 ha realizado %2").arg(QString::fromStdString(Atacante->getName())).arg(QString::fromStdString(_move->getName())));
                this->repaint();
                if(Defensor==user_poke )
                    attackAnimationSup();
                else
                    attackAnimationInf();
                hpBarAnimation(vida_anterior,Defensor);
                multiplicador = Defensor->getType().multiplicador(_move->getTipos());
                efectividad=Defensor->getType().eficacia(multiplicador);
                ui->cuadro_texto->setText(QString::fromStdString(efectividad));
                this->repaint();
                QThread::msleep(500);
                ui->cuadro_texto->setText("¡Golpe critico!");
                this->repaint();
                break;
            }
        case 4:
            {
                texto= QString("%1").arg(QString::fromStdString(Atacante->getName()));
                ui->cuadro_texto->setText(QString("%1 ha realiazado %2").arg(QString::fromStdString(Atacante->getName())).arg(QString::fromStdString(_move->getName())));
                this->repaint();
                if(Defensor==user_poke)
                    attackAnimationSup();
                else
                    attackAnimationInf();
                hpBarAnimation(vida_anterior,Defensor);
                ui->cuadro_texto->setText(QString::fromStdString(efectividad));
                this->repaint();
                QThread::msleep(500);
                ui->cuadro_texto->setText("¡Golpe critico!");
                this->repaint();
                QThread::msleep(500);
                Defensor->getStatePtr()->getStateName();
                ui->cuadro_texto->setText(QString("%1 ha sido %2.").arg(QString::fromStdString(Defensor->getName())).arg(QString::fromStdString(Defensor->getStatePtr()->getStateName())));
                this->repaint();
                break;
            }
        case 5:
            {
                texto= QString("%1").arg(QString::fromStdString(Atacante->getName()));
                ui->cuadro_texto->setText(QString("%1 ha realiazado %2").arg(QString::fromStdString(Atacante->getName())).arg(QString::fromStdString(_move->getName())));
                this->repaint();
                if(Defensor==user_poke)
                    attackAnimationSup();
                else
                    attackAnimationInf();
                hpBarAnimation(vida_anterior,Defensor);
                QThread::msleep(500);
                Defensor->getStatePtr()->getStateName();
                ui->cuadro_texto->setText(QString("%1 ha sido %2.").arg(QString::fromStdString(Defensor->getName())).arg(QString::fromStdString(Defensor->getStatePtr()->getStateName())));
                this->repaint();
                break;
            }
    default:
            {
            texto = QString("%1").arg(QString::fromStdString(Atacante->getName()));
            ui->cuadro_texto->setText(QString("%1 ha realiazado %2").arg(QString::fromStdString(Atacante->getName())).arg(QString::fromStdString(_move->getName())));
            this->repaint();
            if(Defensor==user_poke)
                attackAnimationSup();
            else
                attackAnimationInf();
            hpBarAnimation(vida_anterior,Defensor);
            multiplicador = Defensor->getType().multiplicador(_move->getTipos());
            efectividad=Defensor->getType().eficacia(multiplicador);
            ui->cuadro_texto->setText(QString::fromStdString(efectividad));
            this->repaint();
            break;
            }

    }
//    QThread::msleep(500);
}
