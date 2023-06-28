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
int current_weight; 
int current_value; 

void branch_and_bound(Item items[], int n, int capacity, int level) {
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
        current_weight += items[level].weight;
        current_value += items[level].value;
        branch_and_bound(items, n, capacity, level + 1);
        current_weight -= items[level].weight;
        current_value -= items[level].value;
    }

    current_solution[level] = 0;
    branch_and_bound(items, n, capacity, level + 1);
}

int main() {
    FILE *out = fopen("tempo.txt", "w");
    double kk;
    clock_t t;
    
    for(int z = 0; z < 100; z++){
    t = clock();
    int n = MAX_N; 
    int capacity; 
    Item items[MAX_N]; 

    for (int i = 0; i < n; i++) {
        items[i].weight = rand() % 200;
        items[i].value = rand() % 200;
    }

    
    best_value = 0;
    current_weight = 0;
    current_value = 0;

    
    branch_and_bound(items, n, capacity, 0);
    t = clock() - t;
    kk = (double) t/(CLOCKS_PER_SEC/1000);
    fprintf(out, "%f\n", kk);
    }
    return 0;
}
