#ifndef CARRERA_H
#define CARRERA_H
#include <Catedra.h>
#include <materia.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include "rlutil.h"
using namespace std;
class Carrera
{
private:
    int duracion; ///En cuatrimestre
    char nombre[100];
    char codigo[10];
    int tipo; //1: De Grado //2: Tecnicatura //3: Licenciatura //4: Doctorado //5: Maestría //6: Especialidad //7: curso
    bool estado;
    int notamin;
    int promocion;
public:
    Carrera();
    bool LeerDeDisco (int );
    bool LeerDeDisco2(int );
    bool GrabarCarrera();
    void Grabarbckp();
    void CargarCarrera();
    void MostrarCarrera(int, int, int, int);
    bool Modificar(int );
    /**gets */
    const char *getcodigo(){return codigo;}
    bool getestado(){return estado;}
    const char *getnombre(){return nombre;}
    int gettipo(){return tipo;}
    int getduracion () {return duracion;}
    int getminaprob () {return notamin;}
    int getminpro () {return promocion;}
    /**sets */
    void setestado(bool est){estado=est;}
    /**des*/
    virtual ~Carrera();
};

#endif // CARRERA_H
