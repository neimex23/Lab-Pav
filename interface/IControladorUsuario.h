#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO
#include<list>
#include<string>
#include"../dtFiles/DtUsuario.h"
#include"../class/Perfil.h"

using namespace std;

class IControladorUsuario {
    public:        
        virtual void altaUsuario()=0;
        virtual void datosComunes(string,string)=0;
        virtual void datosEmpresa(string)=0;
        virtual bool datosJugador(string,string)=0;
        virtual void cancelar()=0;
        virtual void iniciarSesion()=0;
        virtual void cerrarSesion()=0;
        virtual bool verificarContrasenia(string,string)=0;
        virtual bool ingresarDatos(string,string)=0;
        virtual Perfil getPerfil()=0;
        virtual bool existeUsuario(string email)=0;
        virtual Perfil getPerfilUsuarioLogueado()=0;
};
#endif
