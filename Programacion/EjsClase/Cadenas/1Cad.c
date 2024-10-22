#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char str1[100];
	printf(" Introduce una palabra: ");
	fgets(str1, sizeof(str1), stdin);

	printf("Que posicion desea modificar: ");
	int pos;
	scanf(" %d", &pos);

	printf("Que caracter desea poner: ");
	char a;
	scanf(" %c", &a);

	str1[pos] = a;

	printf ("La nueva palabra es: %s", str1);

	return EXIT_SUCCESS;
}
