#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

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

void simboloPersonaje(Personaje personajes[], int PersonajeElegido){

	if(PersonajeElegido==0){
		printf("ð ");
	}
	else if(PersonajeElegido==1){
		printf("¢ ");
	}
	else if(PersonajeElegido==2){
		printf("§ ");
	}
}

int main(){

	system("clear");

	Personaje personajes[3];
	int cantidad = 3;
	InicializarPersonajes(personajes, &cantidad);
	int PersonajeElegido = 0;

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
		//scanf("%c", &posicion);
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

			if(vertical > (largo - 2) ){
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
	}

return 0;
}
