/* Este programa realiza testes unitários nas funções do projeto avl_vs_bst 
 * PARA TESTAR AS FUNÇÕES DE MANIPULAÇÃO DE ARGUMENTOS, É NECESSÁRIO INICIAR
 * COM OS PARÂMETROS -n17 -s 17 -tuj17v p17 */


#include <stdio.h>
#include "randomize.h" /* biblioteca de funções de randomização */
#include "arguments.h" /* biblioteca de funções de manipulação de argumentos*/
#include "global.h" /* definição de constantes globais para o projeto */


#define TESTING_NUMBER (17) /* inteiro usado para testar funções */
#define MIN_ARRAY_SIZE (1) /* tamanho mínimo para um array */


/* Funções da biblioteca randomize.h */
bool test_random_integer(); /* testa a função random_integer */
bool test_sort_a_number(); /* testa a função sort_a_number */


/* Funções da biblioteca arguments.h */
bool test_argument_is_set(int args_count, char *args[]);
bool test_get_argument_value(int args_count, char *args[]);


/* Para cada função testada o prograva deve exibir o nome da função e OK se
 * ela passar no teste ou FAIL caso o resultado não seja o esperado.
 * PARA TESTAR AS FUNÇÕES DE MANIPULAÇÃO DE AGUMENTOS É NECESSÁRIO INICIAR
 * COM OS PARÂMETROS -n17 -s 17 -tuj17v p17
 */
void main (int args_count, char *args[]) {
    
    /* imprimir OK se a função random_integer estiver funcionando */
    printf("random_integer function\t\t");
    if (test_random_integer() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

    /* imprimir OK se a função sort_a_number estiver funcionando */
    printf("sort_a_number function\t\t");
    if (test_sort_a_number() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

    /* imprimir OK se a função argument_is_set estiver funcionando */
    printf("argument_is_set function\t\t");
    if (test_argument_is_set(args_count, args) != FALSE)
        printf("OK\n");
    else
        printf("FAIL if initialized with -n17 -s 17 -tuj17v p17\n");

    /* imprimir OK se a função get_argument_value estiver funcionando */
    printf("get_argument_value function\t\t");
    if (test_get_argument_value(args_count, args) != FALSE)
        printf("OK\n");
    else
        printf("FAIL if initialized with -n17 -s 17 -tuj17v p17\n");

}


/* Retorna TRUE caso a função random_integer esteja funcionando corretamente
 * e FALSE caso contrário */
bool test_random_integer(){
    if (random_integer(TESTING_NUMBER, TESTING_NUMBER) == TESTING_NUMBER)
        return (TRUE);
    return (FALSE);
}


/* Retorna TRUE caso a função sort_a_number esteja funcionando corretamente 
 * e FALSE caso contrário. */
bool test_sort_a_number(){
    int array[MIN_ARRAY_SIZE];
    array[ZERO] = TESTING_NUMBER;
    if (sort_a_number(array, MIN_ARRAY_SIZE) == TESTING_NUMBER)
        return (TRUE);
    return (FALSE);
}


/* Se os resultados da função argument_is_set estiverem corretos para os
 * testes aplicados, retorna TRUE; se não, retorna FALSE
 * PARA TESTAR É NECESSÁRIO INICIAR COM OS PARÂMETROS -n17 -s 17 -tuj17v p17*/
bool test_argument_is_set(int args_count, char *args[]) {

    /* testar se a função está funcionando para os argumentos fictícios;
     * retornar FALSE caso não esteja */
    if (argument_is_set(args_count, args, 'n') != 1)
        return FALSE;
    if (argument_is_set(args_count, args, 's') != 2)
        return FALSE;
    if (argument_is_set(args_count, args, 'o') != FALSE)
        return FALSE;
    if (argument_is_set(args_count, args, 'u') != 4)
        return FALSE;
    if (argument_is_set(args_count, args, 'a') != FALSE)
        return FALSE;


    return TRUE; /* função funciona corretamente, para os testes aplicados */
}


/* Se os resultados da função get_argument_value estiverem corretos para os
 * testes aplicados, retorna TRUE; se não, retorna FALSE 
 * PARA TESTAR É NECESSÁRIO INICIAR COM OS PARÂMETROS -n17 -s 17 -tuj17v p17*/
bool test_get_argument_value(int args_count, char *args[]) {

    /* testar se a função está funcionando para os argumentos fictícios;
     * retornar FALSE caso não esteja */
    if (get_argument_value(args_count, args, 'n') != TESTING_NUMBER)
        return FALSE;
    if (get_argument_value(args_count, args, 's') != TESTING_NUMBER)
        return FALSE;
    if (get_argument_value(args_count, args, 'o') != ERROR)
        return FALSE;
    if (get_argument_value(args_count, args, 'u') != ERROR)
        return FALSE;
    if (get_argument_value(args_count, args, 'j') != TESTING_NUMBER)
        return FALSE;
    if (get_argument_value(args_count, args, 'p') != ERROR)
        return FALSE; 

    return TRUE; /* função funciona corretamente, para os testes aplicados */
}
