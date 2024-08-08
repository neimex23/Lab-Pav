#ifndef DT_CATEGORIA
#define DT_CATEGORIA

#include <string>
#include <iostream>
#include <list>
using namespace std;

class DtCategoria{
    private:
        int id;
        string tipoGenero;
        string tipoPlataforma;
        string descripcion;
    public:
        DtCategoria();
        DtCategoria(string tipoGenero,string tipoPlataforma,string descripcion,int id);
        string getTipoGenero();
        string getTipoPlataforma();
        string getDescripcion();
        int getId();
        friend ostream& operator<<(ostream& salida,DtCategoria &cat);
        ~DtCategoria();
};

#endif