#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tienda.h"

void tienda(int *oro, int *cant_curas, int *cant_X2){

	int cura_precio = 25;
	int X2_precio = 40;

	printf("\x1b[38;5;46m ¡Hola!, bienvenido a la tienda Doña Marta \n\n\x1b[0m");

	while(1){

		printf("\n Oro: %d\n\n", *oro);
        printf(" Productos disponibles:\n");
        printf("    Cura (25 oro)   - Tienes: %d\n", *cant_curas);
        printf("    Daño X2 (40 oro) - Tienes: %d\n", *cant_X2);
        printf("    Salir de la tienda (X)\n");

		char opcion;
		printf("\n¿Qué desea comprar? C (Curas) D (Daño x 2) X (salir) ");
		scanf(" %c", &opcion);

		if (opcion == 'c'){
			if (*oro < cura_precio){
				printf("Oro insuficiente\n");
				getchar();
			}
			else{
				printf("Hascomprado Cura\n");
				(*cant_curas)++;
				*oro -= cura_precio;
				getchar();

			}
		}
		else if (opcion == 'd'){
			if (*oro < X2_precio){
				printf("Oro insuficiente\n");
				getchar();

			}
			else{
				printf("Hascomprado Daño X2\n");
				(*cant_X2)++;
				*oro -= X2_precio;
				getchar();

			}
		}
		else if (opcion == 'x'){
			return;
		}
		else{
			printf("Opción inválida\n");
		}

		system("clear");
	}
}