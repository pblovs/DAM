#include <stdio.h>
#include <string.h>
#include "dragones.h"
#include "Personajes.h"
#include "combate.h"

void turnoDragon(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int i){

	printf("Turno del Dragón.\n");
	int ataqueDragon = calcularAtaqueDragon(dragones, i);
	Personajes[PersonajeElegido].vida -= ataqueDragon;
	printf("Has recibido %d de daño.\n", ataqueDragon);
	printf("Vida: %d hp\n", Personajes[PersonajeElegido].vida);
}

void turnoJugador(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int i){

	int ataque;
	int ataquePersonaje = calcularAtaquePersonaje(Personajes, PersonajeElegido);
	printf("Es tu turno.\n");
	printf("Elige un ataque. ATAQUE 1 (1), ATAQUE 2 (2) : ");
	scanf("%d", &ataque);

	if (ataque == 1){
		dragones[i].vida -= Personajes[PersonajeElegido].ataque1;
		printf("El dragón ha recibido %d de daño.\n", Personajes[PersonajeElegido].ataque1);
		printf("El dragón tiene %d de vida\n", dragones[i].vida);
	}
	else if(ataque == 2){
		dragones[i].vida -= ataquePersonaje;
		printf("El dragón ha recibido %d de daño.\n", ataquePersonaje);
		printf("El dragón tiene %d de vida\n", dragones[i].vida);
	}
}

void combate(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido){

	printf("EMPIEZA EL COMBATE\n");

	int i = 0;

	while(cantPersonajes > 0 && cantDragones > 0){

		turnoJugador(dragones, Personajes, cantPersonajes, cantDragones, PersonajeElegido, i);
		if (dragones[i].vida <= 0){
			printf("Has matado al %s.\n", dragones[i].nombre);
			i++;
			cantDragones--;
		}

		turnoDragon(dragones, Personajes, cantPersonajes, cantDragones, PersonajeElegido, i);
		if (Personajes[PersonajeElegido].vida <= 0){
			printf("%s ha muerto", Personajes[PersonajeElegido].nombre);
			cantPersonajes--;
			PersonajeElegido = ElegirPersonaje();
		}
	}
	
	if(cantPersonajes == 0){
		printf("GAME OVER\n");
		return ;
	}
	else if(cantDragones == 0){
		printf("HAS GANADO\n");
		return ;
	}
}