#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Ordena um vetor utilizando o método do Bubble Sort.
 * @param vet O vetor que será ordenado;
 * @param tamanho O tamanho do vetor que será ordenado.
 * @return
 */
void bubbleSort(int* vet, int tamanho);


/**
 * Ordena um vetor utilizando o método do Merge Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return
 */
void mergeSort(int* vet, int i, int f);


/**
 * Intercala crescentemente os valores dos índices de um vetor em um intervalo.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param meio Índice do meio do intervalo;
 * @param fim Índice do final do intervalo.
 * @return
 */
void intercala(int* vet, int init, int meio, int fim);


/**
 * Ordena um vetor utilizando o método do Quick Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return
 */
void quickSort(int* vet, int i, int f);


/**
 * Organiza o vetor de forma que, em um intervalo, e a partir de um pivô, todos os valores maiores que o mesmo ficam à sua direita, e todos os menores, à sua esquerda, deixando o pivô na posição correta no vetor.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param fim Índice do final do intervalo.
 * @return O índice final do pivô.
 */
int particiona(int* vet, int init, int fim);


/**
 * Ordena um vetor utilizando o método do Quick Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return
 */
void quickSortRandom(int* vet, int i, int f);


/**
 * Organiza o vetor de forma que, em um intervalo, e a partir de um pivô, todos os valores maiores que o mesmo ficam à sua direita, e todos os menores, à sua esquerda, deixando o pivô na posição correta no vetor.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param fim Índice do final do intervalo.
 * @return O índice final do pivô.
 */
int particionaRandom(int* vet, int init, int fim);

void interfaceOrdenacao();
