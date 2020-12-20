// Filename: persona.h
// Description: Contiene la definicion de los metodos de la clase Persona

#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona{
private:
    string nombre_;
    string apellido1_;
    string apellido2_;
    string DNI_;
    string correo_;
    int edad_;
public:
    inline Persona(string nombre="", string apellido1="", string apellido2="", string DNI="", string correo="", int edad=0){
        nombre_=nombre;
        apellido1_=apellido1;
        apellido2_=apellido2;
        DNI_=DNI;
        correo_=correo;
        edad_=edad;
    }
    //GETS
    inline string getNombre()const{return nombre_;}
    inline string getApellido1()const{return apellido1_;}
    inline string getApellido2()const{return apellido2_;}
    inline string getDni()const{return DNI_;}
    inline string getCorreo()const{return correo_;}
    inline int getEdad()const{return edad_;}
    //SETS
    inline void setNombre(string nombre){nombre_=nombre;}
    inline void setApellido1(string apellido1){apellido1_=apellido1;}
    inline void setApellido2(string apellido2){apellido2_=apellido2;}
    inline void setDni(string DNI){DNI_=DNI;}
    inline void setCorreo(string correo){correo_=correo;}
    inline void setEdad(int edad){edad_=edad;}
};

#endif