#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

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

/*Fun��o que imprime os elementos de uma fila.*/
void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espa�o alocado para uma fila.*/
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

//TRABALHO: fun��o para retornar o n�mero de elementos da fila com valor maior que n.
int qtd_maior(Fila* f, int n){
	
}

//TRABALHO: fun��o que crie uma fila com os elementos da fila f na ordem inversa.
Fila* inverte(Fila* f){
	
}

//TRABALHO: fun��o para retornar o n�mero de elementos da fila que possuem o campo info com valor par. 
int pares(Fila* f){
	
}
