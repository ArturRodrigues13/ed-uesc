#include <stdlib.h>

/**
 * Inicia uma fila de prioridade com o tamanho desejado.
 * @param tamanho Tamanho desejado para a fila de prioridade.
 * @return Um vetor alocado com o tamanho desejado.
 */
int* initFilaP(int tamanho);


/**
 * Organiza e define a prioridade de um novo valor inserido no início de uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param n Último índice da fila de prioridade;
 * @param i Índice do novo valor.
 * @return
 */
void desceHeap(int* vet, int n, int i);


/**
 * Organiza e define a prioridade de um novo valor inserido no final de uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param indexAtual Índice do novo valor.
 * @return
 */
void sobeHeap(int* vet, int indexAtual);


/**
 * Aumenta a prioridade de um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade;
 * @param indice Índice do valor que terá a prioridade aumentada;
 * @param aumento A quantidade que será incrementado ao valor.
 * @return 1 caso o aumento de prioridade tenha sido um sucesso, ou 0 caso contrário.
 */
int aumentarPrioIndice(int* vet, int currentSize, int indice, int aumento);


/**
 * Diminui a prioridade de um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade;
 * @param indice Índice do valor que terá a prioridade diminuida;
 * @param aumento A quantidade que será decrementada do valor.
 * @return 1 caso a diminuição de prioridade tenha sido um sucesso, ou 0 caso contrário.
 */
int diminuirPrioIndice(int* vet, int currentSize, int indice, int decressimo);


/**
 * Retira o valor com maior prioridade em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade.
 * @return O valor com maior prioridade, ou -1 caso a fila de prioridade esteja vazia.
 */
int extrairMaxPrio(int* vet, int* currentSize);


/**
 * Insere um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param value O valor que será inserido;
 * @param currentSize Tamanho da fila de prioridade;
 * @param maxSize Tamanho máximo permitido da fila de prioridade.
 * @return 1 caso o valor for inserido com sucesso, ou 0 caso contrário.
 */
int inserirPrio(int* vet, int value, int* currentSize, int maxSize);


/**
 * Exibe no monitor uma fila de prioridade.
 * @param array A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade.
 * @return
 */
void imprimirFila(int* array, int currentSize);

/**
 * Busca um valor na fila de prioridade.
 * @param vet A fila de prioridade;
 * @param x Valor a ser buscado.
 * @param currentSize Tamanho da fila de prioridade.
 * @param indice Indice atual onde será buscado o valor.
 * @return
 */
int BuscaHeap(int* vet, int x, int tamanho, int indice);

void interfaceHeap(int* filaP, int* currentSize);
