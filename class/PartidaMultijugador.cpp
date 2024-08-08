#include "PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(){}

PartidaMultijugador::PartidaMultijugador(Jugador* jugador, DtFechaHora* fecha, int duracion, bool transmitidaEnVivo, int cantJugadores):Partida(jugador,fecha,duracion){
    this->transmitidaEnVivo=transmitidaEnVivo;
    this->cantJugadores=cantJugadores;
}

bool PartidaMultijugador::getTransmitidaEnVivo(){
    return transmitidaEnVivo;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool transmitidaEnVivo){
    this->transmitidaEnVivo=transmitidaEnVivo;
}

int PartidaMultijugador::getCantJugadores(){
    return this->cantJugadores;
}

void PartidaMultijugador::setCantJugadores(int cantJugadores){
    this->cantJugadores = cantJugadores;
}

int PartidaMultijugador::darTotalHorasParticipantes(){
    return this->duracion*this->cantJugadores;
}

PartidaMultijugador::~PartidaMultijugador(){}