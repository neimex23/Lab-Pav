#ifndef SUSCRIPCION
#define SUSCRIPCION

#include <string>
#include "../dtFiles/DtFechaHora.h"
#include "TipoPago.h"
#include "Jugador.h"
using namespace std;

class Suscripcion{
    private:
        DtFechaHora* fechaHora;
        TipoPago tipoPago;
        Jugador* jugador;
    public: 
        Suscripcion();
        Suscripcion(DtFechaHora* fechaHora, TipoPago tipoPago,Jugador* jugador);
        DtFechaHora* getFechaHora();
        TipoPago getTipoPago();
        Jugador* getJugador();
        void setJugador(Jugador* jugador);
        void setFechaHora(DtFechaHora* fechaHora);
        void setTipoPago(TipoPago tipoPago);
        ~Suscripcion();
};
#endif