#include <stdio.h>
#include <stdlib.h>

struct Conteudo {
	char letra;
};

typedef struct Conteudo tpItem;

struct rNo {
	tpItem item;
	struct rNo *esquerda, *direita;
};

typedef struct rNo tpArvore;

tpArvore* initArvore();

int alturaArvore(tpArvore* arvore);

tpArvore* RSD(tpArvore* arv);

tpArvore* RSE(tpArvore* arv);

int verificaFB(tpArvore* arvore);

tpArvore* insertArvore(tpArvore* arvore, tpItem item);

tpItem buscaArvore(tpArvore* arvore,char caractere);

void printArvoreEmPosOrdem(tpArvore* arvore);

void printArvoreBonita(tpArvore* arvore, int nivel);

tpArvore* procuraMenor(tpArvore* arvore);

int removeArvore(tpArvore** raiz, char valor);

//-----------------------------------------------------------//

void InserirElementoArvore(tpArvore** arvore);

void RemoverElementoArvore(tpArvore** arvore);

void BuscarElementoArvore(tpArvore* arvore);

void PrintarArvoreOrdem(tpArvore* arvore);

void PrintarArvoreBonita(tpArvore* arvore);
