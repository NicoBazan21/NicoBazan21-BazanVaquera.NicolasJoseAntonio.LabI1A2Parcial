#ifndef MIBIBLIOTECA_H_INCLUDED
#define MIBIBLIOTECA_H_INCLUDED



#endif // MIBIBLIOTECA_H_INCLUDED


/** \brief menu
 *
 * \return int
 *
 */
int menu();
/** \brief menu modificar persona
 *
 * \return int
 *
 */
int menuModificacion();
/** \brief validar numeros en cadenas
 *
 * \param name char*
 * \param tam int
 * \return int
 *
 */
int validarNumCadenas(char* name, int tam);
/** \brief pide una cadena
 *
 * \param cadena[] char
 * \param tam int
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \return int
 *
 */
int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[]);
/** \brief pide un flotante
 *
 * \param numero float*
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \param min float
 * \param max float
 * \return int
 *
 */
int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max);
/** \brief pide un entero
 *
 * \param numero int*
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \param min int
 * \param max int
 * \return int
 *
 */
int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max);
/** \brief pide un caracter
 *
 * \param caracter char*
 * \param x char
 * \param y char
 * \param mensajeUno[] char
 * \param mensajeError[] char
 * \return int
 *
 */
int pedirCaracter(char* caracter,char x, char y, char mensajeUno[], char mensajeError[]);
/** \brief submenu para persona
 *
 * \return int
 *
 */
int menuDos();
/** \brief guarda la siguiente id en un archivo
 *
 * \param id int
 * \return void
 *
 */
void saveNextId(int id);
/** \brief obtiene la sieguiente id
 *
 * \return int
 *
 */
int nextId();

/** \brief funcion generadora de numeros random
 *
 * \param min int recibe el minimo
 * \param max int recibe el maximo
 * \return int
 *
 */
int numerosRandom(int min, int max);
