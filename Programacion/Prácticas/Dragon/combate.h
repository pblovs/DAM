#ifndef COMBATE_H
#define COMBATE_H
#define RESET "\x1b[0m"

void turnoDragon(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel);
void turnoJugador(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel);
void combate(Dragon dragones[], Personaje Personajes[], int *cantPersonajes, int *cantDragones, int PersonajeElegido, int *nivel);

#endif