#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file menu.c
* \brief Implementacion del menu
*/

/** \brief funcion menu
 */
int menu(void)
{
    puts("\nMENU");
    puts("----");
    puts("Opcion 1--> Alta pacientes ");
    puts("Opcion 2--> Baja pacientes ");
    puts("Opcion 3--> Alta vacuna");
    puts("Opcion 4--> Alta grupo poblacional");
    puts("Opcion 5--> Alta inoculaciones");
    puts("Opcion 6--> Eliminar inoculaciones");
    puts("Opcion 7--> Listar datos del proceso de vacunacion");
    puts("Opcion 8--> Salir");
    printf("Respuesta: ");
    int respuesta=0;
    scanf("%d",&respuesta);
    return respuesta;

}
