#include "Calificacion.h"
#include <cstdlib>
#include <cstdio>
#include <verificaciones.h>
#include <Conf.h>
using namespace std;
//-----------------------------------------------CONSTRUCTOR
Calificacion::Calificacion(){
    nota=0;
    codcatedra=0;
    legalumno=0;
    tipo=0;
    tiporec=5;
    estado=false;
}

//-----------------------------------------------LEER DE DISCO
bool Calificacion::LeerDeDisco(int pos){
    FILE *C;
    C = fopen("data/Calificaciones.dat","rb");
    if (C==NULL) return false;
    fseek(C,sizeof *this*pos,0);
    bool leyo=fread(this,sizeof *this,1,C);
    fclose(C);
    return leyo;
}

//-----------------------------------------------LEER BACKUP
bool Calificacion::LeerDeDisco2(int pos){
    FILE *C;
    C = fopen("data/Backups/Calificaciones.bckp","rb");
    if (C==NULL) return false;
    fseek(C,sizeof *this*pos,0);
    bool leyo=fread(this,sizeof *this,1,C);
    fclose(C);
    return leyo;
}

//-----------------------------------------------GRABAR EN DISCO
bool Calificacion::GrabarEnDisco(){
    FILE *C;
    C = fopen("data/Calificaciones.dat","ab");
    if (C==NULL) return false;
    fwrite(this, sizeof *this,1,C);
    fclose(C);
    return true;
}

//-----------------------------------------------GRABAR BACKUP
void Calificacion::Grabarbckp(){
    FILE *C;
    C = fopen("data/Backups/Calificaciones.bckp","ab");
    if (C==NULL) return;
    fwrite(this, sizeof *this,1,C);
    fclose(C);
}

//-----------------------------------------------CARGAR CALIFICACION
void Calificacion::CargarCalificacion(){
    Conf c;
    int d,m,a;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+40-c.getx3(),11); cout << "Legajo del alumno: ";
    gotoxy(c.getx()+40-c.getx3(),12); cout << "Codigo de la catedra: ";
    gotoxy(c.getx()+40-c.getx3(),13); cout << "*Tipo: ";
    gotoxy(c.getx()+40-c.getx3(),14); cout << "Valor de la nota: ";
    gotoxy(c.getx()+40-c.getx3(),15); cout << "Fecha: "; gotoxy(c.getx()+64-c.getx3(),15); cout  << "/"; gotoxy(c.getx()+67-c.getx3(),15); cout << "/";
    gotoxy(c.getx()+25-c.getx3(),20); cout << "* Tipo: 1=1erparcial 2=2do parcial 3=3er parcial (Dependiendo de la catedra)";
    gotoxy(c.getx()+25-c.getx3(),21); cout << "4=final 5=recuperatorio [Se aclara que parcial se recupera, si el primero o el segundo]";
    gotoxy(c.getx()+25-c.getx3(),22); cout << "6=trabajo practico";
    gotoxy(c.getx()+62-c.getx3(),11); cin >> legalumno;
    while(Verificar_alumno_existe(legalumno)==false){
        gotoxy(c.getx()+62-c.getx3(),11);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),11);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: El alumno no existe en el registro";
        gotoxy(c.getx()+62-c.getx3(),11); cin >> legalumno;
    }
    gotoxy(c.getx()+40-c.getx3(),30);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),11);cout << " ";
    gotoxy(c.getx()+62-c.getx3(),12); cin >> codcatedra;
    while(Verificar_catedra_existe(codcatedra)==false || Verificar_alumno_catedra(legalumno, codcatedra)==false){
        gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
        gotoxy(c.getx()+62-c.getx3(),12);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),12);cout << "!";
        if (Verificar_catedra_existe(codcatedra)==false){
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La catedra no existe en el registro";
        } else {
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: El alumno no pertenece a la catedra";
        }
        gotoxy(c.getx()+62-c.getx3(),12); cin >> codcatedra;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),12);cout << " ";
    gotoxy(c.getx()+62-c.getx3(),13); cin >> tipo;
    while(Verificar_tipo_calificacion(tipo) || Verificar_cant_parciales_catedra(codcatedra,tipo) || Verificar_nota_existe(legalumno,codcatedra,tipo,5)){
        gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
        gotoxy(c.getx()+62-c.getx3(),13);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),13);cout << "!";
        if (Verificar_tipo_calificacion(tipo)){
            gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Tipo de nota incorrecto";
        } else if (Verificar_cant_parciales_catedra(codcatedra,tipo)) {
            gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La catedra no tiene 3 parciales";
        } else {
             gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La calificacion ya existe en el registro";
        }
        gotoxy(c.getx()+62-c.getx3(),13); cin >> tipo;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),13);cout << " ";
    gotoxy(c.getx()+62-c.getx3(),14); cin >> nota;
    while(Verificar_nota_calificacion(nota)){
        gotoxy(c.getx()+62-c.getx3(),14);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Nota incorrecta";
        gotoxy(c.getx()+62-c.getx3(),14); cin >> nota;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+62-c.getx3(),15); cin >> d;
    gotoxy(c.getx()+65-c.getx3(),15); cin >> m;
    gotoxy(c.getx()+68-c.getx3(),15); cin >> a;
    while(Verificar_persona_fecha(d,m,a)){
        gotoxy(c.getx()+62-c.getx3(),15);cout<<"  " << "/";
        gotoxy(c.getx()+62-c.getx3(),15);cout<<"  " << "/";
        gotoxy(c.getx()+62-c.getx3(),15);cout<<"                    ";
        gotoxy(c.getx()+38-c.getx3(),15);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Fecha incorrecta";
        gotoxy(c.getx()+62-c.getx3(),15); cin >> d;
        gotoxy(c.getx()+65-c.getx3(),15); cin >> m;
        gotoxy(c.getx()+68-c.getx3(),15); cin >> a;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),15);cout << " ";
    if (tipo==5){
        gotoxy(c.getx()+40-c.getx3(),16);cout << "Parcial que se recupera: ";
        gotoxy(c.getx()+65-c.getx3(),16);cin >> tiporec;
        while(Verificar_recuperatorio(tiporec) || Verificar_cant_parciales_catedra(codcatedra,tiporec) || Verificar_nota_existe(legalumno,codcatedra,tipo,tiporec)){
            gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
            gotoxy(c.getx()+65-c.getx3(),16);cout<<"          ";
            gotoxy(c.getx()+38-c.getx3(),16);cout << "!";
            if (Verificar_recuperatorio(tiporec)){
                gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Parcial incorrecto";
            } else if (Verificar_cant_parciales_catedra(codcatedra,tiporec)){
                gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La catedra no tiene 3 parciales";
            } else {
                gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La calificacion ya existe en el registro";
            }
            gotoxy(c.getx()+65-c.getx3(),16);cin >> tiporec;
        }
    }
    calif.setdia(d);
    calif.setmes(m);
    calif.setanio(a);
    estado=true;
}

//-----------------------------------------------MODIFICAR EN DISCO
void Calificacion::Modificar(int pos){
    FILE *CA;
    CA = fopen("data/Calificaciones.dat","rb+");
    if (CA==NULL) exit(1);
    fseek(CA,sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,CA);
    fclose(CA);
}
