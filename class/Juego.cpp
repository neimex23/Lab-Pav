 #include "Juego.h"

Juego::Juego(){}

Juego::Juego(string nombre,string descripcion, int costo,list<Categoria*> categoria,Desarrollador* dev){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->promedio=0;
    this->categorias=categoria;
    this->desarrollador=dev;
}

string Juego::getNombre(){
    return this->nombre;
}

list<Partida*> Juego::getPartidas(){
    return this->partidas;
}

void Juego::setNombre(string nombre){
    this->nombre=nombre;
}

void Juego::setPartidas(Partida* partida){
    this->partidas.push_back(partida);
}

void Juego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}
string Juego::getDescripcion(){
    return this->descripcion;
}

float Juego::getPromedio(){
    return this->promedio;
}
int Juego::getTotalHoras(){
    return this->totalHoras;
}
int Juego::getCosto(){
    return this->costo;
}
void Juego::setPromedio(float promedio){
    this->promedio=promedio;
}
void Juego::setTotalHoras(int duracion){
    this->totalHoras += duracion;
}
void Juego::setCosto(int costo){
    this->costo=costo;
}

list<Categoria*> Juego::getCategorias(){
    return this->categorias;
}
list<Estadistica*> Juego::getEstadisticas(){
    return this->estadisticas;
}
list<Suscripcion*> Juego::getSuscripciones(){
    return this->suscripciones;
}
Desarrollador* Juego::getDesarrollador(){
    return this->desarrollador;
}
void Juego::setCategorias(Categoria* categoria){
    this->categorias.push_back(categoria);
}
void Juego::setEstadisticas(Estadistica* estadistica){
    this->estadisticas.push_back(estadistica);
}
void Juego::setSuscripciones(Suscripcion* suscripcion){
    this->suscripciones.push_back(suscripcion);
}
void Juego::setDesarrollador(Desarrollador*desarrollador){
     this->desarrollador=desarrollador;
}

bool Juego::tieneSuscripcionActiva(Jugador* jugador){
    for (list<Suscripcion *>::iterator iter = suscripciones.begin(); iter != suscripciones.end(); iter++)
        if((*iter)->getJugador() != 0 &&(*iter)->getJugador()->getEmail()==jugador->getEmail())
            return true;
    return false;
}

Juego::~Juego(){
    while(this->suscripciones.size() != 0){
        list<Suscripcion*>::iterator iter = this->suscripciones.begin();
        this->suscripciones.erase(iter);
        (*iter)->~Suscripcion();
    }

    while(this->estadisticas.size() != 0){
        list<Estadistica*>::iterator iter = this->estadisticas.begin();
        this->estadisticas.erase(iter);
        (*iter)->~Estadistica();
    }
    while(this->partidas.size() != 0){
        list<Partida*>::iterator iter = this->partidas.begin();
        this->partidas.erase(iter);
        (*iter)->~Partida();
    }
         
}