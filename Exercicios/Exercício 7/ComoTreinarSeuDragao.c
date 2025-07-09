#include <stdio.h>
#include <stdlib.h>

struct Celula
{
	int dias;
	int multa;
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

int inserirPrio(dragao* dragoes, dragao drag, int* currentSize, int maxSize) {

    if(*currentSize == maxSize)
        return 0;

    dragoes[*currentSize] = drag;

    (*currentSize)++;
    return 1;
}

int main() {

	int n;
	int tamanhoAtual = 0;
	int controle = 1;
	int diasTotais;
	int diasQuePassou = 0;
	int dias;
	int multa;
	float multaTotal;
	dragao dragGenerico;

	scanf("%d",&n);

	dragao *vetDragoes = (dragao*)malloc(sizeof(dragao) * n);

	scanf("%d %d",&dias,&multa);

	dragGenerico.dias = dias;
	dragGenerico.multa = multa;
	dragGenerico.mediaMulta = ((float) multa) / dias;

	inserirPrio(vetDragoes,dragGenerico,&tamanhoAtual,n);

	diasTotais = dragGenerico.dias;

	while (diasQuePassou < diasTotais) {

		if(vetDragoes[0].dias == 0) extrairMaxPrio(vetDragoes,&tamanhoAtual);

		for(int i = 1; i < tamanhoAtual; i++) multaTotal += vetDragoes[i].multa;

		if(controle < 5) {

			scanf("%d %d",&dias,&multa);

			dragGenerico.dias = dias;
			dragGenerico.multa = multa;
			dragGenerico.mediaMulta = ((float) multa) / dias;

			inserirPrio(vetDragoes,dragGenerico,&tamanhoAtual,n);

			diasTotais += vetDragoes[tamanhoAtual - 1].dias;
		}

		controle ++;
		diasQuePassou ++;
		vetDragoes[0].dias --;
	}

	free(vetDragoes);
	printf("%.0lf",multaTotal);

	return 0;
}
