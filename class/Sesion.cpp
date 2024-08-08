#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

Sesion* Sesion::getInstancia(){
    if(instancia == NULL)
        instancia = new Sesion();
    return instancia;
}

Usuario* Sesion::getUsuario(){
    return this->usuario;
}

void Sesion::setUsuario(Usuario* usuario){
    this->usuario = usuario;
}