#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file lista_paciente.c
* \brief Implementacion de todas las funciones de listas relacionadas con la tabla PACIENTE. las funciones "comunes" estan comentadas en LISTA_GRUPO_POBLACIONAL.C ,se comentara las exclusivas de la lista
*/


struct nodo_paciente* l_paciente_crear_p(void)
{
    return(NULL);
};
struct nodo_paciente* l_paciente_insertar_p(struct nodo_paciente *l,struct nodo_paciente *pindice,struct paciente *elemento)
{
    struct nodo_paciente *paux;

    paux = (struct nodo_paciente *) malloc(sizeof (struct nodo_paciente));

    if (paux != NULL) {
       paux->p = elemento;

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
struct nodo_paciente* l_paciente_insertar_primera_posicion(struct nodo_paciente *l,struct paciente *elemento)
{
        struct nodo_paciente *paux;

    paux = (struct nodo_paciente *) malloc(sizeof (struct nodo_paciente));

    if (paux != NULL) {
       paux->p = elemento;

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
struct nodo_paciente* l_paciente_primero(struct nodo_paciente *l)
{
    return(l);
};
struct nodo_paciente* l_paciente_ultimo(struct nodo_paciente *l)
{
    struct nodo_paciente *paux; // ultimo elemento lista = NULL
    paux=l;
    while ((paux != NULL) && (paux->psig != NULL))
        paux = paux->psig;
    return (paux);
};
struct nodo_paciente* l_paciente_siguiente(struct nodo_paciente *l,struct nodo_paciente *pindice)
{
    return(pindice->psig);
};
struct nodo_paciente* l_paciente_anterior(struct nodo_paciente *l,struct nodo_paciente *pindice)
{
    struct nodo_paciente *paux;
    if ((pindice == l) || (l == NULL)) return(NULL);
    else {
      paux = l;
      while (paux->psig != pindice)
        paux=paux->psig;
      return (paux);
   }
};
int l_numero_pacientes(struct nodo_paciente *l)
{
    int contador;
    struct nodo_paciente *paux;
    paux = l;
    contador = 1;
    if (paux->psig == NULL) system("PAUSE");
    while (paux->psig != NULL) {

        contador++;
        paux = paux->psig;
    }
    return (contador);
};
struct nodo_paciente* l_paciente_localizar(struct nodo_paciente* l,const char *elemento)
{
    struct nodo_paciente* paux;
    paux = l;
    while((paux!=NULL)&&(strcmp(elemento,paux->p->dni) !=0))
    {
        paux=paux->psig;
    }
    if(paux==NULL) return NULL;
    return (paux);
};
struct paciente *l_paciente_elemento(struct nodo_paciente *l, struct nodo_paciente *pindice)
{
    return (pindice->p);
};
struct nodo_paciente *l_paciente_borrar(struct nodo_paciente *l, struct nodo_paciente *pindice)
{
  struct nodo_paciente *paux;
  if (l == pindice) {
     l=pindice->psig;
     free(pindice->p->dni);
     free(pindice->p);
     free(pindice);

  }
  else {
    paux = l_paciente_anterior(l,pindice);
    paux->psig=pindice->psig;
    free(pindice->p->dni);
    free(pindice->p);
    free(pindice);
  }
  return l;
}
void l_paciente_destruir(struct nodo_paciente *l)
{
    struct nodo_paciente *pborra;
    struct nodo_paciente *paux;
    paux=l;
    do {
        pborra = paux;
        paux =paux->psig;
        free(pborra->p->apellidos);
     free(pborra->p->nombre);
     free(pborra->p->dni);
     free(pborra->p->direccion);
     free(pborra->p->fecha_nacimiento);
     free(pborra->p->identificador);
     free(pborra->p);
        free (pborra);
    } while (paux != NULL);
};
void mostrar_paciente(struct paciente *p)
{
        printf("\n*********\n");
        printf("DNI: ");puts(p->dni);
        printf("nombre: ");puts(p->nombre);
        printf("apellidos: ");puts(p->apellidos);
        printf("telefono: %d\n");(p->telefono);
        printf("direccion: ");puts(p->direccion);
        printf("fecha_nacimiento: ");puts(p->fecha_nacimiento);
        printf("grupo: ");puts(p->identificador);
        printf("\n*********\n");
};
void l_paciente_listar(struct nodo_paciente *l)
{
    struct nodo_paciente *paux;
    paux=l;
    while(paux != NULL)
    {

        mostrar_paciente(l_paciente_elemento(l,paux));
        paux = paux->psig;
    }
};
int l_paciente_vacia(struct nodo_paciente *l)
{
    if (l == NULL) return 1;
    return 0;
};
/** \brief Conteo de las inoculaciones que tiene el paciente registradas
 */
int l_conteo_inoculaciones(struct nodo_paciente_vacuna *l,const char *dni)
{
    struct nodo_paciente_vacuna *paux;
    paux=l;
    int conta=0;
    while(paux!=NULL)
    {
        if(strcmp(dni,paux->pv->dni)==0)
        {
            ++conta;
        }
        paux=paux->psig;
    }
    return (conta);
};
/** \brief Comprobar que existe el grupo poblacional que se quiere poner como FK
 */
int l_comprobar_grupo(struct nodo_grupo_poblacional *l,const char *identificador)
{
    struct nodo_grupo_poblacional *paux;
    paux=l;
    int conta;
    while(paux != NULL)
    {
        if(strcmp((paux->g->identificador),identificador)==0)
        {
            conta=1;
        }
        paux=paux->psig;
    }
    return(conta);
};
/** \brief Comprobar existencia del paciente
 */
struct nodo_paciente* l_comprobar_paciente(struct nodo_paciente* l,const char *elemento)
{
    struct nodo_paciente* paux;
    paux = l;
    while((paux!=NULL)&&(strcmp(elemento,paux->p->dni) !=0))
    {
        paux=paux->psig;
    }
    if(paux==NULL) return NULL;
    return (1);
};
