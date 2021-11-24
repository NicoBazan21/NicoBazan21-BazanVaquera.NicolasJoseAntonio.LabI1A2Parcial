#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "linkedList.h"
#include "archivos.h"
#include "miBiblioteca.h"
#include "peliculas.h"

int arch_parsearpelisPorTexto(FILE* pFile , LinkedList* pArraypeli)
{
	int todoOk=0;

	/*
	 typedef struct
	{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
	}Employee;
	*/
	char buffer[4][128];

	eMovie* peli = NULL;

	if(pFile != NULL && pArraypeli != NULL)
	{
        //fscanf(pFile, "%d,%[^,],%d,%f",&id, nombre, &horas, &sueldo);
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
    		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

			peli = pelis_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

			if(peli != NULL)
			{
				ll_add(pArraypeli, peli);

				todoOk = 1;
			}
			else
            {
                todoOk=0;
                break;
            }
        }
	}
    return todoOk;
}
