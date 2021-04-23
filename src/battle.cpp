#include "battle.h"
#include "ui_battle.h"

#include <SDL.h>
#include <SDL_main.h>
#include "iostream"

#define FILE_PATH "./theme.wav"

struct AudioData {
    Uint8* pos;
    Uint32 length;
};

void MyAudioCallback(void* userdata, Uint8* stream, int streamLength) {
    AudioData* audio = (AudioData*)userdata;
    if(audio->length == 0) {
        return;
    }

    Uint32 length = (Uint32)streamLength;
    length = (length > audio->length ? audio->length : length);

    SDL_memcpy(stream,audio->pos,length);

    audio->pos += length;
    audio->length -= length;

}

Battle::Battle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Battle)
{
    ui->setupUi(this);

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

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;

    if(SDL_LoadWAV(FILE_PATH, &wavSpec, &wavStart, &wavLength) == NULL) {
        std::cerr << "Error: " << FILE_PATH << " no se puede cargar\n";
        QString pt = QDir::currentPath();
        qDebug() << pt;
    }

    AudioData audio;
    audio.pos = wavStart;
    audio.length = wavLength;

    wavSpec.callback = MyAudioCallback;
    wavSpec.userdata = &audio;

    SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL,0,&wavSpec,NULL,SDL_AUDIO_ALLOW_ANY_CHANGE);

    if(device == 0) {
        std::cerr << "Error, no se puede reproducir.\n";
    }

    SDL_PauseAudioDevice(device,0);
    // Variables de altura y posición para los elementos de la animación
    int width = 0.8*ancho/2;
    int height = (alto-ui->label_2->geometry().height())/3;
    int pY = (alto-ui->label_2->geometry().height())/2 - height/2;

    QLabel* font = new QLabel(this->centralWidget()); // Se genera un fondo negro
    font->setGeometry(0,0,ancho,alto);
    font->setStyleSheet("background-color: black;");
    font->lower();
    font->show();
    ui->label->lower();

    ui->label_2->setText("Te retaron wey!");

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
    PjIzq->setStyleSheet("border-image: url(:/res/Nerea.png);\nbackground: transparent;");
    PjDer->setStyleSheet("border-image: url(:/res/Maria.png);\nbackground: transparent;");
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

    ui->label_2->setText("¡EL COMBATE ESTÁ A PUNTO DE COMENZAR!");
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

    SDL_CloseAudioDevice(device);
    SDL_FreeWAV(wavStart);
    SDL_Quit();

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
}
