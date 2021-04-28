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
        bool selection = false;
        bool genre = false; // male = false, female = true;

    public:
        explicit Personaje(QWidget *parent = nullptr);
        ~Personaje();

    private slots:
        void selection_male();
        void selection_female();
        void on_listo_clicked();

    private:
        Ui::Personaje *ui;
        void closeEvent(QCloseEvent *event) override;
    signals:
        void genrePicked(bool genero);
};


class CustomLabel : public QLabel {
        Q_OBJECT

    public:
        CustomLabel(QWidget* parent = nullptr) : QLabel(parent){}
        void changeFileInf(QString file);
        void changeFileSup(QString file);

    private slots:
        void lowImage();

    private:
        bool internal_flag = false;
        QString file_inf;
        QString file_sup;

    protected:
        void enterEvent(QEnterEvent *ev) override;
        void leaveEvent(QEvent *ev) override;
        void mousePressEvent(QMouseEvent *ev) override;

    signals:
        void changeImage();

};

#endif // PERSONAJE_H
