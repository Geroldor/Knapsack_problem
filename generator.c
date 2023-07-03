#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *size;
    FILE *weight;
    
    size = fopen("sizes.txt", "w");
    weight = fopen("weights.txt", "w");
    for(int i = 0; i < 100; i++){
        //numero = rand() % 190 + 10;
        fprintf(size, "%d\n", (rand() % 200));
        fprintf(weight, "%d\n", (rand() % 200));
    }

    return 0;
}