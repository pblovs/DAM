#include <stdio.h>
#include <stdlib.h>

int main(){

	int * dir = NULL;
	printf("Direccion de memoria: %p\n", dir);  //core dumped
	printf("Contenido de esa direccion: %d\n", *dir);

}
