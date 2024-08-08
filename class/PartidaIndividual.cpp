#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(){}

PartidaIndividual::PartidaIndividual(Jugador* jugador, DtFechaHora* fecha, int duracion, bool continuaPartidaAnterior):Partida(jugador,fecha,duracion){
    this->continuaPartidaAnterior=continuaPartidaAnterior;
}

bool PartidaIndividual::getContinuaPartidaAnterior(){
    return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool continuaPartidaAnterior){
    this->continuaPartidaAnterior=continuaPartidaAnterior;
}

int PartidaIndividual::darTotalHorasParticipantes(){
    return this->duracion;
}

PartidaIndividual::~PartidaIndividual(){}