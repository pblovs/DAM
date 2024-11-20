#include <stdio.h>
#include <stdlib.h>

void printValor(void * ptr, char tipo){

	switch(tipo){
		case 'd' :
			printf("Double %lf\n", * (double *)ptr); //Casting: convertir una variable de un tipo a otro, con el (double*) cambias el tipo y el * de antes es para acceder al contenido
			break;

		case 'i':
			printf("Entero %d\n", * (int *)ptr);
			break;

		default:
			printf("Error");
	}
}

int main(){

	double num=2.3;

	void * dir = &num;

	printValor(dir, 'd');
	printValor(dir, 'i');
}
