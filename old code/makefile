main: DtFechaHora.o DtJuego.o DtJugador.o DtPartidaIndividual.o DtPartidaMultijugador.o DtPartida.o Juego.o Jugador.o Partida.o PartidaIndividual.o PartidaMultijugador.o Sistema.o main.o
	g++ DtFechaHora.o DtJuego.o DtJugador.o DtPartidaIndividual.o DtPartidaMultijugador.o DtPartida.o Juego.o Jugador.o Partida.o PartidaIndividual.o PartidaMultijugador.o Sistema.o main.o -g -o main

DtFechaHora.o: DtFechaHora.cpp
	g++ DtFechaHora.cpp -g -c
DtJuego.o: DtJuego.cpp
	g++ DtJuego.cpp -g -c
DtJugador.o: DtJugador.cpp
	g++ DtJugador.cpp -g -c
DtPartidaIndividual.o: DtPartidaIndividual.cpp
	g++ DtPartidaIndividual.cpp -g -c
DtPartidaMultijugador.o: DtPartidaMultijugador.cpp
	g++ DtPartidaMultijugador.cpp -g -c 
DtPartida.o: DtPartida.cpp
	g++ DtPartida.cpp -g -c
Juego.o: Juego.cpp 
	g++ Juego.cpp  -g -c
Jugador.o: Jugador.cpp 
	g++ Jugador.cpp  -g -c
Partida.o: Partida.cpp 
	g++ Partida.cpp  -g -c
PartidaIndividual.o: PartidaIndividual.cpp 
	g++ PartidaIndividual.cpp  -g -c
PartidaMultijugador.o: PartidaMultijugador.cpp
	g++ PartidaMultijugador.cpp -g -c
Sistema.o: Sistema.cpp
	g++ Sistema.cpp -g -c
main.o: main.cpp
	g++ main.cpp -g -c

clean:
	rm -rf *.o main
	clear