#include "Jugador.h"

Jugador::Jugador(){}

Jugador::Jugador(string nickname, string descripcion,string email, string password):Usuario(email,password){
    this->nickname=nickname;
    this->descripcion=descripcion;
}

string Jugador::getNickname(){
    return this->nickname;
}

string Jugador::getDescripcion(){
    return this->descripcion;
}

void Jugador::setNickname(string nickname){
    this->nickname=nickname;
}

void Jugador::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

Jugador::~Jugador(){}
