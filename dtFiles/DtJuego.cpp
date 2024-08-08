#include "DtJuego.h"

DtJuego::DtJuego(){}

DtJuego::DtJuego(string nombre,string descripcion, int costo){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->numPartidas=0;
    this->puntaje=0;
}

DtJuego::DtJuego(string nombre,string descripcion){
    this->nombre=nombre;
    this->descripcion=descripcion;
}

DtJuego::DtJuego(string nombre,int costo, list<DtSuscripcion*> suscripciones){
    this->nombre=nombre;
    this->costo=costo;
    this->suscripciones=suscripciones;
}
DtJuego::DtJuego(string nombre,int costo){
    this->nombre=nombre;
    this->costo=costo;
}

DtJuego::DtJuego(string nombre,string descripcion, float promedio, int totalHoras){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->promedio=promedio;
    this->totalHoras=totalHoras;   
}

string DtJuego::getNombre(){
    return this->nombre;
}

DtPartida** DtJuego::getPartidas(){
    return this->partidas;
}

int DtJuego::getNumPartidas(){
    return this->numPartidas;
}

string DtJuego::getDescripcion(){
    return this->descripcion;
}

int DtJuego::getPuntuaje(){
    return this->puntaje;
}
int DtJuego::getTotalHoras(){
    return this->totalHoras;
}
int DtJuego::getCosto(){
    return this->costo;
}

float DtJuego::getPromedio(){
    return this->promedio;
}

list<DtCategoria*> DtJuego::getCategorias(){
    return this->categorias;
}
list<DtEstadistica*> DtJuego::getEstadisticas(){
    return this->estadisticas;
}
list<DtSuscripcion*> DtJuego::getSuscripciones(){
    return this->suscripciones;
}
DtDesarrollador* DtJuego::getDesarrollador(){
    return this->desarrollador;
}

ostream& operator<<(ostream& salida,DtJuego &juego){
    cout << "Nombre: " << juego.nombre << " Costo: U$S" << juego.costo << endl;
    return salida;
}



DtJuego::~DtJuego(){}