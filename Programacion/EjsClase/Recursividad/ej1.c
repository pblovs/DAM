#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarConsonantes(char * cadena, int tam, int * contador);

int main(){
	
	int contador = 0;
	char cadena[20];
	printf("Introduce una cadena: ");
	scanf("%s", cadena);
	int tam = strlen(cadena);

	contarConsonantes(cadena, tam, &contador);

	printf("Hay %d consonantes\n", contador);

}

int contarConsonantes(char * cadena, int tam, int * contador){
	if (tam == 0){
		return 0;
	}

	if(cadena[tam-1] != 'a' && cadena[tam-1] != 'e' && cadena[tam-1] != 'i' && cadena[tam-1] != 'o' && cadena[tam-1] != 'u' ){
		(*contador)++;
	}
	return contarConsonantes(cadena, tam-1, contador);
}