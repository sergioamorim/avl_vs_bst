#include <stdio.h>
#include "randomize.h"

/* Funções da biblioteca randomize.h */
int test_random_interger();
int test_sort_a_number();


/* Para cada função testada o prograva deve exibir o nome da função e OK se
 * ela passar no teste ou FAIL caso o resultado não seja o esperado. */
int main () {

    printf("random_interger function\t\t");
    if (test_random_interger())
        printf("OK\n");
    else
        printf("FAIL\n");

    printf("sort_a_number function\t\t");
    if (test_sort_a_number())
        printf("OK\n");
    else
        printf("FAIL\n");

    return (0);
}

/* Retorna 1 caso a função random_interger esteja funcionando corretamente
 * e 0 caso contrário */
int test_random_interger(){
    if (random_interger(17,17)==17)
        return (1);
    return (0);
}

/* Retorna 1 caso a função sort_a_number esteja funcionando corretamente 
 * e 0 caso contrário. */
int test_sort_a_number(){
    int array[1];
    array[0] = 17;
    if (sort_a_number(array,1)==17)
        return (1);
    return (0);
}