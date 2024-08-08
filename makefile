principal: main.o Color.o Categoria.o Desarrollador.o Juego.o Estadistica.o Fabrica.o Jugador.o Partida.o PartidaIndividual.o PartidaMultijugador.o Sesion.o Suscripcion.o Usuario.o ControladorCategoria.o ControladorUsuario.o ControladorVideojuego.o ManejadorCategoria.o ManejadorUsuario.o ManejadorVideojuego.o DtJuegoFull.o DtCategoria.o DtCategoriaKey.o DtDesarrollador.o DtEstadistica.o DtFechaHora.o DtJuego.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtSuscripcion.o DtUsuario.o
	g++ main.o Color.o Categoria.o Desarrollador.o Juego.o Estadistica.o Fabrica.o Jugador.o Partida.o PartidaIndividual.o PartidaMultijugador.o Sesion.o Suscripcion.o Usuario.o ControladorCategoria.o ControladorUsuario.o ControladorVideojuego.o ManejadorCategoria.o ManejadorUsuario.o ManejadorVideojuego.o DtJuegoFull.o DtCategoria.o DtCategoriaKey.o DtDesarrollador.o DtEstadistica.o DtFechaHora.o DtJuego.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtSuscripcion.o DtUsuario.o -g -o main

Color.o: class/Color.cpp
	g++ class/Color.cpp -c -g

Categoria.o: class/Categoria.cpp
	g++ class/Categoria.cpp -c -g

Desarrollador.o: class/Desarrollador.cpp 
	g++ class/Desarrollador.cpp -c -g

Juego.o: class/Juego.cpp
	g++ class/Juego.cpp -c -g

Estadistica.o: class/Estadistica.cpp
	g++ class/Estadistica.cpp -c -g

Jugador.o: class/Jugador.cpp
	g++ class/Jugador.cpp -c -g

Partida.o: class/Partida.cpp
	g++ class/Partida.cpp -c -g

PartidaIndividual.o: class/PartidaIndividual.cpp
	g++ class/PartidaIndividual.cpp -c -g

PartidaMultijugador.o: class/PartidaMultijugador.cpp
	g++ class/PartidaMultijugador.cpp -c -g

Sesion.o: class/Sesion.cpp
	g++ class/Sesion.cpp -c -g

Suscripcion.o: class/Suscripcion.cpp
	g++ class/Suscripcion.cpp -c -g

Usuario.o: class/Usuario.cpp
	g++ class/Usuario.cpp -c -g

ControladorCategoria.o: controllers/ControladorCategoria.cpp
	g++ controllers/ControladorCategoria.cpp -c -g

ControladorUsuario.o: controllers/ControladorUsuario.cpp
	g++ controllers/ControladorUsuario.cpp -c -g

ControladorVideojuego.o: controllers/ControladorVideojuego.cpp
	g++ controllers/ControladorVideojuego.cpp -c -g

ManejadorUsuario.o: handlers/ManejadorUsuario.cpp
	g++ handlers/ManejadorUsuario.cpp -c -g

ManejadorVideojuego.o: handlers/ManejadorVideojuego.cpp
	g++ handlers/ManejadorVideojuego.cpp -c -g

ManejadorCategoria.o: handlers/ManejadorCategoria.cpp
	g++ handlers/ManejadorCategoria.cpp -c -g

DtJuegoFull.o: dtFiles/DtJuegoFull.cpp
	g++ dtFiles/DtJuegoFull.cpp -c -g

DtCategoria.o: dtFiles/DtCategoria.cpp
	g++ dtFiles/DtCategoria.cpp -c -g

DtCategoriaKey.o: dtFiles/DtCategoriaKey.cpp
	g++ dtFiles/DtCategoriaKey.cpp -c -g

DtDesarrollador.o: dtFiles/DtDesarrollador.cpp
	g++ dtFiles/DtDesarrollador.cpp -c -g

DtEstadistica.o: dtFiles/DtEstadistica.cpp
	g++ dtFiles/DtEstadistica.cpp -c -g

DtFechaHora.o: dtFiles/DtFechaHora.cpp
	g++ dtFiles/DtFechaHora.cpp -c -g

DtJuego.o: dtFiles/DtJuego.cpp
	g++ dtFiles/DtJuego.cpp -c -g

DtJugador.o: dtFiles/DtJugador.cpp
	g++ dtFiles/DtJugador.cpp -c -g

DtPartida.o: dtFiles/DtPartida.cpp
	g++ dtFiles/DtPartida.cpp -c -g

DtPartidaIndividual.o: dtFiles/DtPartidaIndividual.cpp
	g++ dtFiles/DtPartidaIndividual.cpp -c -g

DtPartidaMultijugador.o: dtFiles/DtPartidaMultijugador.cpp
	g++ dtFiles/DtPartidaMultijugador.cpp -c -g

DtSuscripcion.o: dtFiles/DtSuscripcion.cpp
	g++ dtFiles/DtSuscripcion.cpp -c -g

DtUsuario.o: dtFiles/DtUsuario.cpp
	g++ dtFiles/DtUsuario.cpp -c -g

Fabrica.o: Fabrica.cpp
	g++ Fabrica.cpp -c -g

main.o: main.cpp
	g++ main.cpp -g -c

clean:
	rm -rf *.o main