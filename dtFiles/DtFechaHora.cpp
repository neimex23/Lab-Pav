#include "DtFechaHora.h"

DtFechaHora::DtFechaHora(){}

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int minuto){
    if(dia<1 || dia>31 || mes<1 || mes>12 || anio<1900)
        throw invalid_argument("Fecha no valida\n");
    else{
        this->dia=dia;
        this->mes=mes;
        this->anio=anio;
        this->hora=hora;
        this->minuto=minuto;
    }
}

int DtFechaHora::getDia(){
    return this->dia;
}

int DtFechaHora::getMes(){
    return this->mes;
}

int DtFechaHora::getAnio(){
    return this->anio;
}

int DtFechaHora::getHora(){
    return this->hora;
}

int DtFechaHora::getMinuto(){
    return this->minuto;
}

ostream& operator<<(ostream& salida,DtFechaHora& fecha){
    cout << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << " " << fecha.getHora() << ":" << fecha.getMinuto();
    return salida;
}

DtFechaHora::~DtFechaHora(){}