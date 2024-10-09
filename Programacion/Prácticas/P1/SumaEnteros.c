#include <stdio.h>
#include <stdlib.h>

int main(){
	int suma, resta, mult, :div, ent1, ent2;
	
	printf("Introduce un entero:\n");
	scanf("%d", &ent1);
	printf("Introduce un entero:\n");
	scanf("%d", &ent2);

	suma = ent1 + ent2;
	resta = ent1 - ent2;
	mult = ent1 * ent2;
	div = ent1 / ent2;

	int resultado_suma = suma;
	int resultado_resta = resta;
	int resultado_mult = mult;
	int resultado_div = div;

	printf("El resultado de la suma es: %d\n", resultado_suma);
	printf("El resultado de la resta es: %d\n", resultado_resta);
	printf("El resultado de la mult es: %d\n", resultado_mult);
	printf("El resultado de la div es: %d\n", resultado_div);

	return 0;
}
