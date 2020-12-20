// Filename: monitor.h
// Description: Contiene las definiciones de los metodos de la clase Monitor

#ifndef MONITOR_H
#define MONITOR_H
#include "persona.h"
#include <iostream>

using namespace std;

class Monitor:public Persona{
private:
    string direccion_;
    int telefono_;
    bool aforo_;
    int Max_;
public:
    inline Monitor(string direccion="",int telefono=0,string nombre="",string apellido1="",string apellido2="",string dni="",string correo="",int edad=0,bool aforo=false,int max=0):Persona(nombre,apellido1,apellido2,dni,correo,edad)
    {setDireccion(direccion);setTelefono(telefono);};
    void iniciarSesionMonitor();
    inline void setDireccion(string check){direccion_=check;};
    inline string getDireccion()const{return direccion_;};
    inline void setTelefono(int check){telefono_=check;};
    inline int getTelefono()const{return telefono_;};
    inline void setAforo(int check){Max_=check;};
    inline bool getAforo(int check){if(check > Max_){aforo_=true;return aforo_;}};
};

#endif