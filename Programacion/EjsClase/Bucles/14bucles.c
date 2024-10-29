#include <stdio.h>
#include <stdlib.h>

int main(){

	int num, contador;

	printf("Introduce un numero: ");
	scanf("%d", &num);

	while (num > 0){
		num = num/10; //divido el numero entre 10
		contador++; //sumo 1 al contador hasta que llegue a 0
	}
	printf("Tiene %d digitos\n", contador);
}
			

