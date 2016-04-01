#include <stdio.h>
#include "global.h" /* constantes e funções globais */
#include "arguments.h" /* funções para tratar argumentos */

#define DEFAULT_QUANTITY_OF_NUMBERS = 10000 
#define DEFAULT_QUANTITY_OF_SORTS = 1000


void main (int args_count, char *args[]) {
	
	int quantity_of_numbers = get_argument_value(args_count, args, 'n');
	if (quantity_of_numbers == ERROR)
		quantity_of_numbers = DEFAULT_QUANTITY_OF_NUMBERS;
	int quantity_of_sorts = get_argument_value(args_count, args, 's');
    if (quantity_of_sorts == ERROR)
        quantity_of_sorts = DEFAULT_QUANTITY_OF_SORTS;


	int i;
	

}