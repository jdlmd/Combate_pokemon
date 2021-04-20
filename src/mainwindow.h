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
        void set_name(QString);
        void set_genre(bool);

private slots:
        void on_start_clicked();
        void on_personaje_clicked();

private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
