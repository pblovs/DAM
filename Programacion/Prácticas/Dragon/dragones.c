#include <stdio.h>
#include <string.h>
#include "dragones.h"

void inicializarDragones(Dragon dragones[], int *cantidad) {

    strcpy(dragones[0].nombre, "dragón de fuego");
    dragones[0].vida = 250;
    dragones[0].ataque = rand () % 21; // entre 0 y 20;

    strcpy(dragones[1].nombre, "dragón de hielo");
    dragones[1].vida = 300;
    dragones[1].ataque = rand () % 31 ; // entre 0 y 30;

    strcpy(dragones[2].nombre, "dragón eléctrico");
    dragones[2].vida = 200;
    dragones[2].ataque = rand () % 51 ; // entre 0 y 50;

    *cantidad = 3; 
}

void mostrarDragones(Dragon dragones[], int cantidad) {
    printf("Dragones disponibles:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s (Vida: %d, Ataque: %d)\n", i + 1, dragones[i].nombre, dragones[i].vida, dragones[i].ataque);
    }
}







