QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cambio.cpp \
    src/atacar.cpp \
    audio/audio.cpp \
    src/batalla.cpp \
    src/battle.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mapa.cpp \
    src/movimientoestado.cpp \
    src/movimientos.cpp \
    src/pokemon.cpp \
    src/tipo.cpp \
    src/pers.cpp \
    src/personaje.cpp \
    src/entrenador.cpp \
    src/estados.cpp 

HEADERS += \
    cambio.h \
    src/atacar.h \
    audio/audio.h \
    src/batalla.h \
    src/battle.h \
    src/mainwindow.h \
    src/mapa.h \
    src/pers.h \
    src/personaje.h \
    src/entrenador.h \
    src/estados.h \
    src/mainwindow.h \
    src/movimientoestado.h \
    src/movimientos.h \
    src/pokemon.h \
    src/tipo.h \
    src/definiciones.h 

FORMS += \
    cambio.ui \
    src/atacar.ui \
    src/batalla.ui \
    src/battle.ui \
    src/mainwindow.ui \
    src/mapa.ui \
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
