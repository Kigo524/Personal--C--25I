/*Crea tres arreglos de enteros, cada uno con 5 calificaciones. 
Llena cada arreglo con calificaciones ingresadas por el usuario. 
Luego, calcula el promedio de cada grupo y muestra los promedios.*/

#include<stdio.h>
int main(){
    float arr1[5], arr2[5], arr3[5];
    int i;
    float sum1=0, sum2=0, sum3=0;
    float prom1=0, prom2=0, prom3=0;
    int cont1=0, cont2=0, cont3=0; //agrego contadores por si se cambia el tamano del arreglo

    //solicitando datos
    printf("Arreglo 1\n");
    
    for(i=0; i<5; i++){
        printf("Introduce la calificacion %d: ", i + 1);
        scanf("%f", &arr1[i]);
        sum1 = sum1 + arr1[i];
        cont1++;
    }

    printf("\n");

    //arreglo 2
    printf("Arreglo 2\n");
    
    for(i=0; i<5; i++){
        printf("Introduce la calificacion %d: ", i + 1);
        scanf("%f", &arr2[i]);
        sum2 = sum2 + arr2[i];
        cont2++;
    }

    printf("\n");

    //arreglo 3
    printf("Arreglo 3\n");
    
    for(i=0; i<5; i++){
        printf("Introduce la calificacion %d: ", i + 1);
        scanf("%f", &arr3[i]);
        sum3 = sum3 + arr3[i];
        cont3++;
    }

    printf("\n");

    //sacando promedios
    prom1 = sum1 / cont1;
    prom2 = sum2 / cont2;
    prom3 = sum3 / cont3;

    //imprimiendo resultados
    //primer conjunto
    printf("El promedio del primer arreglo es: %.2f\n\n", prom1);
    printf("El promedio del segundo arreglo es: %.2f\n\n", prom2);
    printf("El promedio del tercer arreglo es: %.2f\n\n", prom3);

    return 0;
}