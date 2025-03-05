#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include "dragones.h"
#include "Personajes.h"
#include "combate.h"


int main() {

    printf("\n\n");
        printf("\x1b[38;5;46m                              ` )\n\x1b[0m");
        printf("\x1b[38;5;46m                     (         (\n\x1b[0m");
        printf("\x1b[38;5;46m                      )      (\n\x1b[0m");
        printf("\x1b[38;5;46m                    )          )\n\x1b[0m");
        printf("\x1b[38;5;46m                   (          ( ,\n\x1b[0m");
        printf("\x1b[38;5;46m                  _ _)_      .-Y.\n\x1b[0m");
        printf("\x1b[38;5;46m       .--._ _.--'.',T.\\_.--' (_)`.\n\x1b[0m");
        printf("\x1b[38;5;46m     .'_.   `  _.'  `-'    __._.---;\n\x1b[0m");
        printf("\x1b[38;5;46m    /.'  `.  -'     ___.--' ,--.  :\x1b[0m");printf("\x1b[38;5;46m       o       ,-. _\n\x1b[0m");
        printf("\x1b[38;5;46m   : |  xX|       ,'  .-'`.(   |  '\x1b[0m");printf("\x1b[38;5;46m      (   o  ,' .-' `,\x1b[0m"); printf("\x1b[38;5;196m              _                             \n\x1b[0m");
        printf("\x1b[38;5;46m  :  `.  .'    ._'-,  \\   | \\  ||/\x1b[0m"); printf("\x1b[38;5;46m        `.{  / .'    :             \x1b[0m"); printf("\x1b[38;5;196m | |                             \n\x1b[0m");
        printf("\x1b[38;5;46m .;    `'    ,',\\|\\|   \\  |  `.;'\x1b[0m"); printf("\x1b[38;5;46m     .__(()`./.'  _.-'            \x1b[0m"); printf("\x1b[38;5;196m __| |_ __ __ _  __ _  ___  _ __  \n\x1b[0m");
        printf("\x1b[38;5;46m ;           |   ` `    \\.'|\\\\ :\x1b[0m"); printf("\x1b[38;5;46m      ``.-. _ '_.-'               \x1b[0m"); printf("\x1b[38;5;196m / _` | '__/ _` |/ _` |/ _ \\| '_ \\ \n\x1b[0m");
        printf("\x1b[38;5;46m .'           ` /|,         `|\\\\ \\\x1b[0m"); printf("\x1b[38;5;46m        -'' \\  \\               \x1b[0m"); printf("\x1b[38;5;196m | (_| | | | (_| | (_| | (_) | | | |\n\x1b[0m");
        printf("\x1b[38;5;46m :             \\`/|,-.       `|\\\\ :\x1b[0m"); printf("\x1b[38;5;46m        ,-'| `-.               \x1b[0m"); printf("\x1b[38;5;196m \\__,_|_|  \\__,_|\\__, |\\___/|_| |_|\n\x1b[0m");
        printf("\x1b[38;5;46m:        _     \\`/  |   _   .^.'\\ \\\x1b[0m"); printf("\x1b[38;5;46m          -'> \\_                                \x1b[0m"); printf("\x1b[38;5;196m __/ |            \n\x1b[0m");
        printf("\x1b[38;5;46m`;      --`-.   \\`._| ,' \\  |  \\ : \\\x1b[0m"); printf("\x1b[38;5;46m           )`.\\`-                             \x1b[0m"); printf("\x1b[38;5;196m |___/       \n\x1b[0m");
        printf("\x1b[38;5;46m :.      .---\\   \\   ,'   | '   \\ : .\x1b[0m"); printf("\x1b[38;5;46m          `  `.\\_,/\n\x1b[0m");
        printf("\x1b[38;5;46m  :.        __\\   `. :    | `-.-',  :\x1b[0m"); printf("\x1b[38;5;46m               `-'\n\x1b[0m");
        printf("\x1b[38;5;46m  `:.     -'   `.   `.`---'__.--'  /\n\x1b[0m");
        printf("\x1b[38;5;46m   `:         __.\\    `---'      _'\n\x1b[0m");
        printf("\x1b[38;5;46m    `:.     -'    `.       __.--'\n\x1b[0m");
        printf("\x1b[38;5;46m     `:.          __`--.--'\\\n\x1b[0m");
        printf("\x1b[38;5;46m      `:.      --'     __   `.\n\x1b[0m");
        printf("\x1b[38;5;46m       `:.     --'         `-'\n\x1b[0m");
        printf("\x1b[38;5;196m                                       Pulsa ENTER para empezar \n\x1b[0m");
   
    getchar();
    system("clear");

    Dragon dragones[3];
    Personaje personajes[3];
    int cantidad = 3;
    int cantPersonajes = cantidad; 
    int cantDragones = cantidad;

    InicializarPersonajes(personajes, &cantidad);
    inicializarDragones(dragones, &cantidad);

    mostrarDragones(dragones, cantidad);
    MostrarPersonajes(personajes, &cantidad);

    int PersonajeElegido = 0;

    mapa(dragones, &cantDragones, personajes, &cantPersonajes, PersonajeElegido);

    return 0;
}





















































