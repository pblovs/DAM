#include <stdio.h>
#include <stdlib.h>

char capitalizar(char minus){
	char mayus = minus - 32;
	printf("La letra %c en mayúscula es %c\n", minus, mayus);
	return 0;
}

int main(){
	char letra_minuscula;
	printf("Introduce una letra en minúscula: ");
	scanf("%c", &letra_minuscula);

	capitalizar(letra_minuscula);
}
