#AVL vs BST
Comparação de eficiência entre AVL e Árvores de Busca Binária

Este programa faz parte de um projeto de Estrutura de Dados do período 2015.2 no IC (Instituto de Computação) da UFAL (Universidade Federal de Alagoas), Campus A.C. Simões;

Professor responsável: Márcio Ribeiro (http://ic.ufal.br/marcio)

Membros da equipe:
+ Sergio A. T. Amorim <sata@ic.ufal.br>

Trello do projeto: https://trello.com/b/ABXiNDng

Este programa inclui uma números aleatórios em duas estruturas de dados: uma AVL e uma árvore de busca binária. Depois, sorteia dentre os números incluídos, números a serem buscados em ambas as estruturas. Para cada busca, o número de comparações necessárias para encontrar o número é contado e servirá para plotar um gráfico que relaciona a quantidade de comparações necessárias com a quantidade de números buscados.



#####Instruções de uso:
1. Compilar o arquivo main.c;
2. Rodar com o argumento -h para obter instruções;
3. Não usar o número -1 como valor de nenhum argumento do programa;

######argumentos opcionais:
**_-h_**: exibe uma mensagem de ajuda e finaliza o programa

**-n**:
quantidade de números que serão incluídos em ambas as estruturas de dados (padrão: 10000 | obs: o número -1 não deve ser usado; deve ser maior que a quantidade de números a serem sorteados; deve ser um valor positivo)
	
**-s**:
quantidade de números a serem sorteados para serem buscados em
ambas as estruturas (padrão: 1000 | obs: o número -1 não deve
ser usado; deve ser menor que a quantidade de números; deve ser
um valor positivo)

**-a**:	número máximo que pode ser sorteado e incluído nas estruturas	(padrão: 999999 | obs: os números -1 e o inteiro máximo não devem ser usados; deve ser maior que o número mínimo)
	
**-i**: número mínimo que pode ser sorteado e incluído nas estruturas (padrão: -99999 | obs: o número -1 não deve ser usado; deve ser menor que o número máximo)


Testado usando o GCC 5.2.1 GNU/Linux
