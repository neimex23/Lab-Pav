 #include "Suscripcion.h"

Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(DtFechaHora* fechaHora, TipoPago tipoPago, Jugador* jugador){
    this->fechaHora=fechaHora;
    this->tipoPago=tipoPago;
    this->jugador=jugador;
}

Jugador* Suscripcion::getJugador(){
    return this->jugador;
}

DtFechaHora* Suscripcion::getFechaHora(){
    return this->fechaHora;
}
        
TipoPago Suscripcion::getTipoPago(){
    return this->tipoPago;
}


        
void Suscripcion::setJugador(Jugador* jugador){
    this->jugador=jugador;
}

void Suscripcion::setFechaHora(DtFechaHora* fechaHora){
    this->fechaHora=fechaHora;
}

void Suscripcion::setTipoPago(TipoPago tipoPago){
    this->tipoPago=tipoPago;
}


Suscripcion::~Suscripcion(){}