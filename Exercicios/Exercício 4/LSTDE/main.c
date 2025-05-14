#include <stdio.h>
#include <stdlib.h>


#include "ListaDE.h"
#include <conio.h>

char menu();
void inserirAluno(tpLDE *lde);
void deletarAluno(tpLDE *lde);
void pesquisarAluno(tpLDE lde);
void quantosId (tpLDE lde);
void ordenadoOuNao (tpLDE lde);

int main() {

	tpLDE lde = initLstDE();
	char op;
	do{
			op = menu();
			switch (op){
				case '1': inserirAluno(&lde);
						  break;
				case '2': deletarAluno(&lde);
						  break;
				case '3': pesquisarAluno(lde);
						  break;
				case '4': printLstDE(lde);
						  break;
				case '5': quantosId(lde);
						  break;
				case '6': ordenadoOuNao(lde);
						  break;
				case '7': printf("\n Hasta la vista baby!");
						  break;
			}
	} while (op != '7');

	return 0;
}

char menu(){

	char escolha;

	printf("\n----------------------------");
	printf("\n 1 - Cadastrar Aluno");
	printf("\n 2 - Remover Aluno");
	printf("\n 3 - Pesquisar Aluno");
	printf("\n 4 - Mostrar Alunos Cadastrados");
	printf("\n 5 - IDs Repetidos?");
	printf("\n 6 - Está ordenada?");
	printf("\n 7 - Sair do Programa");
	printf("\n Escolha uma das opções acima: ");
	do{
	  escolha = getch();
	} while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5') && (escolha !='6') && (escolha !='7'));
	printf(" %c \n----------------------------", escolha);
	return  escolha;
}

void inserirAluno(tpLDE *lde) {

	tpItem aluno;
    char nome[30];
    unsigned int mat;

	printf("\n Digite o nome do aluno: ");
	fgets(nome, 40, stdin);
	printf("\n Digite a matricula do aluno: ");
	scanf("%d",&mat);
	getchar();
	aluno = setItem(nome,mat);  //guardando os dados do aluno no tpItem aluno

	if (insertLstDE_SR(lde, aluno) == 1) {
		printf("\n Aluno inserido com sucesso!");
	} else {
		printf("\n ERRO!!! Aluno não inserido!");
	}

	return;
}

void deletarAluno(tpLDE *lde) {

	unsigned int mat;
	printf("\n Digite a matricula do aluno: ");
	scanf("%d",&mat);
	getchar();

	if (deleteLstDE(lde, mat) == 1) {
		printf("\n Aluno removido com sucesso!");
	} else {
		printf("\n ERRO!!! Aluno não removido!");
	}

	return;
}

void pesquisarAluno(tpLDE lde) {

	unsigned int mat;
	//Pesquisando na lista um aluno
	printf("\n Digite a matricula do aluno: ");
	scanf("%d",&mat);
	getchar();
	tpItem aluno = searchItemLstDE(lde, mat);
	if (aluno.id != 0) {
		printItem(aluno);
	} else {
		printf("Aluno não encontrado\n");
	}
}

void quantosId (tpLDE lde) {

	unsigned int mat;
	//Pesquisando na lista um aluno
	printf("\n Digite o ID: ");
	scanf("%d",&mat);
	getchar();
	int verificacao = quantidadeRepetidaLstDE(lde, mat);
	printf("O id %d aparece na lista um total de %d vezes",mat,verificacao);
}

void ordenadoOuNao (tpLDE lde) {

	int verificacao = estaOrdenada(lde);

	if(verificacao) {

		printf("\nA lista está ordenada crescentemente");
		return;
	} else {

		printf("\nA lista NÃO está ordenada crescentemente");
		return;
	}
}
