//voy a tomar de base el codigo "cifradoCesar.c" para poder aplicarlo a un mensaje

#include<stdio.h>
#include<string.h>

char abecedario[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int i=0;
int desplazamiento = 0, posicion = 0; //posicion la a definir el usuario para diversos codigos
char mensaje[100];

void cifradoCesar();
void cifrarMensaje(char mensaje[100]);

int main(){
    char mensaje[100];

    //pedir el numero de el cifrado
    printf("Indica el numero de cifrado: ");
    scanf("%d", &posicion);

    //limpiando el buffer
    getchar();

    //pidiendo el mensaje para cifrar
    printf("Escribe el mensaje (en minusculas):\n");
    fgets(mensaje, sizeof(mensaje), stdin); //************************************************************************** */

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

//codificando el mensaje
void cifradoCesar() {
    int nuevaPosicion = 0;
    char abevedarioCifrado[26]; //variable para el nuevo abecedario

    desplazamiento = posicion;

    //aplicando el cifrado
    for(i=0; i<26; i++){
        nuevaPosicion = (i + desplazamiento) % 26; //para calcular la nueva posicion
        abevedarioCifrado[i] = abecedario[nuevaPosicion];
    }

    //imprimiendo el abecedario
    for(i=0; i<26; i++){
        printf("Letra original: %c -> cifrada: %c (Posición: %d)\n", abecedario[i], abevedarioCifrado[i], (i + desplazamiento) % 26);
    }
    printf("\n");
}

//*********************************************************************************************************************

