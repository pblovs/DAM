#include <stdio.h>
#include <stdlib.h>

int contarPares(int num, int * contador);

int main(){
	
	int contador = 0;
	int numero;
	printf("Introduce un numero: ");
	scanf("%d", &numero);

	contarPares(numero, &contador);

	printf("Hay %d dígitos pares.\n", contador);
}

int contarPares(int num, int * contador){

	int digito = num % 10;

	if(digito % 2 == 0){
		(*contador)++;
	}
	return contarPares(num/10, contador);
}
