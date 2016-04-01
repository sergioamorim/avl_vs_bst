#include <stdio.h>
#include <stdlib.h>

/* Retorna um inteiro aleatório, respeitando um número mínimo e um número má-
 * ximo, recebidos pela função. */
int random_interger(int min, int max){
    return ((rand()%(max-min+1))+min);
}

/* Retorna um inteiro aleatório perterncente a um array;
 * Deve receber um array completamente preenchido e o tamanho do array. */
int sort_a_number(int *array, int array_size){
    return (array[random_interger(0, array_size-1)]);
}
