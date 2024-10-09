#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Introduce tu edad: ");
	int edad;
	scanf("%d", &edad);
	if (edad <= 11){      //si tiene menos de 12 años
		printf("Eres un niño\n");
	} else if (edad >= 12 && edad <= 17){     //si tiene entre 12 y 17 años
		printf("Eres un adolescente\n");
	} else if (edad >= 18 && edad <= 64){     //si tiene entre 18 y 64 años
		printf("Eres un adulto\n");
	} else {printf("Eres mayor\n");}      //si es mayor de 64 años
}

