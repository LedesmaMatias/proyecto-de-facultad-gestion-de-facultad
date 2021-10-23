#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
#include <verificaciones.h>
#include <Conf.h>
///ESTADO ACADEMICO

//---------------------------------------------------------CONTAR ASIGNATURAS DE LA CARRERA
int Contar_materias_carrera(const char *codcar) {
    Asignatura a;
    int cant=0,pos=0;
    while (a.LeerDeDisco(pos++)) {
        if (a.getestado()) {
            if (strcmp(a.getcodcarrera(),codcar)==0) {
                cant++;
            }
        }
    }
    return cant;
}

//---------------------------------------------------------CARGAR ASIGNATURAS
void Cargar_asignaturas(Asignatura *asg, const char *codcar) {
    Asignatura a;
    int pos=0,pos2=0;
    while(a.LeerDeDisco(pos++)) {
        if (strcmp(a.getcodcarrera(),codcar)==0) {
            asg[pos2]=a;
            pos2++;
        }
    }
}

//---------------------------------------------------------ORDENAR ASIGNATURAS
void Ordenar_asignaturas(Asignatura *asg, int cant) {
    Asignatura temporal;
    for (int z=0; z<cant-1; z++) {
        for (int x=z+1; x<cant; x++) {
            if (asg[z].getcuatrimestre()>asg[x].getcuatrimestre()) {
                temporal=asg[z];
                asg[z]=asg[x];
                asg[x]=temporal;
            }
        }
    }
}

//---------------------------------------------------------MOSTRAR ESTADO ACADEMICO
void Mostrar_estado_academico(const char *nombre, int estado,int y) {
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+1-c.getx3(),y);
    cout << " | ";
    gotoxy(c.getx()+3-c.getx3(),y);
    cout << nombre;
    gotoxy(c.getx()+69-c.getx3(),y);
    cout << " | ";
    switch(estado) {
    case 0:
        gotoxy(c.getx()+71-c.getx3(),y);
        cout << "-";
        break;
    case 1:
        gotoxy(c.getx()+71-c.getx3(),y);
        cout << "Promocionada";
        break;
    case 2:
        gotoxy(c.getx()+71-c.getx3(),y);
        cout << "Aprobada";
        break;
    case 3:
        gotoxy(c.getx()+71-c.getx3(),y);
        cout << "Cursa";
        break;
    }
    gotoxy(c.getx()+83-c.getx3(),y);
    cout << " | ";
}

//---------------------------------------------------------VERIFICAR ESTADO
int verificar_estado(float *notas, int minaprob, int minpromocion) {
    float cant =0;
    if (notas[2]>0) { //si son  tres parciales
        cant = (notas[0]+notas[1]+notas[2])/3;
        if (cant>=minpromocion) {
            return 1;
        } else if (notas[3]>minaprob){
        return 2;
    } else if (cant>=minaprob) {
            return 3;
        }
    } else { //si son dos parciales
        cant = (notas[0]+notas[1])/2;
        if (cant>=minpromocion) {
            return 1;
        } else if (notas[3]>minaprob){
        return 2;
        } else if (cant>=minaprob) {
            return 3;
        }
    }
    for (int i=0;i<4;i++){
        if (notas[i]>0){
            return 3;
        }
    }
    return 0;
}

//---------------------------------------------------------RETORNAR EL MINIMO APROBADO/PROMOCION DE CARRERA
int returnmin(int codasg, int tipo) {
    Asignatura asg;
    Carrera carr;
    int pos=0,pos2=0;
    while (asg.LeerDeDisco(pos++)) {
        if (asg.getestado()) {
            if (asg.getcodigo()==codasg) {
                while (carr.LeerDeDisco(pos2++)) {
                    if (carr.getestado()) {
                        if (strcmp(asg.getcodcarrera(),carr.getcodigo())==0) {
                            switch(tipo) {
                            case 1:
                                return carr.getminaprob();
                            case 2:
                                return carr.getminpro();
                            }
                        }
                    }
                }
            }
        }
    }
    switch(tipo) {
    case 1:
        return 6;
    case 2:
        return 8;
    }
}

//---------------------------------------------------------OBTIENE LAS NOTAS DEL ALUMNO SEGUN ASIGNATURA
int verificar_estado_1(int leg, int codasg) {
    Calificacion calf;
    Catedra cat;
    int pos=0,pos2;
    int estado=0;
    float notas[6]= {0};
    while (calf.LeerDeDisco(pos++)) {
        if (calf.getestado()) {
            if (calf.getlegalumno()==leg) {
                pos2=0;
                while (cat.LeerDeDisco(pos2++)) {
                    if (cat.getestado()) {
                        if (cat.getcodigo()==calf.getcodcatedra()) {
                            if (cat.getcodasg()==codasg) {
                                if (calf.gettipo()==5){
                                    notas[calf.gettiporec()-1]=calf.getnota();
                                } else {
                                notas[calf.gettipo()-1]=calf.getnota();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return estado = verificar_estado(notas,returnmin(codasg,1),returnmin(codasg,2));
}

//---------------------------------------------------------LISTADO DE ESTADO ACADEMICO
void Estado_academico_listado(int leg, Asignatura *asg, int cant, Alumno a) {
    Conf c;
    c.LeerDeDisco(0);
    int y=4;
    gotoxy(c.getx()+40-c.getx3(),1); cout << "Alumno: " << a.getapellido() << " " << a.getnombre();
    gotoxy(c.getx()+2-c.getx3(),2); cout << "___________________________________________________________________________________";
    gotoxy(c.getx()+1-c.getx3(),3);
    cout << " | ";
    gotoxy(c.getx()+3-c.getx3(),3);
    cout << "Nombre de la asignatura";
    gotoxy(c.getx()+69-c.getx3(),3);
    cout << " | ";
    gotoxy(c.getx()+71-c.getx3(),3);
    cout << "Estado";
    gotoxy(c.getx()+83-c.getx3(),3);
    cout << " | ";
    for (int i=0; i<cant; i++) {
        gotoxy(c.getx()+2-c.getx3(),y);
        cout <<"|___________________________________________________________________|_____________|";
        Mostrar_estado_academico(asg[i].getnombre(),verificar_estado_1(leg,asg[i].getcodigo()),y+1);
        y = y+2;
    }
    gotoxy(c.getx()+2-c.getx3(),y);cout << "|___________________________________________________________________|_____________|";
    cout << endl << endl;
    system("pause");
}

//---------------------------------------------------------ESTADO ACADEMICO
void Estado_academico() {
    Asignatura *asg;
    Carrera cr;
    Alumno a;
    int leg,pos=0;
    gotoxy(40,12);
    rlutil::showcursor();
    cout << "Ingrese el legajo del alumno: ";
    cin >> leg;
    system("cls");
    rlutil::hidecursor();
    a = Buscar_alumno(leg);
    if (a.getestado()==false) {
        cout << "El alumno no existe" << endl;
        system("pause");
        return;
    }
    cr = Buscar_carrera(a.getcodcarrera());
    int cant=0;
    cant = Contar_materias_carrera(cr.getcodigo());
    if (cant<=1) {
        cout << "Se necesitas mas registros" << endl;
        system("pause");
        return;
    }
    asg = new Asignatura [cant];
    Cargar_asignaturas(asg,cr.getcodigo());
    Ordenar_asignaturas(asg,cant);
    Estado_academico_listado(leg,asg,cant, a);
}

///EXAMENES FINALES

//---------------------------------------------------------CONTAR CALIFICACIONES DE FINAL
int Contar_calificaciones_finales(int leg){
    Calificacion calf;
    int pos=0, cant=0;
    while(calf.LeerDeDisco(pos++)){
        if (calf.getestado()){
            if (calf.gettipo()==4){
                if (calf.getlegalumno()==leg){
                    cant++;
                }
            }
        }
    }
    return cant;
}

//---------------------------------------------------------CARGA LAS CALIFICACIONES DE FINAL
void Cargar_calificaciones_finales(Calificacion *c, int leg){
Calificacion calf;
int pos=0,pos2=0;
while(calf.LeerDeDisco(pos++)){
    long sumatoria=0;
    if (calf.getestado()){
        if (calf.gettipo()==4){
            if (calf.getlegalumno()==leg){
                c[pos2]=calf;
                sumatoria= (c[pos2].getf().getanio()*10000) + (c[pos2].getf().getmes()*100)+c[pos2].getf().getdia();
                c[pos2].setfx(sumatoria);
                pos2++;
            }
        }
    }
}
}

//---------------------------------------------------------ORDENA LOS EXAMENES FINALES POR FECHA
void Ordenar_fecha_examen(Calificacion *c,int cant){
    Calificacion temporal;
     for (int z=0; z<cant-1; z++) {
        for (int x=z+1; x<cant; x++) {
            if (c[z].getf().getx()>c[x].getf().getx()) {
                temporal=c[z];
                c[z]=c[x];
                c[x]=temporal;
            }
        }
    }
}

//---------------------------------------------------------MUESTRA EL NOMBRE DE LA ASIGNATURA
void Mostrar_nombre_asignatura(int codcat){
Asignatura asg;
Catedra cat;
char *error="No existe";
int pos=0,pos2;
while (cat.LeerDeDisco(pos++)){
    if (cat.getcodigo()==codcat){
        if (cat.getestado()){
            pos2=0;
            while(asg.LeerDeDisco(pos2++)){
                if (cat.getcodasg()==asg.getcodigo()){
                    if (asg.getestado()){
                        cout << asg.getnombre();
                    }
                }
            }
        }
    }
}
}

//---------------------------------------------------------MUESTRA LOS EXAMENES FINALES
void Mostrar_examenes_finales(Calificacion c, int y){
Conf cf;
cf.LeerDeDisco(0);
gotoxy(cf.getx()+11-cf.getx3(),y);cout << " | ";
gotoxy(cf.getx()+13-cf.getx3(),y);cout << c.getf().getdia() << "/" << c.getf().getmes() << "/" << c.getf().getanio();
gotoxy(cf.getx()+23-cf.getx3(),y);cout << " | ";
gotoxy(cf.getx()+25-cf.getx3(),y);Mostrar_nombre_asignatura(c.getcodcatedra());
gotoxy(cf.getx()+71-cf.getx3(),y);cout << " | ";
gotoxy(cf.getx()+73-cf.getx3(),y);if (c.getnota()>0){ cout << c.getnota();} else {cout << "auns";}
gotoxy(cf.getx()+77-cf.getx3(),y);cout << "| ";
gotoxy(cf.getx()+78-cf.getx3(),y);cout << c.getcodcatedra();
gotoxy(cf.getx()+95-cf.getx3(),y);cout << " | ";
}

//---------------------------------------------------------LISTADO DE EXAMENES FINALES
void Listar_examenes_finales(Calificacion *c,int cant, Alumno a){
    Conf cf;
    cf.LeerDeDisco(0);
    int y=4;
    gotoxy(cf.getx()+25-cf.getx3(),1);cout << "Alumno: " << a.getapellido() << " " << a.getnombre();
    gotoxy(cf.getx()+2-cf.getx3(),2);cout <<"          _____________________________________________________________________________________";
    gotoxy(cf.getx()+11-cf.getx3(),3);cout << " | ";
    gotoxy(cf.getx()+13-cf.getx3(),3);cout << "Fecha";
    gotoxy(cf.getx()+23-cf.getx3(),3);cout << " | ";
    gotoxy(cf.getx()+25-cf.getx3(),3);cout << "Asignatura";
    gotoxy(cf.getx()+71-cf.getx3(),3);cout << " | ";
    gotoxy(cf.getx()+73-cf.getx3(),3);cout << "Nota";
    gotoxy(cf.getx()+77-cf.getx3(),3);cout << "| ";
    gotoxy(cf.getx()+78-cf.getx3(),3);cout << "Codigo de catedra";
    gotoxy(cf.getx()+95-cf.getx3(),3);cout << " | ";
    for (int i=0; i<cant; i++) {
        gotoxy(cf.getx()+2-cf.getx3(),y);
        cout <<"          |___________|_______________________________________________|____|__________________|";
        Mostrar_examenes_finales(c[i],y+1);
        y = y+2;
    }
    gotoxy(cf.getx()+2-cf.getx3(),y); cout << "          |___________|_______________________________________________|____|__________________|";
    cout << endl << endl << endl << endl << endl;
    system("pause");
}

//---------------------------------------------------------EXAMENES FINALES
void Examenes_finales(){
    Calificacion *calf;
    Alumno a;
    int cant, leg;
    rlutil::showcursor();
    gotoxy(40,12); cout << "Ingrese el legajo del alumno: ";
    cin >> leg;
    rlutil::hidecursor();
    system("cls");
    a = Buscar_alumno(leg);
    if (a.getestado()==false){
        cout << "el alumno no existe" << endl;
        system("pause");
        return;
    }
    cant = Contar_calificaciones_finales(leg);
    if (cant<=1){
        cout << "Se necesitan mas registros";
        system("pause");
        return;
    }
    calf = new Calificacion [cant];
    Cargar_calificaciones_finales(calf,leg);
    Ordenar_fecha_examen(calf,cant);
    Listar_examenes_finales(calf,cant,a);
}

///NOTAS PARCIALES DE ALUMNO

//---------------------------------------------------------CUENTA LA CANTIDAD DE CALIFICACIONES
int Contar_calificaciones(int leg){
    Calificacion c;
    int pos=0,cant=0;
    while(c.LeerDeDisco(pos++)){
        if (c.getestado()){
            if (c.getlegalumno()==leg){
                if (c.gettipo()!=4 && c.gettipo()!=6){
                cant++;
            }}
        }
    }
    return cant;
}

//---------------------------------------------------------CARGA LAS CALIFICACIONES
void Cargar_calificaciones(Calificacion *c, int leg){
    Calificacion calf;
    int pos=0,pos2=0;
    while(calf.LeerDeDisco(pos++)){
        if (calf.getestado()){
            if (calf.getlegalumno()==leg){
                if (calf.gettipo()!=4 && calf.gettipo()!=6){
                c[pos2]=calf;
                pos2++;
            }}
        }
    }
}

//---------------------------------------------------------CUENTA LAS CATEDRAS QUE EL ALUMNO ESTA INSCRIPTO
int Contar_catedras_alumno(int leg){
    Catedra_alumnos cata;
    int pos=0,cant=0;
    while(cata.LeerDeDisco(pos++)){
        if (cata.getestado()){
            if(cata.getlegalumno()==leg){
                cant++;
            }
        }
    }
    return cant;
}

//---------------------------------------------------------CARGA LAS CATEDRAS QUE EL ALUMNO ESTA INSCRIPTO
void Cargar_catedras_alumno(Catedra_alumnos *cat,int leg){
    Catedra_alumnos c;
    int pos=0,pos2=0;
    while(c.LeerDeDisco(pos++)){
        if (c.getestado()){
            if (c.getlegalumno()==leg){
                cat[pos2]=c;
                pos2++;
            }
        }
    }
}

//---------------------------------------------------------MUESTRA LA NOTA DE LA CALIFICACION
void Mostrar_calificaciones_2(Calificacion c,int x, int y){
Conf cf;
cf.LeerDeDisco(0);
gotoxy(cf.getx()+x-cf.getx3(),y);cout << c.getnota();
}

//---------------------------------------------------------MUESTRA EL NOMBRE DE LA ASIGNATURA
void Mostrar_calificaciones_1(Catedra_alumnos cata,int y){
Conf c;
c.LeerDeDisco(0);
gotoxy(c.getx()+1-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+3-c.getx3(),y);Mostrar_nombre_asignatura(cata.getcodcat());
gotoxy(c.getx()+43-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+52-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+58-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+64-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+70-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+73-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+76-c.getx3(),y);cout << " | ";
gotoxy(c.getx()+79-c.getx3(),y);cout << " | ";
}

//---------------------------------------------------------LISTADO DE NOTAS PARCIALES
void Listar_notas_parciales(Calificacion *c, Catedra_alumnos *cata,int cant, int cant2, Alumno a){
    Conf cf;
    cf.LeerDeDisco(0);
    int y=4,x;
    gotoxy(cf.getx()+43-cf.getx3(),1);cout << "Alumno: " << a.getapellido() << "  " << a.getnombre();
    gotoxy(cf.getx()+2-cf.getx3(),2); cout << "_______________________________________________________________________________";
    gotoxy(cf.getx()+1-cf.getx3(),3);cout << " | ";
    gotoxy(cf.getx()+3-cf.getx3(),3);cout << "Asignatura";
    gotoxy(cf.getx()+43-cf.getx3(),3);cout << " | ";
    gotoxy(cf.getx()+45-cf.getx3(),3);cout << "*Notas: | 1er | 2do | 3er | recup  |";
    for (int i=0; i<cant2; i++) {
        gotoxy(cf.getx()+2-cf.getx3(),y);
        if (i==0){
            cout <<"|_________________________________________|________|_____|_____|_____|________|";
        } else {
            cout <<"|_________________________________________|________|_____|_____|_____|__|__|__|";
        }
        int j=0;
        Mostrar_calificaciones_1(cata[i],y+1);
        for (j=0; j<cant;j++) {
            if (cata[i].getcodcat()==c[j].getcodcatedra()){
            switch(c[j].gettipo()){
            case 1:
                x=56;
                break;
            case 2:
                x=62;
                break;
            case 3:
                x=68;
                break;
            case 5:
                switch(c[j].gettiporec()){
                case 1:
                    x=72;
                    break;
                case 2:
                    x=75;
                    break;
                case 3:
                    x=78;
                    break;
                }

                break;
            }
            Mostrar_calificaciones_2(c[j],x,y+1);
        }}
        y = y+2;
    }
    gotoxy(cf.getx()+2-cf.getx3(),y); cout << "|_________________________________________|________|_____|_____|_____|__|__|__|";
    cout << endl << endl << endl << endl << endl << endl;
    system("pause");
}

//---------------------------------------------------------NOTAS PARCIALES
void Notas_parciales(){
    Catedra_alumnos *cata;
    Calificacion *calf;
    Alumno a;
    int cant,cant2, leg;
    rlutil::showcursor();
    gotoxy(40,12); cout << "Ingrese el legajo del alumno: ";
    cin >> leg;
    rlutil::hidecursor();
    system("cls");
    a = Buscar_alumno(leg);
    if (a.getestado()==false){
        cout << "El alumno no existe" << endl;
        system("pause");
        return;
    }
    cant = Contar_calificaciones(leg);
    cant2 = Contar_catedras_alumno(leg);
    if (cant<=1){
        cout << "Se necesitan mas registros";
        system("pause");
        return;
    }
    calf = new Calificacion [cant];
    cata = new Catedra_alumnos [cant2];
    Cargar_calificaciones(calf,leg);
    Cargar_catedras_alumno(cata,leg);
    Listar_notas_parciales(calf,cata,cant,cant2, a);
}

///PLAN DE ESTUDIOS CARRERA

//---------------------------------------------------------MUESTRA LA ASIGNATURA DE CARRERA
void Mostrar_plan_de_estudios(Asignatura asg, int y) {
    Conf c;
    c.LeerDeDisco(0);
    gotoxy(c.getx()+1-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+3-c.getx3(),y);cout << asg.getnombre();
    gotoxy(c.getx()+55-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+57-c.getx3(),y);cout << asg.getcodigo();
    gotoxy(c.getx()+69-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+77-c.getx3(),y);cout << asg.getcuatrimestre();
    gotoxy(c.getx()+83-c.getx3(),y);cout << " | ";
    gotoxy(c.getx()+85-c.getx3(),y);cout << asg.gethoras();
    gotoxy(c.getx()+106-c.getx3(),y);cout << " | ";
}

//---------------------------------------------------------LISTA TODAS LAS ASIGNATURAS DE LA CARRERA
void Listar_plan_de_estudios(Asignatura *asg,Carrera cr,int cant) {
     int y=4;
     Conf c;
     c.LeerDeDisco(0);
    gotoxy(c.getx()+35-c.getx3(),1);cout << cr.getnombre();
    gotoxy(c.getx()+2-c.getx3(),2);cout << "__________________________________________________________________________________________________________";
    gotoxy(c.getx()+1-c.getx3(),3);cout << " | ";
    gotoxy(c.getx()+3-c.getx3(),3);cout << "Asignaturas";
    gotoxy(c.getx()+55-c.getx3(),3);cout << " | ";
    gotoxy(c.getx()+57-c.getx3(),3);cout << "Codigo";
    gotoxy(c.getx()+69-c.getx3(),3);cout << " | ";
    gotoxy(c.getx()+71-c.getx3(),3);cout << "Cuatrimestre";
    gotoxy(c.getx()+83-c.getx3(),3);cout << " | ";
    gotoxy(c.getx()+85-c.getx3(),3);cout << "Horas semanales";
    gotoxy(c.getx()+106-c.getx3(),3);cout << " | ";
    for (int i=0; i<cant; i++) {
        gotoxy(c.getx()+2-c.getx3(),y);
        cout <<"|_____________________________________________________|_____________|_____________|______________________|";
        Mostrar_plan_de_estudios(asg[i],y+1);
        y = y+2;
    }
    gotoxy(c.getx()+2-c.getx3(),y);cout << "|_____________________________________________________|_____________|_____________|______________________|";
    cout << endl << endl;
    system("pause");
}

//---------------------------------------------------------PLAN DE ESTUDIOS
void Plan_de_estudios() {
    Carrera cr;
    Asignatura *asg;
    char codcar[10];
    int cant=0;
    gotoxy(40,12);
    rlutil::showcursor();
    cout << "Ingrese el codigo de la carrera: ";
    cin >> codcar;
    system("cls");
    rlutil::hidecursor();
    if (Verificar_carrera_existe(codcar)==false){
        cout << "La carrera no existe" << endl;
        system("pause");
        return;
    }
    cant = Contar_materias_carrera(codcar);
    if (cant <=1 ) {
        cout << "Se necesitan mas registros de la carrera: " << endl;
        system("pause");
        return;
    }
    cr = Buscar_carrera(codcar);
    asg = new Asignatura [cant];
    Cargar_asignaturas(asg,codcar);
    Ordenar_asignaturas(asg,cant);
    Listar_plan_de_estudios(asg,cr,cant);
}

#endif // INFORME_H_INCLUDED
