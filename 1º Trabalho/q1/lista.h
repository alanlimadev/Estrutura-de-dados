typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria();

/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l);

/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);

/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);

//Ordena��o por Constru��o em Lista Encadeada
Lista* lst_insere_ordenado(Lista* l, int info);

//Implementa��o Recursiva: Fun��o Imprime Lista
void lst_imprime_rec(Lista* l);

//Implementa��o Recursiva: Fun��o Imprime Lista Invertida
void lst_imprime_invertida_rec(Lista* l);

//Implementa��o Recursiva: Fun��o Remove Elemento Lista
Lista* lst_remove_rec(Lista* l, int info);

//Implementa��o Recursiva: Fun��o Libera Lista
void lst_libera_rec(Lista *l);

//Implementa��o Recursiva: Fun��o Igualdade Entre Listas
int lst_igual_rec(Lista *l1,Lista *l2);

//TRABALHO: fun��o que calcule o n�mero de n�s de uma lista.
int comprimento(Lista* l);

//TRABALHO: fun��o para retornar o n�mero de n�s da lista que possuem o campo info com valor menor que n.
int menores(Lista* l, int n);

//TRABALHO: fun��o para somar os valores do campo info de todos os n�s.
int soma(Lista* l);

//TRABALHO: fun��o para retornar o n�mero de n�s da lista que possuem o campo info com n�mero primo.
int primos(Lista* l);

//TRABALHO: fun��o para criar uma lista que � a concatena��o de uma lista l2 no final de uma lista l1.
Lista* lst_conc(Lista* l1, Lista* l2);

//TRABALHO: fun��o que fa�a a diferen�a de duas listas L1 e L2 (ou seja, que retire de L1 os elementos que est�o em L2).
Lista* lst_diferenca(Lista* l1, Lista* l2);

