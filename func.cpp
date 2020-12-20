// Filename: administrador.cpp
// Description: Contiene el codigo de los metodos de la clase administrador
#include "administrador.h" 
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Funcion que permite iniciar sesion como administrador en el sistema
void Administrador::iniciarSesionAdmin(){
    string check;
    cout << "<-------------> INICIO SESION <------------->\n";
    cout <<  "\nContraseña: "; // La contraseña por defecto de administrador es 'admin'
    cin >> check;

    if(check == contrasena_){
        cout << "\nAccediendo al sistema como ADMINISTRADOR.";
    }else{
        cout << "\nERROR Contraseña incorrecta";
        cout << "\nSI ES LA PRIMERA VEZ QUE ACCEDE AL SISTEMA LA CONTRASEÑA DEBE SER LA DE POR DEFECTO DEL SISTEMA\n\n";
        exit(-1);
    }
}

// Funcion que busca por UBICACION el area en el sistema e imprime sus datos por pantalla
void Administrador::getArea(){
    string ubi;
    list<Area>::iterator i;
    bool find=false;

    cout << "\nIntroduzca la Ubicacion del Area: ";
    cin >> ubi;

    for(i=areas_.begin();i!=areas_.end();i++){
     if((*i).getUbicacion() == ubi){
         cout << "\nEl area se encuentra registrada en el sistema.\n";
         cout << "Ubicacion: " << (*i).getUbicacion() << endl;
         cout << "Extension: " << (*i).getExtension() << " km2" << endl;
         cout << "Premios: " << (*i).getPremios() << endl;
         if((*i).getEstado() == 0){
             cout << "Estado: Disponible" << endl;
         }else{
             cout << "Estado: NO Disponible" << endl;
         }
         cout << "Fecha Constitucion: " << (*i).getFechaConst() << endl;
         find=true;
     }
    }
    if(!find){cout << "\nEl area No se encuentra registrada en el sistema.\n\n";}
}

// Funcion que permite registrar un nuevo area en el sistema
void Administrador::setArea(){
    string ubi,premios;
    int ext,fecha;

    cout << "\n<----------> Nuevo Area <---------->\n";
    cout << "\nIntroduzca la ubicacion del Area: ";
    cin >> ubi;
    cout << "\nIntroduzca la extension del Area en km2: ";
    cin >> ext;
    cout << "\nIntroduzca los premios del Area(premio1-premio2-...-): ";
    cin >> premios;
    cout << "\nIntroduzca la fecha de constitucion del Area(dd-mm-aa): ";
    cin >> fecha;

    Area aux(ubi,ext,premios,0,fecha);
    areas_.push_back(aux);
    cout << "\nEl parque ha sido añadido al sistema con EXITO\n\n";
}

// Funcion que elimina un area del sistema introduciendo su ubicacion
void Administrador::eliminarArea(){
    list<Area>::iterator i;
    string ubi;
    bool find=false;
    cout << "\nIntroduzca la ubicacion del area a eliminar: ";
    cin >> ubi;

    for(i=areas_.begin();i!=areas_.end();i++){
        if(ubi == (*i).getUbicacion()){
            areas_.erase(i);
            cout << "\nArea borrada con EXITO\n";
            find=true;
        }
    }
    if(!find){cout << "\nEl area NO se encuentra registrada en el sistema\n";}
}

// Funcion que registra nuevas reservas en el sistema
void Administrador::setReserva(){
    list<Reserva>::iterator i;
    string nombre,apell1,apell2,dni,correo,estado,hora,fecha;
    int edad,tel;

    cout << "\n<----------> Nueva Reserva <----------->\n";
    cout << "Nombre: ";
    cin >> nombre;
    cout << "\nPrimer Apellido: ";
    cin >> apell1;
    cout << "\nSegundo Apellido: ";
    cin >> apell2;
    cout << "\nDNI: ";
    cin >> dni;
    cout << "\nCorreo: ";
    cin >> correo;
    cout << "\nEdad: ";
    cin >> edad;
    cout << "\nTelefono: ";
    cin >> tel;
    cout << "\n¿Dolencias?: ";
    cin >> estado;

    Visitante aux(tel,estado,nombre,apell1,apell2,dni,correo,edad);
    visitantes_.push_back(aux);

    cout << "\n<------------> Horario Reserva <------------>\n";
    cout << "Hora Reserva(hh:mm): ";
    cin >> hora;
    cout << "\nFecha Reserva(dd-mm-aa): ";
    cin >> fecha;

    Reserva r(dni,hora,fecha);

    for(i=reservas_.begin();i!=reservas_.end();i++){
        if((dni == (*i).getCodigo()) && fecha == ((*i).getFecha())){
            cout << "\nERROR ya tiene una reserva en esa fecha eliga otra\n\n";
        }
    }
    reservas_.push_back(r);
    cout << "\nLa reserva se ha registrado con EXITO\n";
}

// Funcion que permite ver la informacion de las reservas del visitantes buscando por su dni
void Administrador::getReserva()const{
    list<Reserva>::const_iterator i;
    string dni;
    bool find=false;
    cout << "\nIntroduzca el dni del visitante para ver la informacion de la reserva ";
    cin >> dni;

    for(i=reservas_.begin();i!=reservas_.end();i++){
        if(dni == (*i).getCodigo()){
            cout << "\n<----------> Informacion de la Reserva <---------->\n";
            cout << "Visitante: " << (*i).getCodigo() << endl;
            cout << "Fecha reserva: " << (*i).getFecha() << endl;
            cout << "Hora reserva: " << (*i).getHora() << endl;
            find=true;
        }
    }
    if(!find){cout << "\nAun no hay reservas registradas con ese dni\n\n";}
}

// Funcion que eliminar reservas de la lista de reservas
void Administrador::eliminarReserva(){
    list<Reserva>::iterator i;
    list<Visitante>::iterator j;
    string dni;
    bool find=false;
    
    cout << "\n<-----------> Eliminar Reserva <----------->\n";
    cout << "Introduzca el dni del visitante ";
    cin >> dni;
    for(i=reservas_.begin();i!=reservas_.end();i++){
        if(dni == (*i).getCodigo()){
            i=reservas_.erase(i);
            cout << "\nReserva Borrada con exito\n\n";
            find=true;
        }
    }
    for(j=visitantes_.begin();j!=visitantes_.end();j++){
        if(dni == (*j).getDni()){
            j=visitantes_.erase(j);
            cout << "\nVisitante Borrado con exito\n\n";
            find=true;
        }
    }

    if(!find){cout << "\nERROR La reserva que busca no esta registrada\n\n";}
}

// Funcion que imprime por pantalla la informacion personal de un visitante buscado por el dni
void Administrador::getVisitante()const{
    list<Visitante>::const_iterator i;
    string dni;
    bool find=false;

    cout << "Introduce el dni del visitante para ver su informacion personal ";
    cin >> dni;

    for(i=visitantes_.begin();i!=visitantes_.end();i++){
        if(dni == (*i).getDni()){
            cout << "\n<-----------> Datos Personales <---------->\n";
            cout << "Nombre: " << (*i).getNombre() << endl;
            cout << "Apellidos: " << (*i).getApellido2() << ", " << (*i).getApellido1() << endl;
            cout << "Edad: " << (*i).getEdad() << endl;
            cout << "DNI: " << (*i).getDni() << endl;
            cout << "Telefono: " << (*i).getTelefono() << endl;
            cout << "Correo: " << (*i).getCorreo() << endl;
            cout << "Dolencias: " << (*i).getEstadoSalud() << endl;
            find=true;
        }
    }
    if(!find){cout << "\nERROR el visitante no se encuentra registrado en el sistema\n\n";}
}

// Funcion que añade actividades al area
void Administrador::setActividad(){
    list<Area>::iterator i;
    int dif,medio,id;
    string ubi;

    cout << "\n<------------> Nueva Actividad <------------->\n";
    cout << "Dificultad(1=basico,2=medio,3=avanzado): "; // 1= Basico, 2= Medio, 3= Avanzado
    cin >> dif;
    cout << "\nMedio(1=pie,2=bici,3=pie/bici): "; // 1= Pie, 2= Bicicleta, 3= Pie o Bicicleta
    cin >> medio;
    cout << "\nUbicacion Parque: ";
    cin >> ubi;
    cout << "\nIdentidicador Numerico: ";
    cin >> id;

    if(areas_.size() == 0){
        cout << "\nERROR no hay ningun parque registrado para asignarle actividades\n\n";
    }else{

        for(i=areas_.begin();i!=areas_.end();i++){
            if(ubi == (*i).getUbicacion()){
                Actividad aux(id,dif,medio,ubi);
                actividades_.push_back(aux);
                cout << "\nActividad registrada con EXITO\n\n";
            }else{
                cout << "\nERROR debe asignar una ubicacion almacenada para añadir la actividad al parque\n\n";
            }
        }
    }
}

// Funcion que devuelve la informacion de una actividad buscada por su identificador
void Administrador::getActividad(){
    list<Actividad>::iterator i;
    int id;
    bool find=false;
    cout << "\nIntroduzca el identificador de la actividad ";
    cin >> id;

    for(i=actividades_.begin();i!=actividades_.end();i++){
        if(id == (*i).getIdentificador()){
            cout << "Actividad: " << (*i).getIdentificador() << endl;
            cout << "Ubicacion: " << (*i).getUbicacion() << endl;
            cout << "Dificultad: ";
            switch((*i).getDificultad()){
                case 1: cout << "Basico" << endl;
                        break;
                case 2: cout << "Medio" << endl;
                        break;
                case 3: cout << "Avanzado" << endl;
                        break;
            }
            cout << "Medio: ";
            switch((*i).getMedio()){
                case 1: cout << "Ruta a Pie" << endl;
                        break;
                case 2: cout << "Ruta en Bicicleta" << endl;
                        break;
                case 3: cout << "Ruta Pie/Bicicleta" <<  endl;
                        break;
            }
            find=true;
        }
    }
    if(!find){cout << "\nERROR no hay actividades con el identificador introducido en el sistema\n\n";}
}

// Funcion que elimina las actividades de una ubicacion
void Administrador::eliminarActividad(){
    list<Actividad>::iterator i;
    int id;
    bool find=false;
    cout << "Introduzca el identificador de la actividad ";
    cin >> id;

    for(i=actividades_.begin();i!=actividades_.end();i++){
        if(id == (*i).getIdentificador()){
            i=actividades_.erase(i);
            cout << "\nLa actividad se ha eliminado con EXITO\n\n";
            find=true;
        }
    }
    if(!find){cout << "\nERROR no existe esa actividad en el sistema\n\n";}
}

// Funcion que añade a la plantilla de trabajadores nuevos monitores
void Administrador::setMonitor(){
    string nombre,apell1,apell2,dni,correo,direccion;
    int edad,tlf;

    cout << "\n<-----------> Nuevo Monitor <------------>\n";
    cout << "Nombre: ";
    cin >> nombre;
    cout << "\nPrimer Apellido: ";
    cin >> apell1;
    cout << "\nSegundo Apellido: ";
    cin >> apell2;
    cout << "\nDNI: ";
    cin >> dni;
    cout << "\nCorreo: ";
    cin >> correo;
    cout << "\nEdad: ";
    cin >> edad;
    cout << "\nDireccion: ";
    cin >> direccion;
    cout << "\nTelefono: ";
    cin >> tlf;

    Monitor aux(direccion,tlf,nombre,apell1,apell2,dni,correo,edad);
    plantilla_.push_back(aux);
    setnTrabajadores();
    cout << "\nMonitor añadido a la plantilla de trabajadores con EXITO\n";
}

// Funcion que muestra los datos personales de un monitor buscado por su dni
void Administrador::getMonitor()const{
    list<Monitor>::const_iterator i;
    string dni;
    bool find=false;

    cout << "Introduce el dni del monitor ";
    cin >> dni;

    for(i=plantilla_.begin();i!=plantilla_.end();i++){
        if(dni == (*i).getDni()){
            cout << "\n<-----------> Datos del Monitor " << (*i).getNombre() << "<----------->\n";
            cout << "Nombre: " << (*i).getNombre() << endl;
            cout << "Apellidos: " << (*i).getApellido2() << ", " << (*i).getApellido1() << endl;
            cout << "Edad: " << (*i).getEdad() << endl;
            cout << "DNI: " << (*i).getDni() << endl;
            cout << "Telefono: " << (*i).getTelefono() << endl;
            cout << "Direccion: " << (*i).getDireccion() << endl;
            cout << "Correo: " << (*i).getCorreo() << endl;
            find=true;
        }
    }
    if(!find){cout << "\nERROR el monitor no se encuentra en la plantilla\n\n";}
}

void Administrador::eliminarMonitor(){
    list<Monitor>::iterator i;
    string dni;
    bool find=false;

    cout << "\nIntroduzca el dni del monitor para eliminarlo ";
    cin >> dni;

    for(i=plantilla_.begin();i!=plantilla_.end();i++){
        if(dni == (*i).getDni()){
            i=plantilla_.erase(i);
            cout << "\nEl monitor ha sido eliminado con EXITO\n\n";
            find=true;
        }
    }
    if(!find){cout << "\nERROR el monitor no se encuentra en la plantilla\n\n";}
}

// Funcion que asigna a una actividad un monitor
void Administrador::asignarActividad(){
    list<Monitor>::iterator i;
    list<Actividad>::iterator j;
    string dni;
    int id;
    if(plantilla_.size() == 0){
        cout << "\nERROR la plantilla de monitores se encuentra vacia, no puede asignar actividades aun\n\n";
    }else{
        cout << "<-----------> ASIGNACIONES <--------->\n";
        cout << "\nIntroduzca el dni del monitor para asignar actividad ";
        cin >> dni;
        bool find1=false,find2=false;

        for(i=plantilla_.begin();i!=plantilla_.end();i++){
            if(dni == (*i).getDni()){
                cout << "Introduzca el identificador de la actividad para asignarsela ";
                cin >> id;
                    for(j=actividades_.begin();j!=actividades_.end();j++){
                            if(id == (*j).getIdentificador()){
                                (*j).setAsignacion(dni);
                                cout << "\nSe ha asignado la actividad al monitor " << dni << endl;
                                find1=true;
                            }
                    }
                    if(!find1){cout << "\nERROR la actividad con el identificador introducido no se encuentra registrada en el sistema\n\n";}
                    find2=true;
            }
        }
        if(!find2){cout << "\nERROR el monitor introducido no se encuentra en la plantilla\n\n";}
    }
}

// Funcion que desasigna al monitor de esa actividad
void Administrador::eliminarAsignacion(){
    list<Actividad>::iterator i;
    int id;
    bool find=false;

    if(actividades_.size() == 0){
        cout << "\nERROR La lista de actividades se encuentra vacia no puede desasignarlas aun\n\n";

    }else{
        cout << "Introduzca el identificador de la actividad para eliminar la asignacion ";
        cin >> id;

        for(i=actividades_.begin();i!=actividades_.end();i++){
            if(id == (*i).getIdentificador()){
                (*i).setAsignacion("NINGUNA");
                cout << "\nAsignacion eliminada con EXITO\n\n";
                find=true;
            }
        }
        if(!find){cout << "ERROR la actividad con identificador " << (*i).getIdentificador() << " no se encuentra registrada en el sistema\n\n";}
    }
}

// Funcion que imprime todas las actividades registradas en el sistema
void Administrador::getListaActividades()const{
    list<Actividad>::const_iterator i;
    cout << "\n<-----------> Lista Actividades <----------->\n";

    if(actividades_.size() == 0){
        cout << "La lista se encuentra vacia no existen actividades registradas\n\n";
    }else{
        for(i=actividades_.begin();i!=actividades_.end();i++){
            cout << "Actividad " << (*i).getIdentificador() << endl;
            cout << "Dificultad: ";
                switch((*i).getDificultad()){
                    case 1: cout << "Basico" << endl;
                            break;
                    case 2: cout << "Medio" << endl;
                            break;
                    case 3: cout << "Avanzado" << endl;
                            break;
                }
                cout << "Medio: ";
                switch((*i).getMedio()){
                    case 1: cout << "Ruta a Pie" << endl;
                            break;
                    case 2: cout << "Ruta en Bicicleta" << endl;
                            break;
                    case 3: cout << "Ruta Pie/Bicicleta" <<  endl;
                            break;
                }
                cout << "Asignacion: " << (*i).getAsignacion() << endl;
                cout << "<------------------------------------------->" << endl;
        }
    }
}

// Funcion que imprime la lista de actividades para que pueda visualizarla el monitor
void Administrador::getListaVisitantes()const{
    list<Visitante>::const_iterator i;
    cout << "\n<------------> Visitantes <------------>\n";
    if(visitantes_.size() == 0){
        cout << "\nLa lista de visitantes se ecuentra vacia actualmente\n\n";
    }else{
        for(i=visitantes_.begin();i!=visitantes_.end();i++){
            cout << "\nNombre: " << (*i).getNombre() << endl;
            cout << "Apellidos: " << (*i).getApellido2() << ", " << (*i).getApellido1() << endl;
            cout << "Edad: " << (*i).getEdad() << endl;
            cout << "DNI: " << (*i).getDni() << endl;
            cout << "Telefono: " << (*i).getTelefono() << endl;
            cout << "Correo: " << (*i).getCorreo() << endl;
            cout << "Dolencias: " << (*i).getEstadoSalud() << endl;
            cout << "<------------------------->\n";
        }
    }
}

// Funcion que permite modificar los datos personales de un visitante por su dni
void Administrador::modVisitante(){
    list<Visitante>::iterator i;
    bool find=false;
    string dni;

    if(visitantes_.size() == 0){
        cout << "\nLa lista de visitantes se ecuentra vacia actualmente\n\n";
    }else{
        cout << "\nIntroduzca el dni del visitante para modificar su informacion personal ";
        cin >> dni;

        for(i=visitantes_.begin();i!=visitantes_.end();i++){
            if(dni == (*i).getDni()){
                visitantes_.erase(i);
                setReserva();
                cout << "El visitante ha sido modificado con EXITO\n\n";
                find=true;
            }
        }
        if(!find){cout << "\nERROR el visitante no se encuentra en el sistema\n\n";}
    }
}

// Funcion que permite modificar los datos personales de un monitor por su dni
void Administrador::modMonitor(){
    list<Monitor>::iterator i;
    bool find=false;
    string dni;

    if(plantilla_.size() == 0){
        cout << "\nLa lista de monitores se ecuentra vacia actualmente\n\n";
    }else{
        cout << "\nIntroduzca el dni del monitor para modificar su informacion personal ";
        cin >> dni;

        for(i=plantilla_.begin();i!=plantilla_.end();i++){
            if(dni == (*i).getDni()){
                plantilla_.erase(i);
                setMonitor();
                cout << "El monitor ha sido modificado con EXITO\n\n";
                find=true;
            }
        }
        if(!find){cout << "\nERROR el monitor no se encuentra registrado en la plantilla\n\n";}
    }
}