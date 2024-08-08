#include "ControladorCategoria.h"

void ControladorCategoria::datosCat(string tipoGenero, string tipoPlataforma, string descripcion)
{
    this->tipoGenero = tipoGenero;
    this->tipoPlataforma = tipoPlataforma;
    this->descripcion = descripcion;
}

void ControladorCategoria::agregarCategoria()
{
    ManejadorCategoria *aux = ManejadorCategoria::getInstancia();
    int id = aux->getCategorias().size();
    Categoria *create = new Categoria(this->tipoGenero, this->tipoPlataforma, this->descripcion, id);
    aux->agregarCategoria(create);
}

list<DtCategoria *> ControladorCategoria::getMapCat(){
    Sesion *s = Sesion::getInstancia();
    Usuario *u = s->getUsuario();
    if (u != 0){
            ManejadorCategoria *mc = ManejadorCategoria::getInstancia();
            list<DtCategoria *> listDtCategoria;
            list<Categoria *> listCat = mc->getCategorias();
            for (list<Categoria *>::iterator iter = listCat.begin(); iter != listCat.end(); iter++){
                listDtCategoria.push_back(new DtCategoria((*iter)->getTipoGenero(), (*iter)->getTipoPlataforma(), (*iter)->getDescripcion(), (*iter)->getId()));
            }
            return listDtCategoria;
    }else
        throw invalid_argument("Debes iniciar sesion primero");
}

DtCategoria *ControladorCategoria::buscarCat(int id)
{
    ManejadorCategoria *mc = ManejadorCategoria::getInstancia();
    Categoria *aux = mc->buscarCategoria(id);
    DtCategoria *dtAux = new DtCategoria(aux->getTipoGenero(), aux->getTipoPlataforma(), aux->getDescripcion(), aux->getId());
    return dtAux;
}

int ControladorCategoria::cantidadCategorias(){
    ManejadorCategoria* mc= ManejadorCategoria::getInstancia();
    return mc->getCategorias().size();
}

bool ControladorCategoria::isEmptyCat(){
    ManejadorCategoria* mc= ManejadorCategoria::getInstancia();
    return (mc->getCategorias().size()==0);
}

bool ControladorCategoria::existeCat(int id){
    ManejadorCategoria* mc= ManejadorCategoria::getInstancia();
    return mc->existeCategoria(id);
}

bool ControladorCategoria::existeCatGenPla(string tipoGenero,string tipoPlataforma){
    ManejadorCategoria* mc= ManejadorCategoria::getInstancia();
    list<Categoria*> listCat= mc->getCategorias();
    Categoria* aux;
    for(list<Categoria*>::iterator iter= listCat.begin(); iter!=listCat.end();++iter){
        aux=*iter;
        if (aux->getTipoGenero()==tipoGenero){
            if (aux->getTipoPlataforma()==tipoPlataforma){
                return true;
            }
        }
    }
    return false;
}