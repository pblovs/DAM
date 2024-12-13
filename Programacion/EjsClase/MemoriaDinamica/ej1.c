#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Introduce un tamaño: ");
	int tam;
	scanf("%d", &tam);
	
	int *p = (int *)malloc(sizeof(int) * tam);

	if (p != NULL){
		for(int i = 0; i < tam; i++){
			p[i] = i * 2;
			printf("%d\n", p[i]);
		}
	}
	else {
		printf("Error");
		return EXIT_FAILURE;
	}
	printf("Segunda parte\n");
	p = (int*)realloc(p, sizeof(int) * (tam*2));
	if (p != NULL){
		for(int i = 0; i < (tam*2); i++){
			p[i+tam] = (2*i)+1;
			printf("%d\n", p[i]);
		}
	}
	else {
		printf("Error");
		return EXIT_FAILURE;
	}


	free(p);

}