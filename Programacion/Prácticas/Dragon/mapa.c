#include <stdio.h>
#include <stdlib.h>

typedef struct{

	char nombre[30];
	int ataque1;
	int ataque2;
	int vida;
	int estado;

}Personaje;

void InicializarPersonajes(Personaje personajes[], int * cantidad){

	*cantidad = 3;

	strcpy(personajes[0].nombre, "El caballero Pelayo");
	personajes[0].ataque1 = 20;
	personajes[0].ataque2 = 40;
	personajes[0].vida = 250;
	personajes[0].estado = 1; //1=vivo 0=muerto

	strcpy(personajes[1].nombre, "La arquera Jeanne	de Clisson");
	personajes[1].ataque1 = 30;
	personajes[1].ataque2 = 60;
	personajes[1].vida = 200;
	personajes[1].estado = 1;

	strcpy(personajes[2].nombre, "El hechicero Froilan");
	personajes[2].ataque1 = 45;
	personajes[2].ataque2 = 80;
	personajes[2].vida = 150;
	personajes[2].estado = 1;

}

int ElegirPersonaje(Personaje personajes[]){

	int PersonajeElegido;

	while (1) {

        printf("Seleccione un personaje (0-2): ");
        scanf("%d", &PersonajeElegido);

        if (PersonajeElegido < 0 || PersonajeElegido >= 3) {
            printf("Opción inválida. Elige otro.\n");
        } 
        else if (personajes[PersonajeElegido].estado == 0) {
            printf("Ese personaje está muerto. Elige otro.\n");
        } 
        else {
            return PersonajeElegido;
        }
    }
}

int main(){

	Personaje personajes[3];
	int PersonajeElegido;

	int largo = 11;
	int ancho = 11; 

	int i;
	int j;

	char posicion;

	int vertical = largo / 2;
	int horizontal = ancho / 2;

	while (1){

		for (int i = 0; i < largo; i++){

				for (int j = 0; j < ancho; j++){

						if (i > 0 && i < (largo - 1)){

								if ( i == vertical && j == horizontal) {

										printf("* ");

								}
								else if (j > 0 && j < (ancho - 1)){

										printf("  ");
								
								}
								else if(i == 5 && j == (ancho-1)){

								printf("] Personajes");
								}	
								else {

										printf("# ");
								}
						}

						else if(i == 5 && j == (ancho-2)){
							PersonajeElegido = ElegirPersonaje(personajes);
						}

						else{

								printf("# ");
							} 
				}

				printf("\n");
		}

		printf("W = (Arriba),A = (Izquierda),S = (Abajo), D = (Derecha), Q = (Salir): \n");
		scanf("%c", &posicion);

		system("clear");

		if (posicion == 'w' || posicion == 'W'){
				vertical-= 1;

			if(vertical < 1 ){
				vertical+=1;
			}

		}else if(posicion == 'a' || posicion == 'A'){
			horizontal-= 1;

			if(horizontal < 1 ){
				horizontal+=1;
			}
		
		}else if(posicion == 's' || posicion == 'S'){
			vertical+= 1;

			if(vertical > (largo - 2) ){
				vertical-=1;
			}
		
		}else if(posicion == 'd' || posicion == 'D'){
			horizontal+=1;

			if(horizontal > (ancho - 2) ){
				horizontal-=1;
			}
		
		}else if(posicion == 'q' || posicion == 'Q'){
			break;
		}

	


	}

return 0;
}
