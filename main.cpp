#include "graphics/mainwindow.h"
#include "audio/extern.h"

#include <QApplication>
#include <QFile>
#include <QFontDatabase>

int main(int argc, char *argv[]) {
    audio.launchAudio("theme.wav");
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    w->show();
    return a.exec();
}
