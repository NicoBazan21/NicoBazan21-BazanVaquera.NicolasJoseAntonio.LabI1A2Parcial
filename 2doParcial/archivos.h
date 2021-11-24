#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "linkedList.h"



#endif // ARCHIVOS_H_INCLUDED



/** \brief (funcion creada para reducir codigo) cargar archivo.txt pide el nombre ingreso de usuario y llama al resto de funciones
 *
 * \param peli LinkedList*
 * \return int
 *
 */
int cargarArchivo(LinkedList* peli);
/** \brief funcion cargadora de texto
 *
 * \param path char*
 * \param pArraypeli LinkedList*
 * \return int
 *
 */
int arch_loadFromText(char* path , LinkedList* pArraypeli);

/** \brief funcion cargadora de archivos mediante binario
 *
 * \param path char*
 * \param pArraypeli LinkedList*
 * \return int
 *
 */
int arch_loadFromBinary(char* path , LinkedList* pArraypeli);


int arch_ListarPelis(LinkedList* pArraypeli);

int arch_saveAsText(char* path , LinkedList* pArraypeli);

/** \brief funcion que trabaja con ll_filter para llamar otras funciones
 *
 * \param pelis LinkedList*
 * \return LinkedList* retorna la nueva lista generada para trabajar con ella
 *
 */
LinkedList* filtrar_tipo(LinkedList* pelis);
/** \brief funcion ordenadora de peliculas que trabaja con ll_sort
 *
 * \param pPeli LinkedList*
 * \return LinkedList*
 *
 */
LinkedList* ordenarPeliculas(LinkedList* pPeli);
/** \brief funcion ordena las entidades recibidas por nombre y duracion
 *
 * \param pPeliA void* pelement A
 * \param pPeliB void* pelement B
 * \return int
 *
 */
int pelis_ordenarNombreDuracion(void* pPeliA, void* pPeliB);
