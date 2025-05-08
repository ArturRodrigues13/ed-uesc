#include <stdio.h>
#include <stdlib.h>
#include "ListaE.h"

/**
 * Inicializa a Lista e faz a chamada das funções do Menu.
 */
void lstEncadeada();

/**
 * Imprime a tabela de escolhas e restringe o input do usuário à uma delas.
 * @return a opção escolhida pelo usuário
 */
char menu();

/**
 * Criar um novo aluno do tipo tpItem, fazer suas atribuições e inserir o aluno na Lista.
 * @param lisAl Uma lista de alunos;
 */
void cadastrarLstE(tpNo **lstAl);

/**
 * Receber uma matrícula fornecida pelo usuário e chamar a função de pesquisa, imprimindo seu resultado.
 * @param lisAl Uma lista de alunos;
 */
void consultarLstE(tpNo *lstAl);

/**
 * Receber uma matrícula fornecida pelo usuário e chamar a função de remoção, dando um feedback em relação ao resultado da função.
 * @param lisAl Uma lista de alunos;
 */
void removerLstE(tpNo **lstAl);
