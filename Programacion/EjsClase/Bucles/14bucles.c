#include <stdio.h>
#include <stdlib.h>

int main(){

	int num, contador, digito;

	printf("INtroduce un numero: ");
	scanf("%d", &num);

	while (num > 0){
		digito = num%10;
		num = num/10;
		contador++;
	}
	printf("Tiene %d digitos\n", contador);
}
			

