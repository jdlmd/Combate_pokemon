#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <iostream>
#include <fstream> // Streams de entrada y salida para archivos
#include "definiciones.h"
#include "string"
#include "pokemon.h"
#include "movimientoestado.h"
#include <random>
#include <time.h>

/* Clase entrenador:
La clase entrenador guardará un vector con los pokemons (se guardarán de forma
dinámica en memoria, utilizando punteros). La clase entrenador guardará el nombre
del jugador (y del rival cpu), así como una bandera booleana para saber si ha sido
derrotado. Tendrá métodos generales para fijar su nombre, genero, número de pokemons
y pokemons
*/
class Entrenador {
    public:
        Entrenador(); // Constructor por defecto
        Entrenador(std::string filename); // Cargar desde archivo
        ~Entrenador(); // Destructor
        void setNombre(std::string name); // Cargar nombre al entrenador
        std::string getNombre(); // Recibir el nombre del entrenador
        uint getNumPoke(); // Comprueba la cantidad de pokemons vivos que tiene
        void setNumPoke(uint _numPoke); // Fija la cantidad de pokemons vivos que tiene
        uint getNumber(); // Comprueba la cantida máximas de pokemons que tiene
        void setNumber(); // Fija la cantidad total de pokemons (max 6)
        void updateStatus(); // Actualiza el status del entrenador
        bool checkStatus(); // Comprueba si el entrenador ha sido derrotado
        void addPokemon(); // Añade un pokemon
        void removePokemon(); // Quita un pokemon
        Pokemon* getPokemon(int i); // Devuelve un pokemon

    private:
        std::string nombre; // Nombre del entrenador
        Genero genre; // Género del entrenador
        uint numPoke; // El número actual de pokemons que tiene vivos (max 6)
        uint number; // El número de pokemon totales que tiene (max 6)
        std::vector<Pokemon*> equipo; // El vector con sus pokemons
        bool derrotado; // Guarda si el entrenador ha sido derrotado
        void defaultPoke(); // Pokemon por defecto

};

#endif // ENTRENADOR_H
