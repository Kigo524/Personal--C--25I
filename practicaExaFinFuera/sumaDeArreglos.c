/*Crea tres arreglos de enteros de tamaño 5. 
Llena cada arreglo con números enteros ingresados por el usuario. 
Luego, suma los elementos de los tres arreglos en un cuarto arreglo 
y muestra el resultado.*/

#include<stdio.h>
int main(){
    int arre1[5], arre2[5], arre3[5];
    int arreglo[5];
    int i=0;

    //pidiendo el primer arreglo
    for(i=0; i<5; i++){
        printf("Ingresa el dato ""%d"" del conjunto 1: ", i + 1);
        scanf("%d", &arre1[i]);

        if(i>3){
            printf("\n\n");
        }
    }

    //pedimos el segundo arreglo
    for(i=0; i<5; i++){
        printf("Ingresa el dato ""%d"" del conjunto 2: ", i + 1);
        scanf("%d", &arre2[i]);

        if(i>3){
            printf("\n\n");
        }
    }

    //pedimos el tercer arreglo
    for(i=0; i<5; i++){
        printf("Ingresa el dato ""%d"" del conjunto 3: ", i + 1);
        scanf("%d", &arre3[i]);

        if(i>3){
            printf("\n\n");
        }
    }

    //hacemos la suma
    for(i=0; i<5; i++){
        arreglo[i] = arre1[i] + arre2[i] + arre3[i]; //sumando los tres arreglos anteriores
    }

    printf("\nLa suma de los datos es:\n");
    for(i=0; i<5; i++){
        printf("Resultado %d es:  %d \n\n", i + 1, arreglo[i]);
    }

    return 0;
}