#include "Usuario.h"

  Usuario::Usuario(){}
  Usuario::Usuario(string email, string contrasenia){
      this->email=email;
      this->contrasenia=contrasenia;
  }
  void Usuario::setEmail(string email){
      this->email=email;
  }
  void Usuario::setContrasenia(string contrasenia){
      this->contrasenia=contrasenia;
  }

  string Usuario::getEmail(){
      return this->email;
  }
  string Usuario::getContrasenia(){
      return this->contrasenia;
  }

  Usuario::~Usuario(){}