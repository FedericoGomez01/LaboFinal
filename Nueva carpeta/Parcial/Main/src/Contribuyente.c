#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyente.h"
#include "Biblioteca.h"

void eContribuyente_Inicializar(eContribuyente array[], int TAM) {
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int eContribuyente_ObtenerID(int* Contribuyente_idIncremental) {
	*Contribuyente_idIncremental = *Contribuyente_idIncremental+ 1;

	return *Contribuyente_idIncremental;
}

int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM) {
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
int eContribuyente_ObtenerIndexOcupado(eContribuyente array[], int TAM){
	int rtn = 0;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				rtn++ ;
				break;
			}
		}
	}

	return rtn;
}


int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eContribuyente_MostrarUno(eContribuyente Contribuyente) {
	printf("%5d  %10s  %10s  %10s\n", Contribuyente.idContribuyente, Contribuyente.nombre, Contribuyente.apellido, Contribuyente.cuil);
}

int eContribuyente_MostrarTodos(eContribuyente array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;
	puts("\n\t> LISTADO CONTRIBUYENTES");
	printf("%5s  %10s  %10s  %10s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eContribuyente_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\t> CONTRIBUYENTE\n");
	printf("%5s\n\n", "ID");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == BAJA) {
				eContribuyente_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eContribuyente eContribuyente_CargarDatos(void) {
	eContribuyente auxiliar;
	Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ", auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ", auxiliar.apellido, MAX_CHARS_CADENAS);
	Get_Cuit("INGRESE EL CUIL", auxiliar.cuil);

	return auxiliar;
}

eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente) {
	eContribuyente auxiliar = Contribuyente;
	int opc;
	do{
		opc = Get_IntRange("SELECCIONE QUE DESEA MODIFICAR?:\n\t>[0]-SALIR:\n\t>[1]-NOMBRE:\n\t>[2]-APELLIDO:\n\t>[3]-CUIL:", "ERROR. REINGRESE:", 0, 3);
		switch(opc)
		{
		case 1:
			Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ", auxiliar.nombre, MAX_CHARS_CADENAS);

			break;
		case 2:
			Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ", auxiliar.apellido, MAX_CHARS_CADENAS);


			break;
		case 3:
			Get_Cuit("INGRESE EL CUIL", auxiliar.cuil);
			break;
		}
	}while(opc != 0);

	return auxiliar;
}

int eContribuyente_Alta(eContribuyente array[], int TAM,int* id)
{
	int rtn = 0;
	eContribuyente auxContribuyente;

	int index = eContribuyente_ObtenerIndexLibre(array, TAM);

	if (index != -1)
	{
		auxContribuyente = eContribuyente_CargarDatos();
		auxContribuyente.idContribuyente = eContribuyente_ObtenerID(id);
		auxContribuyente.isEmpty = OCUPADO;


		if(Validate_Exit_SN("DESEA CONTINUAR CON EL ALTA DEL CONTRIBUYENTE? [S]-SI [N]-NO: ", "ERROR. REINGRESE: "))
		{
			array[index] = auxContribuyente;
			rtn = 1;
		}

	}

	return rtn;
}

int eContribuyente_Baja(eContribuyente array[], int TAM) {
	int rtn = 0;
	int idContribuyente;
	int index;
	int flag = 0;

	if (eContribuyente_MostrarTodos(array, TAM)) {
		flag = 1;
	}
	if (flag) {
		idContribuyente = Get_Int("INGRESE ID A DAR DE BAJA: ", "ERROR. REINGRESE: ");

		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			puts("NO EXISTE ID.");
			idContribuyente = Get_Int("INGRESE ID A DAR DE BAJA: ", "ERROR. REINGRESE: ");
		}

		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);
		if(Validate_Exit_SN("DESEA CONTINUAR? S-[SI] N-[NO]", "ERROR. REINGRESE:"))
		{
			array[index].isEmpty = BAJA;
			rtn = 1;
			puts("\n * BAJA DE CONTRIBUYENTE EXITOSA");
		}else{
			puts("\n * BAJA DE CONTRIBUYENTE CANCELADA");
		}
	}

	return rtn;
}

int eContribuyente_Modificacion(eContribuyente array[], int TAM) {
	int rtn = 0;
	int idContribuyente;
	int index;
	int flag = 0;
	eContribuyente auxiliar;

	if (eContribuyente_MostrarTodos(array, TAM)) {
		flag = 1;
	}

	if (flag) {
		idContribuyente = Get_Int("INGRESA EL ID DEL CONTRIBUYENTE:", "ERROR. REINGRESE");

		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			puts("NO EXISTE ID.\n");
			idContribuyente = Get_Int("INGRESA EL ID DEL CONTRIBUYENTE:", "ERROR. REINGRESE");
		}

		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);

		auxiliar = eContribuyente_ModificarUno(array[index]);


		if(Validate_Exit_SN("DESEA CONTINUAR? S-[SI] N-[NO]", "ERROR. REINGRESE:"))
		{
			array[index] = auxiliar;
			rtn = 1;
			puts("\n * MODIFICACION DE CONTRIBUYENTE EXITOSA\n");
			eContribuyente_MostrarUno(array[index]);

		}
		else
		{
			puts("\n * MODIFICACION DE CONTRIBUYENTE CANCELADA");
		}
	}

	return rtn;
}
