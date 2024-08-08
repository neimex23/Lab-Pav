#ifndef DTCATEGORIAKEY
#define DTCATEGORIAKEY
#include <string> 

using namespace std; 

class DtCategoriaKey{
    private:
        string genero;
        string tipoPlataforma;
    public:
        DtCategoriaKey();
        DtCategoriaKey(string genero,string plataforma);
        string getGenero();
        string getTipoPlatoforma();
        ~DtCategoriaKey();
};

#endif