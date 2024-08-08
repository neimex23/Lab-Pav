#ifndef DTESTADISTICA
#define DTESTADISTICA
#include "DtJugador.h"

class DtEstadistica{
    private:
        int puntaje;
        DtJugador* jugador;
    public: 
        DtEstadistica();
        DtEstadistica(int puntaje, DtJugador* jugador);
        int getPuntaje();
        DtJugador* getJugador();
        ~DtEstadistica();
};
#endif