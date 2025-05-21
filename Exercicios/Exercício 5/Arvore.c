#include <stdio.h>
#include <stdlib.h>

struct Conteudo {
	int num;
};

typedef struct Conteudo tpItem;

struct rNo {
	tpItem item;
	struct rNo *esquerda, *direita;
};

typedef struct rNo tpArvore;

tpArvore* initArvore() {

	tpArvore *arvore = NULL;
	return arvore;
}

tpArvore* insertArvore(tpArvore* arvore, tpItem item) {

	if(arvore == NULL) {

		tpArvore *galho = (tpArvore*)malloc(sizeof(tpArvore));

		if(galho != NULL) {

			galho->item = item;
			galho->esquerda = NULL;
			galho->direita = NULL;
			return galho;
		}
		return NULL;
	} else {

		if(item.num > arvore->item.num) {
			arvore->direita = insertArvore(arvore->direita,item);
		} else {
			arvore->esquerda = insertArvore(arvore->esquerda,item);
		}
		return arvore;
	}
}


