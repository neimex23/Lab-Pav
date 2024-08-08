#include "DtPartida.h"

DtPartida::DtPartida(){}

DtPartida::DtPartida(DtFechaHora* fecha,DtJugador* jugador, int duracion){
    this->fecha=fecha;
    this->duracion=duracion;
    this->jugador=jugador;

}

DtFechaHora* DtPartida::getFecha(){
    return this->fecha;
}

int DtPartida::getDuracion(){
    return this->duracion;
}


DtJugador* DtPartida::getDtJugador(){
    return this->jugador;
}

ostream& operator<<(ostream& salida,DtPartida& partida){
    DtFechaHora* fecha= partida.fecha;
    cout << "\nFecha: " << *fecha << "\nDuracion:"<< partida.duracion << endl;


    return salida;
}

DtPartida::~DtPartida(){}