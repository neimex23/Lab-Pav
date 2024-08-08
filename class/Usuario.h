#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
using namespace std;

class Usuario{
    private: 
        string email;
        string contrasenia;
    public:
        Usuario();
        Usuario(string email, string contrasenia);
        void setEmail(string email);
        void setContrasenia(string contrasenia);
        string getEmail();
        string getContrasenia();
        virtual ~Usuario();
};

#endif
