#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40
#define AUTOR 60
#define GENEROS 4

typedef enum {
		FICCION,
		NO_FICCION,
		POESIA,
		TEATRO,
		ENSAYO
	} Genero;

char *nombres_generos[] = {  //Creo un array de punteros con el nombre de los generos
    "Ficción",
    "No ficción",
    "Poesía",
    "Teatro",
    "Ensayo"
};

typedef struct{
	int id;
	char titulo[80];
	char autor[AUTOR];
	float precio;
	Genero genero;
	int cantidad;
}LIBRO;	

void imprimir(LIBRO * libro){  //Función para imprimir un libro
	printf("ID: %d, Título: %s, Autor: %s, %.2lf$, Género: %s, Cantidad: %d\n", libro->id, libro->titulo, libro->autor, libro->precio, nombres_generos[libro->genero], libro->cantidad);
}  //nombres_generos imprime el nombre del género en la posición a la que pertenezca el género del enum

int comprobar(LIBRO * libro, int comprobado, int cantMin, int cantMax){  //Función para comprobar si el dato introducido es correcto
	while (comprobado < cantMin || comprobado > cantMax){
		printf("ERROR Introduce un número válido: ");
		scanf("%d", &comprobado);
	}
	return comprobado;
}

void mostrar(LIBRO * catalogo){  //Función para imprimir todos los libros
	for( int i = 0; i < MAX; i++){
		imprimir(&catalogo[i]);
	}
	printf("\n");
}

void mostrarLibro(LIBRO * catalogo, int id_buscado){  //Función para buscar un libro por su ID
	id_buscado = comprobar(catalogo, id_buscado, 1, MAX);

	for( int i = 0; i < MAX; i++){
		if (id_buscado == catalogo[i].id){
			imprimir(&catalogo[i]);
			return;
		}
	}
	printf("\n");
}

void stock(LIBRO * catalogo, int id_incrementar, int cant_incrementar){  //Función para reabastecer un libro

	for( int i = 0; i < MAX; i++){
		if (id_incrementar == catalogo[i].id){
			catalogo[i].cantidad += cant_incrementar;
			printf("Ahora hay %d ejemplares de %s\n", catalogo[i].cantidad, catalogo[i].titulo);
			return;
		}
	}
	
	printf("\n");
}

void categoria(LIBRO * catalogo, int categ){  //Función para imprimir todos los libros de una categoría
	categ = comprobar(catalogo, categ, 0, GENEROS);
	for( int i = 0; i < MAX; i++){
		if(categ == catalogo[i].genero){
			imprimir(&catalogo[i]);
		}
	}
		printf("\n");
}

void autor(LIBRO * catalogo, char autor_buscado[AUTOR]){  //Función que muestra los libros de un autor buscado

	int encontrado = 0; 
    for (int i = 0; i < MAX; i++) {
        if (strstr(catalogo[i].autor, autor_buscado) != NULL) { //La función strstr() busca la primera aparición de string2 en string1
            imprimir(&catalogo[i]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron libros con ese autor\n");
    }
}

void inicializarLibro(LIBRO * libro, int id, char* titulo, char* autor, double precio, Genero genero, int cantidad){
	
	libro->id = id;
	strcpy(libro->titulo,titulo);
	strcpy(libro->autor,autor);
	libro->precio = precio;
	libro->genero = genero;
	libro->cantidad = cantidad;
}

void añadirLibro(LIBRO * catalogo, int cant_añadir){
	
	int tam = MAX + cant_añadir;

	LIBRO * catalogoNuevo = (LIBRO *)realloc(catalogo, tam * sizeof(LIBRO));

	if (catalogoNuevo == NULL) {
    	printf("Error\n");
    	free(catalogo);
    	return;
	}
	catalogo = catalogoNuevo;

	for (int i = MAX; i < tam; i++){
		printf("Libro nº: ");
		scanf("%d", &catalogoNuevo[i].id);
		printf("Introduce el titulo: ");
		scanf(" %[^\n]", catalogoNuevo[i].titulo); //Permite espacios
		printf("Introduce el autor: ");
		scanf(" %[^\n]", catalogoNuevo[i].autor);
		printf("Introduce el precio: ");
		scanf("%f", &catalogoNuevo[i].precio);
		printf("Introduce el genero (0=Ficcion, 1=No-Ficcion, 2=Poesia, 3=Teatro, 4=Ensayo): ");
		int gen = 0; //Creo una variable para guardar el número que corresponde al género.
		scanf("%d", &gen);
		catalogoNuevo[i].genero = comprobar(&catalogo[i], gen, 0, GENEROS); //Guardo en el catalogo el género, la función comprobar comprueba que has introducido un número entre 0 y 4 y devuelve el número si está entre esos valores.
		printf("Introduce la cantidad: ");
		scanf("%d", &catalogoNuevo[i].cantidad);

	}

	for (int i = 0; i < tam; i++){
		printf("ID: %d, Título: %s, Autor: %s, %.2lf$, Género: %s, Cantidad: %d\n", catalogoNuevo[i].id, catalogoNuevo[i].titulo, catalogoNuevo[i].autor, catalogoNuevo[i].precio,
		 nombres_generos[catalogoNuevo[i].genero], catalogoNuevo[i].cantidad);
	}
	

}

int main(int argc, char * argv[]){

	LIBRO * catalogo;
	catalogo = (LIBRO*)malloc(sizeof(LIBRO) * 40);
	if (catalogo == NULL){
		printf("ERROR");
	}

	            inicializarLibro(&catalogo[0], 1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICCION, 10),
		    	inicializarLibro(&catalogo[1], 2, "1984", "George Orwell", 12.49, FICCION, 5),
	            inicializarLibro(&catalogo[2], 3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICCION, 8),
	            inicializarLibro(&catalogo[3], 4, "Moby Dick", "Herman Melville", 18.99, FICCION, 12),
	            inicializarLibro(&catalogo[4], 5, "War and Peace", "Leo Tolstoy", 20.00, FICCION, 7),
	            inicializarLibro(&catalogo[5], 6, "Pride and Prejudice", "Jane Austen", 14.99, FICCION, 9),
	            inicializarLibro(&catalogo[6], 7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICCION, 6),
	            inicializarLibro(&catalogo[7], 8, "The Odyssey", "Homer", 17.49, FICCION, 4),
	            inicializarLibro(&catalogo[8], 9, "Ulysses", "James Joyce", 25.00, FICCION, 2),
	            inicializarLibro(&catalogo[9], 10, "The Divine Comedy", "Dante Alighieri", 22.00, POESIA, 3),
	            inicializarLibro(&catalogo[10], 11, "Leaves of Grass", "Walt Whitman", 13.00, POESIA, 11),
	            inicializarLibro(&catalogo[11], 12, "The Iliad", "Homer", 18.50, FICCION, 7),
	            inicializarLibro(&catalogo[12], 13, "A Brief History of Time", "Stephen Hawking", 15.00, NO_FICCION, 15),
	            inicializarLibro(&catalogo[13], 14, "The Art of War", "Sun Tzu", 9.99, NO_FICCION, 20),
	            inicializarLibro(&catalogo[14], 15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NO_FICCION, 13),
	            inicializarLibro(&catalogo[15], 16, "The Selfish Gene", "Richard Dawkins", 14.00, NO_FICCION, 6),
	            inicializarLibro(&catalogo[16], 17, "The Road to Serfdom", "F.A. Hayek", 10.50, NO_FICCION, 5),												       	           
	            inicializarLibro(&catalogo[17], 18, "The Wealth of Nations", "Adam Smith", 30.00, NO_FICCION, 8),									
	            inicializarLibro(&catalogo[18], 19, "On the Origin of Species", "Charles Darwin", 24.99, NO_FICCION, 4),												           
	            inicializarLibro(&catalogo[19], 20, "The Prince", "Niccolò Machiavelli", 8.99, NO_FICCION, 14),
	            inicializarLibro(&catalogo[20], 21, "Hamlet", "William Shakespeare", 11.50, TEATRO, 6),
	            inicializarLibro(&catalogo[21], 22, "Macbeth", "William Shakespeare", 9.50, TEATRO, 8),
	            inicializarLibro(&catalogo[22], 23, "Othello", "William Shakespeare", 10.99, TEATRO, 7),													           
	            inicializarLibro(&catalogo[23], 24, "A Doll's House", "Henrik Ibsen", 12.50, TEATRO, 5),
	            inicializarLibro(&catalogo[24], 25, "Waiting for Godot", "Samuel Beckett", 13.99, TEATRO, 4),
	            inicializarLibro(&catalogo[25], 26, "Death of a Salesman", "Arthur Miller", 14.99, TEATRO, 10),
	            inicializarLibro(&catalogo[26], 27, "The Glass Menagerie", "Tennessee Williams", 11.00, TEATRO, 9),
	            inicializarLibro(&catalogo[27], 28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, TEATRO, 3),
	            inicializarLibro(&catalogo[28], 29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, TEATRO, 15),
	            inicializarLibro(&catalogo[29], 30, "The Waste Land", "T.S. Eliot", 6.99, POESIA, 10),														           
	            inicializarLibro(&catalogo[30], 31, "Paradise Lost", "John Milton", 12.00, POESIA, 7),														            
	            inicializarLibro(&catalogo[31], 32, "Beowulf", "Anonymous", 15.00, POESIA, 5),
	            inicializarLibro(&catalogo[32], 33, "Essays", "Michel de Montaigne", 20.00, ENSAYO, 4),														          
	            inicializarLibro(&catalogo[33], 34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ENSAYO, 9),
	            inicializarLibro(&catalogo[34], 35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ENSAYO, 11),
	            inicializarLibro(&catalogo[35], 36, "Meditations", "Marcus Aurelius", 11.99, ENSAYO, 8),
	            inicializarLibro(&catalogo[36], 37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ENSAYO, 5),
	            inicializarLibro(&catalogo[37], 38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ENSAYO, 12),
	            inicializarLibro(&catalogo[38], 39, "The Republic", "Plato", 16.00, ENSAYO, 6),
	            inicializarLibro(&catalogo[39], 40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ENSAYO, 10);
	        
		        

    if (argc > 1){
    	for(int i = 1; i < argc; i++){
    		printf("argv[%d] = %s\n", i, argv[i]);
    	}
    	if (strcmp(argv[1], "mostrar") == 0){
    		mostrar(catalogo);
    	}
    	else if (strcmp(argv[1], "mostrarLibro") == 0 && atoi(argv[2]) <= 40 && atoi(argv[2]) >= 1){
    		mostrarLibro(catalogo, atoi(argv[2]));
    	}
    	else if (strcmp(argv[1], "stock") == 0 && atoi(argv[2]) <= 40 && atoi(argv[2]) >= 1){
    		stock(catalogo, atoi(argv[2]), atoi(argv[3]));
    	}
    	else if (strcmp(argv[1], "categoria") == 0 && atoi(argv[2]) <= 4 && atoi(argv[2]) >= 0){
    		categoria(catalogo, atoi(argv[2]));
    	}
    	else if (strcmp(argv[1], "autor") == 0){
    		autor(catalogo, argv[2]);
    	}
    	else if (strcmp(argv[1], "añadirLibro") == 0 && atoi(argv[2]) >= 0){
    		añadirLibro(catalogo, atoi(argv[2]));
    	}
    	
    }
    else {
    	int opcion;
		printf("\nMenú:\n");
    	printf("1. Mostrar todos los libros\n");
    	printf("2. Buscar libro por ID\n");
    	printf("3. Reabastecer stock\n");
    	printf("4. Mostrar libros por categoría\n");
    	printf("5. Buscar libros por autor\n");
    	printf("Elige una opción: ");
    	scanf("%d", &opcion);
    	printf("\n");

    	switch (opcion) {
        	case 1: 
        		mostrar(catalogo); 
        		break;
        	case 2: 
        		int id;
        		printf("Introduce el id del libro a buscar: ");
        		scanf("%d", &id);
        		mostrarLibro(catalogo, id); 
        		break;
        	case 3: 
        		int id_incrementar, cant_incrementar;
        		printf("Introduce el ID del libro a reabastecer: ");
				scanf("%d", &id_incrementar);
				printf("Introduce la cantidad a añadir: ");
				scanf("%d", &cant_incrementar);
        		stock(catalogo, id_incrementar, cant_incrementar); 
        		break;
        	case 4: 
        		int categ;
				printf("Muestra todos los libros de la categoría (0=Fiction, 1=Non-Fiction, 2=Poetry, 3=Theatr, 4=Essay): ");
				scanf("%d", &categ);
        		categoria(catalogo, categ); 
        		break;
        	case 5: 
        		char autor_buscado[AUTOR];
        		autor(catalogo, autor_buscado); 
        		break;
        	default: 
        		printf("Opción inválida\n");
    	}

    	return 0;
	}

	free(catalogo);
}
    
