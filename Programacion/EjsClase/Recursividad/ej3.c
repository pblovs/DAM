#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cuentaVocales(char * cadena, int tam);
int extraeVocales(char * cadena, int tam, char * cadenaVocales, int tamCadVoc);

int main(){
	
	char cadena[25];
	printf("Introduce una cadena: ");
	scanf("%s", cadena);

	int tam = strlen(cadena); 
	int tamCadVoc = cuentaVocales(cadena, tam); //tamaño sin el \0

	char * cadenaVocales = (char*) malloc ((tamCadVoc+1) * sizeof(char)); // +1 para incluir el \0

	if (cadenaVocales == NULL){
		printf("error a reservar memoria\n");
		exit(0);
	}

	extraeVocales(cadena, tam, cadenaVocales, tamCadVoc);

	printf("Cadena de vocales: %s\n", cadenaVocales);

	free(cadenaVocales);
}

int cuentaVocales(char * cadena, int tam){

	int contador = 0;

	for (int i= 0; i < tam; i++){
		if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' ){
		contador++;
		}
	}
	return contador;
}

int extraeVocales(char * cadena, int tam, char * cadenaVocales, int tamCadVoc){

	if (tam == 0){
		return 0;
	}

	if (cadena[tam-1] == 'a' || cadena[tam-1] == 'e' || cadena[tam-1] == 'i' || cadena[tam-1] == 'o' || cadena[tam-1] == 'u' ){ 
		cadenaVocales[tamCadVoc-1] = cadena[tam-1]; // -1 para no contar el \0
		tamCadVoc--;
	}

	return extraeVocales(cadena, tam-1, cadenaVocales, tamCadVoc);

}