#ifndef DT_PARTIDA
#define DT_PARTIDA
#include "DtFechaHora.h"
#include "DtJugador.h"

class DtPartida{
    protected:
        DtJugador* jugador;
        DtFechaHora* fecha;
        int duracion;
    public:
        DtPartida();
        DtPartida(DtFechaHora* fecha,DtJugador* jugador, int duracion);
        DtFechaHora* getFecha();
        int getDuracion();
        DtJugador* getDtJugador();
        virtual ~DtPartida();
        friend ostream& operator<<(ostream& salida,DtPartida& partida);
};



#endif