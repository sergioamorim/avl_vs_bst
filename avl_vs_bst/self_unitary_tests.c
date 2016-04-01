/* Este programa realiza testes unitários nas funções do projeto avl_vs_bst */


#include <stdio.h>
#include "randomize.h" /* biblioteca de funções de randomização */
#include "global.h" /* definição de constantes globais para o projeto */

#define TESTING_NUMBER (17) /* inteiro usado para testar funções */
#define MIN_ARRAY_SIZE (1) /* tamanho mínimo para um array */

/* Funções da biblioteca randomize.h */
int test_random_interger(); /* testa a função random_interger */
int test_sort_a_number(); /* testa a função sort_a_number */


/* Para cada função testada o prograva deve exibir o nome da função e OK se
 * ela passar no teste ou FAIL caso o resultado não seja o esperado. 
 */
void main () {
    
    /* imprimir OK se a função random_interger estiver funcionando */
    printf("random_interger function\t\t");
    if (test_random_interger() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");


    /* imprimir OK se a função sort_a_number estiver funcionando */
    printf("sort_a_number function\t\t");
    if (test_sort_a_number() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

}

/* Retorna 1 caso a função random_interger esteja funcionando corretamente
 * e 0 caso contrário
 */
int test_random_interger(){
    if (random_interger(TESTING_NUMBER, TESTING_NUMBER) == TESTING_NUMBER)
        return (TRUE);
    return (FALSE);
}

/* Retorna 1 caso a função sort_a_number esteja funcionando corretamente 
 * e 0 caso contrário.
 */
int test_sort_a_number(){
    int array[MIN_ARRAY_SIZE];
    array[ZERO] = TESTING_NUMBER;
    if (sort_a_number(array, MIN_ARRAY_SIZE) == TESTING_NUMBER)
        return (TRUE);
    return (FALSE);
}
