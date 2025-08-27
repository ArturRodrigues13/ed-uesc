#include "Item.h"

/**
 * Cria um item preenchido com nome e matrícula.
 * @param n Nome do aluno até 30 caracteres;
 * @param m Natural indicando a matricula do aluno.
 * @return Um tipo Item preenchido com nome e matrícula.
 */
tpItens  setItem(char n[], unsigned int m){
    tpItens al;
    strcpy(al.nome, n);
    al.id = m;
    return al;
}


/**
 * Exibe no monitor os dados de um item.
 * @param al Um item com dados de um aluno.
 * @return
 */
void printItem(tpItens al){
    printf("\n Nome: %s  ",al.nome);
    printf("\n Matricula: %d",al.id);
}
