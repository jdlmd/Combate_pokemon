#include "entrenador.h"

Entrenador::Entrenador() {
    nombre = "N";
    genre = MALE;
    numPoke = 1;
    defaultPoke();
    derrotado = false;
}

Entrenador::Entrenador(std::string filename) {
    uint cont, cont2;
    std::string aux;
    std::ifstream entrada;
    std::string name, t1, t2;
    uint level;
    struct stats ivs, evs, base;
    derrotado = false;
    entrada.open(filename.c_str()); // Se genera el stream de entrada
    if(entrada.fail()) {
        std::cout << "Archivo no encontrado\n";
        Entrenador(); // Se llama al constructor por defecto
        return;
    }
    entrada >> nombre >> aux >> number;
    // Se determina el género en función del parámetro de entrada
    if (aux == "M")
        genre = MALE;
    else if (aux == "F")
        genre = FEMALE;
    else
        genre = NO_BIN;
    // Se comprueba el número de pokemons introducidos
    if (number > 6) {
        std::cout << "El entrenador tiene mas de 6 pokemons. Mandando los sobrantes a la caja.\n";
        number = 6;
    } else if (number < 1) {
        std::cout << "No tienes ningun pokemon. Te daremos uno!\n";
        defaultPoke();
        return;
    }
    cont = number;
    // Se introducen los pokemones poco a poco
    while(!entrada.eof() && cont--) {
        entrada >> name >> t1 >> t2 >> level;
        // Se introducen los ivs, evs y los stats base
        entrada >> ivs.hp >> ivs.attack >> ivs.defense >> ivs.sp_attack >> ivs.sp_defense >> ivs.speed;
        entrada >> evs.hp >> evs.attack >> evs.defense >> evs.sp_attack >> evs.sp_defense >> evs.speed;
        entrada >> base.hp >> base.attack >> base.defense >> base.sp_attack >> base.sp_defense >> base.speed;
        Pokemon* poke = new Pokemon(name,t1,t2,level,ivs,evs,base);
        equipo.push_back(poke);
        entrada >> cont2;

        if(cont2 > 4) {
            std::cout << "El pokemon no puede tener más de 4 ataques.\n";
        } else if (cont < 1) {
            std::cout << "El pokemon debe tener al menos 1 ataque.\n;";
        }
        while(!entrada.eof() && cont2--) {

        }

    }


}

Entrenador::~Entrenador() {
    /* Vacío */
}

void Entrenador::setNombre(std::string name) {
    nombre = name;
}

std::string Entrenador::getNombre(){
    return nombre;
}

void Entrenador::setNumPoke(uint num) {
    numPoke = num;
}

uint Entrenador::getNumPoke(){
    return numPoke;
}

void Entrenador::updateStatus() {
    // Hacer la función de updateStatus
}

bool Entrenador::checkStatus() {
    return derrotado;
}

void Entrenador::defaultPoke() {
    struct stats ivs, evs, base;
    srand(time(NULL));
    // Los IVs se establecen de forma aleatoria
    ivs.hp = rand() % 30; ivs.attack = rand() % 30; ivs.defense = rand() % 30;
    ivs.sp_attack = rand() % 30; ivs.sp_defense = rand() % 30; ivs.speed = rand() % 30;
    // Los EVs se fijan a 50
    evs.hp = 50; evs.attack = 50; evs.defense = 50;
    evs.sp_attack = 50; evs.sp_defense = 50; evs.speed = 50;
    // Se otorgan los base stats de charyzard
    base.hp = 78; base.attack = 84; base.defense = 78;
    base.sp_attack = 109; base.sp_defense = 85; base.speed = 100;
    Pokemon* poke = new Pokemon("Charyzard","FUEGO","VOLADOR",80,ivs,evs,base);
    equipo.push_back(poke);
    // Se generan los movimientos por defecto de Charyzard
    MovimientoEstado* mov1 = new MovimientoEstado("Inferno","FUEGO",1,50,100,5,"QUEMADO",3,100);
    MovimientoEstado* mov2 = new MovimientoEstado("Flare Blitz","FUEGO",0,100,120,15,"QUEMADO",3,10);
    Movimientos* mov3 = new Movimientos("Acrobatics","VOLADOR",0,100,55,15);
    Movimientos* mov4 = new Movimientos("Metal Claw","ACERO",0,95,50,35);
    poke->addMove(mov1);
    poke->addMove(mov2);
    poke->addMove(mov3);
    poke->addMove(mov4);
}
