#include <stdio.h>
#include <stdlib.h>

int main(){

	char str1[100];
	printf("Introduce una palabra: ");
	scanf("%s", str1); //no se pone & en los strings
	
	int pos;
	printf("Introduce el nº de posición que quieres cambiar: ");
	scanf("%d", &pos);

	char letra;
	printf("Introduce la letra que quieres poner: ");
	scanf(" %c", &letra); //se pone el espacio delante para que no guarde el \n

	str1[pos] = letra; //selecciona la posicion que has elegido dentro de la cadena y la cambia por la letra 

	printf("La nueva palabra es: %s\n", str1);
}
