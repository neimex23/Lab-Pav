#include "ControladorVideojuego.h"


void ControladorVideojuego::seleccionJuego(string nombre){
    this->nombre = nombre;
}

void ControladorVideojuego::seleccionarTipoPago(TipoPago tipoPago){
    this->tipoPago=tipoPago;
}

void ControladorVideojuego::registrarVideojuego(string nombre,string descripcion,int costo,list<DtCategoria*> catAsociada){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->catAsociada=catAsociada;
}


void ControladorVideojuego::altaVideojuego(){
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    Sesion* sesion= Sesion::getInstancia();
    Usuario* d= sesion->getUsuario();
    if (d !=0){
        if (Desarrollador *dev = dynamic_cast<Desarrollador*>(d)){
            list<DtCategoria*> listCatAs= this->catAsociada;
            list<Categoria*> auxLista;
            for (list<DtCategoria*>::iterator iter = listCatAs.begin(); iter!=listCatAs.end(); ++iter){
                DtCategoria* dtAux= *iter;
                Categoria* aux=new Categoria(dtAux->getTipoGenero(),dtAux->getTipoPlataforma(),dtAux->getDescripcion(),dtAux->getId());
                auxLista.push_back(aux);
            }
            Juego* j= new Juego(this->nombre,this->descripcion,this->costo,auxLista,dev);
            mv->agregarVideojuego(j);          
        }else{
            throw invalid_argument("Acceso Denegado: Debes ser Desarollador.");
        }
    }else{
        throw invalid_argument("Debes Iniciar Sesion");
    }
    
}

DtFechaHora* ControladorVideojuego::takeTime(){
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
    return new DtFechaHora(day, month, year, hour, minute);
}

void ControladorVideojuego::cancelarVideojuego(){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Juego* juego = mv->buscarVideojuego(this->nombre);
    list<Suscripcion*> suscripcionList = juego->getSuscripciones();
    for(auto const&suscripcion : suscripcionList)
        if(suscripcion->getJugador() != 0 && Sesion::getInstancia()->getUsuario()->getEmail() == suscripcion->getJugador()->getEmail())
            suscripcion->setJugador(NULL);
}

void ControladorVideojuego::suscribirseAVideojuego(){
    Sesion* s = Sesion::getInstancia();
    Usuario* u = s->getUsuario();
    if(u != 0){
        if (dynamic_cast<Jugador*>(u)){
            ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
            if(mv->existeVideojuego(this->nombre)){
                  Juego* juego = mv->buscarVideojuego(this->nombre);
                  list<Suscripcion*> suscripcionList= juego->getSuscripciones();
                  if(suscripcionList.size() != 0){
                    for(list<Suscripcion*>::iterator it = suscripcionList.begin(); it != suscripcionList.end(); it++){
                        if((*it)->getJugador() != 0 && (*it)->getJugador()->getEmail() == u->getEmail())
                            throw invalid_argument("Ya tiene una suscripcion activa a este juego");                           
                    }
                  }
                    Suscripcion* suscripcion = new Suscripcion(takeTime(),this->tipoPago,dynamic_cast<Jugador*>(u));
                    juego->setSuscripciones(suscripcion);     
            } else 
                throw invalid_argument("No existe videojuego");
        }else
            throw invalid_argument("La Sesion debe ser Jugador");
    }else
        throw invalid_argument("Debe iniciar sesion");

}

void ControladorVideojuego::iniciarPartida(){
    Sesion* sesion = Sesion::getInstancia();
    Jugador* jugador = dynamic_cast<Jugador*>(sesion->getUsuario());
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    if(mv->existeVideojuego(this->nombre)){
        Juego* juego = mv->buscarVideojuego(this->nombre);
        if(juego->tieneSuscripcionActiva(jugador)){
            if(this->esPartidaIndividual){
                PartidaIndividual* partida = new PartidaIndividual(jugador, takeTime(), this->duracion, this->continuaPartidaAnterior);               
                juego->setPartidas(partida);
            } else {
                PartidaMultijugador* partida = new PartidaMultijugador(jugador, takeTime(), this->duracion, this->transmitidaEnVivo, this->cantJugadores);
                juego->setPartidas(partida);
            }
           juego->setTotalHoras(this->duracion);
        } else {
            throw invalid_argument("No tiene suscripcion activa");
        }
    }else {
            throw invalid_argument("No existe videojuego");
    }
}

list<DtJuego*> ControladorVideojuego::verInformacionVideojuegos(){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<DtJuego*> dtJuegos;
    list<Juego*> listVideoJuegos = mv->getVideojuegos();
    for (list<Juego*>::iterator iter = listVideoJuegos.begin(); iter != listVideoJuegos.end(); iter++){
        dtJuegos.push_back(new DtJuego((*iter)->getNombre(), (*iter)->getDescripcion(), (*iter)->getCosto()));
    }
    return dtJuegos;
}


bool ControladorVideojuego::containsList(list<DtJuego*> videojuegosList, string videojuego){
    for(auto const&juego : videojuegosList)
        if(juego->getNombre() == videojuego)
            return true;
    return false;
}

map<string,list<DtJuego*> > ControladorVideojuego::listarVideojuegosXSuscripcion(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Juego*> listVideoJuegos = mv->getVideojuegos();
    list<DtJuego*> suscripcionesJuego;
    list<DtJuego*> sinSuscripcionesJuego;
    map<string,list<DtJuego*> > suscripcionesMap;
    for (list<Juego*>::iterator iter = listVideoJuegos.begin(); iter != listVideoJuegos.end(); iter++){
        list<Suscripcion*> suscripciones = (*iter)->getSuscripciones();
        list<DtSuscripcion*> dtSuscripciones;
        if(suscripciones.size()!=0){
            for (list<Suscripcion*>::iterator iter2 = suscripciones.begin(); iter2 != suscripciones.end(); iter2++){
                Jugador* jugador = (*iter2)->getJugador();
                if(jugador!=0){
                    if(jugador->getEmail()==sesion->getUsuario()->getEmail()){
                        DtJugador* dtJugador = new DtJugador(jugador->getEmail(),jugador->getContrasenia(),jugador->getNickname(),jugador->getDescripcion());
                        dtSuscripciones.push_back(new DtSuscripcion((*iter2)->getFechaHora(),(*iter2)->getTipoPago(),dtJugador));
                        suscripcionesJuego.push_back(new DtJuego((*iter)->getNombre(),(*iter)->getCosto(),dtSuscripciones));
                    } 
                }
            }
        }
    }
    for(auto const&juego : listVideoJuegos)
        if(!containsList(suscripcionesJuego,juego->getNombre()))
             sinSuscripcionesJuego.push_back(new DtJuego(juego->getNombre(),juego->getCosto()));
             
    suscripcionesMap.insert(pair<string,list<DtJuego*> >("activos",suscripcionesJuego));
    suscripcionesMap.insert(pair<string,list<DtJuego*> >("inactivos",sinSuscripcionesJuego));
    return suscripcionesMap;
}



void ControladorVideojuego::seleccionarVideojuego(string nombreVideojuego){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    if(mv->existeVideojuego(nombreVideojuego)){
        this->nombre=nombreVideojuego;
    }
}

DtJuegoFull* ControladorVideojuego::getVideojuegoFull(string nombreVideojuego){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    Juego* juego;
    list<Categoria*> categorias;
    list<DtCategoria*> dtCategorias;

    if(mv->existeVideojuego(nombreVideojuego)){
        juego = mv->buscarVideojuego(nombreVideojuego);
        categorias = juego->getCategorias();
        for (list<Categoria*>::iterator i = categorias.begin(); i!= categorias.end(); i++){
            dtCategorias.push_back(new DtCategoria((*i)->getTipoGenero(),(*i)->getTipoPlataforma(),(*i)->getDescripcion(),(*i)->getId()));
        }
        return new DtJuegoFull(juego->getNombre(),juego->getDescripcion(),new DtDesarrollador(juego->getDesarrollador()->getNombreEmpresa()),juego->getCosto(),juego->getTotalHoras(),juego->getPromedio(),dtCategorias);
    }else
        throw invalid_argument("No existe videojuego");
}

void ControladorVideojuego::datoIndividual(bool continuaPartida,int duracion){
    this->duracion=duracion;
    this->continuaPartidaAnterior=continuaPartida;
    this->esPartidaIndividual=true;
}

void ControladorVideojuego::datoMultijugador(bool transmitidaEnVivo,int cantJugadores,int duracion){
    this->duracion=duracion*cantJugadores;
    this->transmitidaEnVivo=transmitidaEnVivo;
    this->cantJugadores=cantJugadores;
    this->esPartidaIndividual=false;
}

bool ControladorVideojuego::existeVideojuego(string nombre){
    ManejadorVideojuego* mc= ManejadorVideojuego::getInstancia();
    return mc->existeVideojuego(nombre);
}

list<string> ControladorVideojuego::listarVideojuegosDesarrollador(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    list<Juego*> juegos = mv->getVideojuegos();
    list<string> nombresJuegosDesarrollador;
    for (list<Juego*>::iterator iter = juegos.begin(); iter != juegos.end(); iter++){
        if((*iter)->getDesarrollador()->getEmail()==sesion->getUsuario()->getEmail()){
            nombresJuegosDesarrollador.push_back((*iter)->getNombre());
        }
    }
    return nombresJuegosDesarrollador;
}

list<DtJuego*> ControladorVideojuego::listarVideojuegos(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    list<Juego*> juegos = mv->getVideojuegos();
    list<DtJuego*> dtJuegos;
    for (list<Juego*>::iterator iter = juegos.begin(); iter != juegos.end(); iter++){
        dtJuegos.push_back(new DtJuego((*iter)->getNombre(),(*iter)->getDescripcion()));
    }
    return dtJuegos;
}

void ControladorVideojuego::eliminarVideojuego(){
    Usuario* usuario = Sesion::getInstancia()->getUsuario();
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    string emailDevLogueado=dynamic_cast<Desarrollador*>(usuario)->getEmail();
    string emailDevDelVideojuego=mv->buscarVideojuego(this->nombre)->getDesarrollador()->getEmail();
    if(mv->existeVideojuego(this->nombre) && emailDevDelVideojuego==emailDevLogueado){
        Juego* juego = mv->buscarVideojuego(this->nombre);
        mv->eliminarVideojuego(juego->getNombre());
        juego->~Juego();

    } else {
        throw invalid_argument("No existe videojuego");
    }
}

void ControladorVideojuego::datoPuntaje(int puntaje){
    this->puntaje=puntaje;
}

void ControladorVideojuego::asignarPuntaje(){
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    Usuario* usuario = Sesion::getInstancia()->getUsuario();
    Jugador* jugador = dynamic_cast<Jugador*>(usuario);
    Juego* juego = mv->buscarVideojuego(this->nombre);   
    Estadistica* estadistica=new Estadistica(this->puntaje,jugador);
    juego->setEstadisticas(estadistica);

    //Actualiza
    float promedioLocal=0;
    list <Estadistica*> listEstadisticas= juego->getEstadisticas();
        for (list<Estadistica*>::iterator iter = listEstadisticas.begin(); iter != listEstadisticas.end(); iter++)
            promedioLocal+=((*iter)->getPuntaje());
        promedioLocal/=listEstadisticas.size();
        juego->setPromedio(promedioLocal);
}

bool ControladorVideojuego::isEmpty(){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    return (mv->getVideojuegos().size() == 0);
}


bool ControladorVideojuego::isSub(){
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    Juego* juego = mv->buscarVideojuego(this->nombre);
    Usuario* usuario = Sesion::getInstancia()->getUsuario();
    Jugador* j=dynamic_cast<Jugador*>(usuario);
    return juego->tieneSuscripcionActiva(j);
}


bool ControladorVideojuego::jugadorPuntuo(){
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    Usuario* usuario= Sesion::getInstancia()->getUsuario();
    Juego* juego = mv->buscarVideojuego(this->nombre);
    list<Estadistica*> listEstadistica=juego->getEstadisticas();
    for (list<Estadistica*>::iterator iter = listEstadistica.begin(); iter != listEstadistica.end(); iter++){
        if (((*iter)->getJugador()->getEmail())== usuario->getEmail()){
            return true;
        }
    }
    return false;
}

list<DtJuego*> ControladorVideojuego::listarVideojuegosOrdenados(int opcion){
    ManejadorVideojuego* mv = ManejadorVideojuego::getInstancia();
    list<Juego*> juegosList = mv->getVideojuegos();
    list<DtJuego*> dtJuegosList;
    list<DtJuego*> newListDt;
    DtJuego* aux;

    for(auto const& juego : juegosList)
        dtJuegosList.push_back(new DtJuego(juego->getNombre(),juego->getDescripcion(),juego->getPromedio(),juego->getTotalHoras()));
    

    if(dtJuegosList.size() != 0){
        if(opcion == 1){
            for(auto const&dtJuego : dtJuegosList){
                aux = dtJuego;
                for(auto const&dtJuegoAux : dtJuegosList){
                    if(!containsList(newListDt, aux->getNombre())){
                        if(dtJuegoAux->getPromedio() >= aux->getPromedio() && !containsList(newListDt, dtJuegoAux->getNombre()))
                            aux = dtJuegoAux;                
                    }else if(!containsList(newListDt, dtJuegoAux->getNombre()))
                        aux = dtJuegoAux; 
                }   
                newListDt.push_back(aux);
            }
        }else if(opcion == 2){
            for(auto const&dtJuego : dtJuegosList){
                aux = dtJuego;
                for(auto const&dtJuegoAux : dtJuegosList){
                    if(!containsList(newListDt, aux->getNombre())){
                        if(dtJuegoAux->getTotalHoras() >= aux->getTotalHoras() && !containsList(newListDt, dtJuegoAux->getNombre()))
                            aux = dtJuegoAux;                
                    }else if(!containsList(newListDt, dtJuegoAux->getNombre()))
                        aux = dtJuegoAux; 
                }   
                newListDt.push_back(aux);
            }
        }else
            throw invalid_argument("Opcion invalida");
    } else 
        throw invalid_argument("No hay videojuegos en el sistema");

    return newListDt;
}




list<DtPartida*> ControladorVideojuego::getDtPartidas(){
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();
    Juego* juego= mv->buscarVideojuego(this->nombre);
    list<Partida*> listPartidas = juego->getPartidas();
    list<DtPartida*> listDtPartidas;
    DtJugador* dtAuxJ;
    DtPartida* dtAuxP;
    DtPartidaIndividual dtAuxPi;
    DtPartidaMultijugador dtAuxPm;
    for (list<Partida*>::iterator iter=listPartidas.begin(); iter!=listPartidas.end(); ++iter){
        dtAuxJ= new DtJugador((*iter)->getJugador()->getEmail(),(*iter)->getJugador()->getContrasenia(),(*iter)->getJugador()->getNickname(),(*iter)->getJugador()->getDescripcion());
        if(PartidaIndividual * pi = dynamic_cast<PartidaIndividual*>(*iter)){
            DtPartidaIndividual* dpi= new DtPartidaIndividual((*iter)->getFechaHora(),(*iter)->getDuracion(),pi->getContinuaPartidaAnterior());
            dtAuxP=dynamic_cast<DtPartida*>(dpi);
        }else{
            if (PartidaMultijugador * pm = dynamic_cast<PartidaMultijugador*>(*iter)){
                DtPartidaMultijugador* dpm=new DtPartidaMultijugador((*iter)->getFechaHora(),(*iter)->getDuracion(),pm->getTransmitidaEnVivo(),pm->getCantJugadores());DtPartida((*iter)->getFechaHora(),dtAuxJ,(*iter)->getDuracion());
                dtAuxP=dynamic_cast<DtPartida*>(dpm);
            }
        }
        listDtPartidas.push_back(dtAuxP);
    }
    return listDtPartidas;
}

void ControladorVideojuego::datoId(int id){
    this->idCat=id;
}

list<DtJuego*> ControladorVideojuego:: buscarVideojuegoXCategoria(){
    ManejadorVideojuego* mv= ManejadorVideojuego::getInstancia();  
    list<Juego*> j=mv->getVideojuegos();
    list<Categoria*> aux;
    list<DtJuego*> dtListAux;
    DtJuego* dtJAux; 
    for (list<Juego*>::iterator iter=j.begin(); iter!=j.end();++iter){
        aux=(*iter)->getCategorias();
        for (list<Categoria*>::iterator i=aux.begin(); i!=aux.end();++i){
            if((*i)->getId()==this->idCat){
                dtJAux=new DtJuego((*iter)->getNombre(),(*iter)->getDescripcion());
                dtListAux.push_back(dtJAux);
            }
        }   
    }
    return dtListAux;
}



