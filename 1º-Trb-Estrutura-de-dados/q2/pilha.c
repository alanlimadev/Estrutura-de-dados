#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 5

struct lista{
	int info;
	Lista *prox; 
};
struct pilha{
	Lista *prim;
}; 

Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1); 
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
}

//TRABALHO: função que receba uma pilha como argumento e retorne o valor armazenado em seu topo.
//int topo(Pilha* p){
//	if(pilha_vazia(p)){
//		printf("Pilha Vazia!!!\n");
//		exit(1);
//	}
//	return p->v[p->n-1];	
//}

//TRABALHO: função que retorne o número de elementos da pilha que possuem o campo info com valor ímpar
//int impares(Pilha* p){
//	int i, cont = 0;
//	for(i = p->n-1; i >= 0; i--){
//		if((p->v[i] % 2) != 0)
//			cont++;		
//	}
//	return cont;
//}

//TRABALHO: função que verifique quais são os elementos pares de uma pilha p1 e que os empilhe em ordem crescente em uma pilha p2
//Pilha* empilha_pares(Pilha* p1, Pilha* p2){
//	int i;
//	Lista* lAux = lst_cria();
//	Pilha* p01 = p1;
//	
//	for(i = p01->n-1; i >= 0; i--){
//		if((p01->v[i] % 2) == 0)
//			lAux = lst_insere_ordenado(lAux, p01->v[i]);
//	}	
//	while(lAux != NULL){
//		pilha_push(p2, lAux->info);
//		lAux = lAux->prox;
//	}
//	return p2;
//}

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

//Ordenação por Construção em Lista Encadeada
Lista* lst_insere_ordenado(Lista* l, int info){
	Lista* lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
			lNew->prox = NULL;
			return lNew;
	}else if(l->info>=info){
			lNew->prox = l;
			return lNew;
	}else{
		Lista* lAnt = l;
		Lista* lProx = l->prox; 
		while(lProx!=NULL&&lProx->info<info){
			lAnt = lProx;
			lProx = lProx->prox;
		}
		lAnt->prox = lNew;
		lNew->prox = lProx;
		return l;
	}
}

Lista* lst_remove(Lista* l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		if(l->info==info){
			free(l);
			return lAux;
		}
		else{
			Lista* lAnt = l;
			while(lAux!=NULL ){
				if(lAux->info == info){
					lAnt->prox = lAux->prox;
					free(lAux);
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->prox;
				}
			}
		}
	}
	return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista* l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->prox;
		free(l);
		l = lProx;
	}
}

/* Imprime uma lista.*/
void lst_imprime(Lista* l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
}

pilha_push_menor(Pilha* p, int info){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->info = info;
	l->prox = NULL;
	if(p->prim == NULL){
		p->prim = l;
	}else if(info < p->prim){
		l->prox = p->prim;
		p->prim = l;
	}
}

int pilha_soma(Pilha* p){
	Lista* l = p->prim;
	int cont = 0;
	while(l != NULL){
		cont += l->info;
		l = l->prox;
	}
	return cont;
}
