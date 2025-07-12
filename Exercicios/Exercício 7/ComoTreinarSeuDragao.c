#include <stdio.h>
#include <stdlib.h>

struct Celula {
	unsigned long long dias;
	unsigned long long multa;
	float mediaMulta;
};

typedef struct Celula dragao;

void desceHeap(dragao* dragoes, int n, int i) {

    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior;

    if(esq <= n && dragoes[esq].mediaMulta > dragoes[i].mediaMulta)
        maior = esq;
    else
        maior = i;

    if(dir <= n && dragoes[dir].mediaMulta > dragoes[maior].mediaMulta)
        maior = dir;

    if(maior != i){
        dragao aux = dragoes[i];
        dragoes[i] = dragoes[maior];
        dragoes[maior] = aux;

        desceHeap(dragoes, n, maior);
    }
}

int extrairMaxPrio(dragao* dragoes, int* currentSize) {

	if(*currentSize > 0) {
		dragoes[0] = dragoes[*currentSize - 1];
		(*currentSize)--;
		desceHeap(dragoes, *currentSize,0);
		return 0;
	}
	return -1;
}

void sobeHeap(dragao* dragoes, int indexAtual){
    if(indexAtual == 1 || indexAtual == 2)
        return;

    int pai = (indexAtual-1)/2;

    if(dragoes[pai].mediaMulta < dragoes[indexAtual].mediaMulta){
        dragao aux = dragoes[indexAtual];
        dragoes[indexAtual] = dragoes[pai];
        dragoes[pai] = aux;

        sobeHeap(dragoes, pai);
    }
}

int inserirPrio(dragao* dragoes, dragao drag, int* currentSize, int maxSize) {

    if(*currentSize == maxSize)
        return 0;

    dragoes[*currentSize] = drag;
	sobeHeap(dragoes, *currentSize);

    (*currentSize)++;
    return 1;
}

int main() {

	int tamanhoAtual = 0;
	int controle = 0;
	unsigned long long dias;
	unsigned long long multa;
	int multaSoma = 0;
	unsigned long long multaTotal = 0;
	dragao dragInput;

	dragao* vetDragoes = (dragao*)malloc(100000 * sizeof(dragao));

    if(vetDragoes == NULL) return 0;


	scanf("%llu %llu",&dias,&multa);

	dragInput.dias = dias;
	dragInput.multa = multa;
	dragInput.mediaMulta = ((float) multa) / dias;

	inserirPrio(vetDragoes,dragInput,&tamanhoAtual,100000);

	while (tamanhoAtual > 0)
	{
		if(vetDragoes[0].dias == 0) {

			extrairMaxPrio(vetDragoes,&tamanhoAtual);
			multaSoma -= vetDragoes[0].multa;
		}

		if(tamanhoAtual > 0) multaTotal += multaSoma;

		if(controle == 0) {

			if(scanf("%llu %llu",&dias,&multa) == 2) {

				dragInput.dias = dias;
				dragInput.multa = multa;
				dragInput.mediaMulta = ((float) multa) / dias;
				multaSoma += multa;

				inserirPrio(vetDragoes,dragInput,&tamanhoAtual,100000);

			} else {

				controle = 1;
			}
		}

		if(tamanhoAtual > 0) vetDragoes[0].dias --;
	}

	free(vetDragoes);
	printf("%llu\n",multaTotal);

	return 0;
}
