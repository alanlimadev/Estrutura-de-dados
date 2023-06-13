#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvb.h"

struct arvb{
	char info;
	ArvB *esq;
	ArvB *dir;
};

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
ArvB* arvb_cria_vazia(void){
	return NULL;
}

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB *a){
	return a==NULL;
}

ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
		return a;
}

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

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

int arv_altura(ArvB *a){
	if(arvb_vazia(a))
	 	return -1;
	else{
		int hSAE = arv_altura(a->esq);
		int hSAD = arv_altura(a->dir);
		if(hSAE > hSAD) 
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}

bool ehPrimo(int numero) {
    if (numero <= 1)
        return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0)
            return false;
    }
    return true;
}

//TRABALHO: fun��o que retorne a quantidade de folhas que possuem no campo info um n�mero primo.
int folhas_primos(ArvB* a) {
    if(arvb_vazia(a))
    	return 0;
    if(a->esq == NULL && a->dir == NULL){
    	if(ehPrimo(a->info))
    		return 1;
    	else
    		return 0;
	}
	int folhasEsq = folhas_primos(a->esq);
	int folhasDir = folhas_primos(a->dir);
    
    return folhasEsq + folhasDir;
}

//TRABALHO: fun��o que retorne a quantidade de n�s que possuem os dois filhos (campos dir e esq diferentes de NULL).
int dois_filhos(ArvB* a){
	static int contNos = 0;
    if(!arvb_vazia(a)){
    	dois_filhos(a->esq);
    	if(a->dir!=NULL && a->esq!=NULL)
    		contNos++;
    	dois_filhos(a->dir);
	}
    return contNos;
}

//TRABALHO: fun��o que retorne a quantidade de n�s cujas sub�rvores esquerda e direita n�o s�o vazias e t�m igual altura.
int nos_igual_altura(ArvB* a){
	static int contNosAltura = 0;
    if(!arvb_vazia(a)){
    	if((a->dir!=NULL && a->esq!=NULL) && (arv_altura(a->esq) == arv_altura(a->dir)))	
    		contNosAltura++;
		nos_igual_altura(a->esq);
    	nos_igual_altura(a->dir);
	}
    return contNosAltura;
}

//TRABALHO: fun��o que compare se duas �rvores bin�rias de busca s�o iguais.
int iguais(ArvB* a, ArvB* b){
	if(!arvb_vazia(a) && !arvb_vazia(b)){
		iguais(a->esq, b->esq);
		if(a->info == b->info)
			return true;
		else 
			return false;
		iguais(a->dir, b->dir);
	}
}
