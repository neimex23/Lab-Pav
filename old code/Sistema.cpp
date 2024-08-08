#include "Sistema.h"

Sistema::Sistema() {}

void Sistema::validarInt(string text, int &retorno)
{
    bool seguir=true;
    while (seguir)
    {
        cout << text;
        if (cin >> retorno)
        {
            seguir=false;
        }
        else
        {
            cout << "No es un Entero, Intente devuelta\n";
            cin.clear();
            cin.ignore();
        }
    }
    /* while (!(cin >> retorno))
     {
         cout << "Error." + text;
         cin.clear();
         cin.ignore();
     };*/
}

bool Sistema::existeJugador(string nickname)
{
    for (int i = 0; i < cantPersonas; i++)
    {
        // if(capitalizeString(personas[i]->getNickname()) == capitalizeString(nickname))
        if (personas[i]->getNickname() == nickname)
            return true;
    }
    return false;
}

bool Sistema::existeJuego(string nombre)
{
    for (int i = 0; i < cantJuegos; i++)
    {
        if (juegos[i]->getNombre() == nombre)
            return true;
    }
    return false;
}

DtJugador **Sistema::obtenerJugadores(int &cantJugadores)
{
    cantJugadores = cantPersonas;
    DtJugador **dtJugadores = new DtJugador *[cantJugadores];

    for (int i = 0; i < cantJugadores; i++)
    {
        dtJugadores[i] = new DtJugador(personas[i]->getNickname(), personas[i]->getEdad());
    }
    return dtJugadores;
}

DtJuego **Sistema::obtenerVideojuegos(int &cantVideojuegos)
{
    cantVideojuegos = cantJuegos;
    DtJuego **dtJuegos = new DtJuego *[cantVideojuegos];
    int totalHorasDeJuego;
    for (int i = 0; i < cantVideojuegos; i++)
    {
        totalHorasDeJuego = 0;
        for (int j = 0; j < juegos[i]->getNumPartidas(); j++)
        {
            totalHorasDeJuego += juegos[i]->getPartidas()[j]->darTotalHorasParticipantes();
        }
        dtJuegos[i] = new DtJuego(juegos[i]->getNombre(), totalHorasDeJuego, juegos[i]->getGenero());
    }

    return dtJuegos;
}

DtPartida **Sistema::obtenerPartidas(string videojuego, int &cantDePartidas)
{
    DtPartida **dtPartidas;
    if (existeJuego(videojuego))
    {
        Juego *juegoActual = obtenerVideojuego(videojuego);
        cantDePartidas = juegoActual->getNumPartidas();
        dtPartidas = new DtPartida *[cantDePartidas];

        for (int i = 0; i < cantDePartidas; i++)
        { // Se debe especificar el juego de alguna forma
            if (PartidaIndividual *pi = dynamic_cast<PartidaIndividual *>(juegoActual->getPartidas()[i]))
                dtPartidas[i] = new DtPartidaIndividual(pi->getFechaHora(), pi->getDuracion(), pi->getContinuaPartidaAnterior());
            else
            {
                PartidaMultijugador *pm = dynamic_cast<PartidaMultijugador *>(juegoActual->getPartidas()[i]);
                dtPartidas[i] = new DtPartidaMultijugador(pm->getFechaHora(), pm->getDuracion(), pm->getTransmitidaEnVivo(), pm->getTransmitidaEnVivo());
            }
        }
    }
    else
    {
        throw invalid_argument("No Existe Videojuego.");
    }
    return dtPartidas;
}

DtPartida *Sistema::crearDatosPartida(string videojuego, string nickname)
{
    // Mejorar los ifs
    int opcionTipoPartida, opcionContPartida, opcionTransmiteEnVivo, numjugadores, duracion;
    Partida *partida;
    Juego *juego;
    if (existeJuego(videojuego) && existeJugador(nickname))
    {
        juego = obtenerVideojuego(videojuego);
        cout << "Que Tipo de Partida desea iniciar: 1) Individual - 2) Multijugador \nOpcion:";
        cin >> opcionTipoPartida;
        if (opcionTipoPartida == 1 || opcionTipoPartida == 2)
            validarInt("Cuanto es la duracion de la partida: ", duracion);
        switch (opcionTipoPartida)
        {
        case 1: //(DtFechaHora fecha, int duracion,bool continuaPartidaAnterior)
            if (juego->getNumPartidas() < 1)
            {
                return new DtPartidaIndividual(takeTime(), duracion, false);
            }
            else
            {
                cout << "Continua partida anterior? \n 1) Si \n 2) No \nOpcion: ";
                cin >> opcionContPartida;
                return opcionContPartida == 1 ? new DtPartidaIndividual(takeTime(), duracion, true) : new DtPartidaIndividual(takeTime(), duracion, false);
            }
            break;
        case 2:
            validarInt("Transmite en vivo? \n 1) Si \n 2) No \nOpcion: ", opcionTransmiteEnVivo);
            if (opcionTransmiteEnVivo == 1 || opcionTransmiteEnVivo == 2)
            {
                validarInt("Cuantos jugadores seran?:", numjugadores);
                return opcionTransmiteEnVivo == 1 ? new DtPartidaMultijugador(takeTime(), duracion, true, numjugadores) : new DtPartidaMultijugador(takeTime(), duracion, false, numjugadores);
            }
            else
            {
                throw invalid_argument("Opcion Incorrecta.");
            }
        default:
            throw invalid_argument("Opcion Incorrecta.");
            break;
        }
    }
    else
    {
        throw invalid_argument("Jugador o videojuego incorrecto.");
        system("sleep 1");
        system("clear");
    }
}

void Sistema::iniciarPartida(string nickname, string videojuego, DtPartida *datos)
{
    Partida *nuevaPartida;

    if (existeJuego(videojuego) && existeJugador(nickname))
    {
        Jugador *jugador = obtenerJugador(nickname);
        Juego *juego = obtenerVideojuego(videojuego);

        DtPartidaIndividual *dtpi = dynamic_cast<DtPartidaIndividual *>(datos);
        if (dtpi != NULL)
            nuevaPartida = new PartidaIndividual(jugador, takeTime(), dtpi->getDuracion(), dtpi->getContinuaPartidaAnterior());
        else
        {
            DtPartidaMultijugador *dtpm = dynamic_cast<DtPartidaMultijugador *>(datos);
            nuevaPartida = new PartidaMultijugador(jugador, takeTime(), dtpm->getDuracion(), dtpm->getTransmitidaEnVivo(), dtpm->getCantJugadores());
        }
        juego->setPartidas(nuevaPartida);
    }
    else
    {
        throw invalid_argument("Jugador o videojuego incorrecto");
    }
}

Jugador *Sistema::obtenerJugador(string nickname)
{ // Nickname Existe
    int i = 0;
    while (personas[i]->getNickname() != nickname and i <= cantPersonas)
    {
        if (personas[i]->getNickname() == nickname)
        {
            i = cantPersonas + 1;
        }
        i++;
    }
    return personas[i];
}

Juego *Sistema::obtenerVideojuego(string videoJuego)
{ // Videojuego Existe
    int i = 0;
    while (juegos[i]->getNombre() != videoJuego and i <= cantJuegos)
    {
        if (juegos[i]->getNombre() == videoJuego)
        {
            i = cantJuegos++;
        }
        i++;
    }
    return juegos[i];
}

void Sistema::agregarJugador(string nickname, int edad, string password)
{
    if (existeJugador(nickname))
        throw invalid_argument("Nickname ya registrado");
    Jugador *nuevoJuegador = new Jugador(nickname, password, edad);
    personas[cantPersonas] = nuevoJuegador;
    cantPersonas++;
}

void Sistema::agregarJuego(string nombre, TipoGenero genero)
{
    if (existeJuego(nombre))
        throw invalid_argument("Juego ya registrado");
    Juego *nuevoJuego = new Juego(nombre, genero);
    juegos[cantJuegos] = nuevoJuego;
    cantJuegos++;
}

void Sistema::agregarPartidaIndividual(Jugador *jugador, string nombreJuego)
{
    Juego *juego = obtenerVideojuego(nombreJuego);
    Partida *nuevaPartida = new PartidaIndividual(jugador, takeTime(), 0, false);
    juego->setPartidas(nuevaPartida);
}

DtFechaHora Sistema::takeTime()
{
    struct tm *timeinfo;
    char input[80];
    time_t rawtime = time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(input, 80, "%d/%m/%Y %H:%M", timeinfo);
    string str(input);
    int year = stoi(str.substr(6, 4));
    int month = stoi(str.substr(3, 2));
    int day = stoi(str.substr(0, 2));
    int hour = stoi(str.substr(11, 2));
    // Ver de si los minuto empiezan con 0
    int minute = stoi(str.substr(14, 2));

    DtFechaHora fecha = DtFechaHora(day, month, year, hour, minute);
    return fecha;
}

/*
void convertStringToUpper(string& s){
    for(int i=0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
}
}*/

TipoGenero Sistema::tomarGenero(int genero)
{
    TipoGenero enumGenero;
    switch (genero)
    {
    case 1:
        enumGenero = ACCION;
        break;
    case 2:
        enumGenero = AVENTURA;
        break;
    case 3:
        enumGenero = DEPORTE;
        break;
    case 4:
        enumGenero = OTRO;
        break;
    default:
        throw invalid_argument("Genero no existe");
    }
    return enumGenero;
}

void Sistema::imprimirDtPartida(DtPartida *dtPartida)
{
    if (DtPartidaIndividual *pi = dynamic_cast<DtPartidaIndividual *>(dtPartida))
    {
        cout << *pi;
    }
    else
    {
        DtPartidaMultijugador *pm = dynamic_cast<DtPartidaMultijugador *>(dtPartida);
        cout << *pm;
    }
}

void Sistema::ingresarJugadoresPorDefecto()
{
    agregarJugador("Jugador1", 22, "Pass1");
    agregarJugador("Jugador2", 22, "Pass2");
}

void Sistema::ingresarVideoJuegosPorDefecto()
{
    agregarJuego("Videojuego1", ACCION);
    agregarJuego("Videojuego2", AVENTURA);
}

void Sistema::ingresarPartidasPorDefecto()
{
    iniciarPartida("Jugador1", "Videojuego1", crearDatosPartida("Videojuego1", "Jugador1"));
}
