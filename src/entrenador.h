#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <iostream>
#include <fstream> // Streams de entrada y salida para archivos
#include "definiciones.h"
#include "string"
#include "pokemon.h"

class Entrenador {
    public:
        Entrenador(); // Constructor por defecto
        Entrenador(std::string filename); // Cargar desde archivo
        ~Entrenador(); // Destructor

        void setNombre(std::string name); // Cargar nombre al entrenador
        std::string getNombre(); // Recibir el nombre del entrenador

        void setNumPoke(uint num); // Fija el número de pokemons vivos del entrenador
        uint getNumPoke(); // Comprueba la cantidad de pokemons vivos que tiene

        void updateStatus(); // Actualiza el status del entrenador
        bool checkStatus(); // Comprueba si el entrenador ha sido derrotado

    private:
        std::string nombre; // Nombre del entrenador
        Genero genre; // Género del entrenador
        uint numPoke; // El número actual de pokemons que tiene vivos (max 6)
        std::vector<Pokemon> equipo; // El vector con sus pokemons
        bool derrotado; // Guarda si el entrenador ha sido derrotado

};

#endif // ENTRENADOR_H
