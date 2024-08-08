#ifndef DTDESARROLLADOR
#define DTDESARROLLADOR
#include "DtUsuario.h"
#include <string>
#include <iostream>
using namespace std;

class DtDesarrollador: public DtUsuario{
    private:
        string nombreEmpresa ;
    public:
        DtDesarrollador();
        DtDesarrollador(string nombreEmpresa);
        string getNombreEmpresa();
        ~DtDesarrollador();
};

#endif