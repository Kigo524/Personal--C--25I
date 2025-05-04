//programa que busca una matricula

#include<stdio.h>
int main(){
    int matriculas[10] = {201923, 201912, 201901, 201819, 201854, 201836, 201815, 20194, 201903, 201844};
    int i=0, matricula=0;
    int flag = 0; //el 0 es falso y 1 es verdadero

    //se solicita la matricula a buscar
    printf("Introduce la matricula que deseas buscar: ");
    scanf("%d", &matricula);

    //para buscar la matricula
    for(i=0; i<10; i++){
        printf("Comparando con el elmento con indice %d... \n", i); //para mostrar los pasos que va comparando
        if(matricula == matriculas[i]){
            printf("Matricula encontrada en el indice %d", i);
            flag = 1; //para indicarme que se encontro la matricula
            break; //si ya encontro la matricula, que pare de buscar
        }
    }

    if(flag == 0){ //si no encontro la matricula con flag en 0
        printf("\n La matricula no se encuentra registrada");
    }
}