//Essas diretivas servem para evitar que um header file seja inclu�do mais de uma vez
//no mesmo projeto
#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED

#include "Item.h"
#include <stdlib.h>


/********************************************************************
 * Este arquivo cont�m c�digo para manipular uma lista encadeada de itens.
 * Um item � uma estrutura do tipo tpItem definida pelo usu�rio em um arquivo .h nomeado de Item.h.
 * Uma lista encadeada � um ponteiro para um n�. Um n� possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o pr�ximo n� do tipo tpNo;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigat�riamente um campo nomeado de id do tipo unsigned int.
 *
 */


//-----------------------------------------------------------------------------
struct No {
       tpItem    item;
       struct No  *ptrProx, *ptrAnt;
};

typedef  struct No tpNo;
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct ListaDE {
       tpNo *ptrPrim, *ptrUlt;
       int quantItens;
};

typedef  struct ListaDE tpLDE;
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
/**
 * Inicia uma LDE vazia.
 * @param .
 * @return a lista inicializada com os ponteiros apontando para NULL e quantItens=0;
 */
tpLDE initLstDE();


//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contr�rio.
 */
booleano insertLstDE(tpLDE *lstDE, tpItem item);
//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista de itens;
 * @return retorna o item da primeira posi��o de lst ou NULL caso contr�rio.
 */
tpItem getItem(tpLDE lstDE);
//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstDE(tpLDE lst);

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contr�rio.
 */
booleano isEmptyLstDE(tpLDE lst);
//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que ser� buscado em lst.
 * @return o item com o id ou NULL se n�o for encontrado.
 */
tpItem searchItemLstDE(tpLDE lst, unsigned int id);

int insertLstDE_SR(tpLDE *lstDE, tpItem item);

int deleteLstDE(tpLDE *lstDE, unsigned int id);

int quantidadeRepetidaLstDE(tpLDE lst, unsigned int id);

booleano estaOrdenada(tpLDE lst);

tpLDE copiaL1emL2(tpLDE lde1);

void copiaL1emL2_SR(tpLDE lde1, tpLDE *lde2);

tpLDE inverteL1emL2(tpLDE lde1);

#endif // LISTAE_H_INCLUDED
