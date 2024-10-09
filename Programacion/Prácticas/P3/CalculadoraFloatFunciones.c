#include <stdio.h>
#include <stdlib.h>

float suma(float a, float b){
	

	float resultado_suma = a + b;
	printf("El resultado de la suma es: %f\n", resultado_suma);
	return 0;
}

float resta(float a, float b){

	float resultado_resta = a - b;
	printf("El resultado de la resta es: %f\n", resultado_resta);
	return 0;
}

float mult(float a, float b){
	
	float resultado_mult = a * b;
	printf("El resultado de la mult es: %f\n", resultado_mult);
	return 0;
}

float divi(float a, float b){

	float resultado_divi = a/b;
	printf("El resultado de la división es: %f\n", resultado_divi);
	return 0;
}


int main(){
	float ent1, ent2;
	printf("Introduce un numero: ");
	scanf("%f", &ent1);
	printf("Introduce un numero: ");
	scanf("%f", &ent2);

	suma(ent1, ent2);
	resta(ent1, ent2);
	mult(ent1, ent2);
	divi(ent1, ent2);
	return 0;
}

