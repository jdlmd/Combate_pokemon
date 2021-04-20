#include "pers.h"
#include "ui_pers.h"
#include <QString>
#include "QMessageBox"
#include "personaje.h"
#include "mainwindow.h"

pers::pers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pers)
{
    ui->setupUi(this);
    ui->listo->setVisible(false);
}

pers::~pers()
{
    delete ui;
}

void pers::on_siguiente_clicked()
{
    QString nombre=ui->nombre->text();
    parentWidget()->set_name(nombre);
    QMessageBox::information(this,tr("Usuario generado correctamente."),tr("Aprendiz %1, tiene gancho.").arg(nombre));

    Personaje *v_per=new Personaje(this);
    v_per->show();
    hide();
    ui->listo->setVisible(true);

}

void pers::on_listo_clicked()
{
    close();
}

void pers::closeEvent(QCloseEvent *event){
    parentWidget()->show();
    event->accept();
}
