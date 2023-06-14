#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 1000000

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int inicio, int fim) {
    int pivot = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivot) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, fim);
    }
}

int main() {
    int *vetor = malloc(TAMANHO_VETOR * sizeof(int));
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = (rand() % 1000) + 1;
    }

    // Imprimir o vetor desordenado
    printf("Vetor desordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    clock_t inicio = clock();
    quickSort(vetor, 0, TAMANHO_VETOR - 1);
    clock_t fim = clock();

    // Imprimir o vetor ordenado
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    double tempoExecucao = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f milissegundos\n", tempoExecucao);

    free(vetor);

    return 0;
}

