/* uso: ./main.out [-h] [-n QUANTITY_OF_NUMBERS] [-s QUANTITY_OF_SORTS]
 *
 * Inclui uma quantidade de números determinada por [-n] em duasestruturas de
 * dados: uma AVL e uma árvore de busca binária.Depois, sorteia dentre os nú-
 * meros incluídos uma quandidadedeterminada por [-s] para buscar em ambas as
 * estruturas de dados. Para cada busca, o número de comparações necessárias
 * para encontraro número é contado e servirá para plotar um gráfico que re-
 * lacionaa quantidade de comparações necessárias com a quantidade de números
 * buscados. Caso nenhum argumento seja passado, o programa incluirá 10000 nú-
 * meros aleatórios nas duas estruturas de dados e sorteará 1000 dentre esses
 * números para serem buscados em ambas as árvores.
 *
 * argumentos opcionais:
 * -h	exibe essa mensagem de ajuda e finaliza o programa
 * -n QUANTITY_OF_NUMBERS
 *			quantidade de números que serão incluídos em ambas as estruturas
 *			de dados
 * -n QUANTITY_OF_SORTS
 *			quantidade de números a serem sorteados para serem buscados em
 *			ambas as estruturas
 */

#include <stdio.h>
#include "global.h" /* constantes e funções globais */
#include "arguments.h" /* funções para tratar argumentos */


#define DEFAULT_QUANTITY_OF_NUMBERS (10000)
#define DEFAULT_QUANTITY_OF_SORTS (1000)

/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name);


int main (int args_count, char *args[]) {
	
	int quantity_of_numbers;
	int quantity_of_sorts;
	int i;

    if (argument_is_set(args_count, args, 'h')) {
        print_help(args[ZERO]);
        return (ZERO);
	}

	quantity_of_numbers = get_argument_value(args_count, args, 'n');
	if (quantity_of_numbers == ERROR)
		quantity_of_numbers = DEFAULT_QUANTITY_OF_NUMBERS;
	quantity_of_sorts = get_argument_value(args_count, args, 's');
	if (quantity_of_sorts == ERROR)
		quantity_of_sorts = DEFAULT_QUANTITY_OF_SORTS;
	
	return (ZERO);

}

/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name) {
    printf("uso: %s [-h] [-n QUANTITY_OF_NUMBERS] [-s QUANTITY_OF_SORTS]",
        self_name);
    
    printf("\n\n");
	printf("Inclui uma quantidade de números aleatórios determinada por [-n]\
 em duas\nestruturas dedados: uma AVL e uma árvore de busca binária. Depois,\
 sorteia\ndentre os números incluídos uma quandidade determinada por [-s]\
 para buscar\nem ambas as estruturas de dados. Para cada busca, o número de\
 comparações\nnecessárias para encontrar o número é contado e servirá para\
 plotar um gráfico\nque relaciona a quantidade de comparações necessárias\
 com a quantidade de nú-\nmeros buscados. Caso nenhum argumento seja passado,\
 o programa incluirá 10000\nnúmeros aleatórios nas duas estruturas de dados\
 e sorteará 1000 dentre esses\nnúmeros para serem buscados em ambas as\
 árvores.");
    printf("\n\n");
    
    printf("argumentos opcionais:");
    printf("\n");
    printf("  -h\t\texibe essa mensagem de ajuda e finaliza o programa");
    printf("\n");
    printf("  -n QUANTITY_OF_NUMBERS\n\t\tquantidade de números que serão\n\
        \tincluídos em ambas as estruturas de dados");
    printf("\n");
    printf("  -n QUANTITY_OF_SORTS\n\t\tquantidade de números a serem\n\
        \tsorteados para serem buscados em ambas as estruturas");
    printf("\n");

}