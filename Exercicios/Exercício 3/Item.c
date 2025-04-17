/********************************************************************
 * Este arquivo implementa um item do tipo Aluno.
 * Nesta implementa��o um aluno possui dois campos: matr�cula e nome.
 * A estrutura de um Aluno est� definida no arquivo Item.h.
 */

#include "Item.h"

//-----------------------------------------------------------------------------
/**
 * @param n = nome do aluno at� 30 caracteres;
 * @param m = natural indicando a matricula do aluno;
 * @return Um tipo Item preenchido com nome=n e matr�cula=m;
 */
tpItem  setItem(char n[], unsigned int m){
    tpItem al;
    strcpy(al.nome, n);
    al.id = m;
    return al;
}

//-----------------------------------------------------------------------------
/**
 * Exibe no v�deo os dados de al.
 * @param al = um item com dados de um aluno;
 * @return
 */
void printItem(tpItem al){
    printf("\n Nome: %s  ",al.nome);
    printf("\n Matricula: %d",al.id);
}
