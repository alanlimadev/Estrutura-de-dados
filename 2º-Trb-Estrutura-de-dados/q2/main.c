#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 10

void gerarVetorAleatorio(int vetor[], TAMANHO_VETOR) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
}


void gerarVetor(){
	int vetor[TAMANHO_VETOR];
    int i;

    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    // Preenche o vetor com valores aleatórios
    for (i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand();
    }

    // Imprime o vetor gerado
    printf("Vetor gerado:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


int main() {
    
    gerarVetor();

    return 0;
}



