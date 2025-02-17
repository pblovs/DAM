#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include "dragones.h"
#include "Personajes.h"
#include "combate.h"


int main() {

    printf("\n\n"
        "                              ` )\n"
        "                     (         (\n"
        "                      )      (\n"
        "                    )          )\n"
        "                   (          ( ,\n"
        "                  _ _)_      .-Y.\n"
        "       .--._ _.--'.',T.\\_.--' (_)`.\n"
        "     .'_.   `  _.'  `-'    __._.---;\n"
        "    /.'  `.  -'     ___.--' ,--.  :       o       ,-. _\n"
        "   : |  xX|       ,'  .-'`.(   |  '      (   o  ,' .-' `,             _                             \n"
        "  :  `.  .'    ._'-,  \\   | \\  ||/        `.{  / .'    :             | |                             \n"
        " .;    `'    ,',\\|\\|   \\  |  `.;'     .__(()`./.'  _.-'            __| |_ __ __ _  __ _  ___  _ __  \n"
        " ;           |   ` `    \\.'|\\\\ :      ``.-. _ '_.-'               / _` | '__/ _` |/ _` |/ _ \\| '_ \\ \n"
        ".'           ` /|,         `|\\\\ \\        -'' \\  \\                | (_| | | | (_| | (_| | (_) | | | |\n"
        ":             \\`/|,-.       `|\\\\ :         ,-'| `-.               \\__,_|_|  \\__,_|\\__, |\\___/|_| |_|\n"
        ":        _     \\`/  |   _   .^.'\\ \\          -'> \\_                                __/ |            \n"
        "`;      --`-.   \\`._| ,' \\  |  \\ : \\           )`.\\`-                             |___/       \n"
        " :.      .---\\   \\   ,'   | '   \\ : .          `  `.\\_,/\n"
        "  :.        __\\   `. :    | `-.-',  :               `-'\n"
        "  `:.     -'   `.   `.`---'__.--'  /\n"
        "   `:         __.\\    `---'      _'\n"
        "    `:.     -'    `.       __.--'\n"
        "     `:.          __`--.--'\\\n"
        "      `:.      --'     __   `.\n"
        "       `:.     --'         `-'\n"
        "                                       Pulsa ENTER para empezar "
    );
   
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

    mapa(dragones, cantDragones, personajes, cantPersonajes, PersonajeElegido);

    return 0;
}





















































