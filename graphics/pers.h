#ifndef PERS_H
#define PERS_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class pers;
}

class pers : public QMainWindow {
        Q_OBJECT

    public:
        explicit pers(QWidget *parent = nullptr); // Constructor
        ~pers(); // Destructor

    private slots:
        void on_siguiente_clicked(); // Comprueba si se pulsa siguiente

    private:
        Ui::pers *ui;
        void closeEvent(QCloseEvent *event) override; // Cierra la ventana de creacion de personaje

    signals:
        void namePicked(QString nombre);
};

#endif // PERS_H
