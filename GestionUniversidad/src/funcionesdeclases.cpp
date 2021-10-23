#include <funcionesdeclases.h>
using namespace std;

const char *Buscar_carrera_nombre(const char* );


/// FUNCIONES ALUMNO
///-------------------------------------------------------------------

//---------------------------------------------------------ELIMINAR ALUMNO
bool Baja_Alumno (int leg) {
    Conf c;
    c.LeerDeDisco(0);
    Alumno alm;
    int pos=0;
    while (alm.LeerDeDisco(pos++)) {
        if (leg==alm.getlegajo()) {
            if(alm.getestado()) {
                Eliminar_relacionado_alumno(alm.getlegajo());
                if (c.getguardadoautomatico()) backup_alumno();
                alm.setestado(false);
                alm.Modificar(pos-1);
                return true;
            } else {
                return false;
            }

        }
    }
    return false;
}

//---------------------------------------------------------CONTAR LA CANTIDAD DE REGISTROS DE ALUMNO
int contar_cantidad_registro_alumnos(){
    FILE *A;
    int tam,cant;
    A = fopen("data/Alumnos.dat","rb+");
    if (A==NULL) return 0;
    fseek(A,0,2);
    tam = ftell(A);
    fclose(A);
    cant = tam/sizeof (Alumno);
    return cant;
}

//---------------------------------------------------------MOSTRAR ALUMNO SEGUN LEGAJO
bool Mostrar_Alumno_segun_legajo(int leg) {
    Conf c;
    c.LeerDeDisco(0);
    char nombre[100];
    char tecla=NULL;
    Alumno alm;
    int pos=0;
    while (alm.LeerDeDisco(pos++)) {
        if (leg==alm.getlegajo()) {
            if (alm.getestado()==true) {
                strcpy(nombre,Buscar_carrera_nombre(alm.getcodcarrera()));
                alm.mostrarpersona();
                while(true) {
                    gotoxy(c.getx()+45-c.getx3(),25);
                    cout << "flecha izquierda: datos personales";
                    gotoxy(c.getx()+45-c.getx3(),26);
                    cout << "flecha derecha: datos alumno";
                    gotoxy (c.getx()+45-c.getx3(),28);
                    cout << "Enter: salir";
                    tecla = getch();
                    switch(tecla) {
                    case 75:
                        system("cls");
                        alm.mostrarpersona();
                        break;
                    case 77:
                        system("cls");
                        alm.MostrarAlumno(nombre);
                        break;
                    case 13:
                        return true;
                        break;
                    }
                }
            } else {return false; }
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINAR ALUMNO DE CATEDRA
bool Baja_de_catedra(int leg, int cod){
    Catedra_alumnos cata;
    Conf c;
    int pos=0;
    c.LeerDeDisco(0);
    while(cata.LeerDeDisco(pos++)){
        if (cata.getcodcat()==cod && cata.getlegalumno()==leg){
            if (cata.getestado()){
                if (c.getguardadoautomatico()) backup_catedra_alumno();
                cata.setestado(false);
                cata.Modificar(pos-1);
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINAR CALIFICACION DE ALUMNO
bool Baja_Calificacion(int leg, int cod, int tipo, int tiporec){
    Calificacion c;
    Conf cf;
    int pos=0;
    cf.LeerDeDisco(0);
    while(c.LeerDeDisco(pos++)){
            if (c.getestado()){
        if (c.getlegalumno()==leg && c.getcodcatedra()==cod){
            if (tipo==5){
                if (tipo==c.gettipo()&&c.gettiporec()==tiporec){
                    if (cf.getguardadoautomatico()) backup_calificacion();
                    c.setestado(false);
                    c.Modificar(pos-1);
                    return true;
                }
            } else {
                if (tipo==c.gettipo()){
                    if (cf.getguardadoautomatico()) backup_calificacion();
                    c.setestado(false);
                    c.Modificar(pos-1);
                    return true;
                }
            }
        }
    }}
    return false;
}

/// FUNCIONES DOCENTE
///-------------------------------------------------------------------

//---------------------------------------------------------BUSCAR DOCENTE
Docente Buscar_docente(int leg){ //BUSCAR DOCENTE
    Docente doc;
    int pos=0;
    while(doc.LeerDeDisco(pos++)){
        if (doc.getestado()){
            if (doc.getlegajo()==leg){
                return doc;
            }
        }
    }
}

//---------------------------------------------------------CONTAR LA CANTIDAD DE REGISTROS DE DOCENTE
int contar_cantidad_registro_docentes(){
    FILE *A;
    int tam,cant;
    A = fopen("data/Docentes.dat","rb+");
    if (A==NULL) return 0;
    fseek(A,0,2);
    tam = ftell(A);
    fclose(A);
    cant = tam/sizeof (Docente);
    return cant;
}

//---------------------------------------------------------ELIMINAR DOCENTE
bool Baja_Docente (int leg){ //ELIMINAR DOCENTE
    Conf c;
    c.LeerDeDisco(0);
    Docente doc;
    int pos=0;
    while (doc.LeerDeDisco(pos++)) {
        if (leg==doc.getlegajo()) {
            if(doc.getestado()==true) {
                Eliminar_relacionado_docente(doc.getlegajo());
                if (c.getguardadoautomatico())backup_docente();
                doc.setestado(false);
                doc.Modificar(pos-1);
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------CONTAR LAS CATEDRAS DEL DOCENTE
int Contar_catedras_docente(int leg){
    Catedra cat;
    int cant=0;
    int pos=0;
    while(cat.LeerDeDisco(pos++)){
        if (leg==cat.getlegprofesor()){
            if (cat.getestado()){
                cant++;
            }
        }
    }
    return cant;
}

//---------------------------------------------------------MOSTRAR DOCENTE SEGUN LEGAJO
bool Mostrar_Docente_Segun_Legajo(int leg){
    Conf c;
    c.LeerDeDisco(0);
    Docente doc;
    char tecla=NULL;
    int pos=0, cant;
    while(doc.LeerDeDisco(pos++)){
        if (leg==doc.getlegajo()){
            if (doc.getestado()){
                cant= Contar_catedras_docente(leg);
                doc.mostrarpersona();
                while(true) {
                    gotoxy(c.getx()+45-c.getx3(),25);
                    cout << "flecha izquierda: datos personales";
                    gotoxy(c.getx()+45-c.getx3(),26);
                    cout << "flecha derecha: datos docente";
                    gotoxy(c.getx()+45-c.getx3(),27);
                    cout << "Enter: salir";
                    tecla = getch();
                    switch(tecla) {
                    case 75:
                        system("cls");
                        doc.mostrarpersona();
                        break;
                    case 77:
                        system("cls");
                        doc.MostrarDocente(cant);
                        break;
                    case 13:
                        return true;
                        break;
                    }
                }
            } else {return false; }
        }
    }
    return false;
}

/// FUNCIONES CARRERA
///-------------------------------------------------------------------

//---------------------------------------------------------BUSCAR NOMBRE DE LA CARRERA
const char *Buscar_carrera_nombre(const char *cod){
    char *eliminado="ERROR: la carrera fue eliminada o no existe";
    Carrera c;
    int pos=0;
    while (c.LeerDeDisco(pos++)){
        if (strcmp(cod,c.getcodigo())==0){
            if (c.getestado()){
                return c.getnombre();
            } else {
                return eliminado;
                }
            }
        }
        return eliminado;
    }

//---------------------------------------------------------CONTAR ALUMNOS EN LA CARRERA
int Contar_alumnos_en_carrera(const char *cod){
    int cant=0;
    Alumno alm;
    int pos=0;
    while (alm.LeerDeDisco(pos++)){
        if (strcmp(cod,alm.getcodcarrera())==0){
            if (alm.getestado()){
                cant++;
            }
        }
    }
    return cant;
}

//---------------------------------------------------------CONTAR CATEDRAS DE LA CARRERA
int Contar_catedras_de_carrera(const char *cod){
    int cant=0, pos=0, pos2;
    Catedra cat;
    Asignatura asg;
    bool flag;
    while (cat.LeerDeDisco(pos++)){
        if (cat.getestado()){
            pos2=0;
            flag=true;
            while(asg.LeerDeDisco(pos2++) && flag){
            if (cat.getcodasg()==asg.getcodigo()){
                if (strcmp(cod,asg.getcodcarrera())==0){
            if (asg.getestado()){
                cant++;
                flag=false;
            }
        }
            }
        }
}
    }
    return cant;
}

//---------------------------------------------------------CONTAR ASIGNATURAS DE LA CARRERA
int Contar_asignaturas_de_carrera(const char *cod){
    int cant=0,pos=0;
    Asignatura asg;
    while(asg.LeerDeDisco(pos++)){
        if (strcmp(cod,asg.getcodcarrera())==0){
            if (asg.getestado()){
                cant++;
            }
        }
    }
    return cant;
}

//---------------------------------------------------------CONTAR LA CANTIDAD DE HORAS TOTAL DE CARRERA
int Contar_horas_total(Asignatura *m, int cant){
    int total=0;
    for (int i=0;i<cant;i++){
        total+=m[i].gethoras();
    }
    return total;
}

//---------------------------------------------------------MOSTRAR CARRERA POR CODIGO
bool Informar_Carrera_porcodigo(const char *cod){
    Conf c;
    c.LeerDeDisco(0);
    int alm=0,cat=0,asg=0,i=0,totalhoras=0;
    char tecla= NULL;
    Asignatura *mat,m;
    Carrera crr;
    int pos=0,pos2=0;
    while (crr.LeerDeDisco(pos++)) {
        if (strcmp(cod,crr.getcodigo())==0) {
            if (crr.getestado()==true) {
                alm=Contar_alumnos_en_carrera(crr.getcodigo());
                asg=Contar_asignaturas_de_carrera(crr.getcodigo());
                cat=Contar_catedras_de_carrera(crr.getcodigo());
                mat = new Asignatura [asg];
                while (m.LeerDeDisco(pos2++)){
                    if (strcmp(m.getcodcarrera(),crr.getcodigo())==0){
                        if (m.getestado()){
                            mat[i]=m;
                            i++;
                        }
                    }
                }
                totalhoras = Contar_horas_total(mat,asg);
                crr.MostrarCarrera(alm,asg,totalhoras,cat);
                while(true) {
                    gotoxy (c.getx()+45-c.getx3(),28);
                    cout << "Enter: salir";
                    tecla = getch();
                    if (tecla==13) {
                        delete mat;
                        return true;
                        break;
                    }
                }
            } else {return false; }
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINAR CARRERA
bool Baja_Carrera(const char *cod){
    Conf cf;
    Carrera c;
    int pos=0;
    cf.LeerDeDisco(0);
    while (c.LeerDeDisco(pos++)){
        if (strcmp(cod,c.getcodigo())==0){
            if (c.getestado()){
                Eliminar_relacionado_carrera(cod);
                if (cf.getguardadoautomatico()) backup_carrera();
                c.setestado(false);
                return c.Modificar(pos-1);
            } else {
                return false;
            }
        }
    }
    return false;
}


/// FUNCIONES ASIGNATURA
///-------------------------------------------------------------------

//---------------------------------------------------------CONSEGUIR ULTIMO ID ASIGNATURA
int conseguir_ultimo_ID_asignatura(){
    FILE *A;
    int cant=0,tam=0;
    A = fopen("data/Asignaturas.dat","rb");
    if (A==NULL) return 0;
    fseek(A,0,2);
    tam = ftell(A);
    fclose(A);
    cant = tam/sizeof (Materia);
    return cant;
}

//---------------------------------------------------------MOSTRAR ASIGNATURA SEGUN CODIGO
bool Informar_asignatura_codigo(int cod){
    char nombrecar[100];
    Asignatura mat;
    int pos=0;
    while (mat.LeerDeDisco(pos++)){
        if (cod==mat.getcodigo()){
            if (mat.getestado()){
                strcpy(nombrecar,Buscar_carrera_nombre(mat.getcodcarrera()));
                mat.MostrarAsignatura(nombrecar);
                gotoxy(1,30); cout << " ";
                system("pause");
                return true;
            } else {return false;}
        }
    }
    return false;
}

//---------------------------------------------------------ELIMINAR ASIGNATURA
bool Baja_Asignatura(int cod){
    Conf c;
    Asignatura asg;
    int pos=0;
    c.LeerDeDisco(0);
    while (asg.LeerDeDisco(pos++)) {
        if (cod==asg.getcodigo()) {
            if(asg.getestado()==true) {
                Eliminar_relacionado_asignatura(asg.getcodigo());
                if (c.getguardadoautomatico()) backup_asignatura();
                asg.setestado(false);
                asg.Modificar(pos-1);
                return true;
            }
        }
    }
    return false;
}

/// FUNCIONES CATEDRA
///---------------------------------------------------------------------

//---------------------------------------------------------CONSEGUIR ULTIMO ID CATEDRAS
int conseguir_ultimo_ID_catedra(){
    FILE *C;
    int cant=0,tam=0;
    C = fopen("data/Catedras.dat","rb");
    if (C==NULL) return 0;
    fseek(C,0,2);
    tam = ftell(C);
    fclose(C);
    cant = tam/sizeof (Catedra);
    return cant;
}

//---------------------------------------------------------ELIMINAR CATEDRA
bool Baja_Catedra(int cod){
    Conf c;
    Catedra cat;
    int pos=0;
    c.LeerDeDisco(0);
    while(cat.LeerDeDisco(pos++)){
        if(cod==cat.getcodigo()){
            if(cat.getestado()==true){
                Eliminar_relacionado_catedra(cat.getcodigo());
                if (c.getguardadoautomatico()) backup_catedra();
                cat.setestado(false);
                cat.Modificar(pos-1);
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------MOSTRAR CATEDRA SEGUN CODIGO
bool Informar_catedra_codigo(int cod){
    Catedra cat;
    int pos=0;
    while(cat.LeerDeDisco(pos++)){
        if (cod==cat.getcodigo()){
            if (cat.getestado()){
                cat.MostrarCatedra();
                gotoxy(1,30); cout << " ";
                system("pause");
                return true;
            } else {return false;}
        }
    }
    return false;
}

///-------------------------------------------------------------------
///FUNCIONES CONFIGURACION

//---------------------------------------------------------BACKUP ALUMNO
bool backup_alumno(){
    Alumno a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/Alumnos.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
            b = a;
            b.Grabarbckp();
    }
    return true;
}

//---------------------------------------------------------BACKUP DOCENTE
bool backup_docente(){
    Docente a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/Docentes.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
            b = a;
            b.Grabarbckp();
    }
    return true;
}

//---------------------------------------------------------BACKUP CARRERA
bool backup_carrera(){
    Carrera a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/Carreras.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
            b = a;
            b.Grabarbckp();
    }
    return true;
}

//---------------------------------------------------------BACKUP ASIGNATURA
bool backup_asignatura(){
   Asignatura a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/Asignaturas.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
            b = a;
            b.Grabarbckp();
    }
    return true;
}

//---------------------------------------------------------BACKUP CATEDRA
bool backup_catedra(){
    Catedra a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/Catedras.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
            b = a;
            b.Grabarbckp();
    }
    return true;
}

//---------------------------------------------------------BACKUP CATEDRA_ALUMNOS
bool backup_catedra_alumno(){
    Catedra_alumnos a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/catalumnos.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
        if (a.getestado()){
            b = a;
            b.Grabarbckp();
        }
    }
    return true;
}

//---------------------------------------------------------BACKUP CALIFICACION
bool backup_calificacion(){
    Calificacion a,b;
    FILE *BCKP;
    int pos=0;
    if (a.LeerDeDisco(0)==false){
        return false;
    }
    BCKP = fopen("data/Backups/Calificaciones.bckp","wb");
    if (BCKP==NULL) return false;
    fclose(BCKP);
    while(a.LeerDeDisco(pos++)){
        if (a.getestado()){
            b = a;
            b.Grabarbckp();
        }
    }
    return true;
}

///-------------------------------------------------------------------------------------

//---------------------------------------------------------RESTAURAR ALUMNO
bool restaurar_alumno(){
   Alumno a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/Alumnos.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
            b = a;
            b.GrabarAlumno();
    }
    return true;
}

//---------------------------------------------------------RESTAURAR DOCENTE
bool restaurar_docente(){
    Docente a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/Docentes.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
            b = a;
            b.GrabarDocente();
    }
    return true;
}

//---------------------------------------------------------RESTAURAR CARRERA
bool restaurar_carrera(){
    Carrera a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/Carreras.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
        if (a.getestado()){
            b = a;
            b.GrabarCarrera();
        }
    }
    return true;
}

//---------------------------------------------------------RESTAURAR ASIGNATURA
bool restaurar_asignatura(){
    Asignatura a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/Asignaturas.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
            b = a;
            b.Grabar_asignatura();

    }
    return true;
}

//---------------------------------------------------------RESTAURAR CATEDRA
bool restaurar_catedra(){
    Catedra a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/Catedras.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
            b = a;
            b.GrabarCatedra();
    }
    return true;
}

//---------------------------------------------------------RESTAURAR CATEDRA_ALUMNO
bool restaurar_catedra_alumno(){
    Catedra_alumnos a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/catalumnos.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
        if (a.getestado()){
            b = a;
            b.GrabarEnDisco();
        }
    }
    return true;
}

//---------------------------------------------------------RESTAURAR CALIFICACION
bool restaurar_calificacion(){
    Calificacion a,b;
    FILE *A;
    int pos=0;
    if (a.LeerDeDisco2(0)==false){
        return false;
    }
    A = fopen("data/Calificaciones.dat","wb");
    if (A==NULL) return false;
    fclose(A);
    while(a.LeerDeDisco2(pos++)){
        if (a.getestado()){
            b = a;
            b.GrabarEnDisco();
        }
    }
    return true;
}
