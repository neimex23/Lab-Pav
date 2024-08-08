#ifndef ICONTROLADORCATEGORIA
#define ICONTROLADORCATEGORIA
#include<string>
#include<map>
#include "../dtFiles/DtCategoria.h"
#include <list>
using namespace std;

class IControladorCategoria {
    public:        
        virtual void datosCat(string tipoGenero,string tipoPlataforma, string descripcion)=0;
        virtual list<DtCategoria*> getMapCat()=0;
        virtual void agregarCategoria()=0;
        virtual DtCategoria* buscarCat(int id)=0;
        virtual bool existeCat(int id)=0;
        virtual int cantidadCategorias()=0;
        virtual bool isEmptyCat()=0;
        virtual bool existeCatGenPla(string tipoGenero,string tipoPlataforma)=0;
};

#endif