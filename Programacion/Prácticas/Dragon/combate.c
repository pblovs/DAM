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

void turnoJugador(Dragon dragones[], Personaje Personajes[], int PersonajeElegido, int *nivel, int *cant_curas, int *cant_X2){

	int ataque;
	int eleccion;
	static int multiplicador = 1; // Permite daño x2 
	int ataquePersonaje = calcularAtaquePersonaje(Personajes, PersonajeElegido);
	printf("\x1b[38;5;12m\nTU TURNO.\n\n\x1b[0m");

	printf("Elige una acción: ATACAR (1) , UTILIDADES (2): ");
    scanf("%d", &eleccion);

    if (eleccion == 2) {
        char utilidad;
        printf("Elige una utilidad - Curas[%d] (c) o Daño X2[%d] (d): ", *cant_curas, *cant_X2);
        scanf(" %c", &utilidad);

        if (utilidad == 'c' && *cant_curas > 0) {
            Personajes[PersonajeElegido].vida += 50;
            (*cant_curas)--;
            printf(GREEN "%s se ha curado 50 de vida.\n\n" RESET, Personajes[PersonajeElegido].nombre);
            printf("Vida: %d\n", Personajes[PersonajeElegido].vida);
        } 
        else if (utilidad == 'd' && *cant_X2 > 0) {
            multiplicador = 2;
            (*cant_X2)--;
            printf(RED "El siguiente ataque hará el doble de daño.\n\n" RESET);
        } 
        else {
            printf("No tienes suficientes utilidades de este tipo.\n\n");
        }
    }

    printf("Elige un ataque. ATAQUE 1 (%d), ATAQUE 2 (0-%d): ", Personajes[PersonajeElegido].ataque1, Personajes[PersonajeElegido].ataque2);
    scanf("%d", &ataque);

    if (ataque == 1) {
        int daño = Personajes[PersonajeElegido].ataque1 * multiplicador;
        dragones[*nivel].vida -= daño;
        printf("El dragón ha recibido %d de daño.\n", daño);
    } 
    else if (ataque == 2) {
        int daño = ataquePersonaje * multiplicador;
        dragones[*nivel].vida -= daño;
        printf("El dragón ha recibido %d de daño.\n", daño);
    } 
    else {
        printf("Fallaste, ataque no válido.\n");
    }

    printf("El dragón tiene %d de vida\n", dragones[*nivel].vida);

    multiplicador = 1; // Resetear el multiplicador después del ataque
	
}

void combate(Dragon dragones[], Personaje Personajes[], int *cantPersonajes, int *cantDragones, int PersonajeElegido, int *nivel, int *oro, int *cant_curas, int *cant_X2){

	if(*nivel < 3){
		printf("\x1b[38;5;1m \nEMPIEZA EL COMBATE \n\x1b[0m");
		printf("%s VS %s\n", Personajes[PersonajeElegido].nombre, dragones[*nivel].nombre);
		personajeVSdragon(PersonajeElegido);
		printf("\nContinuar ↵ ");
		getchar();
		system("clear");
	}
	

	while(*nivel < 3){

		turnoJugador(dragones, Personajes, PersonajeElegido, nivel, cant_curas, cant_X2);
		

		if (dragones[*nivel].vida <= 0){
			printf("\x1b[38;5;9m \nHas matado al %s.\n \n\x1b[0m", dragones[*nivel].nombre);
			(*cantDragones)--;
			if(*cantDragones == 0){
				printf("HAS GANADO\n");
			}
			
			if (*nivel < 3){
				(*nivel)++;
				*oro += 100;
			}

			getchar();
			getchar(); //se pone dos veces para guardar el scanf anterior
			system("clear"); 
			return;
		}

		turnoDragon(dragones, Personajes, PersonajeElegido, nivel);

		if (Personajes[PersonajeElegido].vida <= 0){		
			printf("\x1b[38;5;9m \n%s ha muerto.\n \n\x1b[0m", Personajes[PersonajeElegido].nombre);
			Personajes[PersonajeElegido].estado = 0; //pasa a estar muerto
			(*cantPersonajes)--;

			if(*cantPersonajes == 0){
				
				printf("GAME OVER\n");
				getchar();
				getchar();
				system("clear");
				return;
			}
			else{
				printf("Elegir otro personaje ↵ ");
			}

			getchar();
			getchar();
			system("clear");
			PersonajeElegido = ElegirPersonaje(Personajes);
			printf("%s VS %s\n", Personajes[PersonajeElegido].nombre, dragones[*nivel].nombre);
			personajeVSdragon(PersonajeElegido);
			printf("\nContinuar ↵ ");
			getchar();
			system("clear");
		}
		
	}


}