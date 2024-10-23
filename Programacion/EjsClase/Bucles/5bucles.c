#include <stdio.h>
#include <stdlib.h>

int main(){

	int n;
	printf("Introduce un numero para calcular su factorial: ");
	scanf("%d", &n);

	int factorial = 1;

	for (int i=n; i>0; i--){
		  factorial *= i;
	}
	printf("El resultados es %d\n", factorial);

}

