#include <stdio.h>
#include <stdlib.h>

void intercala(int *vetor, int inicio, int meio, int final) {

	int aux[final];
	int k = final;

	for(int i = inicio; i <= meio; i++) {
		aux[i] = vetor[i];
	}

	for(int i = meio + 1; i <= final; i++) {
		aux[i] = vetor[k];
		k--;
	}

	int E = inicio;
	int D = final;

	for(int i = inicio; i <= final; i++) {
		if(aux[E] <= aux[D]) {
			vetor[i] = aux[E];
			E++;
		} else {
			vetor[i] = aux[D];
			D--;
		}
	}
}

void mergeSort(int *vetor, int inicio, int final) {

	if (inicio >= final)
		return;

	int meio = (inicio + final) / 2;
	mergeSort(vetor,inicio,meio);
	mergeSort(vetor,meio + 1, final);
	intercala(vetor,inicio,meio,final);

}

int main() {

	int vetor[10] = {10,9,8,7,6,5,4,3,2,1};

	for (int i = 0; i < 10;i++)
	{
		printf("%d ",vetor[i]);
	}

	mergeSort(vetor,0,9);

	for (int i = 0; i < 10;i++)
	{
		printf("%d ",vetor[i]);
	}

	return 0;

}
