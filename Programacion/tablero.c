#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 10

void printBoard(int width, int height, int playerX, int playerY) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            } else if (i == playerY && j == playerX) {
                printf("#");
            } else if (i % 2 == 0 && j % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int width = DEFAULT_SIZE;
    int height = DEFAULT_SIZE;

    // Leer argumentos de línea de comandos
    if (argc == 2) {
        width = height = atoi(argv[1]);
    } else if (argc == 3) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
    }

    if (width < 3 || height < 3) {
        printf("El tamaño del tablero debe ser al menos 3x3.\n");
        return 1;
    }

    int playerX = width / 2;
    int playerY = height / 2;
    char input;

    system("clear"); // Limpia la pantalla (en Linux y MacOS)
    printBoard(width, height, playerX, playerY);

    while (1) {
        printf("\nUsa 'w', 'a', 's', 'd' para mover el '#' o 'q' para salir: ");
        scanf(" %c", &input);

        // Actualizar posición según la tecla presionada
        if (input == 'w' && playerY > 1) {
            playerY--;
        } else if (input == 'a' && playerX > 1) {
            playerX--;
        } else if (input == 's' && playerY < height - 2) {
            playerY++;
        } else if (input == 'd' && playerX < width - 2) {
            playerX++;
        } else if (input == 'q') {
            printf("Saliendo...\n");
            break;
        }

        // Imprimir el tablero actualizado
        system("clear"); // Limpia la pantalla
        printBoard(width, height, playerX, playerY);
    }

    return 0;
}
