#include <stdio.h>
#include <stdlib.h>

int profundidad(char * cadena, int *balance);

int main(){

	char cadena[20];
	printf("Introduce una cadena de parentesis: ");
	scanf("%s", cadena);

	int balance = 0;

	profundidad(cadena, &balance);

	if(balance == 0){
		printf("todos los parentesis se cierran");
	}
	else{
		printf("No se cierran todos");
	}

}

int profundidad(char * cadena, int *balance){
	
	if(*cadena == '\0'){
		return *balance;
	}

	if(*cadena == '('){
		(*balance)++;
		return profundidad(cadena + 1, balance);
	}
	else if(*cadena == ')'){
		(*balance)--;
		return profundidad(cadena + 1, balance);
	}
	else {
		return profundidad(cadena + 1, balance);
	}
}