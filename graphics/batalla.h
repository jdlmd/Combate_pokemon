#ifndef BATALLA_H
#define BATALLA_H

#include <QMainWindow>

namespace Ui {
class Batalla;
}

class Batalla : public QMainWindow
{
    Q_OBJECT

public:
    bool sgenre;
    QString sname;
    explicit Batalla(QWidget *parent = nullptr,QString sname="usuario",bool genre=0); // Constructor
    ~Batalla();

private slots:
    void on_next_clicked(); // Comprueba si se pulsa el boton de siguiente

private:
    Ui::Batalla *ui;
};

#endif // BATALLA_H
