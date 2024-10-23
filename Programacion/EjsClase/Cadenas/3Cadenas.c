#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char cad1[100];
	char cad2[100];

	printf("Introduce una palabra: ");
	scanf("%s", cad1);

	int res = strcmp(cad1, cad2);

	if (res == 0){
		printf("Las palabras son iguales\n");
	}
	else { 
		printf("Las palabras son distintas\n");
	}

	if (cad1[0] == cad2[0]) {
		printf("Los primeros caracteres son iguales\n");     
	}
	else if (cad1[1] == cad2[1]){
		printf("Los segundos caracteres son iguales\n");     
	}

	do {
		if (res < 0){
			printf("La cadena 1 es menor que la 2\n");
			return 0;
		}
		else if (res > 0){
			printf("La cadena 1 es mayor que la 2\n");
			return 0;
		}
	} while (res != 0);



}
