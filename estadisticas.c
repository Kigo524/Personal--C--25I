/*Calculadora de Estadísticas:
Crea un programa que permita al usuario ingresar una serie de números 
y luego calcule la media, mediana y moda de esos números. 
Utiliza arrays para almacenar los datos.*/
//voy a usar 10 numeros solo para ver que funciona.

#include<stdio.h>
    int nums[10];
    int i=0, contMax = 0, suma = 0, modaT = 0; //modaT de Temporal
    int j = 0;

    void pedirNumeros();
    void media();
    void mediana();
    void moda();
    void imprimirNumeros();

    /******************************************************************************** */

int main(){

    pedirNumeros();
    moda();
    
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