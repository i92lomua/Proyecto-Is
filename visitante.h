// Filename: visitante.h
// Description: Contiene la definicion de los metodos de la clase Visitante

#ifndef VISITANTE_H
#define VISITANTE_H
#include <iostream>
#include "persona.h"

using namespace std;

class Visitante:public Persona{
private:
    int telefono_;
    string estadoSalud_;
public:
    inline Visitante(int telefono,string estadoSalud,string nombre,string apellido1,string apellido2,string dni,string correo,int edad):Persona(nombre,apellido1,apellido2,dni,correo,edad)
    {setTelefono(telefono);setEstadoSalud(estadoSalud);};
    inline void setTelefono(int check){telefono_=check;};
    inline int getTelefono()const{return telefono_;};
    inline void setEstadoSalud(string check){estadoSalud_=check;};
    inline string getEstadoSalud()const{return estadoSalud_;};
};

#endif