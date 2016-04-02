/* Estruturas e funções de manipulação de árvores de busca binária e AVL */


#include <stdlib.h> /* malloc */
#inlcude "global.h" /* constantes e funções globais do projeto */


/* estrutura de uma árvore binária em que cada nó guarda um inteiro */
typedef struct binary_tree_t__ {
	int value; /* valor inteiro do nó */
	struct binary_tree_t__ *left; /* filho à esquerda do nó */
	struct binary_tree_t__ *right; /* filho à esquerda do nó */
} binary_tree_t;


/* retorna um ponteiro do tipo árvore binária para NULL, apenas */
binary_tree_t *create_empty_binary_tree();

/* retorna a altura de uma árvore ou sub-arvore, até a folha mais distante */
int height_of_binary_tree(binary_tree_t *);

/* retorna TRUE se a arvore recebida for uma AVL e FALSE caso contrário */
int is_avl(binary_tree_t *);

/* rotaciona uma sub-árvore para a esquerda e retorna a nova sub-árvore */
binary_tree_t *rotate_left(binary_tree_t *);

/* rotaciona uma sub-árvore para a direita e retorna a nova sub-árvore */
binary_tree_t *rotate_right(binary_tree_t *);

/* retorna o fator de balanceamento de um nó recebido */
int balance_factor_of_tree(binary_tree_t *);

/* insere o inteiro recebido em um nó de árvore recebido e retorna o nó */
binary_tree_t *insert_on_binary_tree(binary_tree_t *, int);

/* retorna um nó de árvore com o inteiro recebido e que não tem filhos */
binary_tree_t *create_binary_tree(int);

void print_tree(binary_tree_t *);

/* retorna TRUE se o nó recebido estiver vazio ou FALSE caso contrário */
int is_empty_binary_tree(binary_tree_t *);

/* retorna a árvore binária recebida balanceada de forma a ser uma AVL */
binary_tree_t *balance_binary_tree(binary_tree_t *);


/* retorna um ponteiro do tipo árvore binária para NULL, apenas */
binary_tree_t *create_empty_binary_tree(){
	return (NULL);
}

/* retorna a altura da árvore/sub-árvore recebida até a folha mais distante */
int height_of_binary_tree(binary_tree_t *binary_tree) {

	int left_height; /* receberá a altura do nó à direita */
	int right_height; /* receberá a altura do nó à esquerda */

	if (is_empty_binary_tree(binary_tree)) {
		return -1; /* se o nó está vazio retorna -1 */
	}
	
	/* atribui a altura dos filhos do nó às variáveis locais */
	left_height = height_of_binary_tree(binary_tree->left);
	right_height = height_of_binary_tree(binary_tree->right);
	
	/* retorna a maior altura dentre as duas recebidas */
	if (left_height > right_height) {
		return (left_height + 1);
	}
	
	return (right_height + 1);

}


/* retorna TRUE se a arvore recebida for uma AVL e FALSE caso contrário */
int is_avl(binary_tree_t *binary_tree) {

	/* recebe o fator de balanceamento do nó recebido */
	int balance_factor = balance_factor_of_tree(binary_tree);

	/* assume que os nós filhos avls, para caso não haja filhos */
	int right_is_avl = 1;
	int left_is_avl = 1;

	/* se houver filhos, verifica se estão balanceados e guarda a resposta */
	if (!is_empty_binary_tree(binary_tree->left)) {
		left_is_avl = is_avl(binary_tree->left);
	}
	if (!is_empty_binary_tree(binary_tree->right)) {
		right_is_avl = is_avl(binary_tree->right);
	}

	/* se os dois filhos do nó estiverem balanceados, retorna se o proprio nó
	 * está balanceado ou não */
	if (right_is_avl&&left_is_avl) {
		return ((-2 < balance_factor) && (balance_factor < 2));
	}
   
	return (FALSE); /* algum dos nós filhos não está balanceado */
}

/* rotaciona uma sub-árvore para a esquerda e retorna a nova sub-árvore */
binary_tree_t *rotate_left(binary_tree_t *binary_tree) {

	/* cria um novo nó auxiliar */
	binary_tree_t *new_binary_tree;
	new_binary_tree = create_empty_binary_tree();

	/* realiza a troca de ponteiros usando o nó auxiliar */
	if (!is_empty_binary_tree(binary_tree)
		&& !is_empty_binary_tree(binary_tree->right)) {
		
		new_binary_tree = binary_tree->right;
		binary_tree->right = new_binary_tree->left;
		new_binary_tree->left = binary_tree;
	}

	return (new_binary_tree); /* retorna o nó auxiliar */

}

/* rotaciona uma sub-árvore para a direita e retorna a nova sub-árvore */
binary_tree_t *rotate_right(binary_tree_t *binary_tree) {

	/* cria um novo nó auxiliar */
	binary_tree_t *new_binary_tree;
	new_binary_tree = create_empty_binary_tree();

	/* realiza a troca de ponteiros usando o nó auxiliar */
	if (!is_empty_binary_tree(binary_tree)
		&& !is_empty_binary_tree(binary_tree->left)) {

		new_binary_tree = binary_tree->left;
		binary_tree->left = new_binary_tree->right;
		new_binary_tree->right = binary_tree;

	}

	return (new_binary_tree); /* retorna o nó auxiliar */

}

/* retorna o fator de balanceamento de um nó recebido */
int balance_factor_of_tree(binary_tree_t *binary_tree) {

	/* se o nó não estiver vazio, retorna a altura do filho à esquerda
	 * menos a altura do filho à direita */
	if (!is_empty_binary_tree(binary_tree)) {
		return (height_of_binary_tree(binary_tree->left)
				- height_of_binary_tree(binary_tree->right));
	}

	return (ZERO); /* retorna ZERO se o nó estiver vazio */
}

/* insere o inteiro recebido em um nó de árvore recebido e retorna o nó */
binary_tree_t *insert_on_binary_tree(binary_tree_t *binary_tree, int value) {

	/* se o nó recebido estiver vazio, cria um novo nó com o valor recebido */
	if (is_empty_binary_tree(binary_tree)) {
		binary_tree = create_binary_tree(value);
	/* se não e o valor foi maior que o do nó, insere à direita do nó */
	} else if (binary_tree->value > value) {
		binary_tree->left = insert_on_binary_tree(binary_tree->left, value);
	/* se não e o valor foi menor que o do nó, insere à esquerda do nó */
	} else {
		binary_tree->right = insert_on_binary_tree(binary_tree->right, value);
	}

	return binary_tree; /* retorna o nó */
}

/* retorna um nó de árvore com o inteiro recebido e que não tem filhos */
binary_tree_t *create_binary_tree(int value) {

	/* aloca memória para um novo nó */
	binary_tree_t *binary_tree;
	binary_tree = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	/* insere o valor recebido no nó e torna os dois filhos vazios */
	binary_tree->value = value;
	binary_tree->left = create_empty_binary_tree();
	binary_tree->right = create_empty_binary_tree();

	return binary_tree; /* retorna o novo nó */

}

/* retorna TRUE se o nó recebido estiver vazio ou FALSE caso contrário */
int is_empty_binary_tree(binary_tree_t *binary_tree) {
	return (binary_tree == NULL); /* retorna se o nó aponta para NULL ou não*/
}

/* retorna a árvore binária recebida balanceada de forma a ser uma AVL */
binary_tree_t *balance_binary_tree(binary_tree_t *avl) {
	
	/* se houver um filho à esquerda e ele não for uma AVL, balanceie-o */
	if (!is_empty_binary_tree(avl->left) && !is_avl(avl->left)) {
		avl->left = balance_binary_tree(avl->left);
	}

	/* se houver um filho à direita e ele não for uma AVL, balanceie-o */
	if (!is_avl(avl) && !is_empty_binary_tree(avl->right)
		&& !is_avl(avl->right)) {

		avl->right = balance_binary_tree(avl->right);
	}

	/* se não for uma AVL, balanceie de acordo com o fator de balanceamento */
	if (!is_avl(avl)){
		/* se o fator de balanceamento for maior que 1, há mais nós à
		 * esquerda */
		if (balance_factor_of_tree(avl)>1){ /* left */
			/* se o fator de balanceamento do filho à esquerda for menor que 
			 * 0, é preciso rotacionar para a esquerda primeiro */
			if (balance_factor_of_tree(avl->left) < 0) { /* left-right */
				avl->left = rotate_left(avl->left);
			}
			
			/* left-left */
			avl = rotate_right(avl); /* rotacionar para a direita */
		}

		/* se o fator de balanceamento for menor que 1, há mais nós à
		 * direita */
		else if (balance_factor_of_tree(avl)<1){ /* right */
			/* se o fator de balanceamento do filho à esquerda for maior que
			 * 0, é preciso rotacionar para a esquerda primeiro */
			if (balance_factor_of_tree(avl->right) > 0) { /* right-left */
				avl->right = rotate_right(avl->right);
			}

			/* right-right */
			avl = rotate_left(avl); /* rotacionar para a direita */
		}
	}

	return avl; /* retornar a árvore balanceada */
}

/* busca um número em uma árvore binária e retorna a quantidade de comparações
 * realizadas para encontrar esse número */
int search_on_binary_tree(binary_tree_t *binary_tree, int value){
	if (is_empty_binary_tree(binary_tree))
		return (1);
	if (binary_tree->value == value)
		return (1);
	return (search_on_binary_tree(binary_tree->left, value)+
		search_on_binary_tree(binary_tree->right, value));
}