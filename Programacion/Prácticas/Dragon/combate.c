#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dragones.h"
#include "Personajes.h"
#include "combate.h"

void turnoDragon(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int i){

	printf("\nTURNO DEL DRAGÓN.\n");
	int ataqueDragon = calcularAtaqueDragon(dragones, i);
	Personajes[PersonajeElegido].vida -= ataqueDragon;
	printf("Has recibido %d de daño.\n", ataqueDragon);
	printf("Vida: %d hp\n", Personajes[PersonajeElegido].vida);
}

void turnoJugador(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int i){

	int ataque;
	int ataquePersonaje = calcularAtaquePersonaje(Personajes, PersonajeElegido);
	printf("\nTU TURNO.\n");
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

	printf("\nEMPIEZA EL COMBATE\n");

	int i = 0;

	while(cantPersonajes > 0 && cantDragones > 0){

		turnoJugador(dragones, Personajes, cantPersonajes, cantDragones, PersonajeElegido, i);
		if (dragones[i].vida <= 0){
			printf("\nHas matado al %s.\n", dragones[i].nombre);
			cantDragones--;
			if(cantDragones == 0){
				printf("HAS GANADO\n");
				return ;
			}
			else if (cantDragones > 0) {  // Solo aumentamos i si quedan dragones vivos
        		i++;
    		}
		}

		turnoDragon(dragones, Personajes, cantPersonajes, cantDragones, PersonajeElegido, i);
		if (Personajes[PersonajeElegido].vida <= 0){
			printf("%s ha muerto.\n", Personajes[PersonajeElegido].nombre);
			Personajes[PersonajeElegido].estado = 0;
			cantPersonajes--;
			if(cantPersonajes == 0){
				printf("GAME OVER\n");
				return ;
			}
			PersonajeElegido = ElegirPersonaje(Personajes);
		}
	}
}