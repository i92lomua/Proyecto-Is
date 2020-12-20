// Filename: main.cpp
// Description: Main que implementa un menu de seleccion y comportamiento para el usuario

#include <iostream>
#include "administrador.h"

using namespace std;

int main(void){

Administrador admin;
int option;
string psswrd;

do{
    cout << "\n<---------------> Modo Inicio Sesion <----------------->\n";
    cout << "1.- Administrador";
    cout << "\n2.- Monitor";
    cout << "\n3.- Salir Programa";
    cout << "\nOPCION: ";
    cin >> option;
    system("clear");

    switch(option){
        case 1: admin.iniciarSesionAdmin();
                int select;
                do{
                    cout << "\n<------------> ADMINISTRADOR <-------------->";
                    cout << "\n1.- Modificar Contraseña";
                    cout << "\n2.- Añadir Nuevo Parque al sistema";
                    cout << "\n3.- Imprimir informacion del parque";
                    cout << "\n4.- Eliminar parque del sistema";
                    cout << "\n5.- Nueva Reserva";
                    cout << "\n6.- Imprimir informacion de una reserva";
                    cout << "\n7.- Eliminar Reserva";
                    cout << "\n8.- Imprimir informacion visitante";
                    cout << "\n9.- Añadir actividad al parque";
                    cout << "\n10.- Imprimir informacion de actividad";
                    cout << "\n11.- Eliminar Actividad del parque";
                    cout << "\n12.- Contratar Monitor";
                    cout << "\n13.- Imprimir informacion monitor";
                    cout << "\n14.- Eliminar monitor de plantilla";
                    cout << "\n15.- Asignar Actividad a monitor";
                    cout << "\n16.- Eliminar Asignacion de actividad";
                    cout << "\n17.- Modificar datos Visitante";
                    cout << "\n18.- Modificar datos Monitor";
                    cout << "\n19.- Volver Atras";
                    cout << "\nOPCION: ";
                    cin >> select;

                    system("clear");

                    switch(select){
                        case 1: 
                                cout << "\nNueva Contraseña: ";
                                cin >> psswrd;
                                admin.setContrasena(psswrd);
                                cout << "\nContraseña Actualizada con EXITO\n";
                                break;
                        case 2: admin.setArea(); break;
                        case 3: admin.getArea(); break;
                        case 4: admin.eliminarArea(); break;
                        case 5: admin.setReserva(); break;
                        case 6: admin.getReserva(); break;
                        case 7: admin.eliminarReserva(); break;
                        case 8: admin.getVisitante(); break;
                        case 9: admin.setActividad(); break;
                        case 10: admin.getActividad(); break;
                        case 11: admin.eliminarActividad(); break;
                        case 12: admin.setMonitor(); break;
                        case 13: admin.getMonitor(); break;
                        case 14: admin.eliminarMonitor(); break;
                        case 15: admin.asignarActividad(); break;
                        case 16: admin.eliminarAsignacion(); break;
                        case 17: admin.modVisitante(); break;
                        case 18: admin.modMonitor(); break;
                    }
                }while(select!=19);
                break;
        case 2: if(admin.getnTrabajadores() == 0){cout << "\nERROR no hay ningun monitor registrado en el sistema aun\n\n";}
                else{
                    int option,aforo;
                    Monitor m;
                    do{
                        cout << "\n<----------------> MONITORES <----------------->\n";
                        cout << "\n1.- Imprimir lista actividades";
                        cout << "\n2.- Imprimir lista de Visitantes";
                        cout << "\n3.- Volver Atras";
                        cout << "\nOPCION: ";
                        cin >> option;

                        system("clear");

                        switch(option){
                            case 1: admin.getListaActividades();
                                    break;
                            case 2: admin.getListaVisitantes();
                                    break;
                        }
                    }while(option!=3);
                }
                break;
    }
}while(option!=3);

    return 0;
}