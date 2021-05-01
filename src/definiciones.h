#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <QtGlobal>

enum Tipos : uint {
    NINGUNO = 0,
    NORMAL = 1,
    FUEGO = 2,
    LUCHA = 3,
    AGUA = 4,
    VOLADOR = 5,
    PLANTA = 6,
    ELECTRICO = 7,
    VENENO = 8,
    TIERRA = 9,
    PSIQUICO = 10,
    ROCA = 11,
    HIELO = 12,
    BICHO = 13,
    DRAGON = 14,
    FANTASMA = 15,
    SINIESTRO = 16,
    ACERO = 17,
    HADA = 18,
};

enum Genero : uint {
    NO_BIN = 0,
    MALE = 1,
    FEMALE = 2,
};

enum Estado : uint {
    NONE = 0,
    PARALIZADO = 1,
    QUEMADO = 2,
    ENVENENADO = 3,
    DORMIDO = 4,
    CONGELADO = 5,
};

struct stats {
    int hp;
    uint attack;
    uint defense;
    uint sp_attack;
    uint sp_defense;
    uint speed;
};

#endif // DEFINICIONES_H
