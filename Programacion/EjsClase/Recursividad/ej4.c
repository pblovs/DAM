#include <stdio.h>
#include <stdlib.h>

int numTriangulares(int n);

int main(){
	
	int n;
	printf("Introduce un número: ");
	scanf("%d", &n);

	numTriangulares(n);
	printf("%d", numTriangulares(n));

	
}

int numTriangulares(int n){

	if(n == 0){
		return 0;
	}
	
	int resultado = n + numTriangulares(n-1);
	return resultado;
}