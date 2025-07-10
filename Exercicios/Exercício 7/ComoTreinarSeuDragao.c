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
	int memoria = 0;
	int diasTotais;
	int diasQuePassou = 0;
	int dias;
	int multa;
	int multaSoma = 0;
	float multaTotal;
	dragao dragGenerico;

	dragao *vetDragoes = (dragao*)malloc(sizeof(dragao));

	scanf("%d %d",&dias,&multa);

	dragGenerico.dias = dias;
	dragGenerico.multa = multa;
	dragGenerico.mediaMulta = ((float) multa) / dias;

	inserirPrio(vetDragoes,dragGenerico,&tamanhoAtual,10000);

	diasTotais = dragGenerico.dias;

	while (diasQuePassou < diasTotais) {

		if(vetDragoes[0].dias == 0) {

			extrairMaxPrio(vetDragoes,&tamanhoAtual);
			multaSoma -= vetDragoes[0].multa;
		}

		multaTotal += multaSoma;

		if(controle == 0) {

			if(scanf("%d %d",&dias,&multa) == 2) {

				dragGenerico.dias = dias;
				dragGenerico.multa = multa;
				dragGenerico.mediaMulta = ((float) multa) / dias;
				multaSoma += multa;

				memoria = tamanhoAtual + 1;

				vetDragoes = realloc(vetDragoes, memoria * sizeof(dragao));

				inserirPrio(vetDragoes,dragGenerico,&tamanhoAtual,10000);

				diasTotais += vetDragoes[tamanhoAtual - 1].dias;

			} else {

				controle = 1;
			}
		}

		diasQuePassou ++;
		vetDragoes[0].dias --;
	}

	free(vetDragoes);
	printf("%.0lf",multaTotal);

	return 0;
}
