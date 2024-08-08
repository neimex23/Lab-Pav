#include "DtEstadistica.h"

DtEstadistica::DtEstadistica(){}
DtEstadistica::DtEstadistica(int puntaje, DtJugador* jugador){
    this->puntaje=puntaje;
    this->jugador=jugador;
}
int DtEstadistica::getPuntaje(){
    return this->puntaje;
}

DtJugador* DtEstadistica::getJugador(){
    return this->jugador;
}
DtEstadistica::~DtEstadistica(){}