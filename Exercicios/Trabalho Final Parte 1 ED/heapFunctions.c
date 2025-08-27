#include "heapFunctions.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Inicia uma fila de prioridade com o tamanho desejado.
 * @param tamanho Tamanho desejado para a fila de prioridade.
 * @return Um vetor alocado com o tamanho desejado.
 */
int* initFilaP(int tamanho){
    return ((int*)malloc(sizeof(int)*tamanho));
}


/**
 * Organiza e define a prioridade de um novo valor inserido no início de uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param n Último índice da fila de prioridade;
 * @param i Índice do novo valor.
 * @return
 */
void desceHeap(int* vet, int n, int i){

    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior;

    if(esq <= n && vet[esq] > vet[i])
        maior = esq;
    else
        maior = i;

    if(dir <= n && vet[dir] > vet[maior])
        maior = dir;

    if(maior != i){
        int aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;

        desceHeap(vet, n, maior);
    }
}

int BuscaHeap(int* vet, int x, int tamanho, int indice) {

	if(vet[indice] == x) return indice;

	int esquerda = 2*indice + 1;
	int direita = 2*indice + 2;

	int a = BuscaHeap(vet,x,tamanho,esquerda);
	if(a != -1) return a;

	int b = BuscaHeap(vet,x,tamanho,direita);
	if(b != -1) return b;

	return -1;
}

/**
 * Organiza e define a prioridade de um novo valor inserido no final de uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param indexAtual Índice do novo valor.
 * @return
 */
void sobeHeap(int* vet, int indexAtual){
    if(indexAtual == 0)
        return;

    int pai = (indexAtual-1)/2;

    if(vet[pai] < vet[indexAtual]){
        int aux = vet[indexAtual];
        vet[indexAtual] = vet[pai];
        vet[pai] = aux;

        sobeHeap(vet, pai);
    }
}


/**
 * Aumenta a prioridade de um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade;
 * @param indice Índice do valor que terá a prioridade aumentada;
 * @param aumento A quantidade que será incrementado ao valor.
 * @return 1 caso o aumento de prioridade tenha sido um sucesso, ou 0 caso contrário.
 */
int aumentarPrioIndice(int* vet, int currentSize, int indice, int aumento) {

	if(indice > currentSize - 1) return 0;

	if(currentSize == 0) return 0;

	vet[indice] += aumento;
	sobeHeap(vet,indice);
	return 1;
}


/**
 * Diminui a prioridade de um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade;
 * @param indice Índice do valor que terá a prioridade diminuida;
 * @param aumento A quantidade que será decrementada do valor.
 * @return 1 caso a diminuição de prioridade tenha sido um sucesso, ou 0 caso contrário.
 */
int diminuirPrioIndice(int* vet, int currentSize, int indice, int decressimo) {

	if(indice > currentSize - 1) return 0;

	if(currentSize == 0) return 0;

	vet[indice] -= decressimo;
	desceHeap(vet,currentSize,indice);
	return 1;
}


/**
 * Retira o valor com maior prioridade em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade.
 * @return O valor com maior prioridade, ou -1 caso a fila de prioridade esteja vazia.
 */
int extrairMaxPrio(int* vet, int* currentSize) {

	if(*currentSize > 0) {
		int item = vet[0];
		vet[0] = vet[*currentSize - 1];
		(*currentSize)--;
		desceHeap(vet, *currentSize,0);
		return item;
	}
	return -1;
}


/**
 * Insere um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param value O valor que será inserido;
 * @param currentSize Tamanho da fila de prioridade;
 * @param maxSize Tamanho máximo permitido da fila de prioridade.
 * @return 1 caso o valor for inserido com sucesso, ou 0 caso contrário.
 */
int inserirPrio(int* vet, int value, int* currentSize, int maxSize){
    if(*currentSize == maxSize)
        return 0;

    vet[*currentSize] = value;
    sobeHeap(vet, *currentSize);

    (*currentSize)++;
    return 1;
}


/**
 * Exibe no monitor uma fila de prioridade.
 * @param array A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade.
 * @return
 */
void imprimirFila(int* array, int currentSize){
    for(int i = 0; i < currentSize; i++){
        printf("[%d]", array[i]);
    }
}

void interfaceHeap(int* filaP, int* currentSize) {

	int maxSize = 100000;
    int escolha;

    do{
		printf("Simulador de Fila de Prioridade!\n");
        printf("1 - Inserir um elemento\n");
        printf("2 - Remover o elemento de maior prioridade\n");
        printf("3 - Imprimir elementos da fila de prioridade\n");
		printf("4 - Aumentar a prioridade de um índice\n");
		printf("5 - Diminuir a prioridade de um índice\n");
		printf("6 - Buscar um elemento na fila\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        printf("\n");
        int valor;
		int indice;
        switch(escolha){
            case 1:
                printf("Digite o valor de prioridade a ser inserido na fila: ");
                scanf("%d", &valor);

                if(inserirPrio(filaP, valor, currentSize, maxSize))
                    printf("Elemento inserido com sucesso\n\n");
                else
                    printf("Nao foi possivel inserir o elemento\n\n");
            break;

            case 2:
                if(extrairMaxPrio(filaP, currentSize) == -1)
					printf("Fila não inicializada ou Vazia\n\n");
				else
                	printf("Elemento de maior prioridade removido da fila com sucesso\n\n");
            break;

            case 3:
                printf("Imprimindo todos os elementos da fila de prioridade: ");
                imprimirFila(filaP, *currentSize);
                printf("\n\n");
            break;

			case 4:
				printf("\nDigite o valor do indice: ");
                scanf("%d", &indice);
				printf("\nAgora digite o valor do aumento de sua prioridade: ");
				scanf("%d", &valor);

				if(aumentarPrioIndice(filaP, *currentSize,indice, valor) == 0)
					printf("\nFila não inicializada ou Indice Inválido\n\n");
				else
                	printf("\nPrioridade do Indice %d aumentada com sucesso!\n\n",indice);
			break;

			case 5:
				printf("\nDigite o valor do indice: ");
                scanf("%d", &indice);
				printf("\nAgora digite o valor da diminuição de sua prioridade: ");
				scanf("%d", &valor);

				if(diminuirPrioIndice(filaP, *currentSize,indice, valor) == 0)
					printf("\nFila não inicializada ou Indice Inválido\n\n");
				else
                	printf("\nPrioridade do Indice %d reduzida com sucesso!\n\n",indice);
			break;

			case 6:
				printf("\nDigite o valor a ser buscado: ");
                scanf("%d", &valor);

				int res = BuscaHeap(filaP, valor, *currentSize, 0);

				if(res == -1)
					printf("\nElemento não presente na fila\n\n");
				else
                	printf("\nElemento %d encontrado no índice %d com sucesso!\n\n",valor,res);
			break;

            case 0:
                printf("Saindo...\n\n");
            break;

            default:
                printf("Opcao invalida\n\n");
            break;
        }
    }
    while(escolha != 0);
}
