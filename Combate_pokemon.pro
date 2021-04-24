QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/atacar.cpp \
    audio/audio.cpp \
    src/batalla.cpp \
    src/battle.cpp \
    src/cambio.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mochila.cpp \
    src/pers.cpp \
    src/personaje.cpp

HEADERS += \
    src/atacar.h \
    audio/audio.h \
    src/batalla.h \
    src/battle.h \
    src/cambio.h \
    src/mainwindow.h \
    src/mochila.h \
    src/pers.h \
    src/personaje.h


FORMS += \
    src/atacar.ui \
    src/batalla.ui \
    src/battle.ui \
    src/cambio.ui \
    src/mainwindow.ui \
    src/mochila.ui \
    src/pers.ui \
    src/personaje.ui

TRANSLATIONS += \
    Combate_pokemon_es_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
        README.md

RESOURCES += \
    src/ResourcesVisual.qrc

# Copia de los archivos de audio a la carpeta build
CONFIG += file_copies
COPIES += audioFiles
audioFiles.files = $$files(audio/files/*.wav) # Path de copia
audioFiles.path = $$OUT_PWD/audio # Path destino
audioFiles.base = $$PWD/audio # Base del path

# Copia de los archivos de entrenadores a la carpeta build
COPIES += trainerFiles
trainerFiles.files = $$files(*.txt) # Path de copia
trainerFiles.path = $$OUT_PWD/Combate_pokemon # Path destino
# trainerFiles.base = $$PWD/audio # Base del path

# Instalación de la librería SDL
INCLUDEPATH += ./lib/SDL2-2.0.14/include/

unix|win32: LIBS += -L$$PWD/lib/SDL2-2.0.14/lib/x64/ -lSDL2

INCLUDEPATH += $$PWD/lib/SDL2-2.0.14/lib/x64
DEPENDPATH += $$PWD/lib/SDL2-2.0.14/lib/x64
