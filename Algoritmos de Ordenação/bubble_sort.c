#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int vet[], int tamanho) {

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

int main () {

	int vet[9];

	for (int i = 0; i < 10;i++)
	{
		scanf("%d",&vet[i]);
	}

	bubble_sort(vet,10);

	for (int i = 0; i < 10;i++)
	{
		printf("%d ",vet[i]);
	}

	return 0;
}
