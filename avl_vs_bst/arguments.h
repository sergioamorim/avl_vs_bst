#include <stdio.h>
#include "global.h"


/* recebe o número de argumentos, a lista de strings com os argumentos
 * e qual o argumento desejado;
 * retorna o valor inteiro o argumento desejado, ou ERROR caso o valor não
 * seja encontrado */
int get_argument_value(int args_count, char *args[], char c) {
	
	char arg_value_str[10]; /* string que receberá o valor do argumento */
	int index_arg_value_str = ZERO; /* indíce para adicionar valor à string */
	int arg_value; /* receberá o inteiro do valor do argumento */


	for (i = 1; i < args_count; i++) {
		/* verificar argumentos em busca do argumento solicitado */
		if (args[i][ZERO] == '-' && args[i][1] == c) {
			
			/* salvar o valor em uma string, caso esteja concatenado */
			while (atoi(args[i][index_arg_value_str+2]) != ZERO) {
				arg_value_str[index_arg_value_str] =
					args[i][index_arg_value_str+2];
				index_arg_value_str++;
			}

			/* caso esse seja o último argumento e nenhum valor foi encontra-
			 * do, houve um erro ao passar os argumentos */
			if ((i+1) == args_count && index_arg_value_str == ZERO)
				return ERROR;

			/* se o valor do argumento não foi encontrado concatenado ao argu-
			 * mento, o valor deve estar no próximo argumento */
			if (index_arg_value_str == ZERO) {
				/* salvar o valor em uma string */
				while (args[(i+1)][index_arg_value_str] != ZERO) {
					arg_value_str[index_arg_value_str] = 
						args[(i+1)][index_arg_value_str];
					index_arg_value_str++;
				}
			}

			/* se nenhum valor foi obtido, houve um erro ao passar os argu-
			 * mentos */
			if (index_arg_value_str == ZERO)
				return ERROR;

			/* finalizar a string com o valor obtido */
			arg_value_str[index_arg_value_str] = '\0';
			arg_value = atoi(arg_value_str); /* inteiro do valor obtido */

			return arg_value; /* retornar o valor obtido como inteiro */
		}
	}

	return ERROR; /* o argumento não foi encontrado */
}