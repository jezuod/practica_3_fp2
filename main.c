//* EJERCICIO BOLETIN 3*//
#include "librerias.h"
#include "estructuras.h"
#include "operaciones_struct.h"
#include "funciones_listas.h"
/**
* \file main.c
* \brief Archivo con la funcion int main()
*/


/** \brief Funcion Principal, que usamos como punto de union
 */
int main()
{
    Lista_grupo_poblacional l_g;
    Posicion_grupo_poblacional posicion_g;
    l_g= l_grupo_poblacional_crear_p();

    Lista_paciente l_p;
    Posicion_paciente posicion_p;
    l_p= l_paciente_crear_p();

    Lista_paciente_vacuna l_pv;
    Posicion_paciente_vacuna posicion_pv;
    l_pv= l_paciente_vacuna_crear_p();

    Lista_vacuna l_v;
    Posicion_vacuna posicion_v;
    l_v= l_vacuna_crear_p();

    struct paciente *pacientes;
    struct vacuna *vacunas;
    struct grupo_poblacional *grupos_poblacional;
    struct paciente_vacuna *pacientes_vacunas;
    int opcion=0;
    char id[255];
    char identificador[255];
    int conta_pacientes=0,conta_vacunas=0,conta_grupo=0,conta_pacientes_vacunas=0,conta_num_inoculaciones=0;
    int n_ino=0;
    int a;
    while(opcion!=8)
    {
        opcion=menu();
        /**<  alta pacientes sin fichero */
        if(opcion==1)
        {
            printf("Grupo poblacional al que pertenece : ");
            fflush(stdin);
            gets(identificador);
            a=l_comprobar_grupo(l_g,identificador);
            if(a==1)
            {
                /**<  guardar paciente y contarlo */
                pacientes=crear_paciente(pacientes,&conta_pacientes);
                /**<  guardar paciente en la lista */
                l_p=l_paciente_insertar_p(l_p,l_paciente_ultimo(l_p),pacientes);

            }
            else
            {
                puts("No existe el grupo poblacional");
            }

        }
        /**<  baja pacientes */
        if(opcion==2)
        {
            printf("Dni:");fflush(stdin);gets(id);
            /**<  contamos las inoculaciones del paciente  */
            n_ino=l_conteo_inoculaciones(l_pv,id);
            printf("\nNumero de inoculaciones del paciente : %d\n",n_ino);
            if(n_ino==0)
            {
                /**<  localizamos el paciente  */
                 posicion_p=l_paciente_localizar(l_p,id);

                if(l_paciente_vacia(posicion_p))
                {
                    puts("No se encontro paciente");
                }
                else
                {
                    l_p=l_paciente_borrar(l_p,posicion_p);
                    puts("Eliminado correctamente");

                }
            }


            else
            {
                puts("El paciente tiene inoculaciones asociadas. Se eliminaran tambien las inoculaciones.");
                puts("Desea continuar? 1(si) 2(no)");
                fflush(stdin); scanf("%d",&a);
                if(a==1)
                {
                    posicion_p=l_paciente_localizar(l_p,id);
                    l_p=l_paciente_borrar(l_p,posicion_p);
                    puts("Eliminado correctamente");
                    for(int i=0;i<n_ino;i++)
                    {
                        /**<  borramos las inoculaciones  */
                        posicion_pv=l_paciente_vacuna_localizar_dni(l_pv,id);
                        l_pv=l_paciente_vacuna_borrar(l_pv,posicion_pv);
                    }

                }
            }

        }
        /**< Alta vacuna por terminal*/
        if(opcion==3)
        {
            vacunas=crear_vacuna(vacunas,&conta_vacunas);

            l_v=l_vacuna_insertar_p(l_v,l_vacuna_ultimo(l_v),vacunas);

        }
        /**< Alta grupo por terminal*/
        if(opcion==4)
        {
            grupos_poblacional=crear_grupo(grupos_poblacional,&conta_grupo);

            l_g=l_grupo_poblacional_insertar_p(l_g,l_grupo_poblacional_ultimo(l_g),grupos_poblacional);
        }
        /**< Alta inoculaciones por terminal*/
        if(opcion==5)
        {
            printf("Introduzca el DNI del paciente : ");fflush(stdin);gets(id);
            a=l_comprobar_paciente(l_p,id);
            n_ino=l_conteo_inoculaciones(l_pv,id);
            if(a==1)
               {
                   printf("Introduzca el numero de serie de la vacuna : ");fflush(stdin);gets(id);
                   a=l_comprobar_vacuna(l_v,id);
                   if(a==1)
                   {
                       /**<  contamos las inoculaciones del paciente  */
                        printf("\nNumero de inoculaciones del paciente : %d\n",n_ino);
                        if(n_ino==3)
                        {
                            puts("Limite de 3 inoculaciones alcanzado en el paciente");
                        }
                        else
                        {
                            pacientes_vacunas=crear_pacientes_vacunas(pacientes_vacunas,&conta_pacientes_vacunas);
                            l_pv=l_paciente_vacuna_insertar_p(l_pv,l_paciente_vacuna_ultimo(l_pv),pacientes_vacunas);
                        }
                   }
                   else
                   {
                       puts("Vacuna no registrada");
                   }

               }
               else
               {
                   puts("Paciente no existe");
               }


        }
        /**<  baja inoculaciones */
        if(opcion==6)
        {
            printf("IDENTIFICADOR:");fflush(stdin);gets(identificador);
                        posicion_pv=l_paciente_vacuna_localizar_identificador(l_pv,identificador);

                         /**<  localizamos el paciente  */
                if(l_paciente_vacuna_vacia(posicion_pv))
                {
                    puts("No se encontro la inoculacion");
                }
                else
                {
                    l_pv=l_paciente_vacuna_borrar(l_pv,posicion_pv);
                    puts("Eliminado correctamente");

                }
        }
        /**<  listar */
        if(opcion==7)
        {
            puts("\n-------------------------");
            puts("GRUPO POBLACIONAL");
            puts("-------------------------");
            l_grupo_poblacional_listar(l_g);
            puts("\n-------------------------");
            puts("PACIENTE");
            puts("-------------------------");
            l_paciente_listar(l_p);
            puts("\n-------------------------");
            puts("INOCULACIONES");
            puts("-------------------------");
            l_paciente_vacuna_listar(l_pv);
            puts("\n-------------------------");
            puts("VACUNA");
            puts("-------------------------");
            l_vacuna_listar(l_v);



            }


    }
}
