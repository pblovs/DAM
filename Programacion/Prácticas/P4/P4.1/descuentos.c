#include <stdio.h>
#include <stdlib.h>

int main(){

	float monto, montoFinal;
	char rol;

	printf("Introduce el monto: ");
	scanf("%f", &monto);
	printf("Introduce el rol: ");
	scanf("%c", &rol);
	scanf("%c", &rol);   //se ponen 2 scanf para quitar el salto de linea
	if (rol == 'e') {    //si el rol es estudiante
		montoFinal = monto - (monto * 0.15);   //calcula el monto final con el 15% de descuento
		printf(" El monto final es %.2f\n", montoFinal);

	} else if (rol == 'p') {    //si el rol es profesor
		montoFinal = monto - (monto * 0.1);   //calcula el monto final con el 10% de descuento
		printf("El monto final es %.2f\n", montoFinal);
		
	} else { printf("No tiene descuento, el monto final es %.2f\n",monto);  //si no es ninguno de esos roles no tiene descuento
	}
}

