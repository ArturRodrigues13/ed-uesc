#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "AVLFunctionsChar.h"

// Function prototype for menu
char menu();

//-----------------------------------------------------------------------------
/**
 * Inicializa a Árvore e faz a chamada das funções do Menu.
 */
int main(){
	tpArvore *arvore = initArvore();
	printf("ARVORE AVL de Caracteres!!!\n");
	char op;
	do{
			op = menu();
			switch (op){
				case '1': InserirElementoArvore(&arvore);
						  break;
				case '2': RemoverElementoArvore(&arvore);
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
	printf("\n 3 - Buscar letra na Árvore");
	printf("\n 4 - Printar a Árvore Em Pós-Ordem");
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
	char valor;

	printf("\n Digite a letra a ser armazenada: ");
	scanf("%c",&valor);
	getchar();

	item.letra = valor;

	tpArvore *arvoreAux = insertArvore(*arvore,item);
	if ( arvoreAux == NULL ){
		printf("\n ERRO - Letra Inválida, apenas MAIÚSCULAS");
	} else {
		printf("\n Inserido com Sucesso!!!");
		*arvore = arvoreAux;
	}
}

void RemoverElementoArvore(tpArvore** arvore) {
    char valor;

    printf("\n Digite a letra a ser removida: ");
    scanf("%c", &valor);
    getchar();

    if (arvore != NULL) {
        int resultado = removeArvore(arvore, valor);
        if (resultado == 0) {
            printf("Letra não encontrada na Árvore\n");
        } else {
        	printf("\n Letra %c Removida com Sucesso da Árvore", valor);
        }
    } else {
        printf("\n ERRO - Árvore não inicializada ou vazia!");
    }
}

void BuscarElementoArvore(tpArvore* arvore){
	char valor;

	printf("\n Digite a letra que deseja buscar: ");
	scanf("%c",&valor);
	getchar();

	tpItem item = buscaArvore(arvore,valor);
	if ( item.letra != 'a' ){
		printf("\n Letra encontrada na Árvore");
	} else {
		printf("\n Letra não presente na Árvore!!!");
	}
}

void PrintarArvoreOrdem(tpArvore* arvore) {

    if (arvore != NULL) {
        printArvoreEmPosOrdem(arvore);
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
