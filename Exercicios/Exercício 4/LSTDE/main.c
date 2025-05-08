#include <stdio.h>
#include <stdlib.h>


#include "ListaDE.h"
#include <conio.h>      //as fun��es do conio s�o �teis para manipular caracteres na tela, especificar cor de car�cter e de fundo.

int main()
{   tpLDE lde = initLstDE();
    tpItem aluno;
    char escolha;
    char nome[30];
    unsigned int mat;

    printf("prim=%p, ult=%p, quant=%d ",lde.ptrPrim, lde.ptrUlt, lde.quantItens);

    do{
        //lendo dados de um item aluno
        printf("\n Digite o nome do aluno: ");
        scanf("%s",nome);
        printf("\n Digite a matricula do aluno: ");
        scanf("%d",&mat);
        aluno = setItem(nome,mat);  //guardando os dados do aluno no tpItem aluno

        //guardando na lista
        if (insertLstDE_SR(&lde, aluno) == 1) {
            printf("\n Aluno inserido com sucesso!");
            printf("\n prim=%p, ult=%p, quant=%d ",lde.ptrPrim, lde.ptrUlt, lde.quantItens);
        } else {
            printf("\n ERRO!!! Aluno n�o inserido!");
        }

        //Pesquisando na lista um aluno
        printf("\n Digite a matricula do aluno: ");
        scanf("%d",&mat);
        aluno = searchItemLstDE(lde, mat);
        if (aluno.id != 0) {
            printItem(aluno);
        } else {

			printf("Aluno não encontrado\n");
		}

		//Pesquisando na lista um aluno
        printf("\n Digite a matricula do aluno: ");
        scanf("%d",&mat);
        //guardando na lista
        if (deleteLstDE(&lde, mat) == 1) {
            printf("\n Aluno removido com sucesso!");
            printf("\n prim=%p, ult=%p, quant=%d ",lde.ptrPrim, lde.ptrUlt, lde.quantItens);
        } else {
            printf("\n ERRO!!! Aluno n�o removido!");
        }


        printf("Digite 1 para continuar ou 0 para sair. \n");
        escolha = getch();
        printf("\n Escolha: %c \n----------------------------", escolha);
  }while (escolha !='0');

    printf("\n FIM!\n");
    return 0;
}
