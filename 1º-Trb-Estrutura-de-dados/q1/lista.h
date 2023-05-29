typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria();

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l);

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info);

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);

/* Imprime uma lista.*/
void lst_imprime(Lista *l);

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);

//Ordenação por Construção em Lista Encadeada
Lista* lst_insere_ordenado(Lista* l, int info);

//Implementação Recursiva: Função Imprime Lista
void lst_imprime_rec(Lista* l);

//Implementação Recursiva: Função Imprime Lista Invertida
void lst_imprime_invertida_rec(Lista* l);

//Implementação Recursiva: Função Remove Elemento Lista
Lista* lst_remove_rec(Lista* l, int info);

//Implementação Recursiva: Função Libera Lista
void lst_libera_rec(Lista *l);

//Implementação Recursiva: Função Igualdade Entre Listas
int lst_igual_rec(Lista *l1,Lista *l2);

//TRABALHO: função que calcule o número de nós de uma lista.
int comprimento(Lista* l);

//TRABALHO: função para retornar o número de nós da lista que possuem o campo info com valor menor que n.
int menores(Lista* l, int n);

//TRABALHO: função para somar os valores do campo info de todos os nós.
int soma(Lista* l);

//TRABALHO: função para retornar o número de nós da lista que possuem o campo info com número primo.
int primos(Lista* l);

//TRABALHO: função para criar uma lista que é a concatenação de uma lista l2 no final de uma lista l1.
Lista* lst_conc(Lista* l1, Lista* l2);

//TRABALHO: função que faça a diferença de duas listas L1 e L2 (ou seja, que retire de L1 os elementos que estão em L2).
Lista* lst_diferenca(Lista* l1, Lista* l2);

