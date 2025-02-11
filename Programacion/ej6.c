#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cifradoCesar(char * cadena, int tam, int clave);

int main(){
	
	char cadena[20];
	printf("Introduce una cadena: ");
	scanf("%s", cadena);
	int tam = strlen(cadena);

	int clave;
	printf("Introduce una clave de cifrado: ");
	scanf("%d", &clave);

	cifradoCesar(cadena, tam, clave);

	printf("%s", cadena);

}

int cifradoCesar(char * cadena, int tam, int clave){

	if (tam == 0){
		return 0;
	}

	if (clave >= 0 && clave <= 25){
		
		if(cadena[tam-1] == 'z' || cadena[tam-1] == 'Z'){
		cadena[tam-1] = cadena[tam-1] + clave - 26;
		}
		else{
		cadena[tam-1] = cadena[tam-1] + clave;
		}
	}

	else if (clave <= 0 && clave >= -25){
		
		if(cadena[tam-1] == 'a' || cadena[tam-1] == 'A'){
		cadena[tam-1] = cadena[tam-1] + clave + 26;
		}
		else{
		cadena[tam-1] = cadena[tam-1] + clave;
		}
	}

	return cifradoCesar(cadena, tam-1, clave);
}