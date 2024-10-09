#include <stdio.h>
#include <stdlib.h>

void es_vocal(char letra){
        printf("introduce una letra: ");
        scanf("%c", &letra);
        scanf("%c", &letra);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
	printf("La letra es una vocal\n");}
	else { printf("La letra no es una vocal\n");}
}

void calcular_area_figura(){
	printf("Elige una figura para calcular su área (círculo = 1,cuadrado = 2): ");
	int opcion;
	double Acirculo, Acuadrado, radio, lado;
	scanf("%d", &opcion);
	if (opcion == 1){ 
		printf("Introduce el radio: ");
		scanf("%lf", &radio);
		Acirculo = 3.1416 * radio * radio;
		printf("El área del círculo es %lf\n", Acirculo);
	} else if (opcion == 2) {
		printf("Introduce la longitud del lado: ");
		scanf("%lf", &lado);
		Acuadrado = lado * lado;
		printf("El área del cuadrado es %lf\n", Acuadrado);
	} else {printf("Error, elige una opcion entre 1 y 2");}
}

double calcular_promedio_tres_num(double num1, double num2, double num3){
	printf("Introduce 3 numeros: ");
	scanf("%lf", &num1);
	scanf("%lf", &num2);
	scanf("%lf", &num3);
	double promedio3 = (num1 + num2 + num3) / 3;
	printf("El promedio es: %lf", promedio3);
}

double calcular_promedio_cuatro_num(double num1, double num2, double num3, double num4){
	printf("Introduce 4 numeros: ");
	scanf("%lf", &num1);
	scanf("%lf", &num2);
	scanf("%lf", &num3);
	scanf("%lf", &num4);
	double promedio4 = (num1 + num2 + num3 + num4) / 4;
	printf("El promedio es: %lf", promedio4);
}

void calcular_promedio(){
	int valores;
	double n1, n2, n3, n4;
	printf("De cuántos valores quieres hacer el promedio, 3 o 4? ");
	scanf("%d", &valores);
	if (valores == 3){ 
		calcular_promedio_tres_num( n1, n2, n3);}
	else if (valores == 4){
	       	calcular_promedio_cuatro_num(n1, n2, n3, n4);}
	else { printf("Error, elige un valor entre 3 y 4"); }
}

void convertir_hora_24_a_12(){
	printf("Introduce una hora en formato 24h: ");
	int hora;
	scanf("%d", &hora);
	if (hora >= 13 && hora <= 24){
		hora -= 12;
		printf("Son las %d\n", hora);}
	else if (hora <=12) {
		printf("Son las %d\n", hora);}
	else { printf("Introduce una hora válida\n");}
}

void es_primo(){
	printf("Introduce un número menor de 10: ");
	int num;
	scanf("%d", &num);
	if (num >= 10){
		printf("Introduce uno menor que 10\n");}
	else if (num == 1){
		printf("El 1 no es primo");}
	else if (num == 2){
		printf("El 2 es primo");}
	else { for (int i=2;i<num;i++){
		if (num % i == 0){
			printf("El numero %d no es primo\n", num);
		        return ;}
		else { printf("EL numero %d es primo\n", num);
		       return ;}
	}
	}
}

void comparar_3_numeros(){
	int mayor;
	int array[];
	printf("Introduce 3 números: ");
	for (int i=0;i<3;i++){
	       scanf("%d", &array[i]);}
	for (int i=1;i<3;i++){
		if (array[0] > array[i]){
			mayor = array[0];
	



int main(){
	
	int funciones;
	printf("Selecciona una opción: ");
	scanf("%d", &funciones);

	switch(funciones){

		case 1: 
			char letra2;
			es_vocal(letra2);
			break;
		case 2:
			calcular_area_figura();
			break;
		case 3:
			calcular_promedio();
			break;
		case 4:
			convertir_hora_24_a_12();
			break;
		case 5:
			es_primo();
			break;



		}
}
