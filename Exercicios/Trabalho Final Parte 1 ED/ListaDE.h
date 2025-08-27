#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

struct No {
       tpItens    item;
       struct No  *ptrProx, *ptrAnt;
};

typedef  struct No tpNo;

struct ListaDE {
       tpNo *ptrPrim, *ptrUlt;
       int quantItens;
};

typedef  struct ListaDE tpLDE;

/**
 * Cria uma lista duplamente encadeada vazia.
 * @return A lista duplamente encadeada inicializada com os ponteiros apontando para NULL.
 */
tpLDE initLstDE();


/**
 * Insere um item no fim de uma lista duplamente encadeada.
 * @param lstDE Uma lista duplamente encadeada;
 * @param item O item que será inserido na lista.
 * @return 1 caso o item for inserido com sucesso, ou 0 caso contrário.
 */
booleano insertLstDE(tpLDE *lstDE, tpItens item);


/**
 * Retorna o primeiro item de uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada.
 * @return O primeiro item da lista.
 */
tpItens getItem(tpLDE lstDE);


/**
 * Exibe no monitor os itens de uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada.
 * @return
 */
void printLstDE(tpLDE lst);


/**
 * Verifica se uma lista duplamente encadeada está vazia.
 * @param lst Uma lista duplamente encadeada.
 * @return Verdadeiro caso a lista duplamente encadeada estiver vazia, ou Falso caso contrário.
 */
booleano isEmptyLstDE(tpLDE lst);


/**
 * Procura um item em uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada;
 * @param id O identificador que será buscado na lista.
 * @return O item da lista com o identificador procurado, caso o mesmo seja encontrado na lista, ou um item com identificador 0 caso contrário.
 */
tpItens searchItemLstDE(tpLDE lst, unsigned int id);


/**
 * Insere um item no fim de uma lista duplamente encadeada, sem repetições.
 * @param lstDE Uma lista duplamente encadeada;
 * @param item O item que será inserido na lista.
 * @return 1 caso o item for inserido com sucesso, ou 0 caso contrário.
 */
int insertLstDE_SR(tpLDE *lstDE, tpItens item);


/**
 * Remove um item de uma lista duplamente encadeada.
 * @param lstDE Uma lista duplamente encadeada;
 * @param id O identificador que será deletado da lista.
 * @return 1 caso o item for removido com sucesso, ou 0 caso contrário.
 */
int deleteLstDE (tpLDE *lstDE, unsigned int id);


/**
 * Retorna quantos identificadores específicos existem em uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada;
 * @param id O identificador que será contabilizado na lista.
 * @return A quantidade de identificadores iguais ao desejado que existem na lista.
 */
int quantosIds (tpLDE lst, unsigned int id);


/**
 * Verifica se uma lista duplamente encadeada está ordenada crescentemente ou não.
 * @param lst Uma lista duplamente encadeada.
 * @return Verdadeiro caso a lista esteja ordenada crescentemente, e Falso caso contrário.
 */
booleano ordenadaOuNao (tpLDE lst);

void interfacelstDEncadeada(tpLDE* lstAlunos);
char menulstDEncadeada();
void inserirAluno(tpLDE *lde);
void deletarAluno(tpLDE *lde);
void pesquisarAluno(tpLDE lde);
void quantosId (tpLDE lde);
void ordenadoOuNao (tpLDE lde);
