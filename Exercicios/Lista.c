// Exercício 1. Vamos trabalhar com o TAD lista sobre vetor. Esta é uma versão bem simples.

// Parte 1:
// Após certificar que o arquivo está compilando e executando, faça as seguintes modificações:

// 1. No programa principal façaa os tratamentos de erros adequados, por exemplo a mensagem de erro: ”Não há espaço para novo item”;

// 2. Acrescente ao TAD Lista a operação int Pesquisa(Lista *lista, int elemento); A operaçãoo deverá receber um elemento e pesquisar
// na lista, caso encontre devolve o índice do elemento na lista, caso contrário devolve -1.

// 3. Acrescente a função de ordenação MergeSort (Lista *lista) ao TAD.

// 4. Teste as novas operações;

// Parte 2:
// Altere o programa principal para que um menu seja exibido com as seguintes opções:

// 1- Inserir item na lista
// 2- Remover item da lista
// 3- Exibir lista
// 4- Pesquisar item na lista
// 5- Ordenar crescentemente a lista
// 6- Sair

// Enquanto o usuário não selecionar 6, o programa não finaliza. Para cada opção do menu, crie uma função. Seu código deve
// ser feito de forma modular e legível.

// Parte 3:

// 1. Comente sobre o código criado. Que observações você faria sobre este código?
// 2. Quais as vantagens e desvantagens de se ter todo o código em um único arquivo?
// 3. Como podemos separar o TAD do resto do código?

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 5

/* TAD lista usando vetor.
   elementos = vetor de inteiros [0..CAPACIDADE-1];
   tamanho= armazena a quantidade de elementos existentes na lista.

   Funções:
   void inicializarLista(Lista *lista);
   int estaCheia(Lista *lista);
   int adicionaElemento(Lista *lista, int elemento);
   int removeElemento(Lista *lista, int indice);
   void imprimiLista(Lista *lista);

*/

typedef struct {
    int elementos[CAPACIDADE];
    int tamanho;
} Lista;

/* Função para inicializar a lista como uma lista vazia;
   Entrada: uma estrutura do tipo Lista;
   Saída: uma Lista vazia;
*/
void inicializaLista(Lista *lista) {
    lista->tamanho = 0;
}

/* Função para verificar se a lista está cheia.
   Entrada: uma Lista;
   Saída: verdadeiro se a lista estiver cheia e falso caso contrário.
*/

int estaCheia(Lista *lista) {
    return lista->tamanho == CAPACIDADE;
}

/* Função para adicionar um elemento à lista.
   Entrada: uma Lista e um elemento inteiro;
   Saída: 1 se o elemento foi inserido na Lista e 0 caso contrário (lista sem espaço).
*/
int adicionaElemento(Lista *lista, int elemento) {
    if (estaCheia(lista)) {
        return 0; // Falha ao adicionar elemento
    }
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return 1; // Sucesso
}

/* Função do Menu para o usuário indicar qual elemento será adicionado na lista.
   Entrada: uma Lista e um inteiro que armazenará o elemento que será adicionado na lista;
   Saída: chamada da função adicionaElemento com a lista e o elemento anteriormente definidos como argumentos.
*/
int inserirItem(Lista *lista, int elemento) {
	printf("\nPerfeito, me diga o elemento que será adicionado na Lista: ");
	scanf("%d",&elemento);
	return adicionaElemento(lista, elemento);
}

/* Função para remover um elemento da lista (por índice)
   Entrada: uma Lista e o índice do elemento que se deseja remover.
   Saída: 1 se o elemento foi removido com sucesso ou 0 caso contrário.
*/
int removeElemento(Lista *lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        return 0; // Índice inválido
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1; // Sucesso
}

/* Função do Menu para o usuário indicar qual índice será removido da lista.
   Entrada: uma Lista e um inteiro que armazenará o índice que será removido da lista;
   Saída: chamada da função removeElemento com a lista e o índice anteriormente definidos como argumentos.
*/
int removerItem(Lista *lista, int indice) {
	printf("\nPerfeito, me diga o índice que será removido da Lista: ");
	scanf("%d",&indice);
	return removeElemento(lista, indice);
}



/* Função para imprimir os elementos da lista
   Entrada: uma Lista.
   Saída: os elementos da Lista exibidos na tela.
*/
void imprimiLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

/* Função do Menu que traz um pouco mais de legibilidade ao código.
   Entrada: uma Lista;
   Saída: chamada da função imprimiLista com a lista como argumento.
*/
void exibirLista(Lista *lista) {
	printf("\nAqui está sua lista atual:\n");
	imprimiLista(lista);
}

/* Função para pesquisar um elemento na lista
   Entrada: uma Lista e o elemento que se deseja procurar.
   Saída: o índice do elemento se ele foi encontradp com sucesso ou -1 caso contrário.
*/
int pesquisarElemento(Lista *lista, int elemento) {
	for ( int i = 0 ; i < lista->tamanho ; i++ ) {
		if (elemento == lista->elementos[i]) {
			return i; // Sucesso
		}
	}
	return -1; // Elemento não presente na lista.
}

/* Função do Menu para o usuário indicar qual elemento ele deseja pesquisar na lista.
   Entrada: uma Lista e um inteiro que armazenará o elemento que terá sua presença verificada na lista;
   Saída: chamada da função pesquisarElemento com a lista e o elemento anteriormente definidos como argumentos.
*/
int pesquisarItem(Lista *lista, int elemento) {
	printf("\nPerfeito, me diga qual elemento você deseja pesquisar na Lista: ");
	scanf("%d",&elemento);
	return pesquisarElemento(lista, elemento);
}

/* Função para exibir erros que o usuário pode ter ao chamar as funções.
   Entrada: um inteiro que define qual erro ocorreu;
   Saída: impressão de uma mensagem de feedback que muda conforme qual erro foi recebido.
*/
void printarErro(int indiceErro) {
	if(indiceErro == 0) {
		printf("\nNão há espaço para novo item.\nCAPACIDADE MÁXIMA = %d\n",CAPACIDADE);
	} else if(indiceErro == 1) {
		printf("\nÍndice fora de alcance.\n");
	} else if(indiceErro == 2) {
		printf("\nElemento não pôde ser encontrado no Vetor");
	}
}

/* Função para ordenar um vetor de forma Crescente.
   Entrada: um vetor, o seu ínicio, o índice do meio e o seu último ínidice, todos inteiros;
   Saída: vetor ordenado de forma Crescente.
*/
void intercala(int *vetor, int inicio, int meio, int final) {

	int auxVet[final];
	int auxVar = final;

	for(int i = inicio; i <= meio; i++) {
		auxVet[i] = vetor[i];
	}

	for(int i = meio + 1; i <= final; i++) {
		auxVet[i] = vetor[auxVar];
		auxVar--;
	}

	int esquerda = inicio;
	int direita = final;

	for(int i = inicio; i <= final; i++) {
		if(auxVet[esquerda] <= auxVet[direita]) {
			vetor[i] = auxVet[esquerda];
			esquerda++;
		} else {
			vetor[i] = auxVet[direita];
			direita--;
		}
	}
}

/* Função para ordenar um vetor de forma Crescente.
   Entrada: um vetor, o seu ínicio e o seu último ínidice, todos inteiros;
   Saída: vetor ordenado de forma Crescente.
*/
void mergeSort(int *vetor, int inicio, int final) {

	if (inicio >= final)
		return;

	int meio = (inicio + final) / 2;
	mergeSort(vetor,inicio,meio);
	mergeSort(vetor,meio + 1, final);
	intercala(vetor,inicio,meio,final);

}

int main() {
    Lista minhaLista;
    inicializaLista(&minhaLista);
	int escolha, auxiliar = 0;

	printf("Bem vindo ao TAD\n\nSelecione uma opção no menu a seguir:");

	while (escolha != 6)
	{
		printf("\n\nO que deseja fazer agora?");
		printf("\n1. Inserir item na lista");
		printf("\n2. Remover item da lista");
		printf("\n3. Exibir lista");
		printf("\n4. Pesquisar item na lista");
		printf("\n5. Ordenar crescentemente a lista");
		printf("\n6. Encerrar Programa");
		printf("\n\nDigite sua Resposta: ");

		scanf("%d",&escolha);

		switch (escolha)
		{

		case 1:
			if (inserirItem(&minhaLista, auxiliar) == 0)
				printarErro(0);
			else
				printf("\nElemento adicionado com sucesso");
			break;

		case 2:
			if (removerItem(&minhaLista, auxiliar) == 0)
				printarErro(1);
			else
				printf("\nElemento no índice %d removido com sucesso",auxiliar);
			break;

		case 3:
			exibirLista(&minhaLista);
			break;

		case 4:
			auxiliar = pesquisarItem(&minhaLista, auxiliar);
			if (auxiliar == -1)
				printarErro(2);
			else
				printf("\nO elemento que você pesquisou está no índice [%d]",auxiliar);
			break;

		case 5:
			mergeSort(minhaLista.elementos,0,minhaLista.tamanho-1);
			printf("\nVetor Ordenado de forma Crescente.");
			break;

		case 6:
			printf("\nEncerrando Programa...");
			break;

		default:
			printf("\nEscolha inválida, por favor tente novamente");
			break;

		}
	}

    return 0;
}
