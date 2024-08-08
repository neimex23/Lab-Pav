#include "DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(){}

DtPartidaMultijugador::DtPartidaMultijugador(DtFechaHora* fecha, int duracion,bool transmitidaEnVivo, int cantJugadores):DtPartida(fecha,jugador,duracion){
    this->transmitidaEnVivo=transmitidaEnVivo;
    this->cantJugadores=cantJugadores;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return this->transmitidaEnVivo;
}

int DtPartidaMultijugador::getCantJugadores(){
    return this->cantJugadores;
}

ostream& operator<<(ostream& salida,DtPartidaMultijugador& pm){
    string transEnVivo = pm.transmitidaEnVivo==true ? "Si" : "No";
    salida << (DtPartida&) pm << "Transmitida en vivo: " << transEnVivo << "\nCantidad de jugadores:" << pm.cantJugadores;
    return salida;
}


DtPartidaMultijugador::~DtPartidaMultijugador(){}