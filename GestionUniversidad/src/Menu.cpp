#include "Menu.h"
#include "rlutil.h"
#include <Listado.h>
#include <Informe.h>
#include <Conf.h>
#include <funcionesdeclases.h>
using namespace std;

/**-----MENU PRINCIPÁL-----*/

void MPrincipal::AbrirMenuPrincipal() {
    Conf c;
    c.LeerDeDisco(0);
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(c.getx(),9);
        cout << "   MENÚ PRINCIPAL" << endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "ALUMNOS" <<  endl;
        gotoxy(c.getx(),12);
        cout <<   "DOCENTES"  << endl;
        gotoxy(c.getx(),13);
        cout  << "FACULTAD" <<  endl;
        gotoxy(c.getx(),14);
        cout << "INFORME" << endl;
        gotoxy(c.getx(),15);
        cout << "CONFIGURACION" << endl;
        gotoxy(c.getx(),16);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==17) {
                y--;
            }
            break;
        case 13:
            switch( y ) {
            case 11:
                Menu_Alumnos();
                system("cls");
                break;
            case 12:
                Menu_Docentes();
                system("cls");
                break;
            case 13:
                Menu_Facultad();
                system("cls");
                break;
            case 14:
                Menu_Informe();
                system("cls");
                break;
            case 15:
                Menu_config();
                system("cls");
                break;
            case 16:
                system("cls");
                return;
                break;
            }
            break;
        }
    }

}



/**-----MENU ALUMNOS-----*/

void MAlumnos::AbrirMenuAlumno() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(c.getx(),9);
        cout << "   MENÚ ALUMNOS "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "AGREGAR ALUMNO" <<  endl;
        gotoxy(c.getx(),12);
        cout << "AGREGAR CALIFICACION" << endl; /* Se agrega una calificacion, puede ser primer cuatrimestre, segundo o final */
        gotoxy(c.getx(),13);
        cout << "AGREGAR A CATEDRA" << endl; /* Se agrega asignatura y catedra donde el alumno cursa */
        gotoxy(c.getx(),14);
        cout << "LISTAR ALUMNO" << endl; /* Se listan todos sus datos + materias que cursa */
        gotoxy(c.getx(),15);
        cout << "LISTAR TODOS LOS ALUMNOS" << endl;
        gotoxy(c.getx(),16);
        cout <<  "ELIMINAR ALUMNO"  << endl;
        gotoxy(c.getx(),17);
        cout <<  "ELIMINAR DE CATEDRA"  << endl;
        gotoxy(c.getx(),18);
        cout <<  "ELIMINAR CALIFICACIÓN"  << endl;
        gotoxy(c.getx(),19);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==20) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11: ///-----------------------------------------------AGREGAR ALUMNO
                if (RegistrarAlumno()==true) {
                    cout << "Alumno registrado con exito" << endl;
                } else {
                    cout << "error al eliminar alumno" << endl;
                }
                system("pause");
                break;
            case 12:///------------------------------------------------AGREGAR CALIFICACION
                if (AgregarCalificacion()==true) {
                    cout << "Calificacion registrada con exito" << endl;
                } else {
                    cout << "Error al registrar" << endl;
                }
                system("pause");
                break;
            case 13:///------------------------------------------------AGREGAR CATEDRA
                if (AgregarCatedra()==true) {
                    cout << "Alumno agregado a catedra con exito" << endl;
                } else {
                    cout << "Error al registrar" << endl;
                }
                system("pause");
                break;
            case 14:///------------------------------------------------LISTAR ALUMNO POR LEGAJO
                MostrarAlumno();
                break;
            case 15:///------------------------------------------------LISTAR TODOS LOS ALUMNOS
                Listado_Alumno();
                break;
            case 16:///------------------------------------------------ELIMINAR ALUMNO
                if (EliminarAlumno()==true) {
                    cout << "Alumno eliminado con exito" << endl;
                } else {
                    cout << "El alumno no existe o ya fue eliminado anteriormente" << endl;
                }
                system("pause");
            case 17:
                if (EliminarDeCatedra()==true){
                    cout << "Alumno eliminado de catedra con exito" << endl;
                } else {
                cout << "Error al eliminar alumno de catedra" << endl;
                }
                system("pause");
                break;
            case 18:
                if (EliminarCalificacion()==true){
                    cout << "Calificación eliminada con exito" << endl;
                } else {
                    cout << "Error al eliminar calificación" << endl;
                }
                system("pause");
            case 19:///------------------------------------------------SALIR
                y=11;
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}



/**-----MENU DOCENTES-----*/

void MDocentes::AbrirMenuDocente() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(c.getx(),9);
        cout << "   MENÚ DOCENTES "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "AGREGAR DOCENTE" <<  endl;
        gotoxy(c.getx(),12);
        cout << "LISTAR DOCENTE" << endl;
        gotoxy(c.getx(),13);
        cout << "LISTAR TODOS LOS DOCENTES" << endl;
        gotoxy(c.getx(),14);
        cout <<  "ELIMINAR DOCENTE"  << endl;
        gotoxy(c.getx(),15);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==16) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11: ///-----------------------------------------------AGREGAR DOCENTE
                if (AgregarDocente()==true) {
                    cout << "REGISTRADO CON EXITO" << endl;
                } else {
                    cout << "ERROR AL REGISTRAR DOCENTE" << endl;
                }
                system("pause");
                break;
            case 12:///------------------------------------------------LISTAR DOCENTE POR LEGAJO
                MostrarDocente();
                break;
            case 13:///------------------------------------------------LISTAR TODOS LOS DOCENTES
                Listado_Docente();
                break;
            case 14:///------------------------------------------------ELIMINAR DOCENTE
                if (EliminarDocente()==true) {
                    cout << "Docente eliminado con exito" << endl;
                } else {
                    cout << "El Docente no existe o ya fue eliminado anteriormente" << endl;
                }
                system("pause");
                break;
            case 15:///------------------------------------------------SALIR
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}



/**-----MENU FACULTAD-----*/

void MFacultad::AbrirMenuFacultad() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   MENÚ FACULTAD" << endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "CARRERAS" <<  endl;
        gotoxy(c.getx(),12);
        cout <<   "ASIGNATURAS"  << endl;
        gotoxy(c.getx(),13);
        cout << "CATEDRAS" << endl;
        gotoxy(c.getx(),14);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==15) {
                y--;
            }
            break;
        case 13:
            switch( y ) {
            case 11:///------------------------------------------------ABRIR MENU CARRERA
                Menu_Carreras();
                system("cls");
                break;
            case 12:///------------------------------------------------ABRIR MENU ASIGNATURAS
                Menu_Materias();
                system("cls");
                break;
            case 13:///------------------------------------------------ABRIR MENU CATEDRAS
                Menu_Catedras();
                system ("cls");
                break;
            case 14:
                system("cls");
                return;
                break;
            }
            break;
        }
    }

}



/**-----MENU CARRERA-----*/

void MCarreras::AbrirMenuCarrera() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   MENÚ CARRERAS "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "AGREGAR CARRERA" <<  endl;
        gotoxy(c.getx(),12);
        cout << "LISTAR CARRERA" << endl;
        gotoxy(c.getx(),13);
        cout << "LISTAR TODAS LAS CARRERAS" << endl;
        gotoxy(c.getx(),14);
        cout <<  "ELIMINAR CARRERA"  << endl;
        gotoxy(c.getx(),15);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==16) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11: ///-----------------------------------------------AGREGAR CARRERA
                if (AgregarCarrera()) {
                    cout << "Carrera registrada con exito" <<endl;
                } else {
                    cout << "Error al registrar" <<endl;
                }
                system("pause");
                break;
            case 12:///------------------------------------------------INFORMAR CARRERA SEGUN CODIGO
                MostrarCarrera();
                break;
            case 13:///------------------------------------------------LISTA TODAS LAS CARRERAS
                Listado_Carrera();
                break;
            case 14:///------------------------------------------------ELIMINAR CARRERA
                if (Eliminarcarrera()) {
                    cout << "Carrera eliminada con exito" << endl;
                } else {
                    cout << "Carrera no existe o ya fue eliminada anteriormente" <<endl;
                }
                system("pause");
                break;
            case 15:///------------------------------------------------SALIR
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}



/**-----MENU ASIGNATURAS-----*/

void Masignaturas::AbrirMenuAsignatura() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   MENÚ ASIGNATURAS "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "AGREGAR ASIGNATURA" <<  endl;
        gotoxy(c.getx(),12);
        cout << "LISTAR ASIGNATURA" << endl;
        gotoxy(c.getx(),13);
        cout << "LISTAR TODAS LAS ASIGNATURAS" << endl;
        gotoxy(c.getx(),14);
        cout <<  "ELIMINAR ASIGNATURA"  << endl;
        gotoxy(c.getx(),15);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==16) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11: ///-----------------------------------------------AGREGAR ASIGNATURA
                if (AgregarAsignatura()) {
                    cout << "Asignatura registrada con exito" << endl;
                } else {
                    cout << "Error al registrar" << endl;
                }
                system("pause");
                break;
            case 12:///------------------------------------------------INFORMAR ASIGNATURA
                MostrarAsignatura();
                break;
            case 13:///----------------------------------------------LISTAR TODAS LAS ASIGNATURAS
                Listado_Asignatura();
                break;
            case 14:///------------------------------------------------ELIMINAR ASIGNATURA
                if (EliminarAsignatura()) {
                    cout << "Asignatura eliminada con exito" << endl;
                } else {
                    cout << "Error al eliminar" << endl;
                }
                system("pause");
                break;
            case 15:///------------------------------------------------SALIR
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}



/**-----MENU CATEDRAS-----*/

void MCatedras::AbrirMenuCatedra() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   MENÚ CATEDRAS "<< endl;
        gotoxy(c.getx(),10);
        cout << "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "AGREGAR CATEDRA" <<  endl;
        gotoxy(c.getx(),12);
        cout << "LISTAR CATEDRA" << endl;
        gotoxy(c.getx(),13);
        cout << "LISTAR TODAS LAS CATEDRAS" << endl;
        gotoxy(c.getx(),14);
        cout << "ELIMINAR CATEDRA"  << endl;
        gotoxy(c.getx(),15);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==16) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11: ///-----------------------------------------------AGREGAR CATEDRA
                if (AgregarCatedra()) {
                    cout << "Catedra registrada con exito" << endl;
                } else {
                    cout << "Error al registrar" << endl;
                }
                system("pause");
                break;
            case 12:///------------------------------------------------INFORMAR CATEDRA
                MostrarCatedra();
                break;
            case 13:///------------------------------------------------LISTAR TODAS LAS CATEDRAS
                Listado_Catedra();
                break;
            case 14:///------------------------------------------------ELIMINAR CATEDRA
                if (EliminarCatedra()) {
                    cout << "Catedra eliminada con exito" << endl;
                } else {
                    cout << "Error al eliminar" << endl;
                }
                system("pause");
                break;
            case 15:///------------------------------------------------SALIR
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}

/**-----MENU INFORME-----*/

void MInforme::AbrirMenuInforme() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   MENÚ INFORME "<< endl;
        gotoxy(c.getx(),10);
        cout << "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "ESTADO ACADEMICO DE ALUMNO" <<  endl;
        gotoxy(c.getx(),12);
        cout << "EXAMENES FINALES DE ALUMNO" << endl;
        gotoxy(c.getx(),13);
        cout << "NOTAS DE PARCIALES DE ALUMNO" << endl;
        gotoxy(c.getx(),14);
        cout << "PLAN DE ESTUDIOS DE CARRERA"  << endl;
        gotoxy(c.getx(),15);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==16) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11: ///-----------------------------------------------ESTADO ACADEMICO
                Estado_academico();
                break;
            case 12:///------------------------------------------------EXAMENES FINALES
                Examenes_finales();
                break;
            case 13:///------------------------------------------------NOTAS PARCIALES
                Notas_parciales();
                break;
            case 14:///------------------------------------------------PLAN DE ESTUDIOS
                Plan_de_estudios();
                break;
            case 15:///------------------------------------------------SALIR
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}

/**-----MENU CONFIGURACION-----*/

void MConfig::AbrirMenuConfig() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   MENÚ CONFIGURACIÓN "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "REALIZAR COPIA DE SEGURIDAD" <<  endl;
        gotoxy(c.getx(),12);
        cout << "RESTAURAR" << endl;
        gotoxy(c.getx(),13);
        cout <<  "PANTALLA COMPLETA: ";
        if (c.getfullscreen()) {
            cout << "SI";
        } else {
            cout << "NO";
        }
        gotoxy(c.getx(),14);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==15) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11:
                Menu_Backups();
                break;
            case 12:
                Menu_Restaurar();
                break;
            case 13:
                if (c.getfullscreen()==false) {
                    c.setscreen(true);
                    c.setx(35);
                    c.setx2(33);
                    c.Modificar(0);
                    c.Fullscreen();
                } else {
                    c.setscreen(false);
                    c.Fullscreen();
                    c.setx(60);
                    c.setx2(58);
                    c.Modificar(0);
                }
                break;
            case 14:///------------------------------------------------SALIR
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}

void MConfig::Menu_Backups() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   BACKUP "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "ALUMNOS" <<  endl;
        gotoxy(c.getx(),12);
        cout << "DOCENTES" << endl;
        gotoxy(c.getx(),13);
        cout << "CARRERAS" << endl;
        gotoxy(c.getx(),14);
        cout << "ASIGNATURAS" << endl;
        gotoxy(c.getx(),15);
        cout << "CATEDRAS" << endl;
        gotoxy(c.getx(),16);
        cout << "ALUMNOS EN CATEDRA" << endl;
        gotoxy(c.getx(),17);
        cout << "CALIFICACIONES" << endl;
        gotoxy(c.getx(),18);
        cout <<  "*BACKUP AUTOMATICO: ";
        if (c.getguardadoautomatico()) {
            cout << "SI";
        } else {
            cout << "NO";
        }
        gotoxy(c.getx(),19);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx()-1,24);
        cout << "*Cada vez que se agregue un nuevo registro o se elimine, se realizara";
        gotoxy(c.getx(),25);
        cout << " automaticamente una copia del archivo con los registros anteriores";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==20) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11:
                if (backup_alumno()) {
                    cout << "Copia de seguridad realizada con exito" << endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 12:
                if (backup_docente()) {
                    cout << "Copia de seguridad realizada con exito"<< endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 13:
                if (backup_carrera()) {
                    cout << "Copia de seguridad realizada con exito"<< endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 14:
                if (backup_asignatura()) {
                    cout << "Copia de seguridad realizada con exito"<< endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 15:
                if (backup_catedra()) {
                    cout << "Copia de seguridad realizada con exito"<< endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 16:
                if (backup_catedra_alumno()) {
                    cout << "Copia de seguridad realizada con exito"<< endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 17:
                if (backup_calificacion()) {
                    cout << "Copia de seguridad realizada con exito"<< endl;
                    system("pause");
                } else {
                    cout << "Error al realizar la copia de seguridad"<< endl;
                    system("Pause");
                }
                break;
            case 18:
                if (c.getguardadoautomatico()==false) {
                    c.setguardado(true);
                    c.Modificar(0);
                } else {
                    c.setguardado(false);
                    c.Modificar(0);
                }
                break;
            case 19:///------------------------------------------------SALIR
                y=11;
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}

void MConfig::Menu_Restaurar() {
    Conf c;
    c.LeerDeDisco(0);
    system("cls");
    rlutil::hidecursor();
    y= 11;
    while (true) {
        gotoxy(35,8);
        gotoxy(c.getx(),9);
        cout << "   RESTAURAR "<< endl;
        gotoxy(c.getx(),10);
        cout <<  "                                        " <<  endl;
        gotoxy(c.getx(),11);
        cout << "ALUMNOS" <<  endl;
        gotoxy(c.getx(),12);
        cout << "DOCENTES" << endl;
        gotoxy(c.getx(),13);
        cout << "CARRERAS" << endl;
        gotoxy(c.getx(),14);
        cout << "ASIGNATURAS" << endl;
        gotoxy(c.getx(),15);
        cout << "CATEDRAS" << endl;
        gotoxy(c.getx(),16);
        cout << "ALUMNOS EN CATEDRA" << endl;
        gotoxy(c.getx(),17);
        cout << "CALIFICACIONES" << endl;
        gotoxy(c.getx(),18);
        cout << "SALIR" << endl;
        gotoxy(c.getx(),22);
        cout << "Use las flechas direccionales para moverse en el programa" << endl;
        gotoxy(c.getx(),23);
        cout << "Use la tecla enter para selecionar";
        gotoxy(c.getx2(),y-1);
        cout <<" ";
        gotoxy(c.getx2(),y);
        cout <<">";
        gotoxy(c.getx2(),y+1);
        cout <<" ";
        tecla = getch();
        switch(tecla) {
        case 72:
            y--;
            if (y==10) {
                y++;
            }
            break;
        case 80:
            y++;
            if (y==19) {
                y--;
            }
            break;
        case 13:
            system("cls");
            switch( y ) {
            case 11:
                if (restaurar_alumno()) {
                    cout << "Los datos fueron restaurados exitosamente" << endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 12:
                if (restaurar_docente()) {
                    cout << "Los datos fueron restaurados exitosamente"<< endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 13:
                if (restaurar_carrera()) {
                    cout << "Los datos fueron restaurados exitosamente"<< endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 14:
                if (restaurar_asignatura()) {
                    cout << "Los datos fueron restaurados exitosamente"<< endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 15:
                if (restaurar_catedra()) {
                    cout << "Los datos fueron restaurados exitosamente"<< endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 16:
                if (restaurar_catedra_alumno()) {
                    cout << "Los datos fueron restaurados exitosamente"<< endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 17:
                if (restaurar_calificacion()) {
                    cout << "Los datos fueron restaurados exitosamente"<< endl;
                    system("pause");
                } else {
                    cout << "Error al restaurar los datos"<< endl;
                    system("Pause");
                }
                break;
            case 18:///------------------------------------------------SALIR
                y=11;
                return;
                break;
            }
            rlutil::hidecursor();
            system("cls");
            break;
        }
    }
}
