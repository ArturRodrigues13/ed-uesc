#include <stdio.h>
#include <stdlib.h>

void buble_sort(int artur[], int tamanho) {

	for (int i = 0; i < tamanho; i++) {
		for (int j = 0; j < tamanho; j++) {
			if (artur[j] > artur[i]) {

				int c = artur[i];
				artur[i] = artur[j];
				artur[j] = c;

			}
		}
	}
}

int main () {

	int artur[9];

	for (int i = 0; i < 10;i++)
	{
		scanf("%d",&artur[i]);
	}

	buble_sort(artur,10);

	for (int i = 0; i < 10;i++)
	{
		printf("%d ",artur[i]);
	}

	return 0;
}
