#include <stdio.h>                                                    
#include <stdlib.h>                                                                                                                       
int main(){                                                          
	        float suma, resta, mult, div, ent1, ent2;                                                                                          
		        printf("Introduce un entero:\n");                            
			        scanf("%f", &ent1);                                          
				        printf("Introduce un entero:\n");                            
					        scanf("%f", &ent2);                                                                                                               

						        suma = ent1 + ent2;                                          
							        resta = ent1 - ent2;                                         
								        mult = ent1 * ent2;                                          
									        div = ent1 / ent2;                                           
										                                                                     

										float resultado_suma = suma;                                   
											        float resultado_resta = resta;                                 
												        float resultado_mult = mult;                                   
													        float resultado_div = div;                                     
														                                                                     
														        printf("El resultado de la suma es: %f\n", resultado_suma);  
															        printf("El resultado de la resta es: %f\n", resultado_resta);
																        printf("El resultado de la mult es: %f\n", resultado_mult);  
																	        printf("El resultado de la div es: %f\n", resultado_div);    
																		                                                                     
																		        return 0;                                                    
}                 
