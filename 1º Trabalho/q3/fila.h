typedef struct lista Lista;

typedef struct fila Fila;

struct lista{
	int info;
	Lista *prox;
};
struct fila{
	Lista *ini;
	Lista *fim;
};

//typedef struct fila Fila;

/*Função que cria uma Fila.*/
Fila* fila_cria(void);

/*Testa se uma Fila é vazia.*/
int fila_vazia(Fila *f);

/*Função que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info);

/*Função que remove um elemento de uma Fila.*/
int fila_remove(Fila *f);

/*Função que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f);

/*Libera o espaço alocado para uma Fila.*/
void fila_libera(Fila *f);

//TRABALHO: função para retornar o número de elementos da fila com valor maior que n.
int qtd_maior(Fila* f, int n);

//TRABALHO: função que crie uma fila com os elementos da fila f na ordem inversa.
Fila* inverte(Fila* f);

//TRABALHO: função para retornar o número de elementos da fila que possuem o campo info com valor par. 
int pares(Fila* f);
