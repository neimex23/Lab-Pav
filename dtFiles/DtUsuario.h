#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include <iostream>
using namespace std;

class DtUsuario{
    private:
        string email;
        string contrasenia;
    public:
        DtUsuario();
        DtUsuario(string email, string contrasenia);
        string getEmail();
        string getContrasenia();
        virtual ~DtUsuario();
};

#endif