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

/**
 * Cria uma árvore AVL vazia.
 * @return Um ponteiro para uma árvore AVL vazia, apontando para NULL.
 */
tpArvore* initArvore();


/**
 * Calcula a altura de uma árvore AVL.
 * @param arvore Uma árvore AVL.
 * @return A altura da árvore AVL.
 */
int alturaArvore(tpArvore* arvore);

/**
 * Rotaciona uma árvore AVL para a direita.
 * @param arv Uma árvore AVL.
 * @return A nova raiz da árvore AVL após a rotação.
 */
tpArvore* RSD(tpArvore* arv);

/**
 * Rotaciona uma árvore AVL para a esquerda.
 * @param arv Uma árvore AVL.
 * @return A nova raiz da árvore AVL após a rotação.
 */
tpArvore* RSE(tpArvore* arv);

/**
 * Calcular o fator de balanceamento de um nó de uma árvore AVL.
 * @param arvore Nó de uma árvore AVL.
 * @return O fator de balanceamento do nó.
 */
int verificaFB(tpArvore* arvore);

/**
 * Insere um item em uma árvore AVL.
 * @param arvore Uma árvore AVL;
 * @param item O item que será inserido.
 * @return A nova raiz da árvore AVL, após a inserção.
 */
tpArvore* insertArvore(tpArvore* arvore, tpItem item);

/**
 * Procura um valor em uma árvore AVL.
 * @param arvore Uma árvore AVL;
 * @param valor O valor que será procurado.
 * @return O item caso o mesmo seja encontrado na árvore, ou -1 caso contrário.
 */
int searchArvoreR(tpArvore *arvore, int valor);

/**
 * Exibe no monitor os valores de uma árvore AVL em ordem crescente.
 * @param arvore Uma árvore AVL.
 * @return
 */
void printArvoreEmOrdem(tpArvore* arvore);

/**
 * Encontra o menor valor em uma árvore AVL.
 * @param arvore Uma árvore AVL.
 * @return O ponteiro para o nó com o menor valor da árvore.
 */
tpArvore* procuraMenor(tpArvore* arvore);

/**
 * Remove um valor de uma árvore AVL.
 * @param raiz Uma árvore AVL;
 * @param valor O valor que será removido.
 * @return 1 caso o valor for removido com sucesso, ou 0 caso contrário.
 */
int removeArvore(tpArvore** raiz, int valor);

//-----------------------------------------------------------//

char menu();

void interfaceAVL(tpArvore** arvore);

void InserirElementoArvore(tpArvore** arvore);

void RemoverElementoArvore(tpArvore** arvore);

void BuscarElementoArvore(tpArvore* arvore);

void PrintarArvoreOrdem(tpArvore* arvore);

void PrintarArvoreBonita(tpArvore* arvore);
