#ifndef LISTADO_H_INCLUDED
#define LISTADO_H_INCLUDED
#include <ctype.h>
#include <Clases.h>
#include <Catedra_alumnos.h>
#include <verificaciones.h>
#include <Conf.h>
using namespace std;


///-----LISTADO ALUMNO
///------------------------------------------------------------------------------------------------

//-----------------------------------------------CUENTA LA CANTIDAD DE ALUMNOS
///FUNCIONES
int contar_alumnos(){
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

//-----------------------------------------------CUENTA LOS ALUMNOS EN LA CARRERA
int contar_alumnos_carrera(const char *cod){
    Alumno a;
    int cant=0,pos=0;
    while(a.LeerDeDisco(pos++)){
        if (strcmp(cod,a.getcodcarrera())==0){
            cant++;
        }
    }
    return cant;
}

//-----------------------------------------------CUENTA LOS ALUMNOS EN LA CATEDRA
int contar_alumnos_catedra(int cod){
    Catedra_alumnos cata;
    int pos=0,cant=0;
    while (cata.LeerDeDisco(pos++)){
        if (cata.getcodcat()==cod){
                if (cata.getestado()){
            cant++;
        }}
    }
    return cant;
}

//-----------------------------------------------BUSCA EL NOMBRE DE LA CARRERA Y LO MUESTRA
void Carrera_nombre(const char *cod, int y){
    char *eliminado="La carrera no existe";
    Conf cf;
    cf.LeerDeDisco(0);
    Carrera c;
    int pos=0;
    while (c.LeerDeDisco(pos++)){
        if (strcmp(cod,c.getcodigo())==0){
            if (c.getestado()){
                gotoxy(cf.getx()+37-cf.getx3(),y+7); cout << "Carrera: " << c.getnombre();
                return;
            } else {
                gotoxy(cf.getx()+37-cf.getx3(),y+7); cout << "Carrera: " << eliminado;
                }
            }
        }
        gotoxy(cf.getx()+35-cf.getx3(),y+7); cout << "Carrera: " << eliminado;
    }

//-----------------------------------------------BUSCA EL NOMBRE DE LA ASIGNATURA Y LO MUESTRA
void Asignatura_nombre(int cod, int y){
    char *eliminado="La Asignatura no existe";
    Conf c;
    c.LeerDeDisco(0);
    Asignatura a;
    int pos=0;
    while(a.LeerDeDisco(pos++)){
        if (cod==a.getcodigo()){
            if (a.getestado()){
                gotoxy(c.getx()+39-c.getx3(),y+6); cout << "Asignatura: " << a.getnombre();
                return;
            }
        }
    }
    gotoxy(c.getx()+39-c.getx3(),y+6); cout << "Asignatura: " << eliminado;
}

//-----------------------------------------------BUSCA LA CATEDRA Y MUESTRA SUS DATOS
void Catedra_nombre(int cod, int y){
    char *eliminado="La catedra no existe";
    Conf cf;
    cf.LeerDeDisco(0);
    Catedra c;
    Docente d;
    int pos=0, pos2=0;
    while(c.LeerDeDisco(pos++)){
            if (c.getcodigo()==cod){
                if (c.getestado()){
                    while(d.LeerDeDisco(pos2++)){
                        if (c.getlegprofesor()==d.getlegajo()){
                            if (d.getestado()){
                                gotoxy(cf.getx()+39-cf.getx3(),y+5); cout << "Catedra: " << cod;
                                Asignatura_nombre(c.getcodasg(),y);
                                gotoxy(cf.getx()+39-cf.getx3(),y+7); cout << "Docente: " << d.getapellido();
                                return;
                            }
                        }
                    }
                }
            }
    }
    gotoxy(cf.getx()+39-cf.getx3(),y+5); cout << "Catedra: " << eliminado;
}

///ORDENAR

//-----------------------------------------------ORDENAR POR LEGAJO
void Ordenar_por_legajo_alumno(Alumno *alm){
Alumno a;
int pos=0,pos2=0;
while(a.LeerDeDisco(pos++)){
    alm[pos2]=a;
    pos2++;
}

}

//-----------------------------------------------ORDENAR POR CARRERA
void Ordenar_por_carrera_alumno(Alumno *alm, const char *cod){
    Alumno a;
    int pos=0,pos2=0;
    while(a.LeerDeDisco(pos++)){
                if (strcmp(cod,a.getcodcarrera())==0){
                    alm[pos2]=a;
                    pos2++;
                }
            }
}

//-----------------------------------------------ORDENAR POR CATEDRA
void Ordenar_por_catedra_alumno(Alumno *alm, int codcat){
    Catedra_alumnos cata;
    Alumno a;
    int pos=0,pos2=0,pos3=0;
    while (a.LeerDeDisco(pos++)){
            if (a.getestado()){
                pos2=0;
                while(cata.LeerDeDisco(pos2++)){
                        if (cata.getestado()){
                            if (a.getlegajo()==cata.getlegalumno()){
                                if (cata.getcodcat()==codcat){
                                    alm[pos3]=a;
                                    pos3++;
                            }
                    }
                }
                }
                }
            }
}

//-----------------------------------------------ORDENAR POR APELIDO
void Ordenar_por_apellido_alumno(Alumno *alm,int cant){
    Alumno temporal;
            for (int z=0; z<cant-1; z++){
                for (int x=z+1; x<cant; x++){
                    int n=0;
                    char ap1[30];
                    char ap2[30];
                    strcpy(ap1,alm[z].getapellido());
                    strcpy(ap2,alm[x].getapellido());
                    for (int c = 0; c<30; c++){
                        ap1[c] = tolower(ap1[c]);
                        ap2[c] = tolower(ap2[c]);
                    }
                    n = strncmp(ap1,ap2,30);
                    if (n>0){
                        temporal=alm[z];
                        alm[z]=alm[x];
                        alm[x]=temporal;
                    }
                }
            }
}

///LISTAR

//-----------------------------------------------MUESTRA LA INFORMACION DEL ALUMNO
void Mostrar_alumno(Alumno alm, int y) {
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+3-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+5-c.getx3(),y);cout << alm.getlegajo();
    gotoxy(c.getx()+23-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+25-c.getx3(),y);cout << alm.getapellido();
    gotoxy(c.getx()+43-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+45-c.getx3(),y);cout << alm.getnombre();
    gotoxy(c.getx()+63-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+65-c.getx3(),y);cout << alm.getcodcarrera();
    gotoxy(c.getx()+75-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+77-c.getx3(),y);cout << alm.getinscripcion().getanio();
    gotoxy(c.getx()+93-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+95-c.getx3(),y);cout << alm.getdni();
    gotoxy(c.getx()+104-c.getx3(),y);cout << " | ";
}

//-----------------------------------------------LISTA A LOS ALUMNOS
void Listar_alumnos(Alumno *alm,int cant, int &y, int anio, bool ani ) {
        Conf c;
        c.LeerDeDisco(0);
        gotoxy(c.getx()+3-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+23-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+43-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+63-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+75-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+93-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+104-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+5-c.getx3(),1); cout << "Legajo";
        gotoxy(c.getx()+25-c.getx3(),1); cout << "Apellido";
        gotoxy(c.getx()+45-c.getx3(),1); cout << "Nombre";
        gotoxy(c.getx()+65-c.getx3(),1); cout << "Carrera";
        gotoxy(c.getx()+77-c.getx3(),1); cout << "Inscripcion (año)";
        gotoxy(c.getx()+95-c.getx3(),1); cout << "DNI";
        for (int j=0; j<cant; j++) {
            if (alm[j].getestado()){
                    if (ani && anio>0){
                        if (alm[j].getinscripcion().getanio()==anio){
                        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|___________________|___________________|___________________|___________|_________________|__________|";
                        Mostrar_alumno(alm[j],y);
                        y=y+2;
            }} else {
                gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|___________________|___________________|___________________|___________|_________________|__________|";
                Mostrar_alumno(alm[j],y);
                y=y+2;

            }
            }
        }
        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|___________________|___________________|___________________|___________|_________________|__________|";
        gotoxy(c.getx()+4-c.getx3(),y+7); cout << "Ordenar por...";
        gotoxy(c.getx()+4-c.getx3(),y+9); cout << "A: Legajo S: Apellido D: Inscripcion F: Carrera G: Catedra ";
        gotoxy(c.getx()+4-c.getx3(),y+10); cout << "X: Salir";
}

//-----------------------------------------------MECANISMO DE LISTADO
void Listado_Alumno() {
    char codcar[10];
    int codcat;
    char tecla= 'a';
    int anio=0;
    bool ani=false;;
    Alumno *alm;
    int cant=0;
    int  y;
    ///----------------------------------------Ordenar por legajo
    cant = contar_alumnos();
    if (cant<=1) {
        cout << "Se requieren mas registros.";
        system("pause");
        return;
    }
    alm = new Alumno[cant];
    Ordenar_por_legajo_alumno(alm);
    ///----------------------------------------Mostrar
    while(tecla!='x' && tecla!='X') {
        rlutil::hidecursor();
        system("cls");
        y=3;
        Listar_alumnos(alm,cant,y,anio,ani);//LISTAR
        ani=false;
        anio=0;
        switch(tecla){
        case 'f':
        case 'F':
            Carrera_nombre(codcar,y);
            break;
        case 'g':
        case 'G':
            Catedra_nombre(codcat,y);
            break;
            };
        delete alm;
        tecla=getch();
        while (verificar_tecla_1(tecla)){
            tecla = getch();
        }
        system("cls");
        rlutil::showcursor();
        switch(tecla){
        case 'a': ///--------------------------Ordenar por legajo
        case 'A': {
            cant = contar_alumnos();
            alm = new Alumno [cant];
            Ordenar_por_legajo_alumno(alm);
            break;
        }
        case 'd': ///--------------------------Ordenar segun año
        case 'D': {
            gotoxy(40,12); cout << "Ingrese año de inscripcion: ";
            cin >> anio;
            cant = contar_alumnos();
            alm = new Alumno [cant];
            Ordenar_por_legajo_alumno(alm);
            ani=true;
            break;
        }
        case 'f': ///--------------------------Ordenar segun carrera
        case 'F': {
            gotoxy(40,12); cout << "Ingrese codigo de carrera: ";
            cin >> codcar;
            cant = contar_alumnos_carrera(codcar);
            alm = new Alumno [cant];
            Ordenar_por_carrera_alumno(alm,codcar);
            break;
        }
        case 'g': ///--------------------------Ordenar segun catedra
        case 'G':
            {
            gotoxy(40,12); cout << "Ingrese codigo de catedra: ";
            cin >> codcat;
            cant = contar_alumnos_catedra(codcat);
            alm = new Alumno [cant];
            Ordenar_por_catedra_alumno(alm,codcat);
            break;
            }
    case 's':  ///--------------------------Ordenar por apellido (intento)
    case 'S': {
            cant = contar_alumnos();
            alm = new Alumno [cant];
            Ordenar_por_legajo_alumno(alm);
            Ordenar_por_apellido_alumno(alm,cant);
        break;
    }
        };
    }
}

///-----LISTADO DOCENTE
///-------------------------------------------------------------------------------------------------------

///FUNCIONES

//-----------------------------------------------CUENTA AL CANTIDAD DE DOCENTES
int Contar_docentes(){
    FILE *D;
    int tam,cant;
    D = fopen("data/Docentes.dat","rb+");
    if (D==NULL) return 0;
    fseek(D,0,2);
    tam = ftell(D);
    fclose(D);
    cant = tam/sizeof (Docente);
    return cant;
}

//-----------------------------------------------VERIFICA EL CODIGO DE CARRERA
bool Buscar_cod_carrera (int cod , const char *codcar){
    Asignatura m;
    int pos=0;
    while (m.LeerDeDisco(pos++)){
        if (m.getestado()){
            if (m.getcodigo()==cod){
                if (strcmp(m.getcodcarrera(),codcar)==0){
                    return true;
                } else {return false;}
            }
        }
    }
    return false;
}

//-----------------------------------------------CUENTA LA CANTIDAD DE DOCENTES EN UNA CARRERA
int Contar_docente_carrera(const char *cod){
    Docente doc;
    Catedra c;
    int cant=0;
    int pos=0, pos2;
    bool flag;
    while(doc.LeerDeDisco(pos++)){
        pos2=0;
        flag=true;
        if (doc.getestado()){
            while(c.LeerDeDisco(pos2++) && flag==true){
                if (c.getestado()){
                    if (doc.getlegajo()==c.getlegprofesor()){
                        if (Buscar_cod_carrera(c.getcodasg(),cod)){
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

///ORDENAR

//-----------------------------------------------ORDENAR POR LEGAJO
void Ordenar_por_legajo_docente(Docente *doc){
    Docente d;
    int pos=0,pos2=0;
    while(d.LeerDeDisco(pos++)) {
        doc[pos2]=d;
        pos2++;
    }
}

//-----------------------------------------------ORDENAR POR APELLIDO
void Ordenar_por_apellido_docente(Docente *doc,int cant){
    Docente temporal;
    for (int z=0; z<cant-1; z++){
        for (int x=z+1; x<cant; x++){
            int n=0;
            char ap1[30];
            char ap2[30];
            strcpy(ap1,doc[z].getapellido());
            strcpy(ap2,doc[x].getapellido());
            for (int c = 0; c<30; c++){
                ap1[c] = tolower(ap1[c]);
                ap2[c] = tolower(ap2[c]);
            }
            n = strncmp(ap1,ap2,30);
            if (n>0){
                temporal=doc[z];
                doc[z]=doc[x];
                doc[x]=temporal;
            }
        }
    }
}

//-----------------------------------------------ORDENAR POR CARRERA
void Ordenar_por_carrera_docente(Docente *doc, const char *codcar){
    Asignatura asg;
    Catedra cat;
    Docente d;
    bool flag;
    int pos=0,pos2=0,pos3=0,pos4=0;
    while (d.LeerDeDisco(pos++)){
            if (d.getestado()){
                pos2=0;
                flag=true;
                while (cat.LeerDeDisco(pos2++) && flag==true){
                    if (cat.getestado()){
                   pos3=0;
                    if (cat.getlegprofesor()==d.getlegajo()){
                        flag=false;
                    while(asg.LeerDeDisco(pos3++)){
                        if (asg.getestado()){
                        if (asg.getcodigo()==cat.getcodasg()){
                        if (strcmp(asg.getcodcarrera(),codcar)==0){
                            doc[pos4]=d;
                            pos4++;
                        }
                    }}}
                }}}
            }}
}

///LISTAR

//-----------------------------------------------MUESTRA LA INFORMACION DEL DOCENTE
void Mostrar_docente(Docente doc, int y){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+3-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+5-c.getx3(),y);cout << doc.getlegajo();
    gotoxy(c.getx()+23-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+25-c.getx3(),y);cout << doc.getapellido();
    gotoxy(c.getx()+43-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+45-c.getx3(),y);cout << doc.getnombre();
    gotoxy(c.getx()+63-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+65-c.getx3(),y);cout << doc.getingreso().getanio();
    gotoxy(c.getx()+77-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+79-c.getx3(),y);cout << doc.getdni();
    gotoxy(c.getx()+93-c.getx3(),y);cout << " | ";
}

//-----------------------------------------------LISTA A LOS DOCENTES
void Listar_docentes(Docente *doc, int cant, int &y, int anio, bool ani){
        Conf c;
        c.LeerDeDisco(0);
        gotoxy(c.getx()+3-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+23-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+43-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+63-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+77-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+93-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+5-c.getx3(),1); cout << "Legajo";
        gotoxy(c.getx()+25-c.getx3(),1); cout << "Apellido";
        gotoxy(c.getx()+45-c.getx3(),1); cout << "Nombre";
        gotoxy(c.getx()+65-c.getx3(),1); cout << "Ingreso (año)";
        gotoxy(c.getx()+79-c.getx3(),1); cout << "DNI";
        for (int j=0; j<cant; j++) {
            if (doc[j].getestado()){
                    if (ani==true && anio>0){
                    if (doc[j].getingreso().getanio()==anio){
                        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|___________________|___________________|___________________|_____________|_______________|";
                        Mostrar_docente(doc[j],y);
                        y=y+2;
                }
            } else {
                gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|___________________|___________________|___________________|_____________|_______________|";
                Mostrar_docente(doc[j],y);
                y=y+2;
            }
        }}
        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|___________________|___________________|___________________|_____________|_______________|";
        gotoxy(c.getx()+4-c.getx3(),y+7); cout << "Ordenar por...";
        gotoxy(c.getx()+4-c.getx3(),y+9); cout << "a: Legajo s: Apellido d: Ingreso f: Carrera ";
        gotoxy(c.getx()+4-c.getx3(),y+10); cout << "x: Salir";
}

//-----------------------------------------------MECANISMO DE LISTADO
void Listado_Docente (){
  char codcar[10];
    int codcat;
    char tecla= 'a';
    int anio=0;
    bool ani=false;
    Docente *doc;
    int cant=0;
    int y;
    ///----------------------------------------Ordenar por legajo
    cant = Contar_docentes();
    if (cant<=1) {
        cout << "Se requieren mas registros.";
        system("pause");
        return;
    }
    doc = new Docente[cant];
    Ordenar_por_legajo_docente(doc);
    ///----------------------------------------Mostrar
    while(tecla!='x' && tecla!='X') {
        rlutil::hidecursor();
        system("cls");
        y=3;
        Listar_docentes(doc,cant,y,anio,ani);
        switch(tecla){
        case 'f':
        case 'F':
            Carrera_nombre(codcar,y);
            break;
            };
        delete doc;
        tecla=getch();
        anio=0;
        ani=false;
        while (verificar_tecla_2(tecla)){
            tecla = getch();
        }
        system("cls");
        rlutil::showcursor();
        switch(tecla){
        case 'a': ///--------------------------Ordenar por legajo
        case 'A':
            cant = Contar_docentes();
            doc = new Docente [cant];
            Ordenar_por_legajo_docente(doc);
            break;
        case 's':
        case 'S': {///------------------------Ordenar por apellido
            cant = Contar_docentes();
            doc = new Docente [cant];
            Ordenar_por_legajo_docente(doc);
            Ordenar_por_apellido_docente(doc,cant);
            break; }
        case 'd': ///--------------------------Ordenar segun año
        case 'D':
            cant = Contar_docentes();
            doc = new Docente [cant];
            Ordenar_por_legajo_docente(doc);
            gotoxy(40,12); cout << "Ingrese año de ingreso: ";
            cin >> anio;
            ani=true;
            break;
        case 'f': ///--------------------------Ordenar segun carrera
        case 'F':
            gotoxy(40,12); cout << "Ingrese codigo de carrera: ";
            cin >> codcar;
            cant = Contar_docente_carrera(codcar);
            doc = new Docente [cant];
            Ordenar_por_carrera_docente(doc,codcar);
            break;
            }
        }
    }

///LISTADO CARRERA
///------------------------------------------------------------------------------------------------

///FUNCIONES
//-----------------------------------------------CUENTA LA CANTIDAD DE CARRERAS
int Contar_carreras(){
    FILE *C;
    int tam,cant;
    C = fopen("data/Carreras.dat","rb+");
    if (C==NULL) return 0;
    fseek(C,0,2);
    tam = ftell(C);
    fclose(C);
    cant = tam/sizeof (Carrera);
    return cant;
}

//-----------------------------------------------CUENTA LA CANTIDAD DE CARRERAS SEGUN TIPO
int Contar_carrera_tipo(int t){
Carrera cr;
int pos=0, cant=0;
while (cr.LeerDeDisco(pos++)){
    if (cr.getestado()){
        if (cr.gettipo()==t){
            cant++;
        }
    }
}
return cant;
}

///ORDENAR

//-----------------------------------------------ORDENA LAS CARRERAS
void Ordenar_carrera(Carrera *cr){
    Carrera c;
    int pos=0,pos2=0;
    while(c.LeerDeDisco(pos++)) {
        cr[pos2]=c;
        pos2++;
    }
}

//-----------------------------------------------ORDENA LAS CARRERAS POR CODIGO
void Ordenar_por_codigo_carrera(Carrera *cr, int cant){
    Carrera temporal;
            for (int z=0; z<cant-1; z++){
                for (int x=z+1; x<cant; x++){
                    int n=0;
                    char cod1[10];
                    char cod2[10];
                    strcpy(cod1,cr[z].getcodigo());
                    strcpy(cod2,cr[x].getcodigo());
                    for (int c = 0; c<10; c++){
                        cod1[c] = tolower(cod1[c]);
                        cod2[c] = tolower(cod2[c]);
                    }
                    n = strncmp(cod1,cod2,10);
                    if (n>0){
                        temporal=cr[z];
                        cr[z]=cr[x];
                        cr[x]=temporal;
                    }
                }
            }
}

//-----------------------------------------------ORDENAR POR CANTIDAD DE ALUMNOS
void Ordenar_por_cantidad_alumnos_carrera(Carrera *cr, int cant){
    Carrera temporal;
            for (int z=0; z<cant-1; z++){
                for (int x=z+1; x<cant; x++){
                    int n1=contar_alumnos_carrera(cr[z].getcodigo());
                    int n2=contar_alumnos_carrera(cr[x].getcodigo());
                    if (n1<n2){
                        temporal=cr[z];
                        cr[z]=cr[x];
                        cr[x]=temporal;
                    }
                }
            }
}

//-----------------------------------------------ORDENAR POR DURACION
void Ordenar_por_duracion_carrera(Carrera *cr,int cant){
    Carrera temporal;
            for (int z=0; z<cant-1; z++){
                for (int x=z+1; x<cant; x++){
                    if (cr[z].getduracion()<cr[x].getduracion()){
                        temporal=cr[z];
                        cr[z]=cr[x];
                        cr[x]=temporal;
                    }
                }
            }
}

//-----------------------------------------------ORDENAR POR TIPO
void Ordenar_por_tipo_carrera(Carrera *cr,int tipo){
    Carrera c;
    int pos=0,pos2=0;
    while(c.LeerDeDisco(pos++)){
                if (c.gettipo()==tipo){
                    if (c.getestado()){
                    cr[pos2]=c;
                    pos2++;
                }}
            }
}

///LISTAR

//-----------------------------------------------MUESTRA LA INFORMACION DE LA CARRERA
void Mostrar_carrera(Carrera cr, int y){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+3-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+5-c.getx3(),y);cout << cr.getcodigo();
    gotoxy(c.getx()+14-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+16-c.getx3(),y);cout << cr.getnombre();
    gotoxy(c.getx()+85-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+87-c.getx3(),y);cout << cr.gettipo();
    gotoxy(c.getx()+90-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+92-c.getx3(),y);cout << cr.getduracion();
    gotoxy(c.getx()+101-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+103-c.getx3(),y);cout << contar_alumnos_carrera(cr.getcodigo());
    gotoxy(c.getx()+118-c.getx3(),y);cout << " | ";
}

//-----------------------------------------------LISTA LAS CARRERAS
void Listar_carrera(Carrera *cr, int cant, int &y){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+3-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+14-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+85-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+90-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+101-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+118-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+5-c.getx3(),1); cout << "Codigo";
        gotoxy(c.getx()+16-c.getx3(),1); cout << "Nombre";
        gotoxy(c.getx()+87-c.getx3(),1); cout << "tipo";
        gotoxy(c.getx()+92-c.getx3(),1); cout << "*Duración";
        gotoxy(c.getx()+103-c.getx3(),1); cout << "Cant. Alumnos";
        for (int j=0; j<cant; j++) {
            if (cr[j].getestado()){
                        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|__________|______________________________________________________________________|____|__________|________________|";
                        Mostrar_carrera(cr[j],y);
                        y=y+2;
            }
        }
        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|__________|______________________________________________________________________|____|__________|________________|";
        gotoxy(c.getx()+4-c.getx3(),y+7); cout << "Ordenar por..."; gotoxy(27,y+7); cout << "*Duracion en cuatrimestres";
        gotoxy(c.getx()+4-c.getx3(),y+9); cout << "A: Codigo S: Cantidad de alumnos D: Duración F: Tipo ";
        gotoxy(c.getx()+4-c.getx3(),y+10); cout << "x: Salir";
}

//-----------------------------------------------MECANISMO DE LISTADO
void Listado_Carrera(){
    int tipo;
    char tecla= 'a';
    Carrera *cr;
    int cant=0,cant2=0;
    int y;
    ///----------------------------------------Ordenar
    cant = Contar_carreras();
    if (cant<=2) {
        cout << "Se requieren mas registros.";
        system("pause");
        return;
    }
    cr = new Carrera [cant];
    Ordenar_carrera(cr);
    Ordenar_por_codigo_carrera(cr,cant);
    ///----------------------------------------Mostrar
    while(tecla!='x' && tecla!='X') {
        rlutil::hidecursor();
        system("cls");
        y=3;
        Listar_carrera(cr,cant,y);
        delete cr;
        tecla=getch();
        while (verificar_tecla_2(tecla)){
            tecla=getch();
        }
        system("cls");
        rlutil::showcursor();
        switch(tecla){
        case 'a':
        case 'A': {///--------------------------Ordenar por codigo
            cant = Contar_carreras();
            cr = new Carrera [cant];
            Ordenar_carrera(cr);
            Ordenar_por_codigo_carrera(cr,cant);
            break;
        }
        case 's': ///--------------------------Ordenar por cantidad de alumnos
        case 'S': {
            cant = Contar_carreras();
            cr = new Carrera [cant];
            Ordenar_carrera(cr);
            Ordenar_por_cantidad_alumnos_carrera(cr,cant);
            break;
        }
        case 'd': ///--------------------------Ordenar por duración
        case 'D': {
            cant = Contar_carreras();
            cr = new Carrera [cant];
            Ordenar_carrera(cr);
            Ordenar_por_duracion_carrera(cr,cant);
            break;
        }
        case 'f': ///--------------------------Ordenar por tipo
        case 'F':
            gotoxy(40,12); cout << "Ingrese el tipo de carrera: ";
            cin >> tipo;
            cant = Contar_carrera_tipo(tipo);
            if (cant>0){
            cr = new Carrera [cant];
            Ordenar_por_tipo_carrera(cr,tipo);
            }
            break;
        }}

}

///LISTADO ASIGNATURA
///------------------------------------------------------------------------------------------------

///FUNCIONES

//-----------------------------------------------CUENTA LA CANTIDAD DE ASIGNATURAS
int Contar_Asignaturas(){
    FILE *A;
    int tam,cant;
    A = fopen("data/Asignaturas.dat","rb+");
    if (A==NULL) return 0;
    fseek(A,0,2);
    tam = ftell(A);
    fclose(A);
    cant = tam/sizeof (Asignatura);
    return cant;
}

//-----------------------------------------------CUENTA AL CANTIDAD DE ASIGNATURAS DE CARRERA
int Contar_asignatura_carrera(const char* cod){
    Asignatura asg;
    int pos=0,cant=0;
    while(asg.LeerDeDisco(pos++)){
        if (asg.getestado()){
            if (strcmp(asg.getcodcarrera(),cod)==0){
                cant++;
            }
        }
    }
    return cant;
}

//-----------------------------------------------CUENTA LA CANTIDAD DE CATEDRAS DE ASIGNATURA
int Contar_catedras_asignatura(int cod){
    Catedra cat;
    int pos=0,cant=0;
    while(cat.LeerDeDisco(pos++)){
        if (cat.getestado()){
            if (cat.getcodasg()==cod){
                cant++;
            }
        }
    }
    return cant;
}

///ORDENAR
//-----------------------------------------------ORDENAR POR CODIGO DE ASIGNATURA
void Ordenar_por_codigo_asignatura(Asignatura *asi){
    Asignatura a;
    int pos=0,pos2=0;
    while(a.LeerDeDisco(pos++)) {
        asi[pos2]=a;
        pos2++;
    }
}

//-----------------------------------------------ORDENAR POR NOMBRE DE ASIGNATURA
void Ordenar_por_nombre_asignatura(Asignatura *asi, int cant){
    Asignatura temporal;
            for (int z=0; z<cant-1; z++){
                for (int x=z+1; x<cant; x++){
                    int n=0;
                    char nombre1[100];
                    char nombre2[100];
                    strcpy(nombre1,asi[z].getnombre());
                    strcpy(nombre2,asi[x].getnombre());
                    for (int c = 0; c<100; c++){
                        nombre1[c] = tolower(nombre1[c]);
                        nombre2[c] = tolower(nombre2[c]);
                    }
                    n = strncmp(nombre1,nombre2,30);
                    if (n>0){
                        temporal=asi[z];
                        asi[z]=asi[x];
                        asi[x]=temporal;
                    }
                }
            }
}

//-----------------------------------------------ORDENAR POR CARRERA
void Ordenar_por_carrera_asignatura(Asignatura *asi, const char *codcar){
    Asignatura a;
    int pos=0,pos2=0;
    while (a.LeerDeDisco(pos++)){
                if (strcmp(a.getcodcarrera(),codcar)==0){
                    asi[pos2]=a;
                    pos2++;
                }
            }
}

//-----------------------------------------------ORDENAR POR CANTIDAD DE CATEDRAS
void Ordenar_por_catedra_asignatura(Asignatura *asi,int cant){
    Asignatura temporal;
    for (int z=0; z<cant-1; z++){
                    for (int x=z+1; x<cant; x++){
                        if (Contar_catedras_asignatura(asi[z].getcodigo())<Contar_catedras_asignatura(asi[x].getcodigo())){
                            temporal=asi[z];
                            asi[z]=asi[x];
                            asi[x]=temporal;
                        }
                    }
                }
}

///LISTADO

//-----------------------------------------------MUESTRA LA INFORMACION DE LA ASIGNAUTRA
void Mostrar_asignatura(Asignatura asg, int y){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+3-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+5-c.getx3(),y);cout << asg.getcodigo();
    gotoxy(c.getx()+10-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+12-c.getx3(),y);cout << asg.getnombre();
    gotoxy(c.getx()+68-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+70-c.getx3(),y);cout << asg.getcodcarrera();
    gotoxy(c.getx()+88-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+90-c.getx3(),y);cout << asg.gethoras();
    gotoxy(c.getx()+101-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+103-c.getx3(),y); cout << Contar_catedras_asignatura(asg.getcodigo());
    gotoxy(c.getx()+116-c.getx3(),y); cout << " | ";
}

//-----------------------------------------------LISTA LAS ASIGNATURAS
void Listar_asignatura(Asignatura *asi, int cant, int &y){
        Conf c;
        c.LeerDeDisco(0);
        gotoxy(c.getx()+3-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+10-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+68-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+88-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+101-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+116-c.getx3(),1); cout << " | ";
        gotoxy(c.getx()+5-c.getx3(),1); cout << "ID";
        gotoxy(c.getx()+12-c.getx3(),1); cout << "Nombre";
        gotoxy(c.getx()+70-c.getx3(),1); cout << "Carrera";
        gotoxy(c.getx()+90-c.getx3(),1); cout << "Cant. horas";
        gotoxy(c.getx()+103-c.getx3(),1); cout << "Cant. catedras";
        for (int j=0; j<cant; j++) {
            if (asi[j].getestado()){
                        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|______|_________________________________________________________|___________________|____________|______________|";
                        Mostrar_asignatura(asi[j],y);
                        y=y+2;
            }
        }
        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|______|_________________________________________________________|___________________|____________|______________|";
        gotoxy(c.getx()+4-c.getx3(),y+7); cout << "Ordenar por...";
        gotoxy(c.getx()+4-c.getx3(),y+9); cout << "a: ID s: Nombre d: Carrera f: Catedras ";
        gotoxy(c.getx()+4-c.getx3(),y+10); cout << "x: Salir";
}

//-----------------------------------------------MECANISMO DE LISTADO
void Listado_Asignatura(){
    char tecla= 'a';
    char codcar[10];
    Asignatura *asi;
    int cant=0;
    int y;
    ///----------------------------------------Ordenar
    cant = Contar_Asignaturas();
    if (cant<=1) {
        cout << "Se requieren mas registros.";
        system("pause");
        return;
    }
    asi = new Asignatura [cant];
    Ordenar_por_codigo_asignatura(asi);
    ///----------------------------------------Mostrar
    while(tecla!='x' && tecla!='X') {
        rlutil::hidecursor();
        system("cls");
        y=3;
        Listar_asignatura(asi,cant,y);

        switch(tecla){
        case 'd':
        case 'D':
            Carrera_nombre(codcar,y);
            break;
            };
        delete asi;
        tecla=getch();
        while(verificar_tecla_2(tecla)){
            tecla=getch();
        }
        system("cls");
        rlutil::showcursor();
        switch(tecla){
        case 'a': ///--------------------------Ordenar por ID
        case 'A':
            cant = Contar_Asignaturas();
            asi = new Asignatura [cant];
            Ordenar_por_codigo_asignatura(asi);
            break;
        case 's': ///--------------------------Ordenar por nombre
        case 'S':{
            cant = Contar_Asignaturas();
            asi = new Asignatura [cant];
            Ordenar_por_codigo_asignatura(asi);
            Ordenar_por_nombre_asignatura(asi,cant);
            break; }
        case 'd': ///--------------------------Ordenar por carrera
        case 'D':
            gotoxy(40,12); cout << "Ingrese el codigo de carrera: ";
            cin >> codcar;
            cant = Contar_asignatura_carrera(codcar);
            asi = new Asignatura [cant];
            Ordenar_por_carrera_asignatura(asi,codcar);
            break;
        case 'f':///---------------------------Ordenar por catedras
        case 'F':
            cant = Contar_Asignaturas();
            asi = new Asignatura [cant];
            Ordenar_por_codigo_asignatura(asi);
            Ordenar_por_catedra_asignatura(asi,cant);
            break;

        };}

}

///LISTADO CATEDRAS
///------------------------------------------------------------------------------------------------

///FUNCIONES
//-----------------------------------------------CUENTA LA CANTIDAD DE CATEDRAS
int Contar_catedras(){
 FILE *C;
    int tam,cant;
    C = fopen("data/Catedras.dat","rb+");
    if (C==NULL) return 0;
    fseek(C,0,2);
    tam = ftell(C);
    fclose(C);
    cant = tam/sizeof (Catedra);
    return cant;
}

//-----------------------------------------------BUSCA EL APELLIDO DEL DOCENTE Y LO MUESTRA
void Buscar_apellido_docente(int leg){
    Docente doc;
    int pos=0;
    while(doc.LeerDeDisco(pos++)){
        if (doc.getlegajo()== leg){
            if (doc.getestado()){
                cout << doc.getapellido();
                return;
            } else {
                cout << "No existe";
                return;
            }
        }
    }
    cout << "No existe";
}

//-----------------------------------------------CUENTA LAS CATEDRAS DE X CARRERA
int contar_carreras_catedra(const char* cod){
    Catedra c;
    int cant=0;
    int pos=0;
    while (c.LeerDeDisco(pos++)){
       if (c.getestado()){
            if (Buscar_cod_carrera(c.getcodasg(),cod)){
                            cant++;
                        }
                    }
    }
    return cant;
}

//-----------------------------------------------CUENTA LAS CATEDRAS DE X MODALIDAD
int contar_catedras_modalidad(int mod){
    Catedra cat;
    int pos=0,cant=0;
    while(cat.LeerDeDisco(pos++)){
        if (cat.getmodalidad()==mod){
            if (cat.getestado()){
                cant++;
            }
        }
    }
    return cant;
}

//-----------------------------------------------CUENTA LAS CATEDRAS DE DOCENTE
int contar_docentes_catedra(int leg){
Catedra c;
int pos=0,cant=0;
while (c.LeerDeDisco(pos++)){
    if (c.getlegprofesor()==leg){
        if (c.getestado()){
            cant++;
        }
    }
}
return cant;
}

///ORDENAR

//-----------------------------------------------ORDENA POR CODIGO
void Ordenar_por_codigo_catedra(Catedra *cat){
    Catedra c;
    int pos=0,pos2=0;
    while(c.LeerDeDisco(pos++)) {
        cat[pos2]=c;
        pos2++;
    }
}

//-----------------------------------------------ORDENA POR CARRERA
void Ordenar_por_carrera_catedra(Catedra *cat,const char *codcar){
    Asignatura asg;
    Catedra c;
    int pos=0,pos2=0,pos3=0;
    while (c.LeerDeDisco(pos++)){
            if (c.getestado()){
                         pos2=0;
                        while(asg.LeerDeDisco(pos2++)){
                            if (asg.getcodigo()==c.getcodasg()){
                                    if (asg.getestado()){
                            if (strcmp(asg.getcodcarrera(),codcar)==0){
                                cat[pos3]=c;
                                pos3++;
                                }
                        }
                        }
                    }
    }
}
}

//-----------------------------------------------ORDENA POR ASIGNATURA
void Ordenar_por_asignatura_catedra(Catedra *cat,int codasg){
    Catedra c;
    int pos=0, pos2=0;
    while(c.LeerDeDisco(pos++)){
                    if (c.getcodasg()==codasg){
                            if (c.getestado()){
                        cat[pos2]=c;
                        pos2++;

                        }
                    }
                }
}

//-----------------------------------------------ORDENA POR MODALIDAD
void Ordenar_por_modalidad_catedra(Catedra *cat,int modalidad){
    Catedra c;
    int pos=0,pos2=0;
    while (c.LeerDeDisco(pos++)){
                if (c.getmodalidad()==modalidad){
                    if (c.getestado()){
                        cat[pos2]=c;
                        pos2++;
                    }
                }
            }
}

//-----------------------------------------------ORDENA POR DOCENTE
void Ordenar_por_docente_catedra(Catedra *cat,int leg){
Catedra c;
int pos=0, pos2=0;
while (c.LeerDeDisco(pos++)){
    if (c.getlegprofesor()==leg){
            if (c.getestado()){
        cat[pos2]=c;
        pos2++;
            }}
}
}

///LISTAR

//-----------------------------------------------MUESTRA LA INFORMACION DE LA CATEDRA
void Mostrar_catedra(Catedra cat, int y){
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+3-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+5-c.getx3(),y);cout << cat.getcodigo();
    gotoxy(c.getx()+10-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+12-c.getx3(),y); Buscar_apellido_docente(cat.getlegprofesor());
    gotoxy(c.getx()+35-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+37-c.getx3(),y);cout << cat.getlegprofesor();
    gotoxy(c.getx()+52-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+54-c.getx3(),y);cout << cat.getcodasg();
    gotoxy(c.getx()+73-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+75-c.getx3(),y);cout << cat.getanio();
    gotoxy(c.getx()+88-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+90-c.getx3(),y);cout << ((cat.getmodalidad()==1)? "Mañana":"Tarde");
    gotoxy(c.getx()+100-c.getx3(),y);cout << " | ";
}

//-----------------------------------------------LISTA LAS CATEDRAS
void Listar_catedra(Catedra *cat,int cant,int &y,int anio,bool ani){
        Conf c;
        c.LeerDeDisco(0);
        gotoxy(c.getx()+3-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+10-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+35-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+52-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+73-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+88-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+100-c.getx3(),1);cout << " | ";
        gotoxy(c.getx()+5-c.getx3(),1); cout << "ID";
        gotoxy(c.getx()+12-c.getx3(),1); cout << "Titular";
        gotoxy(c.getx()+37-c.getx3(),1); cout << "leg. Titular";
        gotoxy(c.getx()+54-c.getx3(),1); cout << "ID asignatura";
        gotoxy(c.getx()+75-c.getx3(),1); cout << "Año";
        gotoxy(c.getx()+90-c.getx3(),1); cout << "Modalidad";
        for (int j=0; j<cant; j++) {
            if (cat[j].getestado()){
                    if (ani==true && anio>0){
                        if (anio==cat[j].getanio()){
                        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|______|________________________|________________|____________________|______________|___________|";
                        Mostrar_catedra(cat[j],y);
                        y=y+2;
            }}else {
                gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|______|________________________|________________|____________________|______________|___________|";
                Mostrar_catedra(cat[j],y);
                y=y+2;
            }}
        }
        gotoxy(c.getx()+4-c.getx3(),y-1); cout << "|______|________________________|________________|____________________|______________|___________|";
        gotoxy(c.getx()+4-c.getx3(),y+7); cout << "Ordenar por...";
        gotoxy(c.getx()+4-c.getx3(),y+9); cout << "A: ID S: Carrera D: Asignatura F: Año G: Modalidad Z: Docente";
        gotoxy(c.getx()+4-c.getx3(),y+10); cout << "x: Salir";
}

//-----------------------------------------------MECANISMO DE LISTADO
void Listado_Catedra(){
    int leg;
    int modalidad;
    int anio=0;
    bool ani=false;
    int codasg;
    char tecla= 'a';
    char codcar[10];
    Catedra *cat;
    int cant=0;
    int y;
    ///----------------------------------------Ordenar
    cant = Contar_catedras();
    if (cant<=1) {
        cout << "Se requieren mas registros.";
        system("pause");
        return;
    }
    cat = new Catedra [cant];
    Ordenar_por_codigo_catedra(cat);
    ///----------------------------------------Mostrar
    while(tecla!='x' && tecla!='X'){
        rlutil::hidecursor();
        system("cls");
        y=3;
        Listar_catedra(cat,cant,y,anio,ani);
        switch(tecla){
        case 's':
        case 'S':
            Carrera_nombre(codcar,y);
            break;
        case 'd':
        case 'D':
            Asignatura_nombre(codasg,y+1);
            break;
            };
        anio=0;
        ani=false;
        delete cat;
        tecla=getch();
        while (verificar_tecla_3(tecla)){
            tecla=getch();
        }
        system("cls");
        rlutil::showcursor();
        switch(tecla){
        case 'a': ///--------------------------Ordenar por ID
        case 'A':
            cant = Contar_catedras();
            cat = new Catedra [cant];
            Ordenar_por_codigo_catedra(cat);
            break;
        case 's': ///--------------------------Ordenar por carrera
        case 'S': {
            gotoxy(40,12); cout << "Ingrese codigo de carrera: ";
            cin >> codcar;
            cant = contar_carreras_catedra(codcar);
            cat = new Catedra [cant];
            Ordenar_por_carrera_catedra(cat,codcar);
            break;
        }
        case 'd': ///--------------------------Ordenar por asignatura
        case 'D':
            gotoxy(40,12); cout << "Ingrese codigo de asignatura: ";
            cin >> codasg;
            cant = Contar_catedras_asignatura(codasg);
            cat = new Catedra [cant];
            Ordenar_por_asignatura_catedra(cat,codasg);
            break;
        case 'f':{///---------------------------Ordenar por año
        case 'F':
            cant = Contar_catedras();
            cat = new Catedra [cant];
            Ordenar_por_codigo_catedra(cat);
            gotoxy(40,12); cout << "Ingrese el año: ";
            cin >> anio;
            ani=true;
        break;
        }
    case 'g':
    case 'G':///-------------------------------Ordenar segun modalidad
            gotoxy(40,12); cout << "Ingrese la modalidad (1=Mañana 2=Tarde): ";
            cin >> modalidad;
            cant = contar_catedras_modalidad(modalidad);
            cat = new Catedra [cant];
            Ordenar_por_modalidad_catedra(cat,modalidad);
        break;
    case 'z':
    case 'Z':///-------------------------------Ordenar segun docente
        gotoxy(40,12); cout << "Ingrese el legajo del docente: ";
        cin >> leg;
        cant = contar_docentes_catedra(leg);
        cat = new Catedra [cant];
        Ordenar_por_docente_catedra(cat,leg);
        break;
        }}
}
#endif // LISTADO_H_INCLUDED
