#include "DtUsuario.h"

DtUsuario::DtUsuario(){}
DtUsuario::DtUsuario(string email, string contrasenia){
    this->email=email;
    this->contrasenia=contrasenia;
}
string DtUsuario::getEmail(){
    return this->email;
}
string DtUsuario::getContrasenia(){
    return this->contrasenia;
}
DtUsuario::~DtUsuario(){}