#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file lista_grupo_poblacional.c
* \brief Implementacion de todas las funciones de listas relacionadas con la tabla GRUPO_POBLACIONAL
*/


/** \brief Crear el nodo
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_crear_p(void)
{
    return(NULL);
};
/** \brief Insertar en la lista
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_insertar_p(struct nodo_grupo_poblacional *l,struct nodo_grupo_poblacional *pindice,struct grupo_poblacional *elemento)
{
    struct nodo_grupo_poblacional *paux;

    paux = (struct nodo_grupo_poblacional *) malloc(sizeof (struct nodo_grupo_poblacional));

    if (paux != NULL) {
       paux->g = elemento;

       if (l == NULL) {

         paux->psig = NULL;
          l = paux;


       }
       else {


        paux->psig = pindice->psig;
        pindice->psig = paux;

    }
   }

    return(l);
};
/** \brief Insertar en la primera posicion
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_insertar_primera_posicion(struct nodo_grupo_poblacional *l,struct grupo_poblacional *elemento)
{
        struct nodo_grupo_poblacional *paux;

    paux = (struct nodo_grupo_poblacional *) malloc(sizeof (struct nodo_grupo_poblacional));

    if (paux != NULL) {
       paux->g = elemento;

       if (l == NULL) {
		 l = paux;
         l->psig = NULL;


       }
       else {

        paux->psig = l;
        l = paux;
    }
   }
    return (paux);
};
/** \brief Primera posicion
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_primero(struct nodo_grupo_poblacional *l)
{
    return(l);
};
/** \brief Ultima posicion
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_ultimo(struct nodo_grupo_poblacional *l)
{
    struct nodo_grupo_poblacional *paux; // ultimo elemento lista = NULL
    paux=l;
    while ((paux != NULL) && (paux->psig != NULL))
        paux = paux->psig;
    return (paux);
};

/** \brief Siguiente posicion en la lista
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_siguiente(struct nodo_grupo_poblacional *l,struct nodo_grupo_poblacional *pindice)
{
    return(pindice->psig);
};

/** \brief Posicion anterior
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_anterior(struct nodo_grupo_poblacional *l,struct nodo_grupo_poblacional *pindice)
{
    struct nodo_grupo_poblacional *paux;
    if ((pindice == l) || (l == NULL)) return(NULL);
    else {
      paux = l;
      while (paux->psig != pindice)
        paux=paux->psig;
      return (paux);
   }
};

/** \brief Conteo
 */
int l_numero_grupo_poblacional(struct nodo_grupo_poblacional *l)
{
    int contador;
    struct nodo_grupo_poblacional *paux;
    paux = l;
    contador = 1;
    if (paux->psig == NULL) system("PAUSE");
    while (paux->psig != NULL) {

        contador++;
        paux = paux->psig;
    }
    return (contador);
};

/** \brief Localizacion de la posicion en la lista
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_localizar(struct nodo_grupo_poblacional* l,const char *elemento)
{
    struct nodo_grupo_poblacional* paux;
    int c;
    paux = l;
    while((paux!=NULL)&&(strcmp(elemento,paux->g->identificador)!=0))
    {
        paux=paux->psig;
    }
    if(paux==NULL) return NULL;
    return (paux);
};
/** \brief Elemento en la lista
 */
struct grupo_poblacional *l_grupo_poblacional_elemento(struct nodo_grupo_poblacional *l, struct nodo_grupo_poblacional *pindice)
{
    return (pindice->g);
};
/** \brief Borrado
 */
struct nodo_grupo_poblacional* l_grupo_poblacional_borrar(struct nodo_grupo_poblacional *l, struct nodo_grupo_poblacional *pindice)
{
  struct nodo_grupo_poblacional *paux;
  if (l == pindice) {
     l=pindice->psig;
     free(pindice->g->descripcion);
     free(pindice->g->identificador);
     free(pindice->g);
     free(pindice);

  }
  else {
  paux = l_grupo_poblacional_anterior(l,pindice);
  paux->psig=pindice->psig;
    free(pindice->g->descripcion);
     free(pindice->g->identificador);
     free(pindice->g);
     free(pindice);
 }
};
/** \brief Borrado de toda la lista
 */
void l_grupo_poblacional_destruir(struct nodo_grupo_poblacional *l)
{
    struct nodo_grupo_poblacional *pborra;
    struct nodo_grupo_poblacional *paux;
    paux=l;
    do {
        pborra = paux;
        paux =paux->psig;
        free(pborra->g->descripcion);
     free(pborra->g->identificador);
     free(pborra->g);
     free(pborra);
    } while (paux != NULL);
};
/** \brief Mostrar elemento
 */
void mostrar_grupo_poblacional(struct grupo_poblacional *g)
{
        printf("\n*********\n");
        printf("IDENTIFICADOR: ");puts(g->identificador);
        printf("DESCRIPCION: ");puts(g->descripcion);
        printf("\n*********\n");
};
/** \brief Listado de la lista
 */
void l_grupo_poblacional_listar(struct nodo_grupo_poblacional *l)
{
    struct nodo_grupo_poblacional *paux;
    paux=l;
    while(paux != NULL)
    {

        mostrar_grupo_poblacional(l_grupo_poblacional_elemento(l,paux));
        paux = paux->psig;
    }
};
/** \brief Comprobar si esta vacio el puntero
 */
int l_grupo_poblacional_vacia(struct nodo_grupo_poblacional *l)
{
    if(l==NULL) return l;
    return 0;
};
