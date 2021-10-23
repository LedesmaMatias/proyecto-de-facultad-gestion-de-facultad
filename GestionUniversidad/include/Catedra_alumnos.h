#ifndef CATEDRA_ALUMNOS_H
#define CATEDRA_ALUMNOS_H
#include "rlutil.h"
#include <cstdio>
#include <cstdlib>

class Catedra_alumnos
{
private:
    int legalumno;
    int codcatedra;
    bool estado;
public:
    Catedra_alumnos();
    bool LeerDeDisco(int );
    bool LeerDeDisco2(int );
    bool GrabarEnDisco();
    void Grabarbckp();
    void Cargar();
    void Modificar(int );
    /**gets*/
    int getlegalumno () {return legalumno;}
    int getcodcat ( ) {return codcatedra;}
    bool getestado () {return estado;}
    /**sets*/
    void setestado (bool newest) {estado = newest;}
};

#endif // CATEDRA_ALUMNOS_H
