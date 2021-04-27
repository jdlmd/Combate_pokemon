#include "mainwindow.h"
#include "personaje.h"
#include "battle.h"
#include "audio/extern.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    audio.launchAudio("theme.wav");
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    w->show();
    return a.exec();
}
