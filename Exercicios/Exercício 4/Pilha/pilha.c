#include <stdio.h>
#include <stdlib.h>

struct Celula {
	int n;
    struct Celula *ant;
};

typedef struct Celula tpNo;

struct Pilha
{
	tpNo *topo;
	int quantidade_itens;
};

typedef struct Pilha tpPilha;

tpPilha initPilha(){
    tpPilha pilha;
	pilha.topo = NULL;
	pilha.quantidade_itens = 0;
    return pilha;
}

int pushPilha(tpPilha *pilha, int valor) {

	tpNo *no = (tpNo*)malloc(sizeof(tpNo));

	if (no !=NULL){

		no->n = valor;

		if(pilha->quantidade_itens == 0) {

			no->ant = NULL;
			(*pilha).topo = no;
		} else {

			no->ant = (*pilha).topo;
			(*pilha).topo = no;
		}

		(*pilha).quantidade_itens = (*pilha).quantidade_itens + 1;

		return 0; // Elemento colocado com sucesso
	}
	return 1; // Erro
}

int isEmptyPilha(tpPilha pilha) {

	if(pilha.quantidade_itens == 0)
		return 0;

	return 1;
}

int popPilha(tpPilha *pilha) {

	tpNo *aux = pilha->topo;

	if(aux != NULL) {

		if(pilha->quantidade_itens == 1) {

			pilha->topo = NULL;
			pilha->quantidade_itens = pilha->quantidade_itens -1;
			free(aux);
			return 0; // Correto
		} else {

			pilha->topo = aux->ant;
			pilha->quantidade_itens = pilha->quantidade_itens -1;
			free(aux);
			return 0; // Correto
		}
	} else {
		printf("Pilha Vazia");
		return 1; // Erro
	}
}

tpNo topPilha(tpPilha pilha) {

	tpNo aux = *(pilha.topo);
	return aux;
}

int lenghtPilha(tpPilha pilha) {

	return pilha.quantidade_itens;
}

void printPilha(tpPilha pilha) {

	tpNo *aux = pilha.topo;

	while (aux != NULL) {

		printf("\nValor: %d",(*aux).n);
		printf("\n--------------------------------");
		aux = aux->ant;
	}
}


int main() {

	tpPilha pilha = initPilha();

	if(isEmptyPilha(pilha) == 0) {
		printf("Pilha Vazia");
	}
	pushPilha(&pilha,10);
	pushPilha(&pilha,20);
	pushPilha(&pilha,30);

	if(isEmptyPilha(pilha) == 0) {
		printf("Pilha Vazia");
	}

	popPilha(&pilha);

	printf("%d",lenghtPilha(pilha));

	printPilha(pilha);
}
