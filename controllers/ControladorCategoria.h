#ifndef CONTROLADORCATEGORIA
#define CONTROLADORCATEGORIA

#include <string>
#include <iostream>
#include "../interface/IControladorCategoria.h"
#include "../handlers/ManejadorCategoria.h"
#include "../class/Categoria.h"
#include "../dtFiles/DtCategoria.h"
#include "../class/Sesion.h"
#include "../class/Desarrollador.h"
using namespace std;

class ControladorCategoria : public IControladorCategoria{
    private:
        string tipoGenero;
        string tipoPlataforma;
        string descripcion;
    public:
        void datosCat(string tipoGenero,string tipoPlataforma, string descripcion);
        DtCategoria* buscarCat(int id);
        list<DtCategoria*> getMapCat();
        int cantidadCategorias();
        bool isEmptyCat();
        void agregarCategoria();
        bool existeCat(int id);
        bool existeCatGenPla(string tipoGenero,string tipoPlataforma);
        
};

#endif