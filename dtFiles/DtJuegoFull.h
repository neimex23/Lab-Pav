#ifndef DTJUEGOFULL
#define DTJUEGOFULL
#include "DtJuego.h"
#include "DtCategoria.h"

class DtJuegoFull : public DtJuego{
    private:
        string nombre;
        string descripcion;
        DtDesarrollador* desarrollador;
        float puntaje;
        int costo;
        int totalHoras;
        list<DtCategoria*> listCat;
    public:
        DtJuegoFull();
        DtJuegoFull(string nombre, string descripcion, DtDesarrollador* desarrollador, int costo,int totalHoras, float puntaje, list<DtCategoria*> listCat);
        string getNombre();
        string getDescripcion();
        DtDesarrollador* getDesarrollador();
        int getCosto();
        int getTotalHoras();
        float getPuntaje();
        list<DtCategoria*> getListaCat();
        friend ostream& operator<<(ostream&,DtJuegoFull&);
};

#endif