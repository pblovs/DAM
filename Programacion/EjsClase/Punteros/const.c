#include <stdio.h>

int main(){
	int numero = 10;
	int trampa = 30;
	const int const *ptr = &numero;

	printf("Valor: %d\n", *ptr);

	numero = 20;
	printf("Nuevo valor: %d\n", *ptr);

	*ptr = 30;
	printf("Nuevo valor: %d\n", *ptr);

}