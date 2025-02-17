#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dragones.h"
#include "Personajes.h"
#include "combate.h"

void turnoDragon(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int nivel){

	printf("\nTURNO DEL DRAGÓN.\n");
	int ataqueDragon = calcularAtaqueDragon(dragones, nivel);
	Personajes[PersonajeElegido].vida -= ataqueDragon;
	printf("Has recibido %d de daño.\n", ataqueDragon);
	printf("Vida: %d hp\n", Personajes[PersonajeElegido].vida);
}

void turnoJugador(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int nivel){

	int ataque;
	int ataquePersonaje = calcularAtaquePersonaje(Personajes, PersonajeElegido);
	printf("\nTU TURNO.\n");
	printf("Elige un ataque. ATAQUE 1 (1), ATAQUE 2 (2) : ");
	scanf("%d", &ataque);

	if (ataque == 1){
		dragones[nivel].vida -= Personajes[PersonajeElegido].ataque1;
		printf("El dragón ha recibido %d de daño.\n", Personajes[PersonajeElegido].ataque1);
		printf("El dragón tiene %d de vida\n", dragones[nivel].vida);
	}
	else if(ataque == 2){
		dragones[nivel].vida -= ataquePersonaje;
		printf("El dragón ha recibido %d de daño.\n", ataquePersonaje);
		printf("El dragón tiene %d de vida\n", dragones[nivel].vida);
	}
}

void combate(Dragon dragones[], Personaje Personajes[], int cantPersonajes, int cantDragones, int PersonajeElegido, int *nivel){

	printf("\nEMPIEZA EL COMBATE\n");

	printf("%s VS %s", Personajes[PersonajeElegido].nombre, dragones[nivel].nombre);

	while(Personajes[PersonajeElegido].vida > 0 && dragones[nivel].vida > 0){

		turnoJugador(dragones, Personajes, cantPersonajes, cantDragones, PersonajeElegido, nivel);
		
		turnoDragon(dragones, Personajes, cantPersonajes, cantDragones, PersonajeElegido, nivel);
		
	}

	if (dragones[nivel].vida <= 0){
			printf("\nHas matado al %s.\n", dragones[nivel].nombre);
			cantDragones--;
			if(cantDragones == 0){
				printf("HAS GANADO\n");
			}
			*nivel++;
	}

	if (Personajes[PersonajeElegido].vida <= 0){
			printf("\n%s ha muerto.\n", Personajes[PersonajeElegido].nombre);
			Personajes[PersonajeElegido].estado = 0; //pasa a estar muerto
			if(cantPersonajes == 0){
				printf("GAME OVER\n");
			}
			PersonajeElegido = ElegirPersonaje(Personajes);
	}
}