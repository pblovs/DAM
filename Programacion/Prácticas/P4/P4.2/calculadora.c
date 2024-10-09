#include <stdio.h>
#include <stdlib.h>

int main(){
		
		float num1, num2, res;
			char operador;
				printf("Introduce el primer número: ");
					scanf("%f", &num1);
						printf("Introduce el segundo número: ");
							scanf("%f", &num2);
								printf("Introduce un operador (+, -, *, /): ");
									scanf("%c", &operador);
										scanf("%c", &operador);


											switch(operador)
													{
																case '+':
																				float suma = num1 + num2;
																							printf("El resultado de la sumas es %.2f\n",suma);
																										break;
																												case '-':
																													float resta = num1 - num2;
																																printf("El resultado de la resta es %.2f\n", resta);
																																			break;
																																					case '*':
																																						float mult = num1 * num2;
																																									printf("El resultado de la multiplicación es %.2f\n", mult);
																																												break;
																																														case '/':
																																															float divi = num1 / num2;
																																																		printf("El resultado de la división es %.2f\n", divi);
																																																					break;
																																																							default: printf("El operador no es válido\n");
																																																								 	}
												return 0;
}



