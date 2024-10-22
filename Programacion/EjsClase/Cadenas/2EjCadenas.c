#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

	char str1[100];
	printf("Introduce una palabra: ");
	scanf("%s", str1); //no se pone & en los strings

	char letra;
	printf("Introduce la letra que quieres poner: ");
	scanf(" %c", &letra); //se pone el espacio delante para que no guarde el \n
	
	int pos = strlen(str1); //La posicion = la longitud de la palabra

        str1[pos] = letra;	

	printf("La nueva palabra es: %s\n", str1);
}
