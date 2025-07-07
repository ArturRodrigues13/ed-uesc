#include <stdio.h>
#include <stdlib.h>

void desceHeap(int* vetor, int tamanho, int indice) {

	int esquerda = 2*indice + 1;
	int direita = 2*indice + 2;
	int maior;

	if(esquerda <= tamanho && vetor[esquerda] > vetor[indice]) {

		maior = esquerda;
	} else {

		maior = indice;
	}

	if(direita <= tamanho && vetor[direita] > vetor[maior]) {

		maior = direita;
	}

	if(maior != indice) {

		int aux = vetor[indice];
		vetor[indice] = vetor[maior];
		vetor[maior] = aux;

		desceHeap(vetor,tamanho,maior);
	}
}

void sobeHeap(int* vetor, int indice) {

	int pai = (indice - 1) / 2;

	if(indice > 0 && vetor[pai] < vetor[indice]) {

		int aux = vetor[pai];
		vetor[pai] = vetor[indice];
		vetor[indice] = aux;

		sobeHeap(vetor,pai);
	}
}

void constroiHeap(int* vetor, int tamanho) {

	for(int i = tamanho / 2 - 1; i >= 0; i --) {

		desceHeap(vetor,tamanho,i);
	}
}

int main() {

	int tamanho = 11;

	int vet[tamanho];

	for (int i = 0; i < tamanho;i++)
	{
		scanf("%d",&vet[i]);
	}

	printf("\nVetor original:\n");
	for (int i = 0; i < tamanho;i++)
	{
		printf("%d ",vet[i]);
	}

	constroiHeap(vet,tamanho);

	printf("\nVetor em heap:\n");
	for (int i = 0; i < tamanho;i++)
	{
		printf("%d ",vet[i]);
	}

	return 0;
}
