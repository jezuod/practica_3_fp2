#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED


/**
* \file estructuras.h
* \brief Declaracion de estructuras
*/

/** \brief Tabla Paciente
 *
 * \param DNI -> dni del paciente unico
 * \param NOMBRE -> nombre del paciente
 * \param APELLIDOS -> apellido  del paciente
 * \param TELEFONO -> telefono del paciente
 * \param DIRECCION -> direccion del paciente
 * \param FECHA_NACIMIENTO -> fecha de nacimiento del paciente
 * \param IDENTIFICADOR -> identificador del grupo poblacional al que pertenece el paciente
 * \return
 *
 */

struct paciente
{
    char *dni; /**<  pk */
    char *nombre;
    char *apellidos;
    int telefono;
    char *direccion;
    char *fecha_nacimiento;
    char *identificador; /**<  fk de grupo poblacional */
};
/** \brief Tabla Vacuna
 *
 * \param NUM_SERIE -> numero de serie de la vacuna
 * \param EMPRESA -> empresa que produce la vacuna
 * \param FECHA_APROBACION -> fecha de la aprobacion del uso de la vacuna
 * \param LOTE -> cantidad de vacuna disponible
 * \return
 *
 */
struct vacuna
{
    char *num_serie; /**<  pk */
    char *empresa;
    char *fecha_aprobacion;
    char *lote;
};
/** \brief Tabla Grupo Poblacional
 *
 * \param IDENTIFICADOR -> identificador del grupo poblacional
 * \param DESCRIPCION -> descripcion del grupo poblacional
 * \return
 *
 */
struct grupo_poblacional
{
    char *identificador; /**<  pk */
    char *descripcion;
};
/** \brief Tabla Paciente_Vacuna , hace referencia a las inoculaciones
 *
 * \param IDENTIFICADOR -> identificador FORMATO   <DNI>_<Id>_DD_MM_AAAA
 * \param DNI -> dni del paciente que se ha inoculado
 * \param NUM_SERIE -> numero de serie de la vacuna inoculada
 * \param FECHA -> fecha de la inoculacion
 * \return
 *
 */
struct paciente_vacuna
{
    char *identificador; /**<  FORMATO   <DNI>_<Id>_DD_MM_AAAA */
    char *dni; /**<  clave primaria de paciente */
    char *num_serie; /**<  clave primaria de vacuna */
    char *fecha; /**<  fecha */
};

/** \brief Tabla nodo_paciente , lista
 *
 * \param paciente *p -> estructura anidada
 * \param nodo_paciente *psig -> siguiente puntero
 * \return
 *
 */
struct nodo_paciente
{
    struct paciente *p;
    struct nodo_paciente *psig;
};
/** \brief Tabla nodo_vacuna , lista
 *
 * \param vacuna *v -> estructura anidada
 * \param nodo_vacuna *psig -> siguiente puntero
 * \return
 *
 */
struct nodo_vacuna
{
    struct vacuna *v;
    struct nodo_vacuna *psig;
};
/** \brief Tabla nodo_paciente_vacuna , lista
 *
 * \param paciente_vacuna *v -> estructura anidada
 * \param nodo_paciente_vacuna *psig -> siguiente puntero
 * \return
 *
 */
struct nodo_paciente_vacuna
{
    struct paciente_vacuna *pv;
    struct nodo_paciente_vacuna *psig;
};
/** \brief nodo_grupo_poblacional , lista
 *
 * \param grupo_poblacional *g -> estructura anidada
 * \param nodo_grupo_poblacional *psig -> siguiente puntero
 * \return
 *
 */
struct nodo_grupo_poblacional
{
    struct grupo_poblacional *g;
    struct nodo_grupo_poblacional *psig;
};

/**< TYPEDEF paciente*/
typedef struct nodo_paciente *Lista_paciente;
typedef struct nodo_paciente *Posicion_paciente;
/**< TYPEDEF vacuna*/
typedef struct nodo_vacuna *Lista_vacuna;
typedef struct nodo_vacuna *Posicion_vacuna;
/**< TYPEDEF paciente_vacuna*/
typedef struct nodo_paciente_vacuna *Lista_paciente_vacuna;
typedef struct nodo_paciente_vacuna *Posicion_paciente_vacuna;
/**< TYPEDEF grupo_poblacional */
typedef struct nodo_grupo_poblacional *Lista_grupo_poblacional;
typedef struct nodo_grupo_poblacional *Posicion_grupo_poblacional;

#endif // ESTRUCTURAS_H_INCLUDED
