#include "ManejadorCategoria.h"

ManejadorCategoria* ManejadorCategoria::instancia = NULL;

ManejadorCategoria::ManejadorCategoria(){}

ManejadorCategoria* ManejadorCategoria::getInstancia(){
    if (instancia==NULL){
        instancia= new ManejadorCategoria();
    }
    return instancia;
}

list<Categoria*> ManejadorCategoria::getCategorias(){
    list<Categoria*> listCat;
    for(map<int,Categoria*>::iterator iter=this->categorias.begin(); iter!=this->categorias.end();++iter){
        listCat.push_back(iter->second);
    }
    return listCat;
}


Categoria* ManejadorCategoria::buscarCategoria(int id){ 
    map<int,Categoria*>::iterator iter =this->categorias.find(id);
    return iter->second;
}

void ManejadorCategoria::agregarCategoria(Categoria* categoria){
    categorias.insert(pair<int,Categoria*>(categoria->getId(),categoria));
}

bool ManejadorCategoria::existeCategoria(int id){
    map<int,Categoria*>::iterator iter=this->categorias.find(id);
    return (iter != this->categorias.end());

}   
void ManejadorCategoria::eliminarCategoria(int id){
    map<int,Categoria*>::iterator iter=this->categorias.find(id);
    this->categorias.erase(iter,categorias.end());
}

ManejadorCategoria::~ManejadorCategoria(){}
