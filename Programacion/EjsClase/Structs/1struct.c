#include <stdio.h>
#include <stdlib.h>

	struct dias {
		float temperatura;
		char nombre[10]; 
	}

int main(){

	struct dias semana[8] ;

	semana[0].nombre = "Lunes";
	semana[1].nombre = "Martes";
	semana[2].nombre = "Miércoles";
	semana[3].nombre = "Jueves";
	semana[4].nombre = "Viernes";
	semana[5].nombre = "Sábado";
	semana[6].nombre = "Domingo";

	for (int i = 0; i<7; i++){
		printf("Temperatura del %s: ", semana[i].nombre);
		scanf("%f", semana[i].temperatura);
	}
}
	

