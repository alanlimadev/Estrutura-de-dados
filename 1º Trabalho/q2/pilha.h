typedef struct pilha Pilha;

/*Fun��o que cria uma pilha.*/
Pilha* pilha_cria(void);

/*Testa se uma pilha � vazia.*/
int pilha_vazia(Pilha* p);

/*Fun��o que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha* p, int info);

/*Fun��o que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p);

/*Fun��o que imprime os elementos de uma pilha;*/
void pilha_imprime(Pilha* p);

/*Libera o espa�o alocado para uma pilha.*/
void pilha_libera(Pilha* p);

//TRABALHO
//fun��o que receba uma pilha como argumento e retorne o valor armazenado em seu topo.
int topo(Pilha* p);

//fun��o que retorne o n�mero de elementos da pilha que possuem o campo info com valor �mpar
int impares(Pilha* p);

//fun��o que verifique quais s�o os elementos pares de uma pilha p1 e que os empilhe em ordem crescente em uma pilha p2
Pilha* empilha_pares(Pilha* p1, Pilha* p2);
