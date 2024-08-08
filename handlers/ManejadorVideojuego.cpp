#include "ManejadorVideojuego.h"

ManejadorVideojuego* ManejadorVideojuego::instancia = NULL;

ManejadorVideojuego::ManejadorVideojuego(){}

ManejadorVideojuego* ManejadorVideojuego::getInstancia(){
  if (instancia == NULL) 
    instancia = new ManejadorVideojuego();
  return instancia;
}

list<Juego*> ManejadorVideojuego::getVideojuegos(){
    list<Juego*> videojuegos;
    for (map<string,Juego*>::iterator it = this->videojuegos.begin(); it != this->videojuegos.end(); ++it)
        videojuegos.push_back(it->second);
    return videojuegos;
}

Juego* ManejadorVideojuego::buscarVideojuego(string videojuego){
    map<string,Juego*>::iterator it = this->videojuegos.find(videojuego);
    return it->second;
}

void ManejadorVideojuego::agregarVideojuego(Juego* videojuego){
    videojuegos.insert(std::pair<string,Juego*>(videojuego->getNombre(), videojuego));
}

bool ManejadorVideojuego::existeVideojuego(string videojuego){
    map<string,Juego*>::iterator it = this->videojuegos.find(videojuego);
    return (it != this->videojuegos.end());
}

void ManejadorVideojuego::eliminarVideojuego(string videojuego){
    map<string,Juego*>::iterator it = this->videojuegos.find(videojuego);
    this->videojuegos.erase(it);
}

ManejadorVideojuego::~ManejadorVideojuego(){}
