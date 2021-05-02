#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QMainWindow>
#include <QLabel>
#include <QCloseEvent>

namespace Ui {
    class Personaje;
    class CustomLabel;
}

class CustomLabel;

class Personaje : public QMainWindow {
    Q_OBJECT
        bool selection = false; // si se ha hecho la selección = true
        bool genre = false; // male = false, female = true;

    public:
        explicit Personaje(QWidget *parent = nullptr); // Constructor
        ~Personaje(); // Destructor

    private slots:
        void selection_male(); // Pone el género del personaje a masculino
        void selection_female(); // Pone el género del personaje a femenino
        void on_listo_clicked(); // Emite el género que se ha escogido

    private:
        Ui::Personaje *ui;
        void closeEvent(QCloseEvent *event) override; // Cierra la ventana de selección de avatar y te devuelve a la principal
    signals:
        void genrePicked(bool genero); // Señal que emite el género que se ha escogido
};


class CustomLabel : public QLabel {
        Q_OBJECT

    public:
        CustomLabel(QWidget* parent = nullptr) : QLabel(parent){}
        void changeFileInf(QString file); // Cambia la imagen del label a la oscura
        void changeFileSup(QString file); // Cambia la imagen del label a la de color

    private slots:
        void lowImage(); // Inicializa la label a file inf

    private:
        bool internal_flag = false;
        QString file_inf;
        QString file_sup;

    protected:
        void enterEvent(QEnterEvent *ev) override; // Comprueba si estás encima de los labels
        void leaveEvent(QEvent *ev) override; // Comprueba si no estás encima de los labels
        void mousePressEvent(QMouseEvent *ev) override; // Cuando se pulsa el label se selecciona el personaje que se haya pulsado

    signals:
        void changeImage();

};

#endif // PERSONAJE_H
