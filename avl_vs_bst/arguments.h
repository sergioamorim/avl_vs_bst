/* Funções e constantes relacionadas à manipulação de argumentos 
 */


#include <stdio.h>
#include "global.h" /* constantes e funções globais */


/* Constantes relacionadas à manipulação de argumentos */
#define ARG_SYMBOL ('-') /* símbolo que precede argumentos */
#define MAX_VALUE_LENGTH (10) /* comprimento máximo para valor de argumento */


/* Recebe a contagem de argumentos, um array de argumentos e um argumento de-
 * sejado. Caso o argumento desejado estiver contido no array de argumentos,
 * retorna a posição do argumento no array de argumentos; caso contrário, re-
 * torna FALSE */
bool argument_is_set(int args_count, char *args[], char arg) {

	int i, j; /* índices dos laços para iterar posições dos argumentos */
	for (i = 1; i < args_count; i++) {
		if (args[i][ZERO] == ARG_SYMBOL){ /* o argumento pode estar a seguir */
			for (j = 1; args[i][j] != NULL_CHAR; j++){
				if (args[i][j] == arg) /* se o argumento for encontrado */
					return i; /* retorna a posição do argumento */
			}
		}
	}

	return FALSE; /* o argumento não foi encontrado */
}


/* Recebe o número de argumentos, a lista de strings com os argumentos
 * e qual o argumento desejado;
 * Retorna o valor inteiro o argumento desejado, ou ERROR caso o valor não
 * seja encontrado */
int get_argument_value(int args_count, char *args[], char arg) {
	
	int index_arg_value_str = ZERO; /* indíce para adicionar valor à string */
	int arg_value; /* receberá o inteiro do valor do argumento */
	char arg_value_str[MAX_VALUE_LENGTH]; /* string para valor do argumento */

	/* receberá posição onde o argumento se encontra no array, ou FALSE */
	int arg_pos = argument_is_set(args_count, args, arg); 

	/* caso não exista o argumento desejado no array de argumentos: ERROR */
	if (arg_pos == FALSE)
		return ERROR; /* o argumento não está no array de argumentos */ 
	
	/* verificar argumentos em busca do argumento solicitado */
	if (args[arg_pos][ZERO] == ARG_SYMBOL && args[i][1] == arg) {
		
		/* salvar o valor em uma string, caso esteja concatenado */
		while (atoi(args[i][(index_arg_value_str+2])) != ZERO) {
			arg_value_str[index_arg_value_str] =
				args[i][(index_arg_value_str+2)];
			index_arg_value_str++;
		}

		/* se o valor do argumento não foi encontrado concatenado ao argumen-
		 * to, o valor deve estar no próximo argumento */
		if (index_arg_value_str == ZERO) {
			/* salvar o valor em uma string */
			while (atoi(args[(arg_pos+1)][index_arg_value_str]) != ZERO) {
				arg_value_str[index_arg_value_str] = 
					args[(arg_pos+1)][index_arg_value_str];
				index_arg_value_str++;
			}
		}

		/* se nenhum valor foi obtido, houve erro ao passar os argumentos */
		if (index_arg_value_str == ZERO)
			return ERROR;

		/* finalizar a string com o valor obtido */
		arg_value_str[index_arg_value_str] = NULL_CHAR;
		arg_value = atoi(arg_value_str); /* inteiro do valor obtido */

		return arg_value; /* retornar o valor obtido como inteiro */
	}

	return ERROR; /* o argumento não foi encontrado */
}