#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Ingresa un número entero: ");
	int num;
	scanf("%d", &num);
	if (num % 2 == 0){    //divide num entre 2 y coge el resto
		printf("El número es par\n");}   // si el resto es 0, el numero es par
	else {printf("El número es impar\n");    //si no da 0 el resto, el numero es impar
	}
}

