#ifndef FABRICA
#define FABRICA

#include "interface/IControladorCategoria.h"
#include "interface/IControladorUsuario.h"
#include "interface/IControladorVideojuego.h"

class Fabrica {
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        IControladorUsuario* getIControladorUsuario();
        IControladorCategoria* getIControladorCategoria();
        IControladorVideojuego* getIControladorVideojuego();
        ~Fabrica();
};

#endif