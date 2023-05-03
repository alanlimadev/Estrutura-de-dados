#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

struct lista {
	int info;
	Lista* prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista* l){
	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista* l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista* l, int info){
	Lista* lAux = l;
	while(lAux!=NULL){
		if(lAux->info == info)
			return lAux;
		lAux = lAux->prox;
	}
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista* l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
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

//Implementação Recursiva: Função Imprime Lista
void lst_imprime_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		printf("info: %d\n",l->info);
		lst_imprime_rec(l->prox);
	}
}

//Implementação Recursiva: Função Imprime Lista Invertida
void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
	}
}

//Implementação Recursiva: Função Remove Elemento Lista
Lista* lst_remove_rec(Lista* l, int info){
	if(!lst_vazia(l))
		if(l->info==info){
			Lista* lAux = l;
			l = l->prox;
			free(lAux);
		}
		else{
			l->prox = lst_remove_rec(l->prox,info);
		}
	return l;
}

//Implementação Recursiva: Função Libera Lista
void lst_libera_rec(Lista *l){
	if(!lst_vazia(l)){
		lst_libera_rec(l->prox);
		free(l);
	}
}

//Implementação Recursiva: Função Igualdade Entre Listas
int lst_igual_rec(Lista *l1,Lista *l2){
	if(lst_vazia(l1) && lst_vazia(l2))
		return 1;
	else if (lst_vazia(l1) || lst_vazia(l2))
		return 0;
	else
		return (l1->info==l2->info &&lst_igual_rec(l1->prox,l2->prox));
}

//TRABALHO: função que calcule o número de nós de uma lista.
int comprimento(Lista* l){
	if(!lst_vazia(l)){
		int cont = 0;
		while(l != NULL){
			l = l->prox;
			cont++;
		}
		return cont;
	}
}

//TRABALHO: função para retornar o número de nós da lista que possuem o campo info com valor menor que n.
int menores(Lista* l, int n){
	if(!lst_vazia(l)){
		int cont = 0;
		while(l != NULL){
			
			if(l->info < 30)
				cont++;
			l = l->prox;	
		}
		return cont;
	}
}

//TRABALHO: função para somar os valores do campo info de todos os nós.
int soma(Lista* l){
	if(!lst_vazia(l)){
		int s = 0;
		while(l != NULL){
			s += l->info;
			l = l->prox;	
		}
		return s;
	}
}

//TRABALHO: função para retornar o número de nós da lista que possuem o campo info com número primo.
int primos(Lista* l){
	if(!lst_vazia(l)){
		int numP = 0, i, cont;
		while(l != NULL){
			cont = 0;
			for(i = l->info; i >= 1; i--){
				if(l->info % i == 0)
					cont++;
			}
			if(cont == 2)
				numP++;
			l = l->prox;	
		}
		return numP;
	}
}

//TRABALHO: função para criar uma lista que é a concatenação de uma lista l2 no final de uma lista l1.
Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* l01 = l1;
	Lista* l02 = l2;
	
	Lista* l03 = lst_cria();
	Lista* lRes = lst_cria();
	
	while(l01 != NULL){
		l03 = lst_insere(l03, l01->info);
		l01 = l01->prox;
	}
	
	while(l02 != NULL){
		l03 = lst_insere(l03, l02->info);
		l02 = l02->prox;
	}
	
	while(l03 != NULL){
		lRes = lst_insere(lRes, l03->info);
		l03 = l03->prox;
	}
	return lRes;	
}

//TRABALHO: função que faça a diferença de duas listas L1 e L2 (ou seja, que retire de L1 os elementos que estão em L2).
Lista* lst_diferenca(Lista* l1, Lista* l2){
	int l02, l01;
	Lista* l1Aux = lst_cria();
	for(l02 = l2->info; l2 != NULL; l2 = l2->prox){
		l1Aux = l1;
		for(l01 = l1Aux->info; l1Aux != NULL; l1Aux = l1Aux->prox){
			if(l1Aux->info == l2->info)
				l1 = lst_remove(l1, l1Aux->info);
		}
	}
	return l1;
}
