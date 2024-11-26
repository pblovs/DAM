#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMBRE 20

	typedef struct{
		char nombre[MAX_NOMBRE];
		int edad;
		float nota;
	}Estudiante;

void inicializar(Estudiante * est_rellenar, char * nombre, int edad, float nota){

	est_rellenar->edad = edad;
	strcpy(est_rellenar->nombre, nombre);
	est_rellenar->nota = nota;
}

void cumpleanios(Estudiante * cumpleanero) {
	cumpleanero->edad++;
}

int main(){

	Estudiante listado[MAX_NOMBRE]; //aqui reservamos la memoria
	int num;

	int edad;
	float nota;
	char nombre[MAX_NOMBRE];	

	printf("%p\n", listado);
	printf("%lu\n", sizeof(listado));

	printf("¿Cuantos estudiantes desea introducir? ");
	scanf("%d", &num);
	
	for(int i=0; i < num; i++){
		
		printf("Estudiante %d\n", i+1);		
		printf("Introduce el nombre ");
		scanf("%s", nombre);
		printf("Introduce la edad ");
		scanf("%d", &edad);
		printf("Introduce la nota ");
		scanf("%f", &nota);
		printf("\n");


		inicializar(&listado[i] , nombre, edad, nota);
	}

	for(int i = 0; i < num; i++){
		printf("Estudiante %d\n", i+1);
		printf("Nombre: %s\n", listado[i].nombre);
		printf("Nota: %.2f\n", listado[i].nota);
		printf("Edad: %d\n\n", listado[i].edad);
	}

	cumpleanios(&listado[1]);
	printf("Edad: %d\n\n", listado[1].edad);
}
