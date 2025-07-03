#include <stdio.h>
#include <stdlib.h>

int particiona(int *vetor, int inicio, int final) {

	int pivo = vetor[final];
	int esquerda = inicio - 1;

	for (int direita = inicio; direita < final; direita++) {
		if (vetor[direita] <= pivo) {
			esquerda++;
			int c = vetor[esquerda];
			vetor[esquerda] = vetor[direita];
			vetor[direita] = c;
		}
	}

	esquerda++;

	int c = vetor[esquerda];
	vetor[esquerda] = vetor[final];
	vetor[final] = c;

	return esquerda;
}

void quickSort(int *vetor, int inicio, int final) {

	if (inicio < final) {
		int q = particiona(vetor,inicio,final);
		quickSort(vetor,inicio,q-1);
		quickSort(vetor,q+1,final);
	} else {
		return;
	}
}

int main() {

	int vetor[10] = {99,33,55,77,11,22,88,66,33,44};

	for (int i = 0; i < 10;i++)
	{
		printf("%d ",vetor[i]);
	}

	quickSort(vetor,0,9);

	for (int i = 0; i < 10;i++)
	{
		printf("%d ",vetor[i]);
	}

	return 0;

}
