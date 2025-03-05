#ifndef MAPA_H
#define MAPA_H
#define YELLOW "\x1b[33m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#include "Personajes.h"
#include "dragones.h"

void mapa(Dragon dragones[], int *cantDragones, Personaje personajes[], int *cantPersonajes, int PersonajeElegido);

#endif
