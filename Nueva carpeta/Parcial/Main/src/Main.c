#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Contribuyente.h"
#include "Recaudacion.h"
#include "Biblioteca.h"

#define TAM_ESTRUCTURA 50

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int Contribuyente_idIncremental = 999;
	int Recaudacion_idIncremental = 99;
	int masRefinanciadas;
	int saldadas;
	eContribuyente Contribuyente[TAM_ESTRUCTURA];
	eRecaudacion Recaudacion[TAM_ESTRUCTURA];
	eContribuyente_Inicializar(Contribuyente, TAM_ESTRUCTURA);
	eRecaudacion_Inicializar(Recaudacion, TAM_ESTRUCTURA);
	do {
		Menu("[0] - SALIR\n[1] - ALTA CONTRIBUYENTE\n[2] - MODIFICAR CONTRIBUYENTE\n[3] - BAJA CONTRIBUYENTE\n[4] - INGRESAR RECAUDACION\n[5] - REFINANCIAR RECAUDACION\n[6] - SALDAR RECAUDACION\n[7] - IMPRIMIR CONTRIBUYENTES\n[8] - IMPRIMIR RECAUDACIONES SALDADAS\n[9] - INFORMES\n");
		opc = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 0, 9);
		switch (opc)
		{
		case 0:
			if(Validate_Exit_SN("DESEA SALIR [S]-SI [N]-NO: ", "ERROR. REINGRESE: ")){
				opc = 0;
			}else{
				Menu("[0] - SALIR\n[1] - ALTA CONTRIBUYENTE\n[2] - MODIFICAR CONTRIBUYENTE\n[3] - BAJA CONTRIBUYENTE\n[4] - INGRESAR RECAUDACION\n[5] - REFINANCIAR RECAUDACION\n[6] - SALDAR RECAUDACION\n[7] - IMPRIMIR CONTRIBUYENTES\n[8] - IMPRIMIR RECAUDACIONES SALDADAS\n[9] - INFORMES\n");
				opc = Get_IntRange("INICIE EL MENU: ", "ERROR. REINGRESE: ", 0, 9);
			}
			break;
		case 1:
			if (eContribuyente_Alta(Contribuyente, TAM_ESTRUCTURA, &Contribuyente_idIncremental)) {
				puts(" * CONTRIBUYENTE DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS CONTRIBUYENTE");
			}
			system("pause");
			break;
		case 2:
			eContribuyente_Modificacion(Contribuyente, TAM_ESTRUCTURA);
			system("pause");
			break;
		case 3:
			ContribuyenteRecaudacion_Baja(Contribuyente, TAM_ESTRUCTURA, Recaudacion);
			system("pause");
			break;
		case 4:
			ContribuyenteRecaudacion_Alta(Contribuyente, TAM_ESTRUCTURA, Recaudacion, &Recaudacion_idIncremental);
			system("pause");
			break;
		case 5:
			RecaudacionContribuyente_RefinanciarSaldar(Contribuyente, TAM_ESTRUCTURA, Recaudacion, 1);//RECIBE 1 0 2 PARA [1]REIFNANCIAR [2]SALDAR
			system("pause");
			break;
		case 6:
			RecaudacionContribuyente_RefinanciarSaldar(Contribuyente, TAM_ESTRUCTURA, Recaudacion, 2);//RECIBE 1 0 2 PARA [1]REIFNANCIAR [2]SALDAR
			system("pause");
			break;
		case 7:
			if(eRecaudacionesContribuyente_ImprimirContribuyentes(Contribuyente, TAM_ESTRUCTURA , Recaudacion)){
				system("pause");
			}else{
				puts(" * NO HAY NADA PARA MOSTRAR");
			}
			break;
		case 8:
			if(eRecaudacionesContribuyente_ImprimirRecaudacion(Contribuyente, TAM_ESTRUCTURA, Recaudacion)){
				system("pause");
			}else{
				puts(" * NO HAY RECAUDACIONES SALDADAS PARA MOSTRAR");
			}
			break;
		case 9:
			masRefinanciadas =eContribuyenteRecaudaciones_MasRefinanciados(Contribuyente, TAM_ESTRUCTURA, Recaudacion);
			if(masRefinanciadas!= 0)
			{
				printf("\nLA CANTIDAD DE RECAUDACIONES REFINANCIADAS SON: %d\n", masRefinanciadas);
			}else{
				printf("\nNO HAY NINGUNA RECAUDACION REFINANCIADA\n");
			}
			saldadas =eContribuyenteRecaudaciones_Saldadas( Contribuyente,  TAM_ESTRUCTURA,  Recaudacion);
			if(saldadas > 0)
			{
				printf("LA CANTIDAD DE RECAUDACIONES SALDADAS MAYORES A 1000 SON: %d\n", saldadas);
			}else{
				printf("NO HAY NINGUNA RECAUDACION SALDADA MAYOR A 1000\n");

			}
			if(eRecaudacionesContribuyente_ImprimirPorTipoRec(Contribuyente, TAM_ESTRUCTURA,  Recaudacion)){
			}else{
				printf("NO HAY RECAUDACIONES INGRESADAS\n");
			}
			if(eContribuyenteRecaudacion_mesFebrero(Contribuyente, TAM_ESTRUCTURA, Recaudacion)){
			}else{
				printf("NO HAY RECAUDACIONES INGRESADAS EN EL MES DE FEBRERO\n");
			}
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
