#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	struct dias {
		double temperatura;
		char nombre[10]; 
	};

int main(){

	struct dias semana[8] ;

	strcpy(semana[0].nombre, "Lunes");
	strcpy(semana[1].nombre, "Martes");
	strcpy(semana[2].nombre, "Miércoles");
	strcpy(semana[3].nombre, "Jueves");
	strcpy(semana[4].nombre, "Viernes");
	strcpy(semana[5].nombre, "Sábado");
	strcpy(semana[6].nombre, "Domingo");

	for (int i = 0; i<7; i++){
		printf("Temperatura del %s: ", semana[i].nombre);
		scanf("%lf", &semana[i].temperatura);
	}
}
	

