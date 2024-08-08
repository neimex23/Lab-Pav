#ifndef DTSUSCRIPCION
#define DTSUSCRIPCION

#include <string>
#include "DtFechaHora.h"
#include "DtJugador.h"
#include "../class/TipoPago.h"
using namespace std;

class DtSuscripcion{
    private:
        DtFechaHora* fechaHora;
        TipoPago tipoPago;
        DtJugador* jugador;
    public: 
        DtSuscripcion();
        DtSuscripcion(DtFechaHora* fechaHora, TipoPago tipoPago, DtJugador* jugador);
        DtFechaHora* getFechaHora();
        TipoPago getTipoPago();
        ~DtSuscripcion();
};
#endif