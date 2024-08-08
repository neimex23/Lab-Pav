#include "ControladorUsuario.h"

ControladorUsuario::ControladorUsuario(){}

ControladorUsuario::ControladorUsuario(string email,string contrasenia, string empNom,string nickname,string descripcion){
    this->email = email;
    this->contrasenia=contrasenia;
    this->empNom = empNom;
    this->nickname = nickname;
    this->descripcion = descripcion;
}

void ControladorUsuario::datosComunes(string email, string contrasenia){
    this->email = email;
    this->contrasenia = contrasenia;
}

void ControladorUsuario::datosEmpresa(string nomEmp){
    this->empNom = nomEmp;
    this->perfil = DESARROLLADOR;
}

Perfil ControladorUsuario::getPerfil(){
    return this->perfil;
}

void ControladorUsuario::cancelar(){}

bool ControladorUsuario::datosJugador(string nickname, string descripcion){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    list<Usuario*> usuarios=mu->getUsuarios();
    if(mu->existeUsuario(this->email))
        return true;
    else{
        for (list<Usuario*>::iterator iter = usuarios.begin(); iter != usuarios.end(); iter++){
            if(Jugador* jugador = dynamic_cast<Jugador*>((*iter)))
                if(jugador->getNickname()==nickname)
                    throw invalid_argument("Ya existe un jugador con este nickname");
        }
        this->nickname = nickname;
        this->descripcion = descripcion;
        this->perfil=JUGADOR;
        return false;
    }
}

void ControladorUsuario::iniciarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if(mu->existeUsuario(this->email)){ 
        Usuario* u= mu->buscarUsuario(this->email);
        if(verificarContrasenia(this->contrasenia,u->getContrasenia())) {
            sesion->setUsuario(u);
        } else
            throw invalid_argument("Email o contrasenia incorrectos");
    }else
        throw invalid_argument("Email o contrasenia incorrectos");  
}

void ControladorUsuario::cerrarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    sesion->setUsuario(NULL);
}

void ControladorUsuario::altaUsuario(){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if(this->perfil == DESARROLLADOR){ 
        Desarrollador* dev = new Desarrollador(this->empNom, this->email, this->contrasenia);
        mu->agregarUsuario(dev);
    }else{
        Jugador* jug = new Jugador(this->nickname, this->descripcion,this->email, this->contrasenia);
        mu->agregarUsuario(jug);
    }
}

bool ControladorUsuario::ingresarDatos(string email,string pass){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    if(mu->existeUsuario(email)){
        Usuario* u= mu->buscarUsuario(email);
        if (verificarContrasenia(pass,u->getContrasenia())){
            datosComunes(email,pass);
            return true;
        }else
            return false;
    }else
        return false;
}

bool ControladorUsuario::verificarContrasenia(string userPass,string originalPassword){
    return userPass.compare(originalPassword)==0;
}

bool ControladorUsuario::existeUsuario(string email){
    ManejadorUsuario* mc= ManejadorUsuario::getInstancia();
    return mc->existeUsuario(email);
}

Perfil ControladorUsuario::getPerfilUsuarioLogueado(){
    Sesion* s = Sesion::getInstancia();
    Usuario* u = s->getUsuario();
    if(dynamic_cast<Desarrollador *>(u))
        return DESARROLLADOR;
    else if(dynamic_cast<Jugador*>(u))
        return JUGADOR;
    return USUARIO;
}