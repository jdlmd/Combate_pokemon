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

}

Personaje::~Personaje()
{
    delete ui;
}

void Personaje::selection_male() {
    selection = true;
    genre = false;
    ui->checkBox->setChecked(genre);
}

void Personaje::selection_female() {
    selection = true;
    genre = true;
    ui->checkBox->setChecked(genre);
}

void Personaje::closeEvent(QCloseEvent *event){
    parentWidget()->show();
    event->accept();
}

void CustomLabel::enterEvent(QEvent *ev){
    QLabel::enterEvent(ev);
    if (!internal_flag)
        this->setStyleSheet(file_sup);
}

void CustomLabel::leaveEvent(QEvent *ev){
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

void CustomLabel::changeFileInf(QString file){
    file_inf = file;
}

void CustomLabel::changeFileSup(QString file){
    file_sup = file;
}

void CustomLabel::lowImage(){
    this->setStyleSheet(file_inf);
    internal_flag = true;
}



void Personaje::on_listo_clicked()
{
  close();


}
