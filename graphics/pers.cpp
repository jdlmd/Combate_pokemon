#include "pers.h"
#include "ui_pers.h"
#include <QString>
#include <QMessageBox>
#include "personaje.h"
#include "mainwindow.h"
#include <QFontDatabase>

/* Constructor */
pers::pers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pers)
{
    ui->setupUi(this);
    this->setFixedSize(this->size()); // Evita que se haga resize
    QFontDatabase::addApplicationFont(":/files/Pokemon_Pinball_RS.ttf");
    QFont pokefont = QFont("Pokemon Pinball RS",12,1);
    ui->texto->setFont(pokefont);
}

/* Destructor */
pers::~pers() {
    delete ui;
}

/* Comprueba si se ha pulsado siguiente */
void pers::on_siguiente_clicked() {
    QString nombre=ui->nombre->text();
    emit namePicked(nombre);
    QMessageBox::information(this,tr("Usuario generado correctamente."),tr("Aprendiz %1, tiene gancho.").arg(nombre));

    Personaje *v_per=new Personaje(this);
    v_per->show();
    hide();

}

/* Cierra la ventana de creación de personaje */
void pers::closeEvent(QCloseEvent *event){
    parentWidget()->show();
    event->accept();
}
