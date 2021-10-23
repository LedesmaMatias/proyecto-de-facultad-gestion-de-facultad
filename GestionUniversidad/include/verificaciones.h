#ifndef VERIFICACIONES_H_INCLUDED
#define VERIFICACIONES_H_INCLUDED
#include <Catedra.h>
#include <Persona.h>

bool Verificar_vacio(const char* );

///----------------------------------------------
///PERSONA
///----------------------------------------------

bool Verificar_persona_fecha(int ,int ,int );

bool Verificar_persona_dni(int );

bool Verificar_persona_genero(char );

///----------------------------------------------
///ALUMNO
///----------------------------------------------

Alumno Buscar_alumno(int );

bool Verificar_alumno_existe(int );

bool Existe_algun_alumno( );

void Eliminar_relacionado_alumno(int );

///----------------------------------------------
///DOCENTE
///----------------------------------------------

bool Existe_algun_docente();

void Eliminar_relacionado_docente(int );

bool Verificar_docente_existe(int );

///----------------------------------------------
///CARRERA
///----------------------------------------------

Carrera Buscar_carrera(const char* );

bool Existe_alguna_carrera();

bool Verificar_carrera_existe(const char* );

bool Verificar_carrera_tipo(int );

bool Verificar_carrera_min(int );

void Eliminar_relacionado_carrera(const char* );

bool Verificar_carrera_cuatrimestre(int , const char* );

///----------------------------------------------
///ASIGNATURA
///----------------------------------------------

bool Existe_alguna_asignatura();

void Eliminar_relacionado_asignatura(int );

bool Verificar_asignatura_existe(int );

///----------------------------------------------
///CATEDRA
///----------------------------------------------

void Eliminar_relacionado_catedra(int );

bool Verificar_modalidad_catedra(int );

bool Verificar_parciales_catedra(int );

bool Verificar_anio_catedra(int );

bool Verificar_cuatrimestre_catedra(int );

bool Verificar_catedra_existe(int );

bool Verificar_cant_parciales_catedra(int ,int );

bool Existe_alguna_catedra();

///----------------------------------------------
///CATEDRA ALUMNO
///----------------------------------------------

bool Verificar_alumno_catedra(int, int);

bool Verificar_en_catedra_y_asignatura(int , int );

bool Verificar_en_carrera(int ,int );
///----------------------------------------------
///CALIFICACION
///----------------------------------------------

bool Verificar_nota_calificacion(float );

bool Verificar_tipo_calificacion(int );

bool Verificar_recuperatorio(int );

bool Verificar_nota_existe(int , int, int, int);

///----------------------------------------------
///LISTADO
///----------------------------------------------

bool verificar_tecla_1(char );

bool verificar_tecla_2(char );

bool verificar_tecla_3(char );



#endif // VERIFICACIONES_H_INCLUDED
