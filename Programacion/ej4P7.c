#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(char * cadena, int primero, int ultimo);


int main(){

	char cadena[20];
	printf("Introduce una cadena: ");
	scanf("%s", cadena);

	palindroma(cadena, 0, strlen(cadena) - 1);
}

int palindroma(char * cadena, int primero, int ultimo){

	if(ultimo <= primero){
		printf("Es palindroma\n");
		return 0;
	}

	if(cadena[primero] == cadena[ultimo]){
		palindroma(cadena, primero + 1, ultimo - 1);
	}
	else{
		printf("No es palíndroma\n");
	}
}