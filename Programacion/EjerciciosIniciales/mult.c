#include <stdio.h>
#include <stdlib.h>

int main(){

	int a;
	int b;
	int res;				        
	printf("INTRODUCE EL PRIMER DIGITO: ");
	scanf("%d",&a);
	printf("INTRODUCE EL SEGUNDO DIGITO: ");
	scanf("%d",&b);
	res = a * b;		
	printf("EL RESULTADO DE LA MULTIPLICACION ES:  %d\n ", res);
	return 0;
}
