#include "Fabrica.h"

#include "controllers/ControladorCategoria.h"
#include "controllers/ControladorUsuario.h"
#include "controllers/ControladorVideojuego.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica:: getInstancia(){
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}
IControladorUsuario* Fabrica::getIControladorUsuario(){
    return new ControladorUsuario();
}
IControladorCategoria* Fabrica::getIControladorCategoria(){
    return new ControladorCategoria();
}
IControladorVideojuego* Fabrica::getIControladorVideojuego(){
    return new ControladorVideojuego();
}
Fabrica::~Fabrica(){}