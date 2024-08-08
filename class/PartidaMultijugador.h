#ifndef PARTIDA_MULTIJUGADOR
#define PARTIDA_MULTIJUGADOR
#include "Partida.h"

class PartidaMultijugador : public Partida{
    private:
        bool transmitidaEnVivo;
        int cantJugadores;
    public: 
        PartidaMultijugador();
        PartidaMultijugador(Jugador* jugador, DtFechaHora* fecha, int duracion, bool transmitidaEnVivo, int cantJugadores);
        bool getTransmitidaEnVivo();
        void setTransmitidaEnVivo(bool transmitidaEnVivo);
        int getCantJugadores();
        void setCantJugadores(int cantJugadores);
        int darTotalHorasParticipantes();
        ~PartidaMultijugador();
};
#endif