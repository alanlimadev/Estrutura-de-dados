#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 1000000

void heapify(int vetor[], int tamanho, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    if (direita < tamanho && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    if (maior != indice) {
        int temp = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = temp;

        heapify(vetor, tamanho, maior);
    }
}

void heapSort(int vetor[], int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vetor, tamanho, i);
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
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
    heapSort(vetor, TAMANHO_VETOR);
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

