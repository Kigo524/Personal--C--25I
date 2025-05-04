/*Crea tres arreglos de enteros de tamaño 10. 
Llena el primer arreglo con números enteros ingresados por el usuario. 
Luego, copia los números positivos en el segundo arreglo, 
los negativos en el tercer arreglo y cuenta cuántos números hay en cada uno.*/

#include<stdio.h>
int main(){

    int arr[10], positivos[10], negativos[10];
    int i=0, contPositivo=0, contNegativo=0, contCeros=0;

    //pidiendo datos
    for(i=0; i<10; i++){
        printf("Ingresa el dato %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //clasificando datos
    for(i=0; i<10; i++){
        if(arr[i] > 0){
            positivos[contPositivo++] = arr[i]; //Si es positivo, lo copio al arreglo positivo y aumento el contador
        } else if(arr[i]<0){
            negativos[contNegativo++] = arr[i];
        } else if(arr[i] == 0){ //si existe algun 0 en los datos
            contCeros++;
        }
    }

    printf("\n");

    //imprimiendo resultados
    //numeros positivos
    printf("Hay %d numeros positivos, son: \n", contPositivo);
    for(i=0; i<contPositivo; i++){ //usando contPositivo como limite
        printf("%d, ", positivos[i]);
    }

    printf("\n");

    //numeros negativos
    printf("Hay %d numeros negativos, son: \n", contNegativo);
    for(i=0; i<contNegativo; i++){ //se usa contNegativo como limite
        printf("%d, ", negativos[i]);
    }

    printf("\n");

    //ceros
    printf("Hay %d datos que son cero\n", contCeros);
    if(contCeros == 0){ //si no hay ningun cero
        printf("No hay datos que sean ceros\n");
    }

    return 0;
}