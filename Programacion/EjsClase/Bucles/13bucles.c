#include <stdio.h>
#include <stdlib.h>

int main(){

	int num, digito;

	printf("INtroduce un numero: ");
	scanf("%d", &num);

	while (num > 0){
		digito = num % 10; //aquí guardo el ultimo digito
		printf("%d", digito);
		num = num/10; //divido entre 10 para pasar al digito anterior
	}
}
			

