#ifndef CALIFICACION_H
#define CALIFICACION_H
#include "rlutil.h"
#include <cstdlib>
#include <cstdio>
#include "Fecha.h"

class Calificacion ///CLASE CALIFICACIONES
{
  private:
    float nota;
    int codcatedra;
    int legalumno;
    int tipo; //(1=1erparcial 2=2do parcial 3=3er parcial (Dependiendo de la catedra) 4=final 5=recuperatorio [Se aclara que parcial se recupera, si el primero o el segundo] 6=trabajo practico
    int tiporec; //1=1er parcial 2= 2doparcial 3=3erparcial
    Fecha calif;
    bool estado=true;
public:
    Calificacion();
    bool LeerDeDisco(int );
    bool LeerDeDisco2(int );
    bool GrabarEnDisco();
    void Grabarbckp();
    void CargarCalificacion();
    void Modificar (int );
    /** gets */
    float getnota () {return nota;}
    int getcodcatedra () {return codcatedra;}
    int getlegalumno () {return legalumno;}
    int gettipo () {return tipo;}
    int gettiporec() {return tiporec;}
    bool getestado () {return estado;}
    Fecha getf () {return calif;}
    /**sets */
    void setestado (bool newest) {estado = newest;}
    void setfx (long newx) {calif.setx(newx);}
};

#endif // CALIFICACION_H
