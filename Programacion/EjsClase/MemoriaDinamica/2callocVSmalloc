#include <stdio.h>
#include <stdlib.h> // Para malloc, free, etc.

int main() {
    int n = 5;
    int *arr = (int *)calloc(n, sizeof(int)); // Reserva e inicializa a cero
    if (arr == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }
    // arr[i] estará inicialmente en 0
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}

