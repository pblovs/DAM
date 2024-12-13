#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Introduce un tamaño: ");
	int tam;
	scanf("%d", &tam);
	
	int *p = (int *)malloc(sizeof(int) * tam);

	if (p != NULL){
		for(int i = 0; i < tam; i++){
			printf("Introduce el valor %d: ", i);
			scanf("%d", &p[i]);
		}
	}
	else {
		printf("Error");
		return EXIT_FAILURE;
	}

	printf("¿Cuantos quieres añadir?: ");
	int tam2;
	scanf("%d", &tam2);

	p = (int*)realloc(p, sizeof(int) * (tam + tam2));
	if (p != NULL){
		for(int i = tam; i < (tam + tam2); i++){
			printf("Introduce el valor %d: ", i);
			scanf("%d", &p[i]);
		}
	}
	else {
		printf("Error");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < (tam+tam2); ++i)
	{
		printf("%d\n", p[i]);
	}


	free(p);

}