#ifndef DRAGONES_H
#define DRAGONES_H

typedef struct {
    char nombre[50];
    int vida;
    int ataque;
} Dragon;

void inicializarDragones(Dragon dragones[], int *cantidad);
int calcularAtaqueDragon(Dragon dragones[], int *nivel);
void mostrarDragones(Dragon dragones[], int cantidad);

#endif
