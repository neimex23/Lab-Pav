#ifndef CATEGORIA
#define CATEGORIA
#include <string>
#include <iostream>
using namespace std;

class Categoria{
    private:
        int id;
        string tipoGenero;
        string tipoPlataforma;
        string descripcion;
    public:
        Categoria();
        Categoria(string tipoGenero,string tipoPlataforma,string descripcion,int id);
        void setId(int id);
        void setTipoGenero(string tipoGenero);
        void setTipoPlataforma (string tipoPlataforma);
        void setDescripcion (string descripcion);
        int getId();
        string getTipoGenero();
        string getTipoPlataforma();
        string getDescripcion();
        ~Categoria();
};

#endif