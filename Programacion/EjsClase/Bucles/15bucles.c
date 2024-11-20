#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int num, win;
	srand(time(NULL)); //Cada segundo
	win = rand() % 100 + 1; //Da números aleatorios entre 1 y 100
	
	do{
		printf("Adivina el número del 1 al 100:");
		scanf("%d", &num);
		if (num == win)
			printf("Ya era horaaa ACERTASTEE\n");
		else
		       printf("Sigue intentando crack\n");
	}	
	while (num != win);
}
