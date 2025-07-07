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

tpArvore* insertArvoreSemSerBinariaBusca(tpArvore* arvore, tpItem item) {

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

		arvore->direita = insertArvoreSemSerBinariaBusca(arvore->direita,item);

		return arvore;
	}
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

int VerificaIgualdadeArvore(tpArvore* arvore1, tpArvore* arvore2) {

	if(arvore1 == NULL && arvore2 == NULL) {
		return 1;
	}

	if(arvore1 == NULL || arvore2 == NULL) {
		return 0;
	}

	if(arvore1->item.num != arvore2->item.num) {
		return 0;
	}

	return VerificaIgualdadeArvore(arvore1->esquerda,arvore2->esquerda) && VerificaIgualdadeArvore(arvore1->direita,arvore2->direita);
}

int VerificaSeABB(tpArvore* arvore, int minimo, int maximo) {

	if(arvore == NULL) {
		return 1;
	}

	if(!(maximo > arvore->item.num && arvore->item.num > minimo)) {
		return 0;
	}

	return VerificaSeABB(arvore->esquerda,minimo,arvore->item.num) && VerificaSeABB(arvore->direita,arvore->item.num,maximo);
}

int main() {

	tpArvore *arvore = initArvore();
	tpItem item;

	item.num = 10;
	arvore = insertArvore(arvore,item);
	printf("%d",arvore->item.num);
	item.num = 5;
	arvore = insertArvore(arvore,item);
	item.num = 6;
	arvore = insertArvore(arvore,item);
	item.num = 1;
	arvore = insertArvore(arvore,item);
	item.num = 20;
	arvore = insertArvore(arvore,item);
	item.num = 30;
	arvore = insertArvore(arvore,item);

	//item.num = 12;
	//arvore->esquerda->direita->direita = insertArvore(arvore->esquerda->direita->direita,item);

	tpArvore *arvore2 = initArvore();
	item.num = 10;
	arvore2 = insertArvoreSemSerBinariaBusca(arvore2,item);
	printf("%d",arvore->item.num);
	item.num = 11;
	arvore2 = insertArvoreSemSerBinariaBusca(arvore2,item);
	printf("%d",arvore->direita->item.num);
	item.num = 9;
	arvore2 = insertArvoreSemSerBinariaBusca(arvore2,item);

	int verifica = VerificaSeABB(arvore,0,100000);

	printf("\n\n\n\n%d",verifica);

	printf("\nAltura: %d",alturaArvore(arvore));
	tpItem teste = buscaArvore(arvore,2);
	printf("\n%d",teste.num);

	return 0;
}
