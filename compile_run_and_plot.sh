#!/bin/bash

# compilar
gcc main.c -o main.out

# rodar
./main.out -n 500

# plotar
R < avl_vs_bst.R --no-save --slave
