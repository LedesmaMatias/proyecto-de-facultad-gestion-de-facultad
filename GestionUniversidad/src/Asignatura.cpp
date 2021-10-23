#include "Asignatura.h"
#include <cstdlib>
#include <verificaciones.h>
#include <Conf.h>
using namespace std;

//---------------------------------------------------------CONSTRUCTOR
Asignatura::Asignatura() {
    codigo=0;
    horas=0;
    cuatrimestre=0;
    estado=false;
}

//---------------------------------------------------------GRABAR EN DISCO
bool Asignatura::Grabar_asignatura() {
    FILE *A;
    A = fopen("data/Asignaturas.dat","ab");
    if (A==NULL)return false;
    fwrite(this,sizeof *this,1,A);
    fclose(A);
    return true;
}

//---------------------------------------------------------GRABAR BACKUP
void Asignatura::Grabarbckp() {
    FILE *A;
    A = fopen("data/Backups/Asignaturas.bckp","ab");
    if (A==NULL)return;
    fwrite(this,sizeof *this,1,A);
    fclose(A);
}

//---------------------------------------------------------LEER EN DISCO
bool Asignatura::LeerDeDisco(int pos) {
    FILE *A;
    A = fopen("data/Asignaturas.dat","rb");
    if (A==NULL)return false;
    fseek(A,sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,A);
    fclose(A);
    return leyo;
}

//---------------------------------------------------------LEER BACKUP
bool Asignatura::LeerDeDisco2(int pos) {
    FILE *A;
    A = fopen("data/Backups/Asignaturas.bckp","rb");
    if (A==NULL)return false;
    fseek(A,sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,A);
    fclose(A);
    return leyo;
}

//---------------------------------------------------------MOSTRAR ASIGNATURA
void Asignatura::MostrarAsignatura(const char* nombrecar) {
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+40-c.getx3(),11);cout << "Codigo: " << codigo;
    gotoxy(c.getx()+40-c.getx3(),12);cout << "Nombre: " << nombre;
    gotoxy(c.getx()+40-c.getx3(),13);cout << "Codigo de carrera: " << codcarrera;
    gotoxy(c.getx()+40-c.getx3(),14);cout << "Nombre carrera: " << nombrecar;
    gotoxy(c.getx()+40-c.getx3(),15);cout << "Cuatrimestre dentro del plan: " << cuatrimestre;
    gotoxy(c.getx()+40-c.getx3(),16);cout << "horas cuatrimestrales: " << horas;
}

//---------------------------------------------------------CARGAR ASIGNATURA
void Asignatura::Cargar_asignatura(int ultid=0) {
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+40-c.getx3(),11);cout << "Codigo: " << ultid+1;
    gotoxy(c.getx()+40-c.getx3(),12);cout << "Nombre de la asignatura: ";
    gotoxy(c.getx()+40-c.getx3(),13);cout << "Codigo de carrera: ";
    gotoxy(c.getx()+40-c.getx3(),14);cout << "Cuatrimestre dentro del plan de carrera: ";
    gotoxy(c.getx()+40-c.getx3(),15);cout << "Horas semanales: ";
    codigo=ultid+1;
    gotoxy(c.getx()+70-c.getx3(),12);cin.getline(nombre,100);
    while(Verificar_vacio(nombre)==false) {
        gotoxy(c.getx()+38-c.getx3(),12);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: El campo no puede estar vacío";
        gotoxy(c.getx()+70-c.getx3(),12);cin.getline(nombre,100);
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),12);cout << " ";
    gotoxy(c.getx()+70-c.getx3(),13);cin >> codcarrera;
    while(Verificar_carrera_existe(codcarrera)==false) {
        gotoxy(c.getx()+70-c.getx3(),13);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),13);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La carrera no existe en el registro";
        gotoxy(c.getx()+70-c.getx3(),13);cin >> codcarrera;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),13);cout << " ";
    gotoxy(c.getx()+81-c.getx3(),14);cin >> cuatrimestre;
    while(Verificar_carrera_cuatrimestre(cuatrimestre,codcarrera)) {
        gotoxy(c.getx()+81-c.getx3(),14);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: No existe cuatrimestre dentro de la carrera";
        gotoxy(c.getx()+81-c.getx3(),14);cin >> cuatrimestre;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+70-c.getx3(),15);cin >> horas;
    estado=true;
}

//---------------------------------------------------------MODIFICAR EN DISCO
void Asignatura::Modificar(int pos) {
    FILE *A;
    A = fopen("data/Asignaturas.dat","rb+");
    if (A==NULL)
        return;
    fseek(A,sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,A);
    fclose(A);
}

