#ifndef ATACAR_H
#define ATACAR_H

#include <QDialog>

namespace Ui {
class atacar;
}

class atacar : public QDialog
{
    Q_OBJECT

public:
    explicit atacar(QWidget *parent = nullptr);
    ~atacar();

private:
    Ui::atacar *ui;
};

#endif // ATACAR_H
