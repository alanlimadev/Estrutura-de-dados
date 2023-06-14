#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 100

void insertionSort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
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
    insertionSort(vetor, TAMANHO_VETOR);
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

