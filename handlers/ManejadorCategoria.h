#ifndef MANEJADORCATEGORIA
#define MANEJADORCATEGORIA

#include <map>
#include <list>
#include <string>
#include "../dtFiles/DtCategoriaKey.h"
#include "../dtFiles/DtCategoria.h"
#include "../class/Categoria.h"

using namespace std;

class ManejadorCategoria{
    private:
        ManejadorCategoria();
        static ManejadorCategoria* instancia;
        map<int,Categoria*> categorias;  
    public:
        static ManejadorCategoria* getInstancia();
        list<Categoria*> getCategorias();
        Categoria* buscarCategoria(int id);
        int cantidadCategorias();
        void agregarCategoria(Categoria*);
        bool existeCategoria(int id);
        void eliminarCategoria(int id);
        virtual ~ManejadorCategoria();
};

#endif