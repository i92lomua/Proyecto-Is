// Filename: administrador.h
// Description: Contiene las definiciones de los metodos de la clase administrador

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "persona.h"
#include "area.h"
#include "visitante.h"
#include "reserva.h"
#include "actividad.h"
#include "monitor.h"
#include <list>

class Administrador: public Persona,public Area{
private:
    string contrasena_;
    list<Area> areas_;
    list<Visitante> visitantes_;
    list<Reserva> reservas_;
    list<Actividad> actividades_;
    list<Monitor> plantilla_;
    int ntrabajadores_;
public:
    inline Administrador(string contrasena="admin",int ntrabajadores=0){setContrasena(contrasena);}
    void iniciarSesionAdmin();
    inline void setContrasena(string contrasena){contrasena_=contrasena;};
    inline void setnTrabajadores(){ntrabajadores_=plantilla_.size();};
    inline int getnTrabajadores()const{return ntrabajadores_;};
    void getArea();
    void setArea();
    void eliminarArea();
    void setReserva();
    void getReserva()const;
    void eliminarReserva();
    void getVisitante()const;
    void setActividad();
    void getActividad();
    void eliminarActividad();
    void setMonitor();
    void getMonitor()const;
    void eliminarMonitor();
    void asignarActividad();
    void eliminarAsignacion();
    void getListaActividades()const;
    void getListaVisitantes()const;
    void modVisitante();
    void modMonitor();
};

#endif