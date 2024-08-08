#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "../class/Usuario.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorUsuario{
    private:
        ManejadorUsuario();
        static ManejadorUsuario* instancia;
        map<string,Usuario*> usuarios;
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        Usuario* buscarUsuario(string);
        void agregarUsuario(Usuario*);
        bool existeUsuario(string);
        void eliminarUsuario(string);
        virtual ~ManejadorUsuario();
};
#endif
