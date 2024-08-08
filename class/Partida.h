#ifndef PARTIDA
#define PARTIDA
#include "Jugador.h"
#include "../dtFiles/DtFechaHora.h"

class Partida{
    protected:
        Jugador* jugador;
        DtFechaHora* fecha;
        int duracion;
        int identificador;
    public:
        Partida();//Preguntar si se hace constructor vacio siendo que multiplicidad de Jugador es 1
        Partida(Jugador* jugador, DtFechaHora* fecha, int duracion);
        Jugador* getJugador();
        DtFechaHora* getFechaHora();
        int getDuracion();
        void setJugador(Jugador* jugador);
        void setFechaHora(DtFechaHora* fecha);
        void setDuracion(int duracion);
        virtual int darTotalHorasParticipantes() = 0;
        virtual ~Partida();
};

#endif