#ifndef DT_FECHA_HORA
#define DT_FECHA_HORA

#include <iostream>
using namespace std;

class DtFechaHora{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int minuto;
    public:
        DtFechaHora();
        DtFechaHora(int dia, int mes, int anio, int hora, int minuto);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
        friend ostream& operator<<(ostream& salida,DtFechaHora& partida);
        ~DtFechaHora();
};

#endif