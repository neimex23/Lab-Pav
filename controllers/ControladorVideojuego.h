#ifndef CONTROLADORVIDEOJUEGO
#define CONTROLADORVIDEOJUEGO

#include "../interface/IControladorVideojuego.h"
#include "../dtFiles/DtJuego.h"
#include "../handlers/ManejadorVideojuego.h"
#include "../class/Usuario.h"
#include "../class/Juego.h"
#include "../class/Sesion.h"
#include "../dtFiles/DtJuego.h"
#include "../dtFiles/DtCategoria.h"
#include "../dtFiles/DtPartida.h"
#include "../dtFiles/DtPartidaIndividual.h"
#include "../dtFiles/DtPartidaMultijugador.h"
#include "../dtFiles/DtJugador.h"
#include "../class/Categoria.h"
#include "../class/Suscripcion.h"
#include "../class/Estadistica.h"
#include "../class/TipoPago.h"
#include "../class/Partida.h"
#include "../class/PartidaIndividual.h"
#include "../class/PartidaMultijugador.h"
#include <string>
#include <list>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <set>

using namespace std;

class ControladorVideojuego : public IControladorVideojuego {
    private:
        string nombre;
        TipoPago tipoPago;
        string descripcion;
        int puntaje;
        int totalHoras;
        int costo;
        bool transmitidaEnVivo;
        int cantJugadores;
        bool continuaPartidaAnterior;
        int duracion;
        int idCat;
        bool esPartidaIndividual;
        list<DtCategoria*> catAsociada;
        list<DtJuego*> listJuegos;
    public:
        void registrarVideojuego(string nombre,string descripcion,int costo,list<DtCategoria*> catAsociada);
        void altaVideojuego();
        void seleccionJuego(string nombre);
        void cancelarVideojuego();
        void eliminarVideojuego();
        void suscribirseAVideojuego();
        void iniciarPartida();
        void seleccionarTipoPago(TipoPago tipoPago);
        void seleccionarVideojuego(string nombreVideojuego);
        void asignarPuntaje();
        void datoPuntaje(int puntaje);
        DtJuegoFull* getVideojuegoFull(string nombreVideojuego);
        void datoIndividual(bool continuaPartida,int duracion);
        void datoMultijugador(bool transmitidaEnVivo,int cantJugadores,int duracion);
        map<string,list<DtJuego*> > listarVideojuegosXSuscripcion();
        list<DtJuego*> listarVideojuegosOrdenados(int);
        list<DtJuego*> verInformacionVideojuegos();
        DtFechaHora* takeTime();
        bool existeVideojuego(string nombre);
        bool isEmpty();
        bool containsList(list<DtJuego*> videojuegosList, string videojuego);
        list<string> listarVideojuegosDesarrollador();  
        list<DtJuego*> listarVideojuegos();
        bool jugadorPuntuo();
        bool isSub();
        list<DtPartida*> getDtPartidas();
        void datoId(int id);
        list<DtJuego*> buscarVideojuegoXCategoria();
};

#endif