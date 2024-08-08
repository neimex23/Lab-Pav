#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include "../interface/IControladorUsuario.h"
#include "../class/Usuario.h"
#include "../handlers/ManejadorUsuario.h"
#include "../class/Desarrollador.h"
#include "../class/Jugador.h"
#include "../class/Sesion.h"
#include "../class/Perfil.h"
#include <string>

using namespace std;

class ControladorUsuario : public IControladorUsuario {
    private:
        string email;
        string contrasenia;
        string empNom;
        string nickname;
        string descripcion;
        Perfil perfil;
    public:
        ControladorUsuario();
        ControladorUsuario(string, string, string, string, string);
        void datosComunes(string,string);
        void datosEmpresa(string);
        void cancelar();
        void altaUsuario();
        void iniciarSesion();
        void cerrarSesion();
        bool verificarContrasenia(string,string);
        bool datosJugador(string,string);
        bool ingresarDatos(string,string);
        Perfil getPerfil();
        bool existeUsuario(string email);
        Perfil getPerfilUsuarioLogueado();
};
#endif


