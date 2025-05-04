// Porgrama que almacena edades

#include<stdio.h>

int main(){
    int edades[10];
    int i=0;

    //Para guardar los datos
    for(i=0; i<10; i++){
        printf("Introduce la edad: ");
        scanf("%d", &edades[i]); //para que en la primera iteracion se guarde en 0, en la segunda en 1...
    }

    printf("\n\n"); //espacios solo para mejora visual

    //Para imprimir los valores almacenados
    for(i=0; i<10; i++){
        printf("%d ", edades[i]); //para que imprima de uno en uno hasta el 9
    }
}