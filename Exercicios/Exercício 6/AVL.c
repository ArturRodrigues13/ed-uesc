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

tpArvore* RSD(tpArvore* arv) {

	tpArvore* filho = arv->esquerda;
	arv->esquerda = filho->direita;
	filho->direita = arv;
	return filho;
}

tpArvore* RSE(tpArvore* arv) {

	tpArvore* filho = arv->direita;
	arv->direita = filho->esquerda;
	filho->esquerda = arv;
	return filho;
}

int verificaFB(tpArvore* arvore) {

	if(arvore == NULL) {

		return 0;
	} else {

		return alturaArvore(arvore->direita) - alturaArvore(arvore->esquerda);
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

		int FB = verificaFB(arvore);

		if(FB < -1 && verificaFB(arvore->esquerda) < 0) {
			return RSD(arvore);
		}
		if(FB < -1 && verificaFB(arvore->esquerda) > 0) {

			arvore->esquerda = RSE(arvore->esquerda);
			return RSD(arvore);
		}
		if(FB > 1 && verificaFB(arvore->direita) > 0) {
			return RSE(arvore);
		}
		if(FB > 1 && verificaFB(arvore->direita) < 0) {

			arvore->direita = RSD(arvore->direita);
			return RSE(arvore);
		}

		return arvore;
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

void printArvoreEmOrdem(tpArvore* arvore) {

	if(arvore == NULL) return;

	printArvoreEmOrdem(arvore->esquerda);
	printf("\n%d",arvore->item.num);
	printArvoreEmOrdem(arvore->direita);
}

tpArvore* procuraMenor(tpArvore* arvore) {

	tpArvore *aux1 = arvore;
	tpArvore *aux2 = arvore->esquerda;

	while (aux2 != NULL) {

		aux1 = aux2;
		aux2 = aux2->esquerda;
	}

	return aux1;
}

int removeArvore(tpArvore** raiz, int valor) {

	if (*raiz == NULL) {
		printf("Árvore vazia ou não inicializada\n");
		return 0;
	}

	int res;

	if (valor < (*raiz)->item.num) {
		res = removeArvore(&((*raiz)->esquerda), valor);
		if (res == 1 && verificaFB(*raiz) >= 2) {
			if (alturaArvore((*raiz)->direita->esquerda) <= alturaArvore((*raiz)->direita->direita)) {
				*raiz = RSE(*raiz);
			} else {
				(*raiz)->direita = RSD((*raiz)->direita);
				*raiz = RSE(*raiz);
			}
		}
	} else if (valor > (*raiz)->item.num) {
		res = removeArvore(&((*raiz)->direita), valor);
		if (res == 1 && verificaFB(*raiz) <= -2) {
			if (alturaArvore((*raiz)->esquerda->direita) <= alturaArvore((*raiz)->esquerda->esquerda)) {
				*raiz = RSD(*raiz);
			} else {
				(*raiz)->esquerda = RSE((*raiz)->esquerda);
				*raiz = RSD(*raiz);
			}
		}
	} else {
		tpArvore* temp = *raiz;

		if ((*raiz)->esquerda == NULL) {
			*raiz = (*raiz)->direita;
			free(temp);
		} else if ((*raiz)->direita == NULL) {
			*raiz = (*raiz)->esquerda;
			free(temp);
		} else {
			tpArvore* menor = procuraMenor((*raiz)->direita);
			(*raiz)->item = menor->item;
			removeArvore(&((*raiz)->direita), menor->item.num);

			if (verificaFB(*raiz) <= -2) {
				if (alturaArvore((*raiz)->esquerda->direita) <= alturaArvore((*raiz)->esquerda->esquerda)) {
					*raiz = RSD(*raiz);
				} else {
					(*raiz)->esquerda = RSE((*raiz)->esquerda);
					*raiz = RSD(*raiz);
				}
			}
		}
		return 1;
	}
	return res;
}


int main() {

	tpArvore *arvore = initArvore();
	tpItem item;

	item.num = 15;
	arvore = insertArvore(arvore,item);
	item.num = 1;
	arvore = insertArvore(arvore,item);
	item.num = 2;
	arvore = insertArvore(arvore,item);
	item.num = 16;
	arvore = insertArvore(arvore,item);
	item.num = 8;
	arvore = insertArvore(arvore,item);
	item.num = 20;
	arvore = insertArvore(arvore,item);
	item.num = 5;
	arvore = insertArvore(arvore,item);
	item.num = 17;
	arvore = insertArvore(arvore,item);

	printArvoreEmOrdem(arvore);

	int verifica = removeArvore(&arvore,15);

	printf("\nRemoveu: %d",verifica);

	printArvoreEmOrdem(arvore);

	return 0;
}
