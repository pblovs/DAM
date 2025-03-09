#ifndef COMBATE_H
#define COMBATE_H
#define RESET "\x1b[0m"

void turnoDragon(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel);
void turnoJugador(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel, int *cant_curas, int *cant_X2);
void combate(Dragon dragones[], Personaje Personajes[], int *cantPersonajes, int *cantDragones, int PersonajeElegido, int *nivel, int *oro, int *cant_curas, int *cant_X2);

#endif