#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file hora.c
* \brief Hora del sistema
*/

/** \brief Funcion para sacar hora del sistema
 */
char hora(char *f)
{
        time_t fecha = time(0);
        struct tm *fecha_actual = localtime(&fecha);
        char fecha_formateada[255];
        strftime(fecha_formateada,128,"%d/%m/%y",fecha_actual);
        printf("%s\n",fecha_formateada);

        strcpy(f,fecha_formateada) ;
};
