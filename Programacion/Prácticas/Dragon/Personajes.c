#include <stdio.h>
#include <string.h>
#include "Personajes.h"

void InicializarPersonajes(Personaje personajes[], int * cantidad){

	*cantidad = 3;

	strcpy(personajes[0].Nombre, "El caballero Pelayo");
	personajes[0].ataque1 = 20;
	personajes[0].ataque2 = 40;
	personajes[0].vida = 250;

	strcpy(personajes[1].Nombre, "La arquera Jeanne	de Clisson");
	personajes[1].ataque1 = 30;
	personajes[1].ataque2 = 60;
	personajes[1].vida = 200;

	strcpy(personajes[2].Nombre, "El hechicero Froilan");
	personajes[2].ataque1 = 45;
	personajes[2].ataque2 = 80;
	personajes[2].vida = 150;

}

int calcularAtaquePersonaje(Personaje personajes[], int PersonajeElegido){
 
	int ataque2 = rand() % (personajes[PersonajeElegido].ataque2 + 1);
	return ataque2;

}

void MostrarPersonajes(Personaje personajes[], int * cantidad){

	printf("Personajes disponibles: \n");

	for (int i = 0; i < *cantidad; i++){
		printf("Nombre: %s.\n Daño del primer ataque: %d.\n El daño del segundo ataque varia entre 0 y %d.\n vida: %d.\n", personajes[i].Nombre, personajes[i].ataque1, personajes[i].ataque2, personajes[i].vida);
	}

}

int ElegirPersonaje(){

	int PersonajeElegido;

	printf("Seleccione un personaje: ");
	scanf("%d", &PersonajeElegido);

	return PersonajeElegido;
}