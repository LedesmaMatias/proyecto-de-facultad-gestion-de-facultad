#ifndef FUNCIONESDECLASES_H_INCLUDED
#define FUNCIONESDECLASES_H_INCLUDED
#include "rlutil.h"
#include <Catedra_alumnos.h>
#include <verificaciones.h>
#include <Conf.h>
using namespace std;

/// FUNCIONES ALUMNO
///-------------------------------------------------------------------


bool Baja_Alumno (int );

int contar_cantidad_registro_alumnos();

bool Mostrar_Alumno_segun_legajo(int );

bool Baja_de_catedra(int ,int );

bool Baja_Calificacion(int ,int ,int ,int);

/// FUNCIONES DOCENTE
///-------------------------------------------------------------------

Docente Buscar_docente(int );

int contar_cantidad_registro_docentes();

bool Baja_Docente (int );

int Contar_catedras_docente(int );

bool Mostrar_Docente_Segun_Legajo(int );

/// FUNCIONES CARRERA
///-------------------------------------------------------------------

const char *Buscar_carrera_nombre(const char* );

int Contar_alumnos_en_carrera(const char* );

int Contar_catedras_de_carrera(const char* );

int Contar_asignaturas_de_carrera(const char* );

int Contar_horas_total(Asignatura* , int );

bool Informar_Carrera_porcodigo(const char* );

bool Baja_Carrera(const char* );


/// FUNCIONES ASIGNATURA
///-------------------------------------------------------------------


int conseguir_ultimo_ID_asignatura();

bool Informar_asignatura_codigo(int );

bool Baja_Asignatura(int );

/// FUNCIONES CATEDRA
///---------------------------------------------------------------------

int conseguir_ultimo_ID_catedra();

bool Baja_Catedra(int );

bool Informar_catedra_codigo(int );

///-------------------------------------------------------------------
///FUNCIONES CONFIGURACION

bool backup_alumno();
bool backup_docente();
bool backup_carrera();
bool backup_asignatura();
bool backup_catedra();
bool backup_catedra_alumno();
bool backup_calificacion();

bool restaurar_alumno();
bool restaurar_docente();
bool restaurar_carrera();
bool restaurar_asignatura();
bool restaurar_catedra();
bool restaurar_catedra_alumno();
bool restaurar_calificacion();
#endif // FUNCIONESDECLASES_H_INCLUDED
