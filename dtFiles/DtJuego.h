#ifndef DTJUEGO
#define DTJUEGO
#include <string>
#include <list>

#include <iostream>
#include "DtCategoria.h"
#include "DtPartida.h"
#include "DtDesarrollador.h"
#include "DtEstadistica.h"
#include "DtSuscripcion.h"
using namespace std;
#define MAX_PART 20

class DtJuego{
    private:
        list<DtCategoria*> categorias;
        DtPartida* partidas[MAX_PART];
        int numPartidas;
        list<DtEstadistica*> estadisticas;
        list<DtSuscripcion*> suscripciones;
        DtDesarrollador* desarrollador;
        string nombre;
        string descripcion;
        int puntaje;
        float promedio;
        int totalHoras;
        int costo;
    public: 
        DtJuego();
        DtJuego(string nombre,string descripcion, int costo);
        DtJuego(string nombre,string descripcion, float promedio, int totalHoras);
        DtJuego(string nombre,string descripcion);
        DtJuego(string nombre,int costo, list<DtSuscripcion*> suscripciones);
        DtJuego(string nombre,int costo);
        string getNombre();
        int getNumPartidas();
        DtPartida** getPartidas();
        string getDescripcion();
        int getPuntuaje();
        int getTotalHoras();
        int getCosto();
        float getPromedio();
        list<DtCategoria*> getCategorias();
        list<DtEstadistica*> getEstadisticas();
        list<DtSuscripcion*> getSuscripciones();
        DtDesarrollador* getDesarrollador();
        friend ostream& operator<<(ostream&, DtJuego&);
        ~DtJuego();
};
#endif