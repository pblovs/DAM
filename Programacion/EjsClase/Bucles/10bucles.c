#include <stdio.h>
#include <stdlib.h>

int main(){

	int n;
	printf("Introduce el tamaño del triamgulo: ");
	scanf("%d", &n);

	for (int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){ //hasta el numero de i
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}
