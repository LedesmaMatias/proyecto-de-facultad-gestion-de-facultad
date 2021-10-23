#include "Menu.h"
#include "rlutil.h"
#include <funcionesdeclases.h>
#include <Catedra_alumnos.h>
using namespace std;

///METODOS MENU PRINCIPAL

void MPrincipal::Menu_Alumnos(){ //ACCEDER A MENU ALUMNOS
   malum.AbrirMenuAlumno();
}

void MPrincipal::Menu_Docentes(){ //ACCEDER A MENU DOCENTES
    mdoc.AbrirMenuDocente();
}

void MPrincipal::Menu_Facultad(){ //ACCEDER A MENU FACULTAD
    mfac.AbrirMenuFacultad();
}

void MPrincipal::Menu_Informe(){
    minf.AbrirMenuInforme();
}

void MPrincipal::Menu_config(){ //ACCEDER A MENU CONFIGURACION
    mconf.AbrirMenuConfig();
}

///METODOS MENU ALUMNO

bool MAlumnos::RegistrarAlumno(){ //AGREGAR ALUMNO
    Conf c;
    c.LeerDeDisco(0);
    Alumno alm;
    int leg;
    leg = contar_cantidad_registro_alumnos();
    rlutil::showcursor();
    if (Existe_alguna_carrera()){
    alm.CargarAlumno(leg+1);
    system("cls");
    if (c.getguardadoautomatico()) backup_alumno();
    if (alm.GrabarAlumno()==true){
        return true;
    }
    return false;
    } else {
        cout << "No se pueden agregar alumnos si no hay alguna carrera en el registro";
        return false;
    }
}

void MAlumnos::MostrarAlumno(){ //LISTAR ALUMNO
    int leg;
    rlutil::showcursor();
    gotoxy(45,12);
    cout << "Ingrese numero de legajo: ";
    cin >> leg;
    rlutil::hidecursor();
    system("cls");
    bool mostro = Mostrar_Alumno_segun_legajo(leg);
    if (mostro==false){
        cout << "El alumno no se encuentra en los archivos" << endl;
        system("pause");
    }
}

bool MAlumnos::EliminarAlumno(){ //ELIMINAR ALUMNO
    int leg;
    rlutil::showcursor();
    gotoxy(45,12);
    cout << "Ingrese numero de legajo para eliminar: ";
    cin >> leg;
    rlutil::hidecursor();
    system("cls");
    bool elimino = Baja_Alumno(leg);
    return elimino;
}

bool MAlumnos::AgregarCatedra(){ //AGREGAR CATEDRA
    Catedra_alumnos cata;
    Conf c;
    c.LeerDeDisco(0);
    if (Existe_algun_alumno() && Existe_alguna_catedra()){
    rlutil::showcursor();
    cata.Cargar();
    system("cls");
    if (c.getguardadoautomatico()) backup_catedra_alumno();
    if (cata.GrabarEnDisco()==true){
        return true;
    }
    return false;
    } else {
        cout << "No se ouede agregar alumno a catedra si no hay agun alumno y/o catedra en el registro";
        return false;
    }
}

bool MAlumnos::AgregarCalificacion(){ //AGREGAR CALIFICACION
    Conf c;
    c.LeerDeDisco(0);
    Calificacion cal;
    if (Existe_algun_alumno() && Existe_alguna_catedra()){
    rlutil::showcursor();
    cal.CargarCalificacion();
    system("cls");
    if (c.getguardadoautomatico()) backup_calificacion();
    if (cal.GrabarEnDisco()==true){
        return true;
    }
    return false;
    } else {
        cout << "No se pueden agregar calificaciones si no hay algun alumno y/o catedra en el registro";
        return false;
    }

}

bool MAlumnos::EliminarDeCatedra(){
    int leg,cod;
    rlutil::showcursor();
    gotoxy(42,12);
    cout << "Ingrese numero de legajo del alumno: ";
    gotoxy(42,13);
    cout << "Ingrese el codigo de al catedra: ";
    gotoxy(79,12);
    cin >> leg;
    gotoxy(79,13);
    cin >> cod;
    system("cls");
    rlutil::hidecursor();
    bool elimino= Baja_de_catedra(leg,cod);
    return elimino;
}

bool MAlumnos::EliminarCalificacion(){
    int leg,cod,tipo,tiporec=-1;
    rlutil::showcursor();
    gotoxy(42,12);
    cout << "Ingrese numero de legajo del alumno: ";
    gotoxy(42,13);
    cout << "Ingrese el codigo de la catedra: ";
    gotoxy(42,14);
    cout << "Ingrese el *tipo de nota a eliminar: ";
    gotoxy(42,20);
    cout << "* 1=1erparcial 2=2do parcial 3=3er parcial 4=final";
    gotoxy(42,21);
    cout << " 5=recuperatorio [Se aclara que recuperatorio de parcial se va a eliminar]";
    gotoxy(42,22);
     cout << " 6=trabajo practico";
    gotoxy(79,12);
    cin >> leg;
    gotoxy(79,13);
    cin >> cod;
    gotoxy(79,14);
    cin >> tipo;
    if (tipo==5){
        gotoxy(42,15);
        cout << "Parcial: ";
        gotoxy(79,15);
        cin >> tiporec;
    }
    system("cls");
    bool elimino=Baja_Calificacion(leg,cod,tipo,tiporec);
    rlutil::hidecursor();
    return elimino;
}
///METODOS MENU DOCENTES

bool MDocentes::AgregarDocente(){ //AGREGAR DOCENTE
    Docente doc;
    Conf c;
    c.LeerDeDisco(0);
    int leg;
    leg = contar_cantidad_registro_docentes();
    rlutil::showcursor();
    doc.CargarDocente(leg+1);
    system("cls");
    if (c.getguardadoautomatico()) backup_docente();
    if (doc.GrabarDocente()==true){
        return true;
    }
     return false;
}

bool MDocentes::EliminarDocente(){ //ELIMINAR DOCENTE
    int leg;
    rlutil::showcursor();
    gotoxy(45,12);
    cout << "Ingrese numero de legajo para eliminar: ";
    cin >> leg;
    rlutil::hidecursor();
    system("cls");
    bool elimino = Baja_Docente(leg);
    return elimino;
}

void MDocentes::MostrarDocente(){ //MOSTRAR DOCENTE
    int leg;
    rlutil::showcursor();
    gotoxy(45,12);
    cout << "Ingrese el numero de legajo: ";
    cin >> leg;
    rlutil::hidecursor();
    system("cls");
    bool mostro= Mostrar_Docente_Segun_Legajo(leg);
    if (mostro==false){
        cout << "El Docente no se encuentra en los archivos" << endl;
        system("pause");
    }
}

///METODOS DE FACULTAD

void MFacultad::Menu_Carreras(){ //ACCEDER A MENU CARRERAS
    mcar.AbrirMenuCarrera();
}

void MFacultad::Menu_Materias(){ //ACCEDER A MENU MATERIAS
    masg.AbrirMenuAsignatura();
}

void MFacultad::Menu_Catedras(){ //ACCEDER A MENU CATEDRAS
    mcat.AbrirMenuCatedra();
}

///METODOS MENU CARRERA

bool MCarreras::AgregarCarrera(){ //NUEVA CARRERA
    Conf c;
    c.LeerDeDisco(0);
    Carrera crr;
    rlutil::showcursor();
    crr.CargarCarrera();
    system("cls");
    rlutil::hidecursor();
    if (c.getguardadoautomatico()) backup_carrera();
    return crr.GrabarCarrera();
}

void MCarreras::MostrarCarrera(){ //LISTAR CARRERA
    rlutil::showcursor();
    char cod[10];
    gotoxy(40,12); cout << "Ingrese el codigo de la carrera: ";
    cin >> cod;
    system("cls");
    rlutil::hidecursor();
    if (Informar_Carrera_porcodigo(cod)){
        return;
    }
    cout << "La carrera no existe en el registro" << endl;
    system("pause");
}

bool MCarreras::Eliminarcarrera(){ //ELIMINAR CARRERA
    rlutil::showcursor();
    char cod[10];
    gotoxy(40,12); cout << "Ingrese el codigo de la carrera a eliminar: ";
    cin >> cod;
    bool elimino = Baja_Carrera(cod);
    system("cls");
    return elimino;
}

///METODOS MENU ASIGNATURAS

bool Masignaturas::AgregarAsignatura(){ //NUEVA ASIGNATURA
    Asignatura asg;
    Conf c;
    c.LeerDeDisco(0);
    rlutil::showcursor();
    if (Existe_alguna_carrera()){
    asg.Cargar_asignatura(conseguir_ultimo_ID_asignatura());
    system("cls");
    rlutil::showcursor();
    if (c.getguardadoautomatico()) backup_asignatura();
    return asg.Grabar_asignatura();
    } else {
        rlutil::hidecursor();
        cout << "No se pueden agregar asignaturas si no hay ninguna carrera en el registro";
        return false;
    }
}

void Masignaturas::MostrarAsignatura(){ //LISTAR ASIGNATURA
    rlutil::showcursor();
    int cod;
    gotoxy(40,12); cout << "Ingrese el codigo de la asignatura: ";
    cin >> cod;
    system("cls");
    rlutil::hidecursor();
    if (Informar_asignatura_codigo(cod)){
        return;
    }
    cout << "La asignatura no existe en el registro" << endl;
    system("pause");
}

bool Masignaturas::EliminarAsignatura(){ //ELIMINAR ASIGNATURA
    rlutil::showcursor();
    int cod;
    gotoxy(40,12); cout << "Ingrese el codigo de la asignatura para eliminar: ";
    cin >> cod;
    system("cls");
    bool elimino= Baja_Asignatura(cod);
    system("cls");
    return elimino;
}

///METODOS MENU CATEDRAS

bool MCatedras::AgregarCatedra(){ //NUEVA CATEDRA
    Catedra cat;
    Conf c;
    c.LeerDeDisco(0);
    if (Existe_alguna_asignatura() && Existe_algun_docente()){
    rlutil::showcursor();
    cat.CargarCatedra(conseguir_ultimo_ID_catedra());
    system("cls");
    rlutil::showcursor();
    if (c.getguardadoautomatico()) backup_catedra();
    return cat.GrabarCatedra();
    } else {
        cout << "No se pueden agregar catedras si no hay ninguna asignatura y/o docente en el registro";
        return false;
    }
}

void MCatedras::MostrarCatedra(){ //LISTAR CATEDRA
    rlutil::showcursor();
    int cod;
    gotoxy(40,12); cout << "Ingrese el codigo de la catedra: ";
    cin >> cod;
    system("cls");
    rlutil::hidecursor();
    if (Informar_catedra_codigo(cod)){
        return;
    }
    cout << "La catedra no existe en el registro" << endl;
    system("pause");
}

bool MCatedras::EliminarCatedra(){ //ELIMINAR CATEDRA
    rlutil::showcursor();
    int cod;
    gotoxy(40,12); cout << "Ingrese el codigo de la catedra para eliminar: ";
    cin >> cod;
    bool elimino= Baja_Catedra(cod);
    system("cls");
    return elimino;
}

