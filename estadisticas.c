/*Calculadora de Estadísticas:
Crea un programa que permita al usuario ingresar una serie de números 
y luego calcule la media, mediana y moda de esos números. 
Utiliza arrays para almacenar los datos.*/
//voy a usar 10 numeros solo para ver que funciona.

#include<stdio.h>
    int nums[10];
    int i=0, contMax = 0, suma = 0, modaT = 0; //modaT de Temporal
    int j = 0;
    int cantNums = 0; //para saber la cantidad de numeros que se ingresa
    float medianaT = 0; //float para manejar promedios
    float mediaT = 0; //global para la media

    void pedirNumeros();
    void media();
    void mediana();
    void moda();
    void imprimirNumeros();

    /******************************************************************************** */

int main(){
    pedirNumeros();
    media();
    mediana();
    moda();
    imprimirNumeros();
    return 0;
}

    /******************************************************************************** */

//pidiendo numeros
void pedirNumeros(){
    for(i=0; i<10; i++){
        printf("Ingresa el numero %d: ", i+1);
        scanf("%d", &nums[i]);

        //sumando numeros para la MEDIA
        suma = suma + nums[i];
        cantNums++; //que va contando cuantos numeros se ingresan
    }
}

void moda(){
    for(i=0; i<10; i++){
        int cont = 0; //contador del numero actual en i
        for(j=0; j<10; j++){
            if(nums[i] == nums[j]){ //comparo el numero actual en i con todos los demas que se guardaron en j
                cont++; //aumenta el contador si coinciden los numeros
            }
        }

        if(cont > contMax){ //despues de contar las veces que aparece el numero actual, se compara si hay un numero que se repite mas
            contMax = cont; //entonces contMax se actualiza
            modaT = nums[i]; //se guarda el valor del numero que se repite mas
        }
    }
}

void mediana(){
    //primero es ordenar los numeros (ordenamiento de burbuja)
    int bandera, aux;
    do{
        bandera=0;
        for(i=0; i<10; i++){
            
            if(nums[i]>nums[i+1]){

                bandera=1; // la bandera para indicar que el programa corre por aqui

                aux=nums[i];
                nums[i]= nums[i+1];
                nums[i+1]=aux;
            }
        }
    }while(bandera==1);

    //para cuando los datos son par
    if(cantNums % 2 == 0){
        int medio1 = nums[(cantNums / 2) - 1]; //numero central izquierdo
        int medio2 = nums[(cantNums / 2)];
        medianaT = (medio1 + medio2) / 2; //sacar promedio de los 2 centrales
    } else{ //para cuando los datos son impares
        medianaT = nums[cantNums / 2]; //numero central
    }
}

void media(){
    mediaT = (float)suma / cantNums;
}

//para imprimir resultados
void imprimirNumeros() {
    // Imprimir los números ingresados
    printf("Los numeros ingresados son:\n");
    for (i = 0; i < cantNums; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    //imprimir la media
    printf("La media es: %.2f\n", mediaT);

    //imprimir la mediana
    printf("Los numeros ordenados son:\n ");
    for(i=0; i<cantNums; i++){
        printf("%d, ", nums[i]);
    }
    printf("\n");
    printf("La mediana es: %.2f\n", medianaT);

    //imprimiendo moda
    printf("La moda es: %d (aparece %d veces)\n", modaT, contMax);
}