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

		printf("INtroduce la edad ");
		scanf("%d", &edad);
		printf("Introduce la nota ");
		scanf("%f", &nota);
		printf("INtroduce el nombre ");
		scanf("%s", nombre);

		inicializar(&listado[i] , nombre, edad, nota);
	}

	for(int i = 0; i < num; i++){
		printf("Estudiante %d\n", i);
		printf("Edad: %p\n", &listado[i].edad);
	}
}
