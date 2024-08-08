#ifndef DT_PARTIDA_MULTIJUGADOR
#define DT_PARTIDA_MULTIJUGADOR
#include "DtPartida.h"

class DtPartidaMultijugador : public DtPartida{
    private:
        bool transmitidaEnVivo;
        int cantJugadores;
    public:
        DtPartidaMultijugador();
        DtPartidaMultijugador(DtFechaHora* fecha, int duracion,bool transmitidaEnVivo,int cantJugadores);
        bool getTransmitidaEnVivo();
        int getCantJugadores();
        friend ostream& operator<<(ostream& salida,DtPartidaMultijugador& partida);
        ~DtPartidaMultijugador();
};
#endif