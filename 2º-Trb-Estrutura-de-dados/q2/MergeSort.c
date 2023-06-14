#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 1000000

void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDir = fim - meio;

    int *esquerda = malloc(tamanhoEsq * sizeof(int));
    int *direita = malloc(tamanhoDir * sizeof(int));

    for (int i = 0; i < tamanhoEsq; i++) {
        esquerda[i] = vetor[inicio + i];
    }
    for (int j = 0; j < tamanhoDir; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < tamanhoEsq && j < tamanhoDir) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsq) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDir) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
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
    mergeSort(vetor, 0, TAMANHO_VETOR - 1);
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

