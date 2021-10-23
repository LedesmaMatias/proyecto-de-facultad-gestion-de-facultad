#include <verificaciones.h>
#include <Clases.h>
#include <Catedra_alumnos.h>
#include <funcionesdeclases.h>
#include <Conf.h>

//---------------------------------------------------------VERIFICA QUE LA CADENA NO SEA VACÍA
bool Verificar_vacio(const char* n) {
    if (strcmp(n,"")!=0 && strcmp(n,"")!=32) {
        return true;
    }
    return false;
}

///----------------------------------------------
///PERSONA
///----------------------------------------------

//---------------------------------------------------------VERIFICA LA FECHA
bool Verificar_persona_fecha(int d, int m, int a) {
    if (a>3000 || a < 1920) { //funcion año actual
        return true;
    }
    if (m>12 || m<1) {
        return true;
    }
    if (d>31 || d<1) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI EXISTE UNA PERSONA CON ESE DNI
bool Verificar_persona_dni(int dni) {
    Alumno a;
    Docente d;
    int pos=0,pos2=0;
    while(a.LeerDeDisco(pos++)) {
        if (a.getestado()) {
            if (a.getdni()==dni) {
                return true;
            }
        }
    }
    while(d.LeerDeDisco(pos2++)) {
        if (d.getestado()) {
            if (d.getdni()==dni) {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA EL GENERO DE LA PERSONA
bool Verificar_persona_genero(char g) {
    if (g=='m' || g=='M') {
        return false;
    }
    if (g=='f' || g=='F') {
        return false;
    }
    if (g=='o' || g=='O') {
        return false;
    }
    return true;
}

///----------------------------------------------
///ALUMNO
///----------------------------------------------

//---------------------------------------------------------BUSCA AL ALUMNO
Alumno Buscar_alumno(int leg) {
    Alumno a;
    int pos=0;
    while (a.LeerDeDisco(pos++)) {
        if (a.getlegajo()==leg) {
            return a;
        } else {
        }
    }
    a.setestado(false);
    return a;
}

//---------------------------------------------------------VERIFICA SI EL ALUMNO EXISTE
bool Verificar_alumno_existe(int leg) {
    Alumno a;
    int pos=0;
    while(a.LeerDeDisco(pos++)) {
        if (a.getestado()) {
            if (a.getlegajo()==leg) {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI EXISTE ALGUN ALUMNO
bool Existe_algun_alumno() {
    Alumno a;
    int pos=0;
    while(a.LeerDeDisco(pos++)) {
        if (a.getestado()) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINA TODO LO RELACIONADO AL ALUMNO
void Eliminar_relacionado_alumno(int leg){
    Conf c;
    c.LeerDeDisco(0);
    Catedra_alumnos cata;
    Calificacion calf;
    int pos=0,pos2=0;
    if (c.getguardadoautomatico())backup_catedra_alumno();
    while(cata.LeerDeDisco(pos++)){
        if (cata.getestado()){
            if (cata.getlegalumno()==leg){
                cata.setestado(false);
                cata.Modificar(pos-1);
            }
        }
    }
    if (c.getguardadoautomatico())backup_calificacion();
    while(calf.LeerDeDisco(pos2++)){
        if (calf.getestado()){
            if (calf.getlegalumno()==leg){
                calf.setestado(false);
                calf.Modificar(pos2-1);
            }
        }
    }

}

///----------------------------------------------
///DOCENTE
///----------------------------------------------

//---------------------------------------------------------VERIFICA SI EXISTE ALGUN DOCENTE
bool Existe_algun_docente() {
    Docente d;
    int pos=0;
    while(d.LeerDeDisco(pos++)) {
        if (d.getestado()) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINA TODO LO RELACIONADO AL DOCENTE
void Eliminar_relacionado_docente(int leg) {
    Conf cf;
    cf.LeerDeDisco(0);
    Catedra c;
    int pos=0;
    if (cf.getguardadoautomatico()) backup_catedra();
    while(c.LeerDeDisco(pos++)) {
        if (c.getlegprofesor()==leg) {
            if (c.getestado()) {
                Eliminar_relacionado_catedra(c.getcodigo());
                c.setestado(false);
                c.Modificar(pos-1);
            }
        }
    }
}

//---------------------------------------------------------VERIFICA SI EL DOCENTE EXISTE
bool Verificar_docente_existe(int leg) {
    Docente d;
    int pos=0;
    while(d.LeerDeDisco(pos++)) {
        if (d.getestado()) {
            if (d.getlegajo()==leg) {
                return true;
            }
        }
    }
    return false;
}

///----------------------------------------------
///CARRERA
///----------------------------------------------

//---------------------------------------------------------BUSCA LA CARRERA
Carrera Buscar_carrera(const char *cod) {
    Carrera c;
    int pos=0;
    while(c.LeerDeDisco(pos++)) {
        if (strcmp(c.getcodigo(),cod)==0) {
            return c;
        }
    }
    c.setestado(false);
    return c;
}

//---------------------------------------------------------VERIFICA SI EXISTE ALGUNA CARRERA
bool Existe_alguna_carrera() {
    Carrera c;
    int pos=0;
    while (c.LeerDeDisco(pos++)) {
        if (c.getestado()) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI LA CARRERA EXISTE
bool Verificar_carrera_existe(const char* cod) {
    Carrera cr;
    int pos=0;
    while(cr.LeerDeDisco(pos++)) {
        if(strcmp(cr.getcodigo(),cod)==0) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA TIPO DE CARRERA
bool Verificar_carrera_tipo(int tipo) {
    if (tipo<1 || tipo>7) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA LA NOTA MINIMA DE CARRERA
bool Verificar_carrera_min(int minn) {
    if (minn<1 || minn>10) {
        return true;
    }
    return false;
}

//---------------------------------------------------------EIMINA TODO LO RELACIONADO DE LA CARRERA
void Eliminar_relacionado_carrera(const char *codcar) {
    Conf c;
    Alumno a;
    Asignatura asg;
    int pos=0,pos2=0;
    c.LeerDeDisco(0);
    if (c.getguardadoautomatico()) backup_alumno();
    while(a.LeerDeDisco(pos++)) {
        if (strcmp(a.getcodcarrera(),codcar)==0) {
            if (a.getestado()) {
                Eliminar_relacionado_alumno(a.getlegajo());
                a.setestado(false);
                a.Modificar(pos-1);
            }
        }
    }
    if (c.getguardadoautomatico()) backup_asignatura();
    while (asg.LeerDeDisco(pos2++)) {
        if (strcmp(asg.getcodcarrera(),codcar)==0) {
            if (asg.getestado()) {
                Eliminar_relacionado_asignatura(asg.getcodigo());
                asg.setestado(false);
                asg.Modificar(pos2-1);
            }
        }
    }
}

//---------------------------------------------------------VERIFICA CUATRIMESTRE DE CARRERA
bool Verificar_carrera_cuatrimestre(int c, const char* cod) {
    Carrera cr;
    int pos=0;
    while(cr.LeerDeDisco(pos++)) {
        if (cr.getestado()) {
            if (strcmp(cr.getcodigo(),cod)==0) {
                if (c<1 || c>cr.getduracion()) {
                    return true;
                }
            }
        }
    }
    return false;
}

///----------------------------------------------
///ASIGNATURA
///----------------------------------------------

//---------------------------------------------------------VERIFICA SI EXISTE ALGUNA ASIGNATURA
bool Existe_alguna_asignatura() {
    Asignatura a;
    int pos=0;
    while (a.LeerDeDisco(pos++)) {
        if (a.getestado()) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINA TODO LO RELACIONADO A LA ASIGNATURA
void Eliminar_relacionado_asignatura(int cod) {
    Conf c;
    Catedra cat;
    int pos=0;
    c.LeerDeDisco(0);
    if (c.getguardadoautomatico()) backup_catedra();
    while(cat.LeerDeDisco(pos++)) {
        if (cat.getcodasg()==cod) {
            if (cat.getestado()) {
                Eliminar_relacionado_catedra(cat.getcodigo());
                cat.setestado(false);
                cat.Modificar(pos-1);
            }
        }
    }
}

//---------------------------------------------------------VERIFICA SI LA ASIGNATURA EXISTE
bool Verificar_asignatura_existe(int cod) {
    Asignatura a;
    int pos=0;
    while(a.LeerDeDisco(pos++)) {
        if (a.getestado()) {
            if (a.getcodigo()==cod) {
                return true;
            }
        }
    }
    return false;
}

///-------------------------------------------------
///CATEDRA
///-------------------------------------------------

//---------------------------------------------------------ELIMINA TODO LO RELACIONADO DE LA CATEDRA
void Eliminar_relacionado_catedra(int cod) {
    Conf c;
    Catedra_alumnos cata;
    int pos=0;
    c.LeerDeDisco(0);
    if (c.getguardadoautomatico()) backup_catedra_alumno();
    while(cata.LeerDeDisco(pos++)) {
        if (cata.getcodcat()==cod) {
            if (cata.getestado()) {
                cata.setestado(false);
                cata.Modificar(pos-1);
            }
        }
    }
}

//---------------------------------------------------------VERIFICA LA MODALIDAD DE LA CATEDRA
bool Verificar_modalidad_catedra(int mod) {
    if (mod == 1 || mod == 2) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA LA CANTIDAD DE PARCIALES DE LA CATEDRA
bool Verificar_parciales_catedra(int cant) {
    if (cant == 2 || cant == 3) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA EL AÑO DE LA CATEDRA
bool Verificar_anio_catedra(int a) {
    if (a>1920 && a<3000) { //funcion año actual
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA EL CUATRIMESTRE DE LA CATEDRA
bool Verificar_cuatrimestre_catedra(int cuat) {
    if(cuat== 1 || cuat == 2) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI LA CATEDRA EXISTE
bool Verificar_catedra_existe(int cod) {
    Catedra c;
    int pos=0;
    while(c.LeerDeDisco(pos++)) {
        if (c.getestado()) {
            if (c.getcodigo()==cod) {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA LA CANTIDAD DE PARCIALES DE LA CATEDRA
bool Verificar_cant_parciales_catedra(int codcat, int n) {
    Catedra c;
    int pos=0;
    if (n==3) {
        while(c.LeerDeDisco(pos++)) {
            if (c.getestado()) {
                if (c.getcodigo()==codcat) {
                    if (c.getcantparciales()==n) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI EXISTE ALGUNA CATEDRA
bool Existe_alguna_catedra() {
    Catedra c;
    int pos=0;
    while(c.LeerDeDisco(pos++)) {
        if (c.getestado()) {
            return true;
        }
    }
    return false;
}

///----------------------------------------------
///CATEDRA_ALUMNO
///----------------------------------------------

//---------------------------------------------------------VERIFICA SI EL ALUMNO ESTA INSCRIPTO EN LA CATEDRA
bool Verificar_alumno_catedra(int leg, int codcat) {
    Catedra_alumnos cata;
    int pos=0;
    while(cata.LeerDeDisco(pos++)) {
        if (cata.getestado()) {
            if (cata.getlegalumno()==leg) {
                if (cata.getcodcat()==codcat) {
                    return true;
                }
            }
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA LA ASIGNATURA DE LA CATEDRA
bool Verificar_asignatura_catedra(int codasg, int leg) {
    Catedra_alumnos cata;
    Catedra cat;
    int pos=0,pos2=0,pos3=0;
    while(cata.LeerDeDisco(pos++)){
        if (cata.getestado()){
            if (cata.getlegalumno()==leg){
                pos2=0;
                while(cat.LeerDeDisco(pos2++)){
                    if (cat.getestado()){
                        if (cat.getcodigo()==cata.getcodcat()){
                            if (cat.getcodasg()==codasg){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI EL ALUMNO CURSA LA CATEDRA/ASIGNATURA
bool Verificar_en_catedra_y_asignatura(int codcat, int leg) {
    Catedra cat;
    Asignatura asg;
    int codasg;
    int pos=0,pos2=0;
    if (Verificar_alumno_catedra(leg,codcat)) {
        return true;
    } else {
        while(cat.LeerDeDisco(pos++)) {
            if (cat.getestado()) {
                if (cat.getcodigo()==codcat) {
                    while(asg.LeerDeDisco(pos2++)) {
                        if (asg.getestado()) {
                            if (cat.getcodasg()==asg.getcodigo()) {
                                codasg=asg.getcodigo();
                                return Verificar_asignatura_catedra(codasg,leg);
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
}

//---------------------------------------------------------VERIFICA SI EL ALUMNO CURSA EN LA CARRERA
bool Verificar_en_carrera(int codcat, int leg){
    Alumno a;
    a = Buscar_alumno(leg);
    Catedra c;
    Asignatura asg;
    int pos=0,pos2;
    while(c.LeerDeDisco(pos++)){
        if (c.getestado()){
            pos2=0;
            if (c.getcodigo()==codcat){
                while(asg.LeerDeDisco(pos2++)){
                if (asg.getestado()){
                    if (c.getcodasg()==asg.getcodigo()){
                        if (strcmp(a.getcodcarrera(),asg.getcodcarrera())==0){
                            return true;
                        } else {
                            return false;
                        }
                    }
            }
        }
    }
    }
    }
    return false;
}

///----------------------------------------------
///CALIFICACION
///----------------------------------------------

//---------------------------------------------------------VERIFICA LA NOTA DE LA CALIFICACION
bool Verificar_nota_calificacion(float nota) {
    if (nota<1 || nota>10) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA EL TIPO DE LA NOTA
bool Verificar_tipo_calificacion(int tipo) {
    if (tipo<1 || tipo>6) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA EL PARCIAL A RECUPERAR
bool Verificar_recuperatorio(int rec) {
    if (rec<1 || rec>3) {
        return true;
    }
    return false;
}

//---------------------------------------------------------VERIFICA SI LA CALIFICACION EXISTE
bool Verificar_nota_existe(int leg, int catedra, int tipo, int tiporec){
    Calificacion c;
    int pos=0;
    if (tipo==4)return false;
    while (c.LeerDeDisco(pos++)){
        if (tipo!=5){
            if (c.getestado()){
                if (c.getlegalumno()==leg && c.getcodcatedra()==catedra && c.gettipo()==tipo){
                    return true;
                }
            }
        } else {
            if (c.getestado()){
                if (c.getlegalumno()==leg && c.getcodcatedra()==catedra && c.gettiporec()==tiporec){
                    return true;
                }
            }
        }
    }
    return false;
}

///----------------------------------------------
///LISTADO
///----------------------------------------------

//---------------------------------------------------------VERIFICA LA TECLA PRESIONADA
bool verificar_tecla_1(char tecla) {
    if (tecla!='a'&&tecla!='A'&&tecla!='s'&&tecla!='S'&&tecla!='d'&&tecla!='D'&&tecla!='f'&&tecla!='F'&&tecla!='g'&&tecla!='G'&&tecla!='x'&&tecla!='X') {
        return true;
    } else {
        return false;
    }
}

//---------------------------------------------------------VERIFICA LA TECLA PRESIONADA
bool verificar_tecla_2(char tecla) {
    if (tecla!='a'&&tecla!='A'&&tecla!='s'&&tecla!='S'&&tecla!='d'&&tecla!='D'&&tecla!='f'&&tecla!='F'&&tecla!='x'&&tecla!='X') {
        return true;
    } else {
        return false;
    }
}

//---------------------------------------------------------VERIFICA LA TECLA PRESIONADA
bool verificar_tecla_3(char tecla) {
    if (tecla!='a'&&tecla!='A'&&tecla!='s'&&tecla!='S'&&tecla!='d'&&tecla!='D'&&tecla!='f'&&tecla!='F'&&tecla!='g'&&tecla!='G'&&tecla!='x'&&tecla!='X'&&tecla!='z'&&tecla!='Z'&&tecla) {
        return true;
    } else {
        return false;
    }
}

