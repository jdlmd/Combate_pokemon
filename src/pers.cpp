#include "pers.h"
#include "ui_pers.h"
#include <QString>
#include "QMessageBox"
#include "personaje.h"

pers::pers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pers)
{
    ui->setupUi(this);
}

pers::~pers()
{
    delete ui;
}

void pers::on_siguiente_clicked()
{
    QString nombre=ui->nombre->text();
    QMessageBox::information(this,tr("Usuario generado correctamente."),tr("Aprendiz %1, tiene gancho.").arg(nombre));

    hide();

    Personaje *v_per=new Personaje(this);
    v_per->show();

}
