#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <string>
#include <iostream>

using namespace std;
#include "Usuario.h"

class Desarrollador: public Usuario{
    private:
        string nombreEmpresa ;
    public:
        Desarrollador();
        Desarrollador(string nombreEmpresa,string email, string password);
        void setNombreEmpresa(string nombreEmpresa);
        string getNombreEmpresa();
        ~Desarrollador();
};

#endif