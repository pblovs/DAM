#include <stdio.h>
#include <stdlib.h>

int main(){

	float x = 10;
	float *p;

	p = &x;

	printf("Valor de x :%f \n", x);
	printf("Direccion de x: %p\n", &x);
	printf("Valor de p: %f\n", *p);
	printf("Direccion de p: %p\n", &p);
}
