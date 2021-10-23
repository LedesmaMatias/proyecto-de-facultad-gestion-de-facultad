#ifndef MATERIA_H
#define MATERIA_H
#include "rlutil.h"
#include <string.h>
#include <cstdio>
#include <cstdlib>

class Materia
{
private:
    int codigo;
    char nombre[100];
    char codcarrera[10];
    int horas;
    bool estado;
public:
    Materia();
    void Cargar_asignatura(int );
    bool Grabar_asignatura();
    bool LeerDeDisco(int );
    void Mostrar_asignatura(const char*);
    /** gets */
    int getcodigo(){return codigo;}
    bool getestado(){return estado;}
    const char *getcodcarrera(){return codcarrera;}
    const char *getnombre(){return nombre;}
    int gethoras(){return horas;}
};

#endif // MATERIA_H
