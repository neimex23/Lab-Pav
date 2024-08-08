#include "DtSuscripcion.h"

DtSuscripcion::DtSuscripcion(){}

DtSuscripcion::DtSuscripcion(DtFechaHora* fechaHora, TipoPago tipoPago,DtJugador* jugador){
    this->fechaHora=fechaHora;
    this->tipoPago=tipoPago;
    this->jugador=jugador;
}

DtFechaHora* DtSuscripcion::getFechaHora(){
    return this->fechaHora;
}
        
TipoPago DtSuscripcion::getTipoPago(){
    return this->tipoPago;
}

        
DtSuscripcion::~DtSuscripcion(){}