#include "AVLFunctionsChar.h"

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

	if(item.letra < 65 || item.letra > 90) return NULL;

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

		if(item.letra >= arvore->item.letra) {
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

tpItem buscaArvore(tpArvore* arvore,char caractere) {

	tpItem lixo;
	lixo.letra = 'a';

	if(arvore == NULL) {

		return lixo;
	} else {

		if (arvore->item.letra == caractere) {

			return arvore->item;
		} else {

			tpItem procura;

			if(caractere < arvore->item.letra) {

				procura = buscaArvore(arvore -> esquerda,caractere);
			} else {

				procura = buscaArvore(arvore -> direita,caractere);
			}

			if(procura.letra != 'a') {
				return procura;
			}
		}

	}

	return lixo;
}

void printArvoreEmPosOrdem(tpArvore* arvore) {

	if(arvore == NULL) return;

	printArvoreEmPosOrdem(arvore->esquerda);
	printArvoreEmPosOrdem(arvore->direita);
	printf("\n%c",arvore->item.letra);
}

void printArvoreBonita(tpArvore* arvore, int nivel) {
    if (arvore == NULL) return;


    printArvoreBonita(arvore->direita, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%c\n", arvore->item.letra);

    printArvoreBonita(arvore->esquerda, nivel + 1);
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

int removeArvore(tpArvore** raiz, char valor) {

	if (*raiz == NULL) {
		return 0;
	}

	int res;

	if (valor < (*raiz)->item.letra) {
		res = removeArvore(&((*raiz)->esquerda), valor);
		if (res == 1 && verificaFB(*raiz) >= 2) {
			if (alturaArvore((*raiz)->direita->esquerda) <= alturaArvore((*raiz)->direita->direita)) {
				*raiz = RSE(*raiz);
			} else {
				(*raiz)->direita = RSD((*raiz)->direita);
				*raiz = RSE(*raiz);
			}
		}
	} else if (valor > (*raiz)->item.letra) {
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
			removeArvore(&((*raiz)->direita), menor->item.letra);

			if (verificaFB(*raiz) <= -2) {
				if (alturaArvore((*raiz)->esquerda->direita) <= alturaArvore((*raiz)->esquerda->esquerda)) {
					*raiz = RSD(*raiz);
				} else {
					(*raiz)->esquerda = RSE((*raiz)->esquerda);
					*raiz = RSD(*raiz);
				}
			}

			if (verificaFB(*raiz) >= 2) {
				if (alturaArvore((*raiz)->direita->esquerda) <= alturaArvore((*raiz)->direita->direita)) {
					*raiz = RSE(*raiz);
				} else {
					(*raiz)->direita = RSD((*raiz)->direita);
					*raiz = RSE(*raiz);
				}
			}
		}
		return 1;
	}
	return res;
}
