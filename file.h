/* Funções e constantes relacionadas à leitura e escrita de arquivos */


#include <stdio.h> /* fopen, fprintf, fclose ... */


/* nomes de arquivos pré-definidos */
#define DEFAULT_FILE_NAME "avl_vs_bst" /* nome padrão do arquivo de saída */
#define HELP_FILE_NAME "help.txt" /* contém o menu de ajuda acionado por -h */
#define R_TEMPLATE_FILE_NAME "r_template.txt" /* contém template do gráfico */


/* copia todos os caracteres de um arquivo para outro, retorna ERROR em caso
 * de falha e ZERO se executado com sucesso */
int copy_file(FILE *to, FILE *from);

/* exibe instruções de uso do programa e informações sobre o funcionamento;
 * retorna ERROR em caso de falha e ZERO se executado com sucesso */
int print_help(char *self_name);

/* escreve o arquivo R com os arrays de número de comparações recebidos,
 * e o nome de arquivo recebido; retorna ERROR em caso de falha e ZERO caso
 * executado com sucesso  */
int write_r_file (int *quantity_of_comparisons_avl,
					int *quantity_of_comparisons_bst,
	 				int quantity_of_sorts, char *r_file_name);


/* copia todos os caracteres de um arquivo para outro, retorna ERROR em caso
 * de falha e ZERO se executado com sucesso */
int copy_file(FILE *to_file, FILE *from_file) {

	/* se algum dos arquivos não existir, retorne ERROR */
	if (to_file == NULL || from_file == NULL)
		return (ERROR);

	/* copiar caracter por caracter do arquivo de origem para o arquivo de
	 * destino, até que EOF seja encontrado */
	char character;
	character = getc(from_file);
	while (character != EOF) {
		fprintf(to_file, "%c", character);
		character = getc(from_file);
	}

	return (ZERO); /* a função foi executada com sucesso */
}


/* exibe instruções de uso do programa e informações sobre o funcionamento;
 * retorna ERROR em caso de falha e ZERO se executado com sucesso */
int print_help(char *self_name) {
	/* abre o arquivo que tem as informações de ajuda e verifica se é válido
	 * retornará NULL se não for */
	FILE *help_file = fopen(HELP_FILE_NAME, "r");
	if (help_file == NULL) {
		fprintf(stderr, "ERRO ao abrir arquivo com informações de ajuda.\n");
		return (ERROR);
	}
	/* imprime copia o arquivo de ajuda para a saída padrão */
	printf("uso: %s", self_name);
	copy_file(stdout, help_file);
	return (ZERO); /* a função foi executada com sucesso */
}


/* escreve o arquivo R com os arrays de número de comparações recebidos,
 * e o nome de arquivo recebido; retorna ERROR em caso de falha e ZERO caso
 * executado com sucesso  */
int write_r_file (int *quantity_of_comparisons_avl,
					int *quantity_of_comparisons_bst,
	 				int quantity_of_sorts, char *r_file_name) {
	/* abre o arquivo para inserir os dados coletados */
	FILE *r_file;
	FILE *r_template_file;

	int i; /* servirá como índice para laço */


	r_file = fopen(r_file_name, "w");
	/* em caso de erro ao abrir o arquivo, exibe uma mensagem de erro e inter-
	 * rompe o programa */
	if (r_file == NULL) {
		fprintf(stderr, "ERRO: falha ao tentar escrever no arquivo ");
		fprintf(stderr, "%s.\n", r_file_name);
		return (ERROR); /* interromper programa */
	}

	/* abre o arquivo de configurações do gráfico, em caso de erro exibirá uma
	 * mensagem e retorna-rá ERROR */
	r_template_file = fopen(R_TEMPLATE_FILE_NAME, "r");
	if (r_template_file == NULL) {
		fprintf(stderr, "ERRO: falha ao tentar ler o arquivo ");
		fprintf(stderr, "%s.\n", R_TEMPLATE_FILE_NAME);
		return (ERROR); /* interromper programa */
	}


	/* escreve no arquivo R as as quantidades de comparações como vectors */
	fprintf(r_file, "avl <- c(");
	for (i = ZERO; i < (quantity_of_sorts-1); i++) {
		fprintf(r_file, "%d, ", quantity_of_comparisons_avl[i]);
	}
	fprintf(r_file, "%d", quantity_of_comparisons_avl[i]);

	fprintf(r_file, ")\nbst <- c(");
	for (i = ZERO; i < (quantity_of_sorts-1); i++) {
		fprintf(r_file, "%d, ", quantity_of_comparisons_bst[i]);
	}
	fprintf(r_file, "%d)\n", quantity_of_comparisons_bst[i]);
	
	/* copia as configurações do gráfico para o arquivo */
	fprintf(r_file, "pdf('%s')\n", r_file_name);
	copy_file(r_file, r_template_file);


	fclose(r_template_file); /* fechar arquivo de template */
	fclose(r_file); /* fechar arquivo escrito */

	return (ZERO); /* a função foi executada com sucesso */
}