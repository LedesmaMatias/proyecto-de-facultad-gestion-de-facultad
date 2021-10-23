#include "Persona.h"
#include <string.h>
#include "rlutil.h"
#include <verificaciones.h>
#include <Conf.h>
using namespace std;

//-------------------------------------------------CONSTRUCTOR PERSONA
Persona::Persona(){
    dni=0;
    codpostal=0;
    telefono=0;
    estado=false;
}

//-------------------------------------------------CARGAR PERSONA
void Persona::cargarpersona(){
    int d,m,a;
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+45-c.getx3(),12);cout << "-----REGISTRO 1/2-----";
    gotoxy(c.getx()+45-c.getx3(),13);cout << "Nombre: ";
    gotoxy(c.getx()+45-c.getx3(),14);cout << "Apellido: ";
    gotoxy(c.getx()+45-c.getx3(),15); cout << "Localidad: ";
    gotoxy(c.getx()+45-c.getx3(),16);cout << "Domicilio: ";
    gotoxy(c.getx()+45-c.getx3(),17);cout <<  "Nacionalidad: ";
    gotoxy(c.getx()+45-c.getx3(),18);cout << "dni: ";
    gotoxy(c.getx()+45-c.getx3(),19);cout << "Nacimiento: "; gotoxy(c.getx()+60-c.getx3(),19); cout << "/"; gotoxy(c.getx()+63-c.getx3(),19); cout << "/";
    gotoxy(c.getx()+45-c.getx3(),20);cout << "Codigo postal: ";
    gotoxy(c.getx()+45-c.getx3(),21);cout << "Telefono: ";
    gotoxy(c.getx()+45-c.getx3(),22);cout << "Email: ";
    gotoxy(c.getx()+45-c.getx3(),23);cout << "Genero: ";
    gotoxy(c.getx()+57-c.getx3(),13);cin.getline(nombre,30);
    while(Verificar_vacio(nombre)==false){
        gotoxy(c.getx()+43-c.getx3(),13);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+57-c.getx3(),13);cin.getline(nombre,30);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),13);cout << " ";
    gotoxy(c.getx()+57-c.getx3(),14);cin.getline(apellido,30);
    while(Verificar_vacio(apellido)==false){
        gotoxy(c.getx()+43-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+57-c.getx3(),14);cin.getline(apellido,30);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+57-c.getx3(),15);cin.getline(localidad,50);
    while(Verificar_vacio(localidad)==false){
        gotoxy(c.getx()+43-c.getx3(),15);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+57-c.getx3(),15);cin.getline(localidad,50);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),15);cout << " ";
    gotoxy(c.getx()+57-c.getx3(),16);cin.getline(domicilio,50);
    while(Verificar_vacio(domicilio)==false){
        gotoxy(c.getx()+43-c.getx3(),16);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+57-c.getx3(),16);cin.getline(domicilio,50);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),16);cout << " ";
    gotoxy(c.getx()+60-c.getx3(),17);cin.getline(nacionalidad,30);
    while(Verificar_vacio(nacionalidad)==false){
        gotoxy(c.getx()+43-c.getx3(),17);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+60-c.getx3(),17);cin.getline(nacionalidad,30);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),17);cout << " ";
    gotoxy(c.getx()+50-c.getx3(),18);cin >> dni;
    while(Verificar_persona_dni(dni)){
        gotoxy(c.getx()+50-c.getx3(),18);cout<<"            ";
        gotoxy(c.getx()+43-c.getx3(),18);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: La persona ya existe en el registro";
        gotoxy(c.getx()+50-c.getx3(),18);cin >> dni;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),18);cout << " ";
    gotoxy(c.getx()+58-c.getx3(),19);cin >> d;
    gotoxy(c.getx()+61-c.getx3(),19);cin >> m;
    gotoxy(c.getx()+64-c.getx3(),19);cin >> a;
    while(Verificar_persona_fecha(d,m,a)){
        gotoxy(c.getx()+58-c.getx3(),19);cout<<"  ";
        gotoxy(c.getx()+61-c.getx3(),19);cout<<"  ";
        gotoxy(c.getx()+64-c.getx3(),19);cout<<"            ";
        gotoxy(c.getx()+43-c.getx3(),19);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: Error en el nacimiento";
        gotoxy(c.getx()+58-c.getx3(),19);cin >> d;
        gotoxy(c.getx()+61-c.getx3(),19);cin >> m;
        gotoxy(c.getx()+64-c.getx3(),19);cin >> a;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),19);cout << " ";
    nacimiento.setdia(d); nacimiento.setmes(m); nacimiento.setanio(a);
    gotoxy(c.getx()+61-c.getx3(),20);cin >> codpostal;
    gotoxy(c.getx()+57-c.getx3(),21);cin >> telefono;
    gotoxy(c.getx()+57-c.getx3(),22);cin.ignore();cin >> email;
    gotoxy(c.getx()+57-c.getx3(),23);cin >> genero;
    while(Verificar_persona_genero(genero)){
        gotoxy(c.getx()+57-c.getx3(),23);cout<<"                    ";
        gotoxy(c.getx()+43-c.getx3(),23);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: Genero incorrecto (M o F u O) ";
        gotoxy(c.getx()+57-c.getx3(),23);cin >> genero;
    }
}

//-------------------------------------------------MOSTRAR INFORMACION PERSONAL
void Persona::mostrarpersona(){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+45-c.getx3(),12);cout << "Nombre: " << nombre;
    gotoxy(c.getx()+45-c.getx3(),13);cout << "Apellido: " << apellido;
    gotoxy(c.getx()+45-c.getx3(),14);cout << "Domicilio: " << domicilio;
    gotoxy(c.getx()+45-c.getx3(),15);cout << "Nacionalidad: " << nacionalidad;
    gotoxy(c.getx()+45-c.getx3(),16);cout << "DNI: " << dni;
    gotoxy(c.getx()+45-c.getx3(),17);cout << "Nacimiento: " << nacimiento.getdia() << "/" << nacimiento.getmes() << "/" << nacimiento.getanio();
    gotoxy(c.getx()+45-c.getx3(),18);cout << "Codigo postal: " << codpostal;
    gotoxy(c.getx()+45-c.getx3(),19);cout << "telefono: " << telefono;
    gotoxy(c.getx()+45-c.getx3(),20);cout << "Email: " << email;
    gotoxy(c.getx()+45-c.getx3(),21);cout << "genero: ";
    switch(genero){
        case 'm':
        case 'M':
            cout << "Masculino";
            break;
        case 'f':
        case 'F':
            cout << "Femenino";
            break;
        case 'o':
        case 'O':
            cout << "Otro";
            break;
    }
}


///METODOS ALUMNO
///------------------------------------------------------------------------

//-------------------------------------------------CONSTRUCTOR ALUMNO
Alumno::Alumno(){
    legajo=0;
}

//-------------------------------------------------LEER DE DISCO
bool Alumno::LeerDeDisco(int pos){
    FILE *A;
    A = fopen("data/Alumnos.dat","rb");
    if (A == NULL) return false;
    fseek(A, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this,1,A);
    fclose(A);
    return leyo;
}

//-------------------------------------------------LEER BACKUP
bool Alumno::LeerDeDisco2(int pos){
    FILE *A;
    A = fopen("data/Backups/Alumnos.bckp","rb");
    if (A == NULL) return false;
    fseek(A, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this,1,A);
    fclose(A);
    return leyo;
}

//-------------------------------------------------GRABAR EN DISCO
bool Alumno::GrabarAlumno(){
    FILE *A;
    A = fopen("data/Alumnos.dat","ab");
    if (A==NULL)return false;
    fwrite(this, sizeof *this,1,A);
    fclose(A);
    return true;
}

//-------------------------------------------------GRABAR BACKUP
void Alumno::Grabarbckp(){
    FILE *A;
    A = fopen("data/Backups/Alumnos.bckp","ab");
    if (A==NULL) return;
    fwrite(this, sizeof *this,1,A);
    fclose(A);
}

//-------------------------------------------------CARGAR ALUMNO
void Alumno::CargarAlumno(int leg){
    Conf c;
    c.LeerDeDisco(0);
    cargarpersona();
    system("cls");
    int d,m,a;
    gotoxy(c.getx()+45-c.getx3(),12);cout << "-----REGISTRO 2/2-----";
    gotoxy(c.getx()+45-c.getx3(),13);cout << "legajo: ";
    gotoxy(c.getx()+45-c.getx3(),14);cout << "titulo secundario: ";
    gotoxy(c.getx()+45-c.getx3(),15); cout << "Recibido del: ";
    gotoxy(c.getx()+45-c.getx3(),16);cout << "Codigo de carrera: ";
    gotoxy(c.getx()+45-c.getx3(),17);cout << "Fecha de inscripcion: "; gotoxy(c.getx()+70-c.getx3(),17); cout << "/"; gotoxy(c.getx()+73-c.getx3(),17); cout << "/";
    gotoxy(c.getx()+45-c.getx3(),18);cout << "Trabaja ? ( 0 = no 1 = si ): ";
    legajo = leg;
    gotoxy(c.getx()+57-c.getx3(),13);cout << legajo;
    gotoxy(c.getx()+64-c.getx3(),14);cin.ignore();cin.getline(titulosecundario,50);
    while(Verificar_vacio(titulosecundario)==false){
        gotoxy(c.getx()+43-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+64-c.getx3(),14);cin.getline(titulosecundario,50);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+59-c.getx3(),15); cin.getline(recibido,100);
    while(Verificar_vacio(recibido)==false){
        gotoxy(c.getx()+43-c.getx3(),15);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+59-c.getx3(),15); cin.getline(recibido,100);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),15);cout << " ";
    gotoxy(c.getx()+64-c.getx3(),16);cin >> codcarrera;
    while(Verificar_carrera_existe(codcarrera)==false){
        gotoxy(c.getx()+64-c.getx3(),16);cout << "           ";
        gotoxy(c.getx()+43-c.getx3(),16);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: La carrera no existe en el registro";
        gotoxy(c.getx()+64-c.getx3(),16);cin >> codcarrera;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+43-c.getx3(),16);cout << " ";
    gotoxy(c.getx()+68-c.getx3(),17); cin >> d;
    gotoxy(c.getx()+71-c.getx3(),17); cin >> m;
    gotoxy(c.getx()+74-c.getx3(),17); cin >> a;
    while(Verificar_persona_fecha(d,m,a)){
        gotoxy(c.getx()+68-c.getx3(),17);cout<<"  ";
        gotoxy(c.getx()+71-c.getx3(),17);cout<<"  ";
        gotoxy(c.getx()+74-c.getx3(),15);cout<<"            ";
        gotoxy(c.getx()+43-c.getx3(),15);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: Error en la fecha";
        gotoxy(c.getx()+68-c.getx3(),17); cin >> d;
        gotoxy(c.getx()+71-c.getx3(),17); cin >> m;
        gotoxy(c.getx()+74-c.getx3(),17); cin >> a;
    }
    inscripcion.setdia(d); inscripcion.setmes(m); inscripcion.setanio(a);
    gotoxy(c.getx()+75-c.getx3(),18);cin >> trabaja;
    if (trabaja) {
        gotoxy(c.getx()+47-c.getx3(),19);cout << "Trabajo: ";
        gotoxy(c.getx()+57-c.getx3(),19);cin.ignore();cin.getline(trabajo,50);
        while(Verificar_vacio(trabajo)){
        gotoxy(c.getx()+43-c.getx3(),19);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+57-c.getx3(),19);cin.getline(trabajo,50);
        }
    }
    estado=true;
}

//-------------------------------------------------MOSTRAR ALUMNO
void Alumno::MostrarAlumno(const char *nombrecar){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+45-c.getx3(),12);cout << "legajo: " << legajo;
    gotoxy(c.getx()+45-c.getx3(),13);cout << "Titulo secundario: " << titulosecundario;
    gotoxy(c.getx()+45-c.getx3(),14); cout << "Recibido del: " << recibido;
    gotoxy(c.getx()+45-c.getx3(),15);cout << "Codigo de carrera: " << codcarrera;
    gotoxy(c.getx()+45-c.getx3(),16);cout << "Nombre de la carrera: " << nombrecar;
    if (trabaja){
        gotoxy(c.getx()+45-c.getx3(),17);cout << "Trabajo: " << trabajo;
    }
}

//-------------------------------------------------MODIDIFCAR EN DISCO
void Alumno::Modificar(int pos){
    FILE *A;
    A = fopen("data/Alumnos.dat","rb+");
    if (A==NULL) exit(1);
    fseek(A, sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,A);
    fclose(A);
}


///METODOS DOCENTES
///-------------------------------------------------------------------------

//-------------------------------------------------CONSTRUCTOR DOCENTE
Docente::Docente(){
    legajo=0;
}

//-------------------------------------------------LEER DE DISCO
bool Docente::LeerDeDisco(int pos){
    FILE *D;
    D = fopen("data/Docentes.dat","rb");
    if (D==NULL) return false;
    fseek(D, sizeof *this*pos, 0);
    bool leyo = fread(this, sizeof *this,1,D);
    fclose(D);
    return leyo;
}

//-------------------------------------------------LEER BACKUP
bool Docente::LeerDeDisco2(int pos){
    FILE *D;
    D = fopen("data/Backups/Docentes.bckp","rb");
    if (D==NULL) return false;
    fseek(D, sizeof *this*pos, 0);
    bool leyo = fread(this, sizeof *this,1,D);
    fclose(D);
    return leyo;
}

//-------------------------------------------------GRABAR EN DISCO
bool Docente::GrabarDocente(){
    FILE *D;
    D = fopen("data/Docentes.dat","ab");
    if (D==NULL) return false;
    fwrite(this, sizeof *this,1,D);
    fclose(D);
    return true;
}

//-------------------------------------------------GRABAR BACKUP
void Docente::Grabarbckp(){
    FILE *D;
    D = fopen("data/Backups/Docentes.bckp","ab");
    if (D==NULL) return;
    fwrite(this, sizeof *this,1,D);
    fclose(D);
}

//-------------------------------------------------MODIFICAR EN DISCO
void Docente::Modificar(int pos){
    FILE *D;
    D = fopen("data/Docentes.dat","rb+");
    if (D==NULL) exit(1);
    fseek(D, sizeof *this*pos,0);
    fwrite(this, sizeof *this, 1 ,D);
    fclose(D);
}

//-------------------------------------------------CARGAR DOCENTE
void Docente::CargarDocente(int leg){
    Conf c;
    c.LeerDeDisco(0);
    cargarpersona();
    system("cls");
    int d,m,a;
    gotoxy(c.getx()+45-c.getx3(),12);cout << "-----REGISTRO 2/2-----";
    gotoxy(c.getx()+45-c.getx3(),13);cout << "legajo: ";
    gotoxy(c.getx()+45-c.getx3(),14);cout << "cargo: ";
    gotoxy(c.getx()+45-c.getx3(),15);cout << "Fecha de ingreso: "; gotoxy(c.getx()+70-c.getx3(),15); cout << "/"; gotoxy(c.getx()+73-c.getx3(),15); cout << "/";
    legajo = leg;
    gotoxy(c.getx()+57-c.getx3(),13);cout << legajo;
    gotoxy(c.getx()+57-c.getx3(),14);cin.ignore();cin.getline(cargo,50);
    while(Verificar_vacio(cargo)==false){
        gotoxy(c.getx()+43-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+57-c.getx3(),14);cin.getline(cargo,50);
    }
    gotoxy(c.getx()+43-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+45-c.getx3(),25);cout << "                                           ";
    gotoxy(c.getx()+68-c.getx3(),15); cin >> d;
    gotoxy(c.getx()+71-c.getx3(),15); cin >> m;
    gotoxy(c.getx()+74-c.getx3(),15); cin >> a;
    while(Verificar_persona_fecha(d,m,a)){
        gotoxy(c.getx()+68-c.getx3(),15);cout<<"  ";
        gotoxy(c.getx()+71-c.getx3(),15);cout<<"  ";
        gotoxy(c.getx()+74-c.getx3(),15);cout<<"            ";
        gotoxy(c.getx()+43-c.getx3(),15);cout << "!";
        gotoxy(c.getx()+45-c.getx3(),25);cout << "!: Error en la fecha";
        gotoxy(c.getx()+68-c.getx3(),15);cin >> d;
        gotoxy(c.getx()+71-c.getx3(),15);cin >> m;
        gotoxy(c.getx()+74-c.getx3(),15);cin >> a;
    }
    ingreso.setdia(d); ingreso.setmes(m); ingreso.setanio(a);
    estado=true;
}

//-------------------------------------------------MOSTRAR DOCENTE
void Docente::MostrarDocente(int cantcat){
    Conf c;
    c.LeerDeDisco(0);
     gotoxy(c.getx()+45-c.getx3(),12);cout << "legajo: " << legajo;
    gotoxy(c.getx()+45-c.getx3(),13);cout << "Fecha de ingreso: " << ingreso.getdia() << "/" << ingreso.getmes() << "/" << ingreso.getanio();
    gotoxy(c.getx()+45-c.getx3(),14);cout << "Cantidad de catedras: " << cantcat;
    gotoxy(c.getx()+45-c.getx3(),15);cout << "Cargo: " << cargo;
}

