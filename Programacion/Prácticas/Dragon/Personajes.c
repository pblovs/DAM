#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Personajes.h"

void InicializarPersonajes(Personaje personajes[], int * cantidad){

	*cantidad = 3;

	strcpy(personajes[0].nombre, "El caballero Pelayo");
	personajes[0].ataque1 = 20;
	personajes[0].ataque2 = 40;
	personajes[0].vida = 250;

	strcpy(personajes[1].nombre, "La arquera Jeanne	de Clisson");
	personajes[1].ataque1 = 30;
	personajes[1].ataque2 = 60;
	personajes[1].vida = 200;

	strcpy(personajes[2].nombre, "El hechicero Froilan");
	personajes[2].ataque1 = 45;
	personajes[2].ataque2 = 80;
	personajes[2].vida = 150;

}

int calcularAtaquePersonaje(Personaje personajes[], int PersonajeElegido){
 
	int ataque2 = rand() % (personajes[PersonajeElegido].ataque2 + 1);
	return ataque2;

}

void MostrarPersonajes(Personaje personajes[], int * cantidad){

	printf("\nPERSONAJES: \n");

	for (int i = 0; i < *cantidad; i++){
		printf("Nombre: %s.\nAtaque 1: %d.\nAtaque 2: 0-%d.\nVida: %d.\n", personajes[i].nombre, personajes[i].ataque1, personajes[i].ataque2, personajes[i].vida);
	}

}

int ElegirPersonaje(){

	int PersonajeElegido;

	printf("\nSeleccione un personaje: ");
	scanf("%d", &PersonajeElegido);

	return PersonajeElegido;
}