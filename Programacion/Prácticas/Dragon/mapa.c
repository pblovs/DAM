#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "mapa.h"
#include "Personajes.h"
#include "dragones.h"
#include "combate.h"


// Función para capturar una tecla sin presionar Enter
char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); // Obtener configuración actual del terminal
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Desactivar modo canónico y eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplicar cambios
    ch = getchar(); // Leer tecla
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaurar configuración
    return ch;
}

void mapa(Dragon dragones[], int cantDragones, Personaje personajes[], int cantPersonajes, int PersonajeElegido){

	system("clear");

	int nivel = 0;
	
	int largo = 13;
	int ancho = 13; 

	int i;
	int j;

	char posicion;

	int vertical = largo / 2;
	int horizontal = ancho / 2;

    int selectorY = 6;

	while (1){

		printf("          Tienda\n");

		for (int i = 0; i < largo; i++){
				for (int j = 0; j < ancho; j++){
						if (i > 0 && i < (largo - 1)){
								if ( i == vertical && j == horizontal) {
									simboloPersonaje(personajes, PersonajeElegido);
								}
								else if (j > 0 && j < (ancho - 1)){
									printf("  ");
								}
								else if(i == selectorY && j == (ancho-1)){
									printf("] Personajes");
								}
								else {
									printf("# "); //imprime las lineas de los lados
								}
						}
						else if(i == (largo-1) && j == 6){
									printf("__");
						}
						else if(i == (largo-1) && j == 5){
									printf("#_");
						}
						else if(i == 0 && j == 6){
									printf("¯¯");
						}
						else if(i == 0 && j == 5){
									printf("#¯");
						}	
						else{
							printf("# "); //imprime la linea de arriba y la de abajo
						} 
				}
				printf("\n");
		}

		printf("         Combate\n");

		printf("\nPersonje: %s / Vida: %dhp / Ataque 1: %d / Ataque 2: 0-%d\n", personajes[PersonajeElegido].nombre, personajes[PersonajeElegido].vida, personajes[PersonajeElegido].ataque1, personajes[PersonajeElegido].ataque2);
		posicion = getch(); // Captura la tecla sin Enter

		system("clear");

		if (posicion == 'w' || posicion == 'W'){
				vertical-= 1;

			if(vertical < 1 ){ //si se pasa del borde le suma otro para que se contrarreste y se quede en el mismo sitio
				vertical+=1;
			}

		}else if(posicion == 'a' || posicion == 'A'){
			horizontal-= 1;

			if(horizontal < 1 ){
				horizontal+=1;
			}
		
		}else if(posicion == 's' || posicion == 'S'){
			vertical+= 1;

			if(vertical > (largo - 2)){
				if (horizontal == selectorY){ //si la posicionY del * es = posicionY de ] 
            		combate(dragones, personajes, cantPersonajes, cantDragones, PersonajeElegido, nivel);
            		for (int i = 0; i < cantPersonajes; i++) {
    					personajes[i].vida = personajes[i].vidaMax;  // Recuperar la vida cuando acabe el combate
    					personajes[i].estado = 1;
					}
            	}
				vertical-=1;
			}
		
		}else if(posicion == 'd' || posicion == 'D'){
			horizontal+=1;

			if(horizontal > (ancho - 2)){
				if (vertical == selectorY){ //si la posicionY del * es = posicionY de ] 
            		PersonajeElegido = ElegirPersonaje(personajes);
            	}
				horizontal-=1;
			}
		
		}else if(posicion == 'q' || posicion == 'Q'){
			break;
		}
		
		printf("Nivel: %d", nivel);
	}
}
