/* uso: ./main.out [-h] [-n QUANTITY_OF_NUMBERS] [-s QUANTITY_OF_SORTS]
 *		[-a MAX_NUMBER] [-i MIN_NUMBER]
 *
 * Inclui uma números aleatórios em duas estruturas de dados: uma AVL e uma
 * árvore de busca binária. Depois, sorteia dentre os números incluídos,
 * números a serem buscados em ambas as estruturas. Para cada busca, o número
 * de comparações necessárias para encontrar o número é contado e servirá para
 * plotar um gráfico que relaciona a quantidade de comparações necessárias com
 * a quantidade de números buscados.
 *
 * argumentos opcionais:
 * -h		exibe essa mensagem de ajuda e finaliza o programa
 * -n QUANTITY_OF_NUMBERS
 *		quantidade de números que serão incluídos em ambas as estruturas de
 *		dados (padrão: 10000 | obs: o número -1 não deve ser usado; deve ser
 *		maior que a quantidade de números a serem sorteados)
 * -s QUANTITY_OF_SORTS
 *		quantidade de números a serem sorteados para serem buscados em ambas
 *		as estruturas (padrão: 1000 | obs: o número -1 não deve ser usado;
 *		deve ser menor que a quantidade de números)
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
#include "trees.h" /*estruturas e funções de AVL e árvores de busca binária */

/* valores padrão para as variáveis do programa, caso algum argumento não seja
 * setado */
#define DEFAULT_QUANTITY_OF_NUMBERS (10000)
#define DEFAULT_QUANTITY_OF_SORTS (1000)
#define DEFAULT_MAX_NUMBER (999999)
#define DEFAULT_MIN_NUMBER (-99999)


/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name);


int main (int args_count, char *args[]) {
	
	/* AVL que será comparada à árvore de busca binária */
	binary_tree_t *avl = create_empty_binary_tree();
	/* árvore de busca binária que será comparada à AVL */
	binary_tree_t *bst = create_empty_binary_tree();
	int quantity_of_numbers; /* quantidade de números a incluir nas árvores */
	int quantity_of_sorts; /* quantidade de números para buscar nas árvores */
	int max_number, min_number; /* limites mínimo e máximo dos números */
	int sorted_number; /* guardará temporariamente o número gerado/sorteado */
	int i; /* será usado como índice para laços */

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

	/* se a quantidade de números a serem sorteados for maior que a quantidade
	 * de números, exibe uma mensagem de erro, as instruções de uso e encerra
	 * o programa */
	if (quantity_of_sorts>quantity_of_numbers) {
		printf("ERRO: a quantidade de números a serem sorteados não deve ultr\
apassar a quanti-\n\tdade de números\n\n");
		print_help(args[ZERO]); /* exibir instruções */
		return (ERROR); /* interromper programa */
	}

	/* se o número mínimo for maior que o número máximo, exibe uma mensagem
	 * de erro, as instruções de uso, e encerra o programa */
	if (min_number>max_number) {
		printf("ERRO: número mínimo deve ser menor que número máximo.\n\n");
		print_help(args[ZERO]); /* exibir instruções */
		return (ERROR); /* interromper programa */
	}
	

	/* array que receberá os números aleatórios para sortear depois*/	
	int numbers_array[quantity_of_numbers];
	/* guarda os números aleatórios nas duas estruturas */
	for (i = ZERO; i < quantity_of_numbers; i++) {
		sorted_number = random_integer(min_number, max_number);
		numbers_array[i] = sorted_number; /* guarda para sortear depois */
		avl = insert_on_binary_tree(avl, sorted_number);
		if (is_avl(avl) != TRUE) {
			avl = balance_binary_tree(avl);
		}
		bst = insert_on_binary_tree(bst, sorted_number);
	}

	/* números aleatórios serão buscados nas duas árvores e arrays guardarão
	 * a quantidade de comparações para cada número sorteado para que o gráfi-
	 * co seja plotado com esses valores depois */
	int quantity_of_comparisons_avl[quantity_of_sorts];
	int quantity_of_comparisons_bst[quantity_of_sorts];
	for (i = ZERO; i < quantity_of_sorts; i++) {
		sorted_number = sort_a_number(numbers_array, quantity_of_numbers);
		quantity_of_numbers--;
		
		/* buscar na AVL e salvar a quantidade de comparações no array 
		 * quantity_of_comparisons_avl, posição i */
		
		/* buscar na BST e salver a quantidade de comparações no array
		 * quantity_of_comparisons_bst, posição i */
	}
	

	/* plotar gráfico com os valores contidos nos arrays
	 * quantity_of_comparisons_avl e quantity_of_comparisons_bst relacionados
	 * com a posição de cada valor */


	return (ZERO); /* programa executado com sucesso */

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
-1 não deve ser\n\t\tusado; deve ser maior que a quantidade de números a sere\
m sor-\n\t\tteados)");
	printf("\n");
	printf("  -s QUANTITY_OF_SORTS\n\t\tquantidade de números a serem sortead\
os para serem buscados em\n\t\tambas as estruturas (padrão: 1000 | obs: o núm\
ero -1 não deve\n\t\tser usado; deve ser menor que a quantidade de números)");
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