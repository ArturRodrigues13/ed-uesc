#include "sortFunctions.h"

/**
 * Ordena um vetor utilizando o método do Bubble Sort.
 * @param vet O vetor que será ordenado;
 * @param tamanho O tamanho do vetor que será ordenado.
 * @return
 */
void bubbleSort(int* vet, int tamanho){
    int aux;
    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - i - 1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}


/**
 * Ordena um vetor utilizando o método do Merge Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return
 */
void mergeSort(int* vet, int i, int f){
    if(i>=f)
        return;

    int meio = (f + i) / 2;
    mergeSort(vet, i, meio);
    mergeSort(vet, meio + 1, f);
    intercala(vet, i, meio, f);
}


/**
 * Intercala crescentemente os valores dos índices de um vetor em um intervalo.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param meio Índice do meio do intervalo;
 * @param fim Índice do final do intervalo.
 * @return
 */
void intercala(int* vet, int init, int meio, int fim){
    int* vetAux = (int*)malloc(sizeof(int) * (unsigned long long)(fim - init + 1));
    int aux = 0;

    int v1 = init;
    int v2 = meio+1;

    while(v1 <= meio && v2 <= fim){
        if(vet[v1] <= vet[v2]){
            vetAux[aux] = vet[v1];
            aux++;
            v1++;
        }
        else{
            vetAux[aux] = vet[v2];
            aux++;
            v2++;
        }
    }

    while(v1 <= meio){
        vetAux[aux] = vet[v1];
        v1++;
        aux++;
    }

    while(v2 <= fim){
        vetAux[aux] = vet[v2];
        v2++;
        aux++;
    }

    aux = 0;
    for(int x = init; x <= fim; x++){
        vet[x] = vetAux[aux];
        aux++;
    }

    free(vetAux);
}


/**
 * Ordena um vetor utilizando o método do Quick Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return
 */
void quickSort(int* vet, int i, int f){
    if(i >= f)
        return;

    int pivot = particiona(vet, i, f);
    quickSort(vet, i, pivot - 1);
    quickSort(vet, pivot + 1, f);
}


/**
 * Organiza o vetor de forma que, em um intervalo, e a partir de um pivô, todos os valores maiores que o mesmo ficam à sua direita, e todos os menores, à sua esquerda, deixando o pivô na posição correta no vetor.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param fim Índice do final do intervalo.
 * @return O índice final do pivô.
 */
int particiona(int* vet, int init, int fim){

    int v1 = init-1;
    int v2 = init;

    int pivot = vet[fim];

    int aux;
    for(; v2 < fim;v2++){
        if(vet[v2] < pivot){
            v1++;
            aux = vet[v2];
            vet[v2] = vet[v1];
            vet[v1] = aux;
        }
    }

    v1++;
    vet[fim] = vet[v1];
    vet[v1] = pivot;

    return v1;
}


/**
 * Ordena um vetor utilizando o método do Quick Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return
 */
void quickSortRandom(int* vet, int i, int f){
    if(i >= f)
        return;

    int pivot = particionaRandom(vet, i, f);
    quickSortRandom(vet, i, pivot - 1);
    quickSortRandom(vet, pivot + 1, f);
}


/**
 * Organiza o vetor de forma que, em um intervalo, e a partir de um pivô, todos os valores maiores que o mesmo ficam à sua direita, e todos os menores, à sua esquerda, deixando o pivô na posição correta no vetor.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param fim Índice do final do intervalo.
 * @return O índice final do pivô.
 */
int particionaRandom(int* vet, int init, int fim){

    int v1 = init-1;
    int v2 = init;

    int randomindex = init + (rand() % (fim - init + 1));

    int pivot = vet[randomindex];

    int aux;
    for(; v2 <= fim; v2++){
        if(v2 == randomindex){}
        else if(vet[v2] < pivot){
            v1++;
            if(v1!=randomindex){
                aux = vet[v2];
                vet[v2] = vet[v1];
                vet[v1] = aux;
            }
            else{
                aux = vet[v2];
                vet[v2] = vet[v1+1];
                vet[v1+1] = vet[v1];
                vet[v1] = aux;
                randomindex++;
            }
        }
    }

    v1++;
    vet[randomindex] = vet[v1];
    vet[v1] = pivot;

    return v1;
}

void interfaceOrdenacao() {

	int escolha;
	int tamanho;
	int valor;

	printf("Simulador de Algoritmos de Ordenação!\n");
	printf("Primeiro, defina um tamanho para o Array de testes: ");
	scanf("%d",&tamanho);
	int *vet = (int*)malloc(sizeof(int)*tamanho);
	printf("Okay, agora insira os elementos\n");
	for(int i = 0; i < tamanho;i++) {

		scanf("%d",&valor);
		vet[i] = valor;
	}

	printf("Perfeito, este será o vetor que você usará para as operações!");

	do{

		printf("O que deseja fazer agora?\n");
        printf("1 - Imprimir Vetor\n");
        printf("2 - Bubble Sort\n");
        printf("3 - Merge Sort\n");
		printf("4 - Quick Sort\n");
		printf("5 - Quick Sort Random\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        printf("\n");
        switch(escolha){
            case 1:
				for(int i = 0; i < tamanho; i++){
					printf("[%d]", vet[i]);
				}
            break;

            case 2:
                bubbleSort(vet,tamanho);
			    printf("Vetor Ordenado!");
            break;

            case 3:
                mergeSort(vet,0,tamanho - 1);
				printf("Vetor Ordenado!");
            break;

			case 4:
				quickSort(vet,0,tamanho -1);
				printf("Vetor Ordenado!");
			break;

			case 5:
				quickSortRandom(vet,0,tamanho-1);
				printf("Vetor Ordenado!");
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
