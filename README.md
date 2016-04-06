#AVL vs BST
Comparação de eficiência entre AVL e Árvores de Busca Binária

Este programa faz parte de um projeto de Estrutura de Dados do período 2015.2 no IC (Instituto de Computação) da UFAL (Universidade Federal de Alagoas), Campus A.C. Simões;

Professor responsável: Márcio Ribeiro [http://ic.ufal.br/marcio]

Membros da equipe:
+ Bharbara Correia Costa Coutinho Pereira <bharbara.costa@hotmail.com>
+ Sergio Augusto Teixeira Amorim <sata@ic.ufal.br>

Trello do projeto: https://trello.com/b/ABXiNDng


Este programa inclui números aleatórios em duas estruturas de dados: uma AVL e uma árvore de busca binária. Depois, sorteia dentre os números incluídos, números a serem buscados em ambas as estruturas. Para cada busca, a quantidade de comparações necessárias para encontrar o número é contado e servirá para plotar um gráfico que relaciona a quantidade de comparações necessárias com a quantidade de números buscados. Pode-se forçar a inclusão e busca de números em ordem usando o argumento **_-o_**.



####Instruções de uso:
1. Compilar o arquivo main.c;
2. Rodar com o argumento **_-h_** para obter instruções;
3. Não usar o número -1 como valor de nenhum argumento do programa;
4. O arquivo `self_unitary_tests.c` possui testes unitários para as funções mais importantes do programa - caso modifique alguma dessas funções, compile esse algoritmo e execute-o para certificar-se do correto funcionamento dessas funções; Os argumentos `-n17 -s 17 -tuj17v p17` devem ser usados para testar as funções de recebimento de parâmetros;
5. Para facilitar a execução dos códigos durante a codificação, o script compile\_and\_run.sh pode ser usado para compilar e rodar o programa; estando no diretório do programa, basta usar `chmod +x compile_and_run.sh` para adicionar permissão de execução para o arquivo e depois executá-lo com `./compile_and_run.sh`; É possível utilizar o script passando argumentos, que serão repassados para o programa na hora de rodar - ex.: `./compile_and_run.sh -o -R`;
6. Este programa foi projetado para funcionar em sistemas Linux, recomenda-se que o BASH esteja instalado.

######Argumentos opcionais:
**_-h_**: exibe uma mensagem de ajuda e finaliza o programa;

**_-o_**: força a inserção de números em ordem (ignora argumentos **-a** e **-i**);

**_-R_**: plota o gráfico a partir do arquivo de saída usando R (é necessário possuir o R instalado);

**-n**:
quantidade de números que serão incluídos em ambas as estruturas de dados (padrão: 1000 | obs: o valor -1 não deve ser usado; deve ser maior que a quantidade de números a serem sorteados; deve ser um valor positivo);
	
**-s**:
quantidade de números a serem sorteados para serem buscados em ambas as estruturas (padrão: 1000 | obs: o valor -1 não deve ser usado; deve ser menor que a quantidade de números; deve ser um valor positivo);

**-a**:	número máximo que pode ser sorteado e incluído nas estruturas	(padrão: 999999 | obs: os valores -1 e o inteiro máximo não devem ser usados; deve ser maior que o número mínimo);
	
**-i**: número mínimo que pode ser sorteado e incluído nas estruturas (padrão: -99999 | obs: o valor -1 não deve ser usado; deve ser menor que o número máximo);

**-f**: nome para o arquivo de saída, sem extensão (padrão: avl_vs_bst | não deve ultrapassar 100 caracteres; deve haver um espaço entre o argumento e o nome do arquivo);

Caso não haja valores para os argumentos **-n**, **-s**, **-a**, **-i** e **-f** ou eles não estiverem setados, o valor padrão será utilizado.


####Arquivos:

**arguments.h**: Funções e constantes relacionadas à manipulação de argumentos;

**compile\_and\_run.sh**: script para agilizar a compilação e executar o programa;

**file.h**: Funções e constantes relacionadas à leitura e escrita de arquivos;

**global.h**: Tipos de dados e constantes que podem ser utilizadas em qualquer parte do projeto;

**help\_menu**: Arquivo com instruções de uso do programa - é usado para imprimir as instruções quando o argumento **_-h_** é setado;

**main.c**: arquivo principal, que deve ser compilado para rodar o projeto;

**r_template**: configurações para o gráfico (código R) gerado pelo programa;

**randomize.h**: Funções relativas à randomização de números;

**self\_unitary\_tests.c**: realiza testes unitários nas funções importantes do projeto - compilar e rodar para obter informações sobre o correto funcionamento das funções; Os argumentos `-n17 -s 17 -tuj17v p17` devem ser usados para testar as funções de recebimento de parâmetros;

**trees.h**: Estruturas e funções de manipulação de árvores de busca binária e AVL; Definição dos tipos abstratos de dados AVL e BST;



####Observações:

O programa gerará um arquivo .R que pode ser usado para plotar um gráfico que relaciona o crescimento número de comparações necessárias ao realizar buscas nos dois tipos de árvores (AVL e BST) com o número de buscas realizado.

As recomendações de estilo na escrita do código descritas neste documento foram seguidas a medida que não fugiam do escorpo do projeto: Recommended C Style and Coding Standards (Cannon) [https://www.doc.ic.ac.uk/lab/cplus/cstyle.html]

Testado usando o GCC 5.2.1 GNU/Linux e R 3.2.2