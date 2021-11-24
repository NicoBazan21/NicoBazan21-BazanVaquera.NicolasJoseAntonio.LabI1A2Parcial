#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "linkedList.h"

typedef struct{

    int id;
    char titulo[32];
    char genero[32];
    int duracion;

}eMovie;

#endif // PELICULAS_H_INCLUDED



/** \brief constructor de linkedlist Movie
 *
 * \return eMovie*
 *
 */
eMovie* pelis_new();

/** \brief constructor parametrizado de linkedlist movie
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param tituloStr char*
 * \param duracionStr char*
 * \return eMovie*
 *
 */
eMovie* pelis_newParametros(char* idStr,char* nombreStr,char* tituloStr, char* duracionStr);

/** \brief setea la id del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param id int id a validar y setear
 * \return int
 *
 */
int pelis_setId(eMovie* this,int id);
/** \brief setea el titulo del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param titulo char* nombre a validar y setear
 * \return int
 *
 */
int pelis_setTitulo(eMovie* this,char* titulo);
/** \brief setea el genero del elemento pasado linked list movie
 *
 * \param this eMovie*direccion de memoria de la estructura movie
 * \param genero char*genero a validar y setear
 * \return int
 *
 */
int pelis_setGenero(eMovie* this,char* genero);
/** \brief setea la duracion del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param duracion int duracion a validar y setear
 * \return int
 *
 */
int pelis_setDuracion(eMovie* this,int duracion);

/** \brief geter de la id del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param id int* variable pasada por referencia para asignar el valor del id
 * \return int
 *
 */
int pelis_getId(eMovie* this,int* id);
/** \brief  geter del titulo del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param titulo char* variable pasada por referencia para asignar el valor del titulo
 * \return int
 *
 */
int pelis_getTitulo(eMovie* this,char* titulo);
/** \brief geter del genero del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param genero char* variable pasada por referencia para asignar el valor del genero
 * \return int
 *
 */
int pelis_getGenero(eMovie* this,char* genero);
/** \brief  geter de la duracion del elemento pasado linked list movie
 *
 * \param this eMovie* direccion de memoria de la estructura movie
 * \param duracion int* variable pasada por referencia para asignar el valor de la duracion
 * \return int
 *
 */
int pelis_getDuracion(eMovie* this,int* duracion);

/** \brief muestra el elemento pasado
 *
 * \param pelicula eMovie* recibe el pelement
 * \return void
 *
 */
void pelis_mostrarpelis(eMovie* pelicula);
/** \brief funcion que inicializa aleatorios (funcion creada para reducir codigo)
 *
 * \param ppelis void*
 * \return void*
 *
 */
void* inicializarAleatorios(void* ppelis);



/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoAventura(void* pPeli);
/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoDrama(void* pPeli);
/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoComedy(void* pPeli);
/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoRomance(void* pPeli);
/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoDocumentary(void* pPeli);
/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoHorror(void* pPeli);
/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
int pelis_filtrarTipoMusical(void* pPeli);

/** \brief funcion para usar con ll_sort para filtrar por categoria seleccionada
 *
 * \param pPeli void*
 * \return int
 *
 */
 int pelis_filtrarTipoAction(void* pPeli);
