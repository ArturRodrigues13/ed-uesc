#include <stdio.h>
#include <stdlib.h>
#include "ListaE.h"
#include "interface.h"
#include <conio.h>


//-----------------------------------------------------------------------------
/**
 * Inicializa a Lista e faz a chamada das funções do Menu.
 */
void lstEncadeada(){
	tpNo *lstAlunos = initLstE();
	printf("PROGRAMA ALUNOS!\n");
	char op;
	do{
			op = menu();
			switch (op){
				case '1': cadastrarLstE(&lstAlunos);
						  break;
				case '2': printLstE(lstAlunos);
						  break;
				case '3': consultarLstE(lstAlunos);
						  break;
				case '4': removerLstE(&lstAlunos);
						  break;
				case '5':
						  break;
				case '6': printf("\n Hasta la vista baby!");
			}
	}while (op != '6');
}

//-----------------------------------------------------------------------------
/**
 * Imprime a tabela de escolhas e restringe o input do usuário à uma delas.
 * @return a opção escolhida pelo usuário
 */
char menu(){
	char escolha;

	printf("\n----------------------------");
	printf("\n 1 - Cadastrar Aluno");
	printf("\n 2 - Exibir Alunos");
	printf("\n 3 - Consultar Aluno");
	printf("\n 4 - Remover Aluno");
	printf("\n 5 - Ordenar a Lista");
	printf("\n 6 - Sair do programa");
	printf("\n Escolha uma das opções acima: ");
	do{
	  escolha = getch();
	}while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5') && (escolha !='6'));
	printf(" %c \n----------------------------", escolha);
	return  escolha;
}

//-----------------------------------------------------------------------------
/**
 * Criar um novo aluno do tipo tpItem, fazer suas atribuições e inserir o aluno na Lista.
 * @param lisAl Uma lista de alunos;
 */
void cadastrarLstE(tpNo **lstAl){
	tpItem aluno;
	char nome[30];
	unsigned int mat;

	printf("\n Digite o nome do aluno: ");
	fgets(nome, 30, stdin);
	printf("\n Digite a matricula do aluno: ");
	scanf("%d",&mat);
	getchar();

	if (searchItemLstE(*lstAl,mat) != NULL) {
		printf("Matrícula Já cadastrada!");
		return;
	}

	aluno = setItem(nome,mat);
	tpNo *lstAux = insertLstE(*lstAl, aluno);
	if ( isEmptyLstE(lstAux) ){
		printf("\n ERRO - aluno não cadastrado");
	} else {
		printf("\n CADASTRO COM SUCESSO!!!");
		(*lstAl) = lstAux;
	}

}

//-----------------------------------------------------------------------------
/**
 * Receber uma matrícula fornecida pelo usuário e chamar a função de pesquisa, imprimindo seu resultado.
 * @param lisAl Uma lista de alunos;
 */
void consultarLstE(tpNo *lstAl){
	unsigned int mat;

	printf("\n Digite a matricula do aluno: ");
	scanf("%d",&mat);
	getchar();
	tpItem *al = searchItemLstE(lstAl,mat);
	if ( al != NULL ){
		printf("\n aluno cadastrado");
		printf("\n Nome do aluno: %s", al->nome);
	} else {
		printf("\n ALUNO NÃO CADASTRADO!!!");
	}
}

//-----------------------------------------------------------------------------
/**
 * Receber uma matrícula fornecida pelo usuário e chamar a função de remoção, dando um feedback em relação ao resultado da função.
 * @param lisAl Uma lista de alunos;
 */
void removerLstE(tpNo **lstAl) {
    unsigned int mat;

    printf("\n Digite a matricula do aluno que será removido: ");
    scanf("%d", &mat);
    getchar();

    if (*lstAl != NULL) {
        tpNo *resultado = removeItemLstEAux(lstAl, mat);
        if (resultado != NULL || *lstAl == NULL) {
            printf("\n Aluno com matrícula %d removido com sucesso!", mat);
        } else {
            printf("\n Matrícula %d não encontrada na lista!", mat);
        }
    } else {
        printf("\n ERRO - Lista não inicializada ou vazia!");
    }
}
