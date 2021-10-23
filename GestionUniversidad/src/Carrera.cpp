#include "Carrera.h"
#include <string.h>
#include <verificaciones.h>
#include <Conf.h>

//---------------------------------------------------------CONSTRUCTOR
Carrera::Carrera()
{
   duracion=0;
   tipo=0;
   notamin=0;
   promocion=0;
   estado=false;
}

//---------------------------------------------------------LEER DE DISCO
bool Carrera::LeerDeDisco(int pos){
    FILE *C;
    C = fopen("data/Carreras.dat","rb");
    if (C==NULL) return 0;
    fseek(C, sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,C);
    fclose(C);
    return leyo;
}

//---------------------------------------------------------LEER BACKUP
bool Carrera::LeerDeDisco2(int pos){
    FILE *C;
    C = fopen("data/Backups/Carreras.bckp","rb");
    if (C==NULL) return 0;
    fseek(C, sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,C);
    fclose(C);
    return leyo;
}

//---------------------------------------------------------GRABAR EN DISCO
bool Carrera::GrabarCarrera(){
    FILE *C;
    C = fopen("data/Carreras.dat","ab");
    if (C==NULL) return false;
    fwrite(this, sizeof *this,1,C);
    fclose(C);
    return true;
}

//---------------------------------------------------------GRABAR BACKUP
void Carrera::Grabarbckp(){
    FILE *C;
    C = fopen("data/Backups/Carreras.bckp","ab");
    if (C==NULL) return;
    fwrite(this, sizeof *this,1,C);
    fclose(C);
}

//---------------------------------------------------------CARGAR CARRERA
void Carrera::CargarCarrera(){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+35-c.getx3(),12);cout << "Ingrese el nombre de la carrera: ";
    gotoxy(c.getx()+35-c.getx3(),13);cout << "Ingrese el codigo de la carrera: ";
    gotoxy(c.getx()+35-c.getx3(),14);cout << "Ingrese el tipo de la carrera: ";
    gotoxy(c.getx()+35-c.getx3(),15);cout << "(1: Grado 2: Tecnicatura 3: Licenciatura ";
    gotoxy(c.getx()+35-c.getx3(),16);cout << "4: Doctorado 5: Maestría 6: Especialidad 7: Curso)";
    gotoxy(c.getx()+35-c.getx3(),17);cout << "Ingrese la duracion en cuatrimestres: ";
    gotoxy(c.getx()+35-c.getx3(),18);cout << "Ingrese la nota minima para aprobar: ";
    gotoxy(c.getx()+35-c.getx3(),19);cout << "Ingrese la nota minima para promocion: ";
    gotoxy(c.getx()+70-c.getx3(),12);cin.getline(nombre,50);
    while(Verificar_vacio(nombre)==false){
        gotoxy(c.getx()+33-c.getx3(),12);cout << "!";
        gotoxy(c.getx()+35-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+70-c.getx3(),12);cin.getline(nombre,50);
    }
    gotoxy(c.getx()+35-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+33-c.getx3(),12);cout << " ";
    gotoxy(c.getx()+70-c.getx3(),13);cin >> codigo;
    while(Verificar_carrera_existe(codigo) && Verificar_vacio(codigo)==false){
        gotoxy(c.getx()+70-c.getx3(),13);cout<<"          ";
        gotoxy(c.getx()+33-c.getx3(),13);cout << "!";
        gotoxy(c.getx()+35-c.getx3(),25);cout << "!: El codigo de carrera ya existe en los archivos";
        gotoxy(c.getx()+70-c.getx3(),13);cin >> codigo;
    }
    gotoxy(c.getx()+35-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+33-c.getx3(),13);cout << " ";
    gotoxy(c.getx()+70-c.getx3(),14);cin >> tipo;
    while(Verificar_carrera_tipo(tipo)){
        gotoxy(c.getx()+70-c.getx3(),14);cout<<"          ";
        gotoxy(c.getx()+33-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+35-c.getx3(),25);cout << "!: El tipo de carrera es incorrecto";
        gotoxy(c.getx()+70-c.getx3(),14);cin >> tipo;
    }
    gotoxy(c.getx()+35-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+33-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+75-c.getx3(),17);cin >> duracion;
    gotoxy(c.getx()+75-c.getx3(),18);cin >> notamin;
    while(Verificar_carrera_min(notamin)){
        gotoxy(c.getx()+75-c.getx3(),18);cout<<"          ";
        gotoxy(c.getx()+33-c.getx3(),18);cout << "!";
        gotoxy(c.getx()+35-c.getx3(),25);cout << "!: La nota minima no puede ser menor que 1 ni mayor que 10";
        gotoxy(c.getx()+75-c.getx3(),18);cin >> notamin;
    }
    gotoxy(c.getx()+35-c.getx3(),25);cout<< "                                                             ";
    gotoxy(c.getx()+33-c.getx3(),18);cout << " ";
    gotoxy(c.getx()+75-c.getx3(),19);cin >> promocion;
    while(Verificar_carrera_min(promocion)){
        gotoxy(c.getx()+75-c.getx3(),19);cout<<"          ";
        gotoxy(c.getx()+33-c.getx3(),19);cout << "!";
        gotoxy(c.getx()+35-c.getx3(),25);cout << "!: La nota minima no puede ser menor que 1 ni mayor que 10";
        gotoxy(c.getx()+75-c.getx3(),19);cin >> promocion;
    }
    gotoxy(c.getx()+35-c.getx3(),25);cout<< "                                                             ";
    gotoxy(c.getx()+33-c.getx3(),19);cout << " ";
    estado=true;
}

//---------------------------------------------------------MOSTRAR CARRERA
void Carrera::MostrarCarrera(int alum=0, int asig=0, int horas=0, int cat=0){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+35-c.getx3(),12); cout << "Nombre: " << nombre;
    gotoxy(c.getx()+35-c.getx3(),13); cout << "Codigo: " << codigo;
    gotoxy(c.getx()+35-c.getx3(),14); cout << "Tipo de carrera: ";
    switch(tipo){
    case 1:
        cout << "de grado";
        break;
    case 2:
        cout << "Tecnicatura";
        break;
    case 3:
        cout << "Licenciatura";
        break;
    case 4:
        cout << "Doctorado";
        break;
    case 5:
        cout << "Maestria";
        break;
    case 6:
        cout << "Especialidad";
        break;
    case 7:
        cout << "Curso";
        break;
    }
    gotoxy(c.getx()+35-c.getx3(),15); cout << "Cantidad de alumnos inscriptos: " << alum;
    gotoxy(c.getx()+35-c.getx3(),16); cout << "Cantidad de catedras: " << cat;
    gotoxy(c.getx()+35-c.getx3(),17); cout << "Cantidad de asignaturas: " << asig;
    gotoxy(c.getx()+35-c.getx3(),18); cout << "Duracion en cuatrimestres: " << duracion;
}

//---------------------------------------------------------MODIFICAR EN DISCO
bool Carrera::Modificar(int pos){
    FILE *C;
    C = fopen("data/Carreras.dat","rb+");
    if (C==NULL) return false;
    fseek(C,sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,C);
    fclose(C);
    return true;
}

//---------------------------------------------------------DESTRUCTOR
Carrera::~Carrera()
{
    //dtor
}
