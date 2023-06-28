#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *filename;
    float tempo, soma, media, aux;
    FILE *t;
    t = fopen("tempos_de_execucao(size_&_weight).txt", "r");
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
    return 0;
}