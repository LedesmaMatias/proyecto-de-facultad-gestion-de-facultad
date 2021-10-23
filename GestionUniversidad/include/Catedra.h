#ifndef CATEDRA_H
#define CATEDRA_H
#include "rlutil.h"
#include <Persona.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>

class Catedra
{
private:
    int codigo;
    int legprofesor;
    int codasignatura;
    int modalidad;
    int cuatrimestre; //1ro o 2do
    int anio;
    int cantparciales; //2 - 3
    bool estado;
public:
    Catedra();
    bool LeerDeDisco(int );
    bool LeerDeDisco2(int );
    bool GrabarCatedra();
    void Grabarbckp();
    void Modificar(int );
    void CargarCatedra(int );
    void MostrarCatedra();
    /** gets */
    int getcodigo (){return codigo;}
    bool getestado () {return estado;}
    int getcodasg () {return codasignatura;}
    int getlegprofesor () {return legprofesor;}
    int getcuatrimestre () {return cuatrimestre;}
    int getanio () {return anio;}
    int getmodalidad () {return modalidad;}
    int getcantparciales () {return cantparciales;}
    /** sets */
    void setestado (bool est) {estado = est;}
};

#endif // CATEDRA_H
