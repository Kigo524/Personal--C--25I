#include <stdio.h>

    char abecedario[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i=0;
    int desplazamiento = 0, posicion = 0; //posicion la a definir el usuario para diversos codigos

    void cifradoCesar();

int main(){

    //pedir el numero de casillas que se va a recorrer
    printf("Indica el número de cifrado: ");
    scanf("%d", &posicion);

    //imprimir el abecedario normal
    for(i=0; i<26; i++){
        printf("%c, ", abecedario[i]);
    }
    printf("\n\n");

    cifradoCesar();

    return 0;
}

//*********************************************************************** */
//codificando el texto
void cifradoCesar() {
    int nuevaPosicion = 0;
    char abecedarioCifrado[26]; //variable para el nuevo abecedario

    desplazamiento = posicion;

    //aplicando el cifrado
    for(i=0; i<26; i++){
        nuevaPosicion = (i + desplazamiento) % 26; //para clacular la nueva posicion
        abecedarioCifrado[i] = abecedario[nuevaPosicion];
    }

    //imprimir el abecedario cifrado
    printf("Abecedario cifrado (desplazado %d posiciones):\n", desplazamiento);
    for (i = 0; i < 26; i++) {
        printf("Letra original: %c -> Letra cifrada: %c (Posición: %d)\n", abecedario[i], abecedarioCifrado[i], (i + desplazamiento) % 26);
    }
}