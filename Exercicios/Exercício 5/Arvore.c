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

int alturaArvore(tpArvore* arvore) {

	if(arvore == NULL) {

		return -1;
	} else {

		if(arvore ->direita == NULL && arvore ->esquerda == NULL) {

			return 0;
		} else if (arvore ->direita == NULL && arvore ->esquerda != NULL) {

			return 1 + alturaArvore(arvore -> esquerda);
		} else if (arvore -> direita != NULL && arvore ->esquerda == NULL) {

			return 1 + alturaArvore(arvore -> direita);
		} else if (arvore -> direita != NULL && arvore ->esquerda != NULL) {

			int esquerda = 1 + alturaArvore(arvore -> esquerda);
			int direita = 1 + alturaArvore(arvore -> direita);

			if(esquerda > direita) {
				return esquerda;
			} else {
 				return direita;
			}
		}
		return -1;
	}
}

tpItem buscaArvore(tpArvore* arvore,int item) {

	tpItem lixo;
	lixo.num = -1;

	if(arvore == NULL) {

		return lixo;
	} else {

		if (arvore->item.num == item) {

			return arvore->item;
		} else {

			tpItem procura;

			if(item < arvore->item.num) {

				procura = buscaArvore(arvore -> esquerda,item);
			} else {

				procura = buscaArvore(arvore -> direita,item);
			}

			if(procura.num != -1) {
				return procura;
			}
		}

	}

	return lixo;
}


int main() {

	tpArvore *arvore = initArvore();
	tpItem item;

	item.num = 10;
	arvore = insertArvore(arvore,item);
	printf("%d",arvore->item.num);
	item.num = 12;
	arvore = insertArvore(arvore,item);
	printf("%d",arvore->direita->item.num);
	item.num = 14;
	arvore = insertArvore(arvore,item);

	item.num = 16;
	arvore = insertArvore(arvore,item);

	item.num = 4;
	arvore = insertArvore(arvore,item);

	item.num = 3;
	arvore = insertArvore(arvore,item);

	item.num = 2;
	arvore = insertArvore(arvore,item);

	item.num = 1;
	arvore = insertArvore(arvore,item);

	printf("\nAltura: %d",alturaArvore(arvore));
	tpItem teste = buscaArvore(arvore,2);
	printf("\n%d",teste.num);

	return 0;
}
