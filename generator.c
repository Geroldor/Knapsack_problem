#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *size;
    FILE *weight;
    size = fopen("sizes.txt", "w");
    weight = fopen("weights.txt", "w");
    for(int i = 0; i < 10000; i++){
        fprintf(size, "%d\n", (rand() % 200) + 300);
        fprintf(weight, "%d\n", (rand() % 100));
    }

    return 0;
}