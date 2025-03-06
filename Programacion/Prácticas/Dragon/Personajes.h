#ifndef PERSONAJES_H
#define PERSONAJES_H
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"


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
char getch();
int ElegirPersonaje(Personaje personajes[]);
void simboloPersonaje(Personaje personajes[], int PersonajeElegido);
void personajeVSdragon(int PersonajeElegido);

#endif


