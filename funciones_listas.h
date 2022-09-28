#ifndef FUNCIONES_LISTAS_H_INCLUDED
#define FUNCIONES_LISTAS_H_INCLUDED

#include "estructuras.h"
//DEFINICION DE LAS FUNCIONES
/**
* \file funciones_listas.h
* \brief Cabecera de funciones para la gestion de la lista
*/

/**< FUNCIONES PACIENTE */

struct nodo_paciente* l_paciente_crear_p(void);
struct nodo_paciente* l_paciente_insertar_p(struct nodo_paciente *l,struct nodo_paciente *pindice,struct paciente *elemento);
struct nodo_paciente* l_paciente_insertar_primera_posicion(struct nodo_paciente *l,struct paciente *elemento);
struct nodo_paciente* l_paciente_primero(struct nodo_paciente *l);
struct nodo_paciente* l_paciente_ultimo(struct nodo_paciente *l);
struct nodo_paciente* l_paciente_siguiente(struct nodo_paciente *l,struct nodo_paciente *pindice);
struct nodo_paciente* l_paciente_anterior(struct nodo_paciente *l,struct nodo_paciente *pindice);
int l_numero_pacientes(struct nodo_paciente *l);
struct nodo_paciente* l_paciente_localizar(struct nodo_paciente* l,const char *elemento);
struct paciente *l_paciente_elemento(struct nodo_paciente *l, struct nodo_paciente *pindice);
struct nodo_paciente* l_paciente_borrar(struct nodo_paciente *l, struct nodo_paciente *pindice);
void l_paciente_destruir(struct nodo_paciente *l);
void l_paciente_listar(struct nodo_paciente *l);
int l_paciente_vacia(struct nodo_paciente *l);
void mostrar_paciente(struct paciente *p);
int l_conteo_inoculaciones(struct nodo_paciente_vacuna *l,const char *dni);
int l_comprobar_grupo(struct nodo_grupo_poblacional *l,const char *identificador);
struct nodo_paciente* l_comprobar_paciente(struct nodo_paciente* l,const char *elemento);
/**< FUNCIONES VACUNA */

struct nodo_vacuna* l_vacuna_crear_p(void);
struct nodo_vacuna* l_vacuna_insertar_p(struct nodo_vacuna *l,struct nodo_vacuna *pindice,struct vacuna *elemento);
struct nodo_vacuna* l_vacuna_insertar_primera_posicion(struct nodo_vacuna *l,struct vacuna *elemento );
struct nodo_vacuna* l_vacuna_primero(struct nodo_vacuna *l);
struct nodo_vacuna* l_vacuna_ultimo(struct nodo_vacuna *l);
struct nodo_vacuna* l_vacuna_siguiente(struct nodo_vacuna *l,struct nodo_vacuna *pindice);
struct nodo_vacuna* l_vacuna_anterior(struct nodo_vacuna *l,struct nodo_vacuna *pindice);
int l_numero_vacuna(struct nodo_vacuna *l);
struct nodo_vacuna* l_vacuna_localizar(struct nodo_vacuna* l,const char *elemento);
struct vacuna *l_vacuna_elemento(struct nodo_vacuna *l, struct nodo_vacuna *pindice);
struct nodo_vacuna* l_vacuna_borrar(struct nodo_vacuna *l, struct nodo_vacuna *pindice);
void l_vacuna_destruir(struct nodo_vacuna *l);
void l_vacuna_listar(struct nodo_vacuna *l);
int l_vacuna_vacia(struct nodo_vacuna *l);
void mostrar_vacuna(struct vacuna *v);
struct nodo_vacuna* l_comprobar_vacuna(struct nodo_vacuna *l,const char *elemento);

/**< FUNCIONES GRUPO_POBLACIONAL */

struct nodo_grupo_poblacional* l_grupo_poblacional_crear_p(void);
struct nodo_grupo_poblacional* l_grupo_poblacional_insertar_p(struct nodo_grupo_poblacional *l,struct nodo_grupo_poblacional *pindice,struct grupo_poblacional *elemento);
struct nodo_grupo_poblacional* l_grupo_poblacional_insertar_primera_posicion(struct nodo_grupo_poblacional *l,struct grupo_poblacional *elemento);
struct nodo_grupo_poblacional* l_grupo_poblacional_primero(struct nodo_grupo_poblacional *l);
struct nodo_grupo_poblacional* l_grupo_poblacional_ultimo(struct nodo_grupo_poblacional *l);
struct nodo_grupo_poblacional* l_grupo_poblacional_siguiente(struct nodo_grupo_poblacional *l,struct nodo_grupo_poblacional *pindice);
struct nodo_grupo_poblacional* l_grupo_poblacional_anterior(struct nodo_grupo_poblacional *l,struct nodo_grupo_poblacional *pindice);
int l_numero_grupo_poblacional(struct nodo_grupo_poblacional *l);
struct nodo_grupo_poblacional* l_grupo_poblacional_localizar(struct nodo_grupo_poblacional* l,const char *elemento);
struct grupo_poblacional *l_grupo_poblacional_elemento(struct nodo_grupo_poblacional *l, struct nodo_grupo_poblacional *pindice);
struct nodo_grupo_poblacional* l_grupo_poblacional_borrar(struct nodo_grupo_poblacional *l, struct nodo_grupo_poblacional *pindice);
void l_grupo_poblacional_destruir(struct nodo_grupo_poblacional *l);
void l_grupo_poblacional_listar(struct nodo_grupo_poblacional *l);
int l_grupo_poblacional_vacia(struct nodo_grupo_poblacional *l);
void mostrar_grupo_poblacional(struct grupo_poblacional *g);

/**< FUNCIONES PACIENTE_VACUNA */

struct nodo_paciente_vacuna* l_paciente_vacuna_crear_p(void);
struct nodo_paciente_vacuna* l_paciente_vacuna_insertar_p(struct nodo_paciente_vacuna *l,struct nodo_paciente_vacuna *pindice,struct paciente_vacuna *elemento);
struct nodo_paciente_vacuna* l_paciente_vacuna_insertar_primera_posicion(struct nodo_paciente_vacuna *l,struct paciente_vacuna *elemento);
struct nodo_paciente_vacuna* l_paciente_vacuna_primero(struct nodo_paciente_vacuna *l);
struct nodo_paciente_vacuna* l_paciente_vacuna_ultimo(struct nodo_paciente_vacuna *l);
struct nodo_paciente_vacuna* l_paciente_vacuna_siguiente(struct nodo_paciente_vacuna *l,struct nodo_paciente_vacuna *pindice);
struct nodo_paciente_vacuna* l_paciente_vacuna_anterior(struct nodo_paciente_vacuna *l,struct nodo_paciente_vacuna *pindice);
int l_numero_paciente_vacuna(struct nodo_paciente_vacuna *l);
struct nodo_paciente_vacuna* l_paciente_vacuna_localizar_dni(struct nodo_paciente_vacuna* l,const char *elemento);
struct nodo_paciente_vacuna* l_paciente_vacuna_localizar_identificador(struct nodo_paciente_vacuna* l,const char *elemento);
struct paciente_vacuna *l_paciente_vacuna_elemento(struct nodo_paciente_vacuna *l, struct nodo_paciente_vacuna *pindice);
struct nodo_paciente_vacuna* l_paciente_vacuna_borrar(struct nodo_paciente_vacuna *l, struct nodo_paciente_vacuna *pindice);
void l_paciente_vacuna_destruir(struct nodo_paciente_vacuna *l);
void l_paciente_vacuna_listar(struct nodo_paciente_vacuna *l);
int l_paciente_vacuna_vacia(struct nodo_paciente_vacuna *l);
void mostrar_paciente_vacuna(struct paciente_vacuna *pv);

#endif // FUNCIONES_LISTAS_H_INCLUDED
