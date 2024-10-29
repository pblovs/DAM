#include <stdio.h>
#include <stdlib.h>

int main(){

	int num, win;
	win = rand() % 101;
	
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
