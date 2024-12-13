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

	for(int i = 0; i < tam; i++){
		printf("%d\n", p[i]);
	}

	free(p);

}