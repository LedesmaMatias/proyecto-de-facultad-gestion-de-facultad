#ifndef MENU_H
#define MENU_H
#include <cstdlib>
#include <cstdio>
#include <Clases.h>
#include "rlutil.h"

class Menu ///CLASE MENU
{
protected:
   int y;
   char tecla=NULL;
public:
    Menu(){
       setlocale(LC_ALL,"spanish");
SetConsoleOutputCP(1252);
SetConsoleCP(1252);
    }

};

class MAlumnos : public Menu { ///CLASE MENU DE ALUMNOS
public:
    void AbrirMenuAlumno();
    bool RegistrarAlumno();
    bool EliminarAlumno();
    void MostrarAlumno();
    bool AgregarCatedra();
    bool AgregarCalificacion();
    bool EliminarDeCatedra();
    bool EliminarCalificacion();
};

class MDocentes : public Menu { ///CLASE MENU DE DOCENTES
public:
    void AbrirMenuDocente();
    bool AgregarDocente();
    bool EliminarDocente();
    void MostrarDocente();
};

class MCatedras : public Menu{ ///CLASE MENU DE CATEDRAS
public:
    void AbrirMenuCatedra();
    bool AgregarCatedra();
    bool EliminarCatedra();
    void MostrarCatedra();
};

class MCarreras : public Menu { ///CLASE MENU DE CARRERAS
public:
    void AbrirMenuCarrera();
    bool AgregarCarrera();
    void MostrarCarrera();
    bool Eliminarcarrera();
    };

class Masignaturas : public Menu { ///CLASE MENU DE ASIGNATURAS
public:
    bool AgregarAsignatura();
    void MostrarAsignatura();
    void AbrirMenuAsignatura();
    bool EliminarAsignatura();
};

class MFacultad : public Menu { ///CLASE MENU DE FACULTAD
private:
    MCarreras mcar;
    MCatedras mcat;
    Masignaturas masg;
public:
    void AbrirMenuFacultad();
    void Menu_Catedras();
    void Menu_Carreras();
    void Menu_Materias();
};

class MConfig : public Menu { ///CLASE MENU DE CONFIGURACIÓN
public:
    void AbrirMenuConfig();
    void Menu_Backups();
    void Menu_Restaurar();
};

class MInforme : public Menu { ///CLASE MENU DE INFORMES
public:
    void AbrirMenuInforme();
};

class MPrincipal : public Menu { ///CLASE MENU PRINCIPAL
private:
    MAlumnos malum;
    MDocentes mdoc;
    MFacultad mfac;
    MConfig mconf;
    MInforme minf;
public:
    void AbrirMenuPrincipal();
    void Menu_Alumnos();
    void Menu_Docentes();
    void Menu_Facultad();
    void Menu_config();
    void Menu_Informe();
};

#endif // MENU_H
