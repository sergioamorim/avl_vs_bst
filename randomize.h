#include <stdlib.h> /* rand() */
#include "global.h" /* constantes e funções globais do projeto */

/* Recebe um array e duas posições do array; troca os valores das
 * posições recebidas entre si */
void swap(int *array, int position_a, int position_b) {
	int aux;
	aux = array[position_a];
	array[position_a] = array[position_b];
	array[position_b] = aux;
}

/* Retorna um inteiro aleatório, respeitando um número mínimo e um número má-
 * ximo, recebidos pela função. */
int random_integer(int min, int max){
    return ((rand()%(max-min+1))+min);
}

/* Retorna um inteiro aleatório pertencente a um array e troca o valor do
 * número sorteado com o número na última posição do array. Deve receber um
 * array completamente preenchido e o tamanho do array. */
int sort_a_number(int *array, int array_size){
	/* sorteia uma posição do array e salva o valor do array nessa posição */
	int random_position = random_integer(ZERO, (array_size-1));
	int sorted_number = array[random_position];
	
	/* troca a posição sorteada com a última posição do array */
	swap(array, random_position, (array_size-1));

   	return (sorted_number); /* retorna o valor do array na posição sorteada */
}