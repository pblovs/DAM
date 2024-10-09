#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
		float monto;
			float montoFinal;
				
				char rol;

					printf("Introduce el monto: ");
						scanf("%f", &monto);
							printf("Introduce el rol: ");
								scanf("%c", &rol);
									scanf("%c", &rol);

										if (rol == 'e'){
													montoFinal = monto - (monto * 0.15);
															printf(" El monto final es %.2f\n", montoFinal);
																} else if (rol == 'p'){
																			montoFinal = monto - (monto * 0.1);
																					printf("El monto final es %.2f\n", montoFinal);
																						} else { printf("No tiene descuento, el monto final es %f\n",monto);
																								}
}

