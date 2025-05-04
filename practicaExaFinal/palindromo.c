// buscar que una palabra se lea igual al derecho y al reves
//falta corregirlo

#include<stdio.h>
#include<string.h>

int main(){
    char palabra[20];
    char sinEspacio[20];
    char invertida[20];
    int i=0, j=0, cont=0;

    printf("Inserte la palabra: ");
    gets(palabra);

    for(i=0; i<strlen(palabra); i++){
        if(palabra[i] != ' '){
            sinEspacio[cont] = palabra[i];
            cont++;
        }
    }

    strlen(sinEspacio);

    for(i=cont - 1; i>=0; i--){ 
        for(j=0; j<=cont; j++){
            invertida[j] = sinEspacio[i];
        }
    }

    if(strcmp(sinEspacio, invertida) == 0){
        printf("Es un palindromo");
    } else {
        printf("NO es un palindromo");
    }
}