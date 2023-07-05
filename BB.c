#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    int valor;
    int peso;
} Item;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int mochilaRecursiva(Item* itens, int capacidade, int n, int** matriz) {
    if (n == 0 || capacidade == 0)
        return 0;

    if (matriz[n][capacidade] != -1)
        return matriz[n][capacidade];

    if (itens[n - 1].peso > capacidade)
        return matriz[n][capacidade] = mochilaRecursiva(itens, capacidade, n - 1, matriz);

    int incluirItem = itens[n - 1].valor + mochilaRecursiva(itens, capacidade - itens[n - 1].peso, n - 1, matriz);
    int excluirItem = mochilaRecursiva(itens, capacidade, n - 1, matriz);

    return matriz[n][capacidade] = max(incluirItem, excluirItem);
}

int mochilaBranchAndBound(Item* itens, int capacidade, int n) {
    int** matriz = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++)
        matriz[i] = (int*)malloc((capacidade + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacidade; j++) {
            matriz[i][j] = -1;
        }
    }

    return mochilaRecursiva(itens, capacidade, n, matriz);
}

int main() {
    FILE *sizes = fopen("sizes.txt", "r");
    FILE *weights = fopen("weights.txt", "r");
    FILE *out = fopen("tempos.txt", "w");
    int capacidadeMochila = 500;
    int quantidadeItens = 10000;
    double soma = 0;
    double media = 0;
    clock_t t;
    Item* itens = (Item*)malloc(quantidadeItens * sizeof(Item));
    for (int i = 0; i < quantidadeItens; i++) {
        fscanf(sizes, "%d", &itens[i].valor);
        fscanf(weights, "%d", &itens[i].peso);
    }
    
    for(int z = 0; z<100; z++){
    t = clock();
    int valorMaximo = mochilaBranchAndBound(itens, capacidadeMochila, quantidadeItens);
    t = clock() - t;
    double time_taken = (double) t/CLOCKS_PER_SEC;
    soma = soma + time_taken;
    fprintf(out, "%f\n", time_taken);
    printf("Tempo executado teste %d: %f\n", z+1, time_taken);
    }
    media = soma/100;
    printf("Media: %f\n", media);
    free(itens);
    return 0;
}
