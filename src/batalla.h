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

    void on_next_clicked();
    void batalla();
    void get_name();
    void get_genre();

private:
    Ui::Batalla *ui;
};

#endif // BATALLA_H
