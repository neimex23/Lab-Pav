#ifndef DT_PARTIDA_INDIVIDUAL
#define DT_PARTIDA_INDIVIDUAL

#include "DtPartida.h"

class DtPartidaIndividual : public DtPartida{
    private:
        bool continuaPartidaAnterior;
    public:
        DtPartidaIndividual();
        DtPartidaIndividual(DtFechaHora* fecha, int duracion, bool continuaPartidaAnterior);
        bool getContinuaPartidaAnterior();
        friend ostream& operator<<(ostream& salida,DtPartidaIndividual& partida);
        ~DtPartidaIndividual();
};
#endif