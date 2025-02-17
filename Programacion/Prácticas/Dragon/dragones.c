#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dragones.h"

void inicializarDragones(Dragon dragones[], int *cantidad) {

    strcpy(dragones[0].nombre, "dragón de fuego");
    dragones[0].vida = 250;
    dragones[0].ataque = 20; // entre 0 y 20;

    strcpy(dragones[1].nombre, "dragón de hielo");
    dragones[1].vida = 300;
    dragones[1].ataque = 30; // entre 0 y 30;

    strcpy(dragones[2].nombre, "dragón eléctrico");
    dragones[2].vida = 200;
    dragones[2].ataque = 50; // entre 0 y 50;

    *cantidad = 3; 
}


int calcularAtaqueDragon(Dragon dragones[], int nivel){

    int ataque = rand() % (dragones[nivel].ataque + 1);
    return ataque;
}


void mostrarDragones(Dragon dragones[], int cantidad) {
    printf("\nDRAGONES:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s (Vida: %d, Ataque: 0-%d)\n", i + 1, dragones[i].nombre, dragones[i].vida, dragones[i].ataque);
    }
}







