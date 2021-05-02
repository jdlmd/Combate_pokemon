#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pers.h"
#include "batalla.h"
#include <QFontDatabase>

/* Constructor */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->hide();
    ui->checkBox->hide();
    this->setFixedSize(this->size()); // Evita que se haga resize
}

/* Destructor */
MainWindow::~MainWindow()
{
    delete ui;
}

/* Boton de Start pulsado */
void MainWindow::on_start_clicked()
{
     hide();
     Batalla *v_batalla=new Batalla(this,name,genre);
     v_batalla->show();
}

/* Boton de Crear personaje pulsado */
void MainWindow::on_personaje_clicked()
{
    hide();
    pers *v_personaje=new pers(this);
    v_personaje->show();
    QObject::connect(v_personaje,SIGNAL(namePicked(QString)),this,SLOT(set_name(QString)));
}

/* Elección del nombre del personaje */
void MainWindow::set_name(QString nombre)
{
    name = nombre;
    ui->label_2->setText(name);
}

/* Elección del genero del personaje */
void MainWindow::set_genre(bool genero)
{
    genre = genero;
    ui->checkBox->setChecked(genero);
}
