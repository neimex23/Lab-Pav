#ifndef SISTEMA
#define SISTEMA

#include "Juego.h"
#include "Jugador.h"
#include "DtJugador.h"
#include "DtJuego.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "DtFechaHora.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <stdio.h>
#include <time.h>

using namespace std;

//Variables
#define MAX_VIDEOJUEGOS 50
#define MAX_JUGADORES 50
#define MAX_PARTIDAS 50

class Sistema{
    public: 
        Sistema();
        Juego* juegos[MAX_VIDEOJUEGOS];
        int cantJuegos;
        Jugador* personas[MAX_JUGADORES];
        int cantPersonas;

        void agregarJugador(string nickname, int edad, string password);
        void agregarJuego(string name, TipoGenero genero);
        DtJugador** obtenerJugadores(int& cantJugadores);
        DtJuego** obtenerVideojuegos(int& cantJuegos);
        DtPartida** obtenerPartidas(string videojuego,int& cantPartidas);
        void iniciarPartida(string nickname,string videojuego,DtPartida* datos);
        bool existeJugador(string nickname);
        bool existeJuego(string nombre);
        Jugador* obtenerJugador(string nickname);
        Juego* obtenerVideojuego(string videoJuego);
        DtPartida* crearDatosPartida(string videojuego, string nickname);
        void agregarPartidaIndividual(Jugador* jugador, string nombreJuego);
        TipoGenero tomarGenero(int genero);
        DtFechaHora takeTime();
        void imprimirDtPartida(DtPartida* dtPartida);

        void ingresarJugadoresPorDefecto();
        void ingresarVideoJuegosPorDefecto();
        void ingresarPartidasPorDefecto();
        void validarInt(string text, int &retorno);
};

#endif