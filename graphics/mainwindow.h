#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
            void on_start_clicked(); // Boton de Start pulsado
            void on_personaje_clicked(); // Boton de Crear personaje pulsado
            void set_name(QString nombre); // Elección del nombre del personaje
            void set_genre(bool genero); // Elección del genero del personaje

    private:
            Ui::MainWindow *ui;
            QString name;
            bool genre;
};

#endif // MAINWINDOW_H
