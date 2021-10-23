#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "rlutil.h"
#include <string.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Asignatura
{
   private:
    int codigo;
    char nombre[100];
    char codcarrera[10];
    int horas; //cuatrimestrales
    int cuatrimestre;
    bool estado;
public:
    Asignatura();
    void Cargar_asignatura(int );
    bool Grabar_asignatura();
    void Grabarbckp();
    bool LeerDeDisco(int );
    bool LeerDeDisco2(int );
    void MostrarAsignatura(const char*);
    void Modificar(int );
    /** gets */
    int getcuatrimestre(){return cuatrimestre;}
    int getcodigo(){return codigo;}
    bool getestado(){return estado;}
    const char *getcodcarrera(){return codcarrera;}
    const char *getnombre(){return nombre;}
    int gethoras(){return horas;}
    /**sets*/
    void setestado (bool est) { estado= est;}
};

#endif // ASIGNATURA_H
