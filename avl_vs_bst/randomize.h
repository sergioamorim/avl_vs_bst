#include <stdio.h>
#include <stdlib.h> /* definição da função rand() */
#include "global.h" /* constantes e funções globais do projeto */

/* Retorna um inteiro aleatório, respeitando um número mínimo e um número má-
 * ximo, recebidos pela função. */
int random_interger(int min, int max){
    return ((rand()%(max-min+1))+min);
}

/* Retorna um inteiro aleatório perterncente a um array;
 * Deve receber um array completamente preenchido e o tamanho do array. */
int sort_a_number(int *array, int array_size){
	/* sorteia uma posição do array, depois retorna o inteiro dessa posição */
	int random_position = random_interger(ZERO, (array_size-1));
    return (array[random_position]);
}