typedef struct{

	char Nombre[20];
	int ataque1;
	int ataque2;
	int vida;

}Personaje;

void InicializarPersonajes(Personaje personajes[], int* cantidad);
int calcularAtaquePersonaje(Personaje personajes[], int i);
void MostrarPersonajes(Personaje personajes[], int * cantidad);
int ElegirPersonaje();