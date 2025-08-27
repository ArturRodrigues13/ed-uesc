// Feito em conjunto por Artur Rodrigues Santos, Cauã Clemente Lima e Ronaldo Ribeiro Porto Filho :)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "AVLFunctions.h"
#include "heapFunctions.h"
#include "sortFunctions.h"
#include "arrayFunctions.h"
#include "ListaDE.h"

int main() {

	tpArvore *arvore = initArvore();

	int *filaP = initFilaP(100000);
	int currentSize = 0;

	int *array = initArray(100000);
	int tamanhoAtual = 0;

	tpLDE lstAlunos = initLstDE();

	char escolha;

	do {

		printf("\nBem Vindo ao Testador de EDs e afins, Escolha a Biblioteca que deseja testar");
		printf("\n 1 - Árvore AVL");
		printf("\n 2 - Fila de Prioridade");
		printf("\n 3 - Algoritmos de Ordenação");
		printf("\n 4 - Operações com Vetor");
		printf("\n 5 - Lista Duplamente Encadeada");
		printf("\n 6 - Sair do programa");
		printf("\n Escolha uma das opções acima: ");
		do{
			escolha = (char) getch();
		}while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5' && (escolha !='6')));
		printf(" %c \n----------------------------\n", escolha);

		switch (escolha) {
			case '1':
				interfaceAVL(&arvore);
				break;
			case '2':
				interfaceHeap(filaP, &currentSize);
				break;
			case '3':
				interfaceOrdenacao();
				break;
			case '4':
				interfaceArray(array,&tamanhoAtual);
				break;
			case '5':
				interfacelstDEncadeada(&lstAlunos);
				break;
			case '6':
				printf("Encerrando Programa...\n");
				break;
			default:
				break;
		}
	}while (escolha != '6');

	free(arvore);
	free(filaP);
	free(array);

	return 0;
}
