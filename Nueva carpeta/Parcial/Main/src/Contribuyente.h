#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#ifndef Contribuyente_H_
#define Contribuyente_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct {
	int idContribuyente;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	char cuil[MAX_CHARS_CADENAS];
	char estado[MAX_CHARS_CADENAS];
	int isEmpty;
} eContribuyente;
//***

/** INICIO CABECERAS DE FUNCION*/
void eContribuyente_Inicializar(eContribuyente array[], int TAM);
/*
 * Inicializa el array de contribuyentes is Empty en libre=0
 *
 *
 * @Param Recive como parametro mi array de tipo eContribuyente y su tamaño
 *
 * @return void.
 *
 * */
int eContribuyente_ObtenerID(int* Contribuyente_idIncremental);
/*
 * Cuando es llamada aumenta en uno el valor del puntero pasado
 *
 *
 * @Param Recive como parametro un entero de tipo puntero
 *
 * @return el numero modificado.
 *
 * */
int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM);
/*
 * Me devuelve la posicion del primer array libre que encuentr dentro de mi array
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return la posicion si pudo o -1 si no encontro ningun lugar libre.
 *
 * */
int eContribuyente_ObtenerIndexOcupado(eContribuyente array[], int TAM);
/*
 * Me devuelve la cantidad de indices ocupados
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no hay ningun o la cantidad de ocupados.
 *
 * */
int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID);
/*
 * Busca y compara el id de mi array con uno pasado por parametro.
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente, su tamaño y id a comparar
 *
 * @return -1 si no hay ningun o la posicion del id que es igual.
 *
 * */

void eContribuyente_MostrarUno(eContribuyente Contribuyente);
/*
 * Imprime por consola uno de los contribuyentes
 *
 *
 * @Param Recive como parametro una posicion de array de tipo eContribuyente
 *
 * @return void.
 *
 * */

int eContribuyente_MostrarTodos(eContribuyente array[], int TAM);
/*
 * reecorre el tamaño del array, llama a la funcuion eContribuyente_MostrarUno para imprimir todas las posiciones ocupadas
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no hay ninguno para imprimir o 1 si imprimio al menos uno para imprimir.
 *
 * */
int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM);
/*
 * recorre el tamaño del array y llama a la funcion eContribuyente_MostrarUno para mostrar los dados de baja
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no hay ningun o 1 si imprimio al menos uno para imprimir.
 *
 * */

//ABM
eContribuyente eContribuyente_CargarDatos(void);
/*
 * Carga datos en una posicion del array
 *
 *
 * @Param void
 *
 * @return el array cargado de tipo eContribuyente.
 *
 * */
eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente);
/*
 * Menu que deja modificar los campos que tiene una posicion del array.
 *
 *
 * @Param Recive como parametro una posicion del array de tipo eContribuyente
 *
 * @return el array modificado de tipo eContribuyente.
 *
 * */

int eContribuyente_Alta(eContribuyente array[], int TAM,int* id);
/*
 * obtiene indice libre donde cargar datos, llama a funicon eContribuyente_CargarDatos y eContribuyente_ObtenerID y cambia el isEmpty a ocupado
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente, su tamaño y el puntero del id
 *
 * @return 0 si no lo cargo y 1 si lo cargo
 *
 * */
int eContribuyente_Baja(eContribuyente array[], int TAM);
/*
 * pide al usuario el id del contribuyente a dar de baja y lo da de baja si el usuario quiere
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no lo cargo y 1 si lo cargo
 *
 * */

int eContribuyente_Modificacion(eContribuyente array[], int TAM);
/*
 * pide al usuario el id del contribuyente a dar de baja y lo da de baja si el usuario quiere
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no lo cargo y 1 si lo cargo
 *
 * */
/** FIN CABECERAS DE FUNCION*/
#endif
