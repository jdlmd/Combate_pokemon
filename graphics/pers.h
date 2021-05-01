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
        explicit pers(QWidget *parent = nullptr);
        ~pers();

    private slots:
        void on_siguiente_clicked();
        void on_listo_clicked();

    private:
        Ui::pers *ui;
        void closeEvent(QCloseEvent *event) override;

    signals:
        void namePicked(QString nombre);
};

#endif // PERS_H
