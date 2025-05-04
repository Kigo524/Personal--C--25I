//cadena de caracteres

#include<stdio.h>
#include<string.h> //para una funcion que mide el tamano de la cadena almacenada **

int main(){
    char nombre[10];
    char apellido[10];
    char nombreCompleto[30] = {}; //esto es para que al imprimirlo no salga con caracteres basura
    int i=0;

    printf("Inserte su nombre: ");
    gets(nombre);

    printf("Inserte su apellido: ");
    gets(apellido);

    printf("El usuario es: %s %s\n\n", nombre, apellido);

    //para imprimir caracter por caracter
    //aqui se usa la funcion para saber el tamano ** de la cadena y que no recorra mas el programa
    for(i=0; i<strlen(nombre); i++){ //el i va de 0 hasta el tamano de el nombre
        printf("%c\n", nombre[i]);
    }

    //para concatenar cadenas
    //srtcat(cadenaDestino, cadenaOrigen); lo que este en la Origen, se concatena a Destino
    strcat(nombreCompleto, nombre);
    strcat(nombreCompleto, " "); //para que se agregue tambien un espacio en blanco
    strcat(nombreCompleto, apellido);

    printf("\n\nEl nombre completo es: %s\n", nombreCompleto);

    return 0;
}