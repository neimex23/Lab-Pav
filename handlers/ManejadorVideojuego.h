#ifndef MANEJADORVIDEOJUEGO
#define MANEJADORVIDEOJUEGO

#include "../class/Juego.h"
#include <map>
#include <string>
#include <list>

class ManejadorVideojuego{
  private:
    static ManejadorVideojuego* instancia;
    map<string,Juego*> videojuegos;
    ManejadorVideojuego();
  public:
    static ManejadorVideojuego* getInstancia();
    list<Juego*> getVideojuegos();
    Juego* buscarVideojuego(string videojuego);
    void agregarVideojuego(Juego* videojuego);
    bool existeVideojuego(string videojuego);
    void eliminarVideojuego(string videojuego);
    virtual ~ManejadorVideojuego();
};
#endif
