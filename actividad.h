// Filename: actividad.h
// Description: Contiene las definiciones de los metodos de la clase Actividad

#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <iostream>
#include "area.h"

using namespace std;

class Actividad:public Area{
private: 
    int identificador_;
    int dificultad_;
    int medio_;
    string asignacion_;
    string ubicacion_;
public:
    inline Actividad(int id,int dificultad,int medio,string ubicacion,string asignacion="NINGUNA"){setIdentificador(id);setDificultad(dificultad);setMedio(medio);};
    inline void setUbicacion(string check){ubicacion_=check;};
    inline string getUbicacion()const{return ubicacion_;};
    inline void setIdentificador(int check){identificador_=check;};
    inline int getIdentificador()const{return identificador_;};
    inline void setDificultad(int check){dificultad_=check;};
    inline int getDificultad()const{return dificultad_;};
    inline void setMedio(int check){medio_=check;};
    inline int getMedio()const{return medio_;};
    inline void setAsignacion(string check){asignacion_=check;};
    inline string getAsignacion()const{return asignacion_;};
};


#endif