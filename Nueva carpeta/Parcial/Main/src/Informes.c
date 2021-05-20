#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Biblioteca.h"
#include "Informes.h"


int ContribuyenteRecaudacion_Baja(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[])
{
	int indexContribuyente;
	int idContribuyente;
	int rtn;

	if(eContribuyente_ObtenerIndexOcupado(Contribuyente, TAM_ESTRUCTURA)!= 0)
	{
		eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
		idContribuyente = Get_Int("SELECCIONE ID DEL CONTRIBUYENTE: ", "ERROR. REINGRESE: ");
		indexContribuyente = eContribuyente_BuscarPorID(Contribuyente, TAM_ESTRUCTURA, idContribuyente);
		while(indexContribuyente == -1)
		{
			eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
			idContribuyente = Get_Int("SELECCIONE ID DEL CONTRIBUYENTE: ", "ERROR. REINGRESE: ");
			indexContribuyente = eContribuyente_BuscarPorID(Contribuyente, TAM_ESTRUCTURA, idContribuyente);
		}


		if(eRecaudacionContribuyente_MostrarTodos(Recaudacion, TAM_ESTRUCTURA, idContribuyente)==0)
		{
			puts(" * ESTE CONTRIBUYENTE NO TIENE RECAUDACIONES ASIGNADAS");

		}



		if(Validate_Exit_SN("DESEA DAR DE BAJA DEFINITIVAMENTE? [S]-SI  [N]-NO:", "ERROR. REINGRESE: "))
		{
			for(int i =0; i< TAM_ESTRUCTURA; i++)
				{
					if(Recaudacion[i].isEmpty == OCUPADO && Recaudacion[i].idContribuyente == idContribuyente)
					{
						Recaudacion[i].isEmpty = BAJA;
					}
				}
			Contribuyente[indexContribuyente].isEmpty = BAJA;
			puts(" * RECAUDACION DADA DE BAJA EXITOSAMENTE");
			rtn = 0;
		}
		else{
			puts(" * BAJA DE RECAUDACION CANCELADA");
			rtn = 1;
		}


	}
	else
	{
		puts(" * NO SE INGRESO NINGUN CONTRIBUYENTE");
		rtn = 1;
	}

	return rtn;
}


int ContribuyenteRecaudacion_Alta(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[], int * id)
{
	int rtn = 0;
	eRecaudacion auxRecaudacion;
	int indexContribuyente;
	int idContribuyente;
	int indexRecaudacion;

	if(eContribuyente_ObtenerIndexOcupado(Contribuyente, TAM_ESTRUCTURA)!= 0)
	{
		eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
		idContribuyente = Get_Int("SELECCIONE ID DEL CONTRIBUYENTE: ", "ERROR. REINGRESE: ");
		indexContribuyente = eContribuyente_BuscarPorID(Contribuyente, TAM_ESTRUCTURA, idContribuyente);
		while(indexContribuyente == -1)
		{
			eContribuyente_MostrarTodos(Contribuyente, TAM_ESTRUCTURA);
			idContribuyente = Get_Int("SELECCIONE ID DEL CONTRIBUYENTE: ", "ERROR. REINGRESE: ");
			indexContribuyente = eContribuyente_BuscarPorID(Contribuyente, TAM_ESTRUCTURA, idContribuyente);
		}
		indexRecaudacion = eRecaudacion_ObtenerIndexLibre(Recaudacion, TAM_ESTRUCTURA);

		if (indexRecaudacion != -1)
		{
			auxRecaudacion = eRecaudacion_CargarDatos();
			if (Validate_Exit_SN("QUIERE CONTINUARCON LA CARGA? [S]-SI  [N]-NO: ", "ERROR. REINGRESE: "))
			{
				auxRecaudacion.idRecaudacion = eRecaudacion_ObtenerID(id);
				auxRecaudacion.isEmpty = OCUPADO;
				Recaudacion[indexRecaudacion] = auxRecaudacion;
				Recaudacion[indexRecaudacion].idContribuyente = idContribuyente;
				rtn = 1;
				puts(" * RECAUDACION DADA DE ALTA EXITOSAMENTE");
			}
			else
			{
				puts(" * ALTA DE RECAUDACION CANCELADA");
			}
		}
	}
	else
	{
		puts(" * NO HAY NINGUN CONTRIBUYENTE INICIALIZADO");
	}

	return rtn;


}

int RecaudacionContribuyente_RefinanciarSaldar(eContribuyente Contribuyente[], int TAM_ESTRUCTURA, eRecaudacion Recaudacion[], int opc)
{
	int idRecaudacion;
	int indexRecaudacion;
	int idContribuyente;
	int indexContribuyente;
	int rtn = 0;
	eRecaudacion_MostrarTodos(Recaudacion, TAM_ESTRUCTURA);
	idRecaudacion = Get_Int("SELECCIONE ID DE LA RECAUDACION : ", "ERROR. REINGRESE: ");
	indexRecaudacion = eRecaudacion_BuscarPorID(Recaudacion, TAM_ESTRUCTURA, idRecaudacion);
	while(indexRecaudacion == -1)
	{
		eRecaudacion_MostrarTodos(Recaudacion, TAM_ESTRUCTURA);
		idRecaudacion = Get_Int("SELECCIONE ID DEL CONTRIBUYENTE: ", "ERROR. REINGRESE: ");
		indexRecaudacion = eRecaudacion_BuscarPorID(Recaudacion, TAM_ESTRUCTURA, idRecaudacion);
	}

	idContribuyente = Recaudacion[indexRecaudacion].idContribuyente;
	indexContribuyente = eContribuyente_BuscarPorID(Contribuyente, TAM_ESTRUCTURA, idContribuyente);
	puts("EL CONTRIBUYENTE ES: ");
	eContribuyente_MostrarUno(Contribuyente[indexContribuyente]);

	switch(opc)
	{
		case 1:
			if(Validate_Exit_SN("DESEA REFINANCIAR RECAUDACION? [S]-SI  [N]-NO: ", "ERROR. REINGRESE: ")){
				Recaudacion[indexRecaudacion].estado = REFINANCIAR;
				puts(" * ESTADO CAMBIADO A REFINANCIACION EXITOSAMENTE");
				rtn=1;
			}
			else
			{
				puts(" * CAMBIO DE ESTADO A REFINANCIACION CANCELADO");

			}
			break;

		case 2:
			if(Validate_Exit_SN("DESEA SALDAR RECAUDACION? [S]-SI  [N]-NO: ", "ERROR. REINGRESE: ")){
				Recaudacion[indexRecaudacion].estado = SALDADO;
				puts(" * ESTADO CAMBIADO A SALDADO EXITOSAMENTE");
				rtn=1;
			}
			else
			{
				puts(" * CAMBIO DE ESTADO A SALDADO CANCELADO");

			}

			break;
	}

	return rtn;
}


void eRecaudacionContribuyente_MostrarUno(eRecaudacion Recaudacion) {
	if(Recaudacion.tipo == ARBA)
	{
		printf("%5d  %12d  %12s  %12.0f \n", Recaudacion.idRecaudacion, Recaudacion.mes , "ARBA", Recaudacion.importe);

	}
	else
	{
		if(Recaudacion.tipo == IIBB)
		{
			printf("%5d  %12d  %12s  %12.0f \n", Recaudacion.idRecaudacion, Recaudacion.mes , "IIBB", Recaudacion.importe);

		}
		else
		{
			printf("%5d  %12d  %12s  %12.0f \n", Recaudacion.idRecaudacion, Recaudacion.mes , "GANANCIAS", Recaudacion.importe);

		}
	}
}

int eRecaudacionContribuyente_MostrarTodos(eRecaudacion array[], int TAM, int ID) {

	int i;
	int rtn = 0;
	int cantidad = 0;


	puts("\n\t> LISTADO RECAUDACIONES");
	printf("%10s  %10s %10s  %10s \n\n", "RECAUDACION", "MES", "TIPO" ,"IMPORTE");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO && array[i].idContribuyente == ID) {
				eRecaudacionContribuyente_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eRecaudacionesContribuyente_ImprimirContribuyentes(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[])
{
	int rtn=0;
	int idAnterior;
	int flag =1;
	if(eContribuyente_ObtenerIndexOcupado(Contribuyente, TAM)>0)
		for(int i = 0; i< TAM;i++)
		{
			for(int j = 0; j< TAM; j++)
			{
				if(Contribuyente[i].isEmpty == OCUPADO && Contribuyente[i].idContribuyente == Recaudacion[j].idContribuyente)
				{
					if(Contribuyente[i].idContribuyente != idAnterior || flag ==1)
					{
						puts("\n\n");
						eContribuyente_MostrarUno(Contribuyente[i]);

						eRecaudacionContribuyente_MostrarTodos(Recaudacion, TAM, Contribuyente[i].idContribuyente);
						idAnterior = Contribuyente[i].idContribuyente;
						flag =0;
						rtn =1;
					}

				}
			}

		}
	return rtn;
}

int eRecaudacionesContribuyente_ImprimirRecaudacion(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[])
{
	int rtn =0;

	for(int i=0; i<TAM; i++)
	{
		for(int j =0; j<TAM;j++)
		{
			if(Recaudacion[i].estado == SALDADO && Recaudacion[i].idContribuyente == Contribuyente[j].idContribuyente)
			{
				puts("\n\n");
				puts("LA RECAUDACION ES:");
				eRecaudacion_MostrarUno(Recaudacion[i]);
				puts("EL CONTRIBUYENTE ES:");
				eContribuyente_MostrarUno(Contribuyente[j]);
				rtn =1;
			}
		}
	}

	return rtn;
}

int eContribuyenteRecaudaciones_MasRefinanciados(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]){
	int contador =0;

	for(int i =0; i< TAM ; i++){
		for (int j =0; j<TAM; j++){
			if(Recaudacion[i].estado == REFINANCIAR && Recaudacion[i].idContribuyente == Contribuyente[j].idContribuyente){
				contador ++;
			}
		}
	}
	return contador;
}

int eContribuyenteRecaudaciones_Saldadas(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]){
	int contador =0;

	for(int i =0; i< TAM ; i++){
		if(Recaudacion[i].estado == SALDADO && Recaudacion[i].importe >= 1000){
			contador++;
		}

	}
	return contador;
}

int eRecaudacionesContribuyente_ImprimirPorTipoRec(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[])
{
	int rtn=0;
	if(eContribuyente_ObtenerIndexOcupado(Contribuyente, TAM)>0)
		for(int i = 0; i< TAM;i++)
		{
			for(int j = 0; j< TAM; j++)
			{
				if(Contribuyente[i].isEmpty == OCUPADO && Contribuyente[i].idContribuyente == Recaudacion[j].idContribuyente)
				{
					switch(Recaudacion[j].tipo){
					case ARBA:
						puts("\nTIPO DE RECAUDACION: ARBA");
						eContribuyente_MostrarUno(Contribuyente[i]);
						rtn=1;
						break;
					case IIBB:
						puts("\nTIPO DE RECAUDACION: IIBB");
						eContribuyente_MostrarUno(Contribuyente[i]);
						rtn=1;
						break;
					case GANANCIAS:
						puts("\nTIPO DE RECAUDACION: GANANCIAS");
						eContribuyente_MostrarUno(Contribuyente[i]);
						rtn=1;
						break;
					}

				}
			}

		}
	return rtn;
}

int eContribuyenteRecaudacion_mesFebrero(eContribuyente Contribuyente[], int TAM, eRecaudacion Recaudacion[]){

	int rtn = 0;


	for(int i =0; i< TAM ; i++){
		for (int j =0; j<TAM; j++){
			if(Recaudacion[i].mes == 2 && Recaudacion[i].idContribuyente == Contribuyente[j].idContribuyente){
				puts(" * CONTRIBUYENTE MES FEBRERO:");
				eContribuyente_MostrarUno(Contribuyente[j]);
				rtn=1;
			}
		}
	}

	return rtn;
}

