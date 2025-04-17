//Essas diretivas servem para evitar que um header file seja incluído mais de uma vez
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
 * b) um ponteiro para o pr�ximo n�;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigat�riamente um campo nomeado de id do tipo unsigned int.
 *
 */


typedef  struct Celula tpNo;

//-----------------------------------------------------------------------------
/**
 * @param .
 * @return a lista inicializada com o ponteiro apontando para NULL;
 */
tpNo * initLstE();
/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contrário.
 */
tpNo*insertLstE(tpNo *lst, tpItem item);
//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista de itens;
 * @return retorna o item da primeira posição de lst ou NULL caso contrário.
 */
tpItem  getE(tpNo *lst);
//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstE(tpNo *lst);

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst);

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que será buscado em lst.
 * @return o item com o id ou NULL se não for encontrado.
 */
tpItem *searchItemLstE(tpNo *lst, unsigned int id);



#include "ListaE.c"
#endif // LISTAE_H_INCLUDED
