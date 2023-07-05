#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 100 
#define MAX_W 100 

typedef struct {
    int weight;
    int value;
} Item;

int best_value; 
int best_solution[MAX_N];  
int current_solution[MAX_N];
Item items[MAX_N];   
int current_weight; 
int current_value; 

void branch_and_bound(int n, int capacity, int level) {
    if (level == n) {
        if (current_value > best_value) {
            best_value = current_value;
            for (int i = 0; i < n; i++) {
                best_solution[i] = current_solution[i];
            }
        }
        return;
    }

    if (current_weight + items[level].weight <= capacity) {
        current_solution[level] = 1;
        current_weight = current_weight + items[level].weight;
        current_value = current_value + items[level].value;
        branch_and_bound(n, capacity, level + 1);
        current_weight = current_weight - items[level].weight;
        current_value = current_value - items[level].value;
    }

    current_solution[level] = 0;
    branch_and_bound(n, capacity, level + 1);
}

void ordenador(){
    Item aux;
    for (int i = 1; i <= MAX_N; i++)
    {
        for (int j = 0; j < MAX_N - 1; j++)
        {
            if(items[j].weight > items[j+1].weight){
                aux = items[j];
                items[j] = items[j+1];
                items[j+1] = aux;
            }
        }
    }
}


int main() {
    FILE *out = fopen("tempos.txt", "w");
    //FILE *sizes = fopen("sizes.txt", "r");
    //FILE *weights = fopen("weights.txt", "r");
    double kk;
    clock_t t;
    
    for(int z = 0; z < 100; z++){
        t = clock();
        int n = MAX_N; 
        int capacity = 200; 
    

        for (int i = 0; i < n; i++) {
            //items[i].weight = fscanf(weights, "%d", &items[i].weight);
            //items[i].value = fscanf(sizes, "%d", &items[i].value);
            items[i].value = rand() % 200;
            items[i].weight = rand() % 100;
        }

    
        best_value = 0;
        current_weight = 0;
        current_value = 0;
        //ordenador();
    
        branch_and_bound(n, capacity, 0);
        t = clock() - t;
        kk = (double) t/(CLOCKS_PER_SEC/1000);
        fprintf(out, "%f\n", kk);
        printf("%d\n", best_value);
    }
    return 0;
}
