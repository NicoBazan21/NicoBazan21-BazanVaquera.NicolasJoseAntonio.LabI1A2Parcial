#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "peliculas.h"
#include "miBiblioteca.h"
#include "linkedList.h"

eMovie* pelis_new()
{
	 eMovie* nuevaPeli;

	 nuevaPeli = (eMovie*) malloc (sizeof(eMovie));

	 if(nuevaPeli != NULL)
	 {
		 nuevaPeli->id=0;
		 strcpy(nuevaPeli->titulo, "nn");
		 strcpy(nuevaPeli->genero, "nnn");
		 nuevaPeli->duracion=0;
	 }

	 return nuevaPeli;
}

eMovie* pelis_newParametros(char* idStr,char* tituloStr,char* generoStr, char* duracionStr)
{
	eMovie* nuevaPeli;

	nuevaPeli = pelis_new();

	if(nuevaPeli != NULL)
	{
		if(!( pelis_setId(nuevaPeli, atoi(idStr))
             && pelis_setTitulo(nuevaPeli, tituloStr)
             && pelis_setGenero(nuevaPeli, generoStr)
             && pelis_setDuracion(nuevaPeli, atoi(duracionStr))  ))
		{
		     free(nuevaPeli);
		     nuevaPeli=NULL;
		}
	}

	return nuevaPeli;
}

int pelis_setId(eMovie* this,int id)
{
    int todoOk=0;

    if(this != NULL && id > 0)
    {
    	this->id = id;
        todoOk=1;
    }
    else
    {
    	printf("Id invalido\n");
    }

    return todoOk;
}


int pelis_setTitulo(eMovie* this,char* titulo)
{
    int todoOk=0;

    if(this != NULL && titulo != NULL)
    {
        if(strlen(titulo) < 32 && strlen(titulo) > 2)
        {
            strcpy(this->titulo, titulo);
            strlwr(this->titulo);
            this->titulo[0] = toupper(this->titulo[0]);
            for(int i = 0; i < 32; i++)
            {
                if(titulo[i] == ' ')
                {
                    this->titulo[i+1] = toupper(this->titulo[i+1]);
                }
            }
            todoOk=1;
        }
    }
    else
    {
    	printf("Nombre invalido\n");
    }

    return todoOk;
}

int pelis_setGenero(eMovie* this,char* genero)
{
    int todoOk=0;

    if(this != NULL && genero != NULL)
    {
        if(strlen(genero) < 32 && strlen(genero) > 2)
        {
            strcpy(this->genero, genero);
            strlwr(this->genero);
            this->genero[0] = toupper(this->genero[0]);
            for(int i = 0; i < 30; i++)
            {
                if(genero[i] == ' ')
                {
                    this->genero[i+1] = toupper(this->genero[i+1]);
                }
            }
            todoOk=1;
        }
    }
    else
    {
    	printf("Genero invalido\n");
    }

    return todoOk;
}

int pelis_setDuracion(eMovie* this,int duracion)
{
    int todoOk = 0;
    if(this != NULL)
    {
    	this->duracion=duracion;
        todoOk=1;
    }
    else
    {
    	printf("Tiempo invalido\n");
    }
    return todoOk;
}


int pelis_getId(eMovie* this,int* id)
{
	int todoOk = 0;

	   if(this != NULL && id != NULL)
	   {
	       *id=this->id;
	       todoOk=1;
	   }
	   return todoOk;
}

int pelis_getTitulo(eMovie* this,char* titulo)
{
    int todoOk=0;

    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk=1;
    }

    return todoOk;
}

int pelis_getGenero(eMovie* this,char* genero)
{
    int todoOk=0;

    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk=1;
    }

    return todoOk;
}

int pelis_getDuracion(eMovie* this,int* duracion)
{
    int todoOk=0;

    if(this != NULL && duracion != NULL)
    {
        *duracion=this->duracion;
        todoOk=1;
    }

    return todoOk;
}


void pelis_mostrarpelis(eMovie* pelis)
{
	int id;
	char nombre[32];
    char tipo[32];
    int tiempo;

	if(pelis != NULL)
	{
		pelis_getId(pelis, &id);
		pelis_getTitulo(pelis, nombre);
        pelis_getGenero(pelis, tipo);
        pelis_getDuracion(pelis, &tiempo);

        printf("%d   %20s    %10s\t \t%d\n",id, nombre, tipo, tiempo);

	}
}


void* inicializarAleatorios(void* ppelis)
{
    int tiempo;

    if(ppelis != NULL)
    {
        ppelis=(eMovie*)ppelis;

        tiempo = numerosRandom(100,240);

        pelis_setDuracion(ppelis, tiempo);

        ppelis=(void*)ppelis;
    }
    return ppelis;
}


int pelis_filtrarTipoAventura(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Adventure") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}

int pelis_filtrarTipoDrama(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Drama") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
int pelis_filtrarTipoComedy(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Comedy") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
int pelis_filtrarTipoRomance(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Romance") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
int pelis_filtrarTipoDocumentary(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Documentary") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
int pelis_filtrarTipoHorror(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Horror") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
int pelis_filtrarTipoMusical(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Musical") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
int pelis_filtrarTipoAction(void* pPeli)
{
	char generoObtenido[32];

	eMovie* peliAux = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPeli != NULL)
	{
		peliAux = (eMovie*) pPeli;

		if(pelis_getGenero(peliAux, generoObtenido) == 1)
		{
			if(strcmp(generoObtenido,"Action") == 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
            {
                retornoXqSinEstoMeDaUnWarning = 0;
            }
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}


