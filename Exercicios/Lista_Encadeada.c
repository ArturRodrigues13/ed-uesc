#include <stdio.h>
#include <stdlib.h>

struct Conteudo
{
	int num;
};

typedef struct Conteudo tpitem;

struct rNo
{
	tpitem Item;
	struct rNo *ptrProx;
};

typedef struct rNo tpNo;

typedef struct
{

	int tamanho;
	tpNo *ptrInicio;
	tpNo *ptrFinal;

} Lista_Encadeada;

void inicializaLista(Lista_Encadeada *lista) {
    lista->tamanho = 0;
}

int adicionaElemento(Lista_Encadeada *lista, int elemento) {

    if (lista -> tamanho == 0) {
        tpNo *novoPonteiro;
		novoPonteiro = (tpNo*) malloc(sizeof(tpNo));
		novoPonteiro -> Item.num = elemento;
		novoPonteiro -> ptrProx = NULL;
		lista -> ptrInicio = novoPonteiro;
		lista -> ptrFinal = novoPonteiro;
		lista -> tamanho++;
		return 0;
    }

	tpNo *novoPonteiro;
	novoPonteiro = (tpNo*) malloc(sizeof(tpNo));
	novoPonteiro -> Item.num = elemento;
	novoPonteiro -> ptrProx = NULL;
	lista -> ptrFinal = novoPonteiro;
	lista -> tamanho++;
    return 1; // Sucesso

}

int main() {

	Lista_Encadeada teste;
	inicializaLista(&teste);

	adicionaElemento(&teste, 25);
	adicionaElemento(&teste, 35);
	adicionaElemento(&teste, 45);
	adicionaElemento(&teste, 55);
	adicionaElemento(&teste, 65);
	adicionaElemento(&teste, 75);

	printf("%d",teste.ptrInicio -> Item.num);
	printf("%d",teste.ptrFinal -> Item.num);

}
