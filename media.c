#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void media(){
    float tempo, soma, media, aux = 0;
    FILE *t;
    t = fopen("tempos.txt", "r");
    if(t == NULL){
        printf("\nErro na abertura do arquivo\n");
        exit(1);
    }
    while (!feof(t))
    {
        fscanf(t, "%f", &tempo);
        soma = soma + tempo;
        aux++;
    }
    media = soma/aux;
    printf("\nResultado:\t%f\n", media);
}