/* Inclui números aleatórios em duas estruturas de dados: uma AVL e uma
 * árvore de busca binária. Depois, sorteia dentre os números incluídos,
 * números a serem buscados em ambas as estruturas. Para cada busca, o número
 * de comparações necessárias para encontrar o número é contado e servirá para
 * plotar um gráfico que relaciona a quantidade de comparações necessárias com
 * a quantidade de números buscados.
 *
 * uso: ./main.out [-h] [-o] [-R] [-n QUANTITY_OF_NUMBERS]
 *					[-s QUANTITY_OF_SORTS] [-a MAX_NUMBER]
 * 					[-i MIN_NUMBER] [-f FILE_NAME]
 *
 * argumentos opcionais:
 * -h		exibe essa mensagem de ajuda e finaliza o programa
 * -o 		forçar inserção e busca dos números em ordem (ignora argumen-
 *			tos -a e -i)
 * -R 		plota o gráfico usando R (é necessário possuir o R instalado)
 * -n QUANTITY_OF_NUMBERS
 *		quantidade de números que serão incluídos em ambas as estruturas de
 *		dados (padrão: 1000 | obs: o número -1 não deve ser usado; deve ser
 *		maior que a quantidade de números a serem sorteados; deve ser um valor
 *		positivo)
 * -s QUANTITY_OF_SORTS
 *		quantidade de números a serem sorteados para serem buscados em ambas
 *		as estruturas (padrão: 500 | obs: o número -1 não deve ser usado;
 *		deve ser menor que a quantidade de números; deve ser um valor positi-
 *		vo)
 * -a MAX_NUMBER
 *		número máximo que pode ser sorteado e incluído nas estruturas (padrão:
 *		999999 | obs: os números -1 e o inteiro máximo não devem ser usados;
 *		deve ser maior que o número mínimo)
 * -i MIN_NUMBER
 *		número mínimo que pode ser sorteado e incluído nas estruturas (padrão:
 * 		-99999 | obs: o número -1 não deve ser usado; deve ser menor que o nú-
 *		mero máximo)
 * -f FILE_NAME
 *		nome para o arquivo de saída, sem extensão (padrão: avl_vs_bst | não deve 
 *		ultrapassar 100 caracteres; deve haver um espaço entre o argumento e
 *		o nome do arquivo)
 */


#include <stdio.h>
#include <string.h> /* função strcpy */
#include <time.h> /* função time */
#include <stdlib.h> /* função srand */
#include "global.h" /* constantes e funções globais */
#include "arguments.h" /* funções para tratar argumentos */
#include "randomize.h" /* funções para randomização de números */
#include "trees.h" /*estruturas e funções de AVL e árvores de busca binária */
#include "file.h" /* funções relativas ao tratamento de arquivos */


/* valores padrão para as variáveis do programa, caso algum argumento não seja
 * setado */
#define DEFAULT_QUANTITY_OF_NUMBERS (1000)
#define DEFAULT_QUANTITY_OF_SORTS (1000)
#define DEFAULT_MAX_NUMBER (999999)
#define DEFAULT_MIN_NUMBER (-99999)
#define FILENAME_LIMIT (101)


/* retornará ZERO se for executado com sucesso e ERROR caso seja interrompido por
 * alguma falha */
int main (int args_count, char *args[]) {
	
	/* arquivo R que guardará o número de comparações */
	FILE *r_file;
	
	/* nome do arquivo de saída com os números de comparações */
	char file_name[FILENAME_LIMIT];

	/* comando que será usado para plotar o gráfico a partir do arquivo gera-
	 * do, caso o argumento -R esteja setado */
	char plot_command[FILENAME_LIMIT+31];

	/* AVL que será comparada à árvore de busca binária */
	binary_tree_t *avl = create_empty_binary_tree();
	
	/* árvore de busca binária que será comparada à AVL */
	binary_tree_t *bst = create_empty_binary_tree();
	
	int quantity_of_numbers; /* quantidade de números a incluir nas árvores */
	int quantity_of_sorts; /* quantidade de números para buscar nas árvores */
	int max_number, min_number; /* limites mínimo e máximo dos números */
	int sorted_number; /* guardará temporariamente o número gerado/sorteado */

	/* guardará a posição do nome do arquivo nos argumentos, se houver */
	int file_name_position; 
	int i; /* será usado como índice para laços */

	/* guarda se o argumento -o foi setado para forçar inserção em ordem */
	bool force_order = (argument_is_set(args_count, args, 'o') != FALSE);


	/* Os arrays abaixo serão declarados tão logo quanto as variáveis que de-
	 * finem seus tamanhos forem setadas:
	 ***receberá a quantidade de comparações para encontrar números na AVL
	 *	int quantity_of_comparisons_avl[quantity_of_sorts]
	 ***receberá a quantidade de comparações para encontrar números na BST
	 *	int quantity_of_comparisons_bst[quantity_of_sorts]
	 ***guardará os números incluídos nas árvores para sortear depois
	 *	int numbers_array[quantity_of_numbers]
	 */


	/* se o argumento de ajuda foi passado, exibir instruções e finalizar */
	if (argument_is_set(args_count, args, 'h')) {
		if (print_help(args[ZERO]) != ZERO)
			return (ERROR);
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

	file_name_position = argument_is_set(args_count, args, 'f');
	if (file_name_position != ZERO) {
		strcpy(file_name, args[(file_name_position+1)]);
	} else {
		strcpy(file_name, DEFAULT_FILE_NAME);
	}


	/* se alguma das quantidades for negativa, exibe uma mensagem de erro,
	 * exibe as instruções de uso e encerra o programa */
	if (quantity_of_sorts < ZERO || quantity_of_numbers < ZERO) {
		fprintf(stderr, "ERRO: quantidades devem ser positivas.\n\n");
		print_help(args[ZERO]); /* exibir instruções */
		return (ERROR); /* interromper programa */
	}

	/* se a quantidade de números a serem sorteados for maior que a quantidade
	 * de números, exibe uma mensagem de erro, as instruções de uso e encerra
	 * o programa */
	if (quantity_of_sorts>quantity_of_numbers) {
		fprintf(stderr, "ERRO: a quantidade de números a serem sorteados nã");
		fprintf(stderr,"o deve ultrapassar a quanti-\n\tdade de números\n\n");
		print_help(args[ZERO]); /* exibir instruções */
		return (ERROR); /* interromper programa */
	}

	/* se o número mínimo for maior que o número máximo, exibe uma mensagem
	 * de erro, as instruções de uso, e encerra o programa */
	if (min_number>max_number) {
		fprintf(stderr, "ERRO: número mínimo deve ser menor que número máxi");
		fprintf(stderr, "mo.\n\n");
		print_help(args[ZERO]); /* exibir instruções */
		return (ERROR); /* interromper programa */
	}

	
	
	/* fazer com que a função de randomização gere números diferentes a cada vez
	 * que o programa roda | atualizar o parâmetro da função de acordo com o
	 * tempo */
	srand(time(NULL));


	/* array que receberá os números aleatórios para sortear depois*/	
	int numbers_array[quantity_of_numbers];
	/* guarda os números aleatórios nas duas estruturas (e no array) */
	for (i = ZERO; i < quantity_of_numbers; i++) {
		switch (force_order){
			case FALSE:
				sorted_number = random_integer(min_number, max_number);
				numbers_array[i] = sorted_number; /* para sortear depois */
				break;
			case TRUE:
				sorted_number = i;
		}
		
		/* inserir o número sorteado na AVL */
		avl = insert_on_binary_tree(avl, sorted_number);

		/* inserir o número sorteado na árvore de busca binária */
		bst = insert_on_binary_tree(bst, sorted_number);
	}

	avl = balance_binary_tree(avl); /* formar a AVL */


	/* números aleatórios serão buscados nas duas árvores e arrays guardarão
	 * a quantidade de comparações para cada número sorteado para que o gráfi-
	 * co seja plotado com esses valores depois */
	int quantity_of_comparisons_avl[quantity_of_sorts];
	int quantity_of_comparisons_bst[quantity_of_sorts];

	/* realizar buscas por números e salvar o número de comparações em forma
	 * de somatório no array de informações de cada estrutura */
	switch (force_order){
		case FALSE:
			sorted_number = sort_a_number(numbers_array, quantity_of_numbers);
			/* ao usar a função sort_a_number, o número sorteado vai para
			 * o final do array; decrementar o tamanho do array garantirá
			 * que um número não seja sorteado mais de uma vez */
			quantity_of_numbers--;
			break;
		case TRUE:
			sorted_number = ZERO;				
	}
	quantity_of_comparisons_avl[ZERO] 
		= search_on_binary_tree(avl,sorted_number);
	quantity_of_comparisons_bst[ZERO]
		= search_on_binary_tree(bst,sorted_number);
	for (i = 1; i < quantity_of_sorts; i++) {
		/* caso o atributo -o exista, os números serão buscados em ordem */
		switch (force_order){ 
			case FALSE:
				sorted_number = sort_a_number(numbers_array,
												quantity_of_numbers);
				/* ao usar a função sort_a_number, o número sorteado vai para
				 * o final do array; decrementar o tamanho do array garantirá
				 * que um número não seja sorteado mais de uma vez */
				quantity_of_numbers--;
				break;
			case TRUE:
				sorted_number = i;				
		}
		
		/* buscar na AVL e salvar a quantidade de comparações no array 
		 * quantity_of_comparisons_avl, posição i */
		quantity_of_comparisons_avl[i]
			= search_on_binary_tree(avl, sorted_number)
			  + quantity_of_comparisons_avl[(i-1)];
		
		/* buscar na BST e salver a quantidade de comparações no array
		 * quantity_of_comparisons_bst, posição i */
		quantity_of_comparisons_bst[i]
			= search_on_binary_tree(bst, sorted_number)
			  + quantity_of_comparisons_bst[(i-1)];
	}
	
	/* salva o somatório do número de comparações em um arquivo R; este arqui-
	 * vo servirá para plotar o gráfico com os valores contidos nos arrays
	 * quantity_of_comparisons_avl e quantity_of_comparisons_bst relacionados
	 * com a posição de cada valor */
	 write_r_file(quantity_of_comparisons_avl, quantity_of_comparisons_bst,
	 				quantity_of_sorts, file_name);

	 /* plotar gráfico a partir do arquivo que foi escrito, caso o comando -R
	  * esteja setado */
	if (argument_is_set(args_count, args, 'R') != FALSE) {
		/* comando que será usado para plotar o gráfico */
		sprintf (plot_command, "R < $PWD/%s.R --no-save --slave", file_name);
		system (plot_command);
	}

	return (ZERO); /* programa executado coma sucesso */

}