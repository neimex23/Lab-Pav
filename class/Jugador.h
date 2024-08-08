#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <iostream>
#include "Usuario.h"
using namespace std;

class Jugador: public Usuario{
    private:
        string nickname;
        string descripcion;
    public: 
        Jugador();
        Jugador(string nickname, string descripcion,string email,string contrasenia);
        string getNickname();
        string getDescripcion();
        void setNickname(string nickname);
        void setDescripcion(string descripcion);
        ~Jugador();
};

#endif