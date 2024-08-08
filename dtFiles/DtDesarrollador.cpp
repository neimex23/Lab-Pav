#include "DtDesarrollador.h"

DtDesarrollador::DtDesarrollador(){}
DtDesarrollador::DtDesarrollador(string nombreEmpresa){
    this->nombreEmpresa=nombreEmpresa;
}
string DtDesarrollador::getNombreEmpresa(){
    return this->nombreEmpresa;
}
DtDesarrollador::~DtDesarrollador(){}