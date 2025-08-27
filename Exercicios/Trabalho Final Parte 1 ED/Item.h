#include <string.h>
#include <stdio.h>

#define false 0;
#define true 1;
typedef int booleano;

struct tpAluno {
    char nome[30];
    unsigned int id; //matr�cula
};

typedef struct tpAluno tpItens;

/**
 * Cria um item preenchido com nome e matrícula.
 * @param n Nome do aluno até 30 caracteres;
 * @param m Natural indicando a matricula do aluno.
 * @return Um tipo Item preenchido com nome e matrícula.
 */
tpItens setItem( char n[],unsigned int m);


/**
 * Exibe no monitor os dados de um item.
 * @param al Um item com dados de um aluno.
 * @return
 */
void printItem(tpItens al);
