#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 5

typedef struct pilha{
	int n;
	int v[MAX];
}Pilha;

Pilha* pilha_cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	if(p == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->n = 0;
	return p;
}

/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p){
	return p->n == 0;
}

/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	if(p->n == MAX){
		printf("Capacidade da Pilha Estourou!!!\n");
		exit(1);
	}
	p->v[p->n] = info;
	p->n = p->n + 1;
}

/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha* p){
	int a;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	a = p->v[p->n-1];
	p->n--;
	return a;
}

/*Fun��o que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha* p){
	int i;
	for(i = p->n-1; i >= 0; i--){
		printf("%d\n", p->v[i]);
	}
}

/*Libera o espa�o alocado para uma pilha.*/
void pilha_libera(Pilha* p){
	free(p);
}

//TRABALHO: fun��o que receba uma pilha como argumento e retorne o valor armazenado em seu topo.
int topo(Pilha* p){
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	return p->v[p->n-1];	
}

//TRABALHO: fun��o que retorne o n�mero de elementos da pilha que possuem o campo info com valor �mpar
int impares(Pilha* p){
	int i, cont = 0;
	for(i = p->n-1; i >= 0; i--){
		if((p->v[i] % 2) != 0)
			cont++;		
	}
	return cont;
}

//TRABALHO: fun��o que verifique quais s�o os elementos pares de uma pilha p1 e que os empilhe em ordem crescente em uma pilha p2
Pilha* empilha_pares(Pilha* p1, Pilha* p2){
	int i, a;
	for(i = p1->n-1; i >= 0; i--){
		if((p1->v[i] % 2) == 0)
			pilha_push(p2, p1->v[i]);	
	}
	
	
	return p2;
}
