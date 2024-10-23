#include <stdio.h>
#include <stdlib.h>

int main(){

	int n;
	printf("Introduce un numero: ");
	scanf("%d", &n);

	int contador = 0;

	for (int i=1; i<=n; i++){
		if (n % i == 0){
			contador ++;
		}
	}
	printf("El numero %d tiene %d divisores\n", n, contador);
	return 0;
}


