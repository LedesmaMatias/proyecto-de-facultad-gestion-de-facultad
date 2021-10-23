#include "Catedra_alumnos.h"
#include <cstdlib>
#include <cstdio>
#include <verificaciones.h>
#include <Conf.h>
using namespace std;
//-----------------------------------------------CONSTRUCTOR
Catedra_alumnos::Catedra_alumnos(){
    legalumno=0;
    codcatedra=0;
    estado=false;
}

//-----------------------------------------------LEER DE DISCO
bool Catedra_alumnos::LeerDeDisco(int pos){
    FILE *CA;
    CA = fopen("data/catalumnos.dat","rb");
    if (CA==NULL) return false;
    fseek(CA, sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,CA);
    fclose(CA);
    return leyo;
}

//-----------------------------------------------LEER BACKUP
bool Catedra_alumnos::LeerDeDisco2(int pos){
    FILE *CA;
    CA = fopen("data/Backups/catalumnos.bckp","rb");
    if (CA==NULL) return false;
    fseek(CA, sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,CA);
    fclose(CA);
    return leyo;
}

//-----------------------------------------------GRABAR EN DISCO
bool Catedra_alumnos::GrabarEnDisco(){
    FILE *CA;
    CA = fopen("data/catalumnos.dat","ab");
    if (CA==NULL) return false;
    fwrite(this, sizeof *this,1,CA);
    fclose(CA);
    return true;
}

//-----------------------------------------------GRABAR BACKUP
void Catedra_alumnos::Grabarbckp(){
    FILE *CA;
    CA = fopen("data/Backups/catalumnos.bckp","ab");
    if (CA==NULL) return;
    fwrite(this, sizeof *this,1,CA);
    fclose(CA);
}

//-----------------------------------------------CARGAR ALUMNO EN CATEDRA
void Catedra_alumnos::Cargar(){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+40-c.getx3(),12); cout << "Legajo de alumno: ";
    gotoxy(c.getx()+40-c.getx3(),13); cout << "Codigo de la catedra: ";
    gotoxy(c.getx()+63-c.getx3(),12); cin >> legalumno;
    while (Verificar_alumno_existe(legalumno)==false){
        gotoxy(c.getx()+63-c.getx3(),12); cout<<"                       ";
        gotoxy(c.getx()+38-c.getx3(),12); cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25); cout << "!: El alumno no existe en el registro";
        gotoxy(c.getx()+63-c.getx3(),12); cin >> legalumno;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),12);cout << " ";
    gotoxy(c.getx()+63-c.getx3(),13); cin >> codcatedra;
    while(Verificar_catedra_existe(codcatedra)==false || Verificar_en_catedra_y_asignatura(codcatedra,legalumno) || Verificar_en_carrera(codcatedra,legalumno)==false){
        gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                                                      ";
        gotoxy(c.getx()+63-c.getx3(),13); cout<<"                       ";
        gotoxy(c.getx()+38-c.getx3(),13); cout << "!";
        if (Verificar_catedra_existe(codcatedra)==false){
            gotoxy(c.getx()+40-c.getx3(),25); cout << "!: La catedra no existe en el registro";
        } else if (Verificar_en_catedra_y_asignatura(codcatedra,legalumno)){
            gotoxy(c.getx()+40-c.getx3(),25); cout << "!: El alumno ya se encuentra inscripto en la catedra o en la asignatura";
        } else {
             gotoxy(c.getx()+40-c.getx3(),25); cout << "!: La catedra no pertenece a la carrera que el alumno cursa";
        }
        gotoxy(c.getx()+63-c.getx3(),13); cin >> codcatedra;
    }
    estado=true;
}

//-----------------------------------------------MODIFICAR EN DISCO
void Catedra_alumnos::Modificar(int pos){
    FILE *CA;
    CA = fopen("data/catalumnos.dat","rb+");
    if (CA==NULL) exit(1);
    fseek(CA,sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,CA);
    fclose(CA);
}
