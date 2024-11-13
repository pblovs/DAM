#include <stdio.h>
#include <stdlib.h>

void incrementarPorReferencia(int *n){ //Aqui usa la misma variable 
	printf("Valor recibido: %d\n", *n);
	(*n)++;
	printf("Valor incrementado: %d\n", *n);
}

void incrementarPorValor(int n){ //Aqui crea una copia de la variable
	printf("Valor recibido: %d\n", n);
	n++;
	printf("Valor incrementado: %d\n", n);
}

int main(){

	int valor = 10;
	incrementarPorReferencia(&valor);
	printf("Valor en el main: %d\n", valor);

	printf("\n");

	int valor2 = 5;
	incrementarPorValor(valor2);
	printf("Valor en el main: %d\n", valor2);
}


