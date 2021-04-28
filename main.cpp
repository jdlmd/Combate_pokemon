#include "graphics/mainwindow.h"
#include "audio/audio.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    Audio snk;
    snk.launchAudio("theme.wav");
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    w->show();
    return a.exec();
}
