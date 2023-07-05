#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CAPACITY 500

typedef struct item{
    int size;
    int weight;
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
            if(itens[j].weight > itens[j+1].weight){
                aux = itens[j];
                itens[j] = itens[j+1];
                itens[j+1] = aux;
            }
        }
    }
}



int main(){
    FILE *time_exec;
    time_exec = fopen("tempos.txt", "w");
    float tempo;
    clock_t t;
    t = clock();
    FILE *s = fopen("sizes.txt", "r");
    FILE *w = fopen("weights.txt", "r");
    b.max_size = MAX;
    b.max_weight = CAPACITY;

    for (int i = 0; i < MAX; i++)
    {
        fscanf(s, "%d", &itens[i].size);
        fscanf(w, "%d", &itens[i].weight);
    }
    ordenador();
    int j = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (b.weight + itens[i].weight < b.max_weight)
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
    fclose(time_exec);
    fclose(s);
    fclose(w);
}