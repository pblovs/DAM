#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "Personajes.h"

void InicializarPersonajes(Personaje personajes[], int * cantidad){

	*cantidad = 3;

	strcpy(personajes[0].nombre, "El caballero Pelayo");
	personajes[0].ataque1 = 20;
	personajes[0].ataque2 = 40;
	personajes[0].vida = 250;
	personajes[0].vidaMax = 250;
	personajes[0].estado = 1; //1=vivo 0=muerto

	strcpy(personajes[1].nombre, "La arquera Jeanne de Clisson");
	personajes[1].ataque1 = 30;
	personajes[1].ataque2 = 60;
	personajes[1].vida = 200;
	personajes[1].vidaMax = 200;
	personajes[1].estado = 1;

	strcpy(personajes[2].nombre, "El hechicero Froilan");
	personajes[2].ataque1 = 45;
	personajes[2].ataque2 = 80;
	personajes[2].vida = 150;
	personajes[2].vidaMax = 170;
	personajes[2].estado = 1;

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

int ElegirPersonaje(Personaje personajes[]){

	int PersonajeElegido;

	int selector = 10;


	while (1) {
        

        printf(" ______________________________________    ____________________________________    ____________________________________ \n");
   		printf("|                                      |  |                                    |  |                                    |\n");
   		printf("|          EL CABALLERO PELAYO         |  |          LA ARQUERA JEANNE         |  |         EL HECHICERO FROILAN       |\n");   		
   		printf("|                                      |  |                                    |  |                                    |\n");
   		printf("|                   .####              |  |           .=.                      |  |      -          .===*-.            |\n");
    	printf("|                  -#&#*+.             |  |        .-+*.      . ..             |  |   .-*        -===                  |\n");
    	printf("|               =##&&#--##:            |  |        *...... ..+####*=.          |  |   *+-       *###                   |\n");
    	printf("|                  -+.+-+*#-           |  |        .=+....* .*=::+####.        |  |    =#     :*#+.. =*=*              |\n");
    	printf("|                   ..*#+#-            |  |        +#*.    *.+#--*=++#-        |  |    .#                              |\n");                      
    	printf("|                +####.-++###=         |  |      .-#-       ..****-*##.        |  |    .#             =*               |\n");
    	printf("|              +## .-:-####**&&*  +-+  |  |    ....+=.       *-----=**+*+.     |  |     #.     &&     ##&              |\n");
    	printf("|             *##=-###.-=+##+=##=-*    |  |  ..:-+::-++*******=:=**#*##:       |  |     =    .&&#     #&&#             |\n");
    	printf("|            *##*-**#* .+*---+*=#&+    |  |   .-*=***##*##########+*#..        |  |     #.---*+*     ###&&-            |\n");
    	printf("|           =###==#&*= -+ ..=+###&+    |  |    .++.  .*....+##**##++*#=.       |  |     #   ===*+    #&##&&            |\n");
    	printf("|          **##&*-*#&* -= =+###&&&&+   |  |     *=      ..*#######:-*#+.       |  |      #   #***##+   ###&&+          |\n");
    	printf("|         #####&&&&#+*#&+++&+*###&+    |  |    =#-.   .-#######**-=.           |  |     #  -****##=  -+##&&&           |\n");
    	printf("|      -**###&#&&&&&*=-+#=..:+&&&&-    |  |    .+*.  .*#########*#*.           |  |      #  ****#&&*.-##*=&&&:         |\n");
    	printf("|   =+#####&#&&&&&&#*#*&&*-.+&&#=      |  |    :*. ..*#***#####*###&-.         |  |      # .*###&&+.*&&&-*&&&          |\n");
    	printf("|  =########&&&&##&&:=&&&&##*#=        |  |    .+*:...*###*#*#**=*=            |  |     # &***#&&#-.#**.*&&&-          |\n");
    	printf("|  ###* ###&&&&##&&*:+#*#&=#*          |  |      .-.  *=*=*--=*--++.           |  |     #-#***&&&*::*###&&&*           |\n");
    	printf("|  **          =##*& -*# +&#**         |  |          ..*--..   .**-+..         |  |      #&****###...=###&&&&          |\n");
    	printf("|                   *###  &&#+         |  |        ..-*-*       .*-*...        |  |      #&&**#&&*...*###&&&&#         |\n");
    	printf("|                  *-*#*  *&&#         |  |          =**+*       .++**.        |  |       # &&*###*...*###*&&&&        |\n");
    	printf("|                   ##*   =##*         |  |         .*#*.         .-*#:        |  |       #  **###-...:*###&&&&-       |\n");
    	printf("|                   -#:    &&*         |  |        .=#*.            .##.       |  |       #   *###*....*####&&&&       |\n");
    	printf("|                   *#     *&#         |  |       .*#+..             .##.      |  |       #    #&&&#....+&&&&&&&       |\n");
    	printf("|                 -.*#.    #&==        |  |       -##+..             .###*-    |  |       #     #&&&&....+&&&&&&&&     |\n");
    	printf("|                **#=       .&&#.      |  |       --==+..             ..===*-  |  |       #      #&&&&....+&&&&&&&&&   |\n");
        printf("|______________________________________|  |____________________________________|  |____________________________________|\n");
        printf("|                                      |  |                                    |  |                                    |\n");
        printf("|      ♥ 250    ➹₁ 20     ➹₂ 0-40      |  |     ♥ 200    ➹₁ 30    ➹₂ 0-60      |  |      ♥ 170    ➹₁ 45    ➹₂ 0-80     |\n");
        printf("|______________________________________|  |____________________________________|  |____________________________________|\n\n");

  		

        for(int i = 0; i < 3; i++){
        	for(int j = 0; j < 52; j++){
        		if (j == 9 || j==10 || j==11 || j==29 || j==30 || j==31 || j==49 || j==50 || j==51){
        			if ( i==1 && j==selector){
        				printf("■ ");
        			}
        			else if ((i==1 && j==10) || (i==1 && j==30) || (i==1 && j==50)){
        				printf("  ");
        			}
        			else{
        				printf("▢ ");
        			}
        		}
        		else{
        			printf("  ");
        		}
        	}
        	printf("\n");
        }

        printf("\n                                               🄰 🄳 MOVER | ↵ SELECCIONAR  ");

        char posicion = getch(); // Captura la tecla sin Enter

        system("clear");

        if (posicion == 'a' || posicion == 'A'){
        	selector -= 20;
        	if (selector < 9){
        		selector += 20;
        	}
        }
        else if (posicion == 'd' || posicion == 'D'){
        	selector += 20;
        	if (selector > 51){
        		selector -= 20;
        	}
        }
        else if (posicion == '\n') {
            PersonajeElegido = (selector - 10) / 20; // (10-10) / 20 = 0 ; (30-10) / 20 = 1 ; (50-10) / 20 = 2 

            if (personajes[PersonajeElegido].estado == 0) {
                printf("Ese personaje está muerto. Elige otro.\n");
            } else {
                return PersonajeElegido;
            }
        }

    }
}

void simboloPersonaje(Personaje personajes[], int PersonajeElegido){

	if(PersonajeElegido==0){
		printf(RED "ð " RESET);
	}
	else if(PersonajeElegido==1){
		printf(GREEN "¢ " RESET);
	}
	else if(PersonajeElegido==2){
		printf(BLUE "§ " RESET);
	}
}

void personajeVSdragon(int PersonajeElegido){

	if(PersonajeElegido == 0){
		printf("                                                                  .+#######*         \n");
		printf("                                                             ++*###########*=.       \n");
		printf("                                                          =########*=::.......:-+=   \n");
		printf("                                                       .*#########-:-+#=......  . .:.\n");
		printf("                                                      .:+##########:...:*=..         \n");
		printf("                                                           +#######=......=          \n");
		printf("                                                            .######*..                \n");
		printf("                                                          .#########.                \n");
		printf("                                                   .- ################=              \n");
		printf("                                              . +########=-+###########.              \n");
		printf("                                              :#######-   ...:=#########              \n");
		printf("                                              ###**###    #*:.:=########              \n");
		printf("                                            #####+--=      :-.-*########-            \n");
		printf("                                            ++-  :=*        :###########              \n");
		printf("                                               -. #-    *##+###########-              \n");
		printf(" .                                          .*.# *   *#####*############              \n");
		printf(" .    #####                             +#=#=.#=.   *#++*+###########=                \n");
		printf("     #####=---=*++                       #+.-##     +#############* +                \n");
		printf("  .  ####=-+=++++++                   .-#*:*-           .=####+                      \n");
		printf("      ##*==#+#==-=   ..:.              ###.#.          .*##+                          \n");
		printf("  .    ##==:.--:..  .::::::--          :.:            .-##.                           \n");
		printf("       ##--+:....  ::::::--===                        .-##        :=                  \n");
		printf(" .---.=   ##*-::  -::::---====                         :##:  :-##*=*#*                \n");
		printf("  +++==*##*-=--=-===-----====.                         :.*#####-     #                \n");
		printf("   0:    ##=-----=*#+---=====                             ..         #-               \n");
		printf("        ###+=--*=#=   ======                                        ####              \n");
		printf("      #####*++++#+:-   ====                                          #*               \n");
		printf("    ###+-++======+*+=                                                                 \n");
		printf("          *+=====:.==-                                                                \n");
		printf("        .=-==.=    -=.                                                                \n");
		printf("       ---.       :-=.                                                                \n");
		printf("     --=:          :=:                                                                \n");
		printf("   :==:            .=+---                                                             \n");
		printf("   --:                                                                               \n");
	}
	
	else if(PersonajeElegido == 1){

		printf("                                                                     .: \n");
		printf("                                           .                     .=#-   \n");
		printf("                                           .:                  +&&*.    \n");
		printf("                                           .+-.             -@&&#:     \n");
		printf("                                            +++= .:       =@@@&&##:    \n");
		printf("                                            :**+++:    :=@@@@@&&#-     \n");
		printf("                                             -***+++=:  .@@@@&&#-      \n");
		printf("                                              -##**++=.  =@@&&&&=      \n");
		printf("                                               .+***++   .@&&+.  .     \n");
		printf("                                                  :+*+- .@&#.          \n");
		printf("                                                   =#***@&&*..         \n");
		printf("                                                -*-***#@@=::+.          \n");
		printf("                         ..                    :*&&&#@&&@#=              \n");
		printf("                          :=-.                 +#-.. =&@@&*#+.          \n");
		printf("                          . .==:-              :.   .@:@@+*&&#=         \n");
		printf("                         .     :--.         :-    .+-   .+* +#&*.       \n");
		printf("                                =-#.                   .#* .&+:*        \n");
		printf("                       .         ++     .=--.              .   ##.      \n");
		printf("                    ..           *=::                         .##.      \n");
		printf("                 #@&#=   ...:-++#&&.                         .*&:       \n");
		printf("             .++--#&##&#&##&&&#:  -#+                 .::-=+#&*.        \n");
		printf("             *@@@@@@&*+*@&-.       *==             .+##*=-::.           \n");
		printf("               =&&&&##***          --:            :##.                  \n");
		printf(" ::           .+#*#@&&##..        =:             -#+                    \n");
		printf(" -##*+:::::.:+#*##*@&&&+  ..    .:.              :##=                   \n");
		printf(" .#**#****##&***#*@&&#*=+*.   .=.                 ##*+.                \n");
		printf(" .&#&##*#****##&*#&&&&@@&#*-    -.                     :::.              \n");
		printf(" -&###**#**#&**#&@@@&@@@@&#:                                            \n");
		printf("  .+###***##&&&&&@@&&&&@@@@&*                                            \n");
		printf("   :*####*#***##***#&#*= =@&=                                            \n");
		printf("       .**+*##&***-      @&.                                            \n");
		printf("         .   -*#*:      .@&.                                             \n");
		printf("            =*+         *@#.                                             \n");
		printf("           -***-          .-:                                           \n");

	}
	
	else if (PersonajeElegido == 2){

	printf("                                      #+=                               \n");
    printf("                                       +-:.&&*+                         \n");
    printf("     .      :                      =+ =*=#0&&&&&=-                      \n");
    printf("    =      +        .             +*&&&&####&&&&&#+-                    \n");
    printf("   :+      #:         .:. - .  -#&&&&0&####0######&*.                  \n");
    printf("   #&**######+ : . -..* #****#&&&00###&####&###*+*#####:                \n");
    printf("  .&&&&##**&&&&&####&&&&######&0&#############:.=  .###-                \n");
    printf("  &00&#+*#* ..*####*####**##*#####*##         *##          #.           \n");
    printf("  #00&+*#* ..*####*####**##*#####*##         *##          #.            \n");
    printf("  *00&#+*#* ..*####*####**##*#####*##         *##       =####*=:.+      \n");
    printf("   #00&&&###*#*   ###+*+====+=++*##**=:            .#==*&&##&==+        \n");
    printf("   .000&*######&.+###++-.....-+=*####*+=-.         :+###&##***+=        \n");
    printf("    0000&#.   .#:+##++--.. . :-=*#**+*##**+=+++++++*+**=.       =       \n");
    printf("   #0##+*&*    +.####*+--......:.  .-+*#########***-     .              \n");
    printf("  0#&#-  =&*   =#####**+++=-... ....     -#####*:          -   .   :    \n");
    printf(" :#:-&+    :.+**####*##*##:.. ...  .... .                   ---::-.-.   \n");
    printf(" :&#  *  ..:+*###########*.      ....   .                  :-:----.-    \n");
    printf("    -  ..+*###&###########*++=:     .  :+.       .           ---  --    \n");
    printf("       :#&&&&&&0###**########*++-    .    #*-     ===*#*=- . :- ---:    \n");
    printf("    .- &00&##&&&0##+###*########**-      :&&&#+=   +*&*      :--.:-     \n");
    printf("     .&00&&&##-&&&##*##=   -**#####*-     &&&000&**###+       =:        \n");
    printf("   :-#0000&&*  #0&####++   .*######.           &&#*#&&#=     :          \n");
    printf("    :&000&&#  .-00&#### .++*###.     .--::     +&&&&0&&#=.:=#          \n");
    printf("   -#00&&&&   +#000&##: =**        ---:  .:    *&000&& +00&&&           \n");
    printf("    =00&&&#   +&000&&* =**=       ===     .    *&&000    .0&&           \n");
    printf("   :.&00&&#: .++=#00#==:+**     .=++           *&00000&   .              \n");
    printf("     &00&&&#  .    -===+**=:.  .+++:      .=+*###&&0000& .               \n");
    printf("      &&&&&##=-        -:----:=++*+    .##&&&&0000&&&&00*.    .=-     .  \n");
    printf("      +=&&&###**-= .        =++***.    .&000000&00&&&&###*****#*   =+=  \n");
    printf("        *&&&&&###**++++=++++*###-      +&00.0000000&&&&&&&#*****##&+  \n");
    printf("           =#&&&&&&############:        &000  #000000&&&00&##&&&&&&#*+   \n");
    printf("              =###&&&&&&###**=           &0==   *&000&&&####&&&&**#&=     \n");
    printf("                                      &0=        :0&&&00&&###0.         \n");
    printf("                                   =&000=.-=+*######&&&&&&00000&*-       \n");
    printf("                                                   .:-=++++++===-       \n");
	}


}