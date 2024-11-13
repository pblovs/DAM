#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *a, int *b, int *c){
	
	*c = *b;
	*b = *a;
	*a = *c;
}

int main(){

	int a = 10;
	int b = 20;
	int c = 0;

	intercambiar(&a, &b, &c);

	printf("valor de b: %d\n", b);
	printf("valor de a: %d\n", a);
}
