#ifndef PARTIDA_INDIVIDUAL
#define PARTIDA_INDIVIDUAL
#include "Partida.h"

class PartidaIndividual : public Partida{
    private:
        bool continuaPartidaAnterior;
    public:
        PartidaIndividual();
        PartidaIndividual(Jugador* jugador, DtFechaHora* fecha, int duracion,bool continuaPartidaAnterior);
        bool getContinuaPartidaAnterior();
        void setContinuaPartidaAnterior(bool continua);
        int darTotalHorasParticipantes();
        ~PartidaIndividual();
};

#endif