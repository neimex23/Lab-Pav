#ifndef ESTADISTICA
#define ESTADISTICA

#include "Jugador.h"

class Estadistica{
    private:
        int puntaje;
        Jugador* jugador;
    public: 
        Estadistica();
        Estadistica(int puntaje, Jugador* jugador);
        int getPuntaje();
        void setPuntaje(int puntaje);
        Jugador* getJugador();
        void setJugador(Jugador* jugador);
        ~Estadistica();
};
#endif