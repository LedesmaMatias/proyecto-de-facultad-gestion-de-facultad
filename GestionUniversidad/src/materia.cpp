#include "Materia.h"
#include <cstdlib>
using namespace std;

Materia::Materia()
{
    //ctor
}

bool Materia::Grabar_asignatura(){
    FILE *A;
    A = fopen("data/Asignaturas.dat","ab");
    if (A==NULL) return false;
    fwrite(this,sizeof *this,1,A);
    fclose(A);
    return true;
}

bool Materia::LeerDeDisco(int pos){
    FILE *A;
    A = fopen("data/Asignaturas.dat","rb");
    if (A==NULL) return false;
    fseek(A,sizeof *this*pos,0);
    bool leyo= fread(this, sizeof *this,1,A);
    fclose(A);
    return leyo;
}

void Materia::Mostrar_asignatura(const char* nombrecar){
    gotoxy(40,11); cout << "Codigo: " << codigo;
    gotoxy(40,12); cout << "Nombre: " << nombre;
    gotoxy(40,13); cout << "Codigo de carrera: " << codcarrera;
    gotoxy(40,14); cout << "Nombre carrera: " << nombrecar;
    gotoxy(40,16); cout << "horas cuatrimestrales: " << horas;
}

void Materia::Cargar_asignatura(int ultid=0){
    gotoxy(40,11); cout << "Codigo: " << ultid+1;
    gotoxy(40,12); cout << "Nombre de la asignatura: ";
    gotoxy(40,13); cout << "Codigo de carrera: ";
    gotoxy(40,14); cout << "Horas cuatrimestrales: ";
    codigo=ultid+1;
    gotoxy(80,12); cin.ignore(); cin.getline(nombre,100);
    gotoxy(80,13); cin >> codcarrera;
    gotoxy(80,14); cin >> horas;
    estado=true;
}
