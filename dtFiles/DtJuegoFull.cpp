#include "DtJuegoFull.h"

DtJuegoFull::DtJuegoFull(){}
DtJuegoFull::DtJuegoFull(string nombre, string descripcion, DtDesarrollador* desarrollador, int costo,int totalHoras,float puntaje, list<DtCategoria*> listCat){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->desarrollador=desarrollador;
    this->costo=costo;
    this->puntaje=puntaje;
    this->totalHoras=totalHoras;
    this->listCat=listCat;
}
string DtJuegoFull::getNombre(){
    return this->nombre;
}
string DtJuegoFull::getDescripcion(){
    return this->descripcion;
}
DtDesarrollador* DtJuegoFull::getDesarrollador(){
    return this->desarrollador;
}
int DtJuegoFull::getCosto(){
    return this->costo;
}
int DtJuegoFull::getTotalHoras(){
    return this->totalHoras;
}

float DtJuegoFull::getPuntaje(){
    return this->puntaje;
}

list<DtCategoria*> DtJuegoFull::getListaCat(){
    return this->listCat;
}


ostream& operator<<(ostream& salida,DtJuegoFull &i){
    DtCategoria* aux;
    cout << "Nombre: " << i.nombre << "\nDescripcion: " << i.descripcion <<"\nNombre Empresa: " << i.desarrollador->getNombreEmpresa() <<endl;
    cout << "Costo: " << i.costo << "\nTotal de Horas: " << i.totalHoras << "\nPuntaje Promedio: " << i.puntaje <<endl;
    cout << "\n---Categorias---- \n" ;
    for (list<DtCategoria*>::iterator iter= i.listCat.begin(); iter!=i.listCat.end();++iter){
        aux=*iter;
        cout << *aux;
    }
    return salida;
}