/*Un pirata desea encontrar un gran tesoro que fue escondido en una isla, 
ayúdalo a encontrarlo.Representa la isla con una matriz de 7 x 7. 

La orilla de la matriz representará la orilla de la isla, la cual secompone 
de Agua, coloca la letra A en cada casilla de la orilla de la matriz para representarla.

Ubica al pirata y al tesoro en la matriz en coordenadas aleatorias, 
evitando las casillas del agua. 

Pararepresentar al Pirata usa la letra P y para representar al Tesoro utiliza la letra T

AQUI EL MONITO SE MUEVE ALEATORIAMENTE*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void inicializarMatriz();
void imprimir();
void colocarPirataTesoro();
void avanzar();

int flag;
char matriz[7][7];
int pirataX, pirataY; //para la posicion del pirata

int main(){
    srand(time(NULL)); // para generar numeros aleatorios
    inicializarMatriz(); //llena la matriz con A en el marco y espacio en lo demas
    colocarPirataTesoro(); //coloca la P(pirata) y la T(tesoro) en posiciones aleatorias
    imprimir(); //imprime la matriz inicial
    do{
        avanzar(); //moverl el pirata
        if(flag==0){
            imprimir(); //solo imprime la matriz si el juego no ha terminado
        }
    }while(flag==0); //repite hasta que el pirata encunetre el tesoro o caiga al agua
}

void inicializarMatriz(){
    int i, j;
    for(i=0; i<7; i++){ //para recorrer filas
        for(j=0; j<7; j++){ //para recorrer columnas
            if(i==0 || i==6 || j==0 || j==6) { //i es para las filas superior e inferior, j es para las columnas
                matriz[i][j]= 'A'; //coloca A en los bordes con esto
            } else {
                matriz[i][j] = ' '; //Espacios en lo demas
            }
        }
    }
}

void colocarPirataTesoro() {
    int tesoroX, tesoroY;

    //generar coordenadas aleatorias para el prirata
    do{
        pirataX = 1 + rand() % 5; //silas entre 1 y 5 para no usar el marco
        pirataY = 1 + rand() % 5; //columnas entre 1 y 5 para no usar el marco
    }while (matriz[pirataX][pirataY] != ' '); //que sea mientras las casillas no esten ocupadas

    matriz[pirataX][pirataY] = 'P'; //colocar la P despues de revisar lo de arriba

    do{ //ahora para hacer el tesoro aleatorio
        tesoroX = 1 + rand() % 5; //filas entre 1 y 5 para no usar el marco 
        tesoroY = 1 + rand() % 5; //columnas entre 1 y 5
    }while(matriz[tesoroX][tesoroY] != ' '); //mientras que no este ocuapa la casilla

    matriz[tesoroX][tesoroY] = 'T'; //colocar el tesoro
}

void imprimir(){
    int i, j;
    for(i=0; i<7; i++){
        for(j=0; j<7; j++){
            printf("[%c]", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void avanzar(){
    int direccion;
    int nuevoX = pirataX, nuevoY = pirataY; //nuevo solo para diferenciar la posicion del pirata
    
    do {
        direccion = 1 + rand() % 4; //direccion 1=norte, 2=sur, 3=este, 4=oeste

        if (direccion == 1) {
            nuevoX = pirataX - 1;
            nuevoY = pirataY;
            printf("Avanzar al NORTE\n");
        } else if (direccion == 2) {
            nuevoX = pirataX + 1;
            nuevoY = pirataY;
            printf("Avanza al SUR\n");
        } else if (direccion == 3) {
            nuevoX = pirataX;
            nuevoY = pirataY + 1;
            printf("Avanza al ESTE\n");
        } else if (direccion == 4) {
            nuevoX = pirataX;
            nuevoY = pirataY - 1;
            printf("Avanza al OESTE\n");
        }
    } while (matriz[nuevoX][nuevoY] != ' ' && matriz[nuevoX][nuevoY] != 'T' && matriz[nuevoX][nuevoY] != 'A');

    //ver si el pirata cae al agua
    if(matriz[nuevoX][nuevoY] == 'A'){
        printf("*****EL JUEGO HA TERMINADO -- EL PIRATA SE HA AHOGADO*****\n\n");
        flag = 1; //termina el juego por el do-while
        return;
    }

    //ver si el pirata encuentra el tesoro
    if(matriz[nuevoX][nuevoY] == 'T'){
        printf("***** EL PIRATA HA ENCONTRADO EL TESORO *****\n\n");
        flag = 1; //termina el juego
        return;
    }

    //para dejar limpio el espacio donde estaba el pirata antes de mover
    matriz[pirataX][pirataY] = ' '; //para dejarla vacia la casilla anterior
    pirataX = nuevoX;
    pirataY = nuevoY;
    matriz[pirataX][pirataY] = 'P'; //pone la P en la nueva posicion
}