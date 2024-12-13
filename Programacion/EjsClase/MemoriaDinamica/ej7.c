//Pide al usuario que introduzca una cadena sin límite fijo, asígnale memoria de forma dinámica y luego imprímela.

#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Introduce un tamaño: ");
	int tam;
	scanf("%d", &tam);


	char *cad = (char *)malloc(sizeof(char) * (tam+1));
	if (cad != NULL){

		printf("Escribe algo: ");
		scanf("%d", &tam); //esto es pq sino no me coje la cadena
		fgets(cad, tam+1, stdin);
		printf("%s\n", cad);
	}
	else{
		printf("Error");
		return EXIT_FAILURE;
	}

	free(cad);

}