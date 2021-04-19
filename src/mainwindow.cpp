#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include "QMainWindow"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{

}

void MainWindow::on_personaje_clicked()
{
    Personaje *v_personaje=new Personaje(this);
    v_personaje->setWindowModality(Qt::WindowModal);
    v_personaje-> show();
}
