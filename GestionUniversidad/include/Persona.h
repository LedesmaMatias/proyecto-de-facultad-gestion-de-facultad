#ifndef PERSONA_H
#define PERSONA_H
#include <Clases.h>
#include <string.h>
#include <fecha.h>

class Persona
{
protected:
char nombre[30];
char apellido[30];
char domicilio[50];
char localidad[50];
int dni;
Fecha nacimiento;
char nacionalidad[30];
int codpostal;
int telefono;
char email[50];
char genero; // M= Masculino F= Femenino O= Otro
bool estado;
public:
    Persona();
    void cargarpersona();
    void mostrarpersona();
    /**gets */
    const char* getnombre(){return nombre;}
    const char* getapellido(){return apellido;}
    const char* getdomicilio(){return domicilio;}
    int getdni(){return dni;}
    Fecha getfecha(){return nacimiento;}
    //const char* getcodciudad(){return codciudad;}
    int gettelefono(){return telefono;}
    const char* getemail(){return email;}
    const char getgenero(){return genero;}
    bool getestado () {return estado;}
    /**sets*/
    void setnombre (const char *n){strcpy(nombre,n);}
    void setapellido (const char *a){strcpy(apellido,a);}
    void setdomicilio (const char *d){strcpy(domicilio,d);}
    void setdni (int d) {dni = d;}
    //void setcodciudad(const char* cod){strcpy(codciudad,cod);}
    void settelefono (int tel){telefono = tel;}
    void setemail (const char* em){strcpy(email,em);}
    void setgenero (const char g){ genero = g;}
    void setestado (bool est) {estado = est;}

};

class Alumno : public Persona {
private:
    int legajo;
    bool trabaja;
    char trabajo[50];
    char titulosecundario[50];
    char recibido[100];
    char codcarrera[10];
    Fecha inscripcion;
public:
    Alumno();
    bool LeerDeDisco(int );
    bool LeerDeDisco2(int );
    bool GrabarAlumno();
    void Grabarbckp();
    void CargarAlumno(int );
    void MostrarAlumno(const char* );
    void Modificar(int );
    /**gets*/
    int getlegajo(){return legajo;}
    bool gettrabaja () {return trabaja;}
    const char *gettrabajo(){return trabajo;}
    const char *gettitulo(){return titulosecundario;}
    const char *getcodcarrera(){return codcarrera;}
    Fecha getinscripcion () {return inscripcion;}
    /**sets*/
    void setlegajo (int n) {legajo = n;}
    void settrabaja (bool t) {trabaja = t;}
    void settrabajo (const char *t) {strcpy(trabajo,t);}
    void settitulo (const char *t) {strcpy(titulosecundario,t);}
};

class Docente : public Persona {
private:
    int legajo;
    char cargo[50];
    Fecha ingreso;
public:
    Docente();
    bool LeerDeDisco(int );
    bool LeerDeDisco2(int );
    bool GrabarDocente();
    void Grabarbckp();
    void CargarDocente(int );
    void MostrarDocente(int );
    void Modificar(int );
    /**gets*/
    int getlegajo(){return legajo;}
    const char *getcargo(){return cargo;}
    Fecha getingreso(){return ingreso;}
    /**sets*/
};




#endif // PERSONA_H
