//programa que guarda estaturas

#include<stdio.h>
int main(){
    float estaturas[5];
    int i = 0;

    //para guardar las edades
    for(i=0; i<5; i++){
        printf("Introduzca la edad %d: ", i+1);
        scanf("%f", &estaturas[i]);
    }

    printf("\n\n");

    printf("No. \t Estatura\n"); //imprime formato de la tabla

    //imrime los valores de la tabla
    for(i=0; i<5; i++){
        printf("%d \t %.2f\n", i+1, estaturas[i]);
    }
}