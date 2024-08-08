#include "Estadistica.h"

Estadistica::Estadistica(){}
Estadistica::Estadistica(int puntaje, Jugador* jugador){
    this->puntaje=puntaje;
    this->jugador=jugador;
}
int Estadistica::getPuntaje(){
    return this->puntaje;
}
void Estadistica::setPuntaje(int puntaje){
    this->puntaje=puntaje;
}
void Estadistica::setJugador(Jugador* jugador){
    this->puntaje=puntaje;
}
Jugador* Estadistica::getJugador(){
    return this->jugador;
}
Estadistica::~Estadistica(){}