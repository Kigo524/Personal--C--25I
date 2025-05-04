#include<stdio.h>
#include <stdlib.h> // Para rand() y srand()
#include <time.h>   // Para inicializar srand()

void inicializarMatriz(); // Inicializa la matriz con espacios vacíos
void imprimir(); // Imprime la matriz actual
void tiraUsuario(); // Turno del usuario
void tiraComputadora(); // Turno de la computadora
void verificarGanador(); // Verifica si hay un ganador

int cont = 0;
int resultadoFinal = 0; // Como bandera. Resultado del juego: 0=empate 1=usuario 2=compu
char matriz[4][4];

int main() {
    srand(time(NULL)); //genera solo un numero aleatorio
    inicializarMatriz();
    imprimir();

    do {
        tiraUsuario();
        imprimir();
        verificarGanador();
        if (resultadoFinal == 1) {
            printf("******* Felicidades! Has ganado! *******\n");
            break;
        }

        cont++; //despues del tiro del usuario

        tiraComputadora();
        imprimir();
        verificarGanador();
        if (resultadoFinal == 2) {
            printf("La computadora ha ganado.\n");
            break;
        }

        cont++; //despues del tiro de la compu

    } while (cont < 16); // Es un tablero de 4x4 entonces son 16 casillas

    if (resultadoFinal == 0) {
        printf("Es un empate.\n");
    }

    return 0;
}

// Inicializa la matriz con espacios vacíos
void inicializarMatriz() {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            matriz[i][j] = ' ';
        }
    }
}

// Imprime la matriz actual
void imprimir() {
    int i, j;

    // Imprimir encabezado de columnas
    printf("   "); // Espacio para alinear las coordenadas con las filas
    for (j = 0; j < 4; j++) {
        printf(" %d ", j); // Imprime los números de las columnas
    }
    printf("\n");

    // Imprimir filas con sus números
    for (i = 0; i < 4; i++) {
        printf(" %d ", i); // Imprime el número de la fila
        for (j = 0; j < 4; j++) {
            printf("[%c]", matriz[i][j]); // Imprime el contenido de la celda
        }
        printf("\n");
    }
    printf("\n");
}

// Turno del usuario
void tiraUsuario() {
    int x, y;
    do {
        printf("Indica en que casilla deseas tirar (y, x): ");
        scanf("%d %d", &x, &y); //lee las coordenadas
        if (x >= 0 && x < 4 && y >= 0 && y < 4 && matriz[x][y] == ' ') {
            matriz[x][y] = 'x'; //marca la casilla con x
            break;
        } else {
            printf("Casilla inválida. Intenta de nuevo\n");
        }
    } while (1); //while 1 para que siga pidiendo coordenas hasta que sea valida la casilla
}

// Turno de la computadora
void tiraComputadora() {
    int i, j;

    // Para intentar ganar primero
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(matriz[i][j] == ' ') { // Encuentra una celda vacía
                matriz[i][j] = 'O'; // Simula el movimiento
                verificarGanador(); // Verifica si este tiro gana el juego
                if(resultadoFinal == 2) { // Si la compu gana
                    return; // Termina el tiro
                }
                matriz[i][j] = ' '; // Deshace el movimiento
            }
        }
    }

    // Para bloquear al usuario si es que no puede ganar
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(matriz[i][j] == ' ') { // Encuentra una celda vacía
                matriz[i][j] = 'x'; // Coloca una x para probar si gana el usuario
                verificarGanador(); // Verifica si con ese movimiento ganaría el usuario
                if(resultadoFinal == 1) {
                    matriz[i][j] = 'O'; // Bloquea al usuario
                    resultadoFinal = 0; // Restablece el resultado
                    return; // Termina el tiro
                }
                matriz[i][j] = ' '; // Si no bloquea al usuario, deshace ese movimiento
            }
        }
    }

    // Para elegir una casilla vacía aleatoria si no hay peligro ni gane
    int casillasVacias = 0;
    // Contar las casillas vacías
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(matriz[i][j] == ' ') {
                casillasVacias++;
            }
        }
    }

    // Si hay casillas vacías, que elija una aleatoria
    if(casillasVacias > 0) {
        int casillaAleatoria = rand() % casillasVacias; // Elegir un número aleatorio dentro de la matriz
        casillasVacias = 0;

        // Para encontrar la casilla correspondiente al número aleatorio
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if(matriz[i][j] == ' ') {
                    if(casillasVacias == casillaAleatoria) {
                        matriz[i][j] = 'O'; // Realiza el movimiento
                        return; // Termina el tiro
                    }
                    casillasVacias++;
                }
            }
        }
    }
}

// Verifica si hay un ganador
void verificarGanador() {
    int i, j;

    // Verificar filas
    for (i = 0; i < 4; i++) {
        if (matriz[i][0] != ' ' && matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][2] == matriz[i][3]) {
            if (matriz[i][0] == 'x') {
                resultadoFinal = 1; // El usuario gana
                break;
            } else if (matriz[i][0] == 'O') {
                resultadoFinal = 2; // La computadora gana
                break;
            }
        }
    }

    // Verificar columnas
    for (j = 0; j < 4; j++) {
        if (matriz[0][j] != ' ' && matriz[0][j] == matriz[1][j] && matriz[1][j] == matriz[2][j] && matriz[2][j] == matriz[3][j]) {
            if (matriz[0][j] == 'x') {
                resultadoFinal = 1; // El usuario gana
                break;
            } else if (matriz[0][j] == 'O') {
                resultadoFinal = 2; // La computadora gana
                break;
            }
        }
    }

    // Si no hay ganador, mantener resultadoFinal en 0
    if(resultadoFinal == 0){
        resultadoFinal = 0; //no hay ganador
    }
}