//programa que captura CALIFICACIONES

#include<stdio.h>
int main(){
    int tam=0, i=0;
    float suma=0, promedio=0, menor=0, mayor=0;

    printf("Ingrese el numero de calificaciones a ingresar: ");
    scanf("%d", &tam); //para que el usuario diga la cantidad de datos

    float calificaciones[tam]; //segun el numero guardado en la variable que dio el usuario

    for(i=0; i<tam; i++){
        printf("Ingrese la calificacion %d: ", i+1);
        scanf("%f", &calificaciones[i]); //para guardarlas en el arreglo
        suma = suma + calificaciones[i]; //para sacar el promedio al final
    }

    promedio= suma / tam; //resultado de la suma ENTRE tam que es el numero de datos

    //para imprimir las calificaciones almacenadas
    printf("\n\nLas calificaciones son: \n");
    for(i=0; i<tam; i++){
        printf("%.2f ", calificaciones[i]);

        //para sacar la menor calificacion
        if(i==0){
            menor = calificaciones[i];
            mayor = calificaciones[i];//la primer calificacion es nuestro numero menor y mayor
        } else {
            if(calificaciones[i] < menor){ //si se ingresa una calificacion mas baja que la primera
                menor = calificaciones[i];
            } else if(calificaciones[i] > mayor){ //si la calificacion es mayor que la anterior
                mayor = calificaciones[i];
            }
        }
    }

    printf("\n\n El promedio es: %.1f\n", promedio);
    printf("\nLa calificacion menor fue de: %.1f\n", menor);
    printf("\nLa calificacion mayor fue de: %.1f\n", mayor);


}