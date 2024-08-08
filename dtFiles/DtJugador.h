#ifndef DTJUGADOR
#define DTJUGADOR
#include <string>
#include <iostream>
using namespace std;
#include "DtUsuario.h"

class DtJugador: public DtUsuario{
    private:
        string nickname;
        string descripcion;
    public:
        DtJugador();
        DtJugador(string email,string contrasenia,string nickname, string descripcion);
        string getNickname();
        string getDescripcion();
        string toString();
        ~DtJugador();

        friend ostream& operator<<(ostream&,DtJugador&);
}
;

#endif