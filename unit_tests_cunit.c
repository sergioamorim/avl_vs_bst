#include <stdio.h>
#include "randomize.h" /* biblioteca de funções de randomização */
#include "trees.h" /* biblioteca com estrutura e funções de BST e AVL */
#include "global.h" /* definição de constantes globais para o projeto */
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>


#define TESTING_NUMBER (17) /* inteiro usado para testar funções */
#define MIN_ARRAY_SIZE (1) /* tamanho mínimo para um array */


/* Funções da biblioteca randomize.h */
void test_random_integer(void); /* testa a função random_integer */
void test_sort_a_number(void); /* testa a função sort_a_number */

/* Funções da biblioteca trees.h */
void test_create_empty_binary_tree(void); /* testa a função create_empty_bin... */
void test_height_of_binary_tree(void); /* testa a função height_of_binary_tree */
void test_is_avl(void); /* testa a função is_avl */
void test_rotate_left(void); /* testa a função rotate_left */
void test_rotate_right(void); /* testa a função rotate_right */
void test_balance_factor_of_tree(void); /* testa a função balance_factor_of_... */
void test_insert_on_binary_tree(void); /* testa a função insert_on_binary_tree */
void test_create_binary_tree(void); /* testa a função create_binary_tree */
void test_is_empty_binary_tree(void); /* testa a função is_empty_binary_tree */
void test_balance_binary_tree(void); /* testa a função balance_binary_tree */
void test_search_on_binary_tree(void); /* testa a função search_on_binary_tree */



/* Para cada função testada o prograva deve exibir o nome da função e OK se
 * ela passar no teste ou FAIL caso o resultado não seja o esperado.
 * PARA TESTAR AS FUNÇÕES DE MANIPULAÇÃO DE AGUMENTOS É NECESSÁRIO INICIAR
 * COM OS PARÂMETROS -n17 -s 17 -tuj17v p17
 */
int main(void) {
	
	CU_pSuite avb_suite = NULL;

	if (CU_initialize_registry() != CUE_SUCCESS){
		fprintf(stderr, "Não foi possível inicializar o CUnit.\n");
		return (CU_get_error());
	}

	avb_suite = CU_add_suite("AVL vs BST suite", NULL, NULL);
	if (avb_suite == NULL) {
		CU_cleanup_registry();
		fprintf(stderr, "Não foi possível adicionar uma suite de testes ao ");
		fprintf(stderr, "CUnit.\n");
		return (CU_get_error());
	}

	if ((CU_add_test(avb_suite, "Test of random_integer()", test_random_integer) == NULL)
		|| (CU_add_test(avb_suite, "Test of sort_a_number()", test_sort_a_number) == NULL)
		|| (CU_add_test(avb_suite, "Test of create_empty_binary_tree()", test_create_empty_binary_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of height_of_binary_tree()", test_height_of_binary_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of is_avl()", test_is_avl) == NULL)
		|| (CU_add_test(avb_suite, "Test of rotate_left()", test_rotate_left) == NULL)
		|| (CU_add_test(avb_suite, "Test of rotate_right()", test_rotate_right) == NULL)
		|| (CU_add_test(avb_suite, "Test of balance_factor_of_tree()", test_balance_factor_of_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of insert_on_binary_tree()", test_insert_on_binary_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of create_binary_tree()", test_create_binary_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of is_empty_binary_tree()", test_is_empty_binary_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of balance_binary_tree()", test_balance_binary_tree) == NULL)
		|| (CU_add_test(avb_suite, "Test of search_on_binary_tree()", test_search_on_binary_tree) == NULL))
	{
		CU_cleanup_registry();
		fprintf(stderr, "Não foi possível adicionar um teste à suite avb_suite.\n");
		return (CU_get_error());
	}

	CU_console_run_tests();
	CU_cleanup_registry();
	return (CU_get_error());
}


/* testa a função random_integer usando CUnit */
void test_random_integer(void) {
    /* se o número máximo e mínimo forem iguais, deve haver garantia de que o
     * número retornado seja igual aos outros dois */
    CU_ASSERT(random_integer(TESTING_NUMBER, TESTING_NUMBER) == TESTING_NUMBER);
}


/* testa a função sort_a_number esteja funcionando corretamente 
 * e FALSE caso contrário. */
void test_sort_a_number(void) {
    int array[MIN_ARRAY_SIZE];
    array[ZERO] = TESTING_NUMBER;
    /* se o array tem apenas uma posição, o número sorteado deve ser o único
     * número que o array contém */
    CU_ASSERT(sort_a_number(array, MIN_ARRAY_SIZE) == TESTING_NUMBER);
}

/* testa a função create_empty_binary_tree usando CUnit */
void test_create_empty_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    CU_ASSERT(binary_tree == NULL); /* binary_tree *deve* ser NULL */
}


/* testa a função height_of_binary_tree esteja usando CUnit */
void test_height_of_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* se não há nenhum nó de árvore, ERROR *deve* ser retornado */
    CU_ASSERT(height_of_binary_tree(binary_tree) == ERROR);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    /* a árvore possui apenas um nó, então a altura deve ser ZERO */
    CU_ASSERT(height_of_binary_tree(binary_tree) == ZERO);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* com dois elementos, a arvore *deve* ter altura 1 */  
    CU_ASSERT(height_of_binary_tree(binary_tree) == 1);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* se há dois elementos enfileirados, a altura é 2 */
    CU_ASSERT(height_of_binary_tree(binary_tree) == 2);

}


/* testa a função is_avl usando CUnit */
void test_is_avl(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* se a arvore está vazia, a função retornará ERROR */
    CU_ASSERT(is_avl(binary_tree) == ERROR);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* com apenas um nó, a árvore é uma AVL */
    CU_ASSERT(is_avl(binary_tree) == TRUE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* com dois nós, a árvore é uma AVL */
    CU_ASSERT(is_avl(binary_tree) == TRUE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* com dois nós enfileirados, uma árvore não é uma AVL */
    CU_ASSERT(is_avl(binary_tree) == FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    /* dois elementos à esquerda e um à direita: a árvore é uma AVL */
    CU_ASSERT(is_avl(binary_tree) == TRUE);

}


/* testa a função rotate_left usando CUnit */
void test_rotate_left(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));

    binary_tree = rotate_left(binary_tree);
    /* rotacionando uma árvore com dois nós enfileirados à direita deve trans-
     * formá-la em uma AVL */
    CU_ASSERT(is_avl(binary_tree));
}


/* testa a função rotate_right usando CUnit */
void test_rotate_right(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    binary_tree = rotate_right(binary_tree);

    /* rotacionando uma árvore com dois nós enfileirados à esquerda deve
     * transformá-la em uma AVL */
    CU_ASSERT(is_avl(binary_tree));

}


/* testa a função balance_factor_of_tree usando CUnit */
void test_balance_factor_of_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* se não há nós, o fator de balanceamento é ZERO */
    CU_ASSERT(balance_factor_of_tree(binary_tree) == ZERO);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* com apenas um nó, o fator de balanceamento é ZERO */ 
    CU_ASSERT(balance_factor_of_tree(binary_tree) == ZERO);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    /* um nó à direita e nenhum à esquerda, o fator de balanceamento é -1 */
    CU_ASSERT(balance_factor_of_tree(binary_tree) == (-1));

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    /* dois nós enfileirados à direira e nenhum à esquerda, o fator de balan-
     * ceamento é -2 */
    CU_ASSERT(balance_factor_of_tree(binary_tree) == (-2));

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* dois nós enfileirados à esquerda e dois enfileirados à direita, o fator
     * de balanceamento é ZERO */
    CU_ASSERT(balance_factor_of_tree(binary_tree) == ZERO);

    free (binary_tree);
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* com um nó à esquerda e nenhum à direita, o fator de balanceamento é 1*/
    CU_ASSERT(balance_factor_of_tree(binary_tree) == 1);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* com dois nós enfileirados à esquerda e nenhum à direita, o fator de ba-
     * lanceamento é 2 */
    CU_ASSERT(balance_factor_of_tree(binary_tree) == 2);


}


/* testa a função balance_factor_of_tree esteja usando CUnit */
void test_insert_on_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();
    
    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* um nó foi inserido, a árvore não deve estar vazia */
    CU_ASSERT(is_empty_binary_tree(binary_tree) == FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* o nó inserido deve ser encontrado e o número de buscas para encontrá-lo
     * deve coincidir com a realidade */
    CU_ASSERT(search_on_binary_tree(binary_tree, (TESTING_NUMBER - 2)) == 2);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* o nó inserido deve ser encontrado e o número de buscas para encontrá-lo
     * deve coincidir com a realidade */
    CU_ASSERT(search_on_binary_tree(binary_tree, (TESTING_NUMBER - 1)) == 3);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    /* o nó inserido deve ser encontrado e o número de buscas para encontrá-lo
     * deve coincidir com a realidade */
    CU_ASSERT(search_on_binary_tree(binary_tree, (TESTING_NUMBER + 1)) == 2);
    /* o tamanho da árvore deve coincidir com a realidade */
    CU_ASSERT(height_of_binary_tree(binary_tree) == 2);

    /* mesmo depois de várias insersões, o valor do nó raiz deve permanecer o
     * mesmo */
    CU_ASSERT(binary_tree->value == TESTING_NUMBER);


}


/* testa a função create_binary_tree usando CUnit */
void test_create_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);

    /* a árvore não pode estar vazia, pois um nó foi criado */
    CU_ASSERT(is_empty_binary_tree(binary_tree) == FALSE);

    /* se há apenas um nó, o tamanho da árvore *deve* ser ZERO */
    CU_ASSERT(height_of_binary_tree(binary_tree) == ZERO);

    /* o número passado como argumento na função deve pertencer à arvore */
    CU_ASSERT(search_on_binary_tree(binary_tree, TESTING_NUMBER) == 1);


}


/* testa a função is_empty_binary_tree usando CUnit */
void test_is_empty_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* a árvore *deve* estar vazia, pois nenhum nó foi inserido */
    CU_ASSERT(is_empty_binary_tree(binary_tree) == TRUE);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* com um nó, a árvore não está vazia */
    CU_ASSERT(is_empty_binary_tree(binary_tree) == FALSE);

}


/* testa a função balance_binary_tree usando CUnit */
void test_balance_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));

    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema right-left e depois a árvore
     * foi balanceada */
    CU_ASSERT(is_avl(binary_tree) == TRUE);
    free(binary_tree);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    
    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema left-right e depois a árvore
     * foi balanceada */
    CU_ASSERT(is_avl(binary_tree) == TRUE);
    free(binary_tree);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    
    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema right-right e depois a árvore
     * foi balanceada */
    CU_ASSERT(is_avl(binary_tree) == TRUE);
    free(binary_tree);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    
    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema left-left e depois a árvore
     * foi balanceada */
    CU_ASSERT(is_avl(binary_tree) == TRUE);

}


/* testa a função search_on_binary_tree usando CUnit */
void test_search_on_binary_tree(void) {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* ao buscar um número em uma árvore vazia, o resultado deve ser ZERO */
    CU_ASSERT(search_on_binary_tree(binary_tree, TESTING_NUMBER) == ZERO);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* se houver apenas um nó na árvore, o resultado ao buscar seu valor deve
     * ser 1 */
    CU_ASSERT(search_on_binary_tree(binary_tree, TESTING_NUMBER) == 1);

    /* adicionar alguns números na árvore */
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    
    /* buscar um nó no segundo nível da árvore requer três comparações */
    CU_ASSERT(search_on_binary_tree(binary_tree, (TESTING_NUMBER - 1)) == 3);
    
    /* buscar um nó no primeiro nível da árvore requer duas comparações */
    CU_ASSERT(search_on_binary_tree(binary_tree, (TESTING_NUMBER + 2)) == 2);
    
    /* ao buscar um número que não existe na árvore o resultado deve ser
     * a altura da árvore */    
    CU_ASSERT(search_on_binary_tree(binary_tree, (ZERO))
        == height_of_binary_tree(binary_tree))
    
}