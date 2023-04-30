#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include"lista.h"

int main (void){
	setlocale(LC_ALL, "Portuguese");
	
	Lista* l = lst_cria();
	l = lst_insere(l,10);
	l = lst_insere(l,20);
	l = lst_insere(l,25);
	l = lst_insere(l,30);
	l = lst_remove(l,10);
	lst_imprime(l);
	
	Lista* l1 = lst_cria();
	l1 = lst_insere(l1,6);
	l1 = lst_insere(l1,13);
	l1 = lst_insere(l1,45);
	l1 = lst_insere(l1,28);
	l1 = lst_insere(l1,41);
	l1 = lst_remove(l1,25);
	l1 = lst_remove_rec(l1,41);
	lst_imprime(l1);
	lst_imprime_invertida_rec(l1);
	printf("Num. nós c/ info < que 30: %d\n",menores(l1,30));
	printf("O comprimento da lista eh %d\n",comprimento(l1));
	printf("Soma dos valores dos nós %d\n",soma(l1));
	printf("Num. nós com val. primos é %d\n",primos(l1));
	
	Lista* l2 = lst_cria();
	l2 = lst_insere(l,28);
	l2 = lst_insere(l,45);
	l2 = lst_insere(l,130);
	
	Lista* l3=lst_conc(l1,l2);
	lst_imprime(l3);
	
	l1=lst_diferenca(l1,l2);
	lst_imprime(l1);
	
	lst_libera(l1);
	lst_libera(l2);
	lst_libera(l3);
	
	system("PAUSE");
	return 0;
}


