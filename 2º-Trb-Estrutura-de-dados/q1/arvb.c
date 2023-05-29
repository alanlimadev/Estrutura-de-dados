#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

typedef struct arvb{
	char info;
	Arv *esq;
	Arv *dir;
}ArvB;

struct arv{
	char info;
	Arv *esq;
	Arv *dir;
};

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a==NULL;
}

//int arv_pertence(Arv *a,char c){
//	if(arv_vazia(a))
//		return 0;
//	else
//		return a->info ==c || arv_pertence(a->esq,c) || arv_pertence(a->dir,c);
//}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL; 
		a->dir = NULL;
	}else if(a->info > c)
		a->esq = arvb_insere(a->esq,c); 
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c); 
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a; 
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c); 
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c); 
		else{
			ArvB* t; 
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL)
					t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	} 
	return a; 
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

//TRABALHO: função que retorne a quantidade de folhas que possuem no campo info um número primo.
int folhas_primos(ArvB* a){
	
}

//TRABALHO: função que retorne a quantidade de nós que possuem os dois filhos (campos dir e esq diferentes de NULL).
int dois_filhos(ArvB* a){
	
}

//TRABALHO: função que retorne a quantidade de nós cujas subárvores esquerda e direita não são vazias e têm igual altura.
int nos_igual_altura(ArvB* a){
	
}

//TRABALHO: função que compare se duas árvores binárias de busca são iguais.
int iguais(ArvB* a, ArvB* b){
	
}
