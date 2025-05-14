/********************************************************************
 * Este arquivo cont�m c�digo para manipular uma lista encadeada de itens.
 * Um item � uma estrutura definida pelo usu�rio da biblioteca ListaE.h.
 * Uma lista encadeada � um ponteiro para um n�. Um n� possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o pr�ximo n�;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigat�riamente um campo nomeado de id do tipo unsigned int.
 *
 */
#include "ListaDE.h"

/**
 * Inicia uma LDE vazia.
 * @param .
 * @return a lista inicializada com os ponteiros apontando para NULL e quantItens=0;
 */
tpLDE initLstDE(){
    tpLDE lde;
    lde.ptrPrim = NULL;
    lde.ptrUlt  = NULL;
    lde.quantItens = 0;
    return lde;
}

//-----------------------------------------------------------------------------
/**
 * Insere um item no fim da lista.
 * @param lstDE = uma Lista de itens;
 * @param item= um item a ser inserido em lstDE
 * @return 1 se o item foi inserido em lst ou 0 caso contr�rio.
 */
int insertLstDE(tpLDE *lstDE, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item      = item;
		no->ptrProx   = NULL;
		no->ptrAnt    = (*lstDE).ptrUlt;

   		(*lstDE).quantItens = (*lstDE).quantItens + 1;
   		if ((*lstDE).ptrPrim == NULL) { //Se a lista estava vazia
            (*lstDE).ptrPrim = no;
			(*lstDE).ptrUlt = no;
		} else {
			lstDE->ptrUlt->ptrProx = no;
			(*lstDE).ptrUlt = no;
		}
   		return 1;   //1 = elemento inserido
	}
    return 0; //0 = elemento n�o inserido
}
//-----------------------------------------------------------------------------
/**
 * Retorna o primeiro item da lista.
 * @param lst = uma Lista n�o vazia de itens;
 * @return retorna o item da primeira posi��o de lst.
 */
tpItem getItem(tpLDE lstDE){
       return lstDE.ptrPrim->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstDE(tpLDE lst){
    tpNo *aux = lst.ptrPrim;

    while (aux != NULL) {
            printItem(aux->item);
            printf("\n----------------------------------");
            aux = aux->ptrProx;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contr�rio.
 */
booleano isEmptyLstDE(tpLDE lst){
    if (lst.quantItens==0) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Busca um item na lista.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que ser� buscado em lst.
 * @return o item na lista com o id ou NULL se n�o for encontrado.
 */
tpItem searchItemLstDE(tpLDE lst, unsigned int id) {
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( (*aux).item.id == id){
            return (*aux).item;
        } else {
            aux = aux->ptrProx;
        }
    }

	tpItem vazio;
	vazio.id = 0;
    return vazio;
}


int insertLstDE_SR(tpLDE *lstDE, tpItem item) {

	tpItem aux = searchItemLstDE(*lstDE,item.id);

	if (aux.id == 0) {
		int aux1 = insertLstDE(lstDE,item);
		if(aux1 == 1) {
			return 1;
		} else {
			printf("Erro ao inserir aluno na lista");
			return 0;
		}

	} else {
		printf("ID já utilizado na Lista");
		return 0;
	}
}

int deleteLstDE(tpLDE *lstDE, unsigned int id) {

	tpNo *aux = lstDE -> ptrPrim;

    while (aux != NULL){
        if ( (*aux).item.id == id){
			if((*aux).item.id == lstDE->ptrPrim->item.id && lstDE->quantItens == 1) {

				lstDE->ptrPrim = NULL;
				lstDE->ptrUlt = NULL;
				lstDE->quantItens = lstDE->quantItens -1;
				free(aux);
				return 1;
			} else if ((*aux).item.id == lstDE->ptrPrim->item.id && lstDE->quantItens != 1) {

				lstDE->ptrPrim = aux->ptrProx;
				aux->ptrProx->ptrAnt = NULL;
				lstDE->quantItens = lstDE->quantItens -1;
				free(aux);
				return 1;
			} else if ((*aux).item.id == lstDE->ptrUlt->item.id && lstDE->quantItens != 1) {

				lstDE->ptrUlt = aux->ptrAnt;
				aux->ptrAnt->ptrProx = NULL;
				lstDE->quantItens = lstDE->quantItens -1;
				free(aux);
				return 1;
			} else {

				aux->ptrAnt->ptrProx = aux->ptrProx;
				aux->ptrProx ->ptrAnt = aux->ptrAnt;
				lstDE ->quantItens = lstDE->quantItens + 1;
				free(aux);
				return 1;
			}
        } else {
            aux = aux->ptrProx;
        }
    }

    return 0;
}

int quantidadeRepetidaLstDE(tpLDE lst, unsigned int id) {

	int contador = 0;
	tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ((*aux).item.id == id){
			contador ++;
        }
		aux = aux -> ptrProx;
    }
	return contador;
}

booleano estaOrdenada(tpLDE lst) {

	tpNo *aux = lst.ptrPrim;
	if (aux == NULL){
        return true;
    }

	while (aux->ptrProx != NULL){
        if (aux->item.id > aux->ptrProx->item.id){
            return false;
        }
        aux = aux->ptrProx;
    }

	return true;
}

tpLDE copiaL1emL2(tpLDE lde1) {

	tpLDE lde2 = initLstDE();
	tpNo *aux = lde1.ptrPrim;

	while (aux != NULL){
		int verificacao = insertLstDE_SR(&lde2,aux->item);
        if (verificacao == 0){
            printf("Erro ao copiar elemento");
			return lde2;
        }
        aux = aux->ptrProx;
    }

	return lde2;
}

void copiaL1emL2_SR(tpLDE lde1, tpLDE *lde2) {

	tpNo *aux = lde1.ptrPrim;

	while (aux != NULL){
		tpItem verificacao = searchItemLstDE((*lde2),aux->item.id);
        if (verificacao.id == 0){
            int veri = insertLstDE_SR(lde2,aux->item);
			if (veri == 0){
				printf("Erro ao copiar elemento");
				return;
			}
        }
        aux = aux->ptrProx;
    }

	return;
}

tpLDE inverteL1emL2(tpLDE lde1) {

	tpLDE lde2 = initLstDE();
	tpNo *aux = lde1.ptrUlt;

	while (aux != NULL){
		int verificacao = insertLstDE_SR(&lde2,aux->item);
        if (verificacao == 0){
            printf("Erro ao copiar elemento");
			return lde2;
        }
        aux = aux->ptrAnt;
    }

	return lde2;
}
