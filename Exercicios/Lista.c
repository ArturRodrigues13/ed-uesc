#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 3

/* TAD lista usando vetor.
   elementos = vetor de inteiros [0..CAPACIDADE-1];
   tamanho= armazena a quantidade de elementos existentes na lista.

   Funções:
   void inicializarLista(Lista *lista);
   int estaCheia(Lista *lista);
   int adicionaElemento(Lista *lista, int elemento);
   int removeElemento(Lista *lista, int indice);
   void imprimiLista(Lista *lista);

*/
typedef struct {
    int elementos[CAPACIDADE];
    int tamanho;
} Lista;

/* Função para inicializar a lista como uma lista vazia;
   Entrada: uma estrutura do tipo Lista;
   Saída: uma Lista vazia;
*/
void inicializaLista(Lista *lista) {
    lista->tamanho = 0;
}

/* Função para verificar se a lista está cheia.
   Entrada: uma Lista;
   Saída: verdadeiro se a lista estiver cheia e falso caso contrário.
*/

int estaCheia(Lista *lista) {
    return lista->tamanho == CAPACIDADE;
}

/* Função para adicionar um elemento à lista.
   Entrada: uma Lista e um elemento inteiro;
   Saída: 1 se o elemento foi inserido na Lista e 0 caso contrário (lista sem espaço).
*/
int adicionaElemento(Lista *lista, int elemento) {
    if (estaCheia(lista)) {
        return 0; // Falha ao adicionar elemento
    }
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return 1; // Sucesso
}

/* Função para remover um elemento da lista (por índice)
   Entrada: uma Lista e o índice do elemento que se deseja remover.
   Saída: 1 se o elemento foi removido com sucesso ou 0 caso contrário.
*/
int removeElemento(Lista *lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        return 0; // Índice inválido
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1; // Sucesso
}

/* Função para imprimir os elementos da lista
   Entrada: uma Lista.
   Saída: os elementos da Lista exibidos na tela.
*/
void imprimiLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void printarErro(int indiceErro) {
	if(indiceErro == 0) {
		printf("Não há espaço para novo item.\nCAPACIDADE MÁXIMA = %d\n",CAPACIDADE);
	}

	if(indiceErro == 1) {
		printf("Índice fora de alcance.\n");
	}
}

int Pesquisa(Lista *lista, int elemento) {
	for (int i = 0; i < lista->tamanho;i++) {
		if (elemento == lista->elementos[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
    Lista minhaLista;
    inicializaLista(&minhaLista);

	adicionaElemento(&minhaLista, 10);
    adicionaElemento(&minhaLista, 20);
    if(adicionaElemento(&minhaLista, 30) == 0){
		printarErro(0);
	}

    printf("Lista inicial: ");
    imprimiLista(&minhaLista);

    if(removeElemento(&minhaLista, 3) == 0){
		printarErro(1);
	}

    printf("Lista após remoção: ");
	printf("O indíce do elemento pesquisado é: %d\n",Pesquisa(&minhaLista,30));
    imprimiLista(&minhaLista);

    return 0;
}
