#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file crear_struct.c
* \brief Implementacion de la modificacion y listado de estructuras
*/


/** \brief añadir grupos poblacionales
 */
 struct grupo_poblacional *crear_grupo(struct grupo_poblacional *g,int *conta_grupo)
{
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);

        g = (struct grupo_poblacional *)malloc(sizeof(struct grupo_poblacional));

    printf("IDENTIFICADOR: ");fflush(stdin);gets(buffer);
    g->identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(g->identificador,buffer);

    printf("NOMBRE: ");fflush(stdin);gets(buffer);
    g->descripcion = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(g->descripcion,buffer);




    (*conta_grupo) = (*conta_grupo) + 1;
    free(buffer);
    return g;

};

/** \brief añadir pacientes
 */
struct paciente *crear_paciente (struct paciente *p,int *conta_pacientes)
{
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);

        p = (struct paciente *)malloc(sizeof(struct paciente));
    printf("DNI: ");fflush(stdin);gets(buffer);
    p->dni = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p->dni,buffer);

    printf("NOMBRE: ");fflush(stdin);gets(buffer);
    p->nombre = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p->nombre,buffer);

    printf("APELLIDOS: ");fflush(stdin);gets(buffer);
    p->apellidos = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p->apellidos,buffer);

    printf("DIRECCION: ");fflush(stdin);gets(buffer);
    p->direccion = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p->direccion,buffer);

    printf("FECHA DE NACIMIENTO: ");fflush(stdin);gets(buffer);
    p->fecha_nacimiento = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p->fecha_nacimiento,buffer);

    printf("Identificador del grupo: ");fflush(stdin);gets(buffer);


    p->identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p->identificador,buffer);



    printf("Numero de telefono: ");fflush(stdin); scanf("%d",&p[*conta_pacientes].telefono);


    (*conta_pacientes) = (*conta_pacientes) + 1;
    free(buffer);
    return p;

};
/** \brief añadir vacunas
 */
struct vacuna *crear_vacuna(struct vacuna *v,int *conta_vacunas)
{

    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);

        v = (struct vacuna *)malloc(sizeof(struct vacuna));

    printf("NUM SERIE: ");fflush(stdin);gets(buffer);
    v->num_serie = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v->num_serie,buffer);

    printf("EMPRESA: ");fflush(stdin);gets(buffer);
    v->empresa = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v->empresa,buffer);

    printf("FECHA APROBACION: ");fflush(stdin);gets(buffer);
    v->fecha_aprobacion = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v->fecha_aprobacion,buffer);

    printf("Lote: ");fflush(stdin); gets(buffer);
    v->lote = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(v->lote,buffer);


    (*conta_vacunas) = (*conta_vacunas) + 1;
    free(buffer);
    return v;
};
/** \brief registrar las inoculaciones en pacientes
 */
struct paciente_vacuna *crear_pacientes_vacunas(struct paciente_vacuna *pv,int *conta_pacientes_vacunas)
{
    char *buffer = (char *)malloc(sizeof(char)*TAM_BUFFER);


        pv = (struct paciente_vacuna *)malloc(sizeof(struct paciente_vacuna));

    printf("DNI: ");fflush(stdin);gets(buffer);
    pv->dni = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv->dni,buffer);

    printf("NUM SERIE: ");fflush(stdin);gets(buffer);
    pv->num_serie = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv->num_serie,buffer);

    printf("\nVa a introducir fecha: Si(1) o No(2)?:");
    fflush(stdin);
    int respuesta;
    scanf("%d",&respuesta);

    if(respuesta==2)
    {

        hora(buffer);
        pv->fecha = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
        strcpy(pv->fecha,buffer);
    }
    else
    {
    printf("FECHA: ");fflush(stdin);gets(buffer);
    pv->fecha = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv->fecha,buffer);
    }


    /**< creacion del identificador */
    strcpy(buffer,pv->dni);
    strcat(buffer,"_");
    strcat(buffer,pv->num_serie);
    strcat(buffer,"_");
    strcat(buffer,pv->fecha);
    pv->identificador = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(pv->identificador,buffer);

    puts("\nLa inoculacion ha sido dado de alta con exito\nEl identificador asignado a la inoculacion es:");
    printf("%s",pv->identificador);
    (*conta_pacientes_vacunas) = (*conta_pacientes_vacunas) + 1;
    free(buffer);
    return pv;

};




