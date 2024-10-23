#include <stdio.h>
#include <stdlib.h>

int main(){

	int n;
	printf("Introduce la longitud del lado: ");
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
