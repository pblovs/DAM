#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int CalcularRaiz(double raiz, int valor){
	printf("Introduce un número para calcular su raiz: ");
	scanf("%d", &valor);
        raiz = sqrt(valor); 
	printf("el resultado de %d es: %lf\n", valor, raiz);
	return 0;
}

int CalcularArea(double radio, double area){

	printf("Introduce el radio para calcular el área: ");
	scanf("%lf", &radio);
	area = radio * radio * M_PI; //M_PI esta definido en math.h
	printf("El área es %lf\n: ", area);			     
	return 0;
}

	
int main(){
	
	
	CalcularRaiz();
	CalcularArea();
	return 0;
}
