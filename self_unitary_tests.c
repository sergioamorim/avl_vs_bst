/* Este programa realiza testes unitários nas funções do projeto avl_vs_bst 
 * PARA TESTAR AS FUNÇÕES DE MANIPULAÇÃO DE ARGUMENTOS, É NECESSÁRIO INICIAR
 * COM OS PARÂMETROS -n17 -s 17 -tuj17v p17 */


#include <stdio.h>
#include "randomize.h" /* biblioteca de funções de randomização */
#include "arguments.h" /* biblioteca de funções de manipulação de argumentos*/
#include "trees.h" /* biblioteca com estrutura e funções de BST e AVL */
#include "global.h" /* definição de constantes globais para o projeto */


#define TESTING_NUMBER (17) /* inteiro usado para testar funções */
#define MIN_ARRAY_SIZE (1) /* tamanho mínimo para um array */


/* Funções da biblioteca randomize.h */
bool test_random_integer(); /* testa a função random_integer */
bool test_sort_a_number(); /* testa a função sort_a_number */


/* Funções da biblioteca arguments.h */
bool test_argument_is_set(int args_count, char *args[]);
bool test_get_argument_value(int args_count, char *args[]);


/* Funções da biblioteca trees.h */
bool test_create_empty_binary_tree(); /* testa a função create_empty_bin... */
bool test_height_of_binary_tree(); /* testa a função height_of_binary_tree */
bool test_is_avl(); /* testa a função is_avl */
bool test_rotate_left(); /* testa a função rotate_left */
bool test_rotate_right(); /* testa a função rotate_right */
bool test_balance_factor_of_tree(); /* testa a função balance_factor_of_... */
bool test_insert_on_binary_tree(); /* testa a função insert_on_binary_tree */
bool test_create_binary_tree(); /* testa a função create_binary_tree */
bool test_is_empty_binary_tree(); /* testa a função is_empty_binary_tree */
bool test_balance_binary_tree(); /* testa a função balance_binary_tree */
bool test_search_on_binary_tree(); /* testa a função search_on_binary_tree */


/* Para cada função testada o prograva deve exibir o nome da função e OK se
 * ela passar no teste ou FAIL caso o resultado não seja o esperado.
 * PARA TESTAR AS FUNÇÕES DE MANIPULAÇÃO DE AGUMENTOS É NECESSÁRIO INICIAR
 * COM OS PARÂMETROS -n17 -s 17 -tuj17v p17
 */
void main (int args_count, char *args[]) {
    
    /* imprimir OK se a função random_integer estiver funcionando */
    printf("random_integer function\t\t");
    if (test_random_integer() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

    /* imprimir OK se a função sort_a_number estiver funcionando */
    printf("sort_a_number function\t\t");
    if (test_sort_a_number() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

    /* imprimir OK se a função argument_is_set estiver funcionando */
    printf("argument_is_set function\t");
    if (test_argument_is_set(args_count, args) != FALSE)
        printf("OK\n");
    else
        printf("FAIL if initialized with -n17 -s 17 -tuj17v p17\n");

    /* imprimir OK se a função get_argument_value estiver funcionando */
    printf("get_argument_value function\t");
    if (test_get_argument_value(args_count, args) != FALSE)
        printf("OK\n");
    else
        printf("FAIL if initialized with -n17 -s 17 -tuj17v p17\n");

    /* imprimir OK se a função create_empty_binary_tree estiver funcionando */
    printf("create_empty_binary_tree\t");
    if (test_create_empty_binary_tree() != FALSE)
        printf("OK\n");
    else
        printf("FAIL\n");

    /* imprimir OK se a função height_of_binary_tree estiver funcionando */
    printf("height_of_binary_tree\t\t");
    if (test_height_of_binary_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_binary_tree,\n\t\t\t\t\tinsert_");
        printf("on_binary_tree\n");
    }

    /* imprimir OK se a função is_avl estiver funcionando */
    printf("is_avl\t\t\t\t");
    if (test_is_avl() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_empty_binary_tree,\n\t\t\t\t\ti");
        printf("nsert_on_binary_tree\n");
    }

    /* imprimir OK se a função rotate_left estiver funcionando */
    printf("rotate_left\t\t\t");
    if (test_rotate_left() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_binary_tree,\n\t\t\t\t\tinsert_");
        printf("on_binary_tree, is_avl\n");
    }

    /* imprimir OK se a função rotate_right estiver funcionando */
    printf("rotate_right\t\t\t");
    if (test_rotate_right() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_binary_tree,\n\t\t\t\t\tinsert");
        printf("_on_binary_tree, is_avl\n");
    }

    /* imprimir OK se a função balance_factor_of_tree estiver funcionando */
    printf("balance_factor_of_tree\t\t");
    if (test_balance_factor_of_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_binary_tree,\n\t\t\t\t\tinsert");
        printf("_on_binary_tree\n");
    }

    /* imprimir OK se a função insert_on_binary_tree estiver funcionando */
    printf("insert_on_binary_tree\t\t");
    if (test_insert_on_binary_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_binary_tree,\n\t\t\t\t\tinsert");
        printf("_on_binary_tree\n");
    }

    /* imprimir OK se a função create_binary_tree estiver funcionando */
    printf("create_binary_tree\t\t");
    if (test_create_binary_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: is_empty_binary_tree,\n\t\t\t\t\theig");
        printf("ht_of_binary_tree, search_on_binary_tree\n");
    }

    /* imprimir OK se a função is_empty_binary_tree estiver funcionando */
    printf("is_empty_binary_tree\t\t");
    if (test_is_empty_binary_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_empty_binary_tree,\n\t\t\t\t\t");
        printf("insert_on_binary_tree\n");
    }

    /* imprimir OK se a função balance_binary_tree estiver funcionando */
    printf("balance_binary_tree\t\t");
    if (test_balance_binary_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_empty_binary_tree,\n\t\t\t\t\t");
        printf("insert_on_binary_tree, is_avl\n");
    }

    /* imprimir OK se a função search_on_binary_tree estiver funcionando */
    printf("search_on_binary_tree\t\t");
    if (test_search_on_binary_tree() != FALSE)
        printf("OK\n");
    else {
        printf("FAIL - dependencies: create_empty_binary_tree,\n\t\t\t\t\t");
        printf("insert_on_binary_tree, height_of_binary_tree\n");
    }

}


/* Retorna TRUE caso a função random_integer esteja funcionando corretamente
 * e FALSE caso contrário */
bool test_random_integer(){
    /* se o número máximo e mínimo forem iguais, deve haver garantia de que o
     * número retornado seja igual aos outros dois */
    return (random_integer(TESTING_NUMBER, TESTING_NUMBER) == TESTING_NUMBER);
}


/* Retorna TRUE caso a função sort_a_number esteja funcionando corretamente 
 * e FALSE caso contrário. */
bool test_sort_a_number(){
    int array[MIN_ARRAY_SIZE];
    array[ZERO] = TESTING_NUMBER;
    /* se o array tem apenas uma posição, o número sorteado deve ser o único
     * número que o array contém */
    return (sort_a_number(array, MIN_ARRAY_SIZE) == TESTING_NUMBER);
}


/* Se os resultados da função argument_is_set estiverem corretos para os
 * testes aplicados, retorna TRUE; se não, retorna FALSE
 * PARA TESTAR É NECESSÁRIO INICIAR COM OS PARÂMETROS -n17 -s 17 -tuj17v p17*/
bool test_argument_is_set(int args_count, char *args[]) {

    /* testar se a função está funcionando para os argumentos fictícios;
     * retornar FALSE caso não esteja */
    if (argument_is_set(args_count, args, 'n') != 1)
        return (FALSE);
    if (argument_is_set(args_count, args, 's') != 2)
        return (FALSE);
    if (argument_is_set(args_count, args, 'o') != FALSE)
        return (FALSE);
    if (argument_is_set(args_count, args, 'u') != 4)
        return (FALSE);
    if (argument_is_set(args_count, args, 'a') != FALSE)
        return (FALSE);

    return (TRUE); /* função funciona corretamente, para os testes aplicados */
}


/* Se os resultados da função get_argument_value estiverem corretos para os
 * testes aplicados, retorna TRUE; se não, retorna FALSE 
 * PARA TESTAR É NECESSÁRIO INICIAR COM OS PARÂMETROS -n17 -s 17 -tuj17v p17*/
bool test_get_argument_value(int args_count, char *args[]) {

    /* testar se a função está funcionando para os argumentos fictícios;
     * retornar FALSE caso não esteja */
    if (get_argument_value(args_count, args, 'n') != TESTING_NUMBER)
        return (FALSE);
    if (get_argument_value(args_count, args, 's') != TESTING_NUMBER)
        return (FALSE);
    if (get_argument_value(args_count, args, 'o') != ERROR)
        return (FALSE);
    if (get_argument_value(args_count, args, 'u') != ERROR)
        return (FALSE);
    if (get_argument_value(args_count, args, 'j') != TESTING_NUMBER)
        return (FALSE);
    if (get_argument_value(args_count, args, 'p') != ERROR)
        return (FALSE); 

    return (TRUE); /* função funciona corretamente, para os testes aplicados */
}



/* retorna TRUE caso a função create_empty_binary_tree esteja funcionando cor-
 * retamente e FALSE caso contrário */
bool test_create_empty_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    return (binary_tree == NULL); /* binary_tree *deve* ser NULL */
}


/* retorna TRUE caso a função height_of_binary_tree esteja funcionando corre-
 * tamente e FALSE caso contrário */
bool test_height_of_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* se não há nenhum nó de árvore, ERROR *deve* ser retornado */
    if (height_of_binary_tree(binary_tree) != ERROR)
        return (FALSE);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    /* a árvore possui apenas um nó, então a altura deve ser ZERO */
    if (height_of_binary_tree(binary_tree) != ZERO)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* com dois elementos, a arvore *deve* ter altura 1 */  
    if (height_of_binary_tree(binary_tree) != 1)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* se há dois elementos enfileirados, a altura é 2 */
    if (height_of_binary_tree(binary_tree) != 2)
        return (FALSE);

    return (TRUE); /* função funciona corretamente, para os testes aplicados */
}


/* retorna TRUE caso a função is_avl esteja funcionando corretamente e FALSE
 * caso contrário */
bool test_is_avl() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* se a arvore está vazia, a função retornará ERROR */
    if (is_avl(binary_tree) != ERROR)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* com apenas um nó, a árvore é uma AVL */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* com dois nós, a árvore é uma AVL */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* com dois nós enfileirados, uma árvore não é uma AVL */
    if (is_avl(binary_tree) != FALSE)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    /* dois elementos à esquerda e um à direita: a árvore é uma AVL */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);

    return (TRUE); /* função funciona corretamente, para os testes aplicados */
}


/* retorna TRUE caso a função rotate_left esteja funcionando corretamente e
 * FALSE caso contrário */
bool test_rotate_left() {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));

    binary_tree = rotate_left(binary_tree);
    /* rotacionando uma árvore com dois nós enfileirados à direita deve trans-
     * formá-la em uma AVL */
    return (is_avl(binary_tree));
}


/* retorna TRUE caso a função rotate_right esteja funcionando corretamente e
 * FALSE caso contrário */
bool test_rotate_right() {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    binary_tree = rotate_right(binary_tree);

    /* rotacionando uma árvore com dois nós enfileirados à esquerda deve
     * transformá-la em uma AVL */
    return (is_avl(binary_tree));

}


/* retorna TRUE caso a função  esteja funcionando corretamente e FALSE caso
 * contrário */
bool test_balance_factor_of_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* se não há nós, o fator de balanceamento é ZERO */
    if (balance_factor_of_tree(binary_tree) != ZERO)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* com apenas um nó, o fator de balanceamento é ZERO */ 
    if (balance_factor_of_tree(binary_tree) != ZERO)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    /* um nó à direita e nenhum à esquerda, o fator de balanceamento é -1 */
    if (balance_factor_of_tree(binary_tree) != (-1))
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    /* dois nós enfileirados à direira e nenhum à esquerda, o fator de balan-
     * ceamento é -2 */
    if (balance_factor_of_tree(binary_tree) != (-2))
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* dois nós enfileirados à esquerda e dois enfileirados à direita, o fator
     * de balanceamento é ZERO */
    if (balance_factor_of_tree(binary_tree) != ZERO)
        return (FALSE);

    free (binary_tree);
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* com um nó à esquerda e nenhum à direita, o fator de balanceamento é 1*/
    if (balance_factor_of_tree(binary_tree) != 1)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* com dois nós enfileirados à esquerda e nenhum à direita, o fator de ba-
     * lanceamento é 2 */
    if (balance_factor_of_tree(binary_tree) != 2)
        return (FALSE);

    return (TRUE); /* nenhum dos testes falhou, a função funciona */
}


/* retorna TRUE caso a função balance_factor_of_tree esteja funcionando corre-
 * tamente e FALSE caso contrário */
bool test_insert_on_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();
    
    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* um nó foi inserido, a árvore não deve estar vazia */
    if (is_empty_binary_tree(binary_tree) != FALSE)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    /* o nó inserido deve ser encontrado e o número de buscas para encontrá-lo
     * deve coincidir com a realidade */
    if (search_on_binary_tree(binary_tree, (TESTING_NUMBER - 2)) != 2)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    /* o nó inserido deve ser encontrado e o número de buscas para encontrá-lo
     * deve coincidir com a realidade */
    if (search_on_binary_tree(binary_tree, (TESTING_NUMBER - 1)) != 3)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    /* o nó inserido deve ser encontrado e o número de buscas para encontrá-lo
     * deve coincidir com a realidade */
    if (search_on_binary_tree(binary_tree, (TESTING_NUMBER + 1)) != 2)
        return (FALSE);
    /* o tamanho da árvore deve coincidir com a realidade */
    if (height_of_binary_tree(binary_tree) != 2)
        return (FALSE);

    /* mesmo depois de várias insersões, o valor do nó raiz deve permanecer o
     * mesmo */
    if (binary_tree->value != TESTING_NUMBER)
        return (FALSE);

    return (TRUE); /* nenhum dos testes falhou, a função funciona */
}


/* retorna TRUE caso a função create_binary_tree esteja funcionando correta-
 * mente e FALSE caso contrário */
bool test_create_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);

    /* a árvore não pode estar vazia, pois um nó foi criado */
    if (is_empty_binary_tree(binary_tree) != FALSE)
        return (FALSE);

    /* se há apenas um nó, o tamanho da árvore *deve* ser ZERO */
    if (height_of_binary_tree(binary_tree) != ZERO)
        return (FALSE);

    /* o número passado como argumento na função deve pertencer à arvore */
    if (search_on_binary_tree(binary_tree, TESTING_NUMBER) != 1)
        return (FALSE);

    return (TRUE); /* nenhum dos testes falhou, a função funciona */
}


/* retorna TRUE caso a função is_empty_binary_tree esteja funcionando correta-
 * mente e FALSE caso contrário */
bool test_is_empty_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* a árvore *deve* estar vazia, pois nenhum nó foi inserido */
    if (is_empty_binary_tree(binary_tree) != TRUE)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* com um nó, a árvore não está vazia */
    if (is_empty_binary_tree(binary_tree) != FALSE)
        return (FALSE);

    return (TRUE); /* nenhum teste falhou, a função funciona */
}


/* retorna TRUE caso a função balance_binary_tree esteja funcionando correta-
 * mente e FALSE caso contrário */
bool test_balance_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));

    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema right-left e depois a árvore
     * foi balanceada */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);
    free(binary_tree);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    
    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema left-right e depois a árvore
     * foi balanceada */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);
    free(binary_tree);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    
    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema right-right e depois a árvore
     * foi balanceada */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);
    free(binary_tree);

    binary_tree = create_binary_tree(TESTING_NUMBER);
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    
    binary_tree = balance_binary_tree(binary_tree);
    /* dois nós inseridos à esquerda no esquema left-left e depois a árvore
     * foi balanceada */
    if (is_avl(binary_tree) != TRUE)
        return (FALSE);

    return (TRUE); /* nenhum teste falhou, a função funciona */
}


/* retorna TRUE caso a função search_on_binary_tree esteja funcionando correta-
 * mente e FALSE caso contrário */
bool test_search_on_binary_tree() {
    binary_tree_t *binary_tree;
    binary_tree = create_empty_binary_tree();

    /* ao buscar um número em uma árvore vazia, o resultado deve ser ZERO */
    if (search_on_binary_tree(binary_tree, TESTING_NUMBER) != ZERO)
        return (FALSE);

    binary_tree = insert_on_binary_tree(binary_tree, TESTING_NUMBER);
    /* se houver apenas um nó na árvore, o resultado ao buscar seu valor deve
     * ser 1 */
    if (search_on_binary_tree(binary_tree, TESTING_NUMBER) != 1)
        return (FALSE);

    /* adicionar alguns números na árvore */
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER - 1));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 2));
    binary_tree = insert_on_binary_tree(binary_tree, (TESTING_NUMBER + 1));
    
    /* buscar um nó no segundo nível da árvore requer três comparações */
    if (search_on_binary_tree(binary_tree, (TESTING_NUMBER - 1)) != 3)
        return (FALSE);
    
    /* buscar um nó no primeiro nível da árvore requer duas comparações */
    if (search_on_binary_tree(binary_tree, (TESTING_NUMBER + 2)) != 2)
        return (FALSE);
    
    /* ao buscar um número que não existe na árvore o resultado deve ser
     * a altura da árvore */    
    if (search_on_binary_tree(binary_tree, (ZERO))
        != height_of_binary_tree(binary_tree))
            return (FALSE);
    
    return (TRUE); /* nenhum dos testes falhou, a função funciona */
}