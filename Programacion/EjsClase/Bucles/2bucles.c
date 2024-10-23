#include <stdio.h>
#include <stdlib.h>

int main(){

	int i;
	for (i=0; i<19; i+=2){
		printf("%d,", i);
	}
	printf("%d.", i);
}
