#include "personaje.h"
#include "ui_personaje.h"
#include "pers.h"

Personaje::Personaje(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Personaje)
{
    ui->setupUi(this);
    ui->label->changeFileInf("background:transparent;\nborder-image: url(:/res/m2.png);");
    ui->label->changeFileSup("background:transparent;\nborder-image: url(:/res/m.png);");
    ui->label_3->changeFileInf("background:transparent;\nborder-image: url(:/res/f.png);");
    ui->label_3->changeFileSup("background:transparent;\nborder-image: url(:/res/f2.png);");

    CustomLabel::connect(ui->label,SIGNAL(changeImage()),ui->label_3,SLOT(lowImage()));
    CustomLabel::connect(ui->label_3,SIGNAL(changeImage()),ui->label,SLOT(lowImage()));

    QWidget::connect(ui->label,SIGNAL(changeImage()),this,SLOT(selection_male()));
    QWidget::connect(ui->label_3,SIGNAL(changeImage()),this,SLOT(selection_female()));

    ui->listo->setVisible(false);

    QObject::connect(this,SIGNAL(genrePicked(bool)),parentWidget()->parentWidget(),SLOT(set_genre(bool)));
}

Personaje::~Personaje()
{
    delete ui;
}

void Personaje::selection_male() {
    selection = true;
    genre = false;
    ui->listo->setVisible(true);
}

void Personaje::selection_female() {
    selection = true;
    genre = true;
    ui->listo->setVisible(true);
}

void Personaje::closeEvent(QCloseEvent *event) {
    parentWidget()->parentWidget()->show();
    event->accept();
}

void CustomLabel::enterEvent(QEnterEvent *ev) {
    QLabel::enterEvent(ev);
    if (!internal_flag)
        this->setStyleSheet(file_sup);
}

void CustomLabel::leaveEvent(QEvent *ev) {
    QLabel::leaveEvent(ev);
    if (!internal_flag)
       this->setStyleSheet(file_inf);
}

void CustomLabel::mousePressEvent(QMouseEvent *ev) {
    QLabel::mousePressEvent(ev);
    internal_flag = true;
    this->setStyleSheet(file_sup);
    emit changeImage();
    /* contrario->lowImage(); */
}

void CustomLabel::changeFileInf(QString file) {
    file_inf = file;
}

void CustomLabel::changeFileSup(QString file) {
    file_sup = file;
}

void CustomLabel::lowImage() {
    this->setStyleSheet(file_inf);
    internal_flag = true;
}


void Personaje::on_listo_clicked() {
    emit genrePicked(genre);
    close();
}

