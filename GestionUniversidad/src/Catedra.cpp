#include "Catedra.h"
#include <cstdlib>
#include <verificaciones.h>
#include <Conf.h>
using namespace std;

//-----------------------------------------------CONSTRUCTOR
Catedra::Catedra(){
    codigo=0;
    legprofesor=0;
    codasignatura=0;
    modalidad=0;
    cuatrimestre=0;
    anio=0;
    cantparciales=0;
    estado=false;
}

//-----------------------------------------------LEER DE DISCO
bool Catedra::LeerDeDisco(int pos){
    FILE *C;
    C = fopen("data/Catedras.dat","rb");
    if (C==NULL) return false;
    fseek(C,sizeof *this*pos,0);
    bool leyo = fread(this, sizeof *this, 1, C);
    fclose(C);
    return leyo;
}

//-----------------------------------------------LEER BACKUP
bool Catedra::LeerDeDisco2(int pos){
    FILE *C;
    C = fopen("data/Backups/Catedras.bckp","rb");
    if (C==NULL) return false;
    fseek(C,sizeof *this*pos,0);
    bool leyo = fread(this, sizeof *this, 1, C);
    fclose(C);
    return leyo;
}

//-----------------------------------------------GRABAR CATEDRA
bool Catedra::GrabarCatedra(){
    FILE *C;
    C = fopen("data/Catedras.dat","ab");
    if (C==NULL) return false;
    fwrite(this, sizeof *this, 1, C);
    fclose(C);
    return true;
}

//-----------------------------------------------GRABAR BACKUP
void Catedra::Grabarbckp(){
    FILE *C;
    C = fopen("data/Backups/Catedras.bckp","ab");
    if (C==NULL) return;
    fwrite(this, sizeof *this, 1, C);
    fclose(C);
}

//-----------------------------------------------MODIFICAR CATEDRA EN DISCO
void Catedra::Modificar(int pos){
    FILE *C;
    C = fopen("data/Catedras.dat","rb+");
    if (C==NULL) exit(1);
    fseek(C, sizeof *this*pos,0);
    fwrite(this, sizeof *this,1,C);
    fclose(C);
}

//-----------------------------------------------CARGAR CATEDRA
void Catedra::CargarCatedra(int id=0){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+40-c.getx3(),11); cout << "Codigo: " << id+1;
    gotoxy(c.getx()+40-c.getx3(),12); cout << "Codigo de asignatura: ";
    gotoxy(c.getx()+40-c.getx3(),13); cout << "Legajo del profesor: ";
    gotoxy(c.getx()+40-c.getx3(),14); cout << "modalidad (1= mañana 2= tarde): ";
    gotoxy(c.getx()+40-c.getx3(),15); cout << "Cantidad de parciales (2 o 3): ";
    gotoxy(c.getx()+40-c.getx3(),16); cout << "Año: ";
    gotoxy(c.getx()+40-c.getx3(),17); cout << "Cuatrimestre (1ro - 2do): ";
    codigo= id+1;
    gotoxy(c.getx()+72-c.getx3(),12); cin >> codasignatura;
    while(Verificar_asignatura_existe(codasignatura)==false){
        gotoxy(c.getx()+72-c.getx3(),12);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),12);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: La asignatura no existe en el registro";
        gotoxy(c.getx()+72-c.getx3(),12); cin >> codasignatura;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),12);cout << " ";
    gotoxy(c.getx()+72-c.getx3(),13); cin >> legprofesor;
    while(Verificar_docente_existe(legprofesor)==false){
        gotoxy(c.getx()+72-c.getx3(),13);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),13);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: El docente no existe en el registro";
        gotoxy(c.getx()+72-c.getx3(),13);cin >> legprofesor;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),13);cout << " ";
    gotoxy(c.getx()+72-c.getx3(),14); cin >> modalidad;
    while(Verificar_modalidad_catedra(modalidad)==false){
        gotoxy(c.getx()+72-c.getx3(),14);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),14);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Modalidad incorrecta";
        gotoxy(c.getx()+72-c.getx3(),14); cin >> modalidad;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),14);cout << " ";
    gotoxy(c.getx()+72-c.getx3(),15); cin >> cantparciales;
    while(Verificar_parciales_catedra(cantparciales)==false){
        gotoxy(c.getx()+72-c.getx3(),15);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),15);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Cantidad incorrecta";
        gotoxy(c.getx()+72-c.getx3(),15); cin >> cantparciales;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),15);cout << " ";
    gotoxy(c.getx()+72-c.getx3(),16);cin >> anio;
    while(Verificar_anio_catedra(anio)==false){
        gotoxy(c.getx()+72-c.getx3(),16);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),16);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Año incorrecto";
        gotoxy(c.getx()+72-c.getx3(),16);cin >> anio;
    }
    gotoxy(c.getx()+40-c.getx3(),25);cout<< "                                                   ";
    gotoxy(c.getx()+38-c.getx3(),16);cout << " ";
    gotoxy(c.getx()+72-c.getx3(),17);cin >> cuatrimestre;
    while (Verificar_cuatrimestre_catedra(cuatrimestre)==false){
        gotoxy(c.getx()+72-c.getx3(),17);cout<<"          ";
        gotoxy(c.getx()+38-c.getx3(),17);cout << "!";
        gotoxy(c.getx()+40-c.getx3(),25);cout << "!: Cuatrimestre incorrecto";
        gotoxy(c.getx()+72-c.getx3(),17);cin >> cuatrimestre;
    }
    estado=true;
    }

//-----------------------------------------------BUSCAR Y MOSTRAR NOMBRE DOCENTE
void Buscar_nombre_docente(int leg){
    Docente doc;
    int pos=0;
    while(doc.LeerDeDisco(pos++)){
        if (leg==doc.getlegajo()){
            cout << doc.getnombre();
        }
    }
}

//-----------------------------------------------BUSCAR Y MOSTRAR APELLIDO DOCENTE
void Buscar_apellido_doc(int leg){
    Docente doc;
    int pos=0;
    while(doc.LeerDeDisco(pos++)){
        if (leg==doc.getlegajo()){
            cout << doc.getapellido();
        }
    }
}

//-----------------------------------------------MOSTRAR CATEDRA
void Catedra::MostrarCatedra(){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+40-c.getx3(),11); cout << "codigo: " << codigo;
    gotoxy(c.getx()+40-c.getx3(),12); cout << "codigo de asignatura: " << codasignatura;
    gotoxy(c.getx()+40-c.getx3(),13); cout << "modalidad: " << modalidad;
    gotoxy(c.getx()+40-c.getx3(),14); cout << "año: " << anio;
    gotoxy(c.getx()+40-c.getx3(),15); cout << "cuatrimestre: " << cuatrimestre;
    gotoxy(c.getx()+40-c.getx3(),16); cout << "legajo del docente: " << legprofesor;
    gotoxy(c.getx()+40-c.getx3(),17); cout << "nombre: "; Buscar_nombre_docente(legprofesor);
    gotoxy(c.getx()+40-c.getx3(),18); cout << "apellido: "; Buscar_apellido_doc(legprofesor);
}
