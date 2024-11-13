#include <stdio.h>
#include <stdlib.h>

int main(){

	int a[5] = {10, 20, 30, 40, 50};
	int *p = a+5;
	int suma = 0;

	for (int i=5; i>0; i--){
		suma += *(p - i);
	}
	printf("suma: %d\n", suma);
}


