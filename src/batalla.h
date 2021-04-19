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
    explicit Batalla(QWidget *parent = nullptr);
    ~Batalla();

private slots:
    void on_atacar_clicked();

    void on_mochila_clicked();

    void on_cambio_clicked();

private:
    Ui::Batalla *ui;
};

#endif // BATALLA_H
