#include "DtJuego.h"
#include "DtJugador.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"

#include "TipoGenero.h"
#include "Sistema.h"
#include <iostream>
#include <string>

using namespace std;


void getText(string &texto)
{
    getc(stdin);
    getline(cin, texto);
}



void pause(){
    cout << "Presione ENTER para continuar...";
    cin.get();
    getchar();
    system("clear");
}



//-------------------------------------Menu Functions----------------------------------------

void menu()
{
    cout << "________________________________" << endl;
    cout << "1. Agregar Usuario" << endl;
    cout << "2. Agregar Videojuego" << endl;
    cout << "3. Listar Jugadores" << endl;
    cout << "4. Listar Videojuegos" << endl;
    cout << "5. Listar Partidas" << endl;
    cout << "6. Iniciar Partida" << endl;
    cout << "7. " << endl;
    cout << "7. Salir" << endl;
    cout << "8. Ingresar juegos y jugadores por defecto(para agilizar)" << endl;
    cout << "9. Registrar partida con Jugador1 y Videojuego1(para agilizar)" << endl;
    cout << "________________________________" << endl;
    cout << "OPCION: ";
}

void menuAgregarJuego(Sistema *s)
{
    int opcionGenero;
    system("clear");
    cout << "______________________________________________" << endl;
    cout << "__________________AGREGAR JUEGO_______________" << endl;
    string nombre;
    cout << "NOMBRE: ";
    getText(nombre);
    cout << "GENERO:\n1)ACCION.\n2)AVENTURA.\n3)DEPORTE.\n4)OTRO.\n";
    s->validarInt("Opcion: ", opcionGenero);
    try
    {
        s->agregarJuego(nombre, s->tomarGenero(opcionGenero));
        cout << "\nSE HA AGREGADO EL JUEGO " << nombre << " EN EL SISTEMA..." << endl;
        cout << "______________________________________________" << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void menuAgregarJugador(Sistema *s)
{
    system("clear");
    cout << "______________________________________________" << endl;
    cout << "_______________AGREGAR JUGADOR________________" << endl;
    string nickname, password;
    int edad;
    cout << "Nickname: ";
    getText(nickname);
    s->validarInt("Edad: ", edad);
    cout << "Password: ";
    getText(password);
    try
    {
        s->agregarJugador(nickname, edad, password);
        cout << "\nSE HA AGREGADO EL JUGADOR " << nickname << " EN EL SISTEMA..." << endl;
        cout << "______________________________________________" << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

void menuListarJugadores(Sistema *s)
{
    int cantJugadores = 0;
    cout << "______________________________________________" << endl;
    cout << "______________Lista de Jugadores______________" << endl;
    DtJugador **dtJugadores = s->obtenerJugadores(cantJugadores);
    if (cantJugadores < 1)
    {
        cout << "No Hay Jugadores Registrados." << endl;
    }
    else
    {
        for (int i = 0; i < cantJugadores; i++)
        {
            cout << *dtJugadores[i] << endl; // preguntar al profe como funciona esto
        }
    }
    cout << "______________________________________________" << endl;
}

void menuListarJuego(Sistema *s)
{
    cout << "______________________________________________" << endl;
    cout << "______________Lista de Juegos______________" << endl;
    // TODO: Preguntar si hay que hacer una variable local o se podria llamar a s->cantJuegos
    int cantJuegos;
    DtJuego **dtJuegos = s->obtenerVideojuegos(cantJuegos);
    if (cantJuegos < 1)
        cout << "No hay Juegos Registrados." << endl;
    else
    {
        for (int i = 0; i < cantJuegos; i++)
        {
            cout << *dtJuegos[i] << endl;
        }        
    }
    cout << "______________________________________________" << endl;
}

void menuObtenerPartidas(Sistema *s)
{
    int cantPartidas;
    string videojuego;
    cout << "______________________________________________" << endl;
    cout << "Videojuego a Listar: ";
    cin >> videojuego;
    try
    {
        DtPartida **dtPartidas = s->obtenerPartidas(videojuego, cantPartidas);
        cout << "             Lista de Partidas" << endl;
        cout << "______________" << videojuego << "______________" << endl;
        if (cantPartidas < 1)
        {
            cout << "No hay Partidas Empezadas." << endl;
        }
        else
        {
            for (int i = 0; i < cantPartidas; i++)
            {
                s->imprimirDtPartida(dtPartidas[i]);
            }
        }
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }
}

void menuIniciarPartida(Sistema *s)
{
    string nickname;
    string videojuego;
    cout << "______________________________________________" << endl;
    cout << "______________Iniciar Partida______________" << endl;
    cout << "Nickname: ";
    cin >> nickname;
    cout << "Videojuego: ";
    getText(videojuego);
    // preguntar nickname y videojuego aqui para agu8./milizar luego en obtener datos
    // Arreglar Invalid argument para que no aumente partida si tira error.
    try
    {
        DtPartida *datosPartida = s->crearDatosPartida(videojuego, nickname);
        s->iniciarPartida(nickname, videojuego, datosPartida);
        cout << "Partida iniciada correctamente" << endl;
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}

//-------------------------------------Main program----------------------------------------
int main()
{
    system("clear");
    // Declaracion de Variables
    int opcion;
    Sistema *sistema = new Sistema();
    // Prog
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            menuAgregarJugador(sistema);
            pause();
            break;
        case 2: // agregarVideojuego(string nombre, TipoGenero genero)
            menuAgregarJuego(sistema);
            pause();
            break;
        case 3:
            menuListarJugadores(sistema);
            pause();
            break;
        case 4: // obtenerVideojuegos(int& cantVideojuegos)
            menuListarJuego(sistema);
            pause();
            break;
        case 5: //* obtenerPartidas(string videojuego, int& cantPartidas)
            menuObtenerPartidas(sistema);
            pause();
            break;
        case 6: // iniciarPartida(string nickname, string videojuego, DtPartida* datos)
            menuIniciarPartida(sistema);
            pause();
            break;
        case 7:
            cout << "Adios :)" << endl;
            break;
        case 8:
            sistema->ingresarJugadoresPorDefecto();
            sistema->ingresarVideoJuegosPorDefecto();
            system("clear");
            break;
        case 9:
            sistema->ingresarPartidasPorDefecto();
            system("clear");
            break;
        default:
            cout << "Error. Opcion incorrecta" << endl;
            pause();
        }
    } while (opcion != 7);

    return 0;
}
