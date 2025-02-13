
typedef struct {
    char nombre[50];
    int vida;
    int ataque;
} Dragon;

void inicializarDragones(Dragon dragones[], int *cantidad);
int calcularAtaqueDragon(Dragon dragones[], int i);
void mostrarDragones(Dragon dragones[], int cantidad);

