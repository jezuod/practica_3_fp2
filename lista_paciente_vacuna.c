#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file lista_paciente_vacuna.c
* \brief Implementacion de todas las funciones de listas relacionadas con la tabla PACIENTE_VACUNA. las funciones "comunes" estan comentadas en LISTA_GRUPO_POBLACIONAL.C ,se comentara las exclusivas de la lista
*/



/**< las funciones "comunes" estan comentadas en LISTA_GRUPO_POBLACIONAL.C */
/**< se comentara las exclusivas de la lista */
struct nodo_paciente_vacuna* l_paciente_vacuna_crear_p(void)
{
    return(NULL);
};
struct nodo_paciente_vacuna* l_paciente_vacuna_insertar_p(struct nodo_paciente_vacuna *l,struct nodo_paciente_vacuna *pindice,struct paciente_vacuna *elemento)
{
    struct nodo_paciente_vacuna *paux;

    paux = (struct nodo_paciente_vacuna *) malloc(sizeof (struct nodo_paciente_vacuna));

    if (paux != NULL) {
       paux->pv = elemento;

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
struct nodo_paciente_vacuna* l_paciente_vacuna_primera_posicion(struct nodo_paciente_vacuna *l,struct grupo_poblacional *elemento)
{
        struct nodo_paciente_vacuna *paux;

    paux = (struct nodo_paciente_vacuna *) malloc(sizeof (struct nodo_paciente_vacuna));

    if (paux != NULL) {
       paux->pv = elemento;

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
struct nodo_paciente_vacuna* l_paciente_vacuna_primero(struct nodo_paciente_vacuna *l)
{
    return(l);
};
struct nodo_paciente_vacuna* l_paciente_vacuna_ultimo(struct nodo_paciente_vacuna *l)
{
    struct nodo_paciente_vacuna *paux; // ultimo elemento lista = NULL
    paux=l;
    while ((paux != NULL) && (paux->psig != NULL))
        paux = paux->psig;
    return (paux);
};
struct nodo_paciente_vacuna* l_paciente_vacuna_siguiente(struct nodo_paciente_vacuna *l,struct nodo_paciente_vacuna *pindice)
{
    return(pindice->psig);
};
struct nodo_paciente_vacuna* l_paciente_vacuna_anterior(struct nodo_paciente_vacuna *l,struct nodo_paciente_vacuna *pindice)
{
    struct nodo_paciente_vacuna *paux;
    if ((pindice == l) || (l == NULL)) return(NULL);
    else {
      paux = l;
      while (paux->psig != pindice)
        paux=paux->psig;
      return (paux);
   }
};
int l_numero_paciente_vacuna(struct nodo_paciente_vacuna *l)
{
    int contador;
    struct nodo_paciente_vacuna *paux;
    paux = l;
    contador = 1;
    if (paux->psig == NULL) system("PAUSE");
    while (paux->psig != NULL) {

        contador++;
        paux = paux->psig;
    }
    return (contador);
};
/** \brief Localizar por el dni FK  del paciente
 */
struct nodo_paciente_vacuna* l_paciente_vacuna_localizar_dni(struct nodo_paciente_vacuna* l,const char *elemento)
{
    struct nodo_paciente_vacuna* paux;
    paux = l;
    while((paux!=NULL)&&(strcmp(elemento,paux->pv->dni) !=0))
    {
        paux=paux->psig;
    }
    if(paux==NULL) return NULL;
    return (paux);
};
/** \brief Localizar por identificador de la inoculacion PK
 */
struct nodo_paciente_vacuna* l_paciente_vacuna_localizar_identificador(struct nodo_paciente_vacuna* l,const char *elemento)
{
    struct nodo_paciente_vacuna* paux;
    paux = l;
    while((paux!=NULL)&&(strcmp(elemento,paux->pv->identificador) !=0))
    {
        paux=paux->psig;
    }
    if(paux==NULL) return NULL;
    return (paux);
};
struct paciente_vacuna *l_paciente_vacuna_elemento(struct nodo_paciente_vacuna *l, struct nodo_paciente_vacuna *pindice)
{
    return (pindice->pv);
};
struct nodo_paciente_vacuna *l_paciente_vacuna_borrar(struct nodo_paciente_vacuna *l, struct nodo_paciente_vacuna *pindice)
{
  struct nodo_paciente_vacuna *paux;
  if (l == pindice) {
     l=pindice->psig;
     free(pindice->pv->dni);
     free(pindice->pv->identificador);
     free(pindice->pv->fecha);
     free(pindice->pv->num_serie);
     free(pindice->pv);
     free(pindice);

  }
  else {
    paux = l_paciente_vacuna_anterior(l,pindice);
    paux->psig=pindice->psig;
    free(pindice->pv->dni);
     free(pindice->pv->identificador);
     free(pindice->pv->fecha);
     free(pindice->pv->num_serie);
     free(pindice->pv);
     free(pindice);
  }
  return l;
}

void l_paciente_vacuna_destruir(struct nodo_paciente_vacuna *l)
{
    struct nodo_paciente_vacuna *pborra;
    struct nodo_paciente_vacuna *paux;
    paux=l;
    do {
        pborra = paux;
        paux =paux->psig;
     free(pborra->pv->identificador);
     free(pborra->pv->dni);
     free(pborra->pv->fecha);
     free(pborra->pv->num_serie);
     free(pborra->pv);
     free(pborra);
    } while (paux != NULL);
};
void mostrar_paciente_vacuna(struct paciente_vacuna *pv)
{
        printf("\n*********\n");
        printf("IDENTIFICADOR: ");puts(pv->identificador);
        printf("DNI: ");puts(pv->dni);
        printf("FECHA: ");puts(pv->fecha);
        printf("NUMERO DE SERIE VACUNA: ");puts(pv->num_serie);
        printf("\n*********\n");
};
void l_paciente_vacuna_listar(struct nodo_paciente_vacuna *l)
{
    struct nodo_paciente_vacuna *paux;
    paux=l;
    while(paux != NULL)
    {

        mostrar_paciente_vacuna(l_paciente_vacuna_elemento(l,paux));
        paux = paux->psig;
    }
};
/* CUIDADO! ASI NO FUNCIONA POR NO HABER ESPACIOS EN EL IF....
int l_paciente_vacuna_vacia(struct nodo_paciente_vacuna *l)
{
    if(l==NULL) return l;
    return 0;
}; */
int l_paciente_vacuna_vacia(struct nodo_paciente_vacuna *l)
{
    if (l == NULL) return 1;
    return 0;
}

