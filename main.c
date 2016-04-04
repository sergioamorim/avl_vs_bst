/* uso: ./main.out [-h] [-n QUANTITY_OF_NUMBERS] [-s QUANTITY_OF_SORTS]
 *		[-a MAX_NUMBER] [-i MIN_NUMBER] [-f FILE_NAME] [-o]
 *
 * Inclui números aleatórios em duas estruturas de dados: uma AVL e uma
 * árvore de busca binária. Depois, sorteia dentre os números incluídos,
 * números a serem buscados em ambas as estruturas. Para cada busca, o número
 * de comparações necessárias para encontrar o número é contado e servirá para
 * plotar um gráfico que relaciona a quantidade de comparações necessárias com
 * a quantidade de números buscados.
 *
 * argumentos opcionais:
 * -h		exibe essa mensagem de ajuda e finaliza o programa
 * -o 		forçar inserção e busca dos números em ordem (ignora argumen-
 *			tos -a e -i)
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


/* valores padrão para as variáveis do programa, caso algum argumento não seja
 * setado */
#define DEFAULT_QUANTITY_OF_NUMBERS (1000)
#define DEFAULT_QUANTITY_OF_SORTS (500)
#define DEFAULT_MAX_NUMBER (999999)
#define DEFAULT_MIN_NUMBER (-99999)
#define DEFAULT_FILE_NAME "avl_vs_bst"

/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name);


/* retornará ZERO se for executado com sucesso e ERROR caso seja interrompido por
 * alguma falha */
int main (int args_count, char *args[]) {
	
	/* arquivo R que guardará o número de comparações */
	FILE *r_file;
	
	/* nome do arquivo de saída com os números de comparações */
	char file_name[101];
	char r_file_name[103];

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

	file_name_position = argument_is_set(args_count, args, 'f');
	if (file_name_position != ZERO) {
		strcpy(file_name, args[(file_name_position+1)]);
	} else {
		strcpy(file_name, DEFAULT_FILE_NAME);
	}
	strcpy(r_file_name, file_name);
	strcat(r_file_name, ".R");

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

	/* abre o arquivo para inserir os dados que serão coletados */
	r_file = fopen(r_file_name, "w");
	/* em caso de erro ao abrir o arquivo, exibe uma mensagem de erro e inter-
	 * rompe o programa */
	if (r_file == NULL) {
		fprintf(stderr, "ERRO: falha ao tentar escrever no arquivo ");
		fprintf(stderr, "%s.\n", file_name);
		return (ERROR); /* interromper programa */
	}

	/* fazer com que a função de randomização gere números diferentes a cada vez
	 * que o programa roda | atualizar o parâmetro da função de acordo com o
	 * tempo */
	srand(time(NULL));

	/* array que receberá os números aleatórios para sortear depois*/	
	int numbers_array[quantity_of_numbers];
	/* guarda os números aleatórios nas duas estruturas */
	for (i = ZERO; i < quantity_of_numbers; i++) {
		switch (force_order){
			case FALSE:
				sorted_number = random_integer(min_number, max_number);
				break;
			case TRUE:
				sorted_number = i;
		}
		numbers_array[i] = sorted_number; /* guarda para sortear depois */
		
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

	switch (force_order){
		case FALSE:
			sorted_number = sort_a_number(numbers_array, quantity_of_numbers);
			break;
		case TRUE:
			sorted_number = ZERO;				
	}
	quantity_of_numbers--;
	quantity_of_comparisons_avl[ZERO] 
		= search_on_binary_tree(avl,sorted_number);
	quantity_of_comparisons_bst[ZERO]
		= search_on_binary_tree(bst,sorted_number);

	for (i = 1; i < quantity_of_sorts; i++) {
		switch (force_order){
			case FALSE:
				sorted_number = sort_a_number(numbers_array, quantity_of_numbers);
				break;
			case TRUE:
				sorted_number = i;				
		}
		quantity_of_numbers--;
		
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
	fprintf(r_file, "avl <- c(");
	for (i = 0; i < (quantity_of_sorts-1); i++) {
		fprintf(r_file, "%d, ", quantity_of_comparisons_avl[i]);
	}
	fprintf(r_file, "%d", quantity_of_comparisons_avl[i]);
	fprintf(r_file, ")\nbst <- c(");
	for (i = 0; i < (quantity_of_sorts-1); i++) {
		fprintf(r_file, "%d, ", quantity_of_comparisons_bst[i]);
	}
	/* configurações do gráfico */
	fprintf(r_file, "%d", quantity_of_comparisons_bst[i]);
	fprintf(r_file, ")\ncomparisons_range <- range(0, avl, bst)\n");
	fprintf(r_file, "pdf('%s.pdf')\n", file_name);
	fprintf(r_file, "options('scipen'=100, 'digits'=4)\n");
	fprintf(r_file, "searchs_range <- range(0, length(avl))\nplot(avl, ");
	fprintf(r_file, "type='l', col='blue', ylim=comparisons_range,");
	fprintf(r_file, "axes = FALSE, ann = FALSE)\naxis(1, at = searchs_range");
	fprintf(r_file, "[2]/10*0:searchs_range[2])\naxis(2, ");
	fprintf(r_file, "at=comparisons_range[2]/10*0:co");
	fprintf(r_file, "mparisons_range[2])\nbox()\nlines(bst, type = 'l',");
	fprintf(r_file, " col = 'red')\ntitle(main = 'AVL vs ");
	fprintf(r_file, "BST', font.main = 2)\ntitle(ylab = 'Comparações')\n");
	fprintf(r_file, "title(xlab = 'Buscas')\nlegend(1, ");
	fprintf(r_file, "comparisons_range[2], c('AVL', 'BST'), cex = 1, ");
	fprintf(r_file, "col = c('blue', 'red'), lty = 1)");
	
	fclose(r_file); /* fechar arquivo */

	return (ZERO); /* programa executado coma sucesso */

}


/* exibe instruções de uso do programa e informações sobre o funcionamento */
void print_help(char *self_name) {
	printf("uso: %s [-h] [-o] [-n QUANTITY_OF_NUMBERS] [-s QUANT", self_name);
	printf("ITY_OF_SORTS]\n\t\t[-a MAX_NUMBER] [-i MIN_NUMBER] [-f FILE_NAM");
	printf("E]\n\nInclui números aleatórios em duas estruturas de dados: um");
	printf("a AVL e uma\nárvore de busca binária. Depois, sorteia dentre os");
	printf(" números incluídos,\nnúmeros a serem buscados em ambas as estru");
	printf("turas. Para cada busca, o número de\ncomparações necessárias pa");
	printf("ra encontrar o número é contado e servirá para\nplotar um gráfi");
	printf("co que relaciona a quantidade de comparações necessárias com\na");
	printf(" quantidade de números buscados. Pode-se forçar a inclusão e bu");
	printf("sca de números\nem ordem usando o argumento -o.\n\n");
	printf("argumentos opcionais:");
	printf("\n");
	printf("  -h\t\texibe essa mensagem de ajuda e finaliza o programa\n");
	printf("  -o\t\tforça a inserção de números em ordem (ignora argumentos");
	printf(" -a e\n\t\t-i)\n");
	printf("  -n QUANTITY_OF_NUMBERS\n\t\tquantidade de números que serão i");
	printf("ncluídos em ambas as estru-\n\t\tturas de dados (padrão: 1000 |");
	printf("obs: o número -1 não deve ser\n\t\tusado; deve ser maior que a ");
	printf("quantidade de números a serem sor-\n\t\tteados; deve ser um val");
	printf("or positivo)");
	printf("\n");
	printf("  -s QUANTITY_OF_SORTS\n\t\tquantidade de números a serem sorte");
	printf("ados para serem buscados em\n\t\tambas as estruturas (padrão: 5");
	printf("00 | obs: o número -1 não deve\n\t\tser usado; deve ser menor q");
	printf("ue a quantidade de números; deve ser\n\t\tum valor positivo)");
	printf("\n");
	printf("  -a MAX_NUMBER\n\t\tnúmero máximo que pode ser sorteado e incl");
	printf("uído nas estruturas\n\t\t(padrão: 999999 | obs: os números -1 e");
	printf(" o inteiro máximo não\n\t\tdevem ser usados; deve ser maior que");
	printf(") o número mínimo)");
	printf("\n");
	printf("  -i MIN_NUMBER\n\t\tnúmero mínimo que pode ser sorteado e incl");
	printf("uído nas estruturas\n\t\t(padrão: -99999 | obs: o número -1 não");
	printf("deve ser usado; deve ser\n\t\tmenor que o número máximo)");
	printf("\n");
	printf("  -f FILE_NAME\n\t\tnome para o arquivo de saída, sem extensão ");
	printf("(padrão: avl_vs_bst\n\t\t| não deve ultrapassar 100 caracteres;");
	printf(" deve haver um espaço en-\n\t\ttre o argumento e o nome do arqu");
	printf("ivo)\n");
}