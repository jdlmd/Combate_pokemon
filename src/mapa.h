#ifndef MAPA_H
#define MAPA_H

#include <QMainWindow>

namespace Ui {
class Mapa;
}

class Mapa : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mapa(QWidget *parent = nullptr);
    ~Mapa();

private slots:
    void on_b3_clicked();

    void on_b2_clicked();

    void on_b1_clicked();

    void on_b4_clicked();

private:
    Ui::Mapa *ui;
};

#endif // MAPA_H
