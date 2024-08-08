#include "DtJugador.h"

DtJugador::DtJugador(){}

DtJugador::DtJugador(string email,string contrasenia,string nickname, string descripcion):DtUsuario(email,contrasenia){
    this->nickname=nickname;
    this->descripcion=descripcion;
}

string DtJugador::getNickname(){
    return this->nickname;
}

string DtJugador::getDescripcion(){
    return this->descripcion;
}

string DtJugador::toString(){
    return "\nNickname: " + this->nickname ;
}

DtJugador::~DtJugador(){}

ostream& operator<<(ostream& salida,DtJugador& jugador){
  cout << "Jugador: " << jugador.nickname << "\n" << "Edad: " << jugador.descripcion <<endl;
  return salida;
}
