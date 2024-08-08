#include "Desarrollador.h"

Desarrollador::Desarrollador(){}
Desarrollador::Desarrollador(string nombreEmpresa,string email,string password): Usuario (email,password){
    this->nombreEmpresa=nombreEmpresa;
}
void Desarrollador::setNombreEmpresa(string nombreEmpresa){
    this->nombreEmpresa=nombreEmpresa;
}
string Desarrollador::getNombreEmpresa(){
    return this->nombreEmpresa;
}
Desarrollador::~Desarrollador(){}