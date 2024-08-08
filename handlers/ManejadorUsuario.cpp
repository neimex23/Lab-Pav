#include "ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if(instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}

list<Usuario*> ManejadorUsuario::getUsuarios(){
    list<Usuario*> lstUsuarios;
    for(map<string,Usuario*>::iterator iter = this->usuarios.begin(); iter!=this->usuarios.end(); ++iter)
        lstUsuarios.push_back(iter->second);
    return lstUsuarios;
}

Usuario* ManejadorUsuario::buscarUsuario(string usuario){
    map<string,Usuario*>::iterator iter = this->usuarios.find(usuario);
    return iter->second;
}

void ManejadorUsuario::agregarUsuario(Usuario* usuario){
     usuarios.insert(std::pair<string,Usuario*>(usuario->getEmail(),usuario));
}

bool ManejadorUsuario::existeUsuario(string email){
    map<string,Usuario*>::iterator iter = this->usuarios.find(email);
    return (iter != this->usuarios.end());
}

void ManejadorUsuario::eliminarUsuario(string email){
    map<string,Usuario*>::iterator iter = this->usuarios.find(email);
    this->usuarios.erase(iter,usuarios.end());
}

ManejadorUsuario::~ManejadorUsuario(){}