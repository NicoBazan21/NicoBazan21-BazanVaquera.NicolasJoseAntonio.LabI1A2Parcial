#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "archivos.h"
#include "miBiblioteca.h"
#include "peliculas.h"
#include "linkedList.h"
#include "parser.h"


int cargarArchivo(LinkedList* peli)
{
    int todoOk=0;
    char archivo[50];

    if(peli != NULL)
    {
        pedirCadena(archivo, 50, "Ingrese el nombre del archivo (incluir extension): ","Error. Reingrese nombre: ");

        if(arch_loadFromText(archivo, peli))
        {
            todoOk=1;
        }
    }

    return todoOk;
}

int arch_loadFromText(char* path , LinkedList* pArraypeli)
{
	int todoOk = 0;

	if(path != NULL && pArraypeli != NULL)
	{
		FILE* f = fopen(path, "r");
		if(f != NULL)
		{
			if(arch_parsearpelisPorTexto(f, pArraypeli))
            {
                printf("Lista cargada con exito.\n");
                todoOk = 1;
            }
            else
            {
                printf("Hubo un error al leer el archivo\n");
            }
		}
		else
		{
			printf("No se pudo cargar el archivo\n");
		}

		fclose(f);
	}
	return todoOk;
}

int arch_loadFromBinary(char* path , LinkedList* pArraypeli)
{
	int todoOk = 0;
	if(path != NULL && pArraypeli != NULL)
	{
		FILE* f = fopen(path, "rb");
		if(f != NULL)
		{
			if(arch_parsearpelisPorTexto(f, pArraypeli))
			{
				printf("Lista cargada con exito.\n");
				todoOk = 1;
			}
		}
		else
		{
			printf("No se pudo cargar el archivo\n");
		}

		fclose(f);
	}
	return todoOk;
}


int arch_ListarPelis(LinkedList* pArraypeli)
{

	int todoOk = 0;
	int tam;
	eMovie* peli = NULL;
	if(pArraypeli != NULL)
	{
		tam = ll_len(pArraypeli);

		printf("        *** Lista de pelis ***\n");
		printf("-------------------------------------------------------------------\n");
		printf("Id\tTitulo\t     \t\tGenero\t\t\tDuracion\n");
		printf("-------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			peli = ll_get(pArraypeli, i);
			if(peli != NULL)
			{
				pelis_mostrarpelis(peli);
				todoOk = 1;
			}
		}
	}
    return todoOk;
}

int arch_saveAsBinary(char* path , LinkedList* pArraypeli)
{
	int todoOk;

		int id;
		char nombre[32];
		char tipo[32];
		int tiempo;

		eMovie* emp;

		if(path != NULL && pArraypeli != NULL)
		{
			FILE* f = fopen(path, "wb");

			emp = pelis_new();

			fprintf(f,"id,nombre,tipo,tiempo\n");

			for(int i = 0; i < ll_len(pArraypeli); i++)
			{
				emp = ll_get(pArraypeli, i);

				if(emp != NULL)
				{
					pelis_getId(emp, &id);
					pelis_getTitulo(emp, nombre);
					pelis_getGenero(emp, tipo);
					pelis_getDuracion(emp, &tiempo);

					fprintf(f, "%d,%s,%s,%d\n", id, nombre, tipo, tiempo);

					todoOk = 1;
				}
				else
				{
					todoOk = 0;
					break;
				}
			}
			fclose(f);
		}
		if(todoOk==0)
        {
            printf("mal");
        }
	    return todoOk;
}

int arch_saveAsText(char* path , LinkedList* pArraypeli)
{
	int todoOk;

	int id;
	char titulo[32];
	char genero[32];
	int duracion;

	eMovie* emp;

	if(path != NULL && pArraypeli != NULL)
	{
		FILE* f = fopen(path, "w");

		emp = pelis_new();

		fprintf(f,"id,titulo,genero,duracion\n");

		for(int i = 0; i < ll_len(pArraypeli); i++)
		{
			emp = ll_get(pArraypeli, i);

			if(emp != NULL)
			{
				pelis_getId(emp, &id);
				pelis_getTitulo(emp, titulo);
				pelis_getGenero(emp, genero);
				pelis_getDuracion(emp, &duracion);

				fprintf(f, "%d,%s,%s,%d\n", id, titulo, genero, duracion);

				todoOk = 1;
			}
			else
			{
				todoOk = 0;
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}


LinkedList* filtrar_tipo(LinkedList* pelis)
{
    int opcion;
    int opcionMin = 1;
    int opcionMax=8;

    LinkedList* mostrar;

    if(pelis != NULL)
    {
        printf("Menu de ordenamiento\n");
        pedirEntero(&opcion, "Ingrese opcion\n1.Drama\n2.Adventure\n3.Comedy\n4.Romance\n5.Documentary\n6.Horror\n7.Musical\n8.Action","Error. Reingrese opcion: ",opcionMin,opcionMax);

        switch(opcion)
        {
            case 1:
                mostrar=ll_filter(pelis, pelis_filtrarTipoDrama);
                arch_ListarPelis(mostrar);
                break;
            case 2:
                mostrar=ll_filter(pelis, pelis_filtrarTipoAventura);
                arch_ListarPelis(mostrar);
                break;
            case 3:
                mostrar=ll_filter(pelis, pelis_filtrarTipoComedy);
                arch_ListarPelis(mostrar);
                break;
            case 4:
                mostrar=ll_filter(pelis, pelis_filtrarTipoRomance);
                arch_ListarPelis(mostrar);
                break;
            case 5:
                mostrar=ll_filter(pelis, pelis_filtrarTipoDocumentary);
                arch_ListarPelis(mostrar);
                break;
            case 6:
                mostrar=ll_filter(pelis, pelis_filtrarTipoHorror);
                arch_ListarPelis(mostrar);
                break;
            case 7:
                mostrar=ll_filter(pelis, pelis_filtrarTipoMusical);
                arch_ListarPelis(mostrar);
                break;
            case 8:
                mostrar=ll_filter(pelis, pelis_filtrarTipoAction);
                arch_ListarPelis(mostrar);
                break;
        }

    }

    return mostrar;
}


int pelis_ordenarNombreDuracion(void* pPeliA, void* pPeliB)
{
    char cadena[128];
	char cadenaDos[128];

	int duracionUno = 0;
	int duracionDos = 0;

	eMovie* emp = NULL;
	eMovie* empDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeliA != NULL && pPeliB != NULL)
	{
		emp = (eMovie*) pPeliA;
		empDos = (eMovie*) pPeliB;

		if(pelis_getTitulo(emp, cadena) == 1
		&& pelis_getTitulo(empDos, cadenaDos) == 1)
		{
			if(strcmp(cadena, cadenaDos) > 0)
            {
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
			    if(strcmp(cadena, cadenaDos) < 0)
                {
                    retornoXqSinEstoMeDaUnWarning = -1;

                }
                else
                {
                    pelis_getDuracion(emp,&duracionUno);
                    pelis_getDuracion(empDos,&duracionUno);
                    if(duracionUno > duracionDos)
                    {
                        retornoXqSinEstoMeDaUnWarning = 1;
                    }
                }
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}


LinkedList* ordenarPeliculas(LinkedList* pPeli)
{
    int opcion;
    int opcionMin=1;
    int opcionMax=2;

    LinkedList* copia;

    copia=ll_clone(pPeli);

    if(pPeli != NULL)
    {
        if(copia != NULL)
        {
            pedirEntero(&opcion, "Ordenamiento. Ingrese:\n1. Ascendente\n2.Descendente\n","Error. Caracter invalido. Reingrese opcion: ",opcionMin, opcionMax);

            if(opcion == 0)
            {
                ll_sort(copia, pelis_ordenarNombreDuracion,0);
                arch_ListarPelis(copia);
            }
            else
            {
                ll_sort(copia, pelis_ordenarNombreDuracion,1);
                arch_ListarPelis(copia);
            }
        }
    }

    return copia;
}

