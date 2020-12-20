// Filename: reserva.h
// Description: Contiene la definicion de los metodos de la clase Reserva

#ifndef RESERVA_H
#define RESERVA_H
#include <iostream>
using namespace std; 

class Reserva{
private:
    string codReserva_; //DNI del visitante (para enlazar las reservas al visitante)
    string hora_;
    string fecha_;
public:
    inline Reserva(string codReserva,string hora, string fecha){codReserva_=codReserva;hora_=hora;fecha_=fecha;};
    //GETS
    inline string getHora()const{return hora_;};
    inline string getFecha()const{return fecha_;};
    inline string getCodigo()const{return codReserva_;};
    //SETS
    inline void setHora(string hora){hora_=hora;};
    inline void setFecha(string fecha){fecha_=fecha;};
};

#endif