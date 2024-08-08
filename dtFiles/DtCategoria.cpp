#include "DtCategoria.h"

DtCategoria::DtCategoria(){}

DtCategoria::DtCategoria(string tipoGenero,string tipoPlataforma,string descripcion,int id){
    this->tipoGenero=tipoGenero;
    this->tipoPlataforma=tipoPlataforma;
    this->descripcion=descripcion;
    this->id = id;
}

string DtCategoria::getTipoGenero(){
    return this->tipoGenero;
}
string DtCategoria::getTipoPlataforma(){
    return this->tipoPlataforma;
}
string DtCategoria::getDescripcion(){
    return this->descripcion;
}

int DtCategoria::getId(){
    return this->id;
}

ostream& operator<<(ostream& salida,DtCategoria &cat){
    cout << cat.id << ". "<< cat.tipoGenero << " - " << cat.tipoPlataforma << endl;
    return salida;
}

DtCategoria::~DtCategoria(){}