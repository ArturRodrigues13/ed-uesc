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

int main(){

	int n;

	scanf("%d",&n);

    int* Vet = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {

        scanf("%d",&Vet[i]);
    }


    int tamanhoP = 0;
    int tamanhoI = 0;
    int controleP = 0;
    int controleI = 0;

    for(int i = 0; i < n; i++) {

        if(Vet[i] % 2 == 0){
            tamanhoP ++;
        } else {
            tamanhoI ++;
        }
    }

	int* pares = (int*)malloc(sizeof(int) * tamanhoP);
	int* impares = (int*)malloc(sizeof(int) * tamanhoI);

    for(int i = 0; i < n; i++) {

        if(Vet[i] % 2 == 0){
            pares[controleP] = Vet[i];
            controleP ++;
        } else {
            impares[controleI] = Vet[i];
            controleI ++;
        }
    }

	for(int i = 0; i < tamanhoI; i++) {

		impares[i] *= -1;
	}

    mergeSort(pares,0,tamanhoP - 1);
    mergeSort(impares,0,tamanhoI - 1);

	for(int i = 0; i < tamanhoI; i++) {

		impares[i] *= -1;
	}

    for(int i = 0; i < tamanhoP; i++) {

        Vet[i] = pares[i];
    }

    for(int i = tamanhoP, j = 0;i < n; i++, j++) {

        Vet[i] = impares[j];
    }

    for(int i = 0; i < n; i++) {

        printf("%d\n",Vet[i]);
    }

	free(Vet);
	free(pares);
	free(impares);

    return 0;
}
