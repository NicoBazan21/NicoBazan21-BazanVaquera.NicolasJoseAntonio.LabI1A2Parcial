#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int opcion;

    system("cls");
    printf("          *** Menu de peliculas ***\n");
    printf("------------------------------------------------------------\n");
    printf(" 1. Cargar archivo\n");
    printf(" 2. Imprimir lista\n");
    printf(" 3. Asignar duracion\n");
    printf(" 4. Filtrar por genero\n");
    printf(" 5. Ordenar peliculas por genero y duracion\n");
    printf(" 6. Guardar archivo anterior\n");
    printf(" 7. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int validarNumCadenas(char* name, int tam)
{
    int todoOk= 0;
    int okey;
    int error = 1;

    if(name != NULL && tam > 0)
    {
        do{
            error=0;
            for(int i = 0; i < tam; i++)
            {
                okey = isalpha(name[i]);

                if(name[i] == ' ')
                {
                    okey=1;
                }
                if(okey == 0)
                {
                    printf("Error. Ingreso con caracteres invalidos. Ingrese nuevamente: ");
                    gets(name);
                    tam=strlen(name);
                    error = 1;
                }
            }

        }while(error == 1);

        todoOk=1;
    }
    return todoOk;
}
int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[])
{
    int todoOk =0;
    char entrada[256];
    int tamEntrada;

    if(cadena != NULL && tam > 0 && mensajeUno != NULL && mensajeError != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        gets(entrada);
        tamEntrada = strlen(entrada);

        //validarNumCadenas(entrada, tamEntrada);

        while(tamEntrada > tam || tamEntrada < 1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            gets(entrada);
            tamEntrada=strlen(entrada);
        }

        strcpy(cadena, entrada);
        todoOk=1;
    }

    return todoOk;
}


int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max)
{
    int todoOk =0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%f", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", numero);
        }

        todoOk=1;
    }


    return todoOk;
}

int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max)
{
    int todoOk=0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%d", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", numero);
        }

    todoOk=1;
    }

    return todoOk;
}

int pedirCaracter(char* caracter,char x, char y, char mensajeUno[], char mensajeError[])
{
    int todoOk = 0;
    char caracIng;

    if(caracter != NULL && mensajeError != NULL && mensajeUno != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%c", &caracIng);

        todoOk=1;

        while(caracIng != x && caracIng != y)
        {
        	printf("%s", mensajeError);
            fflush(stdin);
            scanf("%c", &caracIng);
        }
        *caracter=caracIng;
    }
    return todoOk;
}

int nextId()
{
	FILE* f=fopen("ultimoID.txt", "r");
	int* iD=(int*) malloc(sizeof(int));
	int nextId;

	if(f==NULL)
	{
		nextId=1001;
	}
	else
	{
		fscanf(f, "%d", iD);
		nextId=*iD+1;
	}
	fclose(f);

 return nextId;
}


void saveNextId(int iD)
{
	FILE* f=fopen("ultimoID.txt", "r+");

	    if(f==NULL)
	    {
	        f=fopen("ultimoID.txt", "w");
	    }

	    fprintf(f,"%d", iD);
	    fclose(f);
}

int numerosRandom(int min, int max)
{
    int numero;

    numero = rand() % (max - min + 1) + min;

    return numero;
}
