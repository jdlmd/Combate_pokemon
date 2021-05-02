#include "personaje.h"
#include "ui_personaje.h"
#include "pers.h"
#include <QFontDatabase>

/* Constructor */
Personaje::Personaje(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Personaje)
{
    ui->setupUi(this);
    ui->label->changeFileInf("background:transparent;\nborder-image: url(:/files/personajes/m2.png);");
    ui->label->changeFileSup("background:transparent;\nborder-image: url(:/files/personajes/m.png);");
    ui->label_3->changeFileInf("background:transparent;\nborder-image: url(:/files/personajes/f.png);");
    ui->label_3->changeFileSup("background:transparent;\nborder-image: url(:/files/personajes/f2.png);");

    CustomLabel::connect(ui->label,SIGNAL(changeImage()),ui->label_3,SLOT(lowImage()));
    CustomLabel::connect(ui->label_3,SIGNAL(changeImage()),ui->label,SLOT(lowImage()));

    QWidget::connect(ui->label,SIGNAL(changeImage()),this,SLOT(selection_male()));
    QWidget::connect(ui->label_3,SIGNAL(changeImage()),this,SLOT(selection_female()));

    ui->listo->setVisible(false);

    QObject::connect(this,SIGNAL(genrePicked(bool)),parentWidget()->parentWidget(),SLOT(set_genre(bool)));
    this->setFixedSize(this->size()); // Evita que se haga resize
    QFontDatabase::addApplicationFont(":/files/Pokemon_Pinball_RS.ttf");
    QFont pokefont = QFont("Pokemon Pinball RS",12,1);
    ui->textBrowser->setFont(pokefont);
}

/* Destructor */
Personaje::~Personaje()
{
    delete ui;
}

/* Pone el género del personaje a masculino  */
void Personaje::selection_male() {
    selection = true;
    genre = false;
    ui->listo->setVisible(true);
}

/* Pone el género del personaje a femenino  */
void Personaje::selection_female() {
    selection = true;
    genre = true;
    ui->listo->setVisible(true);
}

/* Cierra la ventana de selección de avatar y te devuelve a la principal */
void Personaje::closeEvent(QCloseEvent *event) {
    parentWidget()->parentWidget()->show();
    event->accept();
}

/* Comprueba si estás encima de los labels para que posteriormente el personaje seleccionado se vea con color */
void CustomLabel::enterEvent(QEnterEvent *ev) {
    QLabel::enterEvent(ev);
    if (!internal_flag)
        this->setStyleSheet(file_sup);
}

/* Comprueba si estás encima de los labels para que posteriormente el personaje no seleccionado se vea en negro */
void CustomLabel::leaveEvent(QEvent *ev) {
    QLabel::leaveEvent(ev);
    if (!internal_flag)
       this->setStyleSheet(file_inf);
}

/* Cuando se pulsa el label se selecciona el personaje que se haya pulsado */
void CustomLabel::mousePressEvent(QMouseEvent *ev) {
    QLabel::mousePressEvent(ev);
    internal_flag = true;
    this->setStyleSheet(file_sup);
    emit changeImage();
    /* contrario->lowImage(); */
}

/* Cambia la imagen del label a la oscura */
void CustomLabel::changeFileInf(QString file) {
    file_inf = file;
}

/* Cambia la imagen del label a la de color */
void CustomLabel::changeFileSup(QString file) {
    file_sup = file;
}

/* Inicializa la label a file inf */
void CustomLabel::lowImage() {
    this->setStyleSheet(file_inf);
    internal_flag = true;
}

/* Emite el género que se ha escogido */
void Personaje::on_listo_clicked() {
    emit genrePicked(genre);
    close();
}

