#ifndef SESION
#define SESION
#include "Usuario.h"

class Sesion{
    private:
        Sesion();
        static Sesion* instancia;
        Usuario* usuario;
    public:
        static Sesion* getInstancia();
        Usuario* getUsuario();
        void setUsuario(Usuario* usuario);
};
#endif