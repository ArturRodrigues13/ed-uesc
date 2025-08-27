#include <stdio.h>
#include <stdlib.h>

/**
 * Aloca um vetor com o tamanho desejado.
 * @param tamanho Tamanho do vetor que será alocado.
 * @return Um vetor alocado com o tamanho especificado.
 */
int* initArray(int tamanho);


/**
 * Insere um valor em um vetor.
 * @param array Vetor onde o item será inserido;
 * @param valor Valor que será inserido no vetor;
 * @param currentSize Maior índice atual do vetor;
 * @param maxSize Índice máximo que o vetor pode assumir.
 * @return 1 se o valor foi inserido com sucesso no vetor, ou 0 caso contrário.
 */
int inserirElemento(int* array, int valor, int* currentSize, int maxSize);


/**
 * Remove um valor em um vetor.
 * @param array Vetor onde o valor será removido;
 * @param valor Valor que será removido do vetor;
 * @param currentSize Maior índice atual do vetor.
 * @return 1 se o valor foi removido com sucesso, ou 0 caso contrário.
 */
int removerElemento(int* array, int valor, int* currentSize);


/**
 * Troca um valor por outro novo em um vetor.
 * @param array Vetor onde o valor será editado;
 * @param valorAtual Valor que será editado no vetor;
 * @param valorNovo Novo valor que substituirá o valor atual;
 * @param currentSize Maior índice atual do vetor.
 * @return 1 se o valor foi trocado com sucesso, ou 0 caso contrário.
 */
int editarElemento(int* array, int valorAtual, int valorNovo,  int currentSize);


/**
 * Pesquisa um valor em um vetor.
 * @param array Vetor onde o valor será pesquisado;
 * @param valor Valor que será pesquisado;
 * @param currentSize Maior índice atual do vetor.
 * @return O índice onde o valor foi encontrado, ou -1 caso o valor não for encontrado.
 */
int pesquisarElemento(int* array, int valor, int currentSize);


/**
 * Exibe no monitor os valores de um vetor.
 * @param array Vetor que será impresso;
 * @param currentSize Maior índice atual do vetor.
 * @return
 */
void imprimirVetor(int* array, int currentSize);

void interfaceArray(int* filaP, int* currentSize);
