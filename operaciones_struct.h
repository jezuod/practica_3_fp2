#ifndef OPERACIONES_STRUCT_H_INCLUDED
#define OPERACIONES_STRUCT_H_INCLUDED

#include "estructuras.h"

/**
* \file operaciones_struct.h
* \brief Declaracion de modificacion y listado estructuras
*/
char hora(char *f);
struct grupo_poblacional *crear_grupo(struct grupo_poblacional *g,int *conta_grupo);
struct paciente *crear_paciente (struct paciente *p,int *conta_pacientes);
struct vacuna *crear_vacuna(struct vacuna *v,int *conta_vacunas);
struct paciente_vacuna *crear_pacientes_vacunas(struct paciente_vacuna *pv,int *conta_pacientes_vacunas);
struct paciente *baja_paciente(struct paciente *p,int *conta_pacientes,char dni[255],int conta_pacientes_vacunas);
struct paciente_vacuna *baja_paciente_vacuna(struct paciente_vacuna *pv,int *conta_paciente_vacuna,char identificador[255]);
//void mostrar_pacientes(struct paciente *p,int contador);
//void mostrar_vacunas(struct vacuna *v,int contador);
//void mostrar_grupo(struct grupo_poblacional *g,int contador);
//void mostrar_pacientes_vacunas(struct paciente_vacuna *pv,int contador);
//int conteo_inoculaciones(struct paciente_vacuna *pv,int contador,char dni[255]);
//struct paciente_vacuna *baja_inoculaciones_paciente(struct paciente_vacuna *pv,int *conta_paciente_vacuna,char id[255]);
#endif // OPERACIONES_STRUCT_H_INCLUDED
