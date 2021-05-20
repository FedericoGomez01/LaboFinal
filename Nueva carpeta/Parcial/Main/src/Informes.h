#ifndef Informes_H_
#define Informes_H_
#include "Contribuyente.h"
#include "Recaudacion.h"




int ContribuyenteRecaudacion_Baja(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[]);

/*
 * Da de baja los contribuyentes con sus respectivas recaudaciones
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente, su tamaño y el array de tipo eRecaudacion
 *
 * @return 1 si se cancela la baja o 0 si se di de baja correctamente
 *
 * */
int ContribuyenteRecaudacion_Alta(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[], int * id);
/*
 * Da de alta una recaudacion y se la asigna a un contribuyente
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente, su tamaño, el array de tipo eRecaudacion y el puntero entero del id
 *
 * @return 0 si se cancela la baja o 1 si se di de baja correctamente
 *
 * */
int RecaudacionContribuyente_RefinanciarSaldar(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[], int opc);
/*
 * cambia el estado del campo de Recaudacion a refinanciar o saldar dependiendo la necesidad
 *
 *
 * @Param Recive como parametro el array de tipo eContribuyente, su tamaño, el array de tipo eRecaudacion y el entero que determina si se salda o se refinancia.
 *
 * @return 0 si se cancela la baja o 1 si se di de baja correctamente
 *
 * */
void eRecaudacionContribuyente_MostrarUno(eRecaudacion Recaudacion);

int eRecaudacionContribuyente_MostrarTodos(eRecaudacion array[], int TAM, int ID);

int eRecaudacionesContribuyente_ImprimirContribuyentes(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]);

int eRecaudacionesContribuyente_ImprimirRecaudacion(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]);

int eContribuyenteRecaudaciones_MasRefinanciados(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]);

int eContribuyenteRecaudaciones_Saldadas(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]);

int eRecaudacionesContribuyente_ImprimirPorTipoRec(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]);

int eContribuyenteRecaudacion_mesFebrero(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]);
#endif
