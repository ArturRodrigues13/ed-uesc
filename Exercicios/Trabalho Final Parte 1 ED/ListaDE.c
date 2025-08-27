#include "ListaDE.h"

/**
 * Cria uma lista duplamente encadeada vazia.
 * @return A lista duplamente encadeada inicializada com os ponteiros apontando para NULL.
 */
tpLDE initLstDE(){
    tpLDE lde;
    lde.ptrPrim = NULL;
    lde.ptrUlt  = NULL;
    lde.quantItens = 0;
    return lde;
}


/**
 * Insere um item no fim de uma lista duplamente encadeada.
 * @param lstDE Uma lista duplamente encadeada;
 * @param item O item que será inserido na lista.
 * @return 1 caso o item for inserido com sucesso, ou 0 caso contrário.
 */
int insertLstDE(tpLDE *lstDE, tpItens item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no != NULL){
		no->item      = item;
		no->ptrProx   = NULL;
		no->ptrAnt    = (*lstDE).ptrUlt;

   		(*lstDE).quantItens = (*lstDE).quantItens + 1;
   		if ((*lstDE).ptrPrim == NULL){
            (*lstDE).ptrPrim = no;
            (*lstDE).ptrUlt = no;
        }
        else{
            lstDE->ptrUlt->ptrProx = no;
            (*lstDE).ptrUlt = no;
        }
   		return 1;
	}
    return 0;
}


/**
 * Retorna o primeiro item de uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada.
 * @return O primeiro item da lista.
 */
tpItens getItem(tpLDE lstDE){
       return lstDE.ptrPrim->item;
}


/**
 * Exibe no monitor os itens de uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada.
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


/**
 * Verifica se uma lista duplamente encadeada está vazia.
 * @param lst Uma lista duplamente encadeada.
 * @return Verdadeiro caso a lista duplamente encadeada estiver vazia, ou Falso caso contrário.
 */
booleano isEmptyLstDE(tpLDE lst){
    if (lst.quantItens==0) return true;
    return false;
}


/**
 * Procura um item em uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada;
 * @param id O identificador que será buscado na lista.
 * @return O item da lista com o identificador procurado, caso o mesmo seja encontrado na lista, ou um item com identificador 0 caso contrário.
 */
tpItens  searchItemLstDE(tpLDE lst, unsigned int id){
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( (*aux).item.id == id){
            return (*aux).item;
        } else {
            aux = aux->ptrProx;
        }
    }
    tpItens item;
    item.id = 0;
    return item;
}


/**
 * Insere um item no fim de uma lista duplamente encadeada, sem repetições.
 * @param lstDE Uma lista duplamente encadeada;
 * @param item O item que será inserido na lista.
 * @return 1 caso o item for inserido com sucesso, ou 0 caso contrário.
 */
int insertLstDE_SR(tpLDE *lstDE, tpItens item){
    tpItens aux = searchItemLstDE(*lstDE, item.id);
    if (aux.id == 0){
        int aux2 = insertLstDE(lstDE, item);
        if (aux2){
            return 1;
        }
        else{
            return 0;
        }
    }
    else {
        return 0;
    }
}


/**
 * Remove um item de uma lista duplamente encadeada.
 * @param lstDE Uma lista duplamente encadeada;
 * @param id O identificador que será deletado da lista.
 * @return 1 caso o item for removido com sucesso, ou 0 caso contrário.
 */
int deleteLstDE (tpLDE *lstDE, unsigned int id){
    tpNo *aux = lstDE->ptrPrim;
    while(aux != NULL){
        if (aux->item.id == id && aux->ptrAnt == NULL && aux->ptrProx == NULL){
            free(aux);
            lstDE->ptrPrim = NULL;
            lstDE->ptrUlt = NULL;
            lstDE->quantItens = lstDE->quantItens - 1;
            return 1;
        }
        else if (aux->item.id == id && aux->ptrAnt == NULL){
            lstDE->ptrPrim = aux->ptrProx;
            lstDE->ptrPrim->ptrAnt = NULL;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            return 1;
        }
        else if (aux->item.id == id && aux->ptrProx == NULL){
            lstDE->ptrUlt = aux->ptrAnt;
            aux->ptrAnt->ptrProx = NULL;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            return 1;
        }
        else if (aux->item.id == id){
            aux->ptrAnt->ptrProx = aux->ptrProx;
            aux->ptrProx->ptrAnt = aux->ptrAnt;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            return 1;
        }
        else{
            aux = aux->ptrProx;
        }
    }
    return 0;
}


/**
 * Retorna quantos identificadores específicos existem em uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada;
 * @param id O identificador que será contabilizado na lista.
 * @return A quantidade de identificadores iguais ao desejado que existem na lista.
 */
int quantosIds (tpLDE lst, unsigned int id){
    int cont = 0;
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if(aux->item.id == id){
            cont++;
        }
        aux = aux->ptrProx;
    }
    return cont;
}


/**
 * Verifica se uma lista duplamente encadeada está ordenada crescentemente ou não.
 * @param lst Uma lista duplamente encadeada.
 * @return Verdadeiro caso a lista esteja ordenada crescentemente, e Falso caso contrário.
 */
booleano ordenadaOuNao (tpLDE lst){
    tpNo *aux = lst.ptrPrim;
    if (aux == NULL){
        return true;
    }
    while(aux->ptrProx != NULL){
        if (aux->item.id > aux->ptrProx->item.id){
            return false;
        }
        aux = aux->ptrProx;
    }
    return true;
}

//-----------------------------------------------------------------------------
/**
 * Inicializa a Lista e faz a chamada das funções do Menu.
 */
void interfacelstDEncadeada(tpLDE* lstAlunos){

	printf("Simulador de Lista Duplamente Encadeada!\n");
	char op;
	do{
			op = menulstDEncadeada();
			switch (op){
				case '1': inserirAluno(lstAlunos);
						  break;
				case '2': deletarAluno(lstAlunos);
						  break;
				case '3': printLstDE(*lstAlunos);
						  break;
				case '4': pesquisarAluno(*lstAlunos);
						  break;
				case '5': quantosId(*lstAlunos);
						  break;
				case '6': ordenadoOuNao(*lstAlunos);
						  break;
				case '7': printf("Encerrando...\n\n");
						  break;
			}
	}while (op != '7');
}


char menulstDEncadeada() {

	char escolha = 'a';
    printf("\n1 - Inserir aluno.\n2 - Deletar aluno.\n3 - Mostrar alunos cadastrados.\n4 - Pesquisar aluno.\n5 - Quantos id's igual.\n6 - Esta ordenada ou nao.\n7 - Sair do Programa.\n");
    while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5' && escolha != '6' && escolha != '7'){
        printf("Digite a seguir: ");
        escolha = getch();
        printf("\nEscolha feita: %c\n", escolha);
    }
    return escolha;
}

void inserirAluno(tpLDE *lde) {

	tpItens aluno;
    char nome[40];
    unsigned int mat;
    printf("Nome do aluno: ");
    fgets(nome, 40, stdin);
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    aluno = setItem(nome, mat);

    int verificacao = insertLstDE_SR(lde, aluno);
    if (!verificacao){
        printf("Erro ao inserir aluno.\n\n");
    }
    else{
        printf("Item inserido com sucesso.\n\n");
    }
    return;
}

void deletarAluno(tpLDE *lde) {

	unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    int verificacao = deleteLstDE(lde, mat);
    if(!verificacao){
        printf("Erro ao remover aluno.\n\n");
    }
    else{
        printf("Aluno removido com sucesso.\n\n");
    }
    return;
}

void pesquisarAluno(tpLDE lde) {

	unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    tpItens aluno = searchItemLstDE(lde, mat);
    if (aluno.id == 0){
        printf("Aluno nao encontrado.\n\n");
    }
    else{
        printf("Aluno encontrado.\n\n");
        printItem(aluno);
    }
    return;
}

void quantosId (tpLDE lde) {

	unsigned int mat;
    printf("Qual o id a ser pesquisado: ");
    scanf("%d", &mat);
    getchar();
    int cont = quantosIds(lde, mat);
    printf("Quantidade de ids iguais ao digitado: %d\n", cont);
    return;
}

void ordenadoOuNao (tpLDE lde) {

	int aux = ordenadaOuNao(lde);
    if (aux){
        printf("A lista esta ordenada.\n");
        return;
    }
    else{
        printf("A lista NAO esta ordenada.\n");
        return;
    }
}
