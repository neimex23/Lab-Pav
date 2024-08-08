#ifndef JUEGO
#define JUEGO

#include <string>
#include <list>
#include "Partida.h"
#include "Categoria.h"
#include "Desarrollador.h"
#include "Estadistica.h"
#include "Suscripcion.h"
#include "map"

using namespace std;

class Juego{
    private:
        list<Categoria*> categorias;
        list<Partida*> partidas;
        list<Estadistica*> estadisticas;
        list<Suscripcion*> suscripciones;
        Desarrollador* desarrollador;
        string nombre;
        string descripcion;
        float promedio;
        int totalHoras;
        int costo;
    public: 
        Juego();
        Juego(string nombre,string descripcion, int costo,list<Categoria*> categoria,Desarrollador* dev);
        string getNombre();
        list<Partida*> getPartidas();
        string getDescripcion();
        float getPromedio();
        int getTotalHoras();
        int getCosto();
        void setNombre(string nombre);
        void setPartidas(Partida* partida);
        void setDescripcion(string descripcion);
        void setPromedio(float promedio);
        void setTotalHoras(int totalHoras);
        void setCosto(int costo);
        list<Categoria*> getCategorias();
        void setCategorias(Categoria*);
        list<Estadistica*> getEstadisticas();
        void setEstadisticas(Estadistica*);
        list<Suscripcion*> getSuscripciones();
        void setSuscripciones(Suscripcion*);
        Desarrollador* getDesarrollador();
        void setDesarrollador(Desarrollador*);
        bool tieneSuscripcionActiva(Jugador*);
        ~Juego();
};
#endif