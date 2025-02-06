#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int palindroma(char * cadena, int primero, int ultimo);


int main(){

	char cadena[20];
	printf("Introduce una cadena: ");
	scanf("%s", cadena);

	if (palindroma(cadena, 0, strlen(cadena) - 1)){
		printf("Es palindroma");
	}else{
		printf("No es palindroma");
	}
}

int palindroma(char * cadena, int primero, int ultimo){

	if(ultimo <= primero){
		return true;
	}

	if(cadena[primero] == cadena[ultimo]){
		return palindroma(cadena, primero + 1, ultimo - 1);
	}
	else{
		return false;
	}
}