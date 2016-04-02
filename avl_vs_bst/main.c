/* uso: ./main.out [-h] [-n QUANTITY_OF_NUMBERS] [-s QUANTITY_OF_SORTS]
 *		[-a MAX_NUMBER] [-i MIN_NUMBER]
 *
 * Inclui uma números aleatórios em duas estruturas de dados: uma AVL e uma
 * árvore de busca binária. Depois, sorteia dentre os números incluídos,
 * números a serem buscados em ambas as estruturas. Para cada busca, o númerode
 * comparações necessárias para encontrar o número é contado e servirá para
 * plotar um gráfico que relaciona a quantidade de comparações necessárias com
 * a quantidade de números buscados.
 *
 * argumentos opcionais:
 * -h		exibe essa mensagem de ajuda e finaliza o programa
 * -n QUANTITY_OF_NUMBERS
 *		quantidade de números que serão incluídos em ambas as estruturas de
 *		dados (padrão: 10000 | obs: o número -1 não deve ser usado)
 * -s QUANTITY_OF_SORTS
 *		quantidade de números a serem sorteados para serem buscados em ambas
 *		as estruturas (padrão: 1000 | obs: o número -1 não deve ser usado)
 * -a MAX_NUMBER
 *		número máximo que pode ser sorteado e incluído nas estruturas (padrão:
 *		999999 | obs: os números -1 e o inteiro máximo não devem ser usados)
 * -i MIN_NUMBER
 *		número mínimo que pode ser sorteado e incluído nas estruturas (padrão:
 * 		-99999 | obs: o número -1 não deve ser usado)
 */

#include <stdio.h>
#include "global.h" /* constantes e funções globais */
#include "arguments.h" /* funções para tratar argumentos */
#include "randomize.h" /* funções para randomização de números */


#define DEFAULT_QUANTITY_OF_NUMBERS (10000)
#define DEFAULT_QUANTITY_OF_SORTS (1000)
#define DEFAULT_MAX_NUMBER (999999)
#define DEFAULT_MIN_NUMBER (-99999)

/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name);


int main (int args_count, char *args[]) {
	
	int quantity_of_numbers;
	int quantity_of_sorts;
	int max_number, min_number;
	int sorted_number;
	int i;

	/* se o argumento de ajuda foi passado, exibir instruções e finalizar */
	if (argument_is_set(args_count, args, 'h')) {
		print_help(args[ZERO]);
		return (ZERO);
	}


	/* Recebe os valores dos argumentos. Caso não haja valor para algum argu-
	 * mento, um valor padrão é atribuído. */
	quantity_of_numbers = get_argument_value(args_count, args, 'n');
	if (quantity_of_numbers == ERROR)
		quantity_of_numbers = DEFAULT_QUANTITY_OF_NUMBERS;

	quantity_of_sorts = get_argument_value(args_count, args, 's');
	if (quantity_of_sorts == ERROR)
		quantity_of_sorts = DEFAULT_QUANTITY_OF_SORTS;

	max_number = get_argument_value(args_count, args, 'a');
	if (max_number == ERROR)
		max_number = DEFAULT_MAX_NUMBER;

	min_number = get_argument_value(args_count, args, 'i');
	if (min_number == ERROR)
		min_number = DEFAULT_MIN_NUMBER;

	/* se o número mínimo for maior que o número máximo, exibe uma mensagem
	 * de erro, as instruções de uso, e encerra o programa */
	if (min_number>max_number) {
		printf("ERRO: O número mínimo deve ser menor que o número máximo.\n\n");
		print_help(args[ZERO]);
		return (ERROR); 
	}


	int numbers_array[quantity_of_numbers];
	for (i = ZERO; i < quantity_of_numbers; i++) {
		sorted_number = random_integer(min_number, max_number);
		printf("%d\n", sorted_number);
		numbers_array[i] = sorted_number;
	}
	
	return (ZERO);

}

/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name) {
	printf("uso: %s [-h] [-n QUANTITY_OF_NUMBERS] [-s QUANTITY_OF_SORTS]\n\
\t\t[-a MAX_NUMBER] [-i MIN_NUMBER]",
		self_name);
	
	printf("\n\n");
	printf("Inclui uma números aleatórios em duas estruturas de dados: uma AV\
L e uma\nárvore de busca binária. Depois, sorteia dentre os números incluídos\
,\nnúmeros a serem buscados em ambas as estruturas. Para cada busca, o número\
 de\ncomparações necessárias para encontrar o número é contado e servirá para\
\nplotar um gráfico que relaciona a quantidade de comparações necessárias com\
\na quantidade de números buscados.");
	printf("\n\n");
	
	printf("argumentos opcionais:");
	printf("\n");
	printf("  -h\t\texibe essa mensagem de ajuda e finaliza o programa");
	printf("\n");
	printf("  -n QUANTITY_OF_NUMBERS\n\t\tquantidade de números que serão inc\
luídos em ambas as estru-\n\t\tturas de dados (padrão: 10000 | obs: o número \
-1 não deve ser\n\t\tusado)");
	printf("\n");
	printf("  -s QUANTITY_OF_SORTS\n\t\tquantidade de números a serem sortead\
os para serem buscados em\n\t\tambas as estruturas (padrão: 1000 | obs: o núm\
ero -1 não deve\n\t\tser usado)");
	printf("\n");
	printf("  -a MAX_NUMBER\n\t\tnúmero máximo que pode ser sorteado e incluí\
do nas estruturas\n\t\t(padrão: 999999 | obs: os números -1 e o inteiro máxim\
o não\n\t\tdevem ser usados; deve ser maior que o número mínimo)");
	printf("\n");
	printf("  -i MIN_NUMBER\n\t\tnúmero mínimo que pode ser sorteado e incluí\
do nas estruturas\n\t\t(padrão: -99999 | obs: o número -1 não deve ser usado;\
 deve ser\n\t\tmenor que o número máximo)\
");
	printf("\n");

}