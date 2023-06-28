#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *size;
    FILE *weight;
    int x;//, numero;

    size = fopen("sizes.txt", "w");
    weight = fopen("weights.txt", "w");
    printf("informe a quantidade de valores a serem gerados: ");
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        //numero = rand() % 190 + 10;
        fprintf(size, "%d\n", (rand() % 200));
        fprintf(weight, "%d\n", (rand() % 200));
    }

    return 0;
}