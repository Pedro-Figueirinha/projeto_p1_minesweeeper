#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.c"

int ncols, nlines;
int nmines;
int mines;
int nflags;
float blank_board[26][26];//tabuleiro composto por '-'s
float final_board[26][26];
char f_or_u;

int main(){

    float board[26][26]; //board inicial, os valores não vao ser alterados, este board nao é impresso
    printf("\t\tDimensoes do tabuleiro:\n");
    printf("linhas:\n");
    scanf("%d", &nlines);
    printf("colunas:\n");
    scanf("%d", &ncols);
    printf("minas:\n");
    scanf("%d", &nmines);
    nflags = nmines;
    generate_board(board, nlines, ncols, nmines);
    jogada(board, nlines, ncols, nmines);
    return 0;
}
