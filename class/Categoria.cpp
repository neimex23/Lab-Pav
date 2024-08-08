#include "Categoria.h"

Categoria::Categoria(){}

Categoria::Categoria(string tipoGenero,string tipoPlataforma,string descripcion,int id){
    this->tipoGenero=tipoGenero;
    this->tipoPlataforma=tipoPlataforma;
    this->descripcion=descripcion;
    this->id=id;
}
void Categoria::setTipoGenero(string tipoGenero){
    this->tipoGenero=tipoGenero;
}
void Categoria::setTipoPlataforma (string tipoPlataforma){
    this->tipoPlataforma=tipoPlataforma;
}
string Categoria::getTipoGenero(){
    return this->tipoGenero;
}
string Categoria::getTipoPlataforma(){
    return this->tipoPlataforma;
}
string Categoria::getDescripcion(){
    return this->descripcion;
}
void Categoria::setId(int id){
    this->id=id;
}
int Categoria::getId(){
    return this->id;
}
Categoria::~Categoria(){}