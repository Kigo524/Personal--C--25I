/*Calculadora de Estadísticas:
Crea un programa que permita al usuario ingresar una serie de números 
y luego calcule la media, mediana y moda de esos números. 
Utiliza arrays para almacenar los datos.*/
//voy a usar 10 numeros solo para ver que funciona.

#include<stdio.h>
    int nums[10];
    int modas[10]; //arreglo para almacenar si hay mas de una moda
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
    int suma = 0, i;
    for(i=0; i<10; i++){
        printf("Ingresa el numero %d: ", i+1);
        scanf("%d", &nums[i]);

        //sumando numeros para la MEDIA
        suma = suma + nums[i];
        cantNums++; //que va contando cuantos numeros se ingresan
    }
    mediaT = (float)suma / cantNums; //calucla la media como flotante
}

void moda() {
    int contMax = 0; // Maxima repeticion encontrada
    int modaCont = 0; // contador de modas
    int i, j;

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
    // Imprimir las modas
    printf("La(s) moda(s) es/son: ");
    for (int i = 0; i < modaCont; i++) {
        printf("%d ", modas[i]);
    }
    printf("(aparece %d veces)\n", contMax);
}

void mediana(){
    //primero es ordenar los numeros (ordenamiento de burbuja)
    int aux;
    for (int i = 0; i < cantNums - 1; i++) {
        for (int j = 0; j < cantNums - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                aux = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = aux;
            }
        }
    }

    // Calcular la mediana
    if (cantNums % 2 == 0) { // Si la cantidad de números es par
        int medio1 = nums[(cantNums / 2) - 1]; // Número central izquierdo
        int medio2 = nums[cantNums / 2];       // Número central derecho
        medianaT = (medio1 + medio2) / 2.0;    // Promedio de los dos números centrales
    } else { // Si la cantidad de números es impar
        medianaT = nums[cantNums / 2]; // Número central
    }
}

// Imprimiendo los resultados
void imprimirNumeros() {
    // Imprimir los números ingresados
    printf("Los numeros ingresados son:\n");
    for (int i = 0; i < cantNums; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Imprimir la media
    printf("La media es: %.2f\n", mediaT);

    // Imprimir la mediana
    printf("Los numeros ordenados son: ");
    for (int i = 0; i < cantNums; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("La mediana es: %.2f\n", medianaT);

    // Imprimir las modas (ya se imprimen en la función moda)
}