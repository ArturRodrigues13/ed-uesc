/********************************************************************
 * Este arquivo contém código para manipular uma lista encadeada de itens.
 * Um item é uma estrutura definida pelo usuário da biblioteca ListaE.h.
 * Uma lista encadeada é um ponteiro para um nó. Um nó possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o próximo nó;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigatóriamente um campo nomeado de id do tipo unsigned int.
 *
 */
#include "ListaE.h"
//-----------------------------------------------------------------------------
struct Celula {
       tpItem item;
       struct Celula *prox;
};

typedef  struct Celula tpNo;
//-----------------------------------------------------------------------------
/**
 * @param .
 * @return a lista inicializada com o ponteiro apontando para NULL;
 */
tpNo* initLstE(){
    tpNo *lst = NULL;
    return lst;
}

/**
 * @param lst uma Lista de itens;
 * @param item um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contrário.
 */
tpNo* insertLstE(tpNo *lst, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item = item;
		no->prox = lst;
   		lst=no;
   		return lst;
	}
    return NULL;
}
//-----------------------------------------------------------------------------
/**
 * @param lst uma Lista não vazia de itens;
 * @return retorna o item da primeira posição de lst.
 */
tpItem  getE(tpNo *lst){
       return lst->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst uma Lista de itens;
 * @return
 */
void printLstE(tpNo *lst){
    //tpNo *aux = lst;

    while (lst != NULL) {
            printItem(lst->item);
            printf("\n----------------------------------");
            lst = lst->prox;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst uma Lista de itens;
 * @return true se lst vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst){
    if (lst == NULL) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Procurar na Lista por algum item que tenha o indentificador fornecido.
 * @param lst uma Lista de itens;
 * @param id é o identificador que será buscado em lst.
 * @return o item na lista com o id ou NULL se não for encontrado.
 */
tpItem* searchItemLstE(tpNo *lst, unsigned int id){
    if  (lst != NULL){
        if (lst->item.id == id){
            return &(lst->item);
        } else {
            return searchItemLstE(lst->prox, id);
        }
    }
    return NULL;
}

//-----------------------------------------------------------------------------

tpNo* removeItemLstEAux(tpNo **noAtual, unsigned int id){
    return removeItemLstE(NULL, noAtual, id);
}

tpNo* removeItemLstE(tpNo **noAnterior, tpNo **noAtual, unsigned int id){
    printf("a");
    if(*noAtual == NULL){
        printf("b");
        return NULL;
    }

    if((*noAtual)->item.id == id){
        printf("c");
        if(noAnterior == NULL){
            printf("d");
            *noAtual = (*noAtual)->prox;
            return *noAtual;
        }
        else{
            printf("e");
            return (*noAnterior)->prox = (*noAtual)->prox;
        }
    }
    else{
        printf("f");
        return removeItemLstE(noAtual, &((*noAtual)->prox), id);
	}
}
