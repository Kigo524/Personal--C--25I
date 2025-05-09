/*Calculadora de Estadísticas:
Crea un programa que permita al usuario ingresar una serie de números 
y luego calcule la media, mediana y moda de esos números. 
Utiliza arrays para almacenar los datos.*/
//voy a usar 10 numeros solo para ver que funciona.

#include<stdio.h>
    int nums[10];
    int modas[10]; //arreglo para almacenar si hay mas de una moda
    int i=0, contMax = 0, suma = 0, modaCont = 0; //modaT de Temporal
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

void moda() {
    contMax = 0; // Reiniciar el máximo contador
    modaCont = 0; // Reiniciar el contador de modas

    for (i = 0; i < 10; i++) {
        int cont = 0; // Contador del número actual en i
        for (j = 0; j < 10; j++) {
            if (nums[i] == nums[j]) { // Comparo el número actual en i con todos los demás que se guardaron en j
                cont++; // Aumenta el contador si coinciden los números
            }
        }

        if (cont > contMax) { // Si encontramos un número con mayor frecuencia
            contMax = cont;  // Actualizamos el máximo
            modaCont = 0;   // Reiniciamos el contador de modas
            modas[modaCont++] = nums[i]; // Guardamos la nueva moda
        } else if (cont == contMax) { // Si la frecuencia es igual al máximo
            int yaGuardado = 0;
            for (int k = 0; k < modaCont; k++) { // Verificar si ya está guardado
                if (modas[k] == nums[i]) {
                    yaGuardado = 1;
                    break;
                }
            }
            if (!yaGuardado) { // Si no está guardado, lo agregamos
                modas[modaCont++] = nums[i];
            }
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
    printf("La moda es: %d (aparece %d veces)\n", modaCont, contMax);
}