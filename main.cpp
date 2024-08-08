#include "dtFiles/DtCategoria.h"
#include "dtFiles/DtCategoriaKey.h"
#include "dtFiles/DtDesarrollador.h"
#include "dtFiles/DtEstadistica.h"
#include "dtFiles/DtFechaHora.h"
#include "dtFiles/DtJuego.h"
#include "dtFiles/DtJuegoFull.h"
#include "dtFiles/DtJugador.h"
#include "dtFiles/DtPartida.h"
#include "dtFiles/DtPartidaIndividual.h"
#include "dtFiles/DtPartidaMultijugador.h"
#include "dtFiles/DtSuscripcion.h"
#include "dtFiles/DtUsuario.h"
#include "class/TipoPago.h"
#include "class/CodeColor.h"
#include "class/Color.h"
#include "Fabrica.h"
#include "interface/IControladorCategoria.h"
#include "interface/IControladorUsuario.h"
#include "interface/IControladorVideojuego.h"
#include "class/Perfil.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

Fabrica* fabrica;
IControladorCategoria* iconCategoria;
IControladorUsuario* iconUsuario;
IControladorVideojuego* iconVideojuego;

Color red(FG_RED);
Color blue(FG_BLUE);
Color green(FG_GREEN);
Color yellow(FG_YELLOW);
Color magenta(FG_MAGENTA);
Color def(FG_DEFAULT);


void pause(){
    cout << green << "Presione ENTER para continuar..."<<def;
    cin.get();
    getchar();
    system("clear");
}


//Listar Categorias
void listarCategorias(){
    DtCategoria* aux;
    list<DtCategoria*> listCategories=iconCategoria->getMapCat();
    if(listCategories.size() != 0){
        cout << magenta << "================= Categorias existentes =================" << def << endl;
        for(list<DtCategoria*>::iterator iter=listCategories.begin(); iter!=listCategories.end();++iter){
            aux=*iter;
            cout << *aux;
        }
    }
    else
        cout << red << "No hay categorias existentes" <<def;
}

void imprimirCat(list<DtCategoria*> lista){
    DtCategoria* aux;
    cout << magenta << "================= Categorias: =================" << def << endl;
    for(list<DtCategoria*>::iterator iter=lista.begin(); iter!=lista.end();++iter){
        aux=*iter;
        cout << *aux;
    }
}


//MenuIniciarSesion
void menuIniciarSesion(){
    int opcion;
    string email,password;
    system("clear");
    do{
        cout << magenta << "================= Inicio de sesion: =====================" << def <<endl;
        cout << "Email: ";
        cin >> email;
        cout << "Password: ";
        cin >> password;
        try{
            iconUsuario->ingresarDatos(email,password);
            iconUsuario->iniciarSesion();
            opcion=2;
            cout << "Usuario logueado con exito." << endl;
        } catch(invalid_argument e){
            cout << red << "\nDATOS INCORRECTOS" <<def<< endl;
            cout << "1: Volver a intentar" << endl;
            cout << "2: Cancelar" << endl;
            cout << "Opcion: "; cin >> opcion;  
            if(opcion==2) 
                cout << red << "Usuario no logueado"<<def << endl;
            else if(opcion==1){system("clear");}
            else{
                cout << red << "Opcion incorrecta." <<def << endl;
                opcion=2;
                pause();
            }
        }
    } while (opcion!=2);
    system("clear");
}

//-------------------------------------Menu Functions----------------------------------------

void agregarCategoriaMenu(){
    string tipoGenero,tipoPlataforma,descripcion,opcion; bool salir=false;
    system("clear");
    try {
        do{
            listarCategorias();
            cout << blue << "\n============================ Agregar Categoria: ============================" << def << endl;
            cout << "Ingrese Genero: "; cin >> tipoGenero;
            cout << "Ingrese Plataforma: "; cin >> tipoPlataforma;
            if (!iconCategoria->existeCatGenPla(tipoGenero,tipoPlataforma)){
                cout << "Ingrese descripcion: ";  cin >> descripcion;
                cout << green << "\n1) Confirmar" << def<< endl;
                cout << red << "2) Cancelar" << def <<endl;  
                cout << "Seleccione una opcion: "; cin >> opcion;
                if(opcion == "1"){
                    iconCategoria->datosCat(tipoGenero,tipoPlataforma,descripcion);
                    iconCategoria->agregarCategoria();
                    system("clear");
                    cout << endl << green <<"Categoria agregada correctamente"<<def <<endl;
                }else{
                    system("clear");
                    cout << endl <<red<<"Cancelado correctamente"<<def << endl;
                }
                salir=true;
                cout << "========================================================"<<endl;
            }else{
                cout << red << "Ya Existe la Categoria"<<def <<endl;
            }
        }while (!salir);
        
            
    } catch(invalid_argument& e) {
        cout << e.what() << '\n';
    }
}

void seleccionarRol(int str){
    if(str == 1){
        string nomEmp;
        cout << "Ingrese nombre de su empresa: ";
        cin >> nomEmp;
        iconUsuario->datosEmpresa(nomEmp);
    }else if(str == 2){
        string nickname, descripcion;
        cout << "Ingrese nickname: ";
        cin >> nickname;
        cout << "Ingrese descripcion: ";
        cin >> descripcion;
        iconUsuario->datosJugador(nickname, descripcion);
    }else
        throw invalid_argument("Seleccione una opcion valida.");
}

void altaUsuarioMenu(){
    string email,password;
    int opcionRol; 
    bool salir=false; 
    system("clear");
    do{
        cout << blue << "================= Alta Usuario: =====================" << def<< endl;
        cout << "Ingrese email: ";
        cin >> email;
        cout << "Ingrese contrasenia: ";
        cin >> password;
        if (!iconUsuario->existeUsuario(email)){
            iconUsuario->datosComunes(email,password);
            cout << red << "\n--Ingrese tipo de usuario--" <<def << endl;
            cout << " 1-Desarrollador"<<endl << " 2-Jugador" << endl;   
            cout << "Seleccione su rol: "; cin >> opcionRol;
            try{
                seleccionarRol(opcionRol);
                iconUsuario->altaUsuario();
                system("clear");
                salir=true;
                cout <<endl << green << "Usuario Agregado Correctamente"<<def<<endl;
                cout << "========================================================" << endl;
            } catch (invalid_argument &e){
                cout << e.what() << endl;
                pause(); system("clear");
            }
        }else{
            cout << "Email Ya Existe" <<endl;
            pause(); system("clear");
        }
    }while (!salir);
}

void listarVideojuegosXSuscripcion(bool inactivas){
    //Ver que no esta vacio
    map<string,list<DtJuego*> > suscripcionesMap = iconVideojuego->listarVideojuegosXSuscripcion();
    for(auto const &suscripcion : suscripcionesMap){
        if(suscripcion.first=="activos"){
            cout << green <<"-SUSCRIPCIONES ACTIVAS-"<<def << endl;
            for(auto const &juego : suscripcion.second)
                cout << *juego;
        } else if(suscripcion.first == "inactivos" && inactivas){
            cout << red << "-SUSCRIPCIONES INACTIVAS-" <<def << endl;
            for(auto const &juego : suscripcion.second)
                cout << *juego;
        }
    }
}


void listarVideojuegos(int mode){
    list<DtJuego*> dtList= iconVideojuego->listarVideojuegos();
    if (dtList.size()!=0 and mode==1){
        for (list<DtJuego*>::iterator iter=dtList.begin(); iter!=dtList.end(); ++iter){
            cout << red <<"[*] "<< def << (*iter)->getNombre() <<endl;
        }
    }else if (dtList.size()!=0 and mode==2){
        for (list<DtJuego*>::iterator iter=dtList.begin(); iter!=dtList.end(); ++iter){
            cout << red <<"[*] "<< def << "Nombre: " << (*iter)->getNombre() << "\nDescripcion: " << (*iter)->getDescripcion() << endl;
        }
    }else
        cout << red <<"No hay Videojuegos Ingresados."<<def <<endl;
}

void suscribirseAVideojuegoMenu(){
    if(!iconVideojuego->isEmpty()){
        string nomJuego;
        int tipoPago;
        bool isValid = false;
        TipoPago tp;
        system("clear");
        listarVideojuegosXSuscripcion(true);
        cout << blue <<"================= Suscribirse a Videojuego: =====================" << def << endl;
        cout << "\n[*] Para salir Escriba:"<<red<< "'salir'"<<def  << endl;
        cout << "Seleccione el nombre del videojuego: ";
        cin >> nomJuego;
        if (iconVideojuego->existeVideojuego(nomJuego)){
            iconVideojuego->seleccionJuego(nomJuego);
            cout <<endl << "1-Credito"<<endl << "2-Debito" << endl;
            while(!isValid){
                cout << "Seleccione metodo de pago: ";
                cin >> tipoPago;
                switch(tipoPago){
                    case 1:
                        tp = CREDITO;
                        isValid = true;
                    break;
                    case 2: 
                        tp = DEBITO;
                        isValid = true;
                    break;
                    default:
                        cout << red << "Metodo de pago invalido"<<def << endl;
                        isValid = false;
                    break;
                }
            }
                iconVideojuego->seleccionarTipoPago(tp);
                try{
                    iconVideojuego->suscribirseAVideojuego();
                    cout << green << "Suscripto a videojuego correctamente." <<def<< endl;
                    pause(); system("clear");
                } catch(invalid_argument& e){
                    cout <<red << e.what() <<def<< endl;
                }
        }else
            if (nomJuego!="salir"){
                cout << red << "No Existe el Videojuego Seleccionado" <<def <<endl;
            }else
                system("clear");
    }else
        cout << red << "No hay Videojuegos en el sistema" << def<<endl;
}


void agregarVideojuegoMenu(){
    string nombre,descripcion; 
    int costo,id; 
    bool exist=false,repitcat=false,repitgame=false;
    char opcion; 
    list<DtCategoria*> listaCat;
    DtCategoria* aux;
    do{
        system("clear");
        cout << blue <<"================= Alta Videojuego: =====================" << def << endl;  
        if (!iconCategoria->isEmptyCat()){
        cout << "Nombre Videojuego: " ; cin >> nombre ;
        if (!iconVideojuego->existeVideojuego(nombre) and nombre !="salir"){
            cout << "Descripcion: " ; cin >> descripcion;
            cout << "Costo: " ; cin >> costo;
                try {
                     do{        
                            listarCategorias();
                            cout << "\nIngrese Id de la Categoria: ";
                            cin >> id;
                            list <DtCategoria*>::iterator iter=listaCat.begin(); 
                            while (iter !=listaCat.end() and !repitcat){
                                aux= *iter;
                                if (aux->getId()==id){
                                    repitcat=true;
                                }else{
                                    ++iter;
                                }
                            }    
                            if (repitcat){
                                cout << "Categoria ya Seleccionada\n" << endl;
                                cout << "================================================================"<<endl;
                                repitcat=false;
                            }else{
                                if (iconCategoria->existeCat(id)){
                                    listaCat.push_back(iconCategoria->buscarCat(id));
                                    if (listaCat.size() < iconCategoria->cantidadCategorias()){
                                        cout << "Quiere Seguir Agregando Categorias? [Y/N]: ";
                                        cin >> opcion;
                                    }else{
                                        cout << magenta <<"No Quedan Categorias Disponibles para Agregar\n"<<def;
                                        opcion='n';
                                    }
                                    cout << "================================================================"<<endl;
                                    if (opcion == 'n'){
                                        cout << "Nombre: " << nombre << "\n" << "Descripcion: " << descripcion <<  "\n" << "Costo: " << costo << "\nCategorias: " <<endl;
                                        imprimirCat(listaCat);
                                        cout << green << "\n1) Confirmar" << def<< endl;
                                        cout << red << "2) Cancelar" << def <<endl;
                                        cout << "Opcion: ";
                                        cin >> opcion;
                                        switch (opcion){
                                            case '1':
                                                iconVideojuego->registrarVideojuego(nombre,descripcion,costo,listaCat);
                                                iconVideojuego->altaVideojuego();
                                                system("clear");
                                                cout << green << "Se Registro Correctamente"<<def <<endl;
                                                break;
                                        }
                                        repitgame=false;
                                        exist=true;
                                    }
                                }else{
                                    cout << "================================================================"<<endl;
                                    cout << red << "No Existe Categoria\n"<<def <<endl;
                                }
                            }
                        }while (!exist); 
                }catch (invalid_argument& e){
                    cout << red<< e.what()<<def <<endl;
                }  
            }else{
                if (nombre != "salir"){
                    cout << red << "Ya Existe el Videojuego" <<def <<endl;
                }else
                    cout << red << "salir: Es una palabra reservada del sistema, Por favor use otro Nombre" <<def <<endl;
            }
        }else
            cout << red << "No Hay Categorias en el Sistema" <<def <<endl;
           
    }while (repitgame);
}

void iniciarPartidaMenu(){
    if(!iconVideojuego->isEmpty()){
        string nombreVideojuego;
        int opcionPartida, duracion, cantJugadores, continuaPartida, transmitidaEnVivo;
        listarVideojuegos(1);
        cout << blue << "================= Iniciar Partida: =====================" << def << endl;
        cout << "Nombre Videojuego: " ; cin >> nombreVideojuego ;
        if (iconVideojuego->existeVideojuego(nombreVideojuego)){
            try{
                iconVideojuego->seleccionarVideojuego(nombreVideojuego);
                cout << "Seleccione tipo de partida. " << endl;
                cout << "1) Partida individual. " << endl;
                cout << "2) Partida multijugador. " << endl;
                cout << "Opcion: " ; cin >> opcionPartida ;
                cout << "Ingrese duracion de partida: " ; cin >> duracion ;
                switch (opcionPartida){
                case 1:
                    cout << "Continua partida anterior? " << endl;
                    cout << "1) Si " << endl;
                    cout << "2) No " << endl;
                    cout << "Opcion: " ; cin >> continuaPartida ;
                    iconVideojuego->datoIndividual(continuaPartida==1?true:false,duracion);
                    iconVideojuego->iniciarPartida();
                    cout << green <<"\nPartida iniciada correctamente. "<<def << endl;
                break;
                case 2:
                    cout << "Se transmite en vivo? " << endl;
                    cout << "1) Si " << endl;
                    cout << "2) No " << endl;
                    cout << "Opcion: " ; cin >> transmitidaEnVivo;
                    cout << "Ingrese cantidad de jugadores: "; cin >> cantJugadores ;
                    iconVideojuego->datoMultijugador(transmitidaEnVivo==1?true:false,cantJugadores,duracion);
                    iconVideojuego->iniciarPartida();
                    cout << green << "\nPartida iniciada correctamente. "<<def << endl;
                break;
                default:
                    cout << red << "Opcion incorrecta"<<def << endl;
                break;
                }
            }catch (invalid_argument &e){
                cout << red << e.what()<<def <<endl;
            }
        } else
            cout << red <<"No Existe el Videojuego Seleccionado" <<def <<endl;
    }else
        cout << "No hay Videojuegos en el sistema" << endl;
}


void verInfoJuego(){
    string nombre; 
    bool salir=false;
    DtJuegoFull* juego;
    system("clear");
    cout << blue << "================= Ver Informacion de Videojuego: =====================" << def <<endl;
    do{
        if (!iconVideojuego->isEmpty()){
            listarVideojuegos(1);
            cout << "\n[*] Para salir Escriba:"<<red<< "'salir'"<<def  << endl;
            cout << "Escriba el Nombre de un Videojuego: "; cin>> nombre;
            system("clear");
            if (nombre != "salir"){
                cout << blue << "================= Informacion: ====================="<<def << endl;
                try{
                    juego=iconVideojuego->getVideojuegoFull(nombre);
                    cout << *juego;
                    salir=true;
                } catch (invalid_argument& e){
                    cout <<red << e.what() << def<< endl;
                }
            }else
                salir=true;
        }else{
            cout << red << "No Hay Videojuegos Para Ver Informacion"<<def <<endl;
            salir=true;
        }
    }while (!salir);
}

void menuEliminarVideojuego(){
    if(!iconVideojuego->isEmpty()){
        int opcion;
        string videojuego;
        list<string> juegos = iconVideojuego->listarVideojuegosDesarrollador();
        system("clear");
        cout << blue << "================= Eliminar Juego: =====================" << def <<endl;
        cout << "--Videojuegos dados de alta por este desarrollador--" << endl;
        for (list<string>::iterator iter = juegos.begin(); iter != juegos.end(); iter++){
            cout << red << " [*] "<<def << "Nombre: " << (*iter) << endl;
        }
        cout << "\nIngrese nombre de videojuego: " ; cin >> videojuego;
        if(iconVideojuego->existeVideojuego(videojuego)){
            iconVideojuego->seleccionarVideojuego(videojuego);
            cout << green << "1) Confirmar" << def<< endl;
            cout << red << "2) Cancelar" << def <<endl;
            cout << "Opcion: "; cin >> opcion;
            switch (opcion){
            case 1:
                try{
                    iconVideojuego->eliminarVideojuego();
                    cout << green << "Videojuego eliminado con exito" << def << endl;
                } catch (invalid_argument &e){
                    cout << e.what() << endl;
                }
                pause(); system("clear");
            break;
            case 2:
                system("clear");
                delete iconVideojuego;
                cout << red <<"Cancelado correctamente"<<def << endl;
                cout << "=======================" << endl;
            break;
            default:
                cout <<red<< "Opcion incorrecta." << def<<endl;
            break;
            }
        }else
            cout << red<< "No Existe el Videojuego Seleccionado" << def<<endl;
    }else
        cout << red<<"No hay Videojuegos en el sistema" <<def<< endl;
}

void cancelarSuscripcionMenu(){
        if(!iconVideojuego->isEmpty()){
                string nombreVideojuego;
                cout << yellow << "================= Cancelar suscripcion a videojuego: =====================" <<def << endl;
                listarVideojuegosXSuscripcion(false);
                cout << "\n[*] Para salir Escriba:"<<red<< "'salir'"<<def  << endl;
                cout << "Seleccione nombre videojuego a eliminar: "; cin >> nombreVideojuego;      
                if (iconVideojuego->existeVideojuego(nombreVideojuego)){
                    iconVideojuego->seleccionarVideojuego(nombreVideojuego);
                    try{
                        if(iconVideojuego->isSub()){
                            iconVideojuego->cancelarVideojuego();
                            cout << yellow << "Suscripcion cancelada correctamente" <<def << endl;
                        } else
                            cout << red << "No tiene suscripcion activa para el videojuego seleccionado" <<def << endl;
                    } catch(invalid_argument & e){
                        cout << red << e.what() << def << endl;
                    } 
                } else{
                    if (nombreVideojuego !="salir"){
                        system("clear");
                        cout << red << "No existe el Videojuego\n"<<def<<endl; 
                    }else
                        system("clear");
                }
    }else{
        cout << red << "No hay Videojuegos en el sistema" <<def <<endl;      
    }
}

void menuPuntuarVideojuego(){
    if(!iconVideojuego->isEmpty()){
        int puntaje;
        string nombre;
        bool salir=false;
        cout << yellow << "================= Puntuar Videojuego: =====================" << def <<endl;
        try{
            do{
                listarVideojuegos(2);
                cout << "\n[*] Para salir Escriba:"<<red<< "'salir'"<<def  << endl;
                cout << "Seleccione el Videojuego a puntuar: "; cin >> nombre;
                if (iconVideojuego->existeVideojuego(nombre)){ 
                    iconVideojuego->seleccionarVideojuego(nombre);
                    if(!iconVideojuego->jugadorPuntuo()){ 
                            do{
                                cout << "Asigne un puntaje del 1 al 5: "; cin >> puntaje;
                                if(puntaje>=1 && puntaje<=5){
                                    iconVideojuego->datoPuntaje(puntaje);
                                    iconVideojuego->asignarPuntaje();
                                    salir=true;
                                    cout << green << "Puntuado Correctamente."<<def <<endl;
                                }else 
                                    cout << red <<"Valor incorrecto\n" <<def<< endl; 
                            }while (puntaje<1 and puntaje>5);
                        
                    }else
                        cout << red << "Ya puntuastes este Videojuego\n"<<def <<endl;
                }else  
                    if (nombre !="salir"){
                        cout << red << "No existe el Videojuego\n"<<def<<endl; 
                        system("clear");
                    }else{
                        salir=true;
                        system("clear");
                    }
            }while(!salir);     
        }catch(invalid_argument &e){
            cout << e.what() << endl;
        }
    }else
        cout << "No hay Videojuegos en el sistema" << endl;
}


void menuVerPartidaVideojuegos(){
    string nombre; bool salir=false;
    cout << yellow << "================= Ver Partida de Videojuego: =====================" << def <<endl;
    do{
        if(!iconVideojuego->isEmpty()){
            listarVideojuegos(2);
            cout << "\n[*] Para salir Escriba:"<<red<< "'salir'"<<def  << endl;
            cout << "Selecciona un Videojuego: ";
            cin >> nombre;
            if (iconVideojuego->existeVideojuego(nombre)){ 
                iconVideojuego->seleccionarVideojuego(nombre);
                list<DtPartida*>listPartidas=iconVideojuego->getDtPartidas();
                system("clear");
                if (listPartidas.size() !=0){
                    cout << "================= Partidas de: " << nombre <<" =================" <<endl;
                    for (list<DtPartida*>::iterator iter=listPartidas.begin(); iter!=listPartidas.end();++iter){          
                        cout << "=================[*]================= ";
                        if (DtPartidaIndividual* dpi=dynamic_cast<DtPartidaIndividual*>(*iter)){
                            cout << *dpi <<endl;
                        }else{
                            if(DtPartidaMultijugador* dpm=dynamic_cast<DtPartidaMultijugador*>(*iter)){
                                cout << *dpm <<endl;
                            }
                        }
                        cout << endl;
                    }
                    salir=true;     
                }else
                    cout << red << "No Hay Partidas para Mostrar\n"<<def <<endl;
                    salir=true;
            }else
                if (nombre!="salir"){
                    cout << red << "No existe el Videojuego\n"<< def <<endl;
                }else{
                    salir=true;
                    system("clear");
                }
        }else{
            cout << red <<"No hay Videojuegos en el Sistema"<<def <<endl;
            salir=true;
        }
    }while (!salir);
}

void buscarVideojuegoXCategoria(){
    if(!iconVideojuego->isEmpty()){
        cout << yellow << "================= Listar Videojuego por Categoria: =====================" << def <<endl; 
        listarCategorias();
        cout << "\n[*] Para salir Escriba:"<<red<< "'-1'"<<def  << endl;
        cout << "Seleccione el id la categoria: ";
        list<DtCategoria*> aux;
        int id;
        cin >> id;
        DtJuego* auxjuego;
        if (iconCategoria->existeCat(id)){
            cout << magenta <<"================================== "<<def<<endl;
            iconVideojuego->datoId(id); 
            list<DtJuego*> juego=iconVideojuego->buscarVideojuegoXCategoria();
            for (list<DtJuego*>::iterator iter=juego.begin(); iter!=juego.end();++iter){
                auxjuego=(*iter);
                cout << red << "[*] " << def <<"Nombre: "<< auxjuego->getNombre() << "\nDescripcion: " << auxjuego->getDescripcion() << endl;
                cout << magenta <<"================================== "<<def<<endl;
            }   
        }else{
            if (id!=-1){
                cout << red << "No existe Categoria" << def << endl;
            }else
                system("clear");
        }
    }else
        cout << "No hay Videojuegos en el sistema" << endl;
}


void listarVideojuegosOrdenados(int opcion){
    list<DtJuego*> dtJuegoList = iconVideojuego->listarVideojuegosOrdenados(opcion);
    if(dtJuegoList.size() != 0){
        for(auto const& dtJuego : dtJuegoList)
            cout << "Nombre: " << dtJuego->getNombre() <<"  Descripcion: "<< dtJuego->getDescripcion() << "  Puntaje: " <<dtJuego->getPromedio() << "  Total horas: " << dtJuego->getTotalHoras() << endl;   
    } else
        cout << red << "No hay categorias existentes" <<def;
}

void rankingVideojuegosMenu(){
    int opcion;
        cout << yellow << "================= Ranking de videojuegos: =====================" << def <<endl;
        cout << "1 - Ordenar videojuegos por puntuacion" << endl;
        cout << "2 - Ordenar videojuegos por duracion total" << endl;
        cout << "\n[*] Para salir Escriba:"<<red<< "'-1"<<def  << endl;
        cout << "Seleccione una opcion: "; cin >> opcion;
        if(opcion !=-1){
            try{
                listarVideojuegosOrdenados(opcion);
            }catch (invalid_argument &e){
                cout << red << e.what() <<def <<endl;
            }
        }else
            system("clear");
}


//--------------------------------Debug Mode-------------------------------------------
void agregarDev(){
  
    iconUsuario=fabrica->getIControladorUsuario();
    iconUsuario->datosComunes("Des1","Des1");
    iconUsuario->datosEmpresa("Des1");
    iconUsuario->altaUsuario();
    cout << "--Se ha dado de alta un Desarrollador--" << endl;
    cout << "Email: Des1" << endl;
    cout << "Contrasenia: Des1" << endl;
    cout << blue <<"============================="<<def<<endl;
}

void agregarJug(){
    iconUsuario= fabrica->getIControladorUsuario();
    iconUsuario->datosComunes("Jug1","Jug1");
    iconUsuario->datosJugador("Jug1","Jug1");
    iconUsuario->altaUsuario();
    iconUsuario->datosComunes("Jug2","Jug2");
    iconUsuario->datosJugador("Jug2","Jug2");
    iconUsuario->altaUsuario();
    cout << "---Se ha dado de alta el siguiente Jugador---" << endl;
    cout << "Email: Jug1" << endl;
    cout << "Contrasenia: Jug1:" << endl;
    cout << blue <<"============================="<<def<<endl;
    cout << "---Se ha dado de alta el siguiente Jugador---" << endl;
    cout << "Email: Jug2" << endl;
    cout << "Contrasenia: Jug2:" << endl;
    cout << blue <<"============================="<<def<<endl;
}

void iniciarSesionDev(){
    iconUsuario= fabrica->getIControladorUsuario();
    iconUsuario->ingresarDatos("Des1","Des1");
    iconUsuario->iniciarSesion();
    cout << "Se ha logueado Des1" << endl;
    cout << blue <<"============================="<<def<<endl;
}

void iniciarSesionJug(){
    iconUsuario= fabrica->getIControladorUsuario();
    iconUsuario->ingresarDatos("Jug1","Jug1");
    iconUsuario->iniciarSesion();
    cout << "Se ha logueado Jug1" << endl;
    cout << blue <<"============================="<<def<<endl;
}

void agregarCat(){
    iconUsuario= fabrica->getIControladorUsuario();
    iconCategoria= fabrica->getIControladorCategoria();
    iconUsuario->ingresarDatos("Des1","Des1");
    cout << "Se ha logueado Des1" << endl;
    iconCategoria->datosCat("Genero1","Plataforma1","Descripcion1");
    iconCategoria->agregarCategoria();
    iconCategoria->datosCat("Genero2","Plataforma2","Descripcion2");
    iconCategoria->agregarCategoria();
    cout << "--Se han creado las siguientes categorias--" << endl;
    cout << "Categoria '1':\n\tGenero: Genero1\n\tPlataforma: Plataforma2" << endl;
    cout << "Categoria '2:\n\tGenero: Genero2\n\tPlataforma: Plataforma2" << endl;
    cout << blue <<"============================="<<def<<endl;
}

void agregarJuego(){
    iconUsuario= fabrica->getIControladorUsuario();
    iconCategoria= fabrica->getIControladorCategoria();
    iconVideojuego=fabrica->getIControladorVideojuego();
    iconUsuario->ingresarDatos("Des1","Des1");
    iconUsuario->iniciarSesion();
    list<DtCategoria*> listaCat;
    listaCat.insert(listaCat.end(),iconCategoria->buscarCat(0));
    iconVideojuego->registrarVideojuego("Videojuego1","Videojuego1",100,listaCat);
    iconVideojuego->altaVideojuego();
    listaCat.insert(listaCat.end(),iconCategoria->buscarCat(1));
    iconVideojuego->registrarVideojuego("Videojuego2","Videojuego2",200,listaCat);
    iconVideojuego->altaVideojuego();
    cout << "--Se han creado las siguientes videojuegos--" << endl;
    cout << red <<"[*]" <<def << "Videojuego1"<<endl;
    cout << red <<"[*]" <<def << "Videojuego2"<<endl;
    cout << blue <<"============================="<<def<<endl;
}

void agregarSus(){
    iconUsuario= fabrica->getIControladorUsuario();
    iconVideojuego=fabrica->getIControladorVideojuego();
    iconUsuario->ingresarDatos("Jug1","Jug1");
    iconUsuario->iniciarSesion();
    iconVideojuego->seleccionJuego("Videojuego1");
    iconVideojuego->seleccionarTipoPago(CREDITO);
    iconVideojuego->suscribirseAVideojuego();
    cout << "Se ha Suscripto: Jug1 a Videojuego1\nMetodo de Pago: Credito"<<endl;
    cout << blue <<"============================="<<def<<endl;
}

void agregarPartidas(){
    iconVideojuego=fabrica->getIControladorVideojuego();
    iconUsuario=fabrica->getIControladorUsuario();
    int duracion=20; int cantJugadores=10;
    iconUsuario->ingresarDatos("Jug1","Jug1");
    iconUsuario->iniciarSesion();           
    iconVideojuego->seleccionarVideojuego("Videojuego1");
    iconVideojuego->datoIndividual(false,duracion);
    iconVideojuego->iniciarPartida();
    iconVideojuego->datoMultijugador(false,cantJugadores,duracion);
    iconVideojuego->iniciarPartida();
    cout << "--Se han Iniciado las Siguientes partidas con Jug1--"<<endl;
    cout << "======="<< red <<"[*]" <<def <<" Videojuego1" <<" =======" <<endl;
    cout << "Partida Individual: No Continua la Anterior - Duracion=20" <<endl;
    cout << "Partida Multijugador: No Trasmite en Vivo - Cantidad de Jugadores:10 - Duracion=20"<<endl;
    cout << blue <<"============================="<<def<<endl;
}

void agregarPuntajes(){ 
    iconVideojuego=fabrica->getIControladorVideojuego();
    iconUsuario=fabrica->getIControladorUsuario();
    iconUsuario->ingresarDatos("Jug1","Jug1");
    iconUsuario->iniciarSesion(); 
    iconVideojuego->seleccionarVideojuego("Videojuego1");
    iconVideojuego->datoPuntaje(5);
    iconVideojuego->asignarPuntaje();
    iconUsuario->ingresarDatos("Jug2","Jug2");
    iconUsuario->iniciarSesion();     
    iconVideojuego->seleccionarVideojuego("Videojuego1");
    iconVideojuego->datoPuntaje(3);
    iconVideojuego->asignarPuntaje();
    cout << "Se Asigno a Videojuego 1; El puntuaje 5 por Jug1; El Puntaje 3 por Jug2" <<endl;
    cout << blue <<"============================="<<def<<endl;
}

void menuFunctionDebug(){
    int opcion;
    do{
        cout << green << "================= Debug Mode: =====================" << def <<endl;
        cout << "________________________________" << endl;
        cout << "10. " << red << "Cargar Datos de Prueba\n" <<def;
        cout << "1. Agregar Desarrollador \n";
        cout << "2. Agregar Jugador\n";
        cout << "3. Iniciar Sesion Desarrollador"<<green << " [Se Requiere 1]\n" << def;
        cout << "4. Iniciar Sesion Jugador" << green << " [Se Requiere 2]\n" << def;
        cout << "5. Agregar Categorias" << green << " [Se Requiere 1,3]\n" << def;
        cout << "6. Agregar videojuegos"<< green << " [Se Requiere 1,3,5]\n" << def;
        cout << "7. Agregar Suscripciones" << green << " [Se Requiere 1,2,5,6]\n" << def;
        cout << "8. Agregar Partidas" << green << " [Se Requiere 1,2,5,6,7]\n" << def;
        cout << "9. Agregar Puntajes"<< green << " [Se Requiere 1,2,5,6,7]\n" << def;
        cout << red << "0. Atras\n" << def;
        cout << "________________________________" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("clear");
        switch (opcion){
            case 1:
                agregarDev();
            break;
            case 2:
                agregarJug();
            break;
            case 3:
                iniciarSesionDev();
            break;    
            case 4:
               iniciarSesionJug();
            break;   
            case 5:
                agregarCat();
            break;   
            case 6:
                agregarJuego();
            break;
            case 7:
                agregarSus();
            break;
            case 8:
                agregarPartidas();
            break;
            case 9:
                agregarPuntajes();
            break;
            case 10:
                agregarDev();
                agregarJug();
                agregarCat();
                agregarJuego();
                agregarSus();
                agregarPartidas();
                agregarPuntajes();
                iconUsuario->cerrarSesion();
            break;      
        } 
        pause();
    }while (opcion != 0);
}


void menuFunctionPrincipal(){
    int opcion;
    bool terminar=false;
    Perfil perfilLogueado;
    cout << "========================================================" << endl;
    cout << red <<"                     Obligatorio 2022"<< def << endl;
    cout << "By: Ezequiel Medina - Santiago Gamarra - Braian Romero - German Burgos" << endl;
    cout << "========================================================" << endl;
    iconUsuario = fabrica->getIControladorUsuario();
    iconUsuario->cerrarSesion(); //Se empieza el programa con Usuario==NULL en Sesion
    do{
        perfilLogueado=iconUsuario->getPerfilUsuarioLogueado();
        switch (perfilLogueado){
        case USUARIO:
            cout << green << "=============== Menu Principal =======================" << def <<endl;
            cout << "________________________________" << endl;
            cout << "1. Alta Usuario" << endl;
            cout << "2. Iniciar Sesion" << endl;  
            cout << "________________________________" << endl;
            cout << "19. Debug Functions"<<endl;
            cout << "________________________________" << endl;
            cout << red << "0. Salir" << def << endl;
            cout << "Opcion: ";
            cin >> opcion;
            switch (opcion){
                case 1: // Alta Usuario
                    iconUsuario = fabrica->getIControladorUsuario(); 
                    system("clear");   
                    altaUsuarioMenu();
                    break;
                case 2: // Iniciar Sesion
                    iconUsuario = fabrica->getIControladorUsuario(); 
                    system("clear");  
                    menuIniciarSesion();
                    break;
                case 19: //Funciones Debug
                    system("clear");  
                    menuFunctionDebug();
                    break;
                case 0:
                    system("clear");
                    cout << "=================================================" <<endl;
                    cout << yellow << "Tenga un Buen Dia :)"<<def<<endl;
                    cout << "=================================================" <<endl;
                    terminar=true;
                    break;
                default:
                    cout << "Error. Opcion incorrecta" << endl;
                    pause();
                    break;
            }
            break;
        case JUGADOR:
            cout << blue << "=============== Bienvenid@ Jugador =======================" <<def <<endl;
            cout << "1. Suscribirse a Videojuego" << endl; 
            cout << "2. Iniciar Partida" << endl;
            cout << "3. Ver Informacion de Videojuego"<< endl;
            cout << "________________________________" << endl;
            cout << "4. Asignar Puntuaje a Videojuego"<< endl;
            cout << "5. Cancelar Suscripcion a Videojuego"<< endl;
            cout << "6. Listar Videojuego por Categoria" << endl; 
            cout << "________________________________" << endl;
            cout << red <<"0. Cerrar Sesion" <<def<< endl;
            cout << "Opcion: ";
            cin >> opcion;
            switch (opcion){
                case 1: //Suscribirse a Videojuego
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    suscribirseAVideojuegoMenu();
                    delete iconVideojuego;
                    break;
                case 2: //Iniciar Partida
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    iniciarPartidaMenu();
                    break;
                case 3: //Ver Informacion de Videojuego
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    verInfoJuego();
                    break;
                case 4: //Asignar Puntuaje a Videojuego
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    menuPuntuarVideojuego();
                    break;
                case 5: //Cancelar Suscripcion a Videojuego
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    cancelarSuscripcionMenu();
                    break;
                case 6:  //Listar Videojuego por Categoria
                    iconCategoria=fabrica->getIControladorCategoria();
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");
                    buscarVideojuegoXCategoria();
                    break;
                case 0: //Cerrar Sesion
                    iconUsuario = fabrica->getIControladorUsuario(); 
                    iconUsuario->cerrarSesion();
                    system("clear");
                    break;
                default:
                    cout << "Error. Opcion incorrecta" << endl;
                    pause();
                    break;
            }
        break;
        case DESARROLLADOR:
                cout << red << "=============== Bienvenid@ Desarrollador =======================" <<def <<endl;
                cout << "1. Agregar Categoria" << endl; 
                cout << "2. Agregar Videojuego" << endl; 
                cout << "3. Eliminar Videojuego"<< endl; 
                cout << "4. Ver Informacion de Videojuego" << endl; 
                cout << "________________________________" << endl;
                cout << "5. Ranking de Videojuegos"<< endl;
                cout << "6. Ver Partidas de un Videojuego"<< endl; 
                cout << "7. Listar Videojuego por Categoria"<< endl;
                cout << "________________________________" << endl;
                cout << red <<"0. Cerrar Sesion" <<def<< endl;
                cout << "Opcion: ";
                cin >> opcion;
                switch (opcion){
                case 1: //Agregar Categoria
                    iconCategoria=fabrica->getIControladorCategoria();
                    system("clear");  
                    agregarCategoriaMenu();
                    break;
                case 2: //Agregar Videojuego 
                    iconCategoria=fabrica->getIControladorCategoria();
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");
                    agregarVideojuegoMenu();
                    break;
                case 3: //Eliminar Videojuego
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    menuEliminarVideojuego();
                break;
                case 4: //Ver Informacion de Videojuego
                    iconCategoria=fabrica->getIControladorCategoria();
                    system("clear");  
                    verInfoJuego();
                    break;
                case 5: //Ranking de Videojuegos
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");
                    rankingVideojuegosMenu();
                    break;
                case 6: //Ver Partidas de un Videojuego
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");  
                    menuVerPartidaVideojuegos();
                    break;
                case 7: //Listar Videojuego por Categoria
                    iconVideojuego= fabrica->getIControladorVideojuego();
                    system("clear");
                    buscarVideojuegoXCategoria();
                    break;
                case 0: //Cerrar Sesion
                    iconUsuario = fabrica->getIControladorUsuario();
                    iconUsuario->cerrarSesion();
                    system("clear");
                    break;
                default:
                    cout << "Error. Opcion incorrecta" << endl;
                    pause();
                    break;
                }
        break;
        }
    }while (!terminar);
}

//-------------------------------------Main program----------------------------------------
int main(){
    fabrica = Fabrica::getInstancia();
    system("clear");
    menuFunctionPrincipal();
    return 0;
}
