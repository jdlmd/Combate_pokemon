QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/estados.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/movimientoestado.cpp \
    src/movimientos.cpp \
    src/pokemon.cpp \
    src/tipo.cpp

HEADERS += \
    src/definiciones.h \
    src/estados.h \
    src/mainwindow.h \
    src/movimientoestado.h \
    src/movimientos.h \
    src/pokemon.h \
    src/tipo.h

FORMS += \
    src/mainwindow.ui

TRANSLATIONS += \
    Combate_pokemon_es_ES.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
        README.md
