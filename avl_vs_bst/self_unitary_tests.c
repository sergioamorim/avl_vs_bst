/* Este programa realiza testes unitários nas funções do projeto avl_vs_bst */


#include <stdio.h>
#include "randomize.h" /* biblioteca de funções de randomização */
#include "arguments.h" /* biblioteca de funções de manipulação de argumentos*/
#include "global.h" /* definição de constantes globais para o projeto */


#define TESTING_NUMBER (17) /* inteiro usado para testar funções */
#define MIN_ARRAY_SIZE (1) /* tamanho mínimo para um array */


/* Funções da biblioteca randomize.h */
bool test_random_interger(); /* testa a função random_interger */
bool test_sort_a_number(); /* testa a função sort_a_number */


/* Funções da biblioteca arguments.h */
bool test_argument_is_set();
bool test_get_argument_value();


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

    /* imprimir OK se a função sort_a_number estiver funcionando */
    printf("argument_is_set function\t\t");
    if (test_argument_is_set() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

    /* imprimir OK se a função sort_a_number estiver funcionando */
    printf("get_argument_value function\t\t");
    if (get_argument_value() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

}


/* Retorna TRUE caso a função random_interger esteja funcionando corretamente
 * e FALSE caso contrário */
bool test_random_interger(){
    if (random_interger(TESTING_NUMBER, TESTING_NUMBER) == TESTING_NUMBER)
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
 * testes aplicados, retorna TRUE; se não, retorna FALSE */
bool test_argument_is_set() {

    /* declarar argumentos fictícios */
    int args_count = 6;
    char args[14][args_count];

    /* setar argumentos fictícios */
    strcpy (args[ZERO], "./program.out");
    strcpy (args[1], "-n17");
    strcpy (args[2], "-s");
    strcpy (args[3], "17");
    strcpy (args[4], "-aiu");
    strcpy (args[5], "p 17");

    /* testar se a função está funcionando para os argumentos fictícios;
     * retornar FALSE caso não esteja */
    if (argument_is_set(args_count, args, 's') != 2)
        return FALSE;
    if (argument_is_set(args_count, args, 'o') != FALSE)
        return FALSE;
    if (argument_is_set(args_count, args, 'n') != 1)
        return FALSE;
    if (argument_is_set(args_count, args, 'i') != 4)
        return FALSE;
    if (argument_is_set(args_count, args, 'p') != FALSE)
        return FALSE;


    return TRUE; /* função funciona corretamente, para os testes aplicados */
}


/* Se os resultados da função get_argument_value estiverem corretos para os
 * testes aplicados, retorna TRUE; se não, retorna FALSE */
bool test_get_argument_value() {

    /* declarar argumentos fictícios */
    int args_count = 6;
    char args[14][args_count];

    /* setar argumentos fictícios */
    strcpy (args[ZERO], "./program.out");
    strcpy (args[1], "-n17");
    strcpy (args[2], "-s");
    strcpy (args[3], "17");
    strcpy (args[4], "-tuj17v")
    strcpy (args[5], "p 17");

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
