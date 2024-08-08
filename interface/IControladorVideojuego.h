#ifndef ICONTROLADORVIDEOJUEGO
#define ICONTROLADORVIDEOJUEGO

#include <list>
#include <string>
#include <map>
#include "../dtFiles/DtJuego.h"
#include "../dtFiles/DtJuegoFull.h"
#include "../class/Categoria.h"
using namespace std;

class IControladorVideojuego{
    public:
        virtual void registrarVideojuego(string nombre,string descripcion,int costo,list<DtCategoria*> catAsociada)=0;
        virtual void altaVideojuego()=0;
        virtual void seleccionJuego(string nombre)=0;
        virtual void cancelarVideojuego()=0;
        virtual void eliminarVideojuego()=0;
        virtual void suscribirseAVideojuego()=0;
        virtual void iniciarPartida()=0;
        virtual void seleccionarTipoPago(TipoPago tipoPago)=0;
        virtual void seleccionarVideojuego(string nombreVideojuego)=0;
        virtual void datoIndividual(bool continuaPartida,int duracion)=0;
        virtual void datoMultijugador(bool transmitidaEnVivo,int cantJugadores,int duracion)=0;
        virtual void asignarPuntaje()=0;
        virtual bool isEmpty()=0;
        virtual void datoPuntaje(int puntaje)=0;
        virtual void datoId(int id)=0;
        virtual list<DtJuego*> buscarVideojuegoXCategoria()=0;
        virtual list<string> listarVideojuegosDesarrollador()=0;
        virtual list<DtJuego*> listarVideojuegos()=0;
        virtual map<string,list<DtJuego*> > listarVideojuegosXSuscripcion()=0;
        virtual list<DtJuego*> verInformacionVideojuegos()=0;
        virtual DtFechaHora* takeTime()=0;
        virtual bool existeVideojuego(string nombre)=0;
        virtual DtJuegoFull* getVideojuegoFull(string nombreVideojuego)=0;
        virtual bool jugadorPuntuo()=0;
        virtual bool isSub()=0;
        virtual list<DtJuego*> listarVideojuegosOrdenados(int)=0;
        virtual list<DtPartida*> getDtPartidas()=0;
        
};
#endif
