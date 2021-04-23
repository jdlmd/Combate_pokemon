#ifndef BATTLE_H
#define BATTLE_H

#include <QMainWindow>

namespace Ui {
    class Battle;
}

class Battle : public QMainWindow
{
        Q_OBJECT

    public:
        explicit Battle(QWidget *parent = nullptr);
        ~Battle();

    private:
        Ui::Battle *ui;
};

#endif // BATTLE_H
