#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedList.h"
#include "archivos.h"
#include "miBiblioteca.h"
#include "peliculas.h"


int main()
{
    char seguir = 'n';
    int crear = 0;
    int asignar = 0;
    char nombre[32];
    char nombreDos[32];

    LinkedList* peliculas = ll_newLinkedList();

    LinkedList* ordenUno;
    LinkedList* ordenDos;
    srand(time(NULL));

    if(peliculas != NULL)
    {
        do{
            switch(menu())
            {
                case 1:
                    if(crear == 0)
                    {
                        if(cargarArchivo(peliculas))
                        {
                            crear=1;
                        }
                    }
                    else
                    {
                        printf("No se puede volver a crear el archivo\n");
                    }
                    break;
                case 2:
                    if(asignar && crear)
                    {
                        arch_ListarPelis(peliculas);
                    }
                    else
                    {
                        if(asignar == 0 && crear == 1)
                        {
                            printf("No se puede listar sin antes asignar la duracion\n");
                        }
                        else
                        {
                            printf("No se puede listar sin antes cargar el archivo\n");
                        }
                    }
                    break;
                case 3:
                    if(asignar == 0 && crear)
                    {
                        peliculas=ll_map(peliculas, inicializarAleatorios);
                        if(peliculas != NULL)
                        {
                            printf("Asignacion exitosa\n");
                            asignar=1;
                        }
                    }
                    else
                    {
                        if(asignar)
                        {
                            printf("No se puede volver a asignar la duracion\n");
                        }
                        else
                        {
                            printf("Primero hay que cargar el archivo\n");
                        }
                    }
                    break;
                case 4:
                    if(asignar)
                    {
                        ordenUno=filtrar_tipo(peliculas);
                        pedirCadena(nombre, 32, "Como se va a llamar el archivo que va a guardar? Ingrese nombre (sin extension): ","Error. Nombre invalidoºn");
                        strcat(nombre,".txt");
                        arch_saveAsText(nombre, ordenUno);
                        //arch_saveAsBinary("paisesExitosos.bin" ,ordenUno);
                    }
                    else
                    {
                        if(crear == 0)
                        {
                            printf("Primero hay que cargar el archivo\n");
                        }
                        else
                        {
                            printf("Primero hay que asignar la duracion\n");
                        }
                    }

                    break;
                case 5:
                    if(asignar)
                    {
                        ordenDos=ordenarPeliculas(peliculas);
                    }
                    else
                    {
                        if(crear == 0)
                        {
                            printf("Primero hay que cargar el archivo\n");
                        }
                        else
                        {
                            printf("Primero hay que asignar la duracion\n");
                        }
                    }
                    break;
                case 6:
                    if(asignar)
                    {
                        pedirCadena(nombreDos, 32, "Como se va a llamar el archivo que va a guardar? Ingrese nombre (sin extension): ","Error. Nombre invalidoºn");
                        strcat(nombreDos,".txt");
                        arch_saveAsText(nombreDos, ordenDos);
                        }
                    else
                    {
                        if(crear == 0)
                        {
                            printf("Primero hay que cargar el archivo\n");
                        }
                        else
                        {
                            printf("Primero hay que asignar la duracion\n");
                        }
                    }
                    break;
                case 7:
                    pedirCaracter(&seguir, 's', 'n', "Desea salir? s/n","Caracter Invalido. Desea salir? s/n");
                    if(seguir=='s')
                    {
                        printf("Saliendo...\n");
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }

        system("pause");

        }while(seguir == 'n');
        ll_deleteLinkedList(peliculas);
    }
    return 0;
}
