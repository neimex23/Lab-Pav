#include "DtPartidaIndividual.h"

DtPartidaIndividual::DtPartidaIndividual(){}

DtPartidaIndividual::DtPartidaIndividual(DtFechaHora* fecha, int duracion,bool continuaPartidaAnterior):DtPartida(fecha,jugador,duracion){
    this->continuaPartidaAnterior=continuaPartidaAnterior;
}

bool DtPartidaIndividual::getContinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;
}

ostream& operator<<(ostream& salida,DtPartidaIndividual& pi){
    string contPartAnt = pi.continuaPartidaAnterior==true ? "Si" : "No"; 
    salida << (DtPartida&) pi << "Continuar partida anterior: " << contPartAnt << "\n";
    return salida;
}

DtPartidaIndividual::~DtPartidaIndividual(){}