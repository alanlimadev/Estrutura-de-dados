#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

struct lista{
	int info;
	Lista *prox; 
};

struct fila{
	Lista *ini;
	Lista *fim;
}; 


struct pilha{
	Lista *prim;
}; 

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
	f->fim = l;
}

int fila_remove(Fila *f){
	Lista *l; int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if(fila_vazia(f))
		f->fim = NULL;
	return a;
}

/*Função que imprime os elementos de uma fila.*/
void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}

//TRABALHO: função para retornar o número de elementos da fila com valor maior que n.
int qtd_maior(Fila* f, int n){
	Lista* lAux = f->ini;
	int cont = 0;
	while(lAux != NULL){
		if(lAux->info > n)
			cont++;
		lAux = lAux->prox;
	}
	return cont;
}

//TRABALHO: função que crie uma fila com os elementos da fila f na ordem inversa.
Fila* inverte(Fila* f){
	Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
	pi->prim = NULL;
	Fila* fi = f;
		
	while(!fila_vazia(fi)){
		pilha_push(pi, fila_remove(fi));		
	}
	while(!pilha_vazia(pi)){
		fila_insere(fi, pilha_pop(pi));
	}
	return fi;
}

//TRABALHO: função para retornar o número de elementos da fila que possuem o campo info com valor par. 
int pares(Fila* f){
	int aux, cont = 0;
	Lista* lAux = f->ini;
	while(lAux != NULL){
		if(lAux->info % 2 == 0)
			cont++;
		lAux = lAux->prox;
	}
	return cont;
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
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

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

