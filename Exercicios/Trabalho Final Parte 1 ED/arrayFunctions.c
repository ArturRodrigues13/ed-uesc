#include <stdlib.h>
#include <stdio.h>
#include "arrayFunctions.h"

/**
 * Aloca um vetor com o tamanho desejado.
 * @param tamanho Tamanho do vetor que será alocado.
 * @return Um vetor alocado com o tamanho especificado.
 */
int* initArray(int tamanho){
    return ((int*)malloc(sizeof(int)*tamanho));
}


/**
 * Insere um valor em um vetor.
 * @param array Vetor onde o item será inserido;
 * @param valor Valor que será inserido no vetor;
 * @param currentSize Maior índice atual do vetor;
 * @param maxSize Índice máximo que o vetor pode assumir.
 * @return 1 se o valor foi inserido com sucesso no vetor, ou 0 caso contrário.
 */
int inserirElemento(int* array, int valor, int* currentSize, int maxSize){
    if(*currentSize == maxSize){
        return 0;
    }

    array[*currentSize] = valor;
    (*currentSize)++;
    return 1;
}


/**
 * Remove um valor em um vetor.
 * @param array Vetor onde o valor será removido;
 * @param valor Valor que será removido do vetor;
 * @param currentSize Maior índice atual do vetor.
 * @return 1 se o valor foi removido com sucesso, ou 0 caso contrário.
 */
int removerElemento(int* array, int valor, int* currentSize){
    for(int i = 0; i < *currentSize; i++){
        if(array[i] == valor){
            (*currentSize)--;
            for(int j = i; j < *currentSize; j++){
                array[j] = array[j+1];
            }
            return 1;
        }
    }

    return 0;
}


/**
 * Troca um valor por outro novo em um vetor.
 * @param array Vetor onde o valor será editado;
 * @param valorAtual Valor que será editado no vetor;
 * @param valorNovo Novo valor que substituirá o valor atual;
 * @param currentSize Maior índice atual do vetor.
 * @return 1 se o valor foi trocado com sucesso, ou 0 caso contrário.
 */
int editarElemento(int* array, int valorAtual, int valorNovo,  int currentSize){
    for(int i = 0; i < currentSize; i++){
        if(array[i] == valorAtual){
            array[i] = valorNovo;
            return 1;
        }
    }

    return 0;
}


/**
 * Pesquisa um valor em um vetor.
 * @param array Vetor onde o valor será pesquisado;
 * @param valor Valor que será pesquisado;
 * @param currentSize Maior índice atual do vetor.
 * @return O índice onde o valor foi encontrado, ou -1 caso o valor não for encontrado.
 */
int pesquisarElemento(int* array, int valor, int currentSize){
    for(int i = 0; i < currentSize; i++){
        if(array[i] == valor){
            return i;
        }
    }

    return -1;
}


/**
 * Exibe no monitor os valores de um vetor.
 * @param array Vetor que será impresso;
 * @param currentSize Maior índice atual do vetor.
 * @return
 */
void imprimirVetor(int* array, int currentSize){
    for(int i = 0; i < currentSize; i++){
        printf("[%d]", array[i]);
    }
}

void interfaceArray(int* array, int* currentSize) {

	int maxSize = 100000;
    int escolha;

    do{
		printf("Simulador de Operações com Array!\n");
        printf("1 - Inserir um elemento\n");
        printf("2 - Remover um elemento\n");
        printf("3 - Editar elemento no Array\n");
		printf("4 - Pesquisar um elemento\n");
		printf("5 - Imprimir Array\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        printf("\n");
        int valor;
		int valor2;
        switch(escolha){
            case 1:
                printf("Digite o valor a ser inserido no Array: ");
                scanf("%d", &valor);

                if(inserirElemento(array, valor, currentSize, maxSize))
                    printf("Elemento inserido com sucesso\n\n");
                else
                    printf("Nao foi possivel inserir o elemento\n\n");
            break;

            case 2:
				printf("Digite o valor a ser removido no Array: ");
                scanf("%d", &valor);

                if(removerElemento(array,valor, currentSize) == 0)
					printf("Valor não encontrado\n\n");
				else
                	printf("Elemento removido do Array com sucesso\n\n");
            break;

            case 3:
				printf("Digite o valor a ser editado no Array: ");
                scanf("%d", &valor);
				printf("Digite o valor que irá substituir ele: ");
                scanf("%d", &valor2);
                if(editarElemento(array,valor,valor2,*currentSize) == 0)
					printf("Valor não encontrado\n\n");
				else
					printf("Elemento editado com sucesso\n\n");
            break;

			case 4:
				printf("\nDigite o valor que será pesquisado: ");
                scanf("%d", &valor);

				int res = pesquisarElemento(array, valor, *currentSize);
				if(res == -1)
					printf("\nValor não encontrado\n\n");
				else
                	printf("\nValor %d encotrado com sucesso no indice %d!\n\n",valor,res);
			break;

			case 5:
				printf("Imprimindo todos os elementos do Array: ");
                imprimirVetor(array, *currentSize);
                printf("\n\n");
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
