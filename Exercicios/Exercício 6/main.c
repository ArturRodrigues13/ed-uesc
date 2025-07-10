#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "AVLFunctions.h"

// Function prototype for menu
char menu();

//-----------------------------------------------------------------------------
/**
 * Inicializa a Árvore e faz a chamada das funções do Menu.
 */
int main(){
	tpArvore *arvore = initArvore();
	printf("ARVORE AVL!\n");
	char op;
	do{
			op = menu();
			switch (op){
				case '1': InserirElementoArvore(&arvore);
						  break;
				case '2': RemoverElementoArvore(arvore);
						  break;
				case '3': BuscarElementoArvore(arvore);
						  break;
				case '4': PrintarArvoreOrdem(arvore);
						  break;
				case '5': PrintarArvoreBonita(arvore);
						  break;
				case '6': printf("\n Bye Bye!");
						  break;

			}
	}while (op != '6');

	return 0;
}

//-----------------------------------------------------------------------------
/**
 * Imprime a tabela de escolhas e restringe o input do usuário à uma delas.
 * @return a opção escolhida pelo usuário
 */
char menu(){
	char escolha;

	printf("\n----------------------------");
	printf("\n 1 - Adicionar Elemento");
	printf("\n 2 - Remover Elemento");
	printf("\n 3 - Buscar Valor na Árvore");
	printf("\n 4 - Printar a Árvore Em Pré-Ordem");
	printf("\n 5 - Printar a Árvore Visual Simulado");
	printf("\n 6 - Sair do programa");
	printf("\n Escolha uma das opções acima: ");
	do{
	  escolha = (char) getch();
	}while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5' && (escolha !='6')));
	printf(" %c \n----------------------------\n", escolha);
	return  escolha;
}

//-----------------------------------------------------------------------------
/**
 * Criar um novo item do tipo tpItem, fazer sua atribuição e inserir o item na Árvore.
 * @param lisAl Uma Árvole AVL;
 */
void InserirElementoArvore(tpArvore** arvore){
	tpItem item;
	int valor;

	printf("\n Digite o valor a ser armazenado: ");
	scanf("%d",&valor);
	getchar();

	item.num = valor;

	tpArvore *arvoreAux = insertArvore(*arvore,item);
	if ( arvoreAux == NULL ){
		printf("\n ERRO - Valor Inválido ou Já Presente na Árvore");
	} else {
		printf("\n Inserido com Sucesso!!!");
		*arvore = arvoreAux;
	}
}

void RemoverElementoArvore(tpArvore* arvore) {
    int valor;

    printf("\n Digite o valor a ser removido: ");
    scanf("%d", &valor);
    getchar();

    if (arvore != NULL) {
        int resultado = removeArvore(&arvore, valor);
        if (resultado == 0) {
            printf("Valor não encontrado na Árvore\n");
        } else {
        	printf("\n Valor %d Removido com Sucesso da Árvore", valor);
        }
    } else {
        printf("\n ERRO - Árvore não inicializada ou vazia!");
    }
}

void BuscarElementoArvore(tpArvore* arvore){
	int valor;

	printf("\n Digite o valor que deseja buscar: ");
	scanf("%d",&valor);
	getchar();

	tpItem item = buscaArvore(arvore,valor);
	if ( item.num != -1 ){
		printf("\n Valor encontrado na Árvore");
	} else {
		printf("\n Valor não presente na Árvore!!!");
	}
}

void PrintarArvoreOrdem(tpArvore* arvore) {

    if (arvore != NULL) {
        printArvoreEmOrdem(arvore);
    } else {
        printf("\n ERRO - Árvore não inicializada ou vazia!");
    }
}

void PrintarArvoreBonita(tpArvore* arvore) {

    if (arvore != NULL) {
        printArvoreBonita(arvore,0);
    } else {
        printf("\n ERRO - Árvore não inicializada ou vazia!");
    }
}
