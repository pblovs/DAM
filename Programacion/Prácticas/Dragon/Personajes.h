#ifndef PERSONAJES_H
#define PERSONAJES_H

typedef struct{

	char nombre[30];
	int ataque1;
	int ataque2;
	int vida;
	int vidaMax;
	int estado;

}Personaje;

void InicializarPersonajes(Personaje personajes[], int* cantidad);
int calcularAtaquePersonaje(Personaje personajes[], int i);
void MostrarPersonajes(Personaje personajes[], int * cantidad);
int ElegirPersonaje(Personaje personajes[]);
void simboloPersonaje(Personaje personajes[], int PersonajeElegido);

#endif


