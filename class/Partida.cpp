#include "Partida.h"

Partida::Partida(){}

Partida::Partida(Jugador* jugador, DtFechaHora* fecha, int duracion){
    this->jugador=jugador;
    this->fecha=fecha;
    this->duracion=duracion;
}

Jugador* Partida::getJugador(){
    return this->jugador;
}

DtFechaHora* Partida::getFechaHora(){
    return this->fecha;
}

int Partida::getDuracion(){
    return this->duracion;
}

void Partida::setJugador(Jugador* jugador){
    this->jugador=jugador;    
}

void Partida::setFechaHora(DtFechaHora* fecha){
    this->fecha=fecha;
}

void Partida::setDuracion(int duracion){
    this->duracion=duracion;
}


Partida::~Partida(){}
