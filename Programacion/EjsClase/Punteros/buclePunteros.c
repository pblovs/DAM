#include <stdio.h>
#include <stdlib.h>

int main(){

	int a[5] = {1, 2, 3, 4, 5};
	
	int elementos = sizeof(a)/sizeof(int); // 20/4=5

	for (int * p = a; p <= &a[elementos - 1]; p++){
		printf("%d\n", *p);
	}
}
