#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

Pilha* pilha_cria(void){
Pilha *p = (Pilha*)malloc(sizeof(Pilha));
if(p==NULL){
printf("Memoria insuficiente!!!\n");
exit(1);
}
p->prim = NULL;
return p;
}

/*Fun��o que adiciona um elemento no topo de uma pilha.*/
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

/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

/*Fun��o que remove um elemento do topo de uma pilha.*/
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

/*Fun��o que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%f\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espa�o alocado para uma pilha.*/
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
