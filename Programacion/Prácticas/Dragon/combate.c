#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dragones.h"
#include "Personajes.h"
#include "combate.h"

void turnoDragon(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel){

	printf("\x1b[38;5;13m\nTURNO DEL DRAGÓN.\n \n\x1b[0m");
	int ataqueDragon = calcularAtaqueDragon(dragones, nivel);
	Personajes[PersonajeElegido].vida -= ataqueDragon;
	printf("Has recibido %d de daño.\n", ataqueDragon);
	printf("Vida: %d hp\n", Personajes[PersonajeElegido].vida);
}

void turnoJugador(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel){

	int ataque;
	int ataquePersonaje = calcularAtaquePersonaje(Personajes, PersonajeElegido);
	printf("\x1b[38;5;12m\nTU TURNO.\n\n\x1b[0m");
	printf("Elige un ataque. ATAQUE 1 (1), ATAQUE 2 (2) : ");
	scanf("%d", &ataque);

	if (ataque == 1){
		dragones[*nivel].vida -= Personajes[PersonajeElegido].ataque1;
		printf("El dragón ha recibido %d de daño.\n", Personajes[PersonajeElegido].ataque1);
		printf("El dragón tiene %d de vida\n", dragones[*nivel].vida);
	}
	else if(ataque == 2){
		dragones[*nivel].vida -= ataquePersonaje;
		printf("El dragón ha recibido %d de daño.\n", ataquePersonaje);
		printf("El dragón tiene %d de vida\n", dragones[*nivel].vida);
	}
}

void combate(Dragon dragones[], Personaje Personajes[], int *cantPersonajes, int *cantDragones, int PersonajeElegido, int *nivel){

	if(*nivel < 3){
		printf("\x1b[38;5;1m \nEMPIEZA EL COMBATE \n\x1b[0m");
		printf("%s VS %s\n", Personajes[PersonajeElegido].nombre, dragones[*nivel].nombre);
		personajeVSdragon(PersonajeElegido);
		printf("\nContinuar ↵ ");
		getchar();
		system("clear");
	}
	

	while(*nivel < 3){

		turnoJugador(dragones, Personajes, PersonajeElegido, nivel);
		

		if (dragones[*nivel].vida <= 0){
			printf("\x1b[38;5;9m \nHas matado al %s.\n \n\x1b[0m", dragones[*nivel].nombre);
			(*cantDragones)--;
			if(*cantDragones == 0){
				printf("HAS GANADO\n");
			}
			
			if (*nivel < 3){
				(*nivel)++;
			}

			getchar();
			getchar(); //se pone dos veces para guardar el scanf anterior
			system("clear"); 
			return;
		}

		turnoDragon(dragones, Personajes, PersonajeElegido, nivel);

		if (Personajes[PersonajeElegido].vida <= 0){
			printf("\x1b[38;5;9m \n%s ha muerto.\n \n\x1b[0m", Personajes[PersonajeElegido].nombre);
			printf("Elegir otro personaje ↵ ");
			Personajes[PersonajeElegido].estado = 0; //pasa a estar muerto
			(*cantPersonajes)--;
			if(*cantPersonajes == 0){
				
				printf("GAME OVER\n");
				getchar();
				getchar();
				system("clear");
				return;
			}
			getchar();
			getchar();
			PersonajeElegido = ElegirPersonaje(Personajes);
			printf("%s VS %s\n", Personajes[PersonajeElegido].nombre, dragones[*nivel].nombre);
			personajeVSdragon(PersonajeElegido);
			printf("\nContinuar ↵ ");
			getchar();
			system("clear");
		}
		
	}


}