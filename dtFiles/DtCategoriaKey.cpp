#include "DtCategoriaKey.h"

DtCategoriaKey::DtCategoriaKey(){}

DtCategoriaKey::DtCategoriaKey(string genero,string plataforma){
    this->genero=genero;
    this->tipoPlataforma=plataforma;
}
string DtCategoriaKey::getGenero(){
    return this->genero;
}
string DtCategoriaKey::getTipoPlatoforma(){
    return this->tipoPlataforma;
}