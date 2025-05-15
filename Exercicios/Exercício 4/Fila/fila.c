#include <stdio.h>
#include <stdlib.h>

struct Celula {
	int n;
    struct Celula *ant, *prox;
};

typedef struct Celula tpNo;

struct Fila
{
	tpNo *prim, *ult;
	int quantidade_itens;
};

typedef struct Fila tpFila;

tpFila initFila(){
    tpFila fila;
	fila.prim = NULL;
	fila.ult = NULL;
	fila.quantidade_itens = 0;
	return fila;
}

int enqueueFila(tpFila *fila, int valor) {

	tpNo *no = (tpNo*)malloc(sizeof(tpNo));

	if (no !=NULL){

		no->n = valor;

		if(fila->quantidade_itens == 0) {

			fila->prim = no;
			fila->ult = no;
			no->ant = NULL;
			no->prox = NULL;
		} else {

			fila->ult->ant = no;
			no->prox = fila->ult;
			fila->ult = no;
			no->ant = NULL;
		}

		(*fila).quantidade_itens = (*fila).quantidade_itens + 1;

		return 0; // Elemento colocado com sucesso
	}
	return 1; // Erro
}

int isEmptyFila(tpFila fila) {

	if(fila.quantidade_itens == 0)
		return 0;

	return 1;
}

int dequeueFila(tpFila *fila) {

	tpNo *aux = fila->prim;

	if(aux != NULL) {

		if(fila->quantidade_itens == 1) {

			fila->prim = NULL;
			fila->ult = NULL;
			fila->quantidade_itens = fila->quantidade_itens -1;
			free(aux);
			return 0; // Correto
		} else {

			fila->prim = aux->ant;
			fila->prim->prox = NULL;
			fila->quantidade_itens = fila->quantidade_itens -1;
			free(aux);
			return 0; // Correto
		}
	} else {
		printf("Fila Vazia");
		return 1; // Erro
	}
}

tpNo firstFila(tpFila fila) {

	tpNo aux = *(fila.prim);
	return aux;
}

int lenghtFila(tpFila fila) {

	return fila.quantidade_itens;
}

void printFila(tpFila fila) {

	tpNo *aux = fila.prim;

	while (aux != NULL) {

		printf("\nValor: %d",(*aux).n);
		printf("\n--------------------------------");
		aux = aux->ant;
	}
}


int main() {

	tpFila fila = initFila();

	if(isEmptyFila(fila) == 0) {
		printf("Fila Vazia");
	}

	enqueueFila(&fila, 10);
	enqueueFila(&fila, 20);
	enqueueFila(&fila, 30);

	if(isEmptyFila(fila) == 0) {
		printf("Fila Vazia");
	}

	dequeueFila(&fila);

	printFila(fila);
}
