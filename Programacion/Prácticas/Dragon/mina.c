#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mina.h"

void ludo(int *oro){

	int oro_conseguido = 0;
	int oro_retirada = 0;
	int prob;

	while(1){

		printf(GREEN "Jugar (1) Retirarse (2) " RESET);
		int opcion;
		scanf("%d", &opcion);

		if (opcion == 1){
			prob = rand() % 11;
			if(prob > 8){
				printf("\x1b[38;5;9m\nPerdiste todo el oro noob.\n\n\x1b[0m");
				oro_retirada = 0;
				getchar();
				return;
			}
			else{
				oro_retirada += oro_conseguido = rand() % 16;
				printf("Has conseguido %d de oro\n", oro_conseguido);
			}
		}
		else if(opcion == 2){
			*oro += oro_retirada;
			printf("\nRetirarse con %d de oro\n\n", oro_retirada);
			getchar();
			return;
		}
		else{
			printf("Opción inválida\n");
		}
	}

	
}

void mina(int *oro){

	while(1){
		printf("Oro: %d\n", *oro);
		printf(YELLOW "Entrar a la taberna (10 oro) s(si) n(no) " RESET);
		char respuesta;
		scanf(" %c", &respuesta);

		if (respuesta == 's'){
			*oro -= 10;
			ludo(oro);
		}
		else if (respuesta == 'n'){
			return;
		}
		else{
			printf("Opción inválida\n");
		}
	}
}