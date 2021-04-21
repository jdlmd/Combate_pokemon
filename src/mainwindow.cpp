#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pers.h"
#include "batalla.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
     hide();
     Batalla *v_batalla=new Batalla(this,name,genre);
     v_batalla->show();
}

void MainWindow::on_personaje_clicked()
{
    hide();
    pers *v_personaje=new pers(this);
    v_personaje->show();
    QObject::connect(v_personaje,SIGNAL(namePicked(QString)),this,SLOT(set_name(QString)));
}

void MainWindow::set_name(QString nombre)
{
    name = nombre;
    ui->label_2->setText(name);
}

void MainWindow::set_genre(bool genero)
{
    genre = genero;
    ui->checkBox->setChecked(genero);
}
