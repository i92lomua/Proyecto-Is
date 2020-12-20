// Filename: area.h
// Description: Contiene la definicion de los metodos de la clase Area
#ifndef AREA_H
#define AREA_H
#include <iostream>
#include <list>
using namespace std;

class Area{
private:
    string ubicacion_;
    int extension_;
    string premios_;
    int estado_;
    int fechaConst_;
public:
    inline Area(string ubicacion="", int extension=0, string premios="", int estado=0, int fechaConst=0){
    setUbicacion(ubicacion);
    setExtension(extension);
    setPremios(premios);
    setEstado(estado);
    setFechaConst(fechaConst);
    };
    //GETS
    inline string getUbicacion()const{return ubicacion_;};
    inline int getExtension()const{return extension_;};
    inline string getPremios()const{return premios_;};
    inline int getEstado()const{return estado_;};
    inline int getFechaConst()const{return fechaConst_;};
    //SETS
    inline void setUbicacion(string ubicacion){ubicacion_=ubicacion;};
    inline void setExtension(int extension){extension_=extension;};
    inline void setPremios(string premios){premios_=premios;};
    inline void setEstado(int estado){estado_=estado;};
    inline void setFechaConst(int fechaConst){fechaConst_=fechaConst;};
};

#endif