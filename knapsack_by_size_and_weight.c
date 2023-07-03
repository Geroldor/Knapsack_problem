#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define CAPACITY 500

typedef struct item{
    int size;
    int weight;
    float mean;
}item;

typedef struct bag{
    int max_size;
    int max_weight;
    int size;
    int weight;
    item itens[MAX];
}bag;

item itens[MAX];
bag b;

void ordenador(){
    item aux;
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if(itens[j].mean > itens[j+1].mean){
                aux = itens[j];
                itens[j] = itens[j+1];
                itens[j+1] = aux;
            }
        }
    }
}



int main(){
    FILE *time_exec;
    FILE *sizes = fopen("sizes.txt", "r");
    FILE *weights = fopen("weights.txt", "r");
    time_exec = fopen("tempos.txt", "w");
    float tempo;
    clock_t t;
    for(int o = 0; o < MAX; o++){
        t = clock();
        b.max_size = CAPACITY;
        b.max_weight = CAPACITY;

        for (int i = 0; i < MAX; i++)
        {
            itens[i].size = fscanf(sizes, "%d", &itens[i].size);
            itens[i].weight = fscanf(weights, "%d", &itens[i].weight);
            itens[i].mean = (float) itens[i].size / itens[i].weight;
        }
        ordenador();
        int j = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (b.size + itens[i].size <= b.max_size)
            {
                b.size = b.size + itens[i].size;
                b.weight = b.weight + itens[i].weight;
                b.itens[j] = itens[i];
                j++;
            }
        }
        t = clock() - t;
        tempo = (double) t/(CLOCKS_PER_SEC/1000);
        fprintf(time_exec, "%lf\n", tempo);
    }
    return 0;
}