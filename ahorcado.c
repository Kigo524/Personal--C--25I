#include<stdio.h>
#include<string.h>

int main(){
    int opcion, i, encontrado, posicion;
    int tam_palabra =0;
    char palabra[20]="peligro";
    char progreso[20];
    char letra;
    /*char *pos; se usaria para lo del comentario mas abajo, 
    lo uso como prueba pero como no entendi como se usar strchr,
    mejor use un for con la bandera encontrado para encontrar la letra*/

    //calcular la longitud de la palabra
    tam_palabra = strlen(palabra); 

    //iniciar el progreso con guiones bajos
    for(i = 0; i<tam_palabra; i++){
        progreso[i] = '_';
    }
    progreso[tam_palabra] = '\0'; //para agregar el tamano nulo hasta el final

    do{
        //para mostrar el progreso actual
        for(i = 0; i < tam_palabra; i++){
            printf("%c ", progreso[i]);
        }
        printf("\n");

        printf("Escribe una letra: ");
        scanf(" %c", &letra); //el espacio antes de c para ignorar saltos de linea

        //buscar la letra en la palabra
        encontrado = 0; //bandera para saber si se encontro la letra
        for(i=0; i<tam_palabra; i++){
            if(palabra[i] == letra){
                progreso[i] = letra; //para reemplazar el _ con la letra
                encontrado = 1;
            }
        }

        //para cuando no se encuentra la letra
        if(!encontrado){
            printf("La letra '%c' no esta en la palabra\n", letra);
        }


        //strchr con tipo char, busca la primera aparicion de una caracter de una cadena, si no lo encuentra, devuelve "NULL"

        /*esto es para probar que si encuentra la letra en la palabra
        if(pos != NULL){
            printf("La letra '%c' se encuentra en la palabra\n", letra);
        } else {
            printf("La letra '%c' no esta en la palabra\n", letra);
        } */

    }while(strcmp(progreso, palabra) != 0); //repetir hasta que se complete la palabra

    printf("\nFelicidades! Adivinaste la palabra: %s\n\n", palabra);

    return 0;

}