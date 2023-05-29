#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

int main (void){
	setlocale(LC_ALL, "Portuguese");
	
	int a;
	Pilha* p1 = pilha_cria();
	pilha_push(p1,10);
	pilha_push(p1,20);
	pilha_push(p1,25);
	pilha_push(p1,30);
	
	pilha_push_menor(p1, 9);
	
	printf("\nSOMA = %d\n", pilha_soma(p1)); 
	
//	a = pilha_pop(p1);
	pilha_imprime(p1);
//	printf("Elemento no topo da pilha p1: %d\n",topo(p1));
//	printf("Qde elems impares na pilha p1: %d\n",impares(p1));
//	
//	Pilha* p2 = pilha_cria();
//	pilha_push(p2,3);
//	pilha_push(p2,4);
//	
//	p2 = empilha_pares(p1,p2);
//	pilha_imprime(p2);

	pilha_libera(p1);
//	pilha_libera(p2);
	
	system("PAUSE");
	return 0;
}

	

