//voy a tomar de base el codigo "cifradoCesar.c" para poder aplicarlo a un mensaje

#include<stdio.h>
#include<string.h>

char abecedario[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
//variables globales
int i=0;
int desplazamiento = 0, posicion = 0; //posicion la a definir el usuario para diversos codigos
char mensaje[100];

void cifradoCesar(); //para mostrar el abecedario cifrado
void cifrarMensaje(char mensaje[100]); //para cifrar el mensaje

int main(){
    char mensaje[100];

    //pedir el numero de el cifrado
    printf("Indica el numero de cifrado: ");
    scanf("%d", &posicion);

    //limpiando el buffer
    getchar();

    //pidiendo el mensaje para cifrar
    printf("Escribe el mensaje (en minusculas):\n");
    fgets(mensaje, sizeof(mensaje), stdin); //leer el mensaje con espacios

    //imprimir el abecedario normal
    for(i=0; i<26; i++){
        printf("%c, ", abecedario[i]);
    }
    printf("\n\n");

    cifradoCesar();
    cifrarMensaje(mensaje);

    return 0;
}

//********************************************************************************************************************* */

//para mostrar el abecedario cifrado
void cifradoCesar() {
    int nuevaPosicion = 0;
    char abevedarioCifrado[26]; //variable para el nuevo abecedario

    desplazamiento = posicion; //para asignar el desplazamiento definido por el usuario

    //aplicando el cifrado al abecedario
    for(i=0; i<26; i++){
        nuevaPosicion = (i + desplazamiento) % 26; //para calcular la nueva posicion con desplazamiento circular
        abevedarioCifrado[i] = abecedario[nuevaPosicion]; //asigna la letra cifrada
    }

    //imprimiendo el abecedario
    for(i=0; i<26; i++){
        printf("Letra original: %c -> cifrada: %c (Posición: %d)\n", abecedario[i], abevedarioCifrado[i], (i + desplazamiento) % 26);
    }
    printf("\n");
}

//*********************************************************************************************************************

// Cifrar un mensaje
void cifrarMensaje(char mensaje[]) {
    char mensajeCifrado[100]; //arreglo para almacenar el mensaje cifrado
    int longitud = strlen(mensaje); //calcular la longitud del mensaje

    //para recorrer cada caracter del mensaje
    for (i = 0; i < longitud; i++) {
        if (mensaje[i] >= 'a' && mensaje[i] <= 'z') {
            int indiceOriginal = mensaje[i] - 'a'; //calcular el indice de la letra en el abecedario
            int nuevaPosicion = (indiceOriginal + posicion) % 26; //calcular la nueva posicion con el desplazamiento
            mensajeCifrado[i] = abecedario[nuevaPosicion]; //asignar la letra cifrada
        } else {
            // Si no es una letra, se deja igual
            mensajeCifrado[i] = mensaje[i];
        }
    }
    mensajeCifrado[longitud] = '\0'; // Terminar la cadena

    printf("Mensaje original: %s\n", mensaje);
    printf("Mensaje cifrado: %s\n", mensajeCifrado);
}