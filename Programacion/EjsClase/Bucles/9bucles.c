#include <stdio.h>
#include <stdlib.h>

int main(){

	int fibo, a = 0, b = 1;
	for (int i=1; i<=10; i++){
		printf("%d ", a);
		fibo = a + b;
		a = b;
		b = fibo;
	}
}
/* fibo = 0 + 1
 * a = 1
 * b = 0 + 1
 * --------------------------------------------
 *  fibo = 1 + (0+1) = 2
 *  a = (0+1)
 *  b = 1 + (0+1) = 2
 *  -------------------------------------------
 *  fibo = 1 + 2
 *  a = 2
 *  b = 1 + 2 = 3
 *  -------------------------------------------
 *  fibo = 2 + 3 = 5
 *  a = 3
 *  b = 5
 *  -------------------------------------------
 *  fibo = 3 + 5 = 8
 *  a = 5
 *  b = 8
 *  -------------------------------------------
 *  ...
 */
		
		



		


		
