#ifndef Recaudacion_H_
#define Recaudacion_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

#define ARBA 1
#define IIBB 2
#define GANANCIAS 3

#define REFINANCIAR 4
#define SALDADO 5

//*** ESTRUCTURA
typedef struct {
	int idRecaudacion;
	int mes;
	int tipo;
	float importe;
	int idContribuyente;
	int estado;
	int isEmpty;
} eRecaudacion;
//***

/** INICIO CABECERAS DE FUNCION*/
void eRecaudacion_Inicializar(eRecaudacion array[], int TAM);
/*
 * Inicializa el array de Recaudacion is Empty en libre=0
 *
 *
 * @Param Recive como parametro mi array de tipo eRecaudacion y su tamaño
 *
 * @return void.
 *
 * */
int eRecaudacion_ObtenerID(int* Recaudacion_idIncremental);
/*
 * Cuando es llamada aumenta en uno el valor del puntero pasado
 *
 *
 * @Param Recive como parametro un entero de tipo puntero
 *
 * @return el numero modificado.
 *
 * */
int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int TAM);
/*
 * Me devuelve la posicion del primer array libre que encuentre dentro de mi array
 *
 *
 * @Param Recive como parametro el array de tipo eRecaudacion y su tamaño
 *
 * @return la posicion si pudo o -1 si no encontro ningun lugar libre.
 *
 * */
int eRecaudacion_BuscarPorID(eRecaudacion array[], int TAM, int ID);
/*
 * Busca y compara el id de mi array con uno pasado por parametro.
 *
 *
 * @Param Recive como parametro el array de tipo eRecaudacion, su tamaño y id a comparar
 *
 * @return -1 si no hay ningun o la posicion del id que es igual.
 *
 * */
void eRecaudacion_MostrarUno(eRecaudacion Recaudacion);
/*
 * Imprime por consola uno de la Recaudacion
 *
 *
 * @Param Recive como parametro una posicion de array de tipo eContribuyente
 *
 * @return void.
 *
 * */

int eRecaudacion_MostrarTodos(eRecaudacion array[], int TAM);
/*
 * reecorre el tamaño del array, llama a la funcuion eRecaudacion_MostrarUno para imprimir todas las posiciones ocupadas
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no hay ninguno para imprimir o 1 si imprimio al menos uno para imprimir.
 *
 * */
int eRecaudacion_MostrarDadosDeBaja(eRecaudacion array[], int TAM);
/*
 * recorre el tamaño del array y llama a la funcion eRecaudacion_MostrarUno para mostrar los dados de baja
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente y su tamaño
 *
 * @return 0 si no hay ningun o 1 si imprimio al menos uno para imprimir.
 *
 * */
//ABM
eRecaudacion eRecaudacion_CargarDatos(void);
/*
 * Carga datos en una posicion del array
 *
 *
 * @Param void
 *
 * @return el array cargado de tipo eRecaudacion.
 *
 * */
eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion);
/*
 * Menu que deja modificar los campos que tiene una posicion del array.
 *
 *
 * @Param Recive como parametro una posicion del array de tipo eRecaudacion
 *
 * @return el array modificado de tipo eRecaudacion.
 *
 * */
int eRecaudacion_Alta(eRecaudacion array[], int TAM,int* id);
/*
 * obtiene indice libre donde cargar datos, llama a funicon eRecaudacion_CargarDatos y eRecaudacion_ObtenerID y cambia el isEmpty a ocupado
 *
 *
 * @Param Recive como parametro el array de tipo eRecaudacion, su tamaño y el puntero del id
 *
 * @return 0 si no lo cargo y 1 si lo cargo
 *
 * */
/** FIN CABECERAS DE FUNCION*/
#endif
