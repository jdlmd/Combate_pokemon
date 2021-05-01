#include "entrenador.h"

/* Constructor por defecto: generado un entrenador genérico llamado 'N' */
Entrenador::Entrenador() {
    nombre = "N";
    genre = MALE;
    number = 1;
    defaultPoke();
    derrotado = false;
}

/* Constructor por archivo: Recibe como argumento de entrada el nombre
de un fichero. El constructor accederá al fichero, y siguiendo la estructura
específica que tendrán estos ficheros construirá al entrenador con sus respectivos
pokemons y movimientos */
Entrenador::Entrenador(std::string filename) {
    // Variables a utilizar durante la ejecución del método
    uint cont, cont2, supp, _precision, _potencia, _pp, _porcentaje, _stOP, _defOR;
    std::string aux;
    std::ifstream entrada;
    std::string name, t1, t2;
    uint level;
    struct stats ivs, evs, base;
    derrotado = false; // Se coloca el entrenador como no derrotado
    entrada.open(filename.c_str()); // Se genera el stream de entrada
    if(entrada.fail()) { // Si no se consigue encontrar o abrir el archivo...
        std::cout << "Archivo no encontrado o imposible de abrir.\n";
        nombre = "N";
        genre = MALE;
        number = 1;
        defaultPoke();
        derrotado = false;
        return;
    }
    entrada >> nombre >> aux >> number; // Se dirigen las salidas del stream a las variables correspondientes
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
        number = 1;
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
        Pokemon* poke = new Pokemon(name,t1,t2,level,ivs,evs,base); // Se genera el pokemon
        // Se comprueba la cantidad de movimientos del pokemon
        entrada >> cont2;
        if(cont2 > 4) {
            std::cout << "El pokemon no puede tener más de 4 ataques.\n";
            cont2 = 4;
        } else if (cont2 < 1) {
            std::cout << "El pokemon debe tener al menos 1 movimiento. Se pondra uno por defecto\n";
            cont2 = 0; // Si no tiene movimientos, añade uno por defecto
            Movimientos* move = new Movimientos("Forcejeo","NORMAL",0,100,50,50,0);
            poke->addMove(move);
        }
        // Se generan los movimientos uno por uno
        while(!entrada.eof() && cont2--) {
            entrada >> name >> t1 >> supp;
            if (supp == 0) { // Si la variable supp = 0, el movimiento es normal
                entrada >> _precision >> _potencia >> _pp >> _stOP >> _defOR;
                Movimientos* move = new Movimientos(name,t1,_stOP,_precision,_potencia,_pp,_defOR);
                poke->addMove(move);
            } else { // Si la variable supp != 0, el movimiento es de estado
                entrada >> _precision >> _potencia >> _pp >> _stOP >> _defOR >> t2 >> _porcentaje;
                MovimientoEstado* move = new MovimientoEstado(name,t1,_stOP,_precision,_potencia,_pp,t2,_porcentaje,_defOR);
                poke->addMove(move);
            }
        }
        // Se introduce el pokemon en el equipo del entrenador
        equipo.push_back(poke);
    }
}

/* Constructor por archivo, con genero y nombre: Recibe como argumento de entrada el nombre
de un fichero, el nombre del entrenador y su genero. El constructor accederá al fichero, y siguiendo la estructura
específica que tendrán estos ficheros construirá al entrenador con sus respectivos
pokemons y movimientos */
Entrenador::Entrenador(std::string _name, Genero _genre, std::string filename) {
    // Variables a utilizar durante la ejecución del método
    uint cont, cont2, supp, _precision, _potencia, _pp, _porcentaje, _stOP, _defOR;
    std::string aux;
    std::ifstream entrada;
    std::string name, t1, t2;
    uint level;
    struct stats ivs, evs, base;
    derrotado = false; // Se coloca el entrenador como no derrotado
    entrada.open(filename.c_str()); // Se genera el stream de entrada
    if(entrada.fail()) { // Si no se consigue encontrar o abrir el archivo...
        std::cout << "Archivo no encontrado o imposible de abrir.\n";
        nombre = _name;
        genre = _genre;
        number = 1;
        defaultPoke();
        derrotado = false;
        return;
    }
    entrada >> number; // Se dirigen las salidas del stream a las variables correspondientes
    // Se comprueba el número de pokemons introducidos
    if (number > 6) {
        std::cout << "El entrenador tiene mas de 6 pokemons. Mandando los sobrantes a la caja.\n";
        number = 6;
    } else if (number < 1) {
        std::cout << "No tienes ningun pokemon. Te daremos uno!\n";
        number = 1;
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
        Pokemon* poke = new Pokemon(name,t1,t2,level,ivs,evs,base); // Se genera el pokemon
        // Se comprueba la cantidad de movimientos del pokemon
        entrada >> cont2;
        if(cont2 > 4) {
            std::cout << "El pokemon no puede tener más de 4 ataques.\n";
            cont2 = 4;
        } else if (cont2 < 1) {
            std::cout << "El pokemon debe tener al menos 1 movimiento. Se pondra uno por defecto\n";
            cont2 = 0; // Si no tiene movimientos, añade uno por defecto
            Movimientos* move = new Movimientos("Forcejeo","NORMAL",0,100,50,50,0);
            poke->addMove(move);
        }
        // Se generan los movimientos uno por uno
        while(!entrada.eof() && cont2--) {
            entrada >> name >> t1 >> supp;
            if (supp == 0) { // Si la variable supp = 0, el movimiento es normal
                entrada >> _precision >> _potencia >> _pp >> _stOP >> _defOR;
                Movimientos* move = new Movimientos(name,t1,_stOP,_precision,_potencia,_pp,_defOR);
                poke->addMove(move);
            } else { // Si la variable supp != 0, el movimiento es de estado
                entrada >> _precision >> _potencia >> _pp >> _stOP >> _defOR >> t2 >> _porcentaje;
                MovimientoEstado* move = new MovimientoEstado(name,t1,_stOP,_precision,_potencia,_pp,t2,_porcentaje,_defOR);
                poke->addMove(move);
            }
        }
        // Se introduce el pokemon en el equipo del entrenador
        equipo.push_back(poke);
    }
}

/* Destructor */
Entrenador::~Entrenador() {
    for (uint i = 0 ; i < equipo.size() ; i++) {
        delete equipo[i];
    }
}

/* Cargar nombre al entrenador */
void Entrenador::setNombre(std::string name) {
    nombre = name;
}

/* Recive el nombre del entrenador */
std::string Entrenador::getNombre(){
    return nombre;
}

/* Devuelve el número total de pokemons del entrenador */
uint Entrenador::getNumber() {
    return number;
}

/* Establece el número máximos de pokemons del entrenador */
void Entrenador::setNumber(uint _number) {
    number = _number;
}

/* Update del status (derrotado o no) del entrenador */
void Entrenador::updateStatus() {
    uint cuenta = 0;
    for (uint i = 0 ; i < number ; i++) {
        if(equipo[i]->getHP() > 0)
            cuenta++;
    }
    if (cuenta == 0)
        derrotado = true;
    else
        derrotado = false;
}

/* Devuelve el estado actual del entrenador */
bool Entrenador::checkStatus() {
    return derrotado;
}

/* Añade un pokemon al entrenador */
void Entrenador::addPokemon(Pokemon* _new) {
    if (equipo.size() < 6) {
        equipo.push_back(_new);
        number = equipo.size();
    } else {
        std::cout << "Numero maximo de pokemons.\n";
    }
}

/* Quita un pokemon al entrenador */
void Entrenador::removePokemon(int i) {
    Pokemon* poke = equipo[i];
    equipo.erase(equipo.begin() + i); // Se elimina la posición del vector
    number--;
    delete poke;
}

/* Devuelve un pokemon */
Pokemon* Entrenador::getPokemon(int i) {
    return equipo[i];
}

/* Devuelve el siguiente pokemon vivo */
Pokemon* Entrenador::getPokemon(){
    for (uint i = 0 ; i < number ; i++) {
        if(equipo[i]->getHP() > 0)
            return equipo[i];
    }
    return nullptr;
}

/* Genera un pokemon por defecto dentro de entrenador*/
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
    Pokemon* poke = new Pokemon("Charizard","FUEGO","VOLADOR",80,ivs,evs,base);
    equipo.push_back(poke);
    // Se generan los movimientos por defecto de Charyzard
    MovimientoEstado* mov1 = new MovimientoEstado("Inferno","FUEGO",1,50,100,5,"QUEMADO",100,1);
    MovimientoEstado* mov2 = new MovimientoEstado("Flare Blitz","FUEGO",0,100,120,15,"QUEMADO",10,0);
    Movimientos* mov3 = new Movimientos("Acrobatics","VOLADOR",0,100,55,15,0);
    Movimientos* mov4 = new Movimientos("Metal Claw","ACERO",0,95,50,35,0);
    poke->addMove(mov1);
    poke->addMove(mov2);
    poke->addMove(mov3);
    poke->addMove(mov4);
}
