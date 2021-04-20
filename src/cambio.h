#ifndef CAMBIO_H
#define CAMBIO_H

#include <QDialog>

namespace Ui {
class cambio;
}

class cambio : public QDialog
{
    Q_OBJECT

public:
    explicit cambio(QWidget *parent = nullptr);
    ~cambio();

private:
    Ui::cambio *ui;
};

#endif // CAMBIO_H
