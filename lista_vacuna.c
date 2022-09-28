#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file lista_vacuna.c
* \brief Implementacion de todas las funciones de listas relacionadas con la tabla VACUNA . las funciones "comunes" estan comentadas en LISTA_GRUPO_POBLACIONAL.C ,se comentara las exclusivas de la lista
*/



/**< las funciones "comunes" estan comentadas en LISTA_GRUPO_POBLACIONAL.C */
/**< se comentara las exclusivas de la lista */
struct nodo_vacuna* l_vacuna_crear_p(void)
{
    return(NULL);
};
struct nodo_vacuna* l_vacuna_insertar_p(struct nodo_vacuna *l,struct nodo_vacuna *pindice,struct vacuna *elemento)
{
    struct nodo_vacuna *paux;

    paux = (struct nodo_vacuna *) malloc(sizeof (struct nodo_vacuna));

    if (paux != NULL) {
       paux->v = elemento;

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
struct nodo_vacuna* l_vacuna_insertar_primera_posicion(struct nodo_vacuna *l,struct vacuna *elemento)
{
        struct nodo_vacuna *paux;

    paux = (struct nodo_vacuna *) malloc(sizeof (struct nodo_vacuna));

    if (paux != NULL) {
       paux->v = elemento;

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
struct nodo_vacuna* l_vacuna_primero(struct nodo_vacuna *l)
{
    return(l);
};
struct nodo_vacuna* l_vacuna_ultimo(struct nodo_vacuna *l)
{
    struct nodo_vacuna *paux; // ultimo elemento lista = NULL
    paux=l;
    while ((paux != NULL) && (paux->psig != NULL))
        paux = paux->psig;
    return (paux);
};
struct nodo_vacuna* l_vacuna_siguiente(struct nodo_vacuna *l,struct nodo_vacuna *pindice)
{
    return(pindice->psig);
};
struct nodo_vacuna* l_vacuna_anterior(struct nodo_vacuna *l,struct nodo_vacuna *pindice)
{
    struct nodo_vacuna *paux;
    if ((pindice == l) || (l == NULL)) return(NULL);
    else {
      paux = l;
      while (paux->psig != pindice)
        paux=paux->psig;
      return (paux);
   }
};
int l_numero_vacuna(struct nodo_vacuna *l)
{
    int contador;
    struct nodo_vacuna *paux;
    paux = l;
    contador = 1;
    if (paux->psig == NULL) system("PAUSE");
    while (paux->psig != NULL) {

        contador++;
        paux = paux->psig;
    }
    return (contador);
};
struct nodo_vacuna* l_vacuna_localizar(struct nodo_vacuna* l,const char *elemento)
{
    struct nodo_vacuna* paux;
    int c;
    paux = l;
    while((paux!=NULL)&&(strcmp(elemento,paux->v->num_serie)!=0))
    {
        paux=paux->psig;
    }
    if(paux==NULL) return NULL;
    return (paux);
};
struct vacuna *l_vacuna_elemento(struct nodo_vacuna *l, struct nodo_vacuna *pindice)
{
    return (pindice->v);
};
struct nodo_vacuna* l_vacuna_borrar(struct nodo_vacuna *l, struct nodo_vacuna *pindice)
{
  struct nodo_vacuna *paux;
  if (l == pindice) {
     l=pindice->psig;
     free(pindice->v->num_serie);
         free(pindice->v->empresa);
         free(pindice->v->lote);
         free(pindice->v->fecha_aprobacion);
         free(pindice->v);
        free(pindice);

  }
  else {
  paux = l_vacuna_anterior(l,pindice);
  paux->psig=pindice->psig;
        free(pindice->v->num_serie);
         free(pindice->v->empresa);
         free(pindice->v->lote);
         free(pindice->v->fecha_aprobacion);
         free(pindice->v);
        free(pindice);
 }
};
void l_vacuna_destruir(struct nodo_vacuna *l)
{
    struct nodo_vacuna *pborra;
    struct nodo_vacuna *paux;
    paux=l;
    do {
        pborra = paux;
        paux =paux->psig;
        free(pborra->v->num_serie);
         free(pborra->v->empresa);
         free(pborra->v->lote);
         free(pborra->v->fecha_aprobacion);
         free(pborra->v);
         free(pborra);
    } while (paux != NULL);
};
void mostrar_vacuna(struct vacuna *v)
{
        printf("\n*********\n");
        printf("NUM SERIE: ");puts(v->num_serie);
        printf("EMPRESA: ");puts(v->empresa);
        printf("LOTE: ");printf("%d\n",v->lote);
        printf("FECHA APROBRACION: ");puts(v->fecha_aprobacion);
        printf("\n*********\n");
};
void l_vacuna_listar(struct nodo_vacuna *l)
{
    struct nodo_vacuna *paux;
    paux=l;
    while(paux != NULL)
    {

        mostrar_vacuna(l_vacuna_elemento(l,paux));
        paux = paux->psig;
    }
};
int l_vacuna_vacia(struct nodo_vacuna *l)
{
    if(l==NULL) return l;
    return 0;
};
/** \brief Comprobrar existencia de la vacuna
 */
struct nodo_vacuna* l_comprobar_vacuna(struct nodo_vacuna *l,const char *elemento)
{
    struct nodo_vacuna *paux;
    paux=l;
    int a=1;
    while((paux != NULL )&&(strcmp(paux->v->num_serie,elemento)!=0))
    {
        paux = paux->psig;
    }
    if(paux == NULL)
    {
        return 0;
    }
    return a;

};
