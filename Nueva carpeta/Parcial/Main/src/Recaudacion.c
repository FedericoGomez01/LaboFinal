#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"
#include "Biblioteca.h"



void eRecaudacion_Inicializar(eRecaudacion array[], int TAM) {
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int eRecaudacion_ObtenerID(int* Recaudacion_idIncremental) {
	*Recaudacion_idIncremental = *Recaudacion_idIncremental + 1;
	return *Recaudacion_idIncremental;
}

int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int TAM) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eRecaudacion_BuscarPorID(eRecaudacion array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].idRecaudacion == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eRecaudacion_MostrarUno(eRecaudacion Recaudacion) {
	switch (Recaudacion.tipo){

	case ARBA:
		printf("%5d  %10d  %10s  %10f\n", Recaudacion.idRecaudacion, Recaudacion.mes , "ARBA", Recaudacion.importe);
		break;

	case IIBB:
		printf("%5d  %10d  %10s  %10f\n", Recaudacion.idRecaudacion, Recaudacion.mes , "IIBB", Recaudacion.importe);
		break;

	case GANANCIAS:
		printf("%5d  %10d  %10s  %10f\n", Recaudacion.idRecaudacion, Recaudacion.mes , "GANANCIAS", Recaudacion.importe);
		break;
	}

}

int eRecaudacion_MostrarTodos(eRecaudacion array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\n\t> LISTADO RECAUDACIONES");
	printf("%10s  %10s %10s  %10s\n\n", "RECAUDACION", "MES", "TIPO" ,"IMPORTE");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eRecaudacion_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_MostrarDadosDeBaja(eRecaudacion array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\t> RECAUDACION\n");
	printf("%5s\n\n", "ID");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == BAJA) {
				eRecaudacion_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eRecaudacion eRecaudacion_CargarDatos(void) {
	eRecaudacion auxiliar;

	auxiliar.mes = Get_IntRange("INGRESE EL MES:(NUMERICO)\n\t[1]-ENERO\n\t[2]-FEBRERO\n\t[3]-MARZO\n\t[4]-ABRIL"
			"\n\t[5]-MAYO\n\t[6]-JUNIO\n\t[7]-JULIO\n\t[8]-AGOSTO\n\t[9]-SEPTIEMBRE\n\t[10]-OCTUBRE"
			"\n\t[11]-NOVIEMBRE\n\t[12]-DICIEMBRE ", "ERROR. REINGRESE: ", 1, 31);
	auxiliar. importe = Get_Int("INGRESE UN IMPORTE: ", "ERROR. REINGRESE: ");

	printf("\nSELECCIONE TIPO DE RECAUDACION\n\t[1]- ARBA\n\t[2]- IIBB\n\t[3]- GANANCIAS\n\n");
	switch (auxiliar.tipo =Get_IntRange("INGRESE EL TIPO DE RECAUDACION: ", "ERROR. REINGRESE:", 1, 3)){

	case ARBA:
		auxiliar.tipo = ARBA;
		break;

	case IIBB:
		auxiliar.tipo = IIBB;
		break;

	case GANANCIAS:
		auxiliar.tipo = GANANCIAS;
		break;

	}
	return auxiliar;
}

eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion) {
	eRecaudacion auxiliar = Recaudacion;
	auxiliar = eRecaudacion_CargarDatos();
	return auxiliar;
}
